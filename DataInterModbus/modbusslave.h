#ifndef MODBUSSLAVE_H
#define MODBUSSLAVE_H

#include "DataInterModbus_global.h"
#include <QtSerialBus/QModbusServer>
#include <QObject>

class ModbusSlave : public QObject
{
    Q_OBJECT

public:
    explicit ModbusSlave(QObject *parent = nullptr);
    ~ModbusSlave();

    ///
    /// \brief initModbus 初始化Modbus从站，默认地址127.0.0.1:502
    ///
    void initModbus(int startAddr,int dataLen,int devID);

private:

    QModbusServer* modbusDevice;

    int decID;
    int startAddr;
    int mdLen;

private slots:

    ///
    /// \brief stateChangedSlot 链接状态
    /// \param state
    ///
    void stateChangedSlot(int state);

    ///
    /// \brief updateDataSlot 更新寄存器值
    /// \param table
    /// \param address
    /// \param size
    ///
    void updateDataSlot(QModbusDataUnit::RegisterType table,int address,int size);

    ///
    /// \brief errOccurredSlot 错误码
    /// \param newError
    ///
    void errOccurredSlot(QModbusDevice::Error newError);

public slots:

    ///
    /// \brief setMoubusDataSlot 设置modbus数据
    /// \param data
    ///
    void setMoubusDataSlot(QModbusDataUnit::RegisterType table,QStringList data);

signals:

    ///
    /// \brief connectSlaveSignal 主机链接状态
    /// \param status
    ///
    void connectSlaveSignal(bool status);

};

#endif // MODBUSSLAVE_H
