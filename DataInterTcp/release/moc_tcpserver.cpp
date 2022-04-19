/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpServer_t {
    QByteArrayData data[27];
    char stringdata0[347];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpServer_t qt_meta_stringdata_TcpServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TcpServer"
QT_MOC_LITERAL(1, 10, 13), // "messageSignal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "type"
QT_MOC_LITERAL(4, 30, 3), // "msg"
QT_MOC_LITERAL(5, 34, 18), // "connectCountSignal"
QT_MOC_LITERAL(6, 53, 5), // "count"
QT_MOC_LITERAL(7, 59, 24), // "signal_sendDataSuccToLog"
QT_MOC_LITERAL(8, 84, 14), // "channel_number"
QT_MOC_LITERAL(9, 99, 6), // "result"
QT_MOC_LITERAL(10, 106, 15), // "linkStateSingal"
QT_MOC_LITERAL(11, 122, 7), // "address"
QT_MOC_LITERAL(12, 130, 4), // "port"
QT_MOC_LITERAL(13, 135, 5), // "state"
QT_MOC_LITERAL(14, 141, 14), // "signal_lifting"
QT_MOC_LITERAL(15, 156, 16), // "disconnectedSlot"
QT_MOC_LITERAL(16, 173, 26), // "setClientChannelNumberSlot"
QT_MOC_LITERAL(17, 200, 7), // "qintptr"
QT_MOC_LITERAL(18, 208, 8), // "socketID"
QT_MOC_LITERAL(19, 217, 17), // "getLastResultSlot"
QT_MOC_LITERAL(20, 235, 7), // "socktID"
QT_MOC_LITERAL(21, 243, 14), // "toSendDataSlot"
QT_MOC_LITERAL(22, 258, 13), // "heartbeatSlot"
QT_MOC_LITERAL(23, 272, 23), // "setHeartPacketStateSlot"
QT_MOC_LITERAL(24, 296, 20), // "releaseResourcesSlot"
QT_MOC_LITERAL(25, 317, 21), // "slot_setMessageFormat"
QT_MOC_LITERAL(26, 339, 7) // "newline"

    },
    "TcpServer\0messageSignal\0\0type\0msg\0"
    "connectCountSignal\0count\0"
    "signal_sendDataSuccToLog\0channel_number\0"
    "result\0linkStateSingal\0address\0port\0"
    "state\0signal_lifting\0disconnectedSlot\0"
    "setClientChannelNumberSlot\0qintptr\0"
    "socketID\0getLastResultSlot\0socktID\0"
    "toSendDataSlot\0heartbeatSlot\0"
    "setHeartPacketStateSlot\0releaseResourcesSlot\0"
    "slot_setMessageFormat\0newline"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       5,    1,   84,    2, 0x06 /* Public */,
       7,    2,   87,    2, 0x06 /* Public */,
      10,    3,   92,    2, 0x06 /* Public */,
      14,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  100,    2, 0x0a /* Public */,
      16,    2,  101,    2, 0x0a /* Public */,
      19,    1,  106,    2, 0x0a /* Public */,
      21,    2,  109,    2, 0x0a /* Public */,
      22,    0,  114,    2, 0x0a /* Public */,
      23,    1,  115,    2, 0x0a /* Public */,
      24,    0,  118,    2, 0x0a /* Public */,
      25,    1,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::Bool,   11,   12,   13,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 17,    8,   18,
    QMetaType::Void, 0x80000000 | 17,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,

       0        // eod
};

void TcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->connectCountSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signal_sendDataSuccToLog((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->linkStateSingal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->signal_lifting(); break;
        case 5: _t->disconnectedSlot(); break;
        case 6: _t->setClientChannelNumberSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 7: _t->getLastResultSlot((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 8: _t->toSendDataSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->heartbeatSlot(); break;
        case 10: _t->setHeartPacketStateSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->releaseResourcesSlot(); break;
        case 12: _t->slot_setMessageFormat((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpServer::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::messageSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::connectCountSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::signal_sendDataSuccToLog)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(const QString & , quint16 , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::linkStateSingal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::signal_lifting)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpServer::staticMetaObject = { {
    &QTcpServer::staticMetaObject,
    qt_meta_stringdata_TcpServer.data,
    qt_meta_data_TcpServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServer.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int TcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void TcpServer::messageSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpServer::connectCountSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpServer::signal_sendDataSuccToLog(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpServer::linkStateSingal(const QString & _t1, quint16 _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpServer::signal_lifting()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
