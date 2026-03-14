/****************************************************************************
** Meta object code from reading C++ file 'kernel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../kernel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kernel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Kernel_t {
    QByteArrayData data[14];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Kernel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Kernel_t qt_meta_stringdata_Kernel = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Kernel"
QT_MOC_LITERAL(1, 7, 22), // "signals_sendClientData"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "char*"
QT_MOC_LITERAL(4, 37, 22), // "slots_sendRegisterInfo"
QT_MOC_LITERAL(5, 60, 19), // "slots_sendLoginInfo"
QT_MOC_LITERAL(6, 80, 20), // "slots_recvServerData"
QT_MOC_LITERAL(7, 101, 19), // "slots_sendServerMsg"
QT_MOC_LITERAL(8, 121, 15), // "slots_addFriend"
QT_MOC_LITERAL(9, 137, 20), // "slots_timerAddFriend"
QT_MOC_LITERAL(10, 158, 23), // "slots_timerFriendOnline"
QT_MOC_LITERAL(11, 182, 24), // "slots_timerFriendOffline"
QT_MOC_LITERAL(12, 207, 21), // "slots_sendUserOffline"
QT_MOC_LITERAL(13, 229, 12) // "slots_delete"

    },
    "Kernel\0signals_sendClientData\0\0char*\0"
    "slots_sendRegisterInfo\0slots_sendLoginInfo\0"
    "slots_recvServerData\0slots_sendServerMsg\0"
    "slots_addFriend\0slots_timerAddFriend\0"
    "slots_timerFriendOnline\0"
    "slots_timerFriendOffline\0slots_sendUserOffline\0"
    "slots_delete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Kernel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   76,    2, 0x0a /* Public */,
       5,    2,   83,    2, 0x0a /* Public */,
       6,    3,   88,    2, 0x0a /* Public */,
       7,    2,   95,    2, 0x0a /* Public */,
       8,    1,  100,    2, 0x0a /* Public */,
       9,    0,  103,    2, 0x0a /* Public */,
      10,    0,  104,    2, 0x0a /* Public */,
      11,    0,  105,    2, 0x0a /* Public */,
      12,    0,  106,    2, 0x0a /* Public */,
      13,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::ULong,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::ULong,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Kernel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Kernel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signals_sendClientData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< ulong(*)>(_a[3]))); break;
        case 1: _t->slots_sendRegisterInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->slots_sendLoginInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->slots_recvServerData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< ulong(*)>(_a[3]))); break;
        case 4: _t->slots_sendServerMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->slots_addFriend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->slots_timerAddFriend(); break;
        case 7: _t->slots_timerFriendOnline(); break;
        case 8: _t->slots_timerFriendOffline(); break;
        case 9: _t->slots_sendUserOffline(); break;
        case 10: _t->slots_delete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Kernel::*)(char * , int , unsigned long );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kernel::signals_sendClientData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Kernel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Kernel.data,
    qt_meta_data_Kernel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Kernel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Kernel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Kernel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Kernel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Kernel::signals_sendClientData(char * _t1, int _t2, unsigned long _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
