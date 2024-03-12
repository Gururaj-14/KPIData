/*
FileName	:version
Purpose     :This Files is used to Define Action.
Authour     :Gururaj B M / Kasturi Rangan / Harsha.
*/
#ifndef DEFINEACTION_H
#define DEFINEACTION_H

#include <QWidget>
#include <QtWidgets>
namespace Ui {
class DefineAction;
}

class DefineAction : public QWidget
{
    Q_OBJECT

public:
    explicit DefineAction(QWidget *parent = nullptr);
    ~DefineAction();
    QString ActionName;
    int count;
    QStringList craneStatus_xml_attribute;
    QStringList craneStatus_xml_dataType;
    QStringList craneStatus_description;
    void FillDataToCraneStatusTable();
    QLineEdit  *editCraneStatus,*editCraneStatus4,*editCraneCommand;
    QComboBox *m_comboBox,*m_comboBox4,*m_cmbx_valueType;
    QStringList strlstStartval,strlstEndval,strlstTypeval;
    void create_csv_for_action(int EventName,QString action_name, int count, QStringList initial_values, QStringList final_values, QStringList types);
    QStringList strList_EventIDs;
private slots:
    void on_pshBtn_SaveAction_clicked();
signals:
    void AddAction(QString Action);

private:
    Ui::DefineAction *ui;
};

#endif // DEFINEACTION_H
