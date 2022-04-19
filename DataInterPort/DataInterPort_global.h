#ifndef DATAINTERPORT_GLOBAL_H
#define DATAINTERPORT_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QDebug>

#if defined(DATAINTERPORT_LIBRARY)
#  define DATAINTERPORT_EXPORT Q_DECL_EXPORT
#else
#  define DATAINTERPORT_EXPORT Q_DECL_IMPORT
#endif

#endif // DATAINTERPORT_GLOBAL_H
