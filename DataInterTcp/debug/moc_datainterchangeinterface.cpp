/****************************************************************************
** Meta object code from reading C++ file 'datainterchangeinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../datainterchangeinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datainterchangeinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataInterchangeInterface_t {
    QByteArrayData data[30];
    char stringdata0[363];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataInterchangeInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataInterchangeInterface_t qt_meta_stringdata_DataInterchangeInterface = {
    {
QT_MOC_LITERAL(0, 0, 24), // "DataInterchangeInterface"
QT_MOC_LITERAL(1, 25, 13), // "messageSignal"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 4), // "type"
QT_MOC_LITERAL(4, 45, 3), // "msg"
QT_MOC_LITERAL(5, 49, 15), // "linkStateSingal"
QT_MOC_LITERAL(6, 65, 7), // "address"
QT_MOC_LITERAL(7, 73, 4), // "port"
QT_MOC_LITERAL(8, 78, 5), // "state"
QT_MOC_LITERAL(9, 84, 18), // "connectCountSignal"
QT_MOC_LITERAL(10, 103, 5), // "count"
QT_MOC_LITERAL(11, 109, 16), // "toSendDataSignal"
QT_MOC_LITERAL(12, 126, 14), // "channel_number"
QT_MOC_LITERAL(13, 141, 6), // "result"
QT_MOC_LITERAL(14, 148, 27), // "setHeartbeatPackStateSignal"
QT_MOC_LITERAL(15, 176, 24), // "signal_sendDataSuccToLog"
QT_MOC_LITERAL(16, 201, 14), // "signal_lifting"
QT_MOC_LITERAL(17, 216, 27), // "InitializationParameterSlot"
QT_MOC_LITERAL(18, 244, 11), // "serviceType"
QT_MOC_LITERAL(19, 256, 9), // "heartBeat"
QT_MOC_LITERAL(20, 266, 11), // "serviceMode"
QT_MOC_LITERAL(21, 278, 9), // "shortLink"
QT_MOC_LITERAL(22, 288, 7), // "newline"
QT_MOC_LITERAL(23, 296, 19), // "getWeightToDataSlot"
QT_MOC_LITERAL(24, 316, 1), // "x"
QT_MOC_LITERAL(25, 318, 1), // "y"
QT_MOC_LITERAL(26, 320, 1), // "w"
QT_MOC_LITERAL(27, 322, 14), // "toSendDataSlot"
QT_MOC_LITERAL(28, 337, 4), // "data"
QT_MOC_LITERAL(29, 342, 20) // "releaseResourcesSlot"

    },
    "DataInterchangeInterface\0messageSignal\0"
    "\0type\0msg\0linkStateSingal\0address\0"
    "port\0state\0connectCountSignal\0count\0"
    "toSendDataSignal\0channel_number\0result\0"
    "setHeartbeatPackStateSignal\0"
    "signal_sendDataSuccToLog\0signal_lifting\0"
    "InitializationParameterSlot\0serviceType\0"
    "heartBeat\0serviceMode\0shortLink\0newline\0"
    "getWeightToDataSlot\0x\0y\0w\0toSendDataSlot\0"
    "data\0releaseResourcesSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataInterchangeInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    3,   74,    2, 0x06 /* Public */,
       9,    1,   81,    2, 0x06 /* Public */,
      11,    2,   84,    2, 0x06 /* Public */,
      14,    1,   89,    2, 0x06 /* Public */,
      15,    2,   92,    2, 0x06 /* Public */,
      16,    0,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    7,   98,    2, 0x0a /* Public */,
      23,    3,  113,    2, 0x0a /* Public */,
      27,    2,  120,    2, 0x0a /* Public */,
      29,    0,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::Bool,    6,    7,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   12,   13,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::Int, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,   18,   19,   20,   21,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   24,   25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   12,   28,
    QMetaType::Void,

       0        // eod
};

void DataInterchangeInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataInterchangeInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->linkStateSingal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->connectCountSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->toSendDataSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->setHeartbeatPackStateSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->signal_sendDataSuccToLog((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->signal_lifting(); break;
        case 7: _t->InitializationParameterSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const bool(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5])),(*reinterpret_cast< const int(*)>(_a[6])),(*reinterpret_cast< const int(*)>(_a[7]))); break;
        case 8: _t->getWeightToDataSlot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 9: _t->toSendDataSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 10: _t->releaseResourcesSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataInterchangeInterface::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataInterchangeInterface::messageSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataInterchangeInterface::*)(const QString & , quint16 , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataInterchangeInterface::linkStateSingal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataInterchangeInterface::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataInterchangeInterface::connectCountSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataInterchangeInterface::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataInterchangeInterface::toSendDataSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DataInterchangeInterface::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataInterchangeInterface::setHeartbeatPackStateSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DataInterchangeInterface::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataInterchangeInterface::signal_sendDataSuccToLog)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DataInterchangeInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataInterchangeInterface::signal_lifting)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataInterchangeInterface::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DataInterchangeInterface.data,
    qt_meta_data_DataInterchangeInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataInterchangeInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataInterchangeInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataInterchangeInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataInterchangeInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DataInterchangeInterface::messageSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataInterchangeInterface::linkStateSingal(const QString & _t1, quint16 _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataInterchangeInterface::connectCountSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataInterchangeInterface::toSendDataSignal(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DataInterchangeInterface::setHeartbeatPackStateSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DataInterchangeInterface::signal_sendDataSuccToLog(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DataInterchangeInterface::signal_lifting()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
