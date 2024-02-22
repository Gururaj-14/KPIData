/********************************************************************************
** Form generated from reading UI file 'wait_time.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAIT_TIME_H
#define UI_WAIT_TIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_wait_time
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_waitTime;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pshbtn_cancelTime;

    void setupUi(QDialog *wait_time)
    {
        if (wait_time->objectName().isEmpty())
            wait_time->setObjectName(QString::fromUtf8("wait_time"));
        wait_time->resize(357, 111);
        verticalLayout_2 = new QVBoxLayout(wait_time);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(wait_time);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label);

        label_waitTime = new QLabel(wait_time);
        label_waitTime->setObjectName(QString::fromUtf8("label_waitTime"));

        horizontalLayout->addWidget(label_waitTime);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pshbtn_cancelTime = new QPushButton(wait_time);
        pshbtn_cancelTime->setObjectName(QString::fromUtf8("pshbtn_cancelTime"));

        horizontalLayout_2->addWidget(pshbtn_cancelTime);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(wait_time);

        QMetaObject::connectSlotsByName(wait_time);
    } // setupUi

    void retranslateUi(QDialog *wait_time)
    {
        wait_time->setWindowTitle(QCoreApplication::translate("wait_time", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("wait_time", "Waiting Time  :", nullptr));
        label_waitTime->setText(QString());
        pshbtn_cancelTime->setText(QCoreApplication::translate("wait_time", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wait_time: public Ui_wait_time {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAIT_TIME_H
