/****************************************************************************
** Meta object code from reading C++ file 'addkpis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "addkpis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addkpis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ADDKPIS_t {
    QByteArrayData data[12];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ADDKPIS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ADDKPIS_t qt_meta_stringdata_ADDKPIS = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ADDKPIS"
QT_MOC_LITERAL(1, 8, 18), // "PushBtnEditClicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "PushBtnDelClicked"
QT_MOC_LITERAL(4, 46, 8), // "saveKpis"
QT_MOC_LITERAL(5, 55, 8), // "closewnd"
QT_MOC_LITERAL(6, 64, 15), // "CheckConnection"
QT_MOC_LITERAL(7, 80, 23), // "on_m_PshBtn_Add_clicked"
QT_MOC_LITERAL(8, 104, 29), // "on_pushButton_connect_clicked"
QT_MOC_LITERAL(9, 134, 43), // "on_comboBox_ConnectedIPs_curr..."
QT_MOC_LITERAL(10, 178, 4), // "arg1"
QT_MOC_LITERAL(11, 183, 30) // "on_toolButton_Versions_clicked"

    },
    "ADDKPIS\0PushBtnEditClicked\0\0"
    "PushBtnDelClicked\0saveKpis\0closewnd\0"
    "CheckConnection\0on_m_PshBtn_Add_clicked\0"
    "on_pushButton_connect_clicked\0"
    "on_comboBox_ConnectedIPs_currentTextChanged\0"
    "arg1\0on_toolButton_Versions_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ADDKPIS[] = {

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
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void ADDKPIS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ADDKPIS *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PushBtnEditClicked(); break;
        case 1: _t->PushBtnDelClicked(); break;
        case 2: _t->saveKpis(); break;
        case 3: _t->closewnd(); break;
        case 4: _t->CheckConnection(); break;
        case 5: _t->on_m_PshBtn_Add_clicked(); break;
        case 6: _t->on_pushButton_connect_clicked(); break;
        case 7: _t->on_comboBox_ConnectedIPs_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_toolButton_Versions_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ADDKPIS::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ADDKPIS.data,
    qt_meta_data_ADDKPIS,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ADDKPIS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ADDKPIS::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ADDKPIS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ADDKPIS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
