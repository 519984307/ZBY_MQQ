#include "dataintermodbus.h"

#include <iostream>
#include <algorithm>

DataInterModbus::DataInterModbus(QObject *parent)
{
    this->setParent(parent);

    modbusDevice = new QModbusTcpClient(this);

    pTd=new QThread(this);
    slave = new ModbusSlave(Q_NULLPTR);
    slave->moveToThread(pTd);
    pTd->start();

    connect(this,&DataInterModbus::setMoubusDataSignal,slave,&ModbusSlave::setMoubusDataSlot);
    connect(slave,&ModbusSlave::connectSlaveSignal,this,&DataInterModbus::connectSlaveSignal);

    requestTimer = new QTimer(this);
    requestTimer->setSingleShot(false);
    connect(requestTimer,&QTimer::timeout,this,&DataInterModbus::requestSlot);

    autoLintTimer = new QTimer(this);
    autoLintTimer->setSingleShot(true);
    connect(autoLintTimer,&QTimer::timeout,this,&DataInterModbus::autoLinkSlot);

    comState=false;
    slingLock=false;
    port = 502;
    decID = 1;
    startAddr = 1;
    mdLen = 10;
    request = 100;
    x = 0;
    y = 0;
    z = 0;
    lock = 0;
    sling = 0;
    box = 0;
}

DataInterModbus::~DataInterModbus()
{
    if(pTd){        
        pTd->exit();
    }

    buf.clear();
    data.clear();

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

    delete  slave;
    slave=nullptr;
}

void DataInterModbus::initModbus(const QString &addr, const qintptr &port, const qintptr &decID, const qintptr &startAddr, const qintptr &mdLen, const qintptr &request)
{
    address = addr;
    this->port = port ;
    this->decID = decID ;
    this->startAddr = startAddr;
    this->mdLen =mdLen ;
    this->request = request;
    bool status=false;

    /*****************************
    * @brief:启动从站服务器
    ******************************/
    if(slave){
        slave->initModbus(startAddr,mdLen,decID);
    }

    if(!modbusDevice){
        qCritical().noquote()<<QString("[%1] load modbusDevice failed").arg(this->metaObject()->className());
        return;
    }

    /*****************************
    * @brief:modbus链接状态
    ******************************/
    connect(modbusDevice,&QModbusClient::stateChanged,this,&DataInterModbus::stateChanged);

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

void DataInterModbus::requestSlot()
{
    if(!modbusDevice){
        return;
    }

    if(auto *reply=modbusDevice->sendReadRequest(QModbusDataUnit(QModbusDataUnit::HoldingRegisters,startAddr,mdLen),decID)){
        if(!reply->isFinished()){
            connect(reply,&QModbusReply::finished,this,&DataInterModbus::readReadySlot);
        }
        else {
            delete reply;
        }
    }
    else {
        qWarning().noquote()<<QString("[%1] Read error:<errCod=%2> ").arg(this->metaObject()->className(),modbusDevice->errorString());
    }
}

void DataInterModbus::readReadySlot()
{
    auto reply=qobject_cast<QModbusReply*>(sender());
    if(!reply){
        return;
    }

    if (reply->error() == QModbusDevice::NoError) {
        const QModbusDataUnit unit = reply->result();

        QByteArray ba;
        QByteArray tmp;
        QString str;

        for (uint i = 0; i < unit.valueCount(); i++) {
            if(0==i){
                /*****************************
                * @brief:作业状态
                ******************************/
                str =QString("%1").arg(unit.value(i),16,2,QLatin1Char('0'));

                /*****************************
                * @brief:串口正常才使用重量开闭锁
                ******************************/
                if(comState){
                    if(slingLock){
                        str[15]='1';
                        str[14]='0';
                    }
                    else {
                        str[15]='0';
                        str[14]='1';
                    }
                }

                std::reverse(str.begin(),str.end());
                /*****************************
                * @brief:开闭锁
                ******************************/
                if('1' == str.at(0)){
                    lock=1;
                }
                if('1' == str.at(1)){
                    lock=0;
                }
                /*****************************
                * @brief:着箱
                ******************************/
                box=('1' ==str.at(2))?1:0;

                if('1' ==str.at(4)){
                    sling=0;
                }
                if('1' ==str.at(5)){
                    sling=1;
                }
            }
            if(2==i || 4==i){
                ba =QString("%1").arg(unit.value(i),4,16,QLatin1Char('0')).toLatin1();
                if(ba.at(0)>'7'){
                    ba="ffff"+ba;
                }
            }

            if(2==i){
                /*****************************
                * @brief:吊具高度
                ******************************/
                z=QByteArray::fromHex(ba.toHex()).toUInt(0,16);
                ba.clear();
            }
            if(4==i){
                /*****************************
                * @brief:小车位置
                ******************************/
                x=QByteArray::fromHex(ba.toHex()).toUInt(0,16);
                ba.clear();
            }
            /*****************************
            * @brief:大车双字11-10
            ******************************/
            if(10==i){
                ba=QString("%1").arg(unit.value(i),4,16,QLatin1Char('0')).toLatin1();
            }
            if(11==i){
                ba=QString("%1").arg(unit.value(i),4,16,QLatin1Char('0')).toLatin1()+ba;
                y=QByteArray::fromHex(ba.toHex()).toInt(0,16);
                ba.clear();
            }

            /*****************************
            * @brief:重量正常才使用
            ******************************/
            if(comState){
                if(0 == i){
                    bool ok;
                    std::reverse(str.begin(),str.end());
                    int val = str.toInt(&ok,2);
                    update.append(QString("%1").arg(val,4,16,QLatin1Char('0')));
                    tmp.append(QString("%1").arg(val,4,16,QLatin1Char('0')).toLatin1());
                }
                else {
                    update.append(QString("%1").arg(unit.value(i),4,16,QLatin1Char('0')));
                    tmp.append(QString("%1").arg(unit.value(i),4,16,QLatin1Char('0')).toLatin1());
                }
            }
            else {
                update.append(QString("%1").arg(unit.value(i),4,16,QLatin1Char('0')));
                tmp.append(QString("%1").arg(unit.value(i),4,16,QLatin1Char('0')).toLatin1());
            }

        }

        if(tmp!=buf){
            data.insert("x",x);
            data.insert("y",y);
            data.insert("z",z);
            data.insert("lock",lock);
            data.insert("sling",sling);
            data.insert("box",box);

            emit setPlcStatusSginal(data);
            emit setMoubusDataSignal(QModbusDataUnit::HoldingRegisters,update);

            buf=tmp;
        }

        tmp.clear();
        ba.clear();
        data.clear();
        update.clear();
    }
    else if (reply->error() == QModbusDevice::ProtocolError) {
        qWarning().noquote()<<QString("[%1] Read response error: %2 (Mobus exception: 0x%3)").arg(this->metaObject()->className(),reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16);
    }
    else {
        qWarning().noquote()<<QString("[%1] Read response error: %2 (code: 0x%3)").arg(this->metaObject()->className(),reply->errorString()).arg(reply->error(), -1, 16);
    }

    reply->deleteLater();
}

void DataInterModbus::stateChanged(int state)
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
            autoLintTimer->start(500);
        }
    }
    emit connectStateSignal(status);
}

void DataInterModbus::autoLinkSlot()
{
    if(modbusDevice){
        modbusDevice->disconnectDevice();
        modbusDevice->connectDevice();
    }
}

void DataInterModbus::getLockStateSlot(bool state)
{
    slingLock=state;
}

void DataInterModbus::getComState(bool status)
{
    comState=status;
}
