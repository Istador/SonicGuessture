/****************************************************************************
** Meta object code from reading C++ file 'colorpicker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Application/colorpicker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorpicker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ColorPicker_t {
    QByteArrayData data[13];
    char stringdata[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ColorPicker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ColorPicker_t qt_meta_stringdata_ColorPicker = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 13),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 10),
QT_MOC_LITERAL(4, 38, 8),
QT_MOC_LITERAL(5, 47, 11),
QT_MOC_LITERAL(6, 59, 13),
QT_MOC_LITERAL(7, 73, 7),
QT_MOC_LITERAL(8, 81, 5),
QT_MOC_LITERAL(9, 87, 11),
QT_MOC_LITERAL(10, 99, 12),
QT_MOC_LITERAL(11, 112, 8),
QT_MOC_LITERAL(12, 121, 8)
    },
    "ColorPicker\0colorSelected\0\0cv::Scalar\0"
    "keyColor\0colorPicked\0modifiedImage\0"
    "cv::Mat\0image\0cameraImage\0mouseClicked\0"
    "keyPress\0shutdown\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorPicker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,
       5,    1,   52,    2, 0x06,
       6,    1,   55,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       9,    1,   58,    2, 0x0a,
      10,    0,   61,    2, 0x0a,
      11,    1,   62,    2, 0x0a,
      12,    0,   65,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void ColorPicker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ColorPicker *_t = static_cast<ColorPicker *>(_o);
        switch (_id) {
        case 0: _t->colorSelected((*reinterpret_cast< const cv::Scalar(*)>(_a[1]))); break;
        case 1: _t->colorPicked((*reinterpret_cast< const cv::Scalar(*)>(_a[1]))); break;
        case 2: _t->modifiedImage((*reinterpret_cast< const cv::Mat(*)>(_a[1]))); break;
        case 3: _t->cameraImage((*reinterpret_cast< const cv::Mat(*)>(_a[1]))); break;
        case 4: _t->mouseClicked(); break;
        case 5: _t->keyPress((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 6: _t->shutdown(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ColorPicker::*_t)(const cv::Scalar & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ColorPicker::colorSelected)) {
                *result = 0;
            }
        }
        {
            typedef void (ColorPicker::*_t)(const cv::Scalar & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ColorPicker::colorPicked)) {
                *result = 1;
            }
        }
        {
            typedef void (ColorPicker::*_t)(const cv::Mat & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ColorPicker::modifiedImage)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ColorPicker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ColorPicker.data,
      qt_meta_data_ColorPicker,  qt_static_metacall, 0, 0}
};


const QMetaObject *ColorPicker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorPicker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorPicker.stringdata))
        return static_cast<void*>(const_cast< ColorPicker*>(this));
    return QObject::qt_metacast(_clname);
}

int ColorPicker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ColorPicker::colorSelected(const cv::Scalar & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ColorPicker::colorPicked(const cv::Scalar & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ColorPicker::modifiedImage(const cv::Mat & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
