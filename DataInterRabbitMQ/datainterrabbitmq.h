#ifndef DATAINTERRABBITMQ_H
#define DATAINTERRABBITMQ_H

#include "DataInterRabbitMQ_global.h"
#include "datainterchangeinterface.h"

#include "qamaqp/qamqpclient.h"
#include "qamaqp/qamqpexchange.h"
#include "qamaqp/qamqpqueue.h"

class DATAINTERRABBITMQ_EXPORT DataInterRabbitMQ:public DataInterchangeInterface
{
    Q_OBJECT
    Q_INTERFACES(DataInterchangeInterface)
    Q_PLUGIN_METADATA(IID DataInterchangeInterfaceIID)

public:

    DataInterRabbitMQ(QObject *parent=nullptr);
    ~DataInterRabbitMQ()Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

    ///
    /// \brief InitializationParameterSlot 初始化参数
    /// \param address 地址
    /// \param port 端口
    /// \param serviceType 服务类型
    /// \param heartBeat 心跳包 状态
    /// \param serviceMode 服务模式
    /// \param shortLink 短链接状态
    /// \param newline 换行符
    ///
    void  InitializationParameterSlot(const QString& address,const quint16& port,const int& serviceType,const bool& heartBeat, const int& serviceMode,const int& shortLink,const int& newline)Q_DECL_OVERRIDE;

    ///
    /// \brief toSendDataSlot 发送数据
    /// \param data 数据体
    ///
    void toSendDataSlot(int channel_number, const QString &data)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 释放资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

private:

    QAmqpClient m_client;
    QAmqpMessage::PropertyHash properties;
    QString sendData;
    QString addr;
    quint16 lport;
    int channel_number;

    bool isConnected;
    QString tmpMsg;

private slots:

    void clientDisconnected();

    void clientConnected();

    void queueDeclared();
};

#endif // DATAINTERRABBITMQ_H
