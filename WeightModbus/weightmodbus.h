#ifndef WEIGHTMODBUS_H
#define WEIGHTMODBUS_H

#include "WeightModbus_global.h"

class WEIGHTMODBUS_EXPORT WeightModbus:public QObject
{
    Q_OBJECT

public:
    WeightModbus(QObject *parent=nullptr);
    ~WeightModbus();

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
    /// \brief setPoundsSignal 解析重量信息
    /// \param x
    /// \param y
    /// \param w
    ///
    void setPoundsSignal(int x,int y,int w);

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

private:

    QModbusClient* modbusDevice;

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

    QString address;
    int port;
    int decID;
    int startAddr;
    int mdLen;
    int request;

    int x,y,w;
};

#endif // WEIGHTMODBUS_H
