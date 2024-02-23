/*
FileName	:version
Purpose     :This Files is used to CCS Simulation Settings.
Authour     :Gururaj B M / Kasturi Rangan / Harsha.
*/

#include "settings.h"
#include "ui_settings.h"

#define GROUPSTATUS "CRANE_STATUS"
#define GROUPCOMMAND "CRANE_COMMAND"

settings::settings(QWidget *parent) :QWidget(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    this->setWindowTitle("CCS Simulator Settings");
    //Crane status variables
    craneStatus_xml_attribute << "CRANE_ID" << "GANTRY.LOCATION" << "GANTRY.SPEED" << "TROLLEY.LOCATION" << "TROLLEY.SPEED" << "SPREADER.LOCATION" <<"SPREADER.SPEED" <<"SPREADER.SPREADER_TRIM"<< "SPREADER.SIZE"<<"SPREADER.LOAD"
                              << "SPREADER.LANDED"<< "SPREADER.TWL_STATE" << "SPREADER.TWIN_CAPABLE"<<"SPREADER.TWIN_FRONT"<<"SPREADER.TWIN_BACK" << "TRUCK. TRUCK_PRESENT" << "TRUCK.TRUCK_FRONT_POS" << "TRUCK.TRUCK_REAR_POS"
                              << "CONTAINER_TOP_HEIGHT" << "JOB.ID" << "JOB.OPERATION" <<"JOB.CONTAINER" << "JOB.TRUCK.ID" << "JOB.TRUCK.SECTION_NUMBER" << "JOB.TRUCK.TYPE"
                              << "JOB.TRUCK.SUB_TYPE" << "JOB.TARGET.GANTRY_LOCATION" << "JOB.TARGET.TROLLEY_LOCATION" << "JOB.TARGET.HEIGHT";

    craneStatus_xml_dataType << "STRING" << "DOUBLE" << "DOUBLE" << "DOUBLE" << "DOUBLE" << "DOUBLE" << "DOUBLE" << "DOUBLE"<< "UINT"<< "DOUBLE" << "BOOLEAN" << "STRING" << "BOOLEAN" << "BOOLEAN" << "BOOLEAN" << "BOOLEAN"
                             << "DOUBLE" << "DOUBLE" << "DOUBLE" << "UINT" << "STRING" << "STRING" << "STRING" << "UINT"<< "STRING" << "UINT" << "DOUBLE" << "DOUBLE" << "DOUBLE";

    craneStatus_description << "crane identification" << "not sent if unknown" << "" << "not sent if unknown" << "" << "height from the ground / not sent if unknown" <<"not sent if unknown" <<"not sent if unknown" << "spreader size" << "" << "spreader landed information"
                            << "twistlock locked" << "" << "" << "" << "truck position under the crane" << ""<< ""<<"measured top of container height" <<"" << "" << "" << "" << "" << "" << "" << "" << "" << "" ;
    //Crane command variables
    craneCommand_Attribute <<"CRANE_ID" << "CRANE_EVENT.JOB" <<"CRANE_EVENT.TRUCK.TRUCK_TYPE"<<
                             "CRANE_EVENT.TRUCK.TRUCK_ID"<< "CRANE_EVENT.TRUCK.DIRECTION" << "CRANE_EVENT.CONTAINER.CONTAINER_ID"<< "CRANE_EVENT.CONTAINER.CONTAINER_ISO"<< "CRANE_EVENT.CONTAINER.CONTAINER_WIDTH";

    craneCommand_Type <<"STRING"<<"BOOLEAN"<<"STRING"<<"STRING"<<"STRING"<<"STRING"<<"STRING"<<"UINT";
    craneCommand_description << "crane identification"<< "job related" << "" << "" << "" << "" << ""<< "20,40,45" ;

    FillDataToCraneStatusTable();
    FillDataToCraneCommandTable();
    ReloadSavedValues();
}

settings::~settings()
{
    delete ui;
}

void settings::FillDataToCraneStatusTable()
{
    ui->tW_CraneStatus->setRowCount(0);
    int i=0;
    while(i < craneStatus_xml_dataType.length())
    {
        ui->tW_CraneStatus->insertRow(i);

        QTableWidgetItem *item;
        QString parameter_name = craneStatus_xml_attribute.at(i);
        QString parameter_data_type = craneStatus_xml_dataType.at(i);
        QString parameter_description = craneStatus_description.at(i);

        item = new QTableWidgetItem(parameter_name);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tW_CraneStatus->setItem(i,0,item);

        item = new QTableWidgetItem(parameter_data_type);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tW_CraneStatus->setItem(i,1,item);

        item = new QTableWidgetItem(parameter_description);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tW_CraneStatus->setItem(i,3,item);

        QLineEdit* l_line_edit=new QLineEdit();
        QComboBox* l_comboBox = new QComboBox();
        l_comboBox->clear();
        if(i == 7)
        {
            QStringList sprederSize;
            sprederSize << "20" << "40" << "45" << "0";
            l_comboBox->addItems(sprederSize);
            ui->tW_CraneStatus->setCellWidget(i,2,l_comboBox);

        }else if(i == 10)
        {
            QStringList spreder_twl_state;
            spreder_twl_state << "Open" << "Closed" ;
            l_comboBox->addItems(spreder_twl_state);
            ui->tW_CraneStatus->setCellWidget(i,2,l_comboBox);

        }else if(i == 19)
        {
            QStringList job_opertion;
            job_opertion << "PICK" << "PLACE" ;
            l_comboBox->addItems(job_opertion);
            ui->tW_CraneStatus->setCellWidget(i,2,l_comboBox);

        }else if(i == 24)
        {
            QStringList job_truck_type;
            job_truck_type << "INTERNAL" << "EXTERNAL" ;
            l_comboBox->addItems(job_truck_type);
            ui->tW_CraneStatus->setCellWidget(i,2,l_comboBox);

        }else
        {
            l_line_edit->setAlignment(Qt::AlignRight);
            if(craneStatus_xml_dataType.at(i) == "DOUBLE")
            {
                QRegExp rx("^[0-9]+\\.?[0-9]*$");
                QRegExpValidator *pReg = new QRegExpValidator(rx, this);
                l_line_edit->setValidator(pReg);
                ui->tW_CraneStatus->setCellWidget(i,2,l_line_edit);
                l_line_edit->setText("10.00");

            }else if(craneStatus_xml_dataType.at(i) == "UINT")
            {
                QRegExp rx("[1-9][0-9]*");
                QRegExpValidator *pReg = new QRegExpValidator(rx, this);
                l_line_edit->setValidator(pReg);
                ui->tW_CraneStatus->setCellWidget(i,2,l_line_edit);
                l_line_edit->setText("20");

            }else if(craneStatus_xml_dataType.at(i) == "BOOLEAN")
            {
                QRegExp rx("[0,1]");
                QRegExpValidator *pReg = new QRegExpValidator(rx, this);
                l_line_edit->setValidator(pReg);
                ui->tW_CraneStatus->setCellWidget(i,2,l_line_edit);
                l_line_edit->setText("1");

            }else
            {
                QRegExp rx("^\\S+$"); // string
                QRegExpValidator *pReg = new QRegExpValidator(rx, this);
                l_line_edit->setValidator(pReg);
                ui->tW_CraneStatus->setCellWidget(i,2,l_line_edit);
                l_line_edit->setText("String");
            }
        }
        //check box
        if(i!=0){
            QWidget * widget=new QWidget();
            QHBoxLayout* hbox=new QHBoxLayout();
            QCheckBox* check_box=new QCheckBox();
            connect(check_box,&QCheckBox::stateChanged,this,[=]() ->void {
                if(check_box->isChecked())
                {
                    l_line_edit->setEnabled(true);
                    l_comboBox->setEnabled(true);
                }
                else
                {
                    l_line_edit->setEnabled(false);
                    l_comboBox->setEnabled(false);
                }
            });
            hbox->addWidget(check_box);
            hbox->setMargin(0);
            hbox->setAlignment(check_box,Qt::AlignCenter);
            widget->setLayout(hbox);
            ui->tW_CraneStatus->setCellWidget(i,4,widget);
        }
        i++;
    }
}

void settings::FillDataToCraneCommandTable()
{
    ui->tW_CraneCommand->setRowCount(0);
    int i=0;
    while(i < craneCommand_Attribute.length())
    {
        ui->tW_CraneCommand->insertRow(i);
        QTableWidgetItem *item;
        QString parameter_name = craneCommand_Attribute.at(i);
        QString parameter_data_type = craneCommand_Type.at(i);
        QString parameter_description = craneCommand_description.at(i);

        item = new QTableWidgetItem(parameter_name);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tW_CraneCommand->setItem(i,0,item);

        item = new QTableWidgetItem(parameter_data_type);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tW_CraneCommand->setItem(i,1,item);

        item = new QTableWidgetItem(parameter_description);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tW_CraneCommand->setItem(i,3,item);

        QLineEdit *l_comboBox = new QLineEdit();
        l_comboBox->setAlignment(Qt::AlignRight);
        if(craneCommand_Type.at(i) == "DOUBLE")
        {
            QRegExp rx("^[0-9]+\\.?[0-9]*$");
            QRegExpValidator *pReg = new QRegExpValidator(rx, this);
            l_comboBox->setValidator(pReg);
            ui->tW_CraneCommand->setCellWidget(i,2,l_comboBox);
            l_comboBox->setText("00.00");

        }else if(craneCommand_Type.at(i) == "UINT")
        {
            QRegExp rx("[0-9]*");
            QRegExpValidator *pReg = new QRegExpValidator(rx, this);
            l_comboBox->setValidator(pReg);
            ui->tW_CraneCommand->setCellWidget(i,2,l_comboBox);
            l_comboBox->setText("00");

        }else if(craneCommand_Type.at(i) == "BOOLEAN")
        {
            QRegExp rx("[0,1]");
            QRegExpValidator *pReg = new QRegExpValidator(rx, this);
            l_comboBox->setValidator(pReg);
            ui->tW_CraneCommand->setCellWidget(i,2,l_comboBox);
            l_comboBox->setText("0");

        }else
        {
            QRegExp rx("^\\S+$"); // string
            QRegExpValidator *pReg = new QRegExpValidator(rx, this);
            l_comboBox->setValidator(pReg);
            ui->tW_CraneCommand->setCellWidget(i,2,l_comboBox);
            l_comboBox->setText("String");
        }
        //check box
        if(i!=0){
            QWidget * widget=new QWidget();
            QHBoxLayout* hbox=new QHBoxLayout();
            QCheckBox* check_box=new QCheckBox();
            connect(check_box,&QCheckBox::stateChanged,this,[=]() ->void {
                if(check_box->isChecked())
                    l_comboBox->setEnabled(true);
                else
                    l_comboBox->setEnabled(false);
            });
            hbox->addWidget(check_box);
            hbox->setMargin(0);
            hbox->setAlignment(check_box,Qt::AlignCenter);
            widget->setLayout(hbox);
            ui->tW_CraneCommand->setCellWidget(i,4,widget);
        }
        i++;
    }
}

void settings::ReloadSavedValues()
{
    QStringList value,valueCmd;
    QSettings settings("Crane","Status");
    settings.beginGroup(GROUPSTATUS);
    QStringList sizeStaus = settings.allKeys();
    if(sizeStaus.size() == 0)
    {
        value += {"String","10.00","10.00","10.00","10.00","10.00","10.00","20","10.00","1","Open","1","1","1","1","10.00","10.00","10.00","20","PICK",
                "String","String","20","20","INTERNAL","20","10.00","10.00","10.00"};
    }else
    {
        for(int i=0; i < sizeStaus.length();i++)
        {
            value << settings.value(QString::number(i)).toString();
        }
        settings.endGroup();
    }

    for (int i=0; i< ui->tW_CraneStatus->rowCount(); ++i)
    {
        QString l_value=value.at(i);
        if(l_value!="NULL" && i!=0){
            QWidget *s= ui->tW_CraneStatus->cellWidget(i,4);
            QCheckBox* k= s->findChild<QCheckBox*>();
            if(k)
                k->setChecked(true);
        }
        if(l_value=="NULL" && i!=0){
            ui->tW_CraneStatus->cellWidget(i,2)->setEnabled(false);
        }
        else{
        if(i == 7 || i == 10 || i == 19 || i == 24)
            ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,2)))->setCurrentText(value.at(i));
        else
            ((QLineEdit*)(ui->tW_CraneStatus->cellWidget(i,2)))->setText(value.at(i));
        }
    }

    //=======================================
    QSettings settings_cmd("Crane","Commands");
    settings_cmd.beginGroup(GROUPCOMMAND);
    QStringList sizecmd = settings_cmd.allKeys();
    if(sizecmd.size() == 0)
    {
        valueCmd += {"String","00","0","String","String","String","String","String","00"};
    }else
    {
        for(int i=0; i < sizecmd.length();i++)
        {
            valueCmd << settings_cmd.value(QString::number(i)).toString();
        }
        settings_cmd.endGroup();
    }

    for (int i=0; i< ui->tW_CraneCommand->rowCount(); ++i)
    {
        QString t=valueCmd.at(i);
        QWidget *s= ui->tW_CraneCommand->cellWidget(i,4);
        QCheckBox *k=s->findChild<QCheckBox*>();
        if(t!="NULL" && i!=0)
              k->setChecked(true);
        else if(t=="NULL" && i!=0){
            ui->tW_CraneCommand->cellWidget(i,2)->setEnabled(false);
        }
        else{
        ((QLineEdit*)(ui->tW_CraneCommand->cellWidget(i,2)))->setText(valueCmd.at(i));
        }

    }
}
void settings::on_pushbtn_savexmlValues_clicked()
{
    strlstCmdval.clear();
    strlstval.clear();
    QString CmbxValue,CmbxCmdValue;
    int nCreateFlag = 0;
    QMessageBox qmsgMessageBox;
    nCreateFlag = qmsgMessageBox.warning(this,"SAVE...","Do You Want to Save the values",QMessageBox::Yes, QMessageBox::No);
    if(nCreateFlag == QMessageBox::Yes)
    {
        for (int i=0; i< ui->tW_CraneStatus->rowCount(); ++i)
        {
            QWidget *s= ui->tW_CraneStatus->cellWidget(i,4);
            QCheckBox *k=s->findChild<QCheckBox*>();
            if((k && k->isChecked()) || i==0){
            if(i == 7 || i == 10 || i == 19 || i == 24)
            {
                CmbxValue = ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,2)))->currentText();
            }else
            {
                CmbxValue  = ((QLineEdit*)(ui->tW_CraneStatus->cellWidget(i,2)))->text();
            }
            strlstval << CmbxValue;

            }
            else{
                strlstval << "NULL";
            }
        }
        // qDebug() << "strlstval" << strlstval << strlstval.size();
        QSettings settings("Crane","Status");
        settings.beginGroup(GROUPSTATUS);
        settings.clear();
        for(int i=0;i<strlstval.length();i++)
        {
            settings.setValue(QString::number(i), strlstval.at(i));
        }
        settings.endGroup();
        //=============================================Command Values================
        for (int i=0; i< ui->tW_CraneCommand->rowCount(); ++i)
        {
            QWidget *s= ui->tW_CraneCommand->cellWidget(i,4);
            QCheckBox *k=s->findChild<QCheckBox*>();
            if((k && k->isChecked()) || i==0){
                CmbxCmdValue  = ((QLineEdit*)(ui->tW_CraneCommand->cellWidget(i,2)))->text();
                strlstCmdval << CmbxCmdValue;
            }
            else{
                strlstCmdval<<"NULL";
            }
        }
        // qDebug() << "strlstCmdval" << strlstCmdval << strlstCmdval.size();
        QSettings settings_cmd("Crane","Commands");
        settings_cmd.beginGroup(GROUPCOMMAND);
        settings_cmd.clear();
        for(int i=0;i<strlstCmdval.length();i++)
        {
            settings_cmd.setValue(QString::number(i), strlstCmdval.at(i));
        }
        settings_cmd.endGroup();
        this->close();
    }
}
