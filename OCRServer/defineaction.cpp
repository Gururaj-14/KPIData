#include "defineaction.h"
#include "ui_defineaction.h"

DefineAction::DefineAction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DefineAction)
{
    ui->setupUi(this);
    strList_EventIDs << "CSPRE" << "BOTWL" <<"LIGHT";
    ui->comboBox->addItems(strList_EventIDs);
    fillDefaluts();
    strlstHeader << "parameter";
    this->setWindowTitle("Define Action");
    LoadAvailableXmlFiles();
}

DefineAction::~DefineAction()
{
    delete ui;
}

void DefineAction::fillDefaluts()
{

    ui->tableWidget->setRowCount(0);
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_3->setRowCount(0);

    QTableWidgetItem *item_cspre,*item_botwl;
    int k = 0,m = 0;
    while(k < m_cspre_event_response_display_parameters.length())
    {
        ui->tableWidget->insertRow(k); // CSPRE
        ui->tableWidget->setRowHeight(k,50);

        QString parameter_name = m_cspre_event_response_display_parameters.at(k);

        item_cspre = new QTableWidgetItem(parameter_name);
        item_cspre->setFlags(item_cspre->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(k,0,item_cspre); // CSPRE
        k++;
    }
    while(m < m_botwl_event_response_display_parameters.length())
    {
        ui->tableWidget_2->insertRow(m); // BOTWL
        ui->tableWidget_2->setRowHeight(m,50);

        QString parameter_name = m_botwl_event_response_display_parameters.at(m);

        item_botwl = new QTableWidgetItem(parameter_name);
        item_botwl->setFlags(item_botwl->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget_2->setItem(m,0,item_botwl); // BOTWL
        m++;
    }
}
void DefineAction::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0){
        ui->tableWidget->show();
        ui->tableWidget_2->hide();
        ui->tableWidget_3->hide();

    }else if(index == 1){
        ui->tableWidget->hide();
        ui->tableWidget_2->show();
        ui->tableWidget_3->hide();

    }else
    {
        ui->tableWidget->hide();
        ui->tableWidget_2->hide();
        ui->tableWidget_3->show();
    }
}
void DefineAction::LoadAvailableXmlFiles()
{
    QStringList filter("*.xml");
    QDir directory(QDir::currentPath());
    QStringList names = directory.entryList(filter);

    for(int i=0; i<names.size();i++)
    {
        //Read text file
        QStringList filename = names[i].split("-");
        filename[1] = filename[1].split(".")[0];
        QFile xmlFile(names[i]);
        if(!xmlFile.open(QIODevice::ReadOnly)){
            qDebug()<<"file not opened";
            continue;
        }
        QTextStream input_stream(&xmlFile);
        QString str=input_stream.readAll();
        QDomDocument xmldoc;
        if(!xmldoc.setContent(str))
        {
            qDebug()<<names[i];
            qDebug()<<"file is not a valid xml";
            continue;
        }

        QDomElement MSG = xmldoc.elementsByTagName("MSG").at(0).toElement();
        QDomElement OCR_EVENT_RESPONSE=MSG.elementsByTagName("OCR_EVENT_RESPONSE").at(0).toElement();
        QList<QDomElement> stack;
        stack.append(MSG);

        //reading and preparing list
        QList<QString> l_values_list;
        QList<QString> l_parameters_list;
        if(filename[0]=="CSPRE"){
            l_parameters_list=m_cspre_event_response_display_parameters;
        }else if(filename[0]=="BOTWL"){
            l_parameters_list=m_botwl_event_response_display_parameters;
        }
        for(int i=0; i<l_parameters_list.length();i++)
        {
            QString l_paramter_name=l_parameters_list[i];
            if(l_paramter_name[0]=="<")
            {
                if(l_paramter_name[1]=="/")
                {
                    stack[stack.length()-2].removeChild(stack[stack.length()-1].toElement());
                    stack.pop_back();
                }
                else{
                    stack.append(stack[stack.length()-1].
                            elementsByTagName(l_paramter_name.remove("<").remove(">")).at(0).toElement());
                }
            }
            else
            {
                bool l_flag=true;
                for(int i=0;i<stack.last().childNodes().count();i++){
                    if(stack.last().childNodes().at(i).toElement().tagName()==l_paramter_name)
                        l_flag=false;
                }
                if(l_flag)
                    l_values_list.append("NULL");
                else
                    l_values_list.append(stack.last().elementsByTagName(l_paramter_name).at(0).firstChild().nodeValue());
            }
        }
        //adding coulmns to the table widget
        if(filename[0]=="CSPRE")
        {
            int l_column_count = ui->tableWidget->columnCount();
            ui->tableWidget->setColumnCount(l_column_count+1);
            QTableWidgetItem *headerItems = new QTableWidgetItem();
            headerItems->setText(filename[1]);
            ui->tableWidget->setHorizontalHeaderItem(l_column_count,headerItems);

            int i=0;
            int index=0;
            while(i < m_cspre_event_response_display_parameters.length())
            {
                if(m_cspre_event_response_display_parameters[i][0]!='<'){
                    QHBoxLayout *l = new QHBoxLayout();
                    chk = new QCheckBox();
                    chk->setGeometry(0,0,50,50);
                    ledt = new QLineEdit();
                    ledt->setFixedHeight(23);
                    ledt->setEnabled(false);
                    l->addWidget(chk);
                    l->addWidget(ledt);
                    QObject::connect(chk, SIGNAL(clicked(bool)), ledt, SLOT(setEnabled(bool)));

                    w = new QWidget();
                    w->setLayout(l);
                    if(l_values_list[index]!="NULL")
                    {
                        chk->setCheckState(Qt::Checked);
                        ledt->setEnabled(true);
                        ledt->setText(l_values_list[index]);
                    }
                    ui->tableWidget->setCellWidget(i,l_column_count, w);
                    index++;
                }
                i++;
            }
        }
        else if(filename[0]=="BOTWL")
        {
            int l_column_count = ui->tableWidget_2->columnCount();
            ui->tableWidget_2->setColumnCount(l_column_count+1);
            QTableWidgetItem *headerItems = new QTableWidgetItem();
            headerItems->setText(filename[1]);
            ui->tableWidget_2->setHorizontalHeaderItem(l_column_count,headerItems);

            int i=0;
            int index=0;
            while(i < m_botwl_event_response_display_parameters.length())
            {
                if(m_botwl_event_response_display_parameters[i][0]!='<'){
                    QHBoxLayout *l = new QHBoxLayout();
                    chk = new QCheckBox();
                    chk->setGeometry(0,0,50,50);
                    ledt = new QLineEdit();
                    ledt->setFixedHeight(23);
                    ledt->setEnabled(false);
                    l->addWidget(chk);
                    l->addWidget(ledt);
                    QObject::connect(chk, SIGNAL(clicked(bool)), ledt, SLOT(setEnabled(bool)));

                    w = new QWidget();
                    w->setLayout(l);
                    if(l_values_list[index]!="NULL")
                    {
                        chk->setCheckState(Qt::Checked);
                        ledt->setEnabled(true);
                        ledt->setText(l_values_list[index]);
                    }
                    ui->tableWidget_2->setCellWidget(i,l_column_count, w);
                    index++;
                }
                i++;
            }
        }
        else{

        }
    }
}
void DefineAction::on_pshBtn_DefineAction_clicked()
{
    groupWidget = new QWidget();
    groupWidget->setGeometry(250,250,300,150);
    groupWidget->setFixedSize(300,150);
    groupWidget->setWindowTitle("Save response name as...");

    QLabel *lb = new QLabel("Response name");
    lEdt = new QLineEdit();

    QString str_Validator = "[0-9A-Za-z_-]{0,30}";
    lEdt->setValidator(new QRegExpValidator(QRegExp(str_Validator)));
    lEdt->setFixedSize(150,30);

    QHBoxLayout *HLayout = new QHBoxLayout();
    HLayout->addWidget(lb);
    HLayout->addWidget(lEdt);

    QPushButton *okBtn = new QPushButton("Ok");
    connect(okBtn, SIGNAL(clicked()), this, SLOT(saveGroupWidget()));
    QPushButton *cancelBtn = new QPushButton("Cancel");
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(closeGroupWidget()));

    QHBoxLayout *H1Layout = new QHBoxLayout();
    H1Layout->addWidget(okBtn);
    H1Layout->addWidget(cancelBtn);

    QVBoxLayout *VLayout = new QVBoxLayout();
    VLayout->addLayout(HLayout);
    VLayout->addLayout(H1Layout);

    groupWidget->setLayout(VLayout);
    groupWidget->show();
}

void DefineAction::saveGroupWidget()
{
    QString response = lEdt->text();
    if(response == ""){
        QMessageBox msgBox;
        msgBox.setText("Please enter respone name");
        msgBox.exec();
        return;
    }
    if(ui->comboBox->currentText() == "CSPRE")
    {
        int l_column_count = ui->tableWidget->columnCount();
        for(int i = 1; i < l_column_count ; i++)
        {
            QString str = ui->tableWidget->horizontalHeaderItem(i)->text().trimmed();
            if( str == response){
                QMessageBox msgBox;
                msgBox.setText("This name already exists! Please enter another respone name");
                msgBox.exec();
                return;
            }
        }
        ui->tableWidget->setColumnCount(l_column_count+1);
        QTableWidgetItem *headerItems = new QTableWidgetItem();
        headerItems->setText(response);
        ui->tableWidget->setHorizontalHeaderItem(l_column_count,headerItems);

        int i=0;
        while(i < m_cspre_event_response_display_parameters.length())
        {
            if(m_cspre_event_response_display_parameters[i][0]!='<'){
                QHBoxLayout *l = new QHBoxLayout();
                chk = new QCheckBox();
                chk->setGeometry(0,0,50,50);
                ledt = new QLineEdit();
                ledt->setFixedHeight(23);
                ledt->setEnabled(false);
                l->addWidget(chk);
                l->addWidget(ledt);
                QObject::connect(chk, SIGNAL(clicked(bool)), ledt, SLOT(setEnabled(bool)));

                w = new QWidget();
                w->setLayout(l);
                ui->tableWidget->setCellWidget(i,l_column_count, w);
            }
            i++;
        }
    }else if(ui->comboBox->currentText() == "BOTWL"){
        int l_column_count = ui->tableWidget_2->columnCount();
        for(int i = 1; i < l_column_count ; i++)
        {
            QString str = ui->tableWidget_2->horizontalHeaderItem(i)->text().trimmed();
            if( str == response){
                QMessageBox msgBox;
                msgBox.setText("This name already exists! Please enter another respone name");
                msgBox.exec();
                return;
            }
        }
        ui->tableWidget_2->setColumnCount(l_column_count+1);
        QTableWidgetItem *header2 = new QTableWidgetItem();
        header2->setText(response);
        ui->tableWidget_2->setHorizontalHeaderItem(l_column_count,header2);

        int i=0;
        while(i < m_botwl_event_response_display_parameters.length())
        {
            if(m_botwl_event_response_display_parameters[i][0]!='<'){
                QHBoxLayout *l = new QHBoxLayout();
                chk = new QCheckBox();
                chk->setGeometry(0,0,50,50);

                ledt = new QLineEdit();
                ledt->setFixedHeight(23);
                ledt->setEnabled(false);
                l->addWidget(chk);
                l->addWidget(ledt);
                QObject::connect(chk, SIGNAL(clicked(bool)), ledt, SLOT(setEnabled(bool)));

                w = new QWidget();
                w->setLayout(l);
                ui->tableWidget_2->setCellWidget(i,l_column_count, w);
            }
            i++;
        }
    }else{
        QMessageBox msgBox;
        msgBox.setText("Currently LIGHTS command event responce has no parameters!");
        msgBox.exec();
    }
    lEdt->clear();
}

void DefineAction::closeGroupWidget()
{
    groupWidget->close();
}

void DefineAction::on_pshBtn_Save_clicked()
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this,"Define Action",
                                                                tr("Do you want to Save the responses?\n"),
                                                                QMessageBox::Yes | QMessageBox::No);
    if (resBtn == QMessageBox::Yes)
    {
        lst_responseValue.clear();
        int j=0;
        if(ui->comboBox->currentText() == "CSPRE")
        {
            int l_column_count = ui->tableWidget->columnCount();
            for(int i = 1; i < l_column_count ; i++){
                QString l_column_name =  ui->tableWidget->horizontalHeaderItem(i)->text();
                emit AddAction("CSPRE-" + l_column_name);
                lst_responseName << "CSPRE-" + l_column_name;
                values.clear();
                j = 0;
                while(j < m_cspre_event_response_display_parameters.length())
                {
                    if(m_cspre_event_response_display_parameters[j][0]!='<'){
                        QWidget *pWidget = ui->tableWidget->cellWidget(j, i);
                        QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
                        if (checkbox && checkbox->isChecked())
                        {
                            QWidget *pWidget = ui->tableWidget->cellWidget(j, i);
                            QLineEdit *lEdt = pWidget->findChild<QLineEdit *>();
                            QString val = lEdt->text();
                            values << val;
                        }else{
                            values << "NULL";
                        }
                    }
                    j++;
                }
                lst_responseValue << values;

                QString filename= "CSPRE-" + l_column_name + ".xml";
                QFile file(filename);
                if (file.open(QIODevice::WriteOnly))
                {
                    QTextStream stream(&file );
                    QString l_xml_data=generate_event_response_xml(m_cspre_event_response_total_parameters,values);
                    file.write(l_xml_data.toUtf8());
                    file.close();
                }
            }

        }else if(ui->comboBox->currentText() == "BOTWL"){
            int l_column_count = ui->tableWidget_2->columnCount();
            for(int i = 1; i < l_column_count ; i++){
                QString l_column_name =  ui->tableWidget_2->horizontalHeaderItem(i)->text();
                emit AddAction("BOTWL-" + l_column_name);
                lst_responseName << "BOTWL-" + l_column_name;
                values.clear();
                j = 0;
                while(j < m_botwl_event_response_display_parameters.length())
                {
                    if(m_botwl_event_response_display_parameters[j][0]!='<'){
                        QWidget *pWidget = ui->tableWidget_2->cellWidget(j, i);
                        QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
                        if (checkbox && checkbox->isChecked())
                        {
                            QWidget *pWidget = ui->tableWidget_2->cellWidget(j, i);
                            QLineEdit *lEdt = pWidget->findChild<QLineEdit *>();
                            QString val = lEdt->text();
                            values << val;
                        }else{
                            values << "NULL";
                        }
                    }

                    j++;
                }
                lst_responseValue << values;
                //qDebug() << "lst_responseValue==" << lst_responseValue;
                QString filename= "BOTWL-" + l_column_name + ".xml";
                QFile file(filename);
                if (file.open(QIODevice::WriteOnly) )
                {
                    QTextStream stream(&file );
                    QString l_xml_content=generate_event_response_xml(m_botwl_event_response_total_parameters,values);
                    file.write(l_xml_content.toUtf8());
                    file.close();
                }
            }
        }
    }
}

QString DefineAction::generate_event_response_xml(QList<QString>parameters,QList<QString> data)
{
    QDomDocument event_response;
    int index=0;
    QDomElement root = event_response.createElement("MSG");
    root.setAttribute("ID","0");
    root.setAttribute("CRANE_ID","0");
    root.setAttribute("VERSION","0");
    root.setAttribute("TS","0");
    event_response.appendChild(root);

    QList<QDomElement> l_stack;
    l_stack.append(root);
    QString l_string;
    int c=0,d=0;
    for(int i=0; i<parameters.length() ;i++)
    {
        l_string=parameters[i];

        if(l_string[0]=="<")
        {
            d++;
            if(l_string[1]=="/"){
                if(l_stack[l_stack.length()-1].hasChildNodes())
                    l_stack[l_stack.length()-2].appendChild(l_stack[l_stack.length()-1]);
                l_stack.pop_back();
            }
            else
                l_stack.append(event_response.createElement(l_string.remove("<").remove(">")));
        }
        else
        {
            c++;
            QString l_data;
            if(l_string=="CRANE_ID"||l_string=="EVENT_ID"||l_string=="CMD_ID"||l_string=="YEAR"||l_string=="MONTH"||l_string=="DAY"||l_string=="HOUR"||l_string=="MINUTE"||l_string=="SECOND"){
                l_data="0";
            }
            else
            {
                l_data=data[index++];
            }
            if(l_data!="NULL")
            {
                QDomElement l_element=event_response.createElement(l_string);
                l_element.appendChild(event_response.createTextNode(l_data));
                l_stack[l_stack.length()-1].appendChild(l_element);
            }
        }
    }
    return event_response.toString();
}

void DefineAction::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this,"Define Action",
                                                                tr("Do you want to Exit?\n"),
                                                                QMessageBox::Yes | QMessageBox::No);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
        emit closeWindow();
    }
}
