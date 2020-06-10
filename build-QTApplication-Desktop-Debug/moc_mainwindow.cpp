/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../QTApplication/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 4), // "open"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "reset"
QT_MOC_LITERAL(4, 23, 4), // "undo"
QT_MOC_LITERAL(5, 28, 4), // "redo"
QT_MOC_LITERAL(6, 33, 11), // "imageToGrey"
QT_MOC_LITERAL(7, 45, 11), // "detectEdges"
QT_MOC_LITERAL(8, 57, 14), // "createPanorama"
QT_MOC_LITERAL(9, 72, 9), // "blurImage"
QT_MOC_LITERAL(10, 82, 8), // "kernelXY"
QT_MOC_LITERAL(11, 91, 14), // "rotateImageP90"
QT_MOC_LITERAL(12, 106, 14), // "rotateImageM90"
QT_MOC_LITERAL(13, 121, 12), // "customRotate"
QT_MOC_LITERAL(14, 134, 13), // "contrastImage"
QT_MOC_LITERAL(15, 148, 4), // "beta"
QT_MOC_LITERAL(16, 153, 13), // "brightenImage"
QT_MOC_LITERAL(17, 167, 5), // "alpha"
QT_MOC_LITERAL(18, 173, 11), // "resizeImage"
QT_MOC_LITERAL(19, 185, 5), // "scale"
QT_MOC_LITERAL(20, 191, 9), // "cropImage"
QT_MOC_LITERAL(21, 201, 11), // "dilateImage"
QT_MOC_LITERAL(22, 213, 13), // "dilation_size"
QT_MOC_LITERAL(23, 227, 10), // "erodeImage"
QT_MOC_LITERAL(24, 238, 10) // "erode_size"

    },
    "MainWindow\0open\0\0reset\0undo\0redo\0"
    "imageToGrey\0detectEdges\0createPanorama\0"
    "blurImage\0kernelXY\0rotateImageP90\0"
    "rotateImageM90\0customRotate\0contrastImage\0"
    "beta\0brightenImage\0alpha\0resizeImage\0"
    "scale\0cropImage\0dilateImage\0dilation_size\0"
    "erodeImage\0erode_size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x0a /* Public */,
       3,    0,  110,    2, 0x0a /* Public */,
       4,    0,  111,    2, 0x0a /* Public */,
       5,    0,  112,    2, 0x0a /* Public */,
       6,    0,  113,    2, 0x0a /* Public */,
       7,    0,  114,    2, 0x0a /* Public */,
       8,    0,  115,    2, 0x0a /* Public */,
       9,    1,  116,    2, 0x0a /* Public */,
      11,    0,  119,    2, 0x0a /* Public */,
      12,    0,  120,    2, 0x0a /* Public */,
      13,    0,  121,    2, 0x0a /* Public */,
      14,    1,  122,    2, 0x0a /* Public */,
      14,    0,  125,    2, 0x2a /* Public | MethodCloned */,
      16,    1,  126,    2, 0x0a /* Public */,
      16,    0,  129,    2, 0x2a /* Public | MethodCloned */,
      18,    1,  130,    2, 0x0a /* Public */,
      20,    0,  133,    2, 0x0a /* Public */,
      21,    1,  134,    2, 0x0a /* Public */,
      23,    1,  137,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   24,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open(); break;
        case 1: _t->reset(); break;
        case 2: _t->undo(); break;
        case 3: _t->redo(); break;
        case 4: _t->imageToGrey(); break;
        case 5: _t->detectEdges(); break;
        case 6: _t->createPanorama(); break;
        case 7: _t->blurImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->rotateImageP90(); break;
        case 9: _t->rotateImageM90(); break;
        case 10: _t->customRotate(); break;
        case 11: _t->contrastImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->contrastImage(); break;
        case 13: _t->brightenImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->brightenImage(); break;
        case 15: _t->resizeImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->cropImage(); break;
        case 17: _t->dilateImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->erodeImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
