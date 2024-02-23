/*
FileName	:version
Purpose     :This Files is used to server connections.
Authour     :Gururaj B M / Kasturi Rangan.
*/

#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::server)
{
    ui->setupUi(this);

    QString Title = QString("OCR Server V %1.%2.%3").arg(VERSION_MAJ).arg(VERSION_MIN).arg(VERSION_REV);
    this->setWindowTitle(Title);

    QRegExp port("[0-9]{4,6}");
    QRegExpValidator *pReg_port = new QRegExpValidator(port, this);
    ui->lnEt_Port->setValidator(pReg_port);

    ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeWidget_log->setColumnCount(1);

    m_dActions = new DefineAction();
    m_Tcpserver = new QTcpServer(this);
    // whenever a user connects, it will emit signal
    connect(m_Tcpserver, SIGNAL(newConnection()),this, SLOT(newConnection()));
    connect(&m_event_timer,&QTimer::timeout,this,&server::send_event_responce);

    strList_EventIDs << "CSPRE" << "BOTWL" <<"LIGHTS";

    addDefineActions();

    //collect all .xml files project dir and append it to respective combobox

    QStringList filter("*.xml");
    QDir directory(QDir::currentPath());
    QStringList names = directory.entryList(filter);
    for(int i=0; i<names.size();i++)
    {
        QStringList t = names[i].split("-");
        t[1] = t[1].split(".")[0];
        for(int j=0; j<strList_EventIDs.length(); j++){
            if(t[0]==strList_EventIDs[j])
                m_cmbxActions[j]->addItem(t[1]);
        }
    }
    QString filename = qApp->applicationDirPath()+"/log.txt";
    filePath = filename;
    ui->label_FilePath->setText(filename);
}

server::~server()
{
    delete ui;
}
void server::addDefineActions()
{
    ui->tableWidget->setRowCount(0);
    int i=0;
    while(i < strList_EventIDs.length())
    {
        ui->tableWidget->insertRow(i);

        QTableWidgetItem *item;
        QString parameter_name = strList_EventIDs.at(i);
        item = new QTableWidgetItem(parameter_name);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(i,0,item);

        m_cmbxActions[i] = new QComboBox();
        m_cmbxActions[i]->clear();
        m_cmbxActions[i]->addItem("Ignore");
        ui->tableWidget->setCellWidget(i,1,m_cmbxActions[i]);

        m_timeForActions[i] = new QLineEdit();
        m_timeForActions[i]->setAlignment(Qt::AlignRight);
        QRegExp rx("[0-9]{0,6}");
        QRegExpValidator *pReg = new QRegExpValidator(rx, this);
        m_timeForActions[i]->setValidator(pReg);
        m_timeForActions[i]->setText("3");
        ui->tableWidget->setCellWidget(i,2,m_timeForActions[i]);

        QWidget *pWidget = new QWidget();
        m_chckBox = new QCheckBox();
        QHBoxLayout *pLayout = new QHBoxLayout(pWidget);
        pLayout->addWidget(m_chckBox);
        pLayout->setAlignment(Qt::AlignCenter);
        pLayout->setContentsMargins(0,0,0,0);
        pWidget->setLayout(pLayout);
        ui->tableWidget->setCellWidget(i,3,pWidget);

        i++;
    }
}

void server::on_pshBtn_StartServer_clicked()
{
    QString port = ui->lnEt_Port->text();
    if(!m_Tcpserver->listen(QHostAddress::Any, port.toInt()))
    {
        ui->lbl_Status->setText("  OCR Server Could Not Start");
        ui->lbl_Status->setStyleSheet("color : red");
    }
    else
    {
        ui->lbl_Status->setText("  OCR Server Started");
        ui->lbl_Status->setStyleSheet("color : green");
    }
}

//void server::on_pshBtn_StopServer_clicked()
//{
//    if (m_Tcpserver && m_Tcpserver->isListening())
//    {
//        m_Tcpserver->close();
//        ui->lbl_Status->setText("  OCR Server Stoped");
//        ui->lbl_Status->setStyleSheet("color : red");
//        m_event_timer.stop();
//    }
//}
void server::newConnection()
{
    m_Tcpsocket = m_Tcpserver->nextPendingConnection();
    connect(m_Tcpsocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    // m_Tcpsocket->close();
}
void server::on_chckBx_LogStatus_clicked(bool checked)
{
    if(checked == true)
    {
        statusLog = true;
    }else{
        statusLog = false;
    }
}
void server::on_pshBtn_ClearLog_clicked()
{
    ui->treeWidget_log->clear();
    ui->txtEdt->clear();
    StrLst_xmlData.clear();
    i = 0;
}
void server::on_treeWidget_log_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->txtEdt->clear();
    int index = item->treeWidget()->currentIndex().row();
    //qDebug() << "index===" << index;
    //qDebug() << StrLst_xmlData;
    // QString selectedText = ui->treeWidget_log->currentItem()->text(ui->treeWidget_log->currentColumn());
    QList<QString> data = StrLst_xmlData[index];
    //qDebug() << "data===" << data.length();

    if(data.length() == 33){
        ui->txtEdt->setText(generate_status_xml(data));
    }else if(data.length() == 16){
        ui->txtEdt->setText(generate_command_xml(data));
    }else if(data.length() == 17){
        ui->txtEdt->setText(generate_ocrstatus_xml(data));
    }else if(data.length() == 11){
        ui->txtEdt->setText(generate_command_replay_xml(data));
    }else if(data.length() == 21){
        ui->txtEdt->setText(generate_event_response_xml(m_cspre_event_response_total_parameters,data));
    }else if(data.length() == 125){
        ui->txtEdt->setText(generate_event_response_xml(m_botwl_event_response_total_parameters,data));
    }

}
void server::onReadyRead()
{
    QString data = m_Tcpsocket->readAll();
    if(data[0] == 0x02 && data.right(1) == 0x03)
    {
        data.remove(0,1);
        data.remove(-1,1);
        QList<QString> list;
        QDomDocument xml;
        xml.setContent(data);
        QDomElement MSG=xml.elementsByTagName("MSG").at(0).toElement();
        list.append(MSG.attributeNode("ID").value());
        list.append(MSG.attributeNode("CRANE_ID").value());
        list.append(MSG.attributeNode("VERSION").value());
        list.append(MSG.attributeNode("TS").value());
        QDateTime z=QDateTime::fromString(list[3],"yyyyMMddhhmmsszzz");
        QString time_stamp = z.toString("dd-MM-yyyy hh:mm:ss.zzz");
        if(MSG.firstChildElement().tagName()=="CRANE_STATUS")
        {
            QList<QString> s,t;
            s = read_crane_status(data);
            QString sNoF = time_stamp + "#" + "Crane Status recieved from CCS " +"\n";

            if(statusLog == true)
            {
                StrLst_xmlData.append(s);
                QTreeWidgetItem *widgetItem;
                widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
                widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
                widgetItem->setText(0, sNoF);
                widgetItem->setToolTip(0, sNoF);
                ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);
            }

            if(status == true)
            {
                QFile file(filePath);
                if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
                {
                    QTextStream stream(&file);
                    stream << sNoF << endl;
                    stream << xml << endl;
                }
                file.close();
            }
            t={"1","crane_1","1","2","crane_1"};
            t[0] = s[0];
            t[1] = s[1];
            t[4] = s[4];

            for(int i =0; i < strList_EventIDs.length() ; i++)
            {
                t.append(strList_EventIDs[i]); // CDOOR,CSPRE,ITRUCK..etc
                QWidget *pWidget = ui->tableWidget->cellWidget(i, 3);
                QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
                if (checkbox && checkbox->isChecked())
                {
                    t.append("1"); // CRANE_EVENT.AVAILABLE
                }else{
                    t.append("0"); // CRANE_EVENT.AVAILABLE
                }
                if(strList_EventIDs[i] == m_event){
                    t.append(m_event_status?"STARTED":"STOPPED"); // CRANE_EVENT.ACTIVE
                    t.append(m_event_cmd_id);
                }else{
                    t.append("STOPPED");
                    t.append("");
                }
            }

            QDateTime time = QDateTime::currentDateTime();
            t[3] = time.toString("yyyyMMddhhmmsszzz");
            time_stamp = time.toString("dd-MM-yyyy hh:mm:ss.zzz");

            QString sNoF1 = time_stamp + "#" + "OCR Status sent to CCS" +"\n";
            if(statusLog == true)
            {
                //qDebug() << "statusLog==" << statusLog;
                StrLst_xmlData.append(t);
                QTreeWidgetItem *widgetItem;
                widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
                widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
                widgetItem->setText(0, sNoF1);
                widgetItem->setToolTip(0, sNoF1);
                ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);
            }
            m_Tcpsocket->write((0x02+generate_ocrstatus_xml(t)+0x03).toUtf8());

            if(status == true)
            {
                QFile file(filePath);
                if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
                {
                    QTextStream stream(&file);
                    stream << sNoF1 << endl;
                    stream << generate_ocrstatus_xml(t) << endl;
                }
                file.close();
            }

        }
        else if(MSG.firstChildElement().tagName()=="CRANE_COMMAND")
        {
            QList<QString> s,t;
            s = read_crane_command(data);
            StrLst_xmlData.append(s);
            QString sNoF = time_stamp + "#Command recieved from CCS" +"\n";

            QTreeWidgetItem *widgetItem;
            widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
            widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
            widgetItem->setText(0, sNoF);
            widgetItem->setToolTip(0, sNoF);
            ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);

            if(status == true)
            {
                QFile file(filePath);
                if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
                {
                    QTextStream stream(&file);
                    stream << sNoF << endl;
                    stream << xml << endl;
                }
                file.close();
            }
            m_crane_id=s[1];
            t = {"2",m_crane_id,"1","",m_crane_id,"5","event","id","1","0",""};
            t[5] = s[5]; // COMMAND_ID ---1,2,3.4--etc.
            t[6] = s[6]; // EVENT_ID ----- CDOOR,CSPRE,ITRUCK..etc
            t[7] = s[7]; // DESCRISPTION ---

            if(s[8] == "STOP"){
                m_event_cmd_id = "";
                m_event_status = false;
                m_event_timer.stop();
                t[8] = "STOPPED";
                m_event_number++;
            }
            else if(s[8] == "START"){
                m_event_cmd_id = s[5];
                m_event = t[6];
                m_event_status = true;
                t[8] = "STARTED";
                int sec = 1;
                for(int i=0;i<strList_EventIDs.length();i++){
                    if(strList_EventIDs[i] == m_event){
                        sec = m_timeForActions[i]->text().toInt();
                    }
                }
                m_event_timer.start(sec * 1000);
            }

            QDateTime time= QDateTime::currentDateTime();
            t[3]=time.toString("yyyyMMddhhmmsszzz");
            time_stamp = time.toString("dd-MM-yyyy hh:mm:ss.zzz");
            StrLst_xmlData.append(t);
            QString sNoF1= time_stamp + "#Command reply sent to CCS" +"\n";
            widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
            widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
            widgetItem->setText(0, sNoF1);
            widgetItem->setToolTip(0, sNoF1);
            ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);

            QString command=0x02 + generate_command_replay_xml(t) + 0x03;
            m_Tcpsocket->write(command.toUtf8());

            if(status == true)
            {
                QFile file(filePath);
                if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
                {
                    QTextStream stream(&file);
                    stream << sNoF1 << endl;
                    stream << generate_command_replay_xml(t) << endl;
                }
                file.close();
            }
        }
    }
}

void server::closeWindow()
{
    //ui->pshBtn_DefineAction->setEnabled(true);
}
void server::on_chckBx_LogFile_clicked(bool checked)
{
    if(checked == true)
    {
        status = true;
    }else{
        status = false;
    }
}

QList<QString> server::read_crane_command(QString crane_command)
{
    QList<QString> command;
    QDomDocument command_xml;
    command_xml.setContent(crane_command);
    QDomElement MSG=command_xml.firstChildElement();
    command.append(MSG.attributeNode("ID").value());
    command.append(MSG.attributeNode("CRANE_ID").value());
    command.append(MSG.attributeNode("VERSION").value());
    command.append(MSG.attributeNode("TS").value());

    QList<QDomElement> l_stack;
    l_stack.append(MSG);
    QString l_string;
    //int c=0,d=0;

    for(int i=0; i<m_crane_command_parametes.length() ;i++)
    {
        l_string=m_crane_command_parametes[i];
        if(l_string[0]=="<")
        {
            //d++;
            if(l_string[1]=="/")
                l_stack.pop_back();
            else
                l_stack.append(l_stack[l_stack.length()-1].
                        elementsByTagName(l_string.remove("<").remove(">")).at(0).toElement());
        }
        else
        {
            //c++;
            if(l_stack.last().elementsByTagName(l_string).length()==0)
                command.append("NULL");
            else
                command.append(l_stack.last().elementsByTagName(l_string).at(0).firstChild().nodeValue());
        }
    }
    return command;
}
QList<QString> server::read_crane_status(QString crane_status)
{
    QList<QString> status;
    QDomDocument status_xml;
    status_xml.setContent(crane_status);
    QDomElement MSG=status_xml.firstChildElement();
    status.append(MSG.attributeNode("ID").value());
    status.append(MSG.attributeNode("CRANE_ID").value());
    status.append(MSG.attributeNode("VERSION").value());
    status.append(MSG.attributeNode("TS").value());

    QList<QDomElement> l_stack;
    l_stack.append(MSG);
    QString l_string;
    //int c=0,d=0;

    for(int i=0; i<m_crane_status_parametes.length() ;i++)
    {
        l_string=m_crane_status_parametes[i];
        if(l_string[0]=="<")
        {
            //d++;
            if(l_string[1]=="/")
                l_stack.pop_back();
            else
                l_stack.append(l_stack[l_stack.length()-1].
                        elementsByTagName(l_string.remove("<").remove(">")).at(0).toElement());
        }
        else
        {
            //c++;
            if(l_stack.last().elementsByTagName(l_string).length()==0)
                status.append("NULL");
            else
                status.append(l_stack.last().elementsByTagName(l_string).at(0).firstChild().nodeValue());
        }
    }
    return status;
}
void server::send_event_responce()
{
    QString indexTemp;
    for(int i=0;i<strList_EventIDs.length();i++)
    {
        if(m_event == strList_EventIDs[i])
        {
            indexTemp = m_cmbxActions[i]->currentText();
        }
    }
    if(indexTemp != "Ignore" && indexTemp !="")
    {
        QFile xmlFile(m_event+"-" + indexTemp + ".xml");
        if(!xmlFile.open(QIODevice::ReadOnly)){
            qDebug()<<"file not opened";
            return;
        }
        QTextStream input_stream(&xmlFile);
        QString str=input_stream.readAll();
        xmlFile.close();
        QDomDocument xmldoc;
        if(!xmldoc.setContent(str))
        {
            qDebug()<<"not a valid xml";
            return;
        }
        QDateTime time= QDateTime::currentDateTime();
        QDomElement MSG = xmldoc.elementsByTagName("MSG").at(0).toElement();
        MSG.attributeNode("ID").setValue(QString::number(m_event_number));
        MSG.attributeNode("CRANE_ID").setValue(m_crane_id);
        MSG.attributeNode("VERSION").setValue("1");
        MSG.attributeNode("TS").setValue(time.toString("yyyyMMddhhmmsszzz"));

        QDomElement OCR_EVENT_RESPONSE=MSG.elementsByTagName("OCR_EVENT_RESPONSE").at(0).toElement();
        OCR_EVENT_RESPONSE.elementsByTagName("CRANE_ID").at(0).toElement().firstChild().setNodeValue(m_crane_id);
        QDomElement CRANE_EVENT=OCR_EVENT_RESPONSE.elementsByTagName("CRANE_EVENT").at(0).toElement();
        CRANE_EVENT.elementsByTagName("EVENT_ID").at(0).toElement().firstChild().setNodeValue(m_event);
        CRANE_EVENT.elementsByTagName("CMD_ID").at(0).toElement().firstChild().setNodeValue(m_event_cmd_id);

        QDomElement EVENT=OCR_EVENT_RESPONSE.elementsByTagName("EVENT").at(0).toElement();
        QDomElement DATE=EVENT.elementsByTagName("DATE").at(0).toElement();
        DATE.elementsByTagName("YEAR").at(0).toElement().firstChild().setNodeValue(time.toString("yyyy"));
        DATE.elementsByTagName("MONTH").at(0).toElement().firstChild().setNodeValue(time.toString("MM"));
        DATE.elementsByTagName("DAY").at(0).toElement().firstChild().setNodeValue(time.toString("dd"));
        DATE.elementsByTagName("HOUR").at(0).toElement().firstChild().setNodeValue(time.toString("hh"));
        DATE.elementsByTagName("MINUTE").at(0).toElement().firstChild().setNodeValue(time.toString("mm"));
        DATE.elementsByTagName("SECOND").at(0).toElement().firstChild().setNodeValue(time.toString("ss"));

        //display the element in widget
        QString sNoF1= time.toString("dd:MM:yyyy hh-mm-ss.zzz") + "#Event response sent to CCS" +"\n";
        QTreeWidgetItem *widgetItem;
        ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->treeWidget_log->setColumnCount(1);
        widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
        widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
        widgetItem->setText(0, sNoF1);
        widgetItem->setToolTip(0, sNoF1);
        ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);

        //send data through tcp socket
        QString event_responce=0x02+ xmldoc.toString() +0x03;
        m_Tcpsocket->write(event_responce.toUtf8());

        //add file if chekc box is checked
        if(status == true)
        {
            QString filename = filePath;
            QFile file(filename);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
            {
                QTextStream stream(&file);
                stream << sNoF1 << endl;
                stream << xmldoc.toString() << endl;
                file.close();
            }
        }
        //read and store values in list
        QList<QDomElement> stack;
        stack.append(MSG);

        QList<QString> l_values_list={QString::number(m_event_number),m_crane_id,time.toString("yyyyMMddhhmmsszzz")};;
        QList<QString> l_parameters_list;
        if(m_event=="CSPRE"){
            l_parameters_list=m_cspre_event_response_total_parameters;
        }else if(m_event=="BOTWL"){
            l_parameters_list=m_botwl_event_response_total_parameters;
        }
        else{

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
                if(l_flag){
                    l_values_list.append("NULL");
                }
                else{
                    l_values_list.append(stack.last().elementsByTagName(l_paramter_name).at(0).firstChild().nodeValue());
                }
            }
        }
        StrLst_xmlData.append(l_values_list);
        //qDebug()<<m_event<<"length variables"<<l_values_list.length();
    }
}

//=====================Starts Generating xml for status,command reply,Event reply==========
QString server::generate_status_xml(QList<QString> data)
{
    QDomDocument crane_status;
    int index=0;
    QDomElement root = crane_status.createElement("MSG");
    root.setAttribute("ID",data[index++]);
    root.setAttribute("CRANE_ID",data[index++]);
    root.setAttribute("VERSION",data[index++]);
    root.setAttribute("TS",data[index++]);
    crane_status.appendChild(root);

    QList<QDomElement> l_stack;
    l_stack.append(root);
    QString l_string;
    //int c=0,d=0;

    for(int i=0; i<m_crane_status_parametes.length() ;i++)
    {
        l_string=m_crane_status_parametes[i];
        if(l_string[0]=="<")
        {
            //d++;
            if(l_string[1]=="/"){
                if(l_stack[l_stack.length()-1].hasChildNodes())
                    l_stack[l_stack.length()-2].appendChild(l_stack[l_stack.length()-1]);
                l_stack.pop_back();
            }
            else
                l_stack.append(crane_status.createElement(l_string.remove("<").remove(">")));
        }
        else
        {
            //c++;
            QString l_data=data[index++];
            if(l_data!="NULL")
            {
                QDomElement l_element=crane_status.createElement(l_string);
                l_element.appendChild(crane_status.createTextNode(l_data));
                l_stack[l_stack.length()-1].appendChild(l_element);
            }
        }
    }
    return crane_status.toString();
}
QString server::generate_command_xml(QList<QString> data)
{
    QDomDocument crane_comand;
    int index=0;
    QDomElement root = crane_comand.createElement("MSG");
    root.setAttribute("ID", data[index++]);
    root.setAttribute("CRANE_ID",data[index++]);
    root.setAttribute("VERSION", data[index++]);
    root.setAttribute("TS",data[index++]);
    crane_comand.appendChild(root);

    QList<QDomElement> l_stack;
    l_stack.append(root);
    QString l_string;
    //int c=0,d=0;

    for(int i=0; i<m_crane_command_parametes.length() ;i++)
    {
        l_string=m_crane_command_parametes[i];
        if(l_string[0]=="<")
        {
            //d++;
            if(l_string[1]=="/"){
                if(l_stack[l_stack.length()-1].hasChildNodes())
                    l_stack[l_stack.length()-2].appendChild(l_stack[l_stack.length()-1]);
                l_stack.pop_back();
            }
            else
                l_stack.append(crane_comand.createElement(l_string.remove("<").remove(">")));
        }
        else
        {
            //c++;
            QString l_data=data[index++];
            if(l_data!="NULL")
            {
                QDomElement l_element=crane_comand.createElement(l_string);
                l_element.appendChild(crane_comand.createTextNode(l_data));
                l_stack[l_stack.length()-1].appendChild(l_element);
            }
        }
    }
    return crane_comand.toString();
}
QString server::generate_ocrstatus_xml(QList<QString> status_list)
{
    int index = 0;
    QDomDocument ocr_status;
    QDomElement root = ocr_status.createElement("MSG");
    root.setAttribute("ID",status_list[index++]);
    root.setAttribute("CRANE_ID",status_list[index++]);
    root.setAttribute("VERSION",status_list[index++]);
    root.setAttribute("TS",status_list[index++]);
    ocr_status.appendChild(root);
    QDomElement OCR_STATUS=ocr_status.createElement("OCR_STATUS");
    QDomElement CRANE_ID=ocr_status.createElement("CRANE_ID");
    CRANE_ID.appendChild(ocr_status.createTextNode(status_list[index++]));
    OCR_STATUS.appendChild(CRANE_ID);
    root.appendChild(OCR_STATUS);
    QDomElement CRANE_EVENTS=ocr_status.createElement("CRANE_EVENTS");

    for(int i =0 ; i < strList_EventIDs.length() ; i++){
        QDomElement CRANE_EVENT=ocr_status.createElement("CRANE_EVENT");
        QDomElement EVENT_ID=ocr_status.createElement("EVENT_ID");
        EVENT_ID.appendChild(ocr_status.createTextNode(status_list[index++]));
        CRANE_EVENT.appendChild(EVENT_ID);
        QDomElement AVAILABLE=ocr_status.createElement("AVAILABLE");
        AVAILABLE.appendChild(ocr_status.createTextNode(status_list[index++]));
        CRANE_EVENT.appendChild(AVAILABLE);
        QDomElement ACTIVE=ocr_status.createElement("ACTIVE");
        ACTIVE.appendChild(ocr_status.createTextNode(status_list[index++]));
        CRANE_EVENT.appendChild(ACTIVE);
        QDomElement CMD_ID=ocr_status.createElement("CMD_ID");
        CMD_ID.appendChild(ocr_status.createTextNode(status_list[index++]));
        CRANE_EVENT.appendChild(CMD_ID);
        CRANE_EVENTS.appendChild(CRANE_EVENT);
    }
    OCR_STATUS.appendChild(CRANE_EVENTS);
    return ocr_status.toString();
}

QString server::generate_command_replay_xml(QList<QString> command_replay_list)
{
    int index = 0;
    QDomDocument command_replay;
    QDomElement root = command_replay.createElement("MSG");
    root.setAttribute("ID",command_replay_list[index++]);
    root.setAttribute("CRANE_ID",command_replay_list[index++]);
    root.setAttribute("VERSION",command_replay_list[index++]);
    root.setAttribute("TS",command_replay_list[index++]);
    command_replay.appendChild(root);
    QDomElement CR_COMMAND_REPLY=command_replay.createElement("OCR_COMMAND_REPLY");
    QDomElement CRANE_ID=command_replay.createElement("CRANE_ID");
    CRANE_ID.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CR_COMMAND_REPLY.appendChild(CRANE_ID);
    root.appendChild(CR_COMMAND_REPLY);
    QDomElement CRANE_EVENTS=command_replay.createElement("CRANE_EVENTS");
    QDomElement CRANE_EVENT=command_replay.createElement("CRANE_EVENT");
    QDomElement CMD_ID=command_replay.createElement("CMD_ID");
    CMD_ID.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CRANE_EVENT.appendChild(CMD_ID);
    QDomElement EVENT_ID=command_replay.createElement("EVENT_ID");
    EVENT_ID.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CRANE_EVENT.appendChild(EVENT_ID);
    QDomElement DESC=command_replay.createElement("DESC");
    DESC.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CRANE_EVENT.appendChild(DESC);
    QDomElement ACTIVE=command_replay.createElement("ACTIVE");
    ACTIVE.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CRANE_EVENT.appendChild(ACTIVE);
    QDomElement err=command_replay.createElement("ERROR");
    err.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CRANE_EVENT.appendChild(err);
    QDomElement ERROR_MSG=command_replay.createElement("ERROR_MSG");
    ERROR_MSG.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CRANE_EVENT.appendChild(ERROR_MSG);
    CRANE_EVENTS.appendChild(CRANE_EVENT);
    CR_COMMAND_REPLY.appendChild(CRANE_EVENTS);
    return command_replay.toString();
}
QString server::generate_event_response_xml(QList<QString> parameters,QList<QString> data)
{
    QDomDocument event_response;
    int index=0;
    QDomElement root = event_response.createElement("MSG");
    root.setAttribute("ID",data[index++]);
    root.setAttribute("CRANE_ID",data[index++]);
    root.setAttribute("VERSION","1");
    root.setAttribute("TS",data[index++]);
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
            QString l_data=data[index++];
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

void server::on_pshBtn_DefineAction_clicked()
{
    QObject::connect(m_dActions, SIGNAL(AddAction(QString)),this , SLOT(AddAction(QString)));
    // QObject::connect(m_dActions, SIGNAL(closeWindow()),this , SLOT(closeWindow()));
    //ui->pshBtn_DefineAction->setEnabled(false);
    m_dActions->show();
    m_dActions->activateWindow();
}
void server::AddAction(QString Action)
{
    QStringList strParam = Action.split("-");
    QString strEvent = strParam.at(0);
    if(strEvent == "CSPRE"){
        m_cmbxActions[0]->addItem(strParam.at(1));
        QStringList strList;
        for(int i = 0; i < m_cmbxActions[0]->count();i++)
        {
            QString lst = m_cmbxActions[0]->itemText(i).trimmed();
            strList << lst;
        }
        strList.removeDuplicates();
        m_cmbxActions[0]->clear();
        m_cmbxActions[0]->addItems(strList);
    }else if(strEvent == "BOTWL"){
        m_cmbxActions[1]->addItem(strParam.at(1));
        QStringList strList;
        for(int i = 0; i < m_cmbxActions[1]->count();i++)
        {
            QString lst = m_cmbxActions[1]->itemText(i).trimmed();
            strList << lst;
        }
        strList.removeDuplicates();
        m_cmbxActions[1]->clear();
        m_cmbxActions[1]->addItems(strList);
    }
}
void server::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this,"OCR Server",
                                                                tr("Do you want to Exit?\n"),
                                                                QMessageBox::Yes | QMessageBox::No);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
        QApplication::quit();
    }
}

void server::on_pshBtn_Set_clicked()
{
    QStringList splitter;
    filePath  = QFileDialog::getExistingDirectory(this,tr("Choose Folder"));
    QDir dec(filePath);
    filePath = dec.filePath("log.txt");
    ui->label_FilePath->setText(filePath);
}
