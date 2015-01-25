/****************************************************************************
** Meta object code from reading C++ file 'guessturecollection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Application/guessturecollection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guessturecollection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GuesstureCollection_t {
    QByteArrayData data[5];
    char stringdata[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GuesstureCollection_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GuesstureCollection_t qt_meta_stringdata_GuesstureCollection = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 12),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 16),
QT_MOC_LITERAL(4, 51, 13)
    },
    "GuesstureCollection\0newGuessture\0\0"
    "noMoreGuesstures\0nextGuessture\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GuesstureCollection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06,
       3,    0,   30,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void GuesstureCollection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuesstureCollection *_t = static_cast<GuesstureCollection *>(_o);
        switch (_id) {
        case 0: _t->newGuessture(); break;
        case 1: _t->noMoreGuesstures(); break;
        case 2: _t->nextGuessture(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GuesstureCollection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuesstureCollection::newGuessture)) {
                *result = 0;
            }
        }
        {
            typedef void (GuesstureCollection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuesstureCollection::noMoreGuesstures)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GuesstureCollection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GuesstureCollection.data,
      qt_meta_data_GuesstureCollection,  qt_static_metacall, 0, 0}
};


const QMetaObject *GuesstureCollection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GuesstureCollection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GuesstureCollection.stringdata))
        return static_cast<void*>(const_cast< GuesstureCollection*>(this));
    return QObject::qt_metacast(_clname);
}

int GuesstureCollection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GuesstureCollection::newGuessture()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GuesstureCollection::noMoreGuesstures()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
