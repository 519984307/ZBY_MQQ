#include "weightmodbus.h"

WeightModbus::WeightModbus(QObject *parent)
{
    this->setParent(parent);

    modbusDevice = new QModbusTcpClient(this);

    requestTimer = new QTimer(this);
    requestTimer->setSingleShot(false);
    connect(requestTimer,&QTimer::timeout,this,&WeightModbus::requestSlot);

    autoLintTimer = new QTimer(this);
    autoLintTimer->setSingleShot(true);
    connect(autoLintTimer,&QTimer::timeout,this,&WeightModbus::autoLinkSlot);

    port = 502;
    decID = 1;
    startAddr = 1;
    mdLen = 10;
    request = 100;
}

WeightModbus::~WeightModbus()
{
    buf.clear();

    if(autoLintTimer){
        autoLintTimer->stop();
    }
    autoLintTimer->deleteLater();

    if(requestTimer){
        requestTimer->stop();
    }
    requestTimer->deleteLater();

    if(modbusDevice){
        modbusDevice->disconnectDevice();
    }

    delete modbusDevice;
    modbusDevice=nullptr;
}

void WeightModbus::initModbus(const QString &addr, const qintptr &port, const qintptr &decID, const qintptr &startAddr, const qintptr &mdLen, const qintptr &request)
{
    address = addr;
    this->port = port ;
    this->decID = decID ;
    this->startAddr = startAddr;
    this->mdLen =mdLen ;
    this->request = request;

    bool status=false;

    if(!modbusDevice){
        qCritical().noquote()<<QString("[%1] load modbusDevice failed").arg(this->metaObject()->className());
        return;
    }

    /*****************************
    * @brief:modbus链接状态
    ******************************/
    connect(modbusDevice,&QModbusClient::stateChanged,this,&WeightModbus::stateChanged);

    modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter,addr);
    modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter,port);
    modbusDevice->setTimeout(500);
    modbusDevice->setNumberOfRetries(1);

    if(!modbusDevice->connectDevice()){
        qCritical().noquote()<<QString("[%1] %2:connected to addr failed <errCode=%3>").arg(this->metaObject()->className(),modbusDevice->errorString());
    }
    else {
        qInfo().noquote()<<QString("[%1] %2:connected to addr sucess").arg(this->metaObject()->className(),addr);
        status=true;
    }
    emit connectStateSignal(status);
}

void WeightModbus::requestSlot()
{
    if(!modbusDevice){
        return;
    }

    if(auto *reply=modbusDevice->sendReadRequest(QModbusDataUnit(QModbusDataUnit::HoldingRegisters,startAddr,mdLen),decID)){
        if(!reply->isFinished()){
            connect(reply,&QModbusReply::finished,this,&WeightModbus::readReadySlot);
        }
        else {
            delete reply;
        }
    }
    else {
        qWarning().noquote()<<QString("[%1] Read error:<errCod=%2> ").arg(this->metaObject()->className(),modbusDevice->errorString());
    }
}

void WeightModbus::readReadySlot()
{
    auto reply=qobject_cast<QModbusReply*>(sender());
    if(!reply){
        return;
    }

    if (reply->error() == QModbusDevice::NoError) {
        const QModbusDataUnit unit = reply->result();

        QByteArray tmp,ba;

        for (uint i = 0; i < unit.valueCount(); i++) {

            ba =QString("%1").arg(unit.value(i),4,16,QLatin1Char('0')).toLatin1();
            tmp.append(QByteArray::fromHex(ba.toHex()).toUInt(0,16));

            if(ba.at(0)>'7'){
                ba="ffff"+ba;
            }

            if(4==i){
                /*****************************
                * @brief:总重
                ******************************/
                w=QByteArray::fromHex(ba.toHex()).toUInt(0,16);
            }
            else if (6==i) {
                /*****************************
                * @brief:偏载
                ******************************/
                y=QByteArray::fromHex(ba.toHex()).toUInt(0,16);
            }
            else if (7==i) {
                /*****************************
                * @brief:偏重
                ******************************/
                x=QByteArray::fromHex(ba.toHex()).toUInt(0,16);
            }
        }

        if(tmp!=buf){
            emit setPoundsSignal(x,y,w);
            buf=tmp;
        }

        tmp.clear();
        ba.clear();
    }
    else if (reply->error() == QModbusDevice::ProtocolError) {
        qWarning().noquote()<<QString("[%1] Read response error: %2 (Mobus exception: 0x%3)").arg(this->metaObject()->className(),reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16);
    }
    else {
        qWarning().noquote()<<QString("[%1] Read response error: %2 (code: 0x%3)").arg(this->metaObject()->className(),reply->errorString()).arg(reply->error(), -1, 16);
    }

    reply->deleteLater();
}

void WeightModbus::stateChanged(int state)
{
    bool status=false;

    if(state==QModbusDevice::ConnectedState){
        status=true;
        if(autoLintTimer){
            autoLintTimer->stop();
        }
        if(requestTimer){
            requestTimer->start(request);
        }
    }
    else {
        if(requestTimer){
            requestTimer->stop();
        }
        if(autoLintTimer){
            autoLintTimer->start(600);
        }
    }
    emit connectStateSignal(status);
}

void WeightModbus::autoLinkSlot()
{
    if(modbusDevice){
        modbusDevice->disconnectDevice();
        modbusDevice->connectDevice();
    }
}
