/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Qt+Holography_Rahul/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainwindow_t {
    QByteArrayData data[8];
    char stringdata[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_mainwindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_mainwindow_t qt_meta_stringdata_mainwindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 21),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 8),
QT_MOC_LITERAL(4, 43, 6),
QT_MOC_LITERAL(5, 50, 7),
QT_MOC_LITERAL(6, 58, 3),
QT_MOC_LITERAL(7, 62, 5)
    },
    "mainwindow\0on_pushButton_clicked\0\0"
    "updateUI\0rotate\0cv::Mat\0src\0angle\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08,
       3,    0,   30,    2, 0x0a,
       4,    2,   31,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 5, 0x80000000 | 5, QMetaType::Double,    6,    7,

       0        // eod
};

void mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainwindow *_t = static_cast<mainwindow *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->updateUI(); break;
        case 2: { cv::Mat _r = _t->rotate((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< cv::Mat*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject mainwindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainwindow.data,
      qt_meta_data_mainwindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainwindow.stringdata))
        return static_cast<void*>(const_cast< mainwindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
