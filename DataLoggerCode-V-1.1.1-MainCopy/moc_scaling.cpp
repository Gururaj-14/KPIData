/****************************************************************************
** Meta object code from reading C++ file 'scaling.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "scaling.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scaling.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Scaling_t {
    QByteArrayData data[20];
    char stringdata0[406];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scaling_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scaling_t qt_meta_stringdata_Scaling = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Scaling"
QT_MOC_LITERAL(1, 8, 15), // "deleteGroupName"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "addGroupName"
QT_MOC_LITERAL(4, 38, 15), // "saveGroupWidget"
QT_MOC_LITERAL(5, 54, 16), // "closeGroupWidget"
QT_MOC_LITERAL(6, 71, 11), // "editedvalue"
QT_MOC_LITERAL(7, 83, 14), // "PushBtnClicked"
QT_MOC_LITERAL(8, 98, 21), // "PushBtnClicked_Offset"
QT_MOC_LITERAL(9, 120, 24), // "on_m_PshBtn_Save_clicked"
QT_MOC_LITERAL(10, 145, 42), // "on_comboBox_saveGroups_curren..."
QT_MOC_LITERAL(11, 188, 4), // "arg1"
QT_MOC_LITERAL(12, 193, 30), // "on_pushButton_NewGroup_clicked"
QT_MOC_LITERAL(13, 224, 26), // "on_pushButton_show_clicked"
QT_MOC_LITERAL(14, 251, 28), // "on_pushButton_Delete_clicked"
QT_MOC_LITERAL(15, 280, 32), // "on_pushButton_ClearValue_clicked"
QT_MOC_LITERAL(16, 313, 28), // "on_pushButton_update_clicked"
QT_MOC_LITERAL(17, 342, 31), // "on_chbx_All_saved_group_clicked"
QT_MOC_LITERAL(18, 374, 7), // "checked"
QT_MOC_LITERAL(19, 382, 23) // "on_pshBtn_close_clicked"

    },
    "Scaling\0deleteGroupName\0\0addGroupName\0"
    "saveGroupWidget\0closeGroupWidget\0"
    "editedvalue\0PushBtnClicked\0"
    "PushBtnClicked_Offset\0on_m_PshBtn_Save_clicked\0"
    "on_comboBox_saveGroups_currentIndexChanged\0"
    "arg1\0on_pushButton_NewGroup_clicked\0"
    "on_pushButton_show_clicked\0"
    "on_pushButton_Delete_clicked\0"
    "on_pushButton_ClearValue_clicked\0"
    "on_pushButton_update_clicked\0"
    "on_chbx_All_saved_group_clicked\0checked\0"
    "on_pshBtn_close_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scaling[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  100,    2, 0x0a /* Public */,
       5,    0,  101,    2, 0x0a /* Public */,
       6,    0,  102,    2, 0x0a /* Public */,
       7,    0,  103,    2, 0x0a /* Public */,
       8,    0,  104,    2, 0x0a /* Public */,
       9,    0,  105,    2, 0x08 /* Private */,
      10,    1,  106,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    1,  114,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,

       0        // eod
};

void Scaling::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Scaling *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteGroupName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addGroupName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->saveGroupWidget(); break;
        case 3: _t->closeGroupWidget(); break;
        case 4: _t->editedvalue(); break;
        case 5: _t->PushBtnClicked(); break;
        case 6: _t->PushBtnClicked_Offset(); break;
        case 7: _t->on_m_PshBtn_Save_clicked(); break;
        case 8: _t->on_comboBox_saveGroups_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_NewGroup_clicked(); break;
        case 10: _t->on_pushButton_show_clicked(); break;
        case 11: _t->on_pushButton_Delete_clicked(); break;
        case 12: _t->on_pushButton_ClearValue_clicked(); break;
        case 13: _t->on_pushButton_update_clicked(); break;
        case 14: _t->on_chbx_All_saved_group_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_pshBtn_close_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Scaling::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scaling::deleteGroupName)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Scaling::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scaling::addGroupName)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Scaling::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Scaling.data,
    qt_meta_data_Scaling,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Scaling::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scaling::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Scaling.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Scaling::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Scaling::deleteGroupName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Scaling::addGroupName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
