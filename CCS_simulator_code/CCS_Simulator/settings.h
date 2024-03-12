/*
FileName	:version
Purpose     :This Files is used to CCS Simulation Settings.
Authour     :Gururaj B M / Kasturi Rangan / Harsha.
*/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>
#include <QSettings>
#include <QDebug>
#include <QLayout>
#include <QCheckBox>

namespace Ui {
class settings;
}

class settings : public QWidget
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

    QStringList craneStatus_xml_attribute;
    QStringList craneStatus_xml_dataType;
    QStringList craneCommand_Attribute;
    QStringList craneCommand_Type;
    QStringList strlstCmdval,strlstval;
    QStringList craneStatus_description;
    QStringList craneCommand_description;

    void FillDataToCraneStatusTable();
    void FillDataToCraneCommandTable();
    void ReloadSavedValues();

public slots:
    void on_pushbtn_savexmlValues_clicked();

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
