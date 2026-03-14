/****************************************************************************
** Meta object code from reading C++ file 'TcpClientMediator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mediator/TcpClientMediator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpClientMediator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpClientMediator_t {
    QByteArrayData data[7];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpClientMediator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpClientMediator_t qt_meta_stringdata_TcpClientMediator = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TcpClientMediator"
QT_MOC_LITERAL(1, 18, 22), // "signals_recvServerData"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 5), // "char*"
QT_MOC_LITERAL(4, 48, 4), // "data"
QT_MOC_LITERAL(5, 53, 3), // "len"
QT_MOC_LITERAL(6, 57, 4) // "from"

    },
    "TcpClientMediator\0signals_recvServerData\0"
    "\0char*\0data\0len\0from"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClientMediator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::ULong,    4,    5,    6,

       0        // eod
};

void TcpClientMediator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpClientMediator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signals_recvServerData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< ulong(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpClientMediator::*)(char * , int , unsigned long );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClientMediator::signals_recvServerData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpClientMediator::staticMetaObject = { {
    QMetaObject::SuperData::link<INetMediator::staticMetaObject>(),
    qt_meta_stringdata_TcpClientMediator.data,
    qt_meta_data_TcpClientMediator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpClientMediator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpClientMediator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClientMediator.stringdata0))
        return static_cast<void*>(this);
    return INetMediator::qt_metacast(_clname);
}

int TcpClientMediator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = INetMediator::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void TcpClientMediator::signals_recvServerData(char * _t1, int _t2, unsigned long _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
