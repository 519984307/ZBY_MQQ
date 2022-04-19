#include "datainterport.h"

DataInterPort::DataInterPort(QObject *parent)
{
    this->setParent(parent);
    devHandle=nullptr;
}

DataInterPort::~DataInterPort()
{
    //libusb_exit(nullptr);
}

QString DataInterPort::InterfaceType()
{
    return QString("PORT");
}

void DataInterPort::InitializationParameterSlot(const QString &address, const quint16 &port, const int &serviceType, const bool &heartBeat, const int &serviceMode, const int &shortLink, const int &newline)
{
    Q_UNUSED(address)
    Q_UNUSED(port)
    Q_UNUSED(serviceType)
    Q_UNUSED(heartBeat)
    Q_UNUSED(serviceMode)
    Q_UNUSED(shortLink)
    Q_UNUSED(newline)


    qDebug()<<serviceMode;
    qDebug()<<serviceType;

    //bool ok;
    QString vid=QString::number(serviceMode,16).right(4);
    QString pid=QString::number(serviceType,16).right(4);
    qDebug()<<vid;

    int ret=libusb_init(nullptr);
    if(ret<0){
        qWarning().noquote()<<QString("[%1] Failed to init libusb").arg(this->metaObject()->className());
        return;
    }
    else {
        qInfo().noquote()<<QString("[%1] Succeeded to init libusb").arg(this->metaObject()->className());
    }

    print_dev();
    devHandle=getDevice(0x05C6,0XF007);
    if(!devHandle){
        qWarning().noquote()<<QString("[%1] Failed to locate device").arg(this->metaObject()->className());
        libusb_exit(nullptr);
    }
    else {
        qInfo().noquote()<<QString("[%1] Succeeded to locate device").arg(this->metaObject()->className());
    }
}

void DataInterPort::toSendDataSlot(int channel_number, const QString &data)
{
    Q_UNUSED(channel_number)

    if(devHandle){
        int r=0;
        int outsize=0;
        QByteArray tmpArr=data.toLatin1();
        qDebug()<<tmpArr;

        unsigned char buf[5] = {0x04, 0x00, 0x06, 0x06, 0x00};
        outsize=sizeof(buf);
        r=libusb_bulk_transfer(devHandle,0x01,buf,outsize,&outsize,3000);
        if(r<0){
            qWarning().noquote()<<QString("[%1] Failed to write data errCode<%2>").arg(this->metaObject()->className(),libusb_error_name(r));
        }
        else {
            qInfo().noquote()<<QString("[%1] success: bulk write %2 bytes").arg(this->metaObject()->className(),QString::number(outsize));
        }
    }
}

void DataInterPort::releaseResourcesSlot()
{
    libusb_exit(nullptr);
}

void DataInterPort::getWeightToDataSlot(const int& x, const int& y ,const int& w)
{
    Q_UNUSED(x)
    Q_UNUSED(y)
    Q_UNUSED(w)
}

void DataInterPort::print_dev()
{
    libusb_device **devs;
    ssize_t cnt;

    cnt=libusb_get_device_list(nullptr,&devs);
    if(cnt<0){
        return;
    }

    libusb_device *dev;
    int i=0;
    while ((dev = devs[i++]) != NULL) {
        struct libusb_device_descriptor desc;
        int r = libusb_get_device_descriptor(dev, &desc);
        if (r < 0) {
            qDebug().noquote()<<QString("[%1] failed to get device descriptor!").arg(this->metaObject()->className());
            return;
        }

        qDebug("%04x:%04x (bus %d, device %d)\n",
               desc.idVendor, desc.idProduct,
               libusb_get_bus_number(dev), libusb_get_device_address(dev));
    }
    libusb_free_device_list(devs, 1);
}

libusb_device_handle *DataInterPort::getDevice(int vid, int pid)
{
    int i = 0;
    ssize_t cnt;
    libusb_device *dev;
    libusb_device **devs;
    libusb_device_handle* handle = NULL;

    cnt = libusb_get_device_list(NULL, &devs);
    if (cnt < 0) {
        qWarning().noquote()<<QString("[%1] Failed libusb_get_device_list").arg(this->metaObject()->className());
        return(0);
    }

    while ((dev = devs[i++]) != NULL) {
        struct libusb_device_descriptor desc;
        int ret = libusb_get_device_descriptor(dev, &desc);
        if (ret < 0) {
            qWarning().noquote()<<QString("[%1] Failed libusb_get_device_descriptor").arg(this->metaObject()->className());
            continue;
        }
        if(desc.idVendor == vid && desc.idProduct == pid) {
            int ret = libusb_open(dev, &handle);
            if (ret < 0) {
                qWarning().noquote()<<QString("[%1] Failed libusb_open: %2\n\r").arg(this->metaObject()->className(),QString::number(ret));
                break;
            }
            #ifndef Q_OS_WIN32
                libusb_detach_kernel_driver(handle, 0);
            #endif
            ret = libusb_claim_interface(handle,0);
            if (ret < 0) {
                libusb_close(handle);
                handle=NULL;
                break;
            }
            break;
        }
    }
    libusb_free_device_list(devs, 1);
    return(handle);
}
