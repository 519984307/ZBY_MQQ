/****************************************************************************
** Meta object code from reading C++ file 'modbusslave.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../modbusslave.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbusslave.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModbusSlave_t {
    QByteArrayData data[16];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModbusSlave_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModbusSlave_t qt_meta_stringdata_ModbusSlave = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ModbusSlave"
QT_MOC_LITERAL(1, 12, 18), // "connectSlaveSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "status"
QT_MOC_LITERAL(4, 39, 16), // "stateChangedSlot"
QT_MOC_LITERAL(5, 56, 5), // "state"
QT_MOC_LITERAL(6, 62, 14), // "updateDataSlot"
QT_MOC_LITERAL(7, 77, 29), // "QModbusDataUnit::RegisterType"
QT_MOC_LITERAL(8, 107, 5), // "table"
QT_MOC_LITERAL(9, 113, 7), // "address"
QT_MOC_LITERAL(10, 121, 4), // "size"
QT_MOC_LITERAL(11, 126, 15), // "errOccurredSlot"
QT_MOC_LITERAL(12, 142, 20), // "QModbusDevice::Error"
QT_MOC_LITERAL(13, 163, 8), // "newError"
QT_MOC_LITERAL(14, 172, 17), // "setMoubusDataSlot"
QT_MOC_LITERAL(15, 190, 4) // "data"

    },
    "ModbusSlave\0connectSlaveSignal\0\0status\0"
    "stateChangedSlot\0state\0updateDataSlot\0"
    "QModbusDataUnit::RegisterType\0table\0"
    "address\0size\0errOccurredSlot\0"
    "QModbusDevice::Error\0newError\0"
    "setMoubusDataSlot\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusSlave[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x08 /* Private */,
       6,    3,   45,    2, 0x08 /* Private */,
      11,    1,   52,    2, 0x08 /* Private */,
      14,    2,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QStringList,    8,   15,

       0        // eod
};

void ModbusSlave::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModbusSlave *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectSlaveSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->stateChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateDataSlot((*reinterpret_cast< QModbusDataUnit::RegisterType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->errOccurredSlot((*reinterpret_cast< QModbusDevice::Error(*)>(_a[1]))); break;
        case 4: _t->setMoubusDataSlot((*reinterpret_cast< QModbusDataUnit::RegisterType(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QModbusDataUnit::RegisterType >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QModbusDataUnit::RegisterType >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModbusSlave::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusSlave::connectSlaveSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ModbusSlave::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ModbusSlave.data,
    qt_meta_data_ModbusSlave,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModbusSlave::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusSlave::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusSlave.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModbusSlave::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ModbusSlave::connectSlaveSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
