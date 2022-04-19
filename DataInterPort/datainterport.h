#ifndef DATAINTERPORT_H
#define DATAINTERPORT_H

#include "DataInterPort_global.h"
#include "datainterchangeinterface.h"
#include "libusb.h"

class DATAINTERPORT_EXPORT DataInterPort:public DataInterchangeInterface
{
    Q_OBJECT
    Q_INTERFACES(DataInterchangeInterface)
    Q_PLUGIN_METADATA(IID DataInterchangeInterfaceIID)

public:

    DataInterPort(QObject* parent=nullptr);
    ~DataInterPort()Q_DECL_OVERRIDE;

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
    void toSendDataSlot(int channel_number,const QString &data)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 释放资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

    ///
    /// \brief setWeightToMQSlot 写入重量数据到
    /// \param x
    /// \param y
    /// \param w
    ///
    void getWeightToDataSlot(const int& x, const int& y ,const int& w)Q_DECL_OVERRIDE;

private:

    ///
    /// \brief print_dev 显示查找的USB列表
    /// \param devs
    ///
    void print_dev();

    ///
    /// \brief handle 打开的USB句柄
    ///
    libusb_device_handle *devHandle;

    libusb_device_handle* getDevice(int vid, int pid);
};

#endif // DATAINTERPORT_H
