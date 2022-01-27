#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSerialBus/QModbusDevice>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<QtMsgType>("QtMsgType");
    qRegisterMetaType<QMap<QString,int>>("QMap<QString,int>");
    qRegisterMetaType<QModbusDevice::State>("QModbusDevice::State");
    qRegisterMetaType<QModbusDevice::Error>("QModbusDevice::Error");
    qRegisterMetaType<QModbusDataUnit::RegisterType>("QModbusDataUnit::RegisterType");

    /*****************************
    * @brief:默认磅重为串口
    ******************************/
    weightModel=0;

    /*****************************
    * @brief:加载参数
    ******************************/
    setting();

    pLog=QSharedPointer<LogController>(new LogController("ZBY_MQ",this));
    connect(pLog.data(),SIGNAL(signal_newLogText(QtMsgType,QDateTime,QString)),this,SLOT(slot_newLogText(QtMsgType,QDateTime,QString)));

    QDir plugin(QCoreApplication::applicationDirPath());
    for(const QString &fileName :plugin.entryList(QDir::Files)){
        QPluginLoader  pluginLoader(plugin.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();

        if(plugin){
            if (DataInterchangeInterface* pDataInterchangeInterface=qobject_cast<DataInterchangeInterface*>(plugin)) {
                if(pDataInterchangeInterface->InterfaceType()=="MQ"){
                    mqProcess(pDataInterchangeInterface);
                    qDebug().noquote()<<QString("MQ plugin load sucess");
                }
                else if(pDataInterchangeInterface->InterfaceType()=="TCP"){
                    tcpProcess(pDataInterchangeInterface);
                    qDebug().noquote()<<QString("TCP plugin load sucess");
                }
            }
            else {
                pluginLoader.unload();
            }
        }
        else {
            delete plugin;
            plugin=nullptr;
        }
    }

    /*****************************
    * @brief:判断在做工
    ******************************/
    work=false;
    batch=0;
    dd="";

    /*****************************
    * @brief:初始化
    ******************************/
    TCP_InitializationParameterSignal(TCPAddr,TCPPort,1,false,0,0,0);
    MQ_InitializationParameterSignal(QString("%1|%2|%3|%4").arg(MQAddr,MQUser,MQPass,MQHost),MQPort,1,false,0,0,0);

    /*****************************
    * @brief:初始化Modbus
    ******************************/
    pModbus=QSharedPointer<DataInterModbus>(new DataInterModbus(this));
    connect(pModbus.data(),&DataInterModbus::connectStateSignal,this,&MainWindow::modbusStatusSlot);
    connect(pModbus.data(),&DataInterModbus::setPlcStatusSginal,this,&MainWindow::getPlcStatusSlot);
    connect(pModbus.data(),&DataInterModbus::connectSlaveSignal,this,&MainWindow::connectSlaveSlot);

    /****************************
    * @brief:初始化磅重
    ******************************/
    if(0 == weightModel){
        pPort=QSharedPointer<DataInterSerailPort>(new DataInterSerailPort(this));
        connect(pPort.data(),&DataInterSerailPort::getPoundsSignal,this,&MainWindow::getPoundsSlot);
        connect(pPort.data(),&DataInterSerailPort::startStatusSignal,this,&MainWindow::startStatusSlot);
        /*****************************
        * @brief:设置串口状态
        ******************************/
        connect(pPort.data(),&DataInterSerailPort::startStatusSignal,pModbus.data(),&DataInterModbus::getComState);
    }else if (1 == weightModel) {
        pWeiModbus=QSharedPointer<WeightModbus>(new WeightModbus(this));
        connect(pWeiModbus.data(),&WeightModbus::setPoundsSignal,this,&MainWindow::getPoundsSlot);
        connect(pWeiModbus.data(),&WeightModbus::connectStateSignal,this,&MainWindow::startStatusSlot);
        /*****************************
        * @brief:设置串口状态
        ******************************/
        connect(pWeiModbus.data(),&WeightModbus::connectStateSignal,pModbus.data(),&DataInterModbus::getComState);
    }

    /*****************************
    * @brief:设置开闭锁状态
    ******************************/
    connect(this,&MainWindow::setLockStateSignal,pModbus.data(),&DataInterModbus::getLockStateSlot);

    if(0 == weightModel){
        pPort->startSlave(PortName,PortBaud,PortData,PortStop,PortParity,0);
    }else if (1 == weightModel) {
        pWeiModbus->initModbus(modbusAddr_weight,modbusPort_weight,decID_weight,startAddr_weight,mdLen_weight,request_weight);
    }

    pModbus->initModbus(modbusAddr,modbusPort,decID,startAddr,mdLen,request,iso);

    /*****************************
    * @brief:初始化统计数据
    ******************************/
    QString date=QDate::currentDate().toString("yyyy-MM-dd");
    if(!QDir("statistical").exists()){
        QDir().mkpath("statistical");
    }
    statistical.setFileName(QDir::toNativeSeparators(QString("statistical/%1").arg(date)));
    statistical.open( QIODevice::ReadOnly | QIODevice::Text | QIODevice::Unbuffered );

    int line=0;
    while (!statistical.atEnd()) {
        if(!statistical.readLine().isEmpty()){
            line++;
        }
    }
    statistical.close();
    ui->spinBox->setValue(line);
    batch=line;

    isSucess=true;
    xx=-1;
    yy=-1;
    zz=-1;

    unLockx=-1;
    unLocky=-1;
    unLockz=-1;

    sUnLockx=-1;
    sUnLocky=-1;
    sUnLockz=-1;
}

MainWindow::~MainWindow()
{
    if(pModbus){
        pModbus->disconnect();
    }

    if(pWeiModbus){
        pWeiModbus->disconnect();
    }

    if(pPort){
        pPort->disconnect();
    }

    qInfo()<<QString("Number of spreader work:%1").arg(QString::number(batch));

    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    emit releaseResourcesSignal();
    QWidget::closeEvent(event);
}

void MainWindow::setting()
{
    QSettings set(QDir::toNativeSeparators("Sys.ini"),QSettings::IniFormat);
    set.setIniCodec("UTF-8");

    set.beginGroup("MQ");
    MQAddr = set.value("MQAddr","127.0.0.1").toString();
    MQPort = set.value("MQPort",5672).toInt();
    MQUser = set.value("MQUser","zby").toString();
    MQPass = set.value("MQPass","ABCabc123").toString();
    MQHost = set.value("MQHost","/zby").toString();
    Channel = set.value("Channel",001).toInt();
    set.endGroup();

    set.beginGroup("TCP");
    TCPPort = set.value("TCPPort",12011).toInt();
    TCPAddr = set.value("TCPAddr","127.0.0.1").toString();
    set.endGroup();

    set.beginGroup("COM");
    PortName = set.value("PortName","com2").toString();
    PortBaud = set.value("PortBaud",19200).toInt();
    PortData = set.value("PortData",8).toInt();
    PortStop = set.value("PortStop",1).toInt();
    PortParity = set.value("PortParity",0).toInt();
    weight = set.value("weight",500).toInt();
    beating = set.value("beating",3).toInt();
    weightModel = set.value("weightModel",0).toInt();
    set.endGroup();

    set.beginGroup("Modbus");
    modbusAddr = set.value("modbusAddr","127.0.0.1").toString();
    modbusPort = set.value("modbusPort",502).toInt();
    decID = set.value("decID",1).toInt();
    startAddr = set.value("startAddr",3399).toInt();
    mdLen = set.value("mdLen",16).toInt();
    request = set.value("request",100).toInt();
    iso = set.value("iso",0).toInt();
    set.endGroup();

    set.beginGroup("Modbus_weight");
    modbusAddr_weight = set.value("modbusAddr_weight","127.0.0.1").toString();
    modbusPort_weight = set.value("modbusPort_weight",502).toInt();
    decID_weight = set.value("decID_weight",1).toInt();
    startAddr_weight = set.value("startAddr_weight",3399).toInt();
    mdLen_weight = set.value("mdLen_weight",16).toInt();
    request_weight = set.value("request_weight",100).toInt();
    validTime_weight = set.value("validTime_weight",5).toInt();
    set_weight = set.value("set_weight",1).toInt();
    set.endGroup();


    set.beginGroup("MQ");
    set.setValue("MQPort",MQPort);
    set.setValue("MQAddr",MQAddr);
    set.setValue("MQUser",MQUser);
    set.setValue("MQPass",MQPass);
    set.setValue("MQHost",MQHost);
    set.setValue("Channel",Channel);
    set.endGroup();

    set.beginGroup("TCP");
    set.setValue("TCPAddr",TCPAddr);
    set.setValue("TCPPort",TCPPort);
    set.endGroup();

    set.beginGroup("COM");
    set.setValue("PortName",PortName);
    set.setValue("PortBaud",PortBaud);
    set.setValue("PortData",PortData);
    set.setValue("PortStop",PortStop);
    set.setValue("PortParity",PortParity);
    set.setValue("weight",weight);
    set.setValue("beating",beating);
    set.value("weightModel",weightModel);
    set.endGroup();

    set.beginGroup("Modbus");
    set.setValue("modbusAddr",modbusAddr);
    set.setValue("modbusPort",modbusPort);
    set.setValue("decID",decID);
    set.setValue("startAddr",startAddr);
    set.setValue("mdLen",mdLen);
    set.setValue("request",request);
    set.setValue("iso",iso);
    set.endGroup();

    set.beginGroup("Modbus_weight");
    set.setValue("modbusAddr_weight",modbusAddr_weight);
    set.setValue("modbusPort_weight",modbusPort_weight);
    set.setValue("decID_weight",decID_weight);
    set.setValue("startAddr_weight",startAddr_weight);
    set.setValue("mdLen_weight",mdLen_weight);
    set.setValue("request_weight",request_weight);
    set.setValue("validTime_weight",validTime_weight);
    set.setValue("set_weight",set_weight);
    set.endGroup();
}


void MainWindow::mqProcess(DataInterchangeInterface *mq)
{
    /* 初始化参数 */
    connect(this,&MainWindow::MQ_InitializationParameterSignal,mq,&DataInterchangeInterface::InitializationParameterSlot);
    /* 发送数据 */
    connect(this,&MainWindow::toSendDataSignal,mq,&DataInterchangeInterface::toSendDataSlot);
    /* 绑定MQ数量到服务界面 */
    connect(mq,&DataInterchangeInterface::linkStateSingal,this,&MainWindow::MQ_socketLinkStateSlot);
    /* 重量写入数据 */
    connect(this,&MainWindow::setWeightToSignal,mq,&DataInterchangeInterface::getWeightToDataSlot);
    /* 释放资源 */
    connect(this,&MainWindow::releaseResourcesSignal,mq,&DataInterchangeInterface::releaseResourcesSlot);
}

void MainWindow::tcpProcess(DataInterchangeInterface *tcp)
{
    /* 初始化参数 */
    connect(this,&MainWindow::TCP_InitializationParameterSignal,tcp,&DataInterchangeInterface::InitializationParameterSlot);
    /* 接收数据 */
    connect(tcp,&DataInterchangeInterface::toSendDataSignal,this,&MainWindow::socketReadDataSlot);
    /* 绑定SOCKET数量到服务界面 */
    connect(tcp,&DataInterchangeInterface::linkStateSingal,this,&MainWindow::TCP_socketLinkStateSlot);
    /* 释放资源 */
    connect(this,&MainWindow::releaseResourcesSignal,tcp,&DataInterchangeInterface::releaseResourcesSlot);
}

void MainWindow::writeLog(const QString &msg)
{
    if(ui->plainTextEdit->blockCount()>300){
        ui->plainTextEdit->clear();
    }
    ui->plainTextEdit->appendPlainText(QString("[%1] [%2] %3").arg("ZBY_MQ",QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"),msg));
}

void MainWindow::statisticalLog(QString data)
{
#ifdef Q_OS_LINUX
    QString eol = "\n";
#endif
#ifdef Q_OS_WIN
    QString eol = "\r\n";
#endif

    QString date=QDate::currentDate().toString("yyyy-MM-dd");

    if(dd.isEmpty()){
        dd=date;
    }
    else {
        if(dd!=date){
            dd=date;
            batch=1;
            ui->spinBox->setValue(batch);
        }
    }

    statistical.setFileName(QDir::toNativeSeparators(QString("statistical/%1").arg(date)));
    statistical.open( QIODevice::Append | QIODevice::Text | QIODevice::Unbuffered );
    statistical.write(QString("%1 - %2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss-zzz"),data).toUtf8());
    statistical.write(eol.toUtf8());
    statistical.close();
}

void MainWindow::socketReadDataSlot(int channel_number, const QString &result)
{
    Q_UNUSED(channel_number);
    emit toSendDataSignal(Channel,result);
}

void MainWindow::getPoundsSlot(int x, int y, int w)
{
    this->x=x;
    this->y=y;
    this->w=w;

    if(-1 != unLockx && -1 != unLocky && -1!=unLockz){
        if(qAbs(unLockx-xx)<500 && qAbs(unLocky-yy)<1000){
            isSucess=false;
        }
        else {
            isSucess=true;
        }

        if(-1 != sUnLockx && -1 != sUnLocky && -1 != sUnLockz){
            if(qAbs(unLockx-sUnLockx)<500 && qAbs(unLocky-sUnLocky)<1000){
                isSucess=true;
            }
        }

        if(isSucess){
            unLockx=-1;
            unLocky=-1;
            unLockz=-1;
            sUnLockx=-1;
            sUnLocky=-1;
            sUnLockz=-1;
        }
    }

    /*****************************
    * @brief:开始做工
    ******************************/
    if(w>weight && !work && isSucess){
        sUnLockx=xx;
        sUnLocky=yy;
        sUnLockz=zz;

        batch++;
        ui->spinBox->setValue(batch);
        ui->label_3->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");

        /*****************************
        * @brief:保持重量写入数据
        ******************************/
        QTimer::singleShot(validTime_weight*1000,this,SLOT(Weight_validTimeSlot()));

        /*****************************
        * @brief:闭锁
        ******************************/
        emit setLockStateSignal(true);

        ui->textEdit->setText(QString("吊箱作业"));

        QtConcurrent::run(this,&MainWindow::statisticalLog,QString("%1 %2 %3").arg(QString::number(x),QString::number(y),QString::number(w)));
        work=true;

        /*****************************
        * @brief:作业完成状态
        ******************************/
        isSucess=false;
    }

    if(w>weight && !work && !isSucess){
        ui->textEdit->setText(QString("吊箱对位"));
    }

    if(w<weight && !work){
        ui->textEdit->setText(QString("吊箱完成"));
    }

    /*****************************
    * @brief做工完成:
    ******************************/
    if(w<weight && work){
        unLockx=xx;
        unLocky=yy;
        unLockz=zz;

        /*****************************
        * @brief:吊箱第一次没有对准
        ******************************/
        if(-1 != sUnLockx && -1 != sUnLocky && -1 != sUnLockz){
            if(qAbs(xx-sUnLockx)<500 && qAbs(yy-sUnLocky)<1000){
                return;
            }
        }

        /*****************************
        * @brief:屏蔽延时做工
        * 20220122
        ******************************/
        work=false;

        /*****************************
        * @brief:开锁
        ******************************/
        emit setLockStateSignal(false);

        /*****************************
        * @brief:保持重量写入数据
        ******************************/
        QTimer::singleShot(validTime_weight*1000,this,SLOT(Weight_validTimeSlot()));

        ui->label_3->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);");

        ui->textEdit->setText(QString("吊箱完成"));
    }

    ui->spinBox_2->setValue(x);
    ui->spinBox_3->setValue(y);
    ui->spinBox_4->setValue(w);
}

void MainWindow::getPlcStatusSlot(QMap<QString, int> msg)
{
    xx=msg.value("x",-1);
    yy=msg.value("y",-1);
    zz=msg.value("z",-1);

    ui->spinBox_5->setValue(msg.value("x",-1));
    ui->spinBox_6->setValue(msg.value("y",-1));
    ui->spinBox_7->setValue(msg.value("z",-1));
    if(msg.value("lock",0)){
         ui->lineEdit_2->setText("闭锁");
    }
    else {
        ui->lineEdit_2->setText("开锁");
    }
    if(msg.value("sling",0)){
        ui->lineEdit->setText("40尺");
    }
    else {
        ui->lineEdit->setText("20尺");
    }

    if(msg.value("box")){
        ui->lineEdit_3->setText("着箱");
    }
    else {
        ui->lineEdit_3->clear();
    }
}

void MainWindow::startStatusSlot(bool status)
{
    if(status){
        ui->label_8->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->label_8->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);");
    }
}

void MainWindow::modbusStatusSlot(bool status)
{
    if(status){
        ui->label_9->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->label_9->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);");
    }
}

void MainWindow::connectSlaveSlot(bool status)
{
    if(status){
        ui->label_16->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->label_16->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);");
    }
}

void MainWindow::MQ_socketLinkStateSlot(const QString &address,quint16 port,bool state)
{
    Q_UNUSED(address);
    Q_UNUSED(port);
    if(state){
        ui->label_2->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->label_2->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);");
    }
}

void MainWindow::TCP_socketLinkStateSlot(const QString &address,quint16 port,bool state)
{
    Q_UNUSED(address);
    Q_UNUSED(port);
    if(state){
        ui->label->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->label->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);");
    }
}

void MainWindow::slot_newLogText(QtMsgType type, QDateTime time, QString value)
{
    Q_UNUSED(time);

    QString msgType=QString("");
    switch (type) {
    case QtDebugMsg:
        msgType="Debug";
        break;
    case QtInfoMsg:
        msgType="Info";
        break;
    case QtWarningMsg:
        msgType="Warning";
        break;
    case QtCriticalMsg:
        msgType="Critical";
        break;
    case QtFatalMsg:
        msgType="Fatal";
        abort();
    }

    writeLog(QString("[%1] %2").arg(msgType,value));
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1==Qt::Unchecked){
        ui->groupBox->setVisible(false);
        this->setFixedSize(1142,60);
    }
    if(arg1==Qt::Checked){
        ui->groupBox->setVisible(true);
        this->setFixedSize(1142,500);
    }
}

void MainWindow::Weight_validTimeSlot()
{
    emit setWeightToSignal(x,y,w);
}
