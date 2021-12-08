#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent):QTcpSocket(parent)
{
    this->setParent(parent);
}

void TcpClient::receiveDataSlot()
{
    QByteArray buf=readAll();

    if(buf.trimmed().startsWith('[')){
        QList<QByteArray> tmp=buf.split('|');
        if(tmp.count()==2){
            if(tmp[0].indexOf('L')!=-1){/* 找到设置通道标标志位 */
                channel_number=tmp[1].split(']')[0].toInt();
                emit setClientChannelNumberSignal(channel_number,this->socketDescriptor());
            }
            else if (tmp[0].indexOf('R')!=-1) {/* 找到取结果标志位 */
                if(tmp[1].split(']')[0].toInt()==channel_number){
                    emit getLastResultSignal(this->socketDescriptor());
                }
            }
        }
        /*****************************
        * @brief:收到抬杆信息
        ******************************/
        if(tmp.count()==1 && buf=="[+LF]"){
            emit signal_lifting();
        }
    }
    buf.clear();
}
