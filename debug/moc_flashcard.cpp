/****************************************************************************
** Meta object code from reading C++ file 'flashcard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/flashcard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flashcard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Flashcard_t {
    QByteArrayData data[15];
    char stringdata[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Flashcard_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Flashcard_t qt_meta_stringdata_Flashcard = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Flashcard"
QT_MOC_LITERAL(1, 10, 4), // "Flip"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11), // "leftToRight"
QT_MOC_LITERAL(4, 28, 10), // "Horizontal"
QT_MOC_LITERAL(5, 39, 8), // "Vertical"
QT_MOC_LITERAL(6, 48, 11), // "LeftToRight"
QT_MOC_LITERAL(7, 60, 11), // "RightToLeft"
QT_MOC_LITERAL(8, 72, 6), // "Normal"
QT_MOC_LITERAL(9, 79, 9), // "Turnstile"
QT_MOC_LITERAL(10, 89, 7), // "FlyAway"
QT_MOC_LITERAL(11, 97, 5), // "Speed"
QT_MOC_LITERAL(12, 103, 5), // "speed"
QT_MOC_LITERAL(13, 109, 15), // "FlyAwayDistance"
QT_MOC_LITERAL(14, 125, 8) // "distance"

    },
    "Flashcard\0Flip\0\0leftToRight\0Horizontal\0"
    "Vertical\0LeftToRight\0RightToLeft\0"
    "Normal\0Turnstile\0FlyAway\0Speed\0speed\0"
    "FlyAwayDistance\0distance"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Flashcard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       1,    0,   72,    2, 0x2a /* Public | MethodCloned */,
       4,    0,   73,    2, 0x08 /* Private */,
       5,    0,   74,    2, 0x08 /* Private */,
       6,    0,   75,    2, 0x08 /* Private */,
       7,    0,   76,    2, 0x08 /* Private */,
       8,    0,   77,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      13,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void Flashcard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Flashcard *_t = static_cast<Flashcard *>(_o);
        switch (_id) {
        case 0: _t->Flip((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->Flip(); break;
        case 2: _t->Horizontal(); break;
        case 3: _t->Vertical(); break;
        case 4: _t->LeftToRight(); break;
        case 5: _t->RightToLeft(); break;
        case 6: _t->Normal(); break;
        case 7: _t->Turnstile(); break;
        case 8: _t->FlyAway(); break;
        case 9: _t->Speed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->FlyAwayDistance((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Flashcard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Flashcard.data,
      qt_meta_data_Flashcard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Flashcard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Flashcard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Flashcard.stringdata))
        return static_cast<void*>(const_cast< Flashcard*>(this));
    return QWidget::qt_metacast(_clname);
}

int Flashcard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
