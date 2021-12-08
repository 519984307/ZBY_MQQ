#ifndef DATAINTERSERAILPORT_H
#define DATAINTERSERAILPORT_H

#include <QObject>

#include "DataInterSerailPort_global.h"

class DATAINTERSERAILPORT_EXPORT DataInterSerailPort:public QObject
{
    Q_OBJECT

public:
    DataInterSerailPort(QObject* parent = nullptr);
    ~DataInterSerailPort();

    ///
    /// \brief startSlave 打开串口
    /// \param portName 串口号
    /// \param baudRate 波特率
    /// \param dataBits 数据位
    /// \param stopBits 停止位
    /// \param parity 校验位
    /// \param flowControl 流控制
    ///
    void startSlave(QString portName,qint32 baudRate=9600,int dataBits=8,int stopBits=1,int parity=0,int flowControl=0);

signals:

    ///
    /// \brief getPoundsSignal 解析重量信息
    /// \param x
    /// \param y
    /// \param w
    ///
    void getPoundsSignal(int x,int y,int w);

    ///
    /// \brief startStatusSignal 串口打开状态
    /// \param status
    ///
    void startStatusSignal(bool status);

private:

    ///
    /// \brief firstBuf 上次数据流
    ///
    QByteArray firstBuf;

    ///
    /// \brief buf 串口数据流
    ///
    QByteArray buf;

    ///
    /// \brief frontBuf 上段数据流
    ///
    QByteArray xBuf,yBuf,wBuf;

    ///
    /// \brief pSerial 串口
    ///
    QSerialPort* pSerial;

    ///
    /// \brief autoLink 重连定时器
    ///
    QTimer* autoLink;

private slots:

    ///
    /// \brief receiveDataSlot 接收数据
    ///
    void receiveDataSlot();

    ///
    /// \brief autoLinkSlot 自动重连
    ///
    void autoLinkSlot();

    ///
    /// \brief errorSerialSlot 串口错误
    /// \param error
    ///
    void errorSerialSlot(QSerialPort::SerialPortError error);
};

#endif // DATAINTERSERAILPORT_H
