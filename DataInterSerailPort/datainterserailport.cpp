#include "datainterserailport.h"

DataInterSerailPort::DataInterSerailPort(QObject* parent):QObject(parent)
{
    this->setParent(parent);

    autoLink=new QTimer(this);
    connect(autoLink,&QTimer::timeout,this,&DataInterSerailPort::autoLinkSlot);

    pSerial=new QSerialPort(this);
    connect(pSerial,&QSerialPort::readyRead,this,&DataInterSerailPort::receiveDataSlot);
    connect(pSerial,&QSerialPort::errorOccurred,this,&DataInterSerailPort::errorSerialSlot);
}

DataInterSerailPort::~DataInterSerailPort()
{
    if(pSerial!=nullptr && pSerial->isOpen()){
        pSerial->close();
    }

    autoLink->stop();
}

void DataInterSerailPort::startSlave(QString portName, qint32 baudRate, int dataBits, int stopBits, int parity, int flowControl)
{
    if(pSerial!=nullptr){
        pSerial->setPortName(portName);
        pSerial->setBaudRate(static_cast<QSerialPort::BaudRate>(baudRate));
        pSerial->setDataBits(static_cast<QSerialPort::DataBits>(dataBits));
        pSerial->setStopBits(static_cast<QSerialPort::StopBits>(stopBits));
        pSerial->setParity(static_cast<QSerialPort::Parity>(parity));
        pSerial->setFlowControl(static_cast<QSerialPort::FlowControl>(flowControl));

        if(!pSerial->open(QIODevice::ReadOnly)){
            qWarning().noquote()<<QString("Open %1 error<errCode=%2>").arg(portName,QString::number(pSerial->error()));

            emit startStatusSignal(false);
        }
        else {
            qInfo().noquote()<<QString("Open %1 sucess").arg(portName);

            emit startStatusSignal(true);
        }
    }
    else {
        qCritical().noquote()<<QString("Failed to initialize the serial port:%1. Procedure").arg(portName);
    }

}

void DataInterSerailPort::receiveDataSlot()
{
    QByteArray data=pSerial->readAll().toHex();

    buf.append(data);

    if(buf.size()>=44){

        if(firstBuf.mid(0,28)==buf.mid(0,28)){
            return;
        }
        else {
            firstBuf=buf;
        }

        if(buf.startsWith("7e") && buf.endsWith("0a")){
            int j=1;
            for(int i=4;i<buf.size();){
                QByteArray tmp=buf.mid(i,2);
                if(tmp== "1b"){
                    i=i+2;
                    int t1=tmp.toInt(0,16);
                    int t2=buf.mid(i,2).toInt(0,16);
                    tmp=QString("%1").arg(t1^t2,2,16,QLatin1Char('0')).toLatin1();
                }
                if(j<=4){
                    xBuf=tmp+xBuf;// .insert(4-j,tmp);
                }
                else if (j<=8) {
                    yBuf=tmp+yBuf;
                }
                else if (j<=12) {
                    wBuf=tmp+wBuf;
                }
                else {
                    break;
                }
                j++;
                i=i+2;
            }
        }
        buf.clear();
        data.clear();

        int x,y,w;

        x=QByteArray::fromHex(xBuf.toHex()).toUInt(0,16);
        y=QByteArray::fromHex(yBuf.toHex()).toUInt(0,16);
        w=QByteArray::fromHex(wBuf.toHex()).toUInt(0,16);

        emit getPoundsSignal(x,y,w);

        xBuf.clear();
        yBuf.clear();
        wBuf.clear();
    }
}

void DataInterSerailPort::autoLinkSlot()
{
    if(pSerial!=nullptr && pSerial->portName().isEmpty()){
        pSerial->open(QIODevice::ReadOnly);
    }
}

void DataInterSerailPort::errorSerialSlot(QSerialPort::SerialPortError error)
{
    QString msg="";
    switch (error) {
        case 0:
            msg=QString("No error occurred.");
        break;
        case 1:
            msg=QString("An error occurred while attempting to open an non-existing device.");
        break;
        case 2:
            msg=QString("An error occurred while attempting to open an already opened device by another process or a user not having enough permission and credentials to open.");
        break;
        case 3:
            msg=QString("An error occurred while attempting to open an already opened device in this object.");
        break;
        case  13:
            msg=QString("This error occurs when an operation is executed that can only be successfully performed if the device is open. This value was introduced in QtSerialPort 5.2.");
        break;
        case 4:
            msg=QString("Parity error detected by the hardware while reading data. This value is obsolete. We strongly advise against using it in new code.");
        break;
        case 5:
            msg=QString("Framing error detected by the hardware while reading data. This value is obsolete. We strongly advise against using it in new code.");
        break;
        case 6:
            msg=QString("Break condition detected by the hardware on the input line. This value is obsolete. We strongly advise against using it in new code.");
        break;
        case 7:
            msg=QString("An I/O error occurred while writing the data.");
        break;
        case 8:
            msg=QString("An I/O error occurred while reading the data.");
        break;
        case  9:
            msg=QString("An I/O error occurred when a resource becomes unavailable, e.g. when the device is unexpectedly removed from the system.");
        break;
        case 10:
            msg=QString("The requested device operation is not supported or prohibited by the running operating system.");
        break;
        case 12:
            msg=QString("A timeout error occurred. This value was introduced in QtSerialPort 5.2.");
        break;
        case 11:
            msg=QString("An unidentified error occurred.");
        break;
    }

    if(error>0){
        autoLink->start(15000);
    }
    qCritical().noquote()<<msg;
}
