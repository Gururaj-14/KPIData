/********************************************************************************
** Form generated from reading UI file 'addkpis.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDKPIS_H
#define UI_ADDKPIS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ADDKPIS
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_16;
    QToolButton *toolButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_6;
    QComboBox *comboBox_ConnectedIPs;
    QPushButton *pushButton_connect;
    QLabel *lbl_error_msg;
    QLabel *lbl_Connection;
    QToolButton *toolButton_Versions;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *comboBox_param;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *m_PshBtn_Add;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *ADDKPIS)
    {
        if (ADDKPIS->objectName().isEmpty())
            ADDKPIS->setObjectName(QString::fromUtf8("ADDKPIS"));
        ADDKPIS->resize(874, 600);
        ADDKPIS->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	font: 11pt ;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(ADDKPIS);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(-1, 4, -1, 0);
        toolButton = new QToolButton(ADDKPIS);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/C_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(16, 16));

        horizontalLayout_16->addWidget(toolButton);

        label = new QLabel(ADDKPIS);
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

        label_6 = new QLabel(ADDKPIS);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_16->addWidget(label_6);

        comboBox_ConnectedIPs = new QComboBox(ADDKPIS);
        comboBox_ConnectedIPs->setObjectName(QString::fromUtf8("comboBox_ConnectedIPs"));
        comboBox_ConnectedIPs->setMinimumSize(QSize(170, 30));
        comboBox_ConnectedIPs->setEditable(true);

        horizontalLayout_16->addWidget(comboBox_ConnectedIPs);

        pushButton_connect = new QPushButton(ADDKPIS);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setMinimumSize(QSize(0, 30));
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

        lbl_error_msg = new QLabel(ADDKPIS);
        lbl_error_msg->setObjectName(QString::fromUtf8("lbl_error_msg"));

        horizontalLayout_16->addWidget(lbl_error_msg);

        lbl_Connection = new QLabel(ADDKPIS);
        lbl_Connection->setObjectName(QString::fromUtf8("lbl_Connection"));
        lbl_Connection->setMinimumSize(QSize(30, 30));
        lbl_Connection->setMaximumSize(QSize(30, 30));
        lbl_Connection->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        horizontalLayout_16->addWidget(lbl_Connection);

        toolButton_Versions = new QToolButton(ADDKPIS);
        toolButton_Versions->setObjectName(QString::fromUtf8("toolButton_Versions"));
        toolButton_Versions->setMinimumSize(QSize(0, 30));

        horizontalLayout_16->addWidget(toolButton_Versions);

        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

        verticalLayout_2->addLayout(horizontalLayout_6);

        tableWidget = new QTableWidget(ADDKPIS);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget->horizontalHeader()->setDefaultSectionSize(250);

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        frame = new QFrame(ADDKPIS);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";\n"
"color: rgb(85, 0, 255);"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_name = new QLineEdit(frame);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setMinimumSize(QSize(250, 30));
        lineEdit_name->setMaximumSize(QSize(250, 30));

        horizontalLayout_2->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        comboBox_param = new QComboBox(frame);
        comboBox_param->setObjectName(QString::fromUtf8("comboBox_param"));
        comboBox_param->setMinimumSize(QSize(250, 30));
        comboBox_param->setMaximumSize(QSize(250, 30));

        horizontalLayout_3->addWidget(comboBox_param);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        m_PshBtn_Add = new QPushButton(frame);
        m_PshBtn_Add->setObjectName(QString::fromUtf8("m_PshBtn_Add"));
        m_PshBtn_Add->setMinimumSize(QSize(120, 30));
        m_PshBtn_Add->setMaximumSize(QSize(100, 30));
        m_PshBtn_Add->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save-local.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_PshBtn_Add->setIcon(icon1);

        horizontalLayout_4->addWidget(m_PshBtn_Add);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addWidget(frame);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(ADDKPIS);

        QMetaObject::connectSlotsByName(ADDKPIS);
    } // setupUi

    void retranslateUi(QWidget *ADDKPIS)
    {
        ADDKPIS->setWindowTitle(QCoreApplication::translate("ADDKPIS", "ADDKPIS", nullptr));
        toolButton->setText(QCoreApplication::translate("ADDKPIS", "...", nullptr));
        label->setText(QCoreApplication::translate("ADDKPIS", "KONECRANES", nullptr));
        label_6->setText(QCoreApplication::translate("ADDKPIS", "Connect New & Connected IPs :", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("ADDKPIS", "   Connect   ", nullptr));
        lbl_error_msg->setText(QCoreApplication::translate("ADDKPIS", "<Error message>", nullptr));
        lbl_Connection->setText(QString());
        toolButton_Versions->setText(QCoreApplication::translate("ADDKPIS", "About...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ADDKPIS", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ADDKPIS", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ADDKPIS", "Parameter", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ADDKPIS", "Action", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ADDKPIS", "Action", nullptr));
        label_2->setText(QCoreApplication::translate("ADDKPIS", "Add KPIs", nullptr));
        label_3->setText(QCoreApplication::translate("ADDKPIS", "Name:", nullptr));
        label_4->setText(QCoreApplication::translate("ADDKPIS", "Choose Parameter:", nullptr));
#if QT_CONFIG(tooltip)
        m_PshBtn_Add->setToolTip(QCoreApplication::translate("ADDKPIS", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Open Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:600;\">Click to Go</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        m_PshBtn_Add->setText(QCoreApplication::translate("ADDKPIS", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ADDKPIS: public Ui_ADDKPIS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDKPIS_H
