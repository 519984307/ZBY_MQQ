#ifndef WEIGHTMODBUS_GLOBAL_H
#define WEIGHTMODBUS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtSerialBus/QModbusTcpClient>
#include <QtSerialBus/QModbusDataUnit>
#include <QtSerialBus/QModbusReply>
#include <QTimer>
#include <QDebug>

#if defined(WEIGHTMODBUS_LIBRARY)
#  define WEIGHTMODBUS_EXPORT Q_DECL_EXPORT
#else
#  define WEIGHTMODBUS_EXPORT Q_DECL_IMPORT
#endif

#endif // WEIGHTMODBUS_GLOBAL_H
