/****************************************************************************
** Meta object code from reading C++ file 'datainterserailport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../datainterserailport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datainterserailport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataInterSerailPort_t {
    QByteArrayData data[13];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataInterSerailPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataInterSerailPort_t qt_meta_stringdata_DataInterSerailPort = {
    {
QT_MOC_LITERAL(0, 0, 19), // "DataInterSerailPort"
QT_MOC_LITERAL(1, 20, 15), // "getPoundsSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 1), // "x"
QT_MOC_LITERAL(4, 39, 1), // "y"
QT_MOC_LITERAL(5, 41, 1), // "w"
QT_MOC_LITERAL(6, 43, 17), // "startStatusSignal"
QT_MOC_LITERAL(7, 61, 6), // "status"
QT_MOC_LITERAL(8, 68, 15), // "receiveDataSlot"
QT_MOC_LITERAL(9, 84, 12), // "autoLinkSlot"
QT_MOC_LITERAL(10, 97, 15), // "errorSerialSlot"
QT_MOC_LITERAL(11, 113, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(12, 142, 5) // "error"

    },
    "DataInterSerailPort\0getPoundsSignal\0"
    "\0x\0y\0w\0startStatusSignal\0status\0"
    "receiveDataSlot\0autoLinkSlot\0"
    "errorSerialSlot\0QSerialPort::SerialPortError\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataInterSerailPort[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       6,    1,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   49,    2, 0x08 /* Private */,
       9,    0,   50,    2, 0x08 /* Private */,
      10,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void DataInterSerailPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataInterSerailPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getPoundsSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->startStatusSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->receiveDataSlot(); break;
        case 3: _t->autoLinkSlot(); break;
        case 4: _t->errorSerialSlot((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataInterSerailPort::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataInterSerailPort::getPoundsSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataInterSerailPort::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataInterSerailPort::startStatusSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataInterSerailPort::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DataInterSerailPort.data,
    qt_meta_data_DataInterSerailPort,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataInterSerailPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataInterSerailPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataInterSerailPort.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataInterSerailPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DataInterSerailPort::getPoundsSignal(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataInterSerailPort::startStatusSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
