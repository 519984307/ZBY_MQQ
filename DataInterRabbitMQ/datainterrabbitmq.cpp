
#include "datainterrabbitmq.h"

DataInterRabbitMQ::DataInterRabbitMQ(QObject *parent)
{
    this->setParent(parent);
}

DataInterRabbitMQ::~DataInterRabbitMQ()
{
    m_client.disconnected();
    m_client.abort();
}

QString DataInterRabbitMQ::InterfaceType()
{
    return QString("MQ");
}

void DataInterRabbitMQ::InitializationParameterSlot(const QString &address, const quint16 &port, const int &serviceType, const bool &heartBeat, const int &serviceMode, const int &shortLink, const int &newline)
{
    Q_UNUSED(serviceType);
    Q_UNUSED(heartBeat);
    Q_UNUSED(serviceMode);
    Q_UNUSED(shortLink);
    Q_UNUSED(newline);

    /*****************************
    * @brief:address="127.0.0.1|zby|ABCabc123|/zby"
    ******************************/
    QStringList addrList=address.split("|");
    QString user="zby";
    QString pass="ABCabc123";
    QString vhost="/zby";
    lport=5672;
    addr="127.0.0.1";

    if(port!=0){
        lport=port;
    }

    if(addrList.size()==4){
        addr=addrList[0];
        user=addrList[1];
        pass=addrList[2];
        vhost=addrList[3];
    }
    else {
        qCritical().noquote()<<QString("Error setting MQ parameters, load default parameters.");
    }

    m_client.setHost(addr);
    m_client.setPort(lport);
    m_client.setUsername(user);
    m_client.setPassword(pass);
    m_client.setVirtualHost(vhost);
    m_client.setAutoReconnect(true);

    connect(&m_client, SIGNAL(connected()), this, SLOT(clientConnected()));
    connect(&m_client, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));

    /*****************************
    * @brief:发送识别结果
    ******************************/
    connect(this,&DataInterRabbitMQ::toSendDataSignal,this,&DataInterRabbitMQ::toSendDataSlot);

    /*****************************
    * @brief:设置持续保存
    ******************************/
    properties[QAmqpMessage::DeliveryMode] = "2";

    isConnected=false;
}

void DataInterRabbitMQ::toSendDataSlot(int channel_number, const QString &data)
{
    this->channel_number=channel_number;
    if(!isConnected){
        isConnected=true;
        sendData=data;
        m_client.connectToHost();
    }
    else {
        tmpMsg=data;
    }
}

void DataInterRabbitMQ::releaseResourcesSlot()
{
    m_client.disconnectFromHost();
    m_client.abort();

    qDebug().noquote()<<QString("DataInterRabbitMQ::releaseResourcesSlot");
}

void DataInterRabbitMQ::clientDisconnected()
{
    emit linkStateSingal(addr,m_client.port(),false);
    emit connectCountSignal(-1);

    if(isConnected && !tmpMsg.isEmpty()){
        isConnected=false;
        toSendDataSlot(channel_number, tmpMsg);
        tmpMsg.clear();
    }
    else {
        isConnected=false;
    }
}

void DataInterRabbitMQ::clientConnected()
{
    emit linkStateSingal(addr,lport,true);
    emit connectCountSignal(1);

    QAmqpQueue *queue = m_client.createQueue("zby_"+QString::number(channel_number));
    connect(queue, SIGNAL(declared()), this, SLOT(queueDeclared()));
    queue->declare(QAmqpExchange::Durable);
}

void DataInterRabbitMQ::queueDeclared()
{
    QAmqpQueue *queue = qobject_cast<QAmqpQueue*>(sender());
    if (!queue)
        return;

    emit signal_sendDataSuccToLog(channel_number,sendData);

    QAmqpExchange *defaultExchange = m_client.createExchange();
    defaultExchange->publish(sendData,"zby_"+QString::number(channel_number),properties);

//    defaultExchange->enableConfirms(true);
//    if(defaultExchange->waitForConfirms(1000)){
//        qDebug().noquote()<< QString("[MQ] send:")<<sendData;
//    }
//    else {
//        qDebug()<<"send message failed";
//        //defaultExchange->publish(sendData, "zby",properties);
//    }

    qDebug().noquote()<< QString("[MQ] send:")<<sendData;
    m_client.disconnectFromHost();
    defaultExchange->deleteLater();
    queue->deleteLater();
}
