#ifndef LOGCONTROLLER_GLOBAL_H
#define LOGCONTROLLER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LOGCONTROLLER_LIBRARY)
#  define LOGCONTROLLER_EXPORT Q_DECL_EXPORT
#else
#  define LOGCONTROLLER_EXPORT Q_DECL_IMPORT
#endif

#endif // LOGCONTROLLER_GLOBAL_H