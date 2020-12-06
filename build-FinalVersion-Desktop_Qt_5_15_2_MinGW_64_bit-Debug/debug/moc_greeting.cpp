/****************************************************************************
** Meta object code from reading C++ file 'greeting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../FinalVersion/greeting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'greeting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Greeting_t {
    QByteArrayData data[9];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Greeting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Greeting_t qt_meta_stringdata_Greeting = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Greeting"
QT_MOC_LITERAL(1, 9, 13), // "sig_newSourse"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "sig_openSourse"
QT_MOC_LITERAL(4, 39, 16), // "sig_openDictList"
QT_MOC_LITERAL(5, 56, 15), // "indicateClosing"
QT_MOC_LITERAL(6, 72, 12), // "sig_template"
QT_MOC_LITERAL(7, 85, 10), // "closeEvent"
QT_MOC_LITERAL(8, 96, 12) // "QCloseEvent*"

    },
    "Greeting\0sig_newSourse\0\0sig_openSourse\0"
    "sig_openDictList\0indicateClosing\0"
    "sig_template\0closeEvent\0QCloseEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Greeting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    2,

       0        // eod
};

void Greeting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Greeting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_newSourse(); break;
        case 1: _t->sig_openSourse(); break;
        case 2: _t->sig_openDictList(); break;
        case 3: _t->indicateClosing(); break;
        case 4: _t->sig_template(); break;
        case 5: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Greeting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Greeting::sig_newSourse)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Greeting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Greeting::sig_openSourse)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Greeting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Greeting::sig_openDictList)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Greeting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Greeting::indicateClosing)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Greeting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Greeting::sig_template)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Greeting::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Greeting.data,
    qt_meta_data_Greeting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Greeting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Greeting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Greeting.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Greeting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Greeting::sig_newSourse()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Greeting::sig_openSourse()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Greeting::sig_openDictList()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Greeting::indicateClosing()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Greeting::sig_template()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
