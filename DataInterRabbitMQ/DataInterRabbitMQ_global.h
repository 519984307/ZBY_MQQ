#ifndef DATAINTERRABBITMQ_GLOBAL_H
#define DATAINTERRABBITMQ_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QPointer>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QSharedPointer>
#include <QJsonArray>

#if defined(DATAINTERRABBITMQ_LIBRARY)
#  define DATAINTERRABBITMQ_EXPORT Q_DECL_EXPORT
#else
#  define DATAINTERRABBITMQ_EXPORT Q_DECL_IMPORT
#endif

#endif // DATAINTERRABBITMQ_GLOBAL_H
