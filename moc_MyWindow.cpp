/****************************************************************************
** Meta object code from reading C++ file 'MyWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyWindow_t {
    QByteArrayData data[14];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyWindow_t qt_meta_stringdata_MyWindow = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyWindow"
QT_MOC_LITERAL(1, 9, 8), // "slotOpen"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "slotSaveAs"
QT_MOC_LITERAL(4, 30, 9), // "slotClear"
QT_MOC_LITERAL(5, 40, 7), // "slotRun"
QT_MOC_LITERAL(6, 48, 18), // "slotProcessStarted"
QT_MOC_LITERAL(7, 67, 19), // "slotProcessFinished"
QT_MOC_LITERAL(8, 87, 8), // "exitCode"
QT_MOC_LITERAL(9, 96, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(10, 117, 10), // "exitStatus"
QT_MOC_LITERAL(11, 128, 22), // "slotReadStandartOutput"
QT_MOC_LITERAL(12, 151, 8), // "slotSave"
QT_MOC_LITERAL(13, 160, 9) // "slotAbout"

    },
    "MyWindow\0slotOpen\0\0slotSaveAs\0slotClear\0"
    "slotRun\0slotProcessStarted\0"
    "slotProcessFinished\0exitCode\0"
    "QProcess::ExitStatus\0exitStatus\0"
    "slotReadStandartOutput\0slotSave\0"
    "slotAbout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    2,   64,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,
      12,    0,   70,    2, 0x0a /* Public */,
      13,    0,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotOpen(); break;
        case 1: _t->slotSaveAs(); break;
        case 2: _t->slotClear(); break;
        case 3: _t->slotRun(); break;
        case 4: _t->slotProcessStarted(); break;
        case 5: _t->slotProcessFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 6: _t->slotReadStandartOutput(); break;
        case 7: _t->slotSave(); break;
        case 8: _t->slotAbout(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MyWindow.data,
    qt_meta_data_MyWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
