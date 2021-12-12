#ifndef DATAINTERMODBUS_GLOBAL_H
#define DATAINTERMODBUS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtSerialBus/QModbusTcpClient>
#include <QtSerialBus/QModbusTcpServer>
#include <QtSerialBus/QModbusDataUnitMap>
#include <QtSerialBus/QModbusDataUnit>
#include <QtSerialBus/QModbusReply>
#include <QTimer>
#include <QThread>
#include <QDebug>

#if defined(DATAINTERMODBUS_LIBRARY)
#  define DATAINTERMODBUS_EXPORT Q_DECL_EXPORT
#else
#  define DATAINTERMODBUS_EXPORT Q_DECL_IMPORT
#endif

#endif // DATAINTERMODBUS_GLOBAL_H
