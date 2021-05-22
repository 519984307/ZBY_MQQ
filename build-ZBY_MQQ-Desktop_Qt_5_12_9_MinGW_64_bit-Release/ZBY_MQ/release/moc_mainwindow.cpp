/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ZBY_MQQ/ZBY_MQ/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[349];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 32), // "MQ_InitializationParameterSignal"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 7), // "address"
QT_MOC_LITERAL(4, 53, 4), // "port"
QT_MOC_LITERAL(5, 58, 11), // "serviceType"
QT_MOC_LITERAL(6, 70, 9), // "heartBeat"
QT_MOC_LITERAL(7, 80, 11), // "serviceMode"
QT_MOC_LITERAL(8, 92, 9), // "shortLink"
QT_MOC_LITERAL(9, 102, 7), // "newline"
QT_MOC_LITERAL(10, 110, 33), // "TCP_InitializationParameterSi..."
QT_MOC_LITERAL(11, 144, 22), // "releaseResourcesSignal"
QT_MOC_LITERAL(12, 167, 16), // "toSendDataSignal"
QT_MOC_LITERAL(13, 184, 14), // "channel_number"
QT_MOC_LITERAL(14, 199, 4), // "data"
QT_MOC_LITERAL(15, 204, 18), // "socketReadDataSlot"
QT_MOC_LITERAL(16, 223, 6), // "result"
QT_MOC_LITERAL(17, 230, 22), // "MQ_socketLinkStateSlot"
QT_MOC_LITERAL(18, 253, 5), // "state"
QT_MOC_LITERAL(19, 259, 23), // "TCP_socketLinkStateSlot"
QT_MOC_LITERAL(20, 283, 15), // "slot_newLogText"
QT_MOC_LITERAL(21, 299, 9), // "QtMsgType"
QT_MOC_LITERAL(22, 309, 4), // "type"
QT_MOC_LITERAL(23, 314, 4), // "time"
QT_MOC_LITERAL(24, 319, 5), // "value"
QT_MOC_LITERAL(25, 325, 23) // "on_pushButton_3_clicked"

    },
    "MainWindow\0MQ_InitializationParameterSignal\0"
    "\0address\0port\0serviceType\0heartBeat\0"
    "serviceMode\0shortLink\0newline\0"
    "TCP_InitializationParameterSignal\0"
    "releaseResourcesSignal\0toSendDataSignal\0"
    "channel_number\0data\0socketReadDataSlot\0"
    "result\0MQ_socketLinkStateSlot\0state\0"
    "TCP_socketLinkStateSlot\0slot_newLogText\0"
    "QtMsgType\0type\0time\0value\0"
    "on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   59,    2, 0x06 /* Public */,
      10,    7,   74,    2, 0x06 /* Public */,
      11,    0,   89,    2, 0x06 /* Public */,
      12,    2,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    2,   95,    2, 0x08 /* Private */,
      17,    3,  100,    2, 0x08 /* Private */,
      19,    3,  107,    2, 0x08 /* Private */,
      20,    3,  114,    2, 0x08 /* Private */,
      25,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::Int, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::Int, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::Bool,    3,    4,   18,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::Bool,    3,    4,   18,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QDateTime, QMetaType::QString,   22,   23,   24,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MQ_InitializationParameterSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const bool(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5])),(*reinterpret_cast< const int(*)>(_a[6])),(*reinterpret_cast< const int(*)>(_a[7]))); break;
        case 1: _t->TCP_InitializationParameterSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const bool(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5])),(*reinterpret_cast< const int(*)>(_a[6])),(*reinterpret_cast< const int(*)>(_a[7]))); break;
        case 2: _t->releaseResourcesSignal(); break;
        case 3: _t->toSendDataSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->socketReadDataSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->MQ_socketLinkStateSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->TCP_socketLinkStateSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: _t->slot_newLogText((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QString & , const quint16 & , const int & , const bool & , const int & , const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::MQ_InitializationParameterSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & , const quint16 & , const int & , const bool & , const int & , const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::TCP_InitializationParameterSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::releaseResourcesSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::toSendDataSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::MQ_InitializationParameterSignal(const QString & _t1, const quint16 & _t2, const int & _t3, const bool & _t4, const int & _t5, const int & _t6, const int & _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::TCP_InitializationParameterSignal(const QString & _t1, const quint16 & _t2, const int & _t3, const bool & _t4, const int & _t5, const int & _t6, const int & _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::releaseResourcesSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::toSendDataSignal(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
