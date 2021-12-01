#ifndef DATAINTERSERAILPORT_GLOBAL_H
#define DATAINTERSERAILPORT_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include <QDebug>

#if defined(DATAINTERSERAILPORT_LIBRARY)
#  define DATAINTERSERAILPORT_EXPORT Q_DECL_EXPORT
#else
#  define DATAINTERSERAILPORT_EXPORT Q_DECL_IMPORT
#endif

#endif // DATAINTERSERAILPORT_GLOBAL_H
