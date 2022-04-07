#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QDir>
#include <QPluginLoader>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QCloseEvent>
#include <QPointer>
#include <QSharedPointer>
#include <QSettings>
#include <QFile>
#include <QStandardPaths>
#include <QtConcurrent>

#include "../LogController/logcontroller.h"
#include "../DataInterSerailPort/datainterserailport.h"
#include "../DataInterModbus/dataintermodbus.h"
#include "../WeightModbus/weightmodbus.h"
#include "datainterchangeinterface.h"

#include "positiondialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent *event)Q_DECL_OVERRIDE;

private:

    ///
    /// \brief mqProcess mq线程处理
    /// \param mq
    ///
    void mqProcess(DataInterchangeInterface* mq);

    ///
    /// \brief tcpProcess tcp线程处理
    /// \param tcp
    ///
    void tcpProcess(DataInterchangeInterface* tcp);

    ///
    /// \brief writeLog 日志
    /// \param msg
    ///
    void writeLog(const QString &msg);

    ///
    /// \brief statisticalLog 做工数据写入日志
    /// \param w
    ///
    void statisticalLog(QString data);

    ///
    /// \brief setting 初始化参数
    ///
    void setting();

private:

    Ui::MainWindow *ui;

    ///
    /// \brief x x轴偏载
    ///
    int x;

    ///
    /// \brief y y轴偏心
    ///
    int y;

    ///
    /// \brief w 重量
    ///
    int w;

    ///
    /// \brief xx 小车位置
    ///
    int xx;

    ///
    /// \brief yy 打车位置
    ///
    int yy;

    ///
    /// \brief zz 吊具位置
    ///
    int zz;

    ///
    /// \brief unLockx 解锁小车位
    ///
    int unLockx;

    ///
    /// \brief unLocky 解锁大车位
    ///
    int unLocky;

    ///
    /// \brief unLockz 解锁吊具高度
    ///
    int unLockz;

    ///
    /// \brief sUnLockx 起始小车位置
    ///
    int sUnLockx;

    ///
    /// \brief sUnLocky 起始大车位置
    ///
    int sUnLocky;

    ///
    /// \brief sUnLockz 起始吊具位置
    ///
    int sUnLockz;

    ///
    /// \brief mq MQ接口处理类
    ///
    DataInterchangeInterface* mq;

    ///
    /// \brief tcp TCP接口处理类
    ///
    DataInterchangeInterface* tcp;

    ///
    /// \brief pLog 日志类
    ///
    QSharedPointer<LogController> pLog;

    ///
    /// \brief pPort 串口数据处理类
    ///
    QSharedPointer<DataInterSerailPort> pPort;

    ///
    /// \brief pModbus PLC数据处理类
    ///
    QSharedPointer<DataInterModbus> pModbus;

    ///
    /// \brief pModbus 磅重MODBUS数据处理类
    ///
    QSharedPointer<WeightModbus> pWeiModbus;

    ///
    /// \brief dd 写入时间戳
    ///
    QString dd;

    ///
    /// \brief statistical 统计文件
    ///
    QFile statistical;

    ///
    /// \brief weightModel 磅重模式，0：com,1:modbus
    ///
    int weightModel;

    ///
    /// \brief isSucess 作业是否完成
    ///
    bool isSucess;


    //MQ

    ///
    /// \brief MQPort mq端口
    ///
    int MQPort;

    ///
    /// \brief MQAddr mq地址
    ///
    QString MQAddr;

    ///
    /// \brief MQUser mq用户
    ///
    QString MQUser;

    ///
    /// \brief MQPass mq密码
    ///
    QString MQPass;

    ///
    /// \brief MQHost mq主机名
    ///
    QString MQHost;

    ///
    /// \brief Channel 通道号，附加到队列名
    ///
    int Channel;

    ///
    /// \brief TCPPort tcp端口号
    ///
    int TCPPort;

    ///
    /// \brief TCPAddr tcp地址
    ///
    QString TCPAddr;


    //com

    ///
    /// \brief PortName 端口号
    ///
    QString PortName;

    ///
    /// \brief PortBaud 波特率
    ///
    qint32 PortBaud;

    ///
    /// \brief PortData 数据位
    ///
    int PortData;

    ///
    /// \brief PortStop 停止位
    ///
    int PortStop;

    ///
    /// \brief PortParity 校验位
    ///
    int PortParity;

    ///
    /// \brief weight 最低重量判断作业
    ///
    int weight;

    ///
    /// \brief beating 过滤波动时间
    ///
    int beating;

    ///
    /// \brief batch 做工次数
    ///
    int batch;

    ///
    /// \brief work 做工
    ///
    bool work;

    //modbus

    ///
    /// \brief modbusAddr 地址
    ///
    QString modbusAddr;

    ///
    /// \brief modbusPort 端口
    ///
    int modbusPort;

    ///
    /// \brief decID 设备地址
    ///
    int decID;

    ///
    /// \brief startAddr 数据起始地址
    ///
    int startAddr;

    ///
    /// \brief mdLen 数据长度
    ///
    int mdLen;

    ///
    /// \brief request 轮询时间
    ///
    int request;

    ///
    /// \brief iso 没有检测到箱型,指定默认箱型
    ///
    int iso;

    //Weight modbus

    ///
    /// \brief modbusAddr_weight 地址
    ///
    QString modbusAddr_weight;

    ///
    /// \brief modbusPort_weight 端口
    ///
    int modbusPort_weight;

    ///
    /// \brief decID_weight 设备地址
    ///
    int decID_weight;

    ///
    /// \brief startAddr_weight 数据起始地址
    ///
    int startAddr_weight;

    ///
    /// \brief mdLen_weight 数据长度
    ///
    int mdLen_weight;

    ///
    /// \brief request_weight 轮询时间
    ///
    int request_weight;
    
    ///
    /// \brief validTime_weight 重量有效时间
    ///
    int validTime_weight;

    ///
    /// \brief set_weight 是否设置重量
    ///
    int set_weight;

signals:

    void  MQ_InitializationParameterSignal(const QString& address,const quint16& port,const int& serviceType,const bool& heartBeat, const int& serviceMode,const int& shortLink,const int& newline);
    void  TCP_InitializationParameterSignal(const QString& address,const quint16& port,const int& serviceType,const bool& heartBeat, const int& serviceMode,const int& shortLink,const int& newline);

    void releaseResourcesSignal();

    ///
    /// \brief toSendDataSignal 发送数据
    /// \param channel_number
    /// \param data
    ///
    void toSendDataSignal(int channel_number,const QString &data);

    ///
    /// \brief setLockStateSignal 设置开闭锁状态
    /// \param state
    ///
    void setLockStateSignal(bool state);

    ///
    /// \brief setWeightToSignal 写入重量数据到MQ
    /// \param x
    /// \param y
    /// \param w
    ///
    void setWeightToSignal(double x, double y ,double w);

    ///
    /// \brief updateModbusSignal 更新modbus
    /// \param x
    /// \param y
    /// \param z
    ///
    void updateModbusSignal(float x,float y,float z);


private slots:

    ///
    /// \brief socketReadDataSlot 接受数据
    /// \param data 数据体
    ///
    void socketReadDataSlot(int channel_number,const QString& result);

    ////
    /// \brief getPoundsSlot 获取磅重
    /// \param x
    /// \param y
    /// \param w
    ///
    void getPoundsSlot(int x,int y,int w);

    ///
    /// \brief getPlcStatusSlot 获取plc状态
    /// \param x 小车
    /// \param y 大车
    /// \param z 吊具
    /// \param lock 开闭锁
    /// \param sling 20/40状态
    /// \param box 着箱
    ///
    void getPlcStatusSlot(QMap<QString, int> msg);

    ///
    /// \brief startStatusSlot 串口打开状态
    /// \param status
    ///
    void startStatusSlot(bool status);

    ///
    /// \brief modbusStatusSlot modbus打开状态
    /// \param status
    ///
    void modbusStatusSlot(bool status);

    ///
    /// \brief connectSlaveSlot 主机链接状态
    /// \param status
    ///
    void connectSlaveSlot(bool status);

    ///
    /// \brief MQ_socketLinkStateSlot MQ链接状态
    /// \param address
    /// \param port
    /// \param state
    ///
    void MQ_socketLinkStateSlot(const QString &address,quint16 port,bool state);

    ///
    /// \brief TCP_socketLinkStateSlot TCP链接状态
    /// \param address
    /// \param port
    /// \param state
    ///
    void TCP_socketLinkStateSlot(const QString &address,quint16 port,bool state);

    ///
    /// \brief slot_newLogText 状态写入日志
    /// \param type
    /// \param time
    /// \param value
    ///
    void slot_newLogText(QtMsgType type,QDateTime time,QString value);

    ///
    /// \brief on_pushButton_3_clicked 清除日志
    ///
    void on_pushButton_3_clicked();

    ///
    /// \brief on_checkBox_stateChanged 显示隐藏日志
    /// \param arg1
    ///
    void on_checkBox_stateChanged(int arg1);

    ///
    /// \brief Weight_validTimeSlot
    ///
    void Weight_validTimeSlot();

    ///
    /// \brief on_pushButton_clicked 显示位置图
    /// \param checked
    ///
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
