/*
FileName	:version
Purpose     :This Files is used to Define Action.
Authour     :Gururaj B M / Kasturi Rangan / Harsha.
*/
#include "defineaction.h"
#include "ui_defineaction.h"

DefineAction::DefineAction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DefineAction)
{
    ui->setupUi(this);
    this->setWindowTitle("Define Action");
    craneStatus_xml_attribute << "CRANE_ID" << "GANTRY.LOCATION" << "GANTRY.SPEED" << "TROLLEY.LOCATION" << "TROLLEY.SPEED" << "SPREADER.LOCATION" <<"SPREADER.SPEED" <<"SPREADER.SPREADER_TRIM"<< "SPREADER.SIZE"<<"SPREADER.LOAD"
                              << "SPREADER.LANDED"<< "SPREADER.TWL_STATE" << "SPREADER.TWIN_CAPABLE"<<"SPREADER.TWIN_FRONT"<<"SPREADER.TWIN_BACK" << "TRUCK. TRUCK_PRESENT" << "TRUCK.TRUCK_FRONT_POS" << "TRUCK.TRUCK_REAR_POS"
                              << "CONTAINER_TOP_HEIGHT" << "JOB.ID" << "JOB.OPERATION" <<"JOB.CONTAINER" << "JOB.TRUCK.ID" << "JOB.TRUCK.SECTION_NUMBER" << "JOB.TRUCK.TYPE"
                              << "JOB.TRUCK.SUB_TYPE" << "JOB.TARGET.GANTRY_LOCATION" << "JOB.TARGET.TROLLEY_LOCATION" << "JOB.TARGET.HEIGHT";

    craneStatus_xml_dataType << "STRING" << "DOUBLE" << "DOUBLE" << "DOUBLE" << "DOUBLE" << "DOUBLE" << "DOUBLE" << "DOUBLE"<< "UINT"<< "DOUBLE" << "BOOLEAN" << "STRING" << "BOOLEAN" << "BOOLEAN" << "BOOLEAN" << "BOOLEAN"
                             << "DOUBLE" << "DOUBLE" << "DOUBLE" << "UINT" << "STRING" << "STRING" << "STRING" << "UINT"<< "STRING" << "UINT" << "DOUBLE" << "DOUBLE" << "DOUBLE";

    craneStatus_description << "crane identification" << "not sent if unknown" << "" << "not sent if unknown" << "" << "height from the ground / not sent if unknown" <<"not sent if unknown" <<"not sent if unknown" << "spreader size" << "" << "spreader landed information"
                            << "twistlock locked" << "" << "" << "" << "truck position under the crane" << ""<< ""<<"measured top of container height" <<"" << "" << "" << "" << "" << "" << "" << "" << "" << "" ;

    FillDataToCraneStatusTable();

    strList_EventIDs << "CSPRE"<<"BOTWL"<<"LIGHTS";
    ui->cmbBx_EventID->addItems(strList_EventIDs);

    QRegExp rx("[1-9][0-9]*");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    ui->lineEdit_Count->setValidator(pReg);
}


DefineAction::~DefineAction()
{
    delete ui;
}

void DefineAction::FillDataToCraneStatusTable()
{
    ui->tW_CraneStatus->setRowCount(0);
    int i=0;
    while(i < craneStatus_xml_dataType.length())
    {
        ui->tW_CraneStatus->insertRow(i);

        QTableWidgetItem *item;
        // ui->tableWidget->insertColumn(i);
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
        ui->tW_CraneStatus->setItem(i,2,item);

        m_cmbx_valueType = new QComboBox();
        m_cmbx_valueType->clear();
        if(i == 0 || i == 7 || i == 10 || i == 19 || i == 20 || i == 21 || i == 24 ){
            QStringList sprederSizeFixed;
            sprederSizeFixed << "Fixed";
            m_cmbx_valueType->addItems(sprederSizeFixed);
            ui->tW_CraneStatus->setCellWidget(i,5,m_cmbx_valueType);
        }else{
            QStringList sprederSizeBoth;
            sprederSizeBoth << "Linear" << "Fixed";
            m_cmbx_valueType->addItems(sprederSizeBoth);
            ui->tW_CraneStatus->setCellWidget(i,5,m_cmbx_valueType);
        }

        editCraneStatus = new QLineEdit();
        editCraneStatus4 = new QLineEdit();
        m_comboBox = new QComboBox();
        m_comboBox4 = new QComboBox();
        m_comboBox->clear();
        m_comboBox4->clear();
        if(i == 7)
        {
            QStringList sprederSize;
            sprederSize << "20" << "40" << "45" << "0";
            m_comboBox->addItems(sprederSize);
            m_comboBox4->addItems(sprederSize);
            ui->tW_CraneStatus->setCellWidget(i,3,m_comboBox);
            ui->tW_CraneStatus->setCellWidget(i,4,m_comboBox4);

        }else if(i == 10)
        {
            QStringList spreder_twl_state;
            spreder_twl_state << "Open" << "Closed" ;
            m_comboBox->addItems(spreder_twl_state);
            m_comboBox4->addItems(spreder_twl_state);
            ui->tW_CraneStatus->setCellWidget(i,3,m_comboBox);
            ui->tW_CraneStatus->setCellWidget(i,4,m_comboBox4);

        }else if(i == 19)
        {
            QStringList job_opertion;
            job_opertion << "PICK" << "PLACE" ;
            m_comboBox->addItems(job_opertion);
            m_comboBox4->addItems(job_opertion);
            ui->tW_CraneStatus->setCellWidget(i,3,m_comboBox);
            ui->tW_CraneStatus->setCellWidget(i,4,m_comboBox4);

        }else if(i == 24)
        {
            QStringList job_truck_type;
            job_truck_type << "INTERNAL" << "EXTERNAL" ;
            m_comboBox->addItems(job_truck_type);
            m_comboBox4->addItems(job_truck_type);
            ui->tW_CraneStatus->setCellWidget(i,3,m_comboBox);
            ui->tW_CraneStatus->setCellWidget(i,4,m_comboBox4);

        }else
        {
            editCraneStatus->setAlignment(Qt::AlignRight);
            editCraneStatus4->setAlignment(Qt::AlignRight);
            if(craneStatus_xml_dataType.at(i) == "DOUBLE")
            {
                QRegExp rx("^[0-9]+\\.?[0-9]*$");
                QRegExpValidator *pReg = new QRegExpValidator(rx, this);
                editCraneStatus->setValidator(pReg);
                editCraneStatus4->setValidator(pReg);
                editCraneStatus->setText("01.00");
                editCraneStatus4->setText("10.00");
                ui->tW_CraneStatus->setCellWidget(i,3,editCraneStatus);
                ui->tW_CraneStatus->setCellWidget(i,4,editCraneStatus4);
            }else if(craneStatus_xml_dataType.at(i) == "UINT")
            {
                QRegExp rx("[1-9][0-9]*");
                QRegExpValidator *pReg = new QRegExpValidator(rx, this);
                editCraneStatus->setValidator(pReg);
                editCraneStatus4->setValidator(pReg);
                editCraneStatus->setText("01");
                editCraneStatus4->setText("20");
                ui->tW_CraneStatus->setCellWidget(i,3,editCraneStatus);
                ui->tW_CraneStatus->setCellWidget(i,4,editCraneStatus4);

            }else if(craneStatus_xml_dataType.at(i) == "BOOLEAN")
            {
                QRegExp rx("[0,1]");
                QRegExpValidator *pReg = new QRegExpValidator(rx, this);
                editCraneStatus->setValidator(pReg);
                editCraneStatus4->setValidator(pReg);
                editCraneStatus->setText("1");
                editCraneStatus4->setText("10");
                ui->tW_CraneStatus->setCellWidget(i,3,editCraneStatus);
                ui->tW_CraneStatus->setCellWidget(i,4,editCraneStatus4);


            }else
            {
                QRegExp rx("^\\S+$"); // string
                QRegExpValidator *pReg = new QRegExpValidator(rx, this);
                editCraneStatus->setValidator(pReg);
                editCraneStatus4->setValidator(pReg);
                editCraneStatus->setText("String");
                editCraneStatus4->setText("String");
                ui->tW_CraneStatus->setCellWidget(i,3,editCraneStatus);
                ui->tW_CraneStatus->setCellWidget(i,4,editCraneStatus4);
            }
        }
        i++;
    }
}


void DefineAction::on_pshBtn_SaveAction_clicked()
{
    strlstStartval.clear();
    strlstEndval.clear();
    strlstTypeval.clear();
    QString StartValue,EndValue,ValueType;
    int nCreateFlag = 0;
    QMessageBox qmsgMessageBox;
    nCreateFlag = qmsgMessageBox.warning(this,"SAVE...","Do You Want to Save the values",QMessageBox::Yes, QMessageBox::No);
    if(nCreateFlag == QMessageBox::Yes)
    {
        for (int i=0; i< ui->tW_CraneStatus->rowCount(); ++i)
        {
            ValueType  = ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,5)))->currentText();

            if(i == 7)
            {
                StartValue = ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,3)))->currentText();
                EndValue = ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,4)))->currentText();
            }else if(i == 10)
            {
                StartValue  = ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,3)))->currentText();
                EndValue = ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,4)))->currentText();
            }else if(i == 19)
            {
                StartValue  = ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,3)))->currentText();
                EndValue = ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,4)))->currentText();
            }else if(i == 24)
            {
                StartValue  = ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,3)))->currentText();
                EndValue = ((QComboBox*)(ui->tW_CraneStatus->cellWidget(i,4)))->currentText();
            }else
            {
                StartValue  = ((QLineEdit*)(ui->tW_CraneStatus->cellWidget(i,3)))->text();
                EndValue = ((QLineEdit*)(ui->tW_CraneStatus->cellWidget(i,4)))->text();
            }
            strlstStartval << StartValue;
            strlstEndval << EndValue;
            strlstTypeval << ValueType;
        }
        //qDebug() << "strlstStartval====" << strlstStartval << strlstStartval.size() << "strlstEndval====" <<   strlstEndval << strlstEndval.size();
        //qDebug() << "strlstTypeval" << strlstTypeval << strlstTypeval.size();
        ActionName =  ui->lineEdit_ActionName->text();
        if(ui->lineEdit_Count->text() == ""){
            count = 20;
        }else{
            count = ui->lineEdit_Count->text().toInt();
        }
    }
    emit AddAction(ActionName);
    int eventName = ui->cmbBx_EventID->currentIndex();
    create_csv_for_action(eventName,ActionName,count,strlstStartval,strlstEndval,strlstTypeval);
}
void DefineAction::create_csv_for_action(int EventName,QString action_name,int count,QStringList initial_values,QStringList final_values,
                                         QStringList types)
{

    QFile file(action_name+".csv");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    file.write((QString::number(EventName) + "\n").toUtf8());
    for(int i=0;i<count+1;i++)
    {
        QString line;
        for(int j=0;j<types.size();j++)
        {
            QString type=types[j];
            if(type=="Fixed")
            {
                line+=initial_values[j];
            }
            else if(type=="Linear")
            {
                line+=QString::number(initial_values[j].toDouble()+(((final_values[j].toDouble()-initial_values[j].toDouble())/count)*i));
            }
            if(j!=types.size()-1)
            {
                line.append(",");
            }
            else{
                line.append("\n");
            }
        }
        //qDebug()<<line;
        file.write(line.toUtf8());
    }
    file.close();
}
