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
    set.endGroup();

    qRegisterMetaType<QtMsgType>("QtMsgType");
    pLog=QSharedPointer<LogController>(new LogController("ZBY_MQ",this));
    connect(pLog.data(),SIGNAL(signal_newLogText(QtMsgType,QDateTime,QString)),this,SLOT(slot_newLogText(QtMsgType,QDateTime,QString)));

    QDir plugin(QCoreApplication::applicationDirPath());
    for(const QString &fileName :plugin.entryList(QDir::Files)){
        qDebug()<<fileName;
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
    TCP_InitializationParameterSignal("127.0.0.1",TCPPort,1,false,0,0,0);
    MQ_InitializationParameterSignal("127.0.0.1|zby|ABCabc123|/zby",MQPort,1,false,0,0,0);
}

MainWindow::~MainWindow()
{
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

void MainWindow::socketReadDataSlot(int channel_number, const QString &result)
{
    Q_UNUSED(channel_number);
    emit toSendDataSignal(Channel,result);
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
