/****************************************************************************
** Meta object code from reading C++ file 'datainterchange.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../datainterchange.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datainterchange.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataInterchange_t {
    QByteArrayData data[15];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataInterchange_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataInterchange_t qt_meta_stringdata_DataInterchange = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DataInterchange"
QT_MOC_LITERAL(1, 16, 23), // "signal_setMessageFormat"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 7), // "newline"
QT_MOC_LITERAL(4, 49, 13), // "startLinkSlot"
QT_MOC_LITERAL(5, 63, 15), // "startListenSlot"
QT_MOC_LITERAL(6, 79, 13), // "heartbeatSlot"
QT_MOC_LITERAL(7, 93, 13), // "connectedSlot"
QT_MOC_LITERAL(8, 107, 15), // "receiveDataSlot"
QT_MOC_LITERAL(9, 123, 16), // "disconnectedSlot"
QT_MOC_LITERAL(10, 140, 16), // "displayErrorSlot"
QT_MOC_LITERAL(11, 157, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(12, 186, 11), // "socketError"
QT_MOC_LITERAL(13, 198, 23), // "setHeartPacketStateSlot"
QT_MOC_LITERAL(14, 222, 5) // "state"

    },
    "DataInterchange\0signal_setMessageFormat\0"
    "\0newline\0startLinkSlot\0startListenSlot\0"
    "heartbeatSlot\0connectedSlot\0receiveDataSlot\0"
    "disconnectedSlot\0displayErrorSlot\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "setHeartPacketStateSlot\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataInterchange[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      13,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Bool,   14,

       0        // eod
};

void DataInterchange::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataInterchange *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_setMessageFormat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->startLinkSlot(); break;
        case 2: _t->startListenSlot(); break;
        case 3: _t->heartbeatSlot(); break;
        case 4: _t->connectedSlot(); break;
        case 5: _t->receiveDataSlot(); break;
        case 6: _t->disconnectedSlot(); break;
        case 7: _t->displayErrorSlot((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 8: _t->setHeartPacketStateSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataInterchange::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataInterchange::signal_setMessageFormat)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataInterchange::staticMetaObject = { {
    &DataInterchangeInterface::staticMetaObject,
    qt_meta_stringdata_DataInterchange.data,
    qt_meta_data_DataInterchange,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataInterchange::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataInterchange::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataInterchange.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ZBY.ContainerServer.DataInterchangeInterface/1.2.3.4"))
        return static_cast< DataInterchangeInterface*>(this);
    return DataInterchangeInterface::qt_metacast(_clname);
}

int DataInterchange::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataInterchangeInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DataInterchange::signal_setMessageFormat(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x34,  'Z',  'B',  'Y',  '.',  'C', 
    'o',  'n',  't',  'a',  'i',  'n',  'e',  'r', 
    'S',  'e',  'r',  'v',  'e',  'r',  '.',  'D', 
    'a',  't',  'a',  'I',  'n',  't',  'e',  'r', 
    'c',  'h',  'a',  'n',  'g',  'e',  'I',  'n', 
    't',  'e',  'r',  'f',  'a',  'c',  'e',  '/', 
    '1',  '.',  '2',  '.',  '3',  '.',  '4', 
    // "className"
    0x03,  0x6f,  'D',  'a',  't',  'a',  'I',  'n', 
    't',  'e',  'r',  'c',  'h',  'a',  'n',  'g', 
    'e', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(DataInterchange, DataInterchange)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
