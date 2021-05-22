#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDir>
#include <QPluginLoader>
#include <QDebug>
#include <QDateTime>
#include <QCloseEvent>
#include <QPointer>
#include <QSharedPointer>

#include "../LogController/logcontroller.h"
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

private:
    Ui::MainWindow *ui;

    ///
    /// \brief pLog 日志
    ///
    QSharedPointer<LogController> pLog;

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

    void MQ_socketLinkStateSlot(const QString &address,quint16 port,bool state);
    void TCP_socketLinkStateSlot(const QString &address,quint16 port,bool state);

    void slot_newLogText(QtMsgType type,QDateTime time,QString value);
    void on_pushButton_3_clicked();
};
#endif // MAINWINDOW_H
