#include "modbusslave.h"

ModbusSlave::ModbusSlave(QObject *parent) : QObject(parent)
{
    this->setParent(parent);

    modbusDevice = QSharedPointer<QModbusTcpServer> (new QModbusTcpServer());
}

ModbusSlave::~ModbusSlave()
{
    if(modbusDevice){
        modbusDevice->disconnectDevice();
    }
}

void ModbusSlave::initModbus(int startAddr, int dataLen, int devID)
{
    this->startAddr=startAddr;
    this->mdLen=dataLen;
    this->decID=devID;

    if(!modbusDevice){
        qCritical().noquote()<<QString("[%1] load modbusDevice failed").arg(this->metaObject()->className());
        return;
    }
    else {
        QModbusDataUnitMap reg;
        reg.insert(QModbusDataUnit::Coils, { QModbusDataUnit::Coils, startAddr, static_cast<quint16>(dataLen) });
        reg.insert(QModbusDataUnit::DiscreteInputs, { QModbusDataUnit::DiscreteInputs, startAddr, static_cast<quint16>(dataLen) });
        reg.insert(QModbusDataUnit::InputRegisters, { QModbusDataUnit::InputRegisters, startAddr, static_cast<quint16>(dataLen) });
        reg.insert(QModbusDataUnit::HoldingRegisters, { QModbusDataUnit::HoldingRegisters, startAddr, static_cast<quint16>(dataLen) });

        modbusDevice->setMap(reg);
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter,"127.0.0.1");
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter,503);
        modbusDevice->setServerAddress(devID);

        /*****************************
        * @brief:设备链接状态
        ******************************/
        connect(modbusDevice.data(),&QModbusServer::stateChanged,this,&ModbusSlave::stateChangedSlot);
        connect(modbusDevice.data(),&QModbusServer::errorOccurred,this,&ModbusSlave::errOccurredSlot);
        connect(modbusDevice.data(),&QModbusServer::dataWritten,this,&ModbusSlave::updateDataSlot);

        modbusDevice->connectDevice();
    }
}

void ModbusSlave::stateChangedSlot(int state)
{
    if(state == QModbusDevice::UnconnectedState){
        emit connectSlaveSignal(false);
    }
    else if (state == QModbusDevice::ConnectedState) {
        emit connectSlaveSignal(true);
    }
}

void ModbusSlave::updateDataSlot(QModbusDataUnit::RegisterType table, int address, int size)
{
    for (int i = 0; i < size; ++i) {
        quint16 value;
        QString text;
        switch (table) {
        case QModbusDataUnit::Coils:
            modbusDevice->data(QModbusDataUnit::Coils, address + i, &value);
            break;
        case QModbusDataUnit::HoldingRegisters:
            modbusDevice->data(QModbusDataUnit::HoldingRegisters, address + i, &value);
            break;
        default:
            break;
        }
    }
}

void ModbusSlave::errOccurredSlot(QModbusDevice::Error newError)
{
    if(newError == QModbusDevice::NoError || !modbusDevice){
        emit connectSlaveSignal(true);
    }
    else {
        qWarning().noquote()<<QString("[%1] %2:moubus slave error=<errCode=%3>").arg(this->metaObject()->className(),"127.0.0.1",modbusDevice->errorString());
        emit connectSlaveSignal(false);
    }
}

void ModbusSlave::setMoubusDataSlot(QModbusDataUnit::RegisterType table, QStringList data)
{
    bool ok;
    for(int i=0;i<data.size();++i){
        QString tmp=data.at(i);
        modbusDevice->setData(table, startAddr + i,tmp.toInt(&ok,16));
    }
}
