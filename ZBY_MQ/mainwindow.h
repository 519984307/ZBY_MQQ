#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
#include "datainterchangeinterface.h"

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

    DataInterchangeInterface* mq;
    DataInterchangeInterface* tcp;

    void mqProcess(DataInterchangeInterface* mq);
    void tcpProcess(DataInterchangeInterface* tcp);
    void writeLog(const QString &msg);

    ///
    /// \brief statisticalLog 做工数据写入日志
    /// \param w
    ///
    void statisticalLog(int w);

private:
    Ui::MainWindow *ui;

    ///
    /// \brief dd 写入时间戳
    ///
    QString dd;

    ///
    /// \brief pLog 日志类
    ///
    QSharedPointer<LogController> pLog;

    ///
    /// \brief pPort 串口数据处理类
    ///
    QSharedPointer<DataInterSerailPort> pPort;

    ///
    /// \brief statistical 统计文件
    ///
    QFile statistical;

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
    /// \brief beating 过滤调动时间
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

    ///
    /// \brief workTimtOut 做功波动超时
    ///
    QTimer* workTimtOut;

signals:

    void  MQ_InitializationParameterSignal(const QString& address,const quint16& port,const int& serviceType,const bool& heartBeat, const int& serviceMode,const int& shortLink,const int& newline);
    void  TCP_InitializationParameterSignal(const QString& address,const quint16& port,const int& serviceType,const bool& heartBeat, const int& serviceMode,const int& shortLink,const int& newline);

    void releaseResourcesSignal();

    ///
    /// \brief toSendDataSignal 发送数据
    /// \param channel_number
    /// \param data
    ///
    void toSendDataSignal(int channel_number, const QString &data);


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
    /// \brief workTimeOutSlot 作业波动检测
    ///
    void workTimeOutSlot();

    ///
    /// \brief startStatusSlot 串口打开状态
    /// \param status
    ///
    void startStatusSlot(bool status);

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
};
#endif // MAINWINDOW_H
