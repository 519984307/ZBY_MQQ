#ifndef DATAINTERTCP_GLOBAL_H
#define DATAINTERTCP_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QSharedPointer>
#include <QJsonArray>

#include <QSharedPointer>
#include <QDebug>
#include <QPointer>

#if defined(DATAINTERTCP_LIBRARY)
#  define DATAINTERTCP_EXPORT Q_DECL_EXPORT
#else
#  define DATAINTERTCP_EXPORT Q_DECL_IMPORT
#endif

#endif // DATAINTERTCP_GLOBAL_H
