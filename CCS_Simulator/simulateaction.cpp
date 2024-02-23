/*
FileName	:version
Purpose     :This Files is used to Simulation Actions.
Authour     :Gururaj B M / Kasturi Rangan / Harsha.
*/
#include "simulateaction.h"
#include "ui_simulateaction.h"
#define GROUPCOMMAND "CRANE_COMMAND"
#define ACTIONS "CRANE_ACTIONS"
#define NO_COMMAND_PARAMETERS 8
#define NO_STATUS_PARAMETERS  29

SimulateAction::SimulateAction(const QString &strIp,
                               const QString &strPort,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulateAction)
{
    ui->setupUi(this);
    this->setWindowTitle("Action Simulation");
    IPAddress = strIp;
    IPPort = strPort;
    m_socket_tcp = new QTcpSocket(this);
    reLoadActions();
    ui->cmbx_Action->lineEdit()->setPlaceholderText("Search or Select Action....");
    ui->cmbx_Action->setInsertPolicy(QComboBox::NoInsert);
    ui->cmbx_Action->completer()->setCompletionMode(QCompleter::PopupCompletion);
    connect(m_socket_tcp, SIGNAL(readyRead()), this, SLOT(readMessage()));
    strList_EventIDs << "CSPRE"<<"BOTWL"<<"LIGHTS";

    strLIst_EventDesc << "Container id, spreadercameras"<<"Bottom twist-locks"<<"Lights on/off";

    connect(&t_action_status,&QTimer::timeout,this,&SimulateAction::send_action_status);
    connect(&t_action_command1,&QTimer::timeout,this,&SimulateAction::StartCmd);
    connect(&t_action_command2,&QTimer::timeout,this,&SimulateAction::StopCmd);

}

SimulateAction::~SimulateAction()
{
    delete ui;
}
void SimulateAction::on_pshBtn_Run_clicked()
{
    ui->pshBtn_Run->setEnabled(false);
    on_pshBtn_ClearLog_clicked();
    m_socket_tcp->connectToHost(IPAddress,IPPort.toInt());

    QString filename = ui->cmbx_Action->currentText().trimmed()+".csv";
    QFile inputFile(filename);
    if(!inputFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"file not open!";
        return;
    }
    QTextStream instream;
    instream.setDevice(&inputFile);
    action_data = instream.readAll().split("\n");

    //qDebug()<<"count"<<action_data.count();
    // qDebug()<<"last element"<<action_data[21];
    inputFile.close();

    action_index=1;
    t_action_command1.start(600);
    t_action_status.start(400);
}
void SimulateAction::reLoadActions()
{
    QString nKey;
    QString nvalue;
    //ui->cmbx_Action->clear();
    QSettings settings("Crane_Action","Crane_Action_csv");
    settings.beginGroup(ACTIONS);
    foreach (const QString &key, settings.childKeys())
    {
        nKey = key;
        nvalue = settings.value(nKey).toString();
        ui->cmbx_Action->addItem(nvalue);
    }
    settings.endGroup();
}
void SimulateAction::AddAction(QString action)
{
    qDebug() << "action======" << action ;
    ui->cmbx_Action->addItem(action);
    QSettings settings("Crane_Action","Crane_Action_csv");
    settings.beginGroup(ACTIONS);
    settings.setValue(action,action);
    settings.endGroup();
}
void SimulateAction::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this,"Action Simulation",
                                                                tr("Do you want to Exit?\n"),
                                                                QMessageBox::Yes | QMessageBox::No);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
        emit simulationEnds();
       // QApplication::quit();
    }
}
void SimulateAction::send_action_status()
{
    QList<QString> t;
    if(action_index==action_data.size()-3)
    {
        t_action_command2.start(200);
    }

    if(action_index < action_data.size()){
        //qDebug()<<"connecton came"<<action_data[action_index];
        QString line = action_data[action_index];
        action_index++;
        t = line.split(",");
        if(t.length() == 29)
        {
            const QDateTime dateTime = QDateTime::currentDateTime();
            time_stamp = dateTime.toString("dd-MM-yyyy hh:mm:ss.zzz");
            QString time_s = dateTime.toString("yyyyMMddhhmmsszzz");
            t.insert(0,QString::number(status_msgId++));
            t.insert(1,time_s);

            QString xmlstatus = generate_status_xml(t);

            int num = i++;
            QByteArray Total_StatusMsg;
            Total_StatusMsg.append(0x02);
            Total_StatusMsg.append(xmlstatus.toUtf8());
            Total_StatusMsg.append(0x03);

            QString s_status;
            s_status = tr("<font color = green >Simulation Starts "" </font size = 11 >");
            ui->label_simulation->setText(s_status);

            m_socket_tcp->write(Total_StatusMsg);
            QString sNoF = time_stamp + "#" + "Crane Status sent to OCR " +"\n";

            //===============================================================================
            QTreeWidgetItem *widgetItem;
            ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
            ui->treeWidget_log->setColumnCount(1);

            //qDebug() << "statusLog==" << statusLog;
            StrLst_xmlData.append(t);
            widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
            widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
            widgetItem->setText(0, sNoF);
            widgetItem->setToolTip(0, sNoF);
            ui->treeWidget_log->insertTopLevelItem(num, widgetItem);
        }
    }
    else{
        t_action_status.stop();
        m_socket_tcp->close();
        QString s_status;
        s_status = tr("<font color = red >Simulation Completed "" </font size = 11 >");
        ui->label_simulation->setText(s_status);
        ui->pshBtn_Run->setEnabled(true);
        // emit simulationEnds();
        // ui->pshBtn_SimulateAction->setEnabled(true);
    }
}

void SimulateAction::on_pshBtn_ClearLog_clicked()
{
    ui->label_simulation->setText("");
    ui->treeWidget_log->clear();
    ui->txtEdt->clear();
    StrLst_xmlData.clear();
    i = 0;
}

void SimulateAction::on_treeWidget_log_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->txtEdt->clear();
    int index = item->treeWidget()->currentIndex().row();
    // qDebug() << "index===" << index;
    // QString selectedText = ui->treeWidget_log->currentItem()->text(ui->treeWidget_log->currentColumn());
    QList<QString> data = StrLst_xmlData[index];
    // qDebug() << "data===" << data;
    if(data.length() == 31){
        ui->txtEdt->setText(generate_status_xml(data));
    }else if(data.length() == 14){
        ui->txtEdt->setText(generate_command_xml(data));
    }else if(data.length() == 17){
        ui->txtEdt->setText(generate_ocrstatus_xml(data));
    }else if(data.length() == 11){
        ui->txtEdt->setText(generate_command_replay_xml(data));
    }else if(data.length() == 22){
        ui->txtEdt->setText(generate_event_response_xml(m_cspre_event_response_total_parameters,data));
    }else if(data.length() == 126){
    ui->txtEdt->setText(generate_event_response_xml(m_botwl_event_response_total_parameters,data));
    }
}
void SimulateAction::StartCmd()
{

    QDateTime dateTime = QDateTime::currentDateTime();
    time_stamp = dateTime.toString("dd-MM-yyyy hh:mm:ss.zzz");
    QString time_s = dateTime.toString("yyyyMMddhhmmsszzz");

    int Cmdindex = action_data.at(0).toInt();
    if(Cmdindex>=3||Cmdindex<0)
    {
        qDebug()<<"command is out of range!";
        return;
    }
    //qDebug()<<action_data<<action_data.length();
    QList<QString> data = generate_command_list();
    data.insert(1,time_s);
    data.insert(4,strList_EventIDs.at(Cmdindex));
    data.insert(5,strLIst_EventDesc.at(Cmdindex));
    data.insert(6,"START");

    StrLst_xmlData.append(data);

    QString xmlcommand = generate_command_xml(data);

    QByteArray Total_CommandMsg;
    Total_CommandMsg.append(0x02);
    Total_CommandMsg.append(xmlcommand.toUtf8());
    Total_CommandMsg.append(0x03);

    m_socket_tcp->write(Total_CommandMsg);

    QString sNoF = time_stamp + "#" + " START " +strList_EventIDs.at(Cmdindex) +" Command sent to OCR " +"\n";

    //===============================================================================
    QTreeWidgetItem *widgetItem;
    ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeWidget_log->setColumnCount(1);
    widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
    widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
    widgetItem->setText(0, sNoF);
    widgetItem->setToolTip(0, sNoF);
    ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);

    t_action_command1.stop();
}
void SimulateAction::StopCmd()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    time_stamp = dateTime.toString("dd-MM-yyyy hh:mm:ss.zzz");
    QString time_s = dateTime.toString("yyyyMMddhhmmsszzz");

    int Cmdindex = action_data.at(0).toInt();

    if(Cmdindex>=3||Cmdindex<0)
    {
        qDebug()<<"command is out of range!";
        return;
    }

    QList<QString> data = generate_command_list();
    data.insert(1,time_s);
    data.insert(4,strList_EventIDs.at(Cmdindex));
    data.insert(5,strLIst_EventDesc.at(Cmdindex));
    data.insert(6,"STOP");


    StrLst_xmlData.append(data);

    QString xmlcommand = generate_command_xml(data);

    QByteArray Total_CommandMsg;
    Total_CommandMsg.append(0x02);
    Total_CommandMsg.append(xmlcommand.toUtf8());
    Total_CommandMsg.append(0x03);

    m_socket_tcp->write(Total_CommandMsg);

    QString sNoF = time_stamp + "#" + " STOP " +strList_EventIDs.at(Cmdindex) +" Command sent to OCR " +"\n";

    //===============================================================================
    QTreeWidgetItem *widgetItem;
    ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeWidget_log->setColumnCount(1);
    widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
    widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
    widgetItem->setText(0, sNoF);
    widgetItem->setToolTip(0, sNoF);
    ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);

    t_action_command2.stop();
}
QList<QString> SimulateAction::generate_command_list()
{
    QList<QString> Status_cmdvalue;
    Status_cmdvalue << QString::number(command_msgId++);
    QString value;
    QSettings settings_cmd("Crane","Commands");
    settings_cmd.beginGroup(GROUPCOMMAND);
    QStringList StrLstsize = settings_cmd.allKeys();
    if(StrLstsize.size() >= NO_COMMAND_PARAMETERS)
    {
        for(int i=0; i < StrLstsize.length();i++)
        {
            value = settings_cmd.value(QString::number(i)).toString();
            Status_cmdvalue << value;
        }
        Status_cmdvalue.insert(2,QString::number(command_msgId-1));
    }else
    {
        Status_cmdvalue += {"String","00","0","String","String","String","String","String","00"};
    }


    //qDebug() << "Status_cmdvalue" << Status_cmdvalue;
    settings_cmd.endGroup();
    return Status_cmdvalue;
}
void SimulateAction::readMessage(){
    QString status;
    QString data = m_socket_tcp->readAll();
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
        time_stamp = z.toString("dd-MM-yyyy hh:mm:ss.zzz");

        if(MSG.firstChildElement().tagName()=="OCR_COMMAND_REPLY")
        {
            status = time_stamp + "#" + "Command reply recieved from OCR " +"\n";
            QDomElement OCR_COMMAND_REPLY=MSG.elementsByTagName("OCR_COMMAND_REPLY").at(0).toElement();
            list.append(OCR_COMMAND_REPLY.elementsByTagName("CRANE_ID").at(0).firstChild().nodeValue());

            QDomElement CRANE_EVENT=OCR_COMMAND_REPLY.elementsByTagName("CRANE_EVENTS").at(0).toElement().elementsByTagName("CRANE_EVENT").at(0).toElement();
            list.append(CRANE_EVENT.elementsByTagName("CMD_ID").at(0).firstChild().nodeValue());
            list.append(CRANE_EVENT.elementsByTagName("EVENT_ID").at(0).firstChild().nodeValue());
            list.append(CRANE_EVENT.elementsByTagName("DESC").at(0).firstChild().nodeValue());
            list.append(CRANE_EVENT.elementsByTagName("ACTIVE").at(0).firstChild().nodeValue());
            list.append(CRANE_EVENT.elementsByTagName("ERROR").at(0).firstChild().nodeValue());
            list.append(CRANE_EVENT.elementsByTagName("ERROR_MSG").at(0).firstChild().nodeValue());
        }
        else if(MSG.firstChildElement().tagName()=="OCR_STATUS")
        {
            status = time_stamp + "#" + "Status recieved from OCR " +"\n";
            QDomElement OCR_STATUS=MSG.elementsByTagName("OCR_STATUS").at(0).toElement();
            list.append(OCR_STATUS.elementsByTagName("CRANE_ID").at(0).firstChild().nodeValue());
            QDomNodeList CRANE_EVENTS=OCR_STATUS.elementsByTagName("CRANE_EVENTS").at(0).toElement().elementsByTagName("CRANE_EVENT");
            for(int i=0;i<strList_EventIDs.length();i++){
                QDomElement CRANE_EVENT=CRANE_EVENTS.at(i).toElement();
                list.append(CRANE_EVENT.elementsByTagName("EVENT_ID").at(0).firstChild().nodeValue());
                list.append(CRANE_EVENT.elementsByTagName("AVAILABLE").at(0).firstChild().nodeValue());
                list.append(CRANE_EVENT.elementsByTagName("ACTIVE").at(0).firstChild().nodeValue());
                list.append(CRANE_EVENT.elementsByTagName("CMD_ID").at(0).firstChild().nodeValue());
            }
        }
        else if(MSG.firstChildElement().tagName()=="OCR_EVENT_RESPONSE")
        {
            status = time_stamp + "#" + "Event response recieved from OCR " +"\n";
            QString l_event=MSG.elementsByTagName("OCR_EVENT_RESPONSE").at(0).toElement().elementsByTagName("CRANE_EVENT").at(0).toElement().elementsByTagName("EVENT_ID").at(0).firstChild().nodeValue();
            QList<QString> l_parameters_list;
            if(l_event=="CSPRE"){
                l_parameters_list=m_cspre_event_response_total_parameters;
            }else if(l_event=="BOTWL"){
                l_parameters_list=m_botwl_event_response_total_parameters;
            }
            QList<QDomElement> stack;
            stack.append(MSG);
            int c=0,d=0;
            for(int i=0; i<l_parameters_list.length() ;i++)
            {
                QString l_parameter=l_parameters_list[i];
                if(l_parameter[0]=="<")
                {
                    d++;
                    if(l_parameter[1]=="/"){
                        stack[stack.length()-2].removeChild(stack[stack.length()-1].toElement());
                        stack.pop_back();
                    }
                    else
                        stack.append(stack[stack.length()-1].
                                elementsByTagName(l_parameter.remove("<").remove(">")).at(0).toElement());
                }
                else
                {
                    c++;
                    bool l_flag=true;
                    for(int i=0;i<stack.last().childNodes().count();i++){
                        if(stack.last().childNodes().at(i).toElement().tagName()==l_parameter)
                            l_flag=false;
                    }
                    if(l_flag)
                        list.append("NULL");
                    else
                        list.append(stack.last().elementsByTagName(l_parameter).at(0).firstChild().nodeValue());
                }
            }
        }

        //QString sNoF = time_stamp + "#" + "Crane Status sent to OCR " +"\n";

        //===============================================================================
        QTreeWidgetItem *widgetItem;
        ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->treeWidget_log->setColumnCount(1);
        if(MSG.firstChildElement().tagName()=="OCR_STATUS")
        {
            StrLst_xmlData.append(list);
            widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
            widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
            widgetItem->setText(0, status);
            widgetItem->setToolTip(0, status);
            ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);

        }
        else
        {
            StrLst_xmlData.append(list);
            widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
            widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
            widgetItem->setText(0, status);
            widgetItem->setToolTip(0, status);
            ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);
        }
        //qDebug()<<"event list: "<<list.size();
    }
}
QString SimulateAction::generate_status_xml(QList<QString> data)
{
    QDomDocument crane_status;
    int index=0;
    QDomElement root = crane_status.createElement("MSG");
    root.setAttribute("ID",data[index++]);
    root.setAttribute("CRANE_ID",data[2]);
    root.setAttribute("VERSION","1");
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
QString SimulateAction::generate_command_xml(QList<QString> data)
{
    //qDebug()<<data;
    QDomDocument crane_comand;
    int index=0;
    QDomElement root = crane_comand.createElement("MSG");
    root.setAttribute("ID", data[index++]);
    root.setAttribute("CRANE_ID",data[2]);
    root.setAttribute("VERSION", "1");
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
    //qDebug()<<"values"<<c;
    return crane_comand.toString();
}
QString SimulateAction::generate_command_replay_xml(QList<QString> command_replay_list)
{
    int index=0;
    QDomDocument command_replay;
    QDomElement root = command_replay.createElement("MSG");
    root.setAttribute("ID",command_replay_list[index++]);
    root.setAttribute("CRANE_ID",command_replay_list[index++]);
    root.setAttribute("VERSION",command_replay_list[index++]);
    root.setAttribute("TS",command_replay_list[index++]);
    command_replay.appendChild(root);
    QDomElement CR_COMMAND_REPLY=command_replay.createElement("CR_COMMAND_REPLY");
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
    QDomElement err = command_replay.createElement("ERROR");
    err.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CRANE_EVENT.appendChild(err);
    QDomElement ERROR_MSG=command_replay.createElement("ERROR_MSG");
    ERROR_MSG.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CRANE_EVENT.appendChild(ERROR_MSG);
    CRANE_EVENTS.appendChild(CRANE_EVENT);
    CR_COMMAND_REPLY.appendChild(CRANE_EVENTS);
    return command_replay.toString();
}
QString SimulateAction::generate_ocrstatus_xml(QList<QString> status_list)
{
    int index=0;
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
    for(int i=0;i<strList_EventIDs.length();i++){
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
QString SimulateAction::generate_event_response_xml(QList<QString> parameters,QList<QString> data)
{
    QDomDocument event_response;
    int index=0;
    QDomElement root = event_response.createElement("MSG");
    root.setAttribute("ID",data[index++]);
    root.setAttribute("CRANE_ID",data[index++]);
    root.setAttribute("VERSION",data[index++]);
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

void SimulateAction::on_cmbx_Action_currentIndexChanged(int index)
{
   on_pshBtn_ClearLog_clicked();
}
