/****************************************************************************
** Meta object code from reading C++ file 'selection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "selection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Selection_t {
    QByteArrayData data[73];
    char stringdata0[1807];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Selection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Selection_t qt_meta_stringdata_Selection = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Selection"
QT_MOC_LITERAL(1, 10, 6), // "rotate"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "xAxisChanged"
QT_MOC_LITERAL(4, 31, 8), // "QCPRange"
QT_MOC_LITERAL(5, 40, 5), // "range"
QT_MOC_LITERAL(6, 46, 12), // "yAxisChanged"
QT_MOC_LITERAL(7, 59, 15), // "controlledZoomX"
QT_MOC_LITERAL(8, 75, 12), // "QWheelEvent*"
QT_MOC_LITERAL(9, 88, 5), // "event"
QT_MOC_LITERAL(10, 94, 12), // "mouseRelease"
QT_MOC_LITERAL(11, 107, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 120, 10), // "mousePress"
QT_MOC_LITERAL(13, 131, 9), // "mouseMove"
QT_MOC_LITERAL(14, 141, 11), // "deleteGroup"
QT_MOC_LITERAL(15, 153, 13), // "del_groupname"
QT_MOC_LITERAL(16, 167, 8), // "addGroup"
QT_MOC_LITERAL(17, 176, 13), // "add_groupname"
QT_MOC_LITERAL(18, 190, 15), // "CheckConnection"
QT_MOC_LITERAL(19, 206, 29), // "on_pushButton_connect_clicked"
QT_MOC_LITERAL(20, 236, 43), // "on_comboBox_ConnectedIPs_curr..."
QT_MOC_LITERAL(21, 280, 4), // "arg1"
QT_MOC_LITERAL(22, 285, 33), // "on_timeEdit_StartTime_timeCha..."
QT_MOC_LITERAL(23, 319, 4), // "time"
QT_MOC_LITERAL(24, 324, 31), // "on_timeEdit_EndTime_timeChanged"
QT_MOC_LITERAL(25, 356, 35), // "on_timeEdit_PValueStart_timeC..."
QT_MOC_LITERAL(26, 392, 33), // "on_timeEdit_PValueEnd_timeCha..."
QT_MOC_LITERAL(27, 426, 34), // "on_cmbBx_Etime_currentIndexCh..."
QT_MOC_LITERAL(28, 461, 35), // "on_cmbBx_Samples_currentTextC..."
QT_MOC_LITERAL(29, 497, 5), // "value"
QT_MOC_LITERAL(30, 503, 36), // "on_cmbBx_Samples_currentIndex..."
QT_MOC_LITERAL(31, 540, 37), // "on_cmbBx_EtimeDur_currentInde..."
QT_MOC_LITERAL(32, 578, 38), // "on_TimeStamp_StartTime_dateTi..."
QT_MOC_LITERAL(33, 617, 8), // "dateTime"
QT_MOC_LITERAL(34, 626, 36), // "on_TimeStamp_EndTime_dateTime..."
QT_MOC_LITERAL(35, 663, 32), // "on_radioButton_TSEndTime_clicked"
QT_MOC_LITERAL(36, 696, 32), // "on_radioButton_TSDurTime_clicked"
QT_MOC_LITERAL(37, 729, 25), // "on_End_PvradioBtn_clicked"
QT_MOC_LITERAL(38, 755, 25), // "on_Dur_PvradioBtn_clicked"
QT_MOC_LITERAL(39, 781, 24), // "on_PshBtn_search_clicked"
QT_MOC_LITERAL(40, 806, 39), // "on_Pvalue_StartdateTime_dateT..."
QT_MOC_LITERAL(41, 846, 44), // "on_treeWidget_ParameterTimeVa..."
QT_MOC_LITERAL(42, 891, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(43, 908, 4), // "item"
QT_MOC_LITERAL(44, 913, 6), // "column"
QT_MOC_LITERAL(45, 920, 29), // "on_pshBtn_clearParams_clicked"
QT_MOC_LITERAL(46, 950, 22), // "on_PshBtn_PLot_clicked"
QT_MOC_LITERAL(47, 973, 26), // "on_m_PshBtn_Delete_clicked"
QT_MOC_LITERAL(48, 1000, 29), // "on_radioButton_x_axis_clicked"
QT_MOC_LITERAL(49, 1030, 29), // "on_radioButton_y_axis_clicked"
QT_MOC_LITERAL(50, 1060, 24), // "on_m_PshBtn_Save_clicked"
QT_MOC_LITERAL(51, 1085, 26), // "on_m_PshBtn_export_clicked"
QT_MOC_LITERAL(52, 1112, 30), // "on_m_PshBtn_SavedPlots_clicked"
QT_MOC_LITERAL(53, 1143, 27), // "on_m_PshBtn_Scaling_clicked"
QT_MOC_LITERAL(54, 1171, 31), // "on_m_PshBtn_ImportGraph_clicked"
QT_MOC_LITERAL(55, 1203, 33), // "on_cmbBx_Type_currentIndexCha..."
QT_MOC_LITERAL(56, 1237, 38), // "on_comboBox_CriParm_currentTe..."
QT_MOC_LITERAL(57, 1276, 41), // "on_comboBox_AndCriParm_curren..."
QT_MOC_LITERAL(58, 1318, 36), // "on_cmbx_Discreate_currentText..."
QT_MOC_LITERAL(59, 1355, 39), // "on_cmbx_DiscreateAnd_currentT..."
QT_MOC_LITERAL(60, 1395, 27), // "on_pushButton_about_clicked"
QT_MOC_LITERAL(61, 1423, 41), // "on_comboBox_databases_current..."
QT_MOC_LITERAL(62, 1465, 5), // "index"
QT_MOC_LITERAL(63, 1471, 26), // "on_pshbtnSearchNow_clicked"
QT_MOC_LITERAL(64, 1498, 26), // "on_pshbtnSelectNow_clicked"
QT_MOC_LITERAL(65, 1525, 36), // "on_treeWidget_TrackTypes_item..."
QT_MOC_LITERAL(66, 1562, 36), // "on_treeWidget_TrackTypes_item..."
QT_MOC_LITERAL(67, 1599, 30), // "on_radioButton_y_axis2_clicked"
QT_MOC_LITERAL(68, 1630, 39), // "on_cmbBx_SavedGroup_currentIn..."
QT_MOC_LITERAL(69, 1670, 40), // "on_comboBox_databases_current..."
QT_MOC_LITERAL(70, 1711, 30), // "on_lineEdit_Before_textChanged"
QT_MOC_LITERAL(71, 1742, 29), // "on_lineEdit_After_textChanged"
QT_MOC_LITERAL(72, 1772, 34) // "on_m_PshBtn_exportcsvFrmDB_cl..."

    },
    "Selection\0rotate\0\0xAxisChanged\0QCPRange\0"
    "range\0yAxisChanged\0controlledZoomX\0"
    "QWheelEvent*\0event\0mouseRelease\0"
    "QMouseEvent*\0mousePress\0mouseMove\0"
    "deleteGroup\0del_groupname\0addGroup\0"
    "add_groupname\0CheckConnection\0"
    "on_pushButton_connect_clicked\0"
    "on_comboBox_ConnectedIPs_currentTextChanged\0"
    "arg1\0on_timeEdit_StartTime_timeChanged\0"
    "time\0on_timeEdit_EndTime_timeChanged\0"
    "on_timeEdit_PValueStart_timeChanged\0"
    "on_timeEdit_PValueEnd_timeChanged\0"
    "on_cmbBx_Etime_currentIndexChanged\0"
    "on_cmbBx_Samples_currentTextChanged\0"
    "value\0on_cmbBx_Samples_currentIndexChanged\0"
    "on_cmbBx_EtimeDur_currentIndexChanged\0"
    "on_TimeStamp_StartTime_dateTimeChanged\0"
    "dateTime\0on_TimeStamp_EndTime_dateTimeChanged\0"
    "on_radioButton_TSEndTime_clicked\0"
    "on_radioButton_TSDurTime_clicked\0"
    "on_End_PvradioBtn_clicked\0"
    "on_Dur_PvradioBtn_clicked\0"
    "on_PshBtn_search_clicked\0"
    "on_Pvalue_StartdateTime_dateTimeChanged\0"
    "on_treeWidget_ParameterTimeValue_itemClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_pshBtn_clearParams_clicked\0"
    "on_PshBtn_PLot_clicked\0"
    "on_m_PshBtn_Delete_clicked\0"
    "on_radioButton_x_axis_clicked\0"
    "on_radioButton_y_axis_clicked\0"
    "on_m_PshBtn_Save_clicked\0"
    "on_m_PshBtn_export_clicked\0"
    "on_m_PshBtn_SavedPlots_clicked\0"
    "on_m_PshBtn_Scaling_clicked\0"
    "on_m_PshBtn_ImportGraph_clicked\0"
    "on_cmbBx_Type_currentIndexChanged\0"
    "on_comboBox_CriParm_currentTextChanged\0"
    "on_comboBox_AndCriParm_currentTextChanged\0"
    "on_cmbx_Discreate_currentTextChanged\0"
    "on_cmbx_DiscreateAnd_currentTextChanged\0"
    "on_pushButton_about_clicked\0"
    "on_comboBox_databases_currentIndexChanged\0"
    "index\0on_pshbtnSearchNow_clicked\0"
    "on_pshbtnSelectNow_clicked\0"
    "on_treeWidget_TrackTypes_itemChanged\0"
    "on_treeWidget_TrackTypes_itemPressed\0"
    "on_radioButton_y_axis2_clicked\0"
    "on_cmbBx_SavedGroup_currentIndexChanged\0"
    "on_comboBox_databases_currentTextChanged\0"
    "on_lineEdit_Before_textChanged\0"
    "on_lineEdit_After_textChanged\0"
    "on_m_PshBtn_exportcsvFrmDB_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Selection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      56,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  294,    2, 0x0a /* Public */,
       3,    1,  295,    2, 0x0a /* Public */,
       6,    1,  298,    2, 0x0a /* Public */,
       7,    1,  301,    2, 0x0a /* Public */,
      10,    1,  304,    2, 0x0a /* Public */,
      12,    1,  307,    2, 0x0a /* Public */,
      13,    1,  310,    2, 0x0a /* Public */,
      14,    1,  313,    2, 0x0a /* Public */,
      16,    1,  316,    2, 0x0a /* Public */,
      18,    0,  319,    2, 0x08 /* Private */,
      19,    0,  320,    2, 0x08 /* Private */,
      20,    1,  321,    2, 0x08 /* Private */,
      22,    1,  324,    2, 0x08 /* Private */,
      24,    1,  327,    2, 0x08 /* Private */,
      25,    1,  330,    2, 0x08 /* Private */,
      26,    1,  333,    2, 0x08 /* Private */,
      27,    1,  336,    2, 0x08 /* Private */,
      28,    1,  339,    2, 0x08 /* Private */,
      30,    1,  342,    2, 0x08 /* Private */,
      31,    1,  345,    2, 0x08 /* Private */,
      32,    1,  348,    2, 0x08 /* Private */,
      34,    1,  351,    2, 0x08 /* Private */,
      35,    0,  354,    2, 0x08 /* Private */,
      36,    0,  355,    2, 0x08 /* Private */,
      37,    0,  356,    2, 0x08 /* Private */,
      38,    0,  357,    2, 0x08 /* Private */,
      39,    0,  358,    2, 0x08 /* Private */,
      40,    1,  359,    2, 0x08 /* Private */,
      41,    2,  362,    2, 0x08 /* Private */,
      45,    0,  367,    2, 0x08 /* Private */,
      46,    0,  368,    2, 0x08 /* Private */,
      47,    0,  369,    2, 0x08 /* Private */,
      48,    0,  370,    2, 0x08 /* Private */,
      49,    0,  371,    2, 0x08 /* Private */,
      50,    0,  372,    2, 0x08 /* Private */,
      51,    0,  373,    2, 0x08 /* Private */,
      52,    0,  374,    2, 0x08 /* Private */,
      53,    0,  375,    2, 0x08 /* Private */,
      54,    0,  376,    2, 0x08 /* Private */,
      55,    1,  377,    2, 0x08 /* Private */,
      56,    1,  380,    2, 0x08 /* Private */,
      57,    1,  383,    2, 0x08 /* Private */,
      58,    1,  386,    2, 0x08 /* Private */,
      59,    1,  389,    2, 0x08 /* Private */,
      60,    0,  392,    2, 0x08 /* Private */,
      61,    1,  393,    2, 0x08 /* Private */,
      63,    0,  396,    2, 0x08 /* Private */,
      64,    0,  397,    2, 0x08 /* Private */,
      65,    2,  398,    2, 0x08 /* Private */,
      66,    2,  403,    2, 0x08 /* Private */,
      67,    0,  408,    2, 0x08 /* Private */,
      68,    1,  409,    2, 0x08 /* Private */,
      69,    1,  412,    2, 0x08 /* Private */,
      70,    1,  415,    2, 0x08 /* Private */,
      71,    1,  418,    2, 0x08 /* Private */,
      72,    0,  421,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QTime,   23,
    QMetaType::Void, QMetaType::QTime,   23,
    QMetaType::Void, QMetaType::QTime,   23,
    QMetaType::Void, QMetaType::QTime,   23,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QDateTime,   33,
    QMetaType::Void, QMetaType::QDateTime,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   33,
    QMetaType::Void, 0x80000000 | 42, QMetaType::Int,   43,   44,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   62,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 42, QMetaType::Int,   43,   44,
    QMetaType::Void, 0x80000000 | 42, QMetaType::Int,   43,   44,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,

       0        // eod
};

void Selection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Selection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rotate(); break;
        case 1: _t->xAxisChanged((*reinterpret_cast< QCPRange(*)>(_a[1]))); break;
        case 2: _t->yAxisChanged((*reinterpret_cast< QCPRange(*)>(_a[1]))); break;
        case 3: _t->controlledZoomX((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 4: _t->mouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->mousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->deleteGroup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->addGroup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->CheckConnection(); break;
        case 10: _t->on_pushButton_connect_clicked(); break;
        case 11: _t->on_comboBox_ConnectedIPs_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_timeEdit_StartTime_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 13: _t->on_timeEdit_EndTime_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 14: _t->on_timeEdit_PValueStart_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 15: _t->on_timeEdit_PValueEnd_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 16: _t->on_cmbBx_Etime_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->on_cmbBx_Samples_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->on_cmbBx_Samples_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->on_cmbBx_EtimeDur_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->on_TimeStamp_StartTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 21: _t->on_TimeStamp_EndTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 22: _t->on_radioButton_TSEndTime_clicked(); break;
        case 23: _t->on_radioButton_TSDurTime_clicked(); break;
        case 24: _t->on_End_PvradioBtn_clicked(); break;
        case 25: _t->on_Dur_PvradioBtn_clicked(); break;
        case 26: _t->on_PshBtn_search_clicked(); break;
        case 27: _t->on_Pvalue_StartdateTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 28: _t->on_treeWidget_ParameterTimeValue_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 29: _t->on_pshBtn_clearParams_clicked(); break;
        case 30: _t->on_PshBtn_PLot_clicked(); break;
        case 31: _t->on_m_PshBtn_Delete_clicked(); break;
        case 32: _t->on_radioButton_x_axis_clicked(); break;
        case 33: _t->on_radioButton_y_axis_clicked(); break;
        case 34: _t->on_m_PshBtn_Save_clicked(); break;
        case 35: _t->on_m_PshBtn_export_clicked(); break;
        case 36: _t->on_m_PshBtn_SavedPlots_clicked(); break;
        case 37: _t->on_m_PshBtn_Scaling_clicked(); break;
        case 38: _t->on_m_PshBtn_ImportGraph_clicked(); break;
        case 39: _t->on_cmbBx_Type_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->on_comboBox_CriParm_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->on_comboBox_AndCriParm_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->on_cmbx_Discreate_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 43: _t->on_cmbx_DiscreateAnd_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 44: _t->on_pushButton_about_clicked(); break;
        case 45: _t->on_comboBox_databases_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->on_pshbtnSearchNow_clicked(); break;
        case 47: _t->on_pshbtnSelectNow_clicked(); break;
        case 48: _t->on_treeWidget_TrackTypes_itemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 49: _t->on_treeWidget_TrackTypes_itemPressed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 50: _t->on_radioButton_y_axis2_clicked(); break;
        case 51: _t->on_cmbBx_SavedGroup_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 52: _t->on_comboBox_databases_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 53: _t->on_lineEdit_Before_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 54: _t->on_lineEdit_After_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 55: _t->on_m_PshBtn_exportcsvFrmDB_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Selection::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Selection.data,
    qt_meta_data_Selection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Selection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Selection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Selection.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Selection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 56)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 56;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 56)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 56;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
