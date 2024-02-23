/********************************************************************************
** Form generated from reading UI file 'appversions.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPVERSIONS_H
#define UI_APPVERSIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppVersions
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *About;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QWidget *Versions;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *m_csLnScoutparameters;
    QHBoxLayout *m_HLayoutDetectionDis_3;
    QLabel *m_csLnDetectionDistce_3;
    QLabel *pc_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor_3;
    QLabel *m_csLnSpacingFactor_3;
    QLabel *pc_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys_3;
    QLabel *m_csLnNoofsonobuys_3;
    QTextEdit *pc_Rnote;
    QLabel *m_csLnSensorParameters;
    QHBoxLayout *m_HLayoutDetectionDis;
    QLabel *m_csLnDetectionDistce;
    QLabel *adc_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor;
    QLabel *m_csLnSpacingFactor;
    QLabel *adc_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys;
    QLabel *m_csLnNoofsonobuys;
    QTextEdit *adc_Rnote;
    QLabel *m_csLnDatumParameters;
    QHBoxLayout *m_HLayoutDetectionDis_4;
    QLabel *m_csLnDetectionDistce_4;
    QLabel *s_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor_4;
    QLabel *m_csLnSpacingFactor_4;
    QLabel *s_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys_4;
    QLabel *m_csLnNoofsonobuys_4;
    QTextEdit *s_Rnote;
    QLabel *m_csLnDatumParameters_2;
    QHBoxLayout *m_HLayoutDetectionDis_5;
    QLabel *m_csLnDetectionDistce_5;
    QLabel *kpi_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor_5;
    QLabel *m_csLnSpacingFactor_5;
    QLabel *kpi_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys_5;
    QLabel *m_csLnNoofsonobuys_5;
    QTextEdit *kpi_Rnote;
    QLabel *m_csLnDatumParameters_3;
    QHBoxLayout *m_HLayoutDetectionDis_6;
    QLabel *m_csLnDetectionDistce_6;
    QLabel *kpicron_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor_6;
    QLabel *m_csLnSpacingFactor_6;
    QLabel *kpicron_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys_6;
    QLabel *m_csLnNoofsonobuys_6;
    QTextEdit *kpicron_Rnote;
    QLabel *m_csLnDatumParameters_4;
    QHBoxLayout *m_HLayoutDetectionDis_7;
    QLabel *m_csLnDetectionDistce_7;
    QLabel *cs_Vnum;
    QHBoxLayout *m_HLayoutSpacingFactor_7;
    QLabel *m_csLnSpacingFactor_7;
    QLabel *cs_Date;
    QHBoxLayout *m_HLayoutNoofsonobuys_7;
    QLabel *m_csLnNoofsonobuys_7;
    QTextEdit *cs_Rnote;

    void setupUi(QWidget *AppVersions)
    {
        if (AppVersions->objectName().isEmpty())
            AppVersions->setObjectName(QString::fromUtf8("AppVersions"));
        AppVersions->resize(450, 644);
        verticalLayout_3 = new QVBoxLayout(AppVersions);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(AppVersions);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(415, 0));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 11pt ;"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        About = new QWidget();
        About->setObjectName(QString::fromUtf8("About"));
        verticalLayout = new QVBoxLayout(About);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(About);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        tabWidget->addTab(About, QString());
        Versions = new QWidget();
        Versions->setObjectName(QString::fromUtf8("Versions"));
        Versions->setStyleSheet(QString::fromUtf8("font: 11pt ;"));
        verticalLayout_4 = new QVBoxLayout(Versions);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        scrollArea = new QScrollArea(Versions);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(415, 0));
        scrollArea->setMaximumSize(QSize(400, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8("/*QScrollArea{\n"
"background:transparent;\n"
"border:none;\n"
"}\n"
"*/"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 1018));
        scrollAreaWidgetContents->setMinimumSize(QSize(380, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(380, 16777215));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 0, 0, 9);
        m_csLnScoutparameters = new QLabel(scrollAreaWidgetContents);
        m_csLnScoutparameters->setObjectName(QString::fromUtf8("m_csLnScoutparameters"));
        m_csLnScoutparameters->setMinimumSize(QSize(150, 24));
        m_csLnScoutparameters->setMaximumSize(QSize(150, 24));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        m_csLnScoutparameters->setFont(font);
        m_csLnScoutparameters->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnScoutparameters->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnScoutparameters);

        m_HLayoutDetectionDis_3 = new QHBoxLayout();
        m_HLayoutDetectionDis_3->setSpacing(20);
        m_HLayoutDetectionDis_3->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_3"));
        m_csLnDetectionDistce_3 = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce_3->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_3"));
        m_csLnDetectionDistce_3->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce_3->setFont(font);
        m_csLnDetectionDistce_3->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_3->addWidget(m_csLnDetectionDistce_3);

        pc_Vnum = new QLabel(scrollAreaWidgetContents);
        pc_Vnum->setObjectName(QString::fromUtf8("pc_Vnum"));
        pc_Vnum->setMinimumSize(QSize(200, 24));
        pc_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_3->addWidget(pc_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis_3);

        m_HLayoutSpacingFactor_3 = new QHBoxLayout();
        m_HLayoutSpacingFactor_3->setSpacing(20);
        m_HLayoutSpacingFactor_3->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor_3"));
        m_csLnSpacingFactor_3 = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor_3->setObjectName(QString::fromUtf8("m_csLnSpacingFactor_3"));
        m_csLnSpacingFactor_3->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor_3->setFont(font);
        m_csLnSpacingFactor_3->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor_3->addWidget(m_csLnSpacingFactor_3);

        pc_Date = new QLabel(scrollAreaWidgetContents);
        pc_Date->setObjectName(QString::fromUtf8("pc_Date"));
        pc_Date->setMinimumSize(QSize(200, 24));
        pc_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor_3->addWidget(pc_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor_3);

        m_HLayoutNoofsonobuys_3 = new QHBoxLayout();
        m_HLayoutNoofsonobuys_3->setSpacing(20);
        m_HLayoutNoofsonobuys_3->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys_3"));
        m_csLnNoofsonobuys_3 = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys_3->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys_3"));
        m_csLnNoofsonobuys_3->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys_3->setFont(font);
        m_csLnNoofsonobuys_3->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys_3->addWidget(m_csLnNoofsonobuys_3);

        pc_Rnote = new QTextEdit(scrollAreaWidgetContents);
        pc_Rnote->setObjectName(QString::fromUtf8("pc_Rnote"));
        pc_Rnote->setMinimumSize(QSize(200, 71));
        pc_Rnote->setMaximumSize(QSize(200, 71));
        pc_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pc_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys_3->addWidget(pc_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys_3);

        m_csLnSensorParameters = new QLabel(scrollAreaWidgetContents);
        m_csLnSensorParameters->setObjectName(QString::fromUtf8("m_csLnSensorParameters"));
        m_csLnSensorParameters->setMinimumSize(QSize(170, 24));
        m_csLnSensorParameters->setMaximumSize(QSize(170, 24));
        m_csLnSensorParameters->setFont(font);
        m_csLnSensorParameters->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnSensorParameters->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnSensorParameters);

        m_HLayoutDetectionDis = new QHBoxLayout();
        m_HLayoutDetectionDis->setSpacing(20);
        m_HLayoutDetectionDis->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis"));
        m_csLnDetectionDistce = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce->setObjectName(QString::fromUtf8("m_csLnDetectionDistce"));
        m_csLnDetectionDistce->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce->setFont(font);
        m_csLnDetectionDistce->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis->addWidget(m_csLnDetectionDistce);

        adc_Vnum = new QLabel(scrollAreaWidgetContents);
        adc_Vnum->setObjectName(QString::fromUtf8("adc_Vnum"));
        adc_Vnum->setMinimumSize(QSize(200, 24));
        adc_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis->addWidget(adc_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis);

        m_HLayoutSpacingFactor = new QHBoxLayout();
        m_HLayoutSpacingFactor->setSpacing(20);
        m_HLayoutSpacingFactor->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor"));
        m_csLnSpacingFactor = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor->setObjectName(QString::fromUtf8("m_csLnSpacingFactor"));
        m_csLnSpacingFactor->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor->setFont(font);
        m_csLnSpacingFactor->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor->addWidget(m_csLnSpacingFactor);

        adc_Date = new QLabel(scrollAreaWidgetContents);
        adc_Date->setObjectName(QString::fromUtf8("adc_Date"));
        adc_Date->setMinimumSize(QSize(200, 24));
        adc_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor->addWidget(adc_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor);

        m_HLayoutNoofsonobuys = new QHBoxLayout();
        m_HLayoutNoofsonobuys->setSpacing(20);
        m_HLayoutNoofsonobuys->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys"));
        m_csLnNoofsonobuys = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys"));
        m_csLnNoofsonobuys->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys->setFont(font);
        m_csLnNoofsonobuys->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys->addWidget(m_csLnNoofsonobuys);

        adc_Rnote = new QTextEdit(scrollAreaWidgetContents);
        adc_Rnote->setObjectName(QString::fromUtf8("adc_Rnote"));
        adc_Rnote->setMinimumSize(QSize(200, 71));
        adc_Rnote->setMaximumSize(QSize(200, 71));
        adc_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        adc_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys->addWidget(adc_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys);

        m_csLnDatumParameters = new QLabel(scrollAreaWidgetContents);
        m_csLnDatumParameters->setObjectName(QString::fromUtf8("m_csLnDatumParameters"));
        m_csLnDatumParameters->setMinimumSize(QSize(150, 24));
        m_csLnDatumParameters->setMaximumSize(QSize(150, 24));
        m_csLnDatumParameters->setFont(font);
        m_csLnDatumParameters->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnDatumParameters->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnDatumParameters);

        m_HLayoutDetectionDis_4 = new QHBoxLayout();
        m_HLayoutDetectionDis_4->setSpacing(20);
        m_HLayoutDetectionDis_4->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_4"));
        m_csLnDetectionDistce_4 = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce_4->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_4"));
        m_csLnDetectionDistce_4->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce_4->setFont(font);
        m_csLnDetectionDistce_4->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_4->addWidget(m_csLnDetectionDistce_4);

        s_Vnum = new QLabel(scrollAreaWidgetContents);
        s_Vnum->setObjectName(QString::fromUtf8("s_Vnum"));
        s_Vnum->setMinimumSize(QSize(200, 24));
        s_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_4->addWidget(s_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis_4);

        m_HLayoutSpacingFactor_4 = new QHBoxLayout();
        m_HLayoutSpacingFactor_4->setSpacing(20);
        m_HLayoutSpacingFactor_4->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor_4"));
        m_csLnSpacingFactor_4 = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor_4->setObjectName(QString::fromUtf8("m_csLnSpacingFactor_4"));
        m_csLnSpacingFactor_4->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor_4->setFont(font);
        m_csLnSpacingFactor_4->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor_4->addWidget(m_csLnSpacingFactor_4);

        s_Date = new QLabel(scrollAreaWidgetContents);
        s_Date->setObjectName(QString::fromUtf8("s_Date"));
        s_Date->setMinimumSize(QSize(200, 24));
        s_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor_4->addWidget(s_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor_4);

        m_HLayoutNoofsonobuys_4 = new QHBoxLayout();
        m_HLayoutNoofsonobuys_4->setSpacing(20);
        m_HLayoutNoofsonobuys_4->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys_4"));
        m_csLnNoofsonobuys_4 = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys_4->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys_4"));
        m_csLnNoofsonobuys_4->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys_4->setFont(font);
        m_csLnNoofsonobuys_4->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys_4->addWidget(m_csLnNoofsonobuys_4);

        s_Rnote = new QTextEdit(scrollAreaWidgetContents);
        s_Rnote->setObjectName(QString::fromUtf8("s_Rnote"));
        s_Rnote->setMinimumSize(QSize(200, 71));
        s_Rnote->setMaximumSize(QSize(200, 71));
        s_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        s_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys_4->addWidget(s_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys_4);

        m_csLnDatumParameters_2 = new QLabel(scrollAreaWidgetContents);
        m_csLnDatumParameters_2->setObjectName(QString::fromUtf8("m_csLnDatumParameters_2"));
        m_csLnDatumParameters_2->setMinimumSize(QSize(150, 24));
        m_csLnDatumParameters_2->setMaximumSize(QSize(150, 24));
        m_csLnDatumParameters_2->setFont(font);
        m_csLnDatumParameters_2->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnDatumParameters_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnDatumParameters_2);

        m_HLayoutDetectionDis_5 = new QHBoxLayout();
        m_HLayoutDetectionDis_5->setSpacing(20);
        m_HLayoutDetectionDis_5->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_5"));
        m_csLnDetectionDistce_5 = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce_5->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_5"));
        m_csLnDetectionDistce_5->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce_5->setFont(font);
        m_csLnDetectionDistce_5->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_5->addWidget(m_csLnDetectionDistce_5);

        kpi_Vnum = new QLabel(scrollAreaWidgetContents);
        kpi_Vnum->setObjectName(QString::fromUtf8("kpi_Vnum"));
        kpi_Vnum->setMinimumSize(QSize(200, 24));
        kpi_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_5->addWidget(kpi_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis_5);

        m_HLayoutSpacingFactor_5 = new QHBoxLayout();
        m_HLayoutSpacingFactor_5->setSpacing(20);
        m_HLayoutSpacingFactor_5->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor_5"));
        m_csLnSpacingFactor_5 = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor_5->setObjectName(QString::fromUtf8("m_csLnSpacingFactor_5"));
        m_csLnSpacingFactor_5->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor_5->setFont(font);
        m_csLnSpacingFactor_5->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor_5->addWidget(m_csLnSpacingFactor_5);

        kpi_Date = new QLabel(scrollAreaWidgetContents);
        kpi_Date->setObjectName(QString::fromUtf8("kpi_Date"));
        kpi_Date->setMinimumSize(QSize(200, 24));
        kpi_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor_5->addWidget(kpi_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor_5);

        m_HLayoutNoofsonobuys_5 = new QHBoxLayout();
        m_HLayoutNoofsonobuys_5->setSpacing(20);
        m_HLayoutNoofsonobuys_5->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys_5"));
        m_csLnNoofsonobuys_5 = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys_5->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys_5"));
        m_csLnNoofsonobuys_5->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys_5->setFont(font);
        m_csLnNoofsonobuys_5->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys_5->addWidget(m_csLnNoofsonobuys_5);

        kpi_Rnote = new QTextEdit(scrollAreaWidgetContents);
        kpi_Rnote->setObjectName(QString::fromUtf8("kpi_Rnote"));
        kpi_Rnote->setMinimumSize(QSize(200, 71));
        kpi_Rnote->setMaximumSize(QSize(200, 71));
        kpi_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        kpi_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys_5->addWidget(kpi_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys_5);

        m_csLnDatumParameters_3 = new QLabel(scrollAreaWidgetContents);
        m_csLnDatumParameters_3->setObjectName(QString::fromUtf8("m_csLnDatumParameters_3"));
        m_csLnDatumParameters_3->setMinimumSize(QSize(150, 24));
        m_csLnDatumParameters_3->setMaximumSize(QSize(200, 24));
        m_csLnDatumParameters_3->setFont(font);
        m_csLnDatumParameters_3->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnDatumParameters_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnDatumParameters_3);

        m_HLayoutDetectionDis_6 = new QHBoxLayout();
        m_HLayoutDetectionDis_6->setSpacing(20);
        m_HLayoutDetectionDis_6->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_6"));
        m_csLnDetectionDistce_6 = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce_6->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_6"));
        m_csLnDetectionDistce_6->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce_6->setFont(font);
        m_csLnDetectionDistce_6->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_6->addWidget(m_csLnDetectionDistce_6);

        kpicron_Vnum = new QLabel(scrollAreaWidgetContents);
        kpicron_Vnum->setObjectName(QString::fromUtf8("kpicron_Vnum"));
        kpicron_Vnum->setMinimumSize(QSize(200, 24));
        kpicron_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_6->addWidget(kpicron_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis_6);

        m_HLayoutSpacingFactor_6 = new QHBoxLayout();
        m_HLayoutSpacingFactor_6->setSpacing(20);
        m_HLayoutSpacingFactor_6->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor_6"));
        m_csLnSpacingFactor_6 = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor_6->setObjectName(QString::fromUtf8("m_csLnSpacingFactor_6"));
        m_csLnSpacingFactor_6->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor_6->setFont(font);
        m_csLnSpacingFactor_6->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor_6->addWidget(m_csLnSpacingFactor_6);

        kpicron_Date = new QLabel(scrollAreaWidgetContents);
        kpicron_Date->setObjectName(QString::fromUtf8("kpicron_Date"));
        kpicron_Date->setMinimumSize(QSize(200, 24));
        kpicron_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor_6->addWidget(kpicron_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor_6);

        m_HLayoutNoofsonobuys_6 = new QHBoxLayout();
        m_HLayoutNoofsonobuys_6->setSpacing(20);
        m_HLayoutNoofsonobuys_6->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys_6"));
        m_csLnNoofsonobuys_6 = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys_6->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys_6"));
        m_csLnNoofsonobuys_6->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys_6->setFont(font);
        m_csLnNoofsonobuys_6->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys_6->addWidget(m_csLnNoofsonobuys_6);

        kpicron_Rnote = new QTextEdit(scrollAreaWidgetContents);
        kpicron_Rnote->setObjectName(QString::fromUtf8("kpicron_Rnote"));
        kpicron_Rnote->setMinimumSize(QSize(200, 71));
        kpicron_Rnote->setMaximumSize(QSize(200, 71));
        kpicron_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        kpicron_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys_6->addWidget(kpicron_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys_6);

        m_csLnDatumParameters_4 = new QLabel(scrollAreaWidgetContents);
        m_csLnDatumParameters_4->setObjectName(QString::fromUtf8("m_csLnDatumParameters_4"));
        m_csLnDatumParameters_4->setMinimumSize(QSize(150, 24));
        m_csLnDatumParameters_4->setMaximumSize(QSize(195, 24));
        m_csLnDatumParameters_4->setFont(font);
        m_csLnDatumParameters_4->setStyleSheet(QString::fromUtf8("/*\n"
"color: rgb(93, 226, 255);*/\n"
"\n"
""));
        m_csLnDatumParameters_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(m_csLnDatumParameters_4);

        m_HLayoutDetectionDis_7 = new QHBoxLayout();
        m_HLayoutDetectionDis_7->setSpacing(20);
        m_HLayoutDetectionDis_7->setObjectName(QString::fromUtf8("m_HLayoutDetectionDis_7"));
        m_csLnDetectionDistce_7 = new QLabel(scrollAreaWidgetContents);
        m_csLnDetectionDistce_7->setObjectName(QString::fromUtf8("m_csLnDetectionDistce_7"));
        m_csLnDetectionDistce_7->setMinimumSize(QSize(140, 24));
        m_csLnDetectionDistce_7->setFont(font);
        m_csLnDetectionDistce_7->setStyleSheet(QString::fromUtf8(""));
        m_csLnDetectionDistce_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutDetectionDis_7->addWidget(m_csLnDetectionDistce_7);

        cs_Vnum = new QLabel(scrollAreaWidgetContents);
        cs_Vnum->setObjectName(QString::fromUtf8("cs_Vnum"));
        cs_Vnum->setMinimumSize(QSize(200, 24));
        cs_Vnum->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutDetectionDis_7->addWidget(cs_Vnum);


        verticalLayout_2->addLayout(m_HLayoutDetectionDis_7);

        m_HLayoutSpacingFactor_7 = new QHBoxLayout();
        m_HLayoutSpacingFactor_7->setSpacing(20);
        m_HLayoutSpacingFactor_7->setObjectName(QString::fromUtf8("m_HLayoutSpacingFactor_7"));
        m_csLnSpacingFactor_7 = new QLabel(scrollAreaWidgetContents);
        m_csLnSpacingFactor_7->setObjectName(QString::fromUtf8("m_csLnSpacingFactor_7"));
        m_csLnSpacingFactor_7->setMinimumSize(QSize(140, 24));
        m_csLnSpacingFactor_7->setFont(font);
        m_csLnSpacingFactor_7->setStyleSheet(QString::fromUtf8(""));
        m_csLnSpacingFactor_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutSpacingFactor_7->addWidget(m_csLnSpacingFactor_7);

        cs_Date = new QLabel(scrollAreaWidgetContents);
        cs_Date->setObjectName(QString::fromUtf8("cs_Date"));
        cs_Date->setMinimumSize(QSize(200, 24));
        cs_Date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        m_HLayoutSpacingFactor_7->addWidget(cs_Date);


        verticalLayout_2->addLayout(m_HLayoutSpacingFactor_7);

        m_HLayoutNoofsonobuys_7 = new QHBoxLayout();
        m_HLayoutNoofsonobuys_7->setSpacing(20);
        m_HLayoutNoofsonobuys_7->setObjectName(QString::fromUtf8("m_HLayoutNoofsonobuys_7"));
        m_csLnNoofsonobuys_7 = new QLabel(scrollAreaWidgetContents);
        m_csLnNoofsonobuys_7->setObjectName(QString::fromUtf8("m_csLnNoofsonobuys_7"));
        m_csLnNoofsonobuys_7->setMinimumSize(QSize(140, 24));
        m_csLnNoofsonobuys_7->setFont(font);
        m_csLnNoofsonobuys_7->setStyleSheet(QString::fromUtf8(""));
        m_csLnNoofsonobuys_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        m_HLayoutNoofsonobuys_7->addWidget(m_csLnNoofsonobuys_7);

        cs_Rnote = new QTextEdit(scrollAreaWidgetContents);
        cs_Rnote->setObjectName(QString::fromUtf8("cs_Rnote"));
        cs_Rnote->setMinimumSize(QSize(200, 71));
        cs_Rnote->setMaximumSize(QSize(200, 71));
        cs_Rnote->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        cs_Rnote->setReadOnly(true);

        m_HLayoutNoofsonobuys_7->addWidget(cs_Rnote);


        verticalLayout_2->addLayout(m_HLayoutNoofsonobuys_7);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        tabWidget->addTab(Versions, QString());

        verticalLayout_3->addWidget(tabWidget);


        retranslateUi(AppVersions);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AppVersions);
    } // setupUi

    void retranslateUi(QWidget *AppVersions)
    {
        AppVersions->setWindowTitle(QCoreApplication::translate("AppVersions", "Form", nullptr));
        textEdit->setHtml(QCoreApplication::translate("AppVersions", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Jsoncpp:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">The JsonCpp library's source code, including accompanying documentation,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right"
                        ":0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">tests and demonstration applications, are licensed under the following</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">conditions...</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Baptiste Lepilleur and The JsonCpp Authors explicitly disclaim copyright in all</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">jurisdictions which recognize such a disclaimer. In such jurisdictio"
                        "ns,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">this software is released into the Public Domain.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">In jurisdictions which do not recognize Public Domain property (e.g. Germany as of</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">2010), this software is Copyright (c) 2007-2010 by Baptiste Lepilleur and</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block"
                        "-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">The JsonCpp Authors, and is released under the terms of the MIT License (see below).</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">In jurisdictions which recognize Public Domain property, the user of this</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">software may choose to accept it either as 1) Public Domain, 2) under the</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">conditions of t"
                        "he MIT License (see below), or 3) under the terms of dual</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Public Domain/MIT License conditions described here, as they choose.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">The MIT License is about as close to Public Domain as a license can get, and is</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">described in clear, concise terms at:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; marg"
                        "in-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">   http://en.wikipedia.org/wiki/MIT_License</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">The full text of the MIT License follows:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inden"
                        "t:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">========================================================================</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Copyright (c) 2007-2010 Baptiste Lepilleur and The JsonCpp Authors</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the &quot;Software&quot;), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribut"
                        "e, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">furnished to do so, subject to the following conditions:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" m"
                        "argin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">========================================================="
                        "===============</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">(END LICENSE TEXT)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">The MIT license is compatible with both the GPL and commercial software, affording one all of the rights of Public Domain with the minor nuisance of being required to keep the above copyright notice and license text in the source code. Note also that by accepting the Public Domain &quot;license&quot; you can re-license your copy using whatever</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inde"
                        "nt:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">license you like.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">libpqxx:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">The source code for libpqxx is available under the BSD license, so you're free to download it, pass it on to others, change it, sell it, include it in your own code, and share your changes with anyone you choose. No ch"
                        "arge, no catch. Also, no guarantees. :-)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">postgres-apache:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">          Apache License</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">          Version 2.0, January 2004</span></p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">          http://www.apache.org/licenses/</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">1. Definitions.</span></p>\n"
"<p style=\"-qt-"
                        "paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">&quot;License&quot; shall mean the terms and conditions     </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">for use, reproduction, and distribution as defined by Sections 1 through 9 of this document.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">&quot;Lice"
                        "nsor&quot; shall mean the copyright owner or    entity authorized by the copyright owner that is granting the License.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">&quot;Legal Entity&quot; shall mean the union of the acting entity and all other entities that control, are controlled by, or are under common control with that entity. For the purposes of  this definition,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\"> &quot;control&quot; means (i) the power, direct or indirect, to cause the direction or management of such entity, whether by contract or otherwise, or (ii) ownership"
                        " of fifty percent (50%) or more of the</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\"> outstanding shares, or (iii) beneficial ownership of such entity.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\"> &quot;You&quot; (or &quot;Your&quot;) shall mean an individual or Legal Entity exercising permissions granted by this License.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0"
                        "px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">&quot;Source&quot; form shall mean the preferred form for making modifications, including but not limited to software source code, documentation source, and configuration files.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">&quot;Object&quot; form shall mean any form resulting from mechanical transformation or translation of a Source form, including but not limited to compiled object code, generated documentation,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">and conversions to o"
                        "ther media types.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">&quot;Work&quot; shall mean the work of authorship, whether in Source or Object form, made available under the License, as indicated by a copyright notice that is included in or attached to the work</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">(an example is provided in the Appendix below).</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; m"
                        "argin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">&quot;Derivative Works&quot; shall mean any work, whether in Source or Object form, that is based on (or derived from) the Work and for which the editorial revisions, annotations, elaborations, or other modifications represent, as a whole, an original work of authorship. For the purposes of this License, Derivative Works shall not include works that remain separable from, or merely link (or bind by name) to the interfaces of, the Work and Derivative Works thereof.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">&quot;Contribution&quot; shall mean any work of authorship, includi"
                        "ng the original version of the Work and any modifications or additions to that Work or Derivative Works thereof, that is intentionally submitted to Licensor for inclusion in the Work by the copyright owner or by an individual or Legal Entity authorized to submit on behalf of the copyright owner. For the purposes of this definition, &quot;submitted&quot; means any form of electronic, verbal, or written communication sent</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">to the Licensor or its representatives, including but not limited to communication on electronic mailing lists, source code control systems,and issue tracking systems that are managed by, or on behalf of, the Licensor for the purpose of discussing and improving the Work, but excluding communication that is conspicuously marked or otherwise designated in writing by the copyright owner as &quot;Not a Contribution.&quot;</spa"
                        "n></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">&quot;Contributor&quot; shall mean Licensor and any individual or Legal Entityon behalf of whom a Contribution has been received by Licensor and</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">subsequently incorporated within the Work.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-ind"
                        "ent:0px;\"><span style=\" font-family:'Ubuntu';\">2. Grant of Copyright License. Subject to the terms and conditions of this License, each Contributor hereby grants to You a perpetual, worldwide, non-exclusive, no-charge, royalty-free, irrevocable copyright license to reproduce, prepare Derivative Works of, publicly display, publicly perform, sublicense, and distribute the Work and such Derivative Works in Source or Object form.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">3. Grant of Patent License. Subject to the terms and conditions of this License, each Contributor hereby grants to You a perpetual, worldwide, non-exclusive, no-charge, royalty-free, irrevocable</span></p>\n"
"<p style=\" margin-top:0"
                        "px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">(except as stated in this section) patent license to make, have made, use, offer to sell, sell, import, and otherwise transfer the Work, where such license applies only to those patent claims licensable by such Contributor that are necessarily infringed by their Contribution(s) alone or by combination of their Contribution(s)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\"> with the Work to which such Contribution(s) was submitted. If You institute patent litigation against any entity (including a cross-claim or counterclaim in a lawsuit) alleging that the Work or a Contribution incorporated within the Work constitutes direct or contributory patent infringement, then any patent licenses granted to You under this License for that Work shall terminate as"
                        " of the date such litigation is filed.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">4. Redistribution. You may reproduce and distribute copies of the Work or Derivative Works thereof in any medium, with or without modifications, and in Source or Object form, provided that You meet the following conditions:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\"> (a) You must give any other recipients of the"
                        " Work or Derivative Works a copy of this License; and</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">(b) You must cause any modified files to carry prominent notices stating that You changed the files; and</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">(c) You must retain, in the Source form of any Derivative Works that You distribute, all copyright, patent, trademark, and attribution notices from th"
                        "e Source form of the Work, excluding those notices that do not pertain to any part of the Derivative Works; and</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">(d) If the Work includes a &quot;NOTICE&quot; text file as part of its distribution, then any Derivative Works that You distribute must include a readable copy of the attribution notices contained within such NOTICE file, excluding those notices that do not</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">pertain to any part of the Derivative Works, in at least one of the following places: within a NOTICE text file distribute"
                        "d as part of the Derivative Works; within the Source form or documentation, if provided along with the Derivative Works; or,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">within a display generated by the Derivative Works, if and wherever such third-party notices normally appear. The contents of the NOTICE file are for informational purposes only and do not modify the License. You may add Your own attribution notices within Derivative Works that You distribute, alongside or as an addendum to the NOTICE text from the Work, provided that such additional attribution notices cannot be construed as modifying the License.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-rig"
                        "ht:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">You may add Your own copyright statement to Your modifications and may provide additional or different license terms and conditions for use, reproduction, or distribution of You modifications, or for any such Derivative Works as a whole, provided Your use, reproduction, and distribution of the Work otherwise complies with</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">the conditions stated in this License.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">5. Submission of Contributions. Unless You "
                        "explicitly state otherwise, any Contribution intentionally submitted for inclusion in the Work by You to the Licensor shall be under the terms and conditions of this License, without any additional terms or conditions.Notwithstanding the above, nothing herein shall supersede or modify the terms of any separate license agreement you may have executed with Licensor regarding such Contributions.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">6. Trademarks. This License does not grant permission to use the trade names, trademarks, service marks, or product names of the Licensor,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px"
                        ";\"><span style=\" font-family:'Ubuntu';\">except as required for reasonable and customary use in describing the origin of the Work and reproducing the content of the NOTICE file.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">7. Disclaimer of Warranty. Unless required by applicable law or agreed to in writing, Licensor provides the Work (and each Contributor provides its Contributions) on an &quot;AS IS&quot; BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied, including, without limitation, any warranties or conditions of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A PARTICULAR PURPOSE. You are solely responsible for determining the appropriateness of using or red"
                        "istributing the Work and assume any risks associated with Your exercise of permissions under this License.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">8. Limitation of Liability. In no event and under no legal theory, whether in tort (including negligence), contract, or otherwise,unless required by applicable law (such as deliberate and grossly negligent acts) or agreed to in writing, shall any Contributor be liable to You for damages, including any direct, indirect, special,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">incidental, or consequential damages of any character a"
                        "rising as a result of this License or out of the use or inability to use the Work (including but not limited to damages for loss of goodwill, work stoppage, computer failure or malfunction, or any and all other commercial damages or losses), even if such Contributor has been advised of the possibility of such damages.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">9. Accepting Warranty or Additional Liability. While redistributing the Work or Derivative Works thereof, You may choose to offer, and charge a fee for, acceptance of support, warranty, indemnity, or other liability obligations and/or rights consistent with this License. However, in accepting such obligations, You may act only on Your own behalf"
                        " and on Your sole responsibility, not on behalf of any other Contributor, and only if You agree to indemnify,defend, and hold each Contributor harmless for any liability incurred by, or claims asserted against, such Contributor by reason of your accepting any such warranty or additional liability.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">END OF TERMS AND CONDITIONS</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-f"
                        "amily:'Ubuntu';\">postgresql:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">PostgreSQL is released under the PostgreSQL License, a liberal Open Source license, similar to the BSD or MIT licenses.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">PostgreSQL Database Management System</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text"
                        "-indent:0px;\"><span style=\" font-family:'Ubuntu';\">(formerly known as Postgres, then as Postgres95)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Portions Copyright \302\251 1996-2021, The PostgreSQL Global Development Group</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Portions Copyright \302\251 1994, The Regents of the University of California</span></p>\n"
"<p style=\"-qt-paragraph-type:empt"
                        "y; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Permission to use, copy, modify, and distribute this software and its documentation for any purpose, without fee, and without a written agreement is hereby granted, provided that the above copyright notice and this paragraph and the following two paragraphs appear in all copies.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR DIRE"
                        "CT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS ON AN &quot;AS IS&quot; BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-"
                        "top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Will PostgreSQL ever be released under a different license?</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">The PostgreSQL Global Development Group remains committed to making PostgreSQL available as free and open source software in perpetuity. There are no plans to change the PostgreSQL License or release PostgreSQL under a different license.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-l"
                        "eft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">If you would like to read more about this topic, then please take a look at the mailing list archives at one of the many discussions on this subject.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">QTLicense:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-t"
                        "op:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Qt is available under different licensing options designed to accommodate the needs of our various users:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Qt licensed under commercial licenses is appropriate for development of proprietary/commercial software where you do not want to share any source code with third parties or otherwise cannot comply with the terms of the GNU LGPL version 3.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Qt lice"
                        "nsed under the GNU Lesser General Public License (LGPL) version 3 is appropriate for the development of Qt applications provided you can comply with the terms and conditions of the GNU LGPL version 3 (or GNU GPL version 3).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Qt components licensed under the Qt Marketplace License Agreement are appropriate for the development of Qt applications commonly with Qt software components licensed under the commercial or GNU LGPL version 3 (or GNU GPL version 3) terms and conditions.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Qt contains also third-party code that is licensed under specific open-source licenses from the original authors.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:"
                        "0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Note: For open-source licensed Qt, some specific parts (modules) are not available under the GNU LGPL version 3, but under the GNU General Public License (GPL) instead. See the list of Qt modules for details. For commercial licensees, all modules are available under a single, commercial Qt license.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Qt documentation is available under commercial licenses from The Qt Company, and under the "
                        "terms of the GNU Free Documentation License (FDL) version 1.3, as published by the Free Software Foundation.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Qt examples are available under commercial licenses from The Qt Company, and under a BSD-3-clause license.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">See http://qt.io/licensing/ for an overview of Qt licensing.</span></p>\n"
"<p style=\"-qt-pa"
                        "ragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Timescale:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Source code in this repository is variously licensed under the Apache License</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Version 2.0, an Apache compatible license, or the Timescale License.</span></"
                        "p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">All source code should have information at the beginning of its respective file</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">which specifies its licensing information.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">* Outside of the &q"
                        "uot;tsl&quot; directory, source code in a      </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">   given file is licensed under the Apache License  </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">   Version 2.0, unless otherwise noted (e.g., an</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">   Apache-compatible license).</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                        "<span style=\" font-family:'Ubuntu';\">* Within the &quot;tsl&quot; folder, source code in a given </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">    file is licensed under the</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">   Timescale License, unless otherwise noted.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">When built, separate shared object files are generated for the Apache-licensed</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px;"
                        " margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">source code and the Timescale-licensed source code. The shared object binaries</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">that contain `-tsl` in their name are licensed under the Timescale License.</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(About), QCoreApplication::translate("AppVersions", "About App", nullptr));
        m_csLnScoutparameters->setText(QCoreApplication::translate("AppVersions", "<html><head/><body><p>plcdatacollector</p></body></html>", nullptr));
        m_csLnDetectionDistce_3->setText(QCoreApplication::translate("AppVersions", "Version Number", nullptr));
        pc_Vnum->setText(QString());
        m_csLnSpacingFactor_3->setText(QCoreApplication::translate("AppVersions", "Date", nullptr));
        pc_Date->setText(QString());
        m_csLnNoofsonobuys_3->setText(QCoreApplication::translate("AppVersions", "Release Note", nullptr));
        m_csLnSensorParameters->setText(QCoreApplication::translate("AppVersions", "<html><head/><body><p>alarmdatacollector</p></body></html>", nullptr));
        m_csLnDetectionDistce->setText(QCoreApplication::translate("AppVersions", "Version Number", nullptr));
        adc_Vnum->setText(QString());
        m_csLnSpacingFactor->setText(QCoreApplication::translate("AppVersions", "Date", nullptr));
        adc_Date->setText(QString());
        m_csLnNoofsonobuys->setText(QCoreApplication::translate("AppVersions", "Release Note", nullptr));
        m_csLnDatumParameters->setText(QCoreApplication::translate("AppVersions", "<html><head/><body><p>server</p></body></html>", nullptr));
        m_csLnDetectionDistce_4->setText(QCoreApplication::translate("AppVersions", "Version Number", nullptr));
        s_Vnum->setText(QString());
        m_csLnSpacingFactor_4->setText(QCoreApplication::translate("AppVersions", "Date", nullptr));
        s_Date->setText(QString());
        m_csLnNoofsonobuys_4->setText(QCoreApplication::translate("AppVersions", "Release Note", nullptr));
        m_csLnDatumParameters_2->setText(QCoreApplication::translate("AppVersions", "<html><head/><body><p>kpidata</p></body></html>", nullptr));
        m_csLnDetectionDistce_5->setText(QCoreApplication::translate("AppVersions", "Version Number", nullptr));
        kpi_Vnum->setText(QString());
        m_csLnSpacingFactor_5->setText(QCoreApplication::translate("AppVersions", "Date", nullptr));
        kpi_Date->setText(QString());
        m_csLnNoofsonobuys_5->setText(QCoreApplication::translate("AppVersions", "Release Note", nullptr));
        m_csLnDatumParameters_3->setText(QCoreApplication::translate("AppVersions", "<html><head/><body><p>kpidatacollectioncron</p></body></html>", nullptr));
        m_csLnDetectionDistce_6->setText(QCoreApplication::translate("AppVersions", "Version Number", nullptr));
        kpicron_Vnum->setText(QString());
        m_csLnSpacingFactor_6->setText(QCoreApplication::translate("AppVersions", "Date", nullptr));
        kpicron_Date->setText(QString());
        m_csLnNoofsonobuys_6->setText(QCoreApplication::translate("AppVersions", "Release Note", nullptr));
        m_csLnDatumParameters_4->setText(QCoreApplication::translate("AppVersions", "<html><head/><body><p>commissioning-server</p></body></html>", nullptr));
        m_csLnDetectionDistce_7->setText(QCoreApplication::translate("AppVersions", "Version Number", nullptr));
        cs_Vnum->setText(QString());
        m_csLnSpacingFactor_7->setText(QCoreApplication::translate("AppVersions", "Date", nullptr));
        cs_Date->setText(QString());
        m_csLnNoofsonobuys_7->setText(QCoreApplication::translate("AppVersions", "Release Note", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Versions), QCoreApplication::translate("AppVersions", "Get Versions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppVersions: public Ui_AppVersions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPVERSIONS_H
