/********************************************************************************
** Form generated from reading UI file 'commissionsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMISSIONSETTING_H
#define UI_COMMISSIONSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommissionSetting
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_16;
    QToolButton *toolButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_6;
    QComboBox *comboBox_ConnectedIPs;
    QPushButton *pushButton_connect;
    QLabel *lbl_error_msg;
    QLabel *lbl_Connection;
    QLabel *label_4;
    QComboBox *comboBox_databases;
    QToolButton *toolButton_Version;
    QSpacerItem *horizontalSpacer;
    QFrame *m_FrameTypeOfPlan_3;
    QVBoxLayout *m_VBoxFrameTypeOfPlan_4;
    QHBoxLayout *m_HBoxTypeOfSearchPlan_5;
    QLabel *m_lblLP_12;
    QSpacerItem *m_RightSprLP_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *m_lblLP_6;
    QLabel *label_UTC_Time;
    QLabel *label_2;
    QDateTimeEdit *TimeStamp_Date;
    QTimeEdit *timeEdit_Time;
    QPushButton *m_PshBtn_UTC_Time;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_lblLP_7;
    QLabel *label_Locale_time;
    QLabel *label_3;
    QComboBox *comboBox_Locale;
    QPushButton *m_PshBtn_LocaleTime;
    QSpacerItem *horizontalSpacer_8;
    QFrame *m_FrameTypeOfPlan_4;
    QVBoxLayout *m_VBoxFrameTypeOfPlan_5;
    QHBoxLayout *m_HBoxTypeOfSearchPlan_6;
    QLabel *m_lblLP_13;
    QSpacerItem *m_RightSprLP_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *m_lblLP_8;
    QLineEdit *lineEdit_DataPort;
    QPushButton *m_PshBtn_PLCDataPortSave;
    QPushButton *m_PshBtn_PLCDataPortArrival;
    QPushButton *m_PshBtn_DataPort_Reset;
    QLabel *m_lblLP_9;
    QLineEdit *lineEdit_AlarmPort;
    QPushButton *m_PshBtn_PLCAlarmPortSave;
    QPushButton *m_PshBtn_PLCAlarmPortArrival;
    QPushButton *m_PshBtn_AlarmPort_Reset;
    QSpacerItem *horizontalSpacer_3;
    QFrame *m_FrameTypeOfPlan_5;
    QVBoxLayout *m_VBoxFrameTypeOfPlan_6;
    QHBoxLayout *m_HBoxTypeOfSearchPlan_7;
    QLabel *m_lblLP_14;
    QSpacerItem *m_RightSprLP_7;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *m_lblLP_10;
    QLabel *label_AWLFile;
    QToolButton *toolButton_AWLFile;
    QPushButton *m_PshBtn_AWLFileUpload;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *m_lblLP_11;
    QRadioButton *radioBtn_Alarm640;
    QRadioButton *radioBtn_Alarm1280;
    QPushButton *m_PshBtn_Alarm;
    QLabel *label_Alarm_message;
    QSpacerItem *horizontalSpacer_5;
    QFrame *m_FrameTypeOfPlan_6;
    QVBoxLayout *m_VBoxFrameTypeOfPlan_7;
    QHBoxLayout *m_HBoxTypeOfSearchPlan_8;
    QLabel *m_lblLP_15;
    QSpacerItem *m_RightSprLP_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *m_lblLP_17;
    QLineEdit *lineEdit_APIPort;
    QPushButton *m_PshBtn_API_Set;
    QPushButton *m_PshBtn_API_Check;
    QPushButton *m_PshBtn_API_Reset;
    QSpacerItem *horizontalSpacer_2;
    QFrame *m_FrameTypeOfPlan_7;
    QVBoxLayout *m_VBoxFrameTypeOfPlan_8;
    QHBoxLayout *m_HBoxTypeOfSearchPlan_9;
    QLabel *m_lblLP_16;
    QSpacerItem *m_RightSprLP_9;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CommissionSetting)
    {
        if (CommissionSetting->objectName().isEmpty())
            CommissionSetting->setObjectName(QString::fromUtf8("CommissionSetting"));
        CommissionSetting->resize(1662, 600);
        CommissionSetting->setStyleSheet(QString::fromUtf8("font: 12pt \"MS Shell Dlg 2\";"));
        verticalLayout_5 = new QVBoxLayout(CommissionSetting);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(4, 0, 0, -1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(-1, 3, 1, -1);
        toolButton = new QToolButton(CommissionSetting);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(35, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/C_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(30, 24));

        horizontalLayout_16->addWidget(toolButton);

        label = new QLabel(CommissionSetting);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("color: rgb(204, 0, 0);"));

        horizontalLayout_16->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_6);

        label_6 = new QLabel(CommissionSetting);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_16->addWidget(label_6);

        comboBox_ConnectedIPs = new QComboBox(CommissionSetting);
        comboBox_ConnectedIPs->setObjectName(QString::fromUtf8("comboBox_ConnectedIPs"));
        comboBox_ConnectedIPs->setMinimumSize(QSize(180, 30));
        comboBox_ConnectedIPs->setEditable(true);

        horizontalLayout_16->addWidget(comboBox_ConnectedIPs);

        pushButton_connect = new QPushButton(CommissionSetting);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setMinimumSize(QSize(120, 30));
        pushButton_connect->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
""));

        horizontalLayout_16->addWidget(pushButton_connect);

        lbl_error_msg = new QLabel(CommissionSetting);
        lbl_error_msg->setObjectName(QString::fromUtf8("lbl_error_msg"));

        horizontalLayout_16->addWidget(lbl_error_msg);

        lbl_Connection = new QLabel(CommissionSetting);
        lbl_Connection->setObjectName(QString::fromUtf8("lbl_Connection"));
        lbl_Connection->setMinimumSize(QSize(30, 30));
        lbl_Connection->setMaximumSize(QSize(30, 30));
        lbl_Connection->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        horizontalLayout_16->addWidget(lbl_Connection);

        label_4 = new QLabel(CommissionSetting);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_16->addWidget(label_4);

        comboBox_databases = new QComboBox(CommissionSetting);
        comboBox_databases->setObjectName(QString::fromUtf8("comboBox_databases"));
        comboBox_databases->setMinimumSize(QSize(0, 0));
        comboBox_databases->setFocusPolicy(Qt::NoFocus);
        comboBox_databases->setEditable(true);

        horizontalLayout_16->addWidget(comboBox_databases);

        toolButton_Version = new QToolButton(CommissionSetting);
        toolButton_Version->setObjectName(QString::fromUtf8("toolButton_Version"));
        toolButton_Version->setMinimumSize(QSize(0, 30));

        horizontalLayout_16->addWidget(toolButton_Version);

        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_16);

        m_FrameTypeOfPlan_3 = new QFrame(CommissionSetting);
        m_FrameTypeOfPlan_3->setObjectName(QString::fromUtf8("m_FrameTypeOfPlan_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_FrameTypeOfPlan_3->sizePolicy().hasHeightForWidth());
        m_FrameTypeOfPlan_3->setSizePolicy(sizePolicy1);
        m_FrameTypeOfPlan_3->setMaximumSize(QSize(16777215, 28));
        m_FrameTypeOfPlan_3->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: rgb(51, 51, 51);\n"
"}\n"
""));
        m_FrameTypeOfPlan_3->setFrameShape(QFrame::StyledPanel);
        m_FrameTypeOfPlan_3->setFrameShadow(QFrame::Raised);
        m_VBoxFrameTypeOfPlan_4 = new QVBoxLayout(m_FrameTypeOfPlan_3);
        m_VBoxFrameTypeOfPlan_4->setSpacing(5);
        m_VBoxFrameTypeOfPlan_4->setObjectName(QString::fromUtf8("m_VBoxFrameTypeOfPlan_4"));
        m_VBoxFrameTypeOfPlan_4->setContentsMargins(0, 0, 0, 0);
        m_HBoxTypeOfSearchPlan_5 = new QHBoxLayout();
        m_HBoxTypeOfSearchPlan_5->setSpacing(3);
        m_HBoxTypeOfSearchPlan_5->setObjectName(QString::fromUtf8("m_HBoxTypeOfSearchPlan_5"));
        m_HBoxTypeOfSearchPlan_5->setContentsMargins(9, 0, 0, 5);
        m_lblLP_12 = new QLabel(m_FrameTypeOfPlan_3);
        m_lblLP_12->setObjectName(QString::fromUtf8("m_lblLP_12"));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans 13"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        m_lblLP_12->setFont(font);
        m_lblLP_12->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 12pt \"Open Sans\" bold;\n"
"}"));

        m_HBoxTypeOfSearchPlan_5->addWidget(m_lblLP_12);

        m_RightSprLP_5 = new QSpacerItem(76, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        m_HBoxTypeOfSearchPlan_5->addItem(m_RightSprLP_5);


        m_VBoxFrameTypeOfPlan_4->addLayout(m_HBoxTypeOfSearchPlan_5);


        verticalLayout_4->addWidget(m_FrameTypeOfPlan_3);

        frame = new QFrame(CommissionSetting);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 230, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_lblLP_6 = new QLabel(frame);
        m_lblLP_6->setObjectName(QString::fromUtf8("m_lblLP_6"));
        sizePolicy.setHeightForWidth(m_lblLP_6->sizePolicy().hasHeightForWidth());
        m_lblLP_6->setSizePolicy(sizePolicy);
        m_lblLP_6->setMinimumSize(QSize(170, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        m_lblLP_6->setFont(font1);
        m_lblLP_6->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));
        m_lblLP_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(m_lblLP_6);

        label_UTC_Time = new QLabel(frame);
        label_UTC_Time->setObjectName(QString::fromUtf8("label_UTC_Time"));
        sizePolicy.setHeightForWidth(label_UTC_Time->sizePolicy().hasHeightForWidth());
        label_UTC_Time->setSizePolicy(sizePolicy);
        label_UTC_Time->setMinimumSize(QSize(250, 30));
        label_UTC_Time->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_UTC_Time->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_UTC_Time);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(90, 30));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        TimeStamp_Date = new QDateTimeEdit(frame);
        TimeStamp_Date->setObjectName(QString::fromUtf8("TimeStamp_Date"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TimeStamp_Date->sizePolicy().hasHeightForWidth());
        TimeStamp_Date->setSizePolicy(sizePolicy2);
        TimeStamp_Date->setMaximumSize(QSize(130, 35));
        TimeStamp_Date->setStyleSheet(QString::fromUtf8("QDateTimeEdit\n"
"{\n"
"background-color: rgb(212, 212, 212);\n"
"}\n"
"QDateTimeEdit:!enabled\n"
"{	\n"
"background-color: rgb(212, 212, 212);\n"
"	color:black;\n"
"}"));
        TimeStamp_Date->setCalendarPopup(true);

        horizontalLayout->addWidget(TimeStamp_Date);

        timeEdit_Time = new QTimeEdit(frame);
        timeEdit_Time->setObjectName(QString::fromUtf8("timeEdit_Time"));
        sizePolicy1.setHeightForWidth(timeEdit_Time->sizePolicy().hasHeightForWidth());
        timeEdit_Time->setSizePolicy(sizePolicy1);
        timeEdit_Time->setMinimumSize(QSize(120, 35));
        timeEdit_Time->setMaximumSize(QSize(120, 35));
        timeEdit_Time->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));
        timeEdit_Time->setCalendarPopup(true);

        horizontalLayout->addWidget(timeEdit_Time);

        m_PshBtn_UTC_Time = new QPushButton(frame);
        m_PshBtn_UTC_Time->setObjectName(QString::fromUtf8("m_PshBtn_UTC_Time"));
        sizePolicy.setHeightForWidth(m_PshBtn_UTC_Time->sizePolicy().hasHeightForWidth());
        m_PshBtn_UTC_Time->setSizePolicy(sizePolicy);
        m_PshBtn_UTC_Time->setMinimumSize(QSize(120, 30));
        m_PshBtn_UTC_Time->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/apply-btn.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_PshBtn_UTC_Time->setIcon(icon1);

        horizontalLayout->addWidget(m_PshBtn_UTC_Time);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_lblLP_7 = new QLabel(frame);
        m_lblLP_7->setObjectName(QString::fromUtf8("m_lblLP_7"));
        sizePolicy.setHeightForWidth(m_lblLP_7->sizePolicy().hasHeightForWidth());
        m_lblLP_7->setSizePolicy(sizePolicy);
        m_lblLP_7->setMinimumSize(QSize(170, 30));
        m_lblLP_7->setFont(font1);
        m_lblLP_7->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));
        m_lblLP_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(m_lblLP_7);

        label_Locale_time = new QLabel(frame);
        label_Locale_time->setObjectName(QString::fromUtf8("label_Locale_time"));
        sizePolicy2.setHeightForWidth(label_Locale_time->sizePolicy().hasHeightForWidth());
        label_Locale_time->setSizePolicy(sizePolicy2);
        label_Locale_time->setMinimumSize(QSize(480, 30));
        label_Locale_time->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_Locale_time->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_Locale_time);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(90, 30));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        comboBox_Locale = new QComboBox(frame);
        comboBox_Locale->setObjectName(QString::fromUtf8("comboBox_Locale"));
        comboBox_Locale->setMinimumSize(QSize(250, 30));
        comboBox_Locale->setMaximumSize(QSize(250, 30));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(212, 212, 212, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 200, 29, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        comboBox_Locale->setPalette(palette);
        comboBox_Locale->setFocusPolicy(Qt::ClickFocus);
        comboBox_Locale->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));
        comboBox_Locale->setEditable(true);

        horizontalLayout_2->addWidget(comboBox_Locale);

        m_PshBtn_LocaleTime = new QPushButton(frame);
        m_PshBtn_LocaleTime->setObjectName(QString::fromUtf8("m_PshBtn_LocaleTime"));
        sizePolicy.setHeightForWidth(m_PshBtn_LocaleTime->sizePolicy().hasHeightForWidth());
        m_PshBtn_LocaleTime->setSizePolicy(sizePolicy);
        m_PshBtn_LocaleTime->setMinimumSize(QSize(120, 30));
        m_PshBtn_LocaleTime->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        m_PshBtn_LocaleTime->setIcon(icon1);

        horizontalLayout_2->addWidget(m_PshBtn_LocaleTime);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(frame);

        m_FrameTypeOfPlan_4 = new QFrame(CommissionSetting);
        m_FrameTypeOfPlan_4->setObjectName(QString::fromUtf8("m_FrameTypeOfPlan_4"));
        sizePolicy1.setHeightForWidth(m_FrameTypeOfPlan_4->sizePolicy().hasHeightForWidth());
        m_FrameTypeOfPlan_4->setSizePolicy(sizePolicy1);
        m_FrameTypeOfPlan_4->setMaximumSize(QSize(16777215, 28));
        m_FrameTypeOfPlan_4->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: rgb(51, 51, 51);\n"
"}\n"
""));
        m_FrameTypeOfPlan_4->setFrameShape(QFrame::StyledPanel);
        m_FrameTypeOfPlan_4->setFrameShadow(QFrame::Raised);
        m_VBoxFrameTypeOfPlan_5 = new QVBoxLayout(m_FrameTypeOfPlan_4);
        m_VBoxFrameTypeOfPlan_5->setSpacing(5);
        m_VBoxFrameTypeOfPlan_5->setObjectName(QString::fromUtf8("m_VBoxFrameTypeOfPlan_5"));
        m_VBoxFrameTypeOfPlan_5->setContentsMargins(0, 0, 0, 0);
        m_HBoxTypeOfSearchPlan_6 = new QHBoxLayout();
        m_HBoxTypeOfSearchPlan_6->setSpacing(3);
        m_HBoxTypeOfSearchPlan_6->setObjectName(QString::fromUtf8("m_HBoxTypeOfSearchPlan_6"));
        m_HBoxTypeOfSearchPlan_6->setContentsMargins(9, 0, 0, 5);
        m_lblLP_13 = new QLabel(m_FrameTypeOfPlan_4);
        m_lblLP_13->setObjectName(QString::fromUtf8("m_lblLP_13"));
        m_lblLP_13->setFont(font);
        m_lblLP_13->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 12pt \"Open Sans\" bold;\n"
"}"));

        m_HBoxTypeOfSearchPlan_6->addWidget(m_lblLP_13);

        m_RightSprLP_6 = new QSpacerItem(76, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        m_HBoxTypeOfSearchPlan_6->addItem(m_RightSprLP_6);


        m_VBoxFrameTypeOfPlan_5->addLayout(m_HBoxTypeOfSearchPlan_6);


        verticalLayout_4->addWidget(m_FrameTypeOfPlan_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_lblLP_8 = new QLabel(CommissionSetting);
        m_lblLP_8->setObjectName(QString::fromUtf8("m_lblLP_8"));
        sizePolicy.setHeightForWidth(m_lblLP_8->sizePolicy().hasHeightForWidth());
        m_lblLP_8->setSizePolicy(sizePolicy);
        m_lblLP_8->setMinimumSize(QSize(85, 30));
        m_lblLP_8->setFont(font1);
        m_lblLP_8->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));
        m_lblLP_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(m_lblLP_8);

        lineEdit_DataPort = new QLineEdit(CommissionSetting);
        lineEdit_DataPort->setObjectName(QString::fromUtf8("lineEdit_DataPort"));
        sizePolicy.setHeightForWidth(lineEdit_DataPort->sizePolicy().hasHeightForWidth());
        lineEdit_DataPort->setSizePolicy(sizePolicy);
        lineEdit_DataPort->setMinimumSize(QSize(85, 30));
        lineEdit_DataPort->setMaximumSize(QSize(85, 30));

        horizontalLayout_3->addWidget(lineEdit_DataPort);

        m_PshBtn_PLCDataPortSave = new QPushButton(CommissionSetting);
        m_PshBtn_PLCDataPortSave->setObjectName(QString::fromUtf8("m_PshBtn_PLCDataPortSave"));
        m_PshBtn_PLCDataPortSave->setMinimumSize(QSize(120, 30));
        m_PshBtn_PLCDataPortSave->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        m_PshBtn_PLCDataPortSave->setIcon(icon1);

        horizontalLayout_3->addWidget(m_PshBtn_PLCDataPortSave);

        m_PshBtn_PLCDataPortArrival = new QPushButton(CommissionSetting);
        m_PshBtn_PLCDataPortArrival->setObjectName(QString::fromUtf8("m_PshBtn_PLCDataPortArrival"));
        m_PshBtn_PLCDataPortArrival->setMinimumSize(QSize(120, 30));
        m_PshBtn_PLCDataPortArrival->setToolTipDuration(-2);
        m_PshBtn_PLCDataPortArrival->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));

        horizontalLayout_3->addWidget(m_PshBtn_PLCDataPortArrival);

        m_PshBtn_DataPort_Reset = new QPushButton(CommissionSetting);
        m_PshBtn_DataPort_Reset->setObjectName(QString::fromUtf8("m_PshBtn_DataPort_Reset"));
        m_PshBtn_DataPort_Reset->setMinimumSize(QSize(130, 30));
        m_PshBtn_DataPort_Reset->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_PshBtn_DataPort_Reset->setIcon(icon2);

        horizontalLayout_3->addWidget(m_PshBtn_DataPort_Reset);

        m_lblLP_9 = new QLabel(CommissionSetting);
        m_lblLP_9->setObjectName(QString::fromUtf8("m_lblLP_9"));
        sizePolicy.setHeightForWidth(m_lblLP_9->sizePolicy().hasHeightForWidth());
        m_lblLP_9->setSizePolicy(sizePolicy);
        m_lblLP_9->setMinimumSize(QSize(0, 30));
        m_lblLP_9->setFont(font1);
        m_lblLP_9->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));

        horizontalLayout_3->addWidget(m_lblLP_9);

        lineEdit_AlarmPort = new QLineEdit(CommissionSetting);
        lineEdit_AlarmPort->setObjectName(QString::fromUtf8("lineEdit_AlarmPort"));
        sizePolicy.setHeightForWidth(lineEdit_AlarmPort->sizePolicy().hasHeightForWidth());
        lineEdit_AlarmPort->setSizePolicy(sizePolicy);
        lineEdit_AlarmPort->setMinimumSize(QSize(85, 30));
        lineEdit_AlarmPort->setMaximumSize(QSize(85, 30));

        horizontalLayout_3->addWidget(lineEdit_AlarmPort);

        m_PshBtn_PLCAlarmPortSave = new QPushButton(CommissionSetting);
        m_PshBtn_PLCAlarmPortSave->setObjectName(QString::fromUtf8("m_PshBtn_PLCAlarmPortSave"));
        sizePolicy.setHeightForWidth(m_PshBtn_PLCAlarmPortSave->sizePolicy().hasHeightForWidth());
        m_PshBtn_PLCAlarmPortSave->setSizePolicy(sizePolicy);
        m_PshBtn_PLCAlarmPortSave->setMinimumSize(QSize(120, 30));
        m_PshBtn_PLCAlarmPortSave->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        m_PshBtn_PLCAlarmPortSave->setIcon(icon1);

        horizontalLayout_3->addWidget(m_PshBtn_PLCAlarmPortSave);

        m_PshBtn_PLCAlarmPortArrival = new QPushButton(CommissionSetting);
        m_PshBtn_PLCAlarmPortArrival->setObjectName(QString::fromUtf8("m_PshBtn_PLCAlarmPortArrival"));
        m_PshBtn_PLCAlarmPortArrival->setMinimumSize(QSize(120, 30));
        m_PshBtn_PLCAlarmPortArrival->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));

        horizontalLayout_3->addWidget(m_PshBtn_PLCAlarmPortArrival);

        m_PshBtn_AlarmPort_Reset = new QPushButton(CommissionSetting);
        m_PshBtn_AlarmPort_Reset->setObjectName(QString::fromUtf8("m_PshBtn_AlarmPort_Reset"));
        m_PshBtn_AlarmPort_Reset->setMinimumSize(QSize(130, 30));
        m_PshBtn_AlarmPort_Reset->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        m_PshBtn_AlarmPort_Reset->setIcon(icon2);

        horizontalLayout_3->addWidget(m_PshBtn_AlarmPort_Reset);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        m_FrameTypeOfPlan_5 = new QFrame(CommissionSetting);
        m_FrameTypeOfPlan_5->setObjectName(QString::fromUtf8("m_FrameTypeOfPlan_5"));
        sizePolicy1.setHeightForWidth(m_FrameTypeOfPlan_5->sizePolicy().hasHeightForWidth());
        m_FrameTypeOfPlan_5->setSizePolicy(sizePolicy1);
        m_FrameTypeOfPlan_5->setMaximumSize(QSize(16777215, 28));
        m_FrameTypeOfPlan_5->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: rgb(51, 51, 51);\n"
"}\n"
""));
        m_FrameTypeOfPlan_5->setFrameShape(QFrame::StyledPanel);
        m_FrameTypeOfPlan_5->setFrameShadow(QFrame::Raised);
        m_VBoxFrameTypeOfPlan_6 = new QVBoxLayout(m_FrameTypeOfPlan_5);
        m_VBoxFrameTypeOfPlan_6->setSpacing(5);
        m_VBoxFrameTypeOfPlan_6->setObjectName(QString::fromUtf8("m_VBoxFrameTypeOfPlan_6"));
        m_VBoxFrameTypeOfPlan_6->setContentsMargins(0, 0, 0, 0);
        m_HBoxTypeOfSearchPlan_7 = new QHBoxLayout();
        m_HBoxTypeOfSearchPlan_7->setSpacing(3);
        m_HBoxTypeOfSearchPlan_7->setObjectName(QString::fromUtf8("m_HBoxTypeOfSearchPlan_7"));
        m_HBoxTypeOfSearchPlan_7->setContentsMargins(9, 0, 0, 5);
        m_lblLP_14 = new QLabel(m_FrameTypeOfPlan_5);
        m_lblLP_14->setObjectName(QString::fromUtf8("m_lblLP_14"));
        m_lblLP_14->setFont(font);
        m_lblLP_14->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 12pt \"Open Sans\" bold;\n"
"}"));

        m_HBoxTypeOfSearchPlan_7->addWidget(m_lblLP_14);

        m_RightSprLP_7 = new QSpacerItem(76, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        m_HBoxTypeOfSearchPlan_7->addItem(m_RightSprLP_7);


        m_VBoxFrameTypeOfPlan_6->addLayout(m_HBoxTypeOfSearchPlan_7);


        verticalLayout_4->addWidget(m_FrameTypeOfPlan_5);

        frame_2 = new QFrame(CommissionSetting);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 230, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, 0, -1);
        m_lblLP_10 = new QLabel(frame_2);
        m_lblLP_10->setObjectName(QString::fromUtf8("m_lblLP_10"));
        sizePolicy.setHeightForWidth(m_lblLP_10->sizePolicy().hasHeightForWidth());
        m_lblLP_10->setSizePolicy(sizePolicy);
        m_lblLP_10->setMinimumSize(QSize(270, 30));
        m_lblLP_10->setFont(font1);
        m_lblLP_10->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));
        m_lblLP_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(m_lblLP_10);

        label_AWLFile = new QLabel(frame_2);
        label_AWLFile->setObjectName(QString::fromUtf8("label_AWLFile"));
        sizePolicy.setHeightForWidth(label_AWLFile->sizePolicy().hasHeightForWidth());
        label_AWLFile->setSizePolicy(sizePolicy);
        label_AWLFile->setMinimumSize(QSize(220, 30));
        label_AWLFile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_AWLFile->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_AWLFile);

        toolButton_AWLFile = new QToolButton(frame_2);
        toolButton_AWLFile->setObjectName(QString::fromUtf8("toolButton_AWLFile"));
        toolButton_AWLFile->setMinimumSize(QSize(95, 30));
        toolButton_AWLFile->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(toolButton_AWLFile);

        m_PshBtn_AWLFileUpload = new QPushButton(frame_2);
        m_PshBtn_AWLFileUpload->setObjectName(QString::fromUtf8("m_PshBtn_AWLFileUpload"));
        sizePolicy.setHeightForWidth(m_PshBtn_AWLFileUpload->sizePolicy().hasHeightForWidth());
        m_PshBtn_AWLFileUpload->setSizePolicy(sizePolicy);
        m_PshBtn_AWLFileUpload->setMinimumSize(QSize(120, 30));
        m_PshBtn_AWLFileUpload->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        m_PshBtn_AWLFileUpload->setIcon(icon1);

        horizontalLayout_4->addWidget(m_PshBtn_AWLFileUpload);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        m_lblLP_11 = new QLabel(frame_2);
        m_lblLP_11->setObjectName(QString::fromUtf8("m_lblLP_11"));
        sizePolicy.setHeightForWidth(m_lblLP_11->sizePolicy().hasHeightForWidth());
        m_lblLP_11->setSizePolicy(sizePolicy);
        m_lblLP_11->setMinimumSize(QSize(270, 30));
        m_lblLP_11->setFont(font1);
        m_lblLP_11->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));
        m_lblLP_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(m_lblLP_11);

        radioBtn_Alarm640 = new QRadioButton(frame_2);
        radioBtn_Alarm640->setObjectName(QString::fromUtf8("radioBtn_Alarm640"));

        horizontalLayout_5->addWidget(radioBtn_Alarm640);

        radioBtn_Alarm1280 = new QRadioButton(frame_2);
        radioBtn_Alarm1280->setObjectName(QString::fromUtf8("radioBtn_Alarm1280"));

        horizontalLayout_5->addWidget(radioBtn_Alarm1280);

        m_PshBtn_Alarm = new QPushButton(frame_2);
        m_PshBtn_Alarm->setObjectName(QString::fromUtf8("m_PshBtn_Alarm"));
        m_PshBtn_Alarm->setMinimumSize(QSize(120, 30));
        m_PshBtn_Alarm->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        m_PshBtn_Alarm->setIcon(icon1);

        horizontalLayout_5->addWidget(m_PshBtn_Alarm);

        label_Alarm_message = new QLabel(frame_2);
        label_Alarm_message->setObjectName(QString::fromUtf8("label_Alarm_message"));

        horizontalLayout_5->addWidget(label_Alarm_message);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(frame_2);

        m_FrameTypeOfPlan_6 = new QFrame(CommissionSetting);
        m_FrameTypeOfPlan_6->setObjectName(QString::fromUtf8("m_FrameTypeOfPlan_6"));
        sizePolicy1.setHeightForWidth(m_FrameTypeOfPlan_6->sizePolicy().hasHeightForWidth());
        m_FrameTypeOfPlan_6->setSizePolicy(sizePolicy1);
        m_FrameTypeOfPlan_6->setMaximumSize(QSize(16777215, 28));
        m_FrameTypeOfPlan_6->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: rgb(51, 51, 51);\n"
"}\n"
""));
        m_FrameTypeOfPlan_6->setFrameShape(QFrame::StyledPanel);
        m_FrameTypeOfPlan_6->setFrameShadow(QFrame::Raised);
        m_VBoxFrameTypeOfPlan_7 = new QVBoxLayout(m_FrameTypeOfPlan_6);
        m_VBoxFrameTypeOfPlan_7->setSpacing(5);
        m_VBoxFrameTypeOfPlan_7->setObjectName(QString::fromUtf8("m_VBoxFrameTypeOfPlan_7"));
        m_VBoxFrameTypeOfPlan_7->setContentsMargins(0, 0, 0, 0);
        m_HBoxTypeOfSearchPlan_8 = new QHBoxLayout();
        m_HBoxTypeOfSearchPlan_8->setSpacing(3);
        m_HBoxTypeOfSearchPlan_8->setObjectName(QString::fromUtf8("m_HBoxTypeOfSearchPlan_8"));
        m_HBoxTypeOfSearchPlan_8->setContentsMargins(9, 0, 0, 5);
        m_lblLP_15 = new QLabel(m_FrameTypeOfPlan_6);
        m_lblLP_15->setObjectName(QString::fromUtf8("m_lblLP_15"));
        m_lblLP_15->setFont(font);
        m_lblLP_15->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 12pt \"Open Sans\" bold;\n"
"}"));

        m_HBoxTypeOfSearchPlan_8->addWidget(m_lblLP_15);

        m_RightSprLP_8 = new QSpacerItem(76, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        m_HBoxTypeOfSearchPlan_8->addItem(m_RightSprLP_8);


        m_VBoxFrameTypeOfPlan_7->addLayout(m_HBoxTypeOfSearchPlan_8);


        verticalLayout_4->addWidget(m_FrameTypeOfPlan_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        m_lblLP_17 = new QLabel(CommissionSetting);
        m_lblLP_17->setObjectName(QString::fromUtf8("m_lblLP_17"));
        sizePolicy.setHeightForWidth(m_lblLP_17->sizePolicy().hasHeightForWidth());
        m_lblLP_17->setSizePolicy(sizePolicy);
        m_lblLP_17->setMinimumSize(QSize(80, 30));
        m_lblLP_17->setFont(font1);
        m_lblLP_17->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);"));
        m_lblLP_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(m_lblLP_17);

        lineEdit_APIPort = new QLineEdit(CommissionSetting);
        lineEdit_APIPort->setObjectName(QString::fromUtf8("lineEdit_APIPort"));
        sizePolicy.setHeightForWidth(lineEdit_APIPort->sizePolicy().hasHeightForWidth());
        lineEdit_APIPort->setSizePolicy(sizePolicy);
        lineEdit_APIPort->setMinimumSize(QSize(85, 30));
        lineEdit_APIPort->setMaximumSize(QSize(85, 30));

        horizontalLayout_6->addWidget(lineEdit_APIPort);

        m_PshBtn_API_Set = new QPushButton(CommissionSetting);
        m_PshBtn_API_Set->setObjectName(QString::fromUtf8("m_PshBtn_API_Set"));
        sizePolicy.setHeightForWidth(m_PshBtn_API_Set->sizePolicy().hasHeightForWidth());
        m_PshBtn_API_Set->setSizePolicy(sizePolicy);
        m_PshBtn_API_Set->setMinimumSize(QSize(120, 30));
        m_PshBtn_API_Set->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        m_PshBtn_API_Set->setIcon(icon1);

        horizontalLayout_6->addWidget(m_PshBtn_API_Set);

        m_PshBtn_API_Check = new QPushButton(CommissionSetting);
        m_PshBtn_API_Check->setObjectName(QString::fromUtf8("m_PshBtn_API_Check"));
        sizePolicy.setHeightForWidth(m_PshBtn_API_Check->sizePolicy().hasHeightForWidth());
        m_PshBtn_API_Check->setSizePolicy(sizePolicy);
        m_PshBtn_API_Check->setMinimumSize(QSize(120, 30));
        m_PshBtn_API_Check->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        m_PshBtn_API_Check->setIcon(icon1);

        horizontalLayout_6->addWidget(m_PshBtn_API_Check);

        m_PshBtn_API_Reset = new QPushButton(CommissionSetting);
        m_PshBtn_API_Reset->setObjectName(QString::fromUtf8("m_PshBtn_API_Reset"));
        sizePolicy.setHeightForWidth(m_PshBtn_API_Reset->sizePolicy().hasHeightForWidth());
        m_PshBtn_API_Reset->setSizePolicy(sizePolicy);
        m_PshBtn_API_Reset->setMinimumSize(QSize(120, 30));
        m_PshBtn_API_Reset->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border: 2px solid red;\n"
"border-width : 2px;\n"
"border-color: rgb(204, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(204, 0, 0);\n"
"font: 10pt \"Open Sans\";\n"
"\n"
"}\n"
" QPushButton:hover \n"
"{\n"
"     background-color: rgb(204, 0, 0);\n"
"     color: rgb(255, 255, 255);\n"
" }\n"
"QPushButton:pressed\n"
"{\n"
"	border:1px solid red;\n"
"}\n"
"QToolTip\n"
"{\n"
"	background-color: rgb(255, 255, 127);\n"
"	color:rgb(0,0,0);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"background-color: rgb(220, 220, 220);\n"
"}"));
        m_PshBtn_API_Reset->setIcon(icon2);

        horizontalLayout_6->addWidget(m_PshBtn_API_Reset);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        m_FrameTypeOfPlan_7 = new QFrame(CommissionSetting);
        m_FrameTypeOfPlan_7->setObjectName(QString::fromUtf8("m_FrameTypeOfPlan_7"));
        sizePolicy1.setHeightForWidth(m_FrameTypeOfPlan_7->sizePolicy().hasHeightForWidth());
        m_FrameTypeOfPlan_7->setSizePolicy(sizePolicy1);
        m_FrameTypeOfPlan_7->setMaximumSize(QSize(16777215, 28));
        m_FrameTypeOfPlan_7->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: rgb(51, 51, 51);\n"
"}\n"
""));
        m_FrameTypeOfPlan_7->setFrameShape(QFrame::StyledPanel);
        m_FrameTypeOfPlan_7->setFrameShadow(QFrame::Raised);
        m_VBoxFrameTypeOfPlan_8 = new QVBoxLayout(m_FrameTypeOfPlan_7);
        m_VBoxFrameTypeOfPlan_8->setSpacing(5);
        m_VBoxFrameTypeOfPlan_8->setObjectName(QString::fromUtf8("m_VBoxFrameTypeOfPlan_8"));
        m_VBoxFrameTypeOfPlan_8->setContentsMargins(0, 0, 0, 0);
        m_HBoxTypeOfSearchPlan_9 = new QHBoxLayout();
        m_HBoxTypeOfSearchPlan_9->setSpacing(3);
        m_HBoxTypeOfSearchPlan_9->setObjectName(QString::fromUtf8("m_HBoxTypeOfSearchPlan_9"));
        m_HBoxTypeOfSearchPlan_9->setContentsMargins(9, 0, 0, 5);
        m_lblLP_16 = new QLabel(m_FrameTypeOfPlan_7);
        m_lblLP_16->setObjectName(QString::fromUtf8("m_lblLP_16"));
        m_lblLP_16->setFont(font);
        m_lblLP_16->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 12pt \"Open Sans\" bold;\n"
"}"));

        m_HBoxTypeOfSearchPlan_9->addWidget(m_lblLP_16);

        m_RightSprLP_9 = new QSpacerItem(76, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        m_HBoxTypeOfSearchPlan_9->addItem(m_RightSprLP_9);


        m_VBoxFrameTypeOfPlan_8->addLayout(m_HBoxTypeOfSearchPlan_9);


        verticalLayout_4->addWidget(m_FrameTypeOfPlan_7);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        retranslateUi(CommissionSetting);

        QMetaObject::connectSlotsByName(CommissionSetting);
    } // setupUi

    void retranslateUi(QWidget *CommissionSetting)
    {
        CommissionSetting->setWindowTitle(QCoreApplication::translate("CommissionSetting", "CommissionSetting", nullptr));
        toolButton->setText(QCoreApplication::translate("CommissionSetting", "...", nullptr));
        label->setText(QCoreApplication::translate("CommissionSetting", "KONECRANES", nullptr));
        label_6->setText(QCoreApplication::translate("CommissionSetting", "Connect New & Connected IPs :", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_connect->setToolTip(QCoreApplication::translate("CommissionSetting", "<html><head/><body><p>Connect IP</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_connect->setText(QCoreApplication::translate("CommissionSetting", "   Connect   ", nullptr));
        lbl_error_msg->setText(QCoreApplication::translate("CommissionSetting", "<Error message>", nullptr));
        lbl_Connection->setText(QString());
        label_4->setText(QCoreApplication::translate("CommissionSetting", "Sources:", nullptr));
        toolButton_Version->setText(QCoreApplication::translate("CommissionSetting", "About...", nullptr));
        m_lblLP_12->setText(QCoreApplication::translate("CommissionSetting", "1. Date and time zone in server.", nullptr));
        m_lblLP_6->setText(QCoreApplication::translate("CommissionSetting", "  Server UTC Time   ", nullptr));
        label_UTC_Time->setText(QString());
        label_2->setText(QCoreApplication::translate("CommissionSetting", "Change to", nullptr));
        TimeStamp_Date->setDisplayFormat(QCoreApplication::translate("CommissionSetting", "dd MMM yy ", nullptr));
        timeEdit_Time->setDisplayFormat(QCoreApplication::translate("CommissionSetting", "hh:mm:ss", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_UTC_Time->setToolTip(QCoreApplication::translate("CommissionSetting", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  Set Server UTC Time   </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_UTC_Time->setText(QCoreApplication::translate("CommissionSetting", "Set", nullptr));
        m_lblLP_7->setText(QCoreApplication::translate("CommissionSetting", "    Server Locale ", nullptr));
        label_Locale_time->setText(QString());
        label_3->setText(QCoreApplication::translate("CommissionSetting", "Change to", nullptr));
#if QT_CONFIG(tooltip)
        comboBox_Locale->setToolTip(QCoreApplication::translate("CommissionSetting", "<html><head/><body><p>List of Saved Plots</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        m_PshBtn_LocaleTime->setToolTip(QCoreApplication::translate("CommissionSetting", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Set Server Locale </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_LocaleTime->setText(QCoreApplication::translate("CommissionSetting", "Set", nullptr));
        m_lblLP_13->setText(QCoreApplication::translate("CommissionSetting", "2. PLC Port Settings.", nullptr));
        m_lblLP_8->setText(QCoreApplication::translate("CommissionSetting", " Data Port", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_PLCDataPortSave->setToolTip(QCoreApplication::translate("CommissionSetting", "<html><head/><body><p>Data port Set</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_PLCDataPortSave->setText(QCoreApplication::translate("CommissionSetting", "Data port Set", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_PLCDataPortArrival->setToolTip(QCoreApplication::translate("CommissionSetting", "<html><head/><body><p>Data Arrival</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_PLCDataPortArrival->setText(QCoreApplication::translate("CommissionSetting", "Data Arrival", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_DataPort_Reset->setToolTip(QCoreApplication::translate("CommissionSetting", "<html><head/><body><p>Reset Data Port </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_DataPort_Reset->setText(QCoreApplication::translate("CommissionSetting", "Reset to default", nullptr));
        m_lblLP_9->setText(QCoreApplication::translate("CommissionSetting", " Alarm Port  ", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_PLCAlarmPortSave->setToolTip(QCoreApplication::translate("CommissionSetting", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Alarm Port Set</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_PLCAlarmPortSave->setText(QCoreApplication::translate("CommissionSetting", "Alarm Port Set", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_PLCAlarmPortArrival->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        m_PshBtn_PLCAlarmPortArrival->setText(QCoreApplication::translate("CommissionSetting", "Alarm Arrival", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_AlarmPort_Reset->setToolTip(QCoreApplication::translate("CommissionSetting", "<html><head/><body><p>Reset Alarm Port</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_AlarmPort_Reset->setText(QCoreApplication::translate("CommissionSetting", "Reset to default", nullptr));
        m_lblLP_14->setText(QCoreApplication::translate("CommissionSetting", "3. Definition file Configuration", nullptr));
        m_lblLP_10->setText(QCoreApplication::translate("CommissionSetting", "AWL file for data and parameters", nullptr));
        label_AWLFile->setText(QString());
        toolButton_AWLFile->setText(QCoreApplication::translate("CommissionSetting", "Open file...", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_AWLFileUpload->setToolTip(QCoreApplication::translate("CommissionSetting", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">AWL file Upload</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_AWLFileUpload->setText(QCoreApplication::translate("CommissionSetting", "Upload", nullptr));
        m_lblLP_11->setText(QCoreApplication::translate("CommissionSetting", "Alarm configuration", nullptr));
        radioBtn_Alarm640->setText(QCoreApplication::translate("CommissionSetting", "640 Alarms", nullptr));
        radioBtn_Alarm1280->setText(QCoreApplication::translate("CommissionSetting", "1280 Alarms", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_Alarm->setToolTip(QCoreApplication::translate("CommissionSetting", "<html><head/><body><p>Set Alarm configuration</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_Alarm->setText(QCoreApplication::translate("CommissionSetting", "Set", nullptr));
        label_Alarm_message->setText(QString());
        m_lblLP_15->setText(QCoreApplication::translate("CommissionSetting", "4. Check API for Analyser ", nullptr));
        m_lblLP_17->setText(QCoreApplication::translate("CommissionSetting", " Port", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_API_Set->setToolTip(QCoreApplication::translate("CommissionSetting", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Set Analyser Port</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_API_Set->setText(QCoreApplication::translate("CommissionSetting", "Set", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_API_Check->setToolTip(QCoreApplication::translate("CommissionSetting", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Check</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_API_Check->setText(QCoreApplication::translate("CommissionSetting", "Check", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_API_Reset->setToolTip(QCoreApplication::translate("CommissionSetting", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Reset to default</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_API_Reset->setText(QCoreApplication::translate("CommissionSetting", "Reset to default", nullptr));
        m_lblLP_16->setText(QCoreApplication::translate("CommissionSetting", "5. Configuration of Retention Policy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommissionSetting: public Ui_CommissionSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMISSIONSETTING_H
