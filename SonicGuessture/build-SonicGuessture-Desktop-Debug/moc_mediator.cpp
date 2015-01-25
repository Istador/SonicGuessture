/****************************************************************************
** Meta object code from reading C++ file 'mediator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Application/mediator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Mediator_t {
    QByteArrayData data[17];
    char stringdata[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Mediator_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Mediator_t qt_meta_stringdata_Mediator = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 12),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 8),
QT_MOC_LITERAL(4, 32, 8),
QT_MOC_LITERAL(5, 41, 9),
QT_MOC_LITERAL(6, 51, 9),
QT_MOC_LITERAL(7, 61, 5),
QT_MOC_LITERAL(8, 67, 13),
QT_MOC_LITERAL(9, 81, 10),
QT_MOC_LITERAL(10, 92, 8),
QT_MOC_LITERAL(11, 101, 11),
QT_MOC_LITERAL(12, 113, 12),
QT_MOC_LITERAL(13, 126, 16),
QT_MOC_LITERAL(14, 143, 19),
QT_MOC_LITERAL(15, 163, 13),
QT_MOC_LITERAL(16, 177, 4)
    },
    "Mediator\0displayImage\0\0filename\0"
    "shutdown\0loopMusic\0playSound\0start\0"
    "colorSelected\0cv::Scalar\0keyColor\0"
    "colorPicked\0newGuessture\0noMoreGuesstures\0"
    "guesstureRecognized\0skipGuessture\0"
    "quit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mediator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06,
       4,    0,   77,    2, 0x06,
       5,    1,   78,    2, 0x06,
       6,    1,   81,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   84,    2, 0x0a,
       8,    1,   85,    2, 0x0a,
      11,    1,   88,    2, 0x0a,
      12,    0,   91,    2, 0x0a,
      13,    0,   92,    2, 0x0a,
      14,    0,   93,    2, 0x0a,
      15,    0,   94,    2, 0x0a,
      16,    0,   95,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Mediator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Mediator *_t = static_cast<Mediator *>(_o);
        switch (_id) {
        case 0: _t->displayImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->shutdown(); break;
        case 2: _t->loopMusic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->playSound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->start(); break;
        case 5: _t->colorSelected((*reinterpret_cast< const cv::Scalar(*)>(_a[1]))); break;
        case 6: _t->colorPicked((*reinterpret_cast< const cv::Scalar(*)>(_a[1]))); break;
        case 7: _t->newGuessture(); break;
        case 8: _t->noMoreGuesstures(); break;
        case 9: _t->guesstureRecognized(); break;
        case 10: _t->skipGuessture(); break;
        case 11: _t->quit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Mediator::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Mediator::displayImage)) {
                *result = 0;
            }
        }
        {
            typedef void (Mediator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Mediator::shutdown)) {
                *result = 1;
            }
        }
        {
            typedef void (Mediator::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Mediator::loopMusic)) {
                *result = 2;
            }
        }
        {
            typedef void (Mediator::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Mediator::playSound)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Mediator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Mediator.data,
      qt_meta_data_Mediator,  qt_static_metacall, 0, 0}
};


const QMetaObject *Mediator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mediator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mediator.stringdata))
        return static_cast<void*>(const_cast< Mediator*>(this));
    return QObject::qt_metacast(_clname);
}

int Mediator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Mediator::displayImage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Mediator::shutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Mediator::loopMusic(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Mediator::playSound(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
