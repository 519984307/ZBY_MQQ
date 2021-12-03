#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings set(QDir::toNativeSeparators("Sys.ini"),QSettings::IniFormat);
    set.setIniCodec("UTF-8");

    set.beginGroup("Sys");
    MQPort = set.value("MQPort",5672).toInt();
    Channel = set.value("Channel",001).toInt();
    TCPPort = set.value("TCPPort",12011).toInt();
    MQAddr = set.value("MQAddr","127.0.0.1").toString();
    MQUser = set.value("MQUser","zby").toString();
    MQPass = set.value("MQPass","ABCabc123").toString();
    MQHost = set.value("MQHost","/zby").toString();
    TCPAddr = set.value("TCPAddr","127.0.0.1").toString();
    PortName = set.value("PortName","com2").toString();
    PortBaud = set.value("PortBaud",19200).toInt();
    PortData = set.value("PortData",8).toInt();
    PortStop = set.value("PortStop",1).toInt();
    PortParity = set.value("PortParity",0).toInt();
    weight = set.value("weight",500).toInt();
    beating = set.value("beating",3).toInt();
    set.endGroup();

    /*****************************
    * @brief:判断在做工
    ******************************/
    work=false;
    batch=0;
    dd="";

    workTimtOut=new QTimer(this);
    workTimtOut->setSingleShot(true);
    connect(workTimtOut,&QTimer::timeout,this,&MainWindow::workTimeOutSlot);


    qRegisterMetaType<QtMsgType>("QtMsgType");
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
    * @brief:初始化
    ******************************/
    TCP_InitializationParameterSignal(TCPAddr,TCPPort,1,false,0,0,0);
    MQ_InitializationParameterSignal(QString("%1|%2|%3|%4").arg(MQAddr,MQUser,MQPass,MQHost),MQPort,1,false,0,0,0);

    /*****************************
    * @brief:初始化参口
    ******************************/
    pPort=QSharedPointer<DataInterSerailPort>(new DataInterSerailPort(this));
    connect(pPort.data(),&DataInterSerailPort::getPoundsSignal,this,&MainWindow::getPoundsSlot);
    connect(pPort.data(),&DataInterSerailPort::startStatusSignal,this,&MainWindow::startStatusSlot);
    pPort->startSlave(PortName,PortBaud,PortData,PortStop,PortParity,0);

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
}

MainWindow::~MainWindow()
{
    qInfo()<<QString("Number of spreader work:%1").arg(QString::number(batch));
    workTimtOut->stop();

    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    emit releaseResourcesSignal();
    QWidget::closeEvent(event);
}

void MainWindow::mqProcess(DataInterchangeInterface *mq)
{
    /* 初始化参数 */
    connect(this,&MainWindow::MQ_InitializationParameterSignal,mq,&DataInterchangeInterface::InitializationParameterSlot);
    /* 发送数据 */
    connect(this,&MainWindow::toSendDataSignal,mq,&DataInterchangeInterface::toSendDataSlot);
    /* 绑定MQ数量到服务界面 */
    connect(mq,&DataInterchangeInterface::linkStateSingal,this,&MainWindow::MQ_socketLinkStateSlot);
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

void MainWindow::statisticalLog(int w)
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
            batch=1;
            ui->spinBox->setValue(batch);
        }
    }

    statistical.setFileName(QDir::toNativeSeparators(QString("statistical/%1").arg(date)));
    statistical.open( QIODevice::Append | QIODevice::Text | QIODevice::Unbuffered );
    statistical.write(QString("%1 - %2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss-zzz"),QString::number(w)).toUtf8());
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
    /*****************************
    * @brief:开始做工
    ******************************/
    if(w>weight && !work){
        if(!work){
            batch++;
            ui->label_3->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");

            QtConcurrent::run(this,&MainWindow::statisticalLog,w);
        }
        work=true;
    }

    /*****************************
    * @brief:落下又拉起
    ******************************/
    if(w>weight && work && workTimtOut->isActive()){
        workTimtOut->stop();
    }

    /*****************************
    * @brief做工完成:
    ******************************/
    if(w<weight && work && !workTimtOut->isActive()){
        workTimtOut->start(beating*1000);
    }

    ui->spinBox->setValue(batch);
    ui->spinBox_2->setValue(x);
    ui->spinBox_3->setValue(y);
    ui->spinBox_4->setValue(w);    
}

void MainWindow::workTimeOutSlot()
{
    /*****************************
    * @brief:做工完成
    ******************************/
    work=false;
    ui->label_3->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);");
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
