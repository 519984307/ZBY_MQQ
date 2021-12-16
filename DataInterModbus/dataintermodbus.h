#ifndef DATAINTERMODBUS_H
#define DATAINTERMODBUS_H

#include "DataInterModbus_global.h"
#include "modbusslave.h"

class DATAINTERMODBUS_EXPORT DataInterModbus:public QObject
{
    Q_OBJECT

public:
    DataInterModbus(QObject *parent=nullptr);
    ~DataInterModbus();

    ///
    /// \brief initModbus 初始化modbus
    /// \param addr
    /// \param port
    ///
    void initModbus(const QString &addr,const qintptr &port,  const qintptr &decID,  const qintptr &startAddr,  const qintptr &mdLen,  const qintptr &request);

signals:

    ///
    /// \brief connectStateSignal 从站链接状态
    /// \param addr
    /// \param status
    ///
    void connectStateSignal(bool status);

    ///
    /// \brief connectSlaveSignal 主机链接状态
    /// \param status
    ///
    void connectSlaveSignal(bool status);

    ///
    /// \brief setPlcStatusSginal 获取plc状态
    /// \param x 小车
    /// \param y 大车
    /// \param z 吊具
    /// \param lock 开闭锁
    /// \param sling 20/40状态
    /// \param box 着箱
    ///
    void setPlcStatusSginal(QMap<QString,int> data);

    ///
    /// \brief setMoubusDataSignal 设置modbus数据
    /// \param data
    ///
    void setMoubusDataSignal(QModbusDataUnit::RegisterType table,QStringList data);

private slots:

    ///
    /// \brief requestSlot 轮询数据
    ///
    void requestSlot();

    ///
    /// \brief readReadySlot 接收数据
    ///
    void readReadySlot();

    ///
    /// \brief stateChanged modbus链接状态
    ///
    void stateChanged(int state);

    ///
    /// \brief autoLinkSlot 自动重连
    ///
    void autoLinkSlot();

public slots:

    ///
    /// \brief getLockStateSlot 设置开闭锁状态
    /// \param state
    ///
    void getLockStateSlot(bool state);

    ///
    /// \brief getComState 设置串口状态到modbus，串口失败就使用modbus开闭锁信息
    /// \param status
    ///
    void getComState(bool status);

private:

    QThread *pTd;

    QModbusClient* modbusDevice;

    ModbusSlave* slave;

    ///
    /// \brief requestTimer 定时检索数据
    ///
    QTimer *requestTimer;

    ///
    /// \brief autoLintTimer 自动重连
    ///
    QTimer *autoLintTimer;

    ///
    /// \brief buf 接收的数据
    ///
    QByteArray buf;

    QStringList update;

    QString address;
    int port;
    int decID;
    int startAddr;
    int mdLen;
    int request;

    QMap<QString,int> data;

    int x;
    int y;
    int z;
    int lock;
    int sling;
    int box;

    ///
    /// \brief slingLock 磅重开闭锁
    ///
    bool slingLock;

    ///
    /// \brief comState 串口状态
    ///
    bool comState;
};

#endif // DATAINTERMODBUS_H
