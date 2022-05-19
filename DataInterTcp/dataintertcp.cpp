#include "dataintertcp.h"

DataInterTcp::DataInterTcp(QObject *parent)
{
    this->setParent(parent);

    isHeartBeat=false;
    isConnected=false;
    pTcpServer=nullptr;
    pTcpClient=nullptr;
    pTimerLinkState=nullptr;
    pTimerAutoLink=nullptr;

    x=0;
    y=0;
    w=0;

#ifdef Q_OS_LINUX
    eol = "\n";
#endif
#ifdef Q_OS_WIN
    eol = "\r\n";
#endif
}

DataInterTcp::~DataInterTcp()
{
}

QString DataInterTcp::InterfaceType()
{
    return QString("TCP_2");
}

void DataInterTcp::InitializationParameterSlot(const QString& address, const quint16& port, const int& serviceType,const bool& heartBeat, const int& serviceMode,const int& shortLink,const int& newline)
{
    if(address.indexOf("|")!=-1){
        return;
    }

    this->address=address;
    this->port=port;
    this->shortLink=shortLink;
    this->newline=newline;

    if(serviceMode==1){/* 服务器模式 */
        pTcpServer=new TcpServer (this);
        pTcpServer->setServiceType(serviceType);/* 设置服务模式 */
        /* 日志信息 */
        connect(pTcpServer,&TcpServer::messageSignal,this,&DataInterTcp::messageSignal);
        /* 心跳包状态设置 */
        connect(this,&DataInterTcp::setHeartbeatPackStateSignal,pTcpServer,&TcpServer::setHeartPacketStateSlot);
        /* 绑定客户端数量 */
        connect(pTcpServer,&TcpServer::connectCountSignal,this,&DataInterTcp::connectCountSignal);
        /* 发送识别结果 */
        connect(this,&DataInterTcp::toSendDataSignal,pTcpServer,&TcpServer::toSendDataSlot);
        /* 设置数据格式 */
        connect(this,&DataInterTcp::signal_setMessageFormat,pTcpServer,&TcpServer::slot_setMessageFormat);
        /* 发送成功写入日志和UI */
        connect(pTcpServer,&TcpServer::signal_sendDataSuccToLog,this,&DataInterTcp::signal_sendDataSuccToLog);
        /* tcp链接状态 */
        connect(pTcpServer,&TcpServer::linkStateSingal,this,&DataInterTcp::linkStateSingal);
        /* tcp链接状态 */
        connect(pTcpServer,&TcpServer::signal_lifting,this,&DataInterTcp::signal_lifting);
        /* 释放资源 */
        connect(this,&DataInterTcp::signal_releaseResources,pTcpServer,&TcpServer::releaseResourcesSlot);

        startListenSlot();
    }
    else if (serviceMode==0) {/* 客户端模式 */
        pTcpClient=new QTcpSocket();
        pTimerLinkState=new QTimer(this);
        pTimerAutoLink=new QTimer(this);
        pTimerAutoLink->setSingleShot(true);

        /* 发送识别结果 */
        connect(this,&DataInterTcp::toSendDataSignal,this,&DataInterTcp::toSendDataSlot);
        /* 心跳包状态设置 */
        connect(this,&DataInterTcp::setHeartbeatPackStateSignal,this,&DataInterTcp::setHeartPacketStateSlot);

        connect(pTcpClient,&QIODevice::readyRead,this,&DataInterTcp::receiveDataSlot);
        connect(pTcpClient,&QAbstractSocket::connected,this,&DataInterTcp::connectedSlot);
        connect(pTcpClient,&QAbstractSocket::disconnected,this,&DataInterTcp::disconnectedSlot);
        connect(pTcpClient,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&DataInterTcp::displayErrorSlot);
        connect(pTimerLinkState,&QTimer::timeout,this,&DataInterTcp::heartbeatSlot);
        connect(pTimerAutoLink,&QTimer::timeout,this,&DataInterTcp::startLinkSlot);

        /*****************************
        * @brief:不是短链接，服务器启动主动链接
        ******************************/
        if(!shortLink){
            startLinkSlot();
        }
    }

    emit setHeartbeatPackStateSignal(heartBeat);
    emit signal_setMessageFormat(newline);
}

void DataInterTcp::startLinkSlot()
{
    if(!isConnected){
        pTcpClient->close();
        pTcpClient->abort();
        pTcpClient->connectToHost(address,port);
    }
}

void DataInterTcp::startListenSlot()
{
    if(!pTcpServer->listen(QHostAddress::AnyIPv4,port)){/* 服务器使用本机地址 */
        qWarning().noquote()<<QString("IP:%1 Listen error<errocCode=%2>").arg(address).arg(pTcpServer->errorString());
    }
    else {
        qDebug().noquote()<<QString("IP:%1 Start listen.").arg(address);
    }
}

void DataInterTcp::heartbeatSlot()
{
    if(isHeartBeat && pTcpClient->isOpen()){
        pTcpClient->write("[H]");/* 心跳包数据 */
    }
}

void DataInterTcp::connectedSlot()
{
    isConnected=true;

    if(!pTimerLinkState->isActive()){
        pTimerLinkState->start(15000);
    }

    emit connectCountSignal(1);
    emit linkStateSingal(address,port,true);
    qDebug().noquote()<<QString("IP:%1:%2 link successful").arg(address).arg(port);
}

void DataInterTcp::receiveDataSlot()
{
    /*****************************
    * @brief:服务器主动取结果
    ******************************/
    QByteArray buf=pTcpClient->readAll();
    if(buf.trimmed().startsWith('[')){
        QList<QByteArray> tmp=buf.split('|');
        if(tmp.count()==2){
            if (tmp[0].indexOf('R')!=-1) {/* 找到取结果标志位 */
                pTcpClient->write(resultOfMemory.toLocal8Bit());
                if(newline){
                    pTcpClient->write(eol.toUtf8());
                }
            }
        }
        /*****************************
        * @brief:收到抬杆信息
        ******************************/
        if(tmp.count()==1 && buf=="[+LF]"){
            emit signal_lifting();
        }
    }
    else {
        /*****************************
        * @brief:202105062343(接收到不是指定数据，源数据转发输出)
        ******************************/
        emit toSendDataSignal(channel,buf);
    }
    buf.clear();
}

void DataInterTcp::disconnectedSlot()
{
    isConnected=false;
    emit connectCountSignal(-1);
    emit linkStateSingal(address,port,false);
}

void DataInterTcp::displayErrorSlot(QAbstractSocket::SocketError socketError)
{
    isConnected=false;

    //emit connectCountSignal(-1);
    emit linkStateSingal(address,port,false);

    if(!shortLink){
        //QTimer::singleShot(15000, this, SLOT(startLinkSlot()));
        pTimerAutoLink->start(15000);
    }
    qWarning().noquote()<<QString("IP:%1:%3  link error<errorCode=%2>").arg(address).arg(socketError).arg(port);
}

void DataInterTcp::setHeartPacketStateSlot(bool state)
{
    isHeartBeat=state;
}

void DataInterTcp::getWeightToDataSlot(const int& x, const int& y ,const int& w)
{
    this->x=x;
    this->y=y;
    this->w=w;

    qDebug().noquote()<<QString("write weight<%1>").arg(QString::number(w));
}

void DataInterTcp::toSendDataSlot(int channel_number,const QString &data)
{
    Q_UNUSED(channel_number);
    resultOfMemory=analyticalData(data);

    if(!pTcpClient->isOpen()){
        startLinkSlot();
        pTcpClient->waitForConnected(3000);
    }

    if(pTcpClient->isOpen()){
        pTcpClient->write(resultOfMemory.simplified().toLatin1());
        qDebug().noquote()<<QString("[%1] Send Data<%2>").arg(this->metaObject()->className(),resultOfMemory);

        if(newline){
            pTcpClient->write(eol.toUtf8());
        }

        emit signal_sendDataSuccToLog(channel_number,data);

        if(shortLink){
            /*****************************
            * @brief:发送完成主动断开
            ******************************/
            pTcpClient->waitForBytesWritten();
            pTcpClient->close();
            pTcpClient->abort();
        }
    }
}

void DataInterTcp::releaseResourcesSlot()
{
    if(pTcpServer!=nullptr && pTcpServer->isListening()){
        emit signal_releaseResources();
        pTcpServer->close();
    }

    if(pTcpClient != nullptr && pTcpClient->isOpen()){
        pTcpClient->disconnected();
        pTcpClient->close();
        pTcpClient->abort();
    }

    isConnected=false;

    if(pTimerLinkState!=nullptr){
        pTimerLinkState->stop();
    }
    if(pTimerAutoLink!=nullptr){
        pTimerAutoLink->stop();
    }

    qDebug().noquote()<<QString("DataInterchange::releaseResourcesSlot");
}

QString DataInterTcp::analyticalData( QString data)
{
    QByteArray arr=data.toLatin1();
    QJsonParseError jsonErr;
    QJsonDocument jsonDoc=QJsonDocument::fromJson(arr,&jsonErr);

    QJsonObject obj_Msg;

    if(!jsonDoc.isNull() && jsonErr.error==QJsonParseError::NoError){
        if(jsonDoc.isObject()){
            QJsonObject obj=jsonDoc.object();
            if(obj.contains(QString("type"))){
                int type = obj.value(QString("type")).toInt();
                if(5 != type){
                    return data;
                }
            }
            if(obj.contains(QString("msg"))){
                QJsonObject obj1=obj.value(QString("msg")).toObject();
                obj1["pz"]=x;
                obj1["pzai"]=y;
                obj1["weight"]=w;


                obj_Msg.insert("msg",obj1);
                obj_Msg["type"]=5;
            }
        }
    }

    QJsonDocument doc;
    doc.setObject(obj_Msg);
    return doc.toJson();
}
