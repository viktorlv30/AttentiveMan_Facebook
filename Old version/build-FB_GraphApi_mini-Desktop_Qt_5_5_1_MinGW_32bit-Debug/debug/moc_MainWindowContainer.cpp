/****************************************************************************
** Meta object code from reading C++ file 'MainWindowContainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../facebook-cpp-graph-api_v3/MainWindowContainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindowContainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindowContainer_t {
    QByteArrayData data[14];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindowContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindowContainer_t qt_meta_stringdata_MainWindowContainer = {
    {
QT_MOC_LITERAL(0, 0, 19), // "MainWindowContainer"
QT_MOC_LITERAL(1, 20, 14), // "adjustLocation"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 14), // "changeLocation"
QT_MOC_LITERAL(4, 51, 11), // "adjustTitle"
QT_MOC_LITERAL(5, 63, 11), // "setProgress"
QT_MOC_LITERAL(6, 75, 1), // "p"
QT_MOC_LITERAL(7, 77, 13), // "finishLoading"
QT_MOC_LITERAL(8, 91, 12), // "finishedSlot"
QT_MOC_LITERAL(9, 104, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 119, 5), // "reply"
QT_MOC_LITERAL(11, 125, 11), // "linkClicked"
QT_MOC_LITERAL(12, 137, 3), // "url"
QT_MOC_LITERAL(13, 141, 8) // "CloseApp"

    },
    "MainWindowContainer\0adjustLocation\0\0"
    "changeLocation\0adjustTitle\0setProgress\0"
    "p\0finishLoading\0finishedSlot\0"
    "QNetworkReply*\0reply\0linkClicked\0url\0"
    "CloseApp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindowContainer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    1,   57,    2, 0x0a /* Public */,
       7,    1,   60,    2, 0x0a /* Public */,
       8,    1,   63,    2, 0x0a /* Public */,
      11,    1,   66,    2, 0x0a /* Public */,
      13,    0,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QUrl,   12,
    QMetaType::Void,

       0        // eod
};

void MainWindowContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindowContainer *_t = static_cast<MainWindowContainer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->adjustLocation(); break;
        case 1: _t->changeLocation(); break;
        case 2: _t->adjustTitle(); break;
        case 3: _t->setProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->finishLoading((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->finishedSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->linkClicked((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 7: _t->CloseApp(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindowContainer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowContainer.data,
      qt_meta_data_MainWindowContainer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindowContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowContainer.stringdata0))
        return static_cast<void*>(const_cast< MainWindowContainer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
