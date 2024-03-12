/*
FileName	:version
Purpose     :This Files is used to CCS Simulation.
Authour     :Gururaj B M / Kasturi Rangan / Harsha.
*/

#include "cssopertion.h"
#include "ui_cssopertion.h"
#define GROUP "IP_PORT_GROUP"
#define GROUPSTATUS "CRANE_STATUS"
#define GROUPCOMMAND "CRANE_COMMAND"
#define NO_STATUS_PARAMETERS  29
#define NO_COMMAND_PARAMETERS 8
CSSOpertion::CSSOpertion(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CSSOpertion)
{
    ui->setupUi(this);

    QString Title = QString("CCS Simulator for OCR V %1.%2.%3").arg(VERSION_MAJ).arg(VERSION_MIN).arg(VERSION_REV);
    this->setWindowTitle(Title);


    m_socket_tcp = new QTcpSocket(this);
    strList_EventIDs << "CSPRE"<<"BOTWL"<<"LIGHTS";
    ui->cmbBx_EventID->addItems(strList_EventIDs);

    strLIst_EventDesc<<"Container id, spreadercameras"<<"Bottom twist-locks"<<"Lights on/off";

    QRegExp ip("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");
    QRegExpValidator *pReg_ip = new QRegExpValidator(ip, this);
    ui->lnEt_IPAddress->setValidator(pReg_ip);

    QRegExp port("[0-9]{4,6}");
    QRegExpValidator *pReg_port = new QRegExpValidator(port, this);
    ui->lnEt_Port->setValidator(pReg_port);

    ui->rdoBtn_sendStopCmd->setChecked(true);
    bFlag=false;
    timer_CraneStatus = new QTimer(this);
    connect(timer_CraneStatus,SIGNAL(timeout()),this,SLOT(send_status()));
    connect(m_socket_tcp, SIGNAL(readyRead()), this, SLOT(readMessage()));

    //    connect(&t_action_status,&QTimer::timeout,this,&CSSOpertion::send_action_status);
    //    connect(&t_action_command1,&QTimer::timeout,this,&CSSOpertion::on_pshBtn_StartCmd_clicked);
    //    connect(&t_action_command2,&QTimer::timeout,this,&CSSOpertion::on_pshBtn_StopCmd_clicked);

    QString filename = qApp->applicationDirPath()+"/log.txt";
    filePath = filename;
    ui->label_FilePath->setText(filename);

    ReloadLastSelectedIPs();
    DisableWidgets();
}

CSSOpertion::~CSSOpertion()
{
    delete ui;
}
void CSSOpertion::FillOCRStatusAttributes()
{
    //    strLst_OCRStatusParam << "CRANE_ID" << "CRANE_EVENT.EVENT_ID" << "CRANE_EVENT.AVAILABLE" << "CRANE_EVENT.ACTIVE" << "CRANE_EVENT.CMD_ID";
    //    ui->tbleWdt_OCRStatus->setRowCount(0);
    //    int i=0;
    //    while(i < strLst_OCRStatusParam.length())
    //    {
    //        ui->tbleWdt_OCRStatus->insertRow(i);

    //        QTableWidgetItem *item;
    //        QString parameter_name = strLst_OCRStatusParam.at(i);

    //        item = new QTableWidgetItem(parameter_name);
    //        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
    //        ui->tbleWdt_OCRStatus->setItem(i,0,item);

    //        i++;
    //    }
}
void CSSOpertion::ReloadLastSelectedIPs()
{
    QString n_k;
    QString value;
    QSettings settingsip("Finecho_IP_Port","IP_Port_Details");
    settingsip.beginGroup(GROUP);
    foreach (const QString &key, settingsip.childKeys())
    {
        n_k = key;
        value = settingsip.value(key).toString();
    }
    if(n_k.length() > 7){
        ui->lnEt_IPAddress->setText(n_k);
        ui->lnEt_Port->setText(value);
    }else{
        ui->lnEt_IPAddress->setText("127.0.0.1");
        ui->lnEt_Port->setText("6789");
    }
    settingsip.endGroup();
}

void CSSOpertion::DisableWidgets()
{
    ui->pshBtn_Run->setEnabled(false);
    ui->comboBox_interval->setEnabled(false);
    ui->cmbBx_EventID->setEnabled(false);
    ui->pshBtn_StartCmd->setEnabled(false);
    ui->pshBtn_StopCmd->setEnabled(false);
    ui->rdoBtn_StopAfterEvent->setEnabled(false);
    ui->rdoBtn_StopBeforeEvent->setEnabled(false);
    ui->rdoBtn_sendStopCmd->setEnabled(false);
    ui->pshBtn_SimulateAction->setEnabled(false);
    ui->pshBtn_DefineAction->setEnabled(false);
    ui->pshBtn_Set->setEnabled(false);
    ui->psbtn_settings->setEnabled(false);
}

void CSSOpertion::EnableWidgets()
{
    ui->pshBtn_Run->setEnabled(true);
    ui->comboBox_interval->setEnabled(true);
    ui->cmbBx_EventID->setEnabled(true);
    ui->pshBtn_StartCmd->setEnabled(true);
    // ui->pshBtn_StopCmd->setEnabled(true);
    ui->rdoBtn_sendStopCmd->setEnabled(true);
    ui->rdoBtn_StopAfterEvent->setEnabled(true);
    ui->rdoBtn_StopBeforeEvent->setEnabled(true);
    ui->pshBtn_SimulateAction->setEnabled(true);
    ui->pshBtn_DefineAction->setEnabled(true);
    ui->pshBtn_Set->setEnabled(true);
    ui->psbtn_settings->setEnabled(true);
}
void CSSOpertion::on_pshBtn_DefineAction_clicked()
{
    m_DefineAction = new DefineAction();
    QObject::connect(m_DefineAction, SIGNAL(AddAction(QString)),m_SimulateAction , SLOT(AddAction(QString)));
    m_DefineAction->show();
}


void CSSOpertion::simulationEnds()
{
    ui->pshBtn_Run->setEnabled(true);
    ui->pshBtn_SimulateAction->setEnabled(true);
}

void CSSOpertion::on_psbtn_settings_clicked()
{
    m_settings = new settings();
    m_settings->show();
    m_settings->activateWindow();
}
bool CSSOpertion::CheckIPAddress(QString strIPAddress,QString strIPPort)
{
    if(strIPAddress.split(".").count()==4)
    {
        QHostAddress address(strIPAddress);
        if(QAbstractSocket::IPv4Protocol==address.protocol())
        {
            bFlag= true;
        }
        else if(QAbstractSocket::IPv6Protocol==address.protocol())
        {
            bFlag= true;
        }
        else
        {
            //QMessageBox::information(this,"Warning","Not a Valid IP Address");
            bFlag= false;
        }
    }
    else
    {
        //QMessageBox::information(this,"Warning","Not a Valid IP Address");
        bFlag= false;
    }
    return bFlag;
}

void CSSOpertion::send_status()
{
    const QDateTime dateTime = QDateTime::currentDateTime();
    time_stamp = dateTime.toString("dd-MM-yyyy hh:mm:ss.zzz");
    QString time_s = dateTime.toString("yyyyMMddhhmmsszzz");

    QStringList data = generate_status_list();
    data.insert(1,time_s);

    QString xmlstatus = generate_status_xml(data);

    int num = i++;
    QByteArray Total_StatusMsg;
    Total_StatusMsg.append(0x02);
    Total_StatusMsg.append(xmlstatus.toUtf8());
    Total_StatusMsg.append(0x03);

    m_socket_tcp->write(Total_StatusMsg);
    QString sNoF = time_stamp + "#" + "Crane Status sent to OCR " +"\n";

    //===============================================================================
    QTreeWidgetItem *widgetItem;
    ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeWidget_log->setColumnCount(1);

    if(statusLog == true)
    {
        //qDebug() << "statusLog==" << statusLog;
        StrLst_xmlData.append(data);
        widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
        widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
        widgetItem->setText(0, sNoF);
        widgetItem->setToolTip(0, sNoF);
        ui->treeWidget_log->insertTopLevelItem(num, widgetItem);
    }

    //==========================================================================
    QString filename = filePath;
    QFile file(filename);
    if(status == true)
    {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {
            QTextStream stream(&file);
            stream << sNoF << endl;
            stream << xmlstatus << endl;
        }
    }
    file.close();
}
void CSSOpertion::on_pshBtn_Test_clicked()
{
    bool ipStatus;
    strIPAddress = ui->lnEt_IPAddress->text();
    strIPPort = ui->lnEt_Port->text();
    m_SimulateAction = new SimulateAction(strIPAddress,strIPPort);
    ipStatus = CheckIPAddress(strIPAddress,strIPPort);
    if(ipStatus == true){
        m_socket_tcp->connectToHost(strIPAddress,strIPPort.toInt());
        if(m_socket_tcp->waitForConnected(10000))
        {
            //ui->label_Log->setText("Connected to IPAddress " + strIPAddress + " and port " + strIPPort);
            QSettings settingsip("Finecho_IP_Port","IP_Port_Details");
            settingsip.beginGroup(GROUP);
            settingsip.clear();
            settingsip.setValue(strIPAddress, strIPPort);
            settingsip.endGroup();
            ui->lbl_Connection->setStyleSheet("background-color:green;");
            EnableWidgets();
        }else{
            //ui->label_Log->setText("Unable Connect to IPAddress " + strIPAddress + " and port " + strIPPort);
            QMessageBox msgBox;
            msgBox.setText("Error: " + m_socket_tcp->errorString() + "\nPlease Check connectivity to server");
            msgBox.exec();
            ui->lbl_Connection->setStyleSheet("background-color:red;");
            DisableWidgets();
        }
    }else{
        // ui->label_Log->setText("Unable to connect,Enter Valid IP Address");
    }
}

void CSSOpertion::on_treeWidget_log_itemClicked(QTreeWidgetItem *item, int column)
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

void CSSOpertion::on_pshBtn_Set_clicked()
{
    QStringList splitter;
    filePath  = QFileDialog::getExistingDirectory(this,tr("Choose Folder"));
    //qDebug() << filePath;
    QDir dec(filePath);
    filePath = dec.filePath("log.txt");
    //qDebug()<< filePath;
    ui->label_FilePath->setText(filePath);

}

void CSSOpertion::on_chckBx_LogFile_clicked(bool checked)
{
    if(checked == true)
    {
        ui->label_FilePath->setEnabled(false);
        ui->pshBtn_Set->setEnabled(false);
        status = true;
    }else{
        ui->label_FilePath->setEnabled(true);
        ui->pshBtn_Set->setEnabled(true);
        status = false;
    }

}
void CSSOpertion::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this,"CCS Simulator for OCR",
                                                                tr("Do you want to Exit?\n"),
                                                                QMessageBox::Yes | QMessageBox::No);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        // event->accept();
        QApplication::quit();
    }
}
void CSSOpertion::on_pshBtn_ClearLog_clicked()
{
    ui->treeWidget_log->clear();
    ui->txtEdt->clear();
    StrLst_xmlData.clear();
    i = 0;
}

void CSSOpertion::on_chckBx_LogStatus_clicked(bool checked)
{
    if(checked == true)
    {
        statusLog = true;
    }else{
        statusLog = false;
    }
}


void CSSOpertion::on_pshBtn_Run_clicked()
{
    QList<float> time_intervals={1,2,3,4,5,10};
    int index = ui->comboBox_interval->currentIndex();
    float time = time_intervals.at(index);
    if(checked == true)
    {
        ui->pshBtn_Run->setText("Pause");
        if(m_socket_tcp->state() == QTcpSocket::ConnectedState){
            //qDebug() << "connected State";
            // m_socket_tcp->close();
        }
        else{
            //qDebug() << "Unconnected State,Now Connecting.....";
            m_socket_tcp->connectToHost(strIPAddress,strIPPort.toInt());
        }

        ui->comboBox_interval->setDisabled(true);
        ui->pshBtn_SimulateAction->setEnabled(false);
        checked = false;
        timer_CraneStatus->start(time * 1000);
    }else{
        ui->pshBtn_Run->setText("Run");
        m_socket_tcp->close();
        ui->comboBox_interval->setDisabled(false);
        ui->pshBtn_SimulateAction->setEnabled(true);
        checked = true;
        timer_CraneStatus->stop();
    }
}

void CSSOpertion::on_pshBtn_StartCmd_clicked()
{
    ui->cmbBx_EventID->setEnabled(false);
    if(ui->rdoBtn_sendStopCmd->isChecked())
    {
        ui->pshBtn_StopCmd->setEnabled(true);
        m_rbtn=0;
        ui->rdoBtn_StopAfterEvent->setEnabled(false);
        ui->rdoBtn_StopBeforeEvent->setEnabled(false);
    }
    else if(ui->rdoBtn_StopAfterEvent->isChecked()){
        m_rbtn=1;
        ui->rdoBtn_sendStopCmd->setEnabled(false);
        ui->rdoBtn_StopBeforeEvent->setEnabled(false);
    }
    else{
        m_rbtn=2;
        ui->rdoBtn_sendStopCmd->setEnabled(false);
        ui->rdoBtn_StopAfterEvent->setEnabled(false);
    }
    ui->pshBtn_StartCmd->setEnabled(false);
    QDateTime dateTime = QDateTime::currentDateTime();
    time_stamp = dateTime.toString("dd-MM-yyyy hh:mm:ss.zzz");
    QString time_s = dateTime.toString("yyyyMMddhhmmsszzz");

    int Cmdindex = ui->cmbBx_EventID->currentIndex();

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

    QString sNoF = time_stamp + "#" + " START " + ui->cmbBx_EventID->currentText() +" Command sent to OCR " +"\n";

    //===============================================================================
    QTreeWidgetItem *widgetItem;
    ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeWidget_log->setColumnCount(1);
    widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
    widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
    widgetItem->setText(0, sNoF);
    widgetItem->setToolTip(0, sNoF);
    ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);

    //==========================================================================
    QString filename = filePath;
    QFile file(filename);
    if(status == true)
    {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {
            QTextStream stream(&file);
            stream << sNoF << endl;
            stream << xmlcommand << endl;
        }
    }
    file.close();
    //t_action_command1.stop();
}

void CSSOpertion::on_pshBtn_StopCmd_clicked()
{
    ui->cmbBx_EventID->setEnabled(true);
    // ui->pshBtn_StopCmd->setEnabled(false);;

    ui->rdoBtn_StopAfterEvent->setEnabled(true);
    ui->rdoBtn_StopBeforeEvent->setEnabled(true);
    ui->rdoBtn_sendStopCmd->setEnabled(true);
    ui->pshBtn_StartCmd->setEnabled(true);
    ui->pshBtn_StopCmd->setEnabled(false);

    QDateTime dateTime = QDateTime::currentDateTime();
    time_stamp = dateTime.toString("dd-MM-yyyy hh:mm:ss.zzz");
    QString time_s = dateTime.toString("yyyyMMddhhmmsszzz");

    int Cmdindex = ui->cmbBx_EventID->currentIndex();

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

    QString sNoF = time_stamp + "#" + " STOP " + ui->cmbBx_EventID->currentText() +" Command sent to OCR " +"\n";

    //===============================================================================
    QTreeWidgetItem *widgetItem;
    ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeWidget_log->setColumnCount(1);
    widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
    widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
    widgetItem->setText(0, sNoF);
    widgetItem->setToolTip(0, sNoF);
    ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);

    //==========================================================================
    QString filename = filePath;
    QFile file(filename);
    if(status == true)
    {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {
            QTextStream stream(&file);
            stream << sNoF << endl;
            stream << xmlcommand << endl;
        }
    }
    file.close();
    //t_action_command2.stop();
}


void CSSOpertion::readMessage(){
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
            status = time_stamp + "#" +" Event Response recieved from OCR " +"\n";

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
                        if(stack[stack.length()-1].tagName()!="OCR_EVENT_RESPONSE")
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
        //===============================================================================
        QTreeWidgetItem *widgetItem;
        ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->treeWidget_log->setColumnCount(1);

        if(MSG.firstChildElement().tagName()=="OCR_STATUS")
        {
            QString ocrStatus;
            for(int i=0;i<strList_EventIDs.length();i++)
            {
                ocrStatus.append(strList_EventIDs[i]+" :  ");
                QString s=list[6+(4*i)]=="0"?tr("<font color = red > Not Avalilable </font size = 11 ><br> "):
                                             tr("<font color = green > Avalilable </font size = 11 ><br> ");
                ocrStatus+=s;
            }
            ui->txtEdt_OCRStatus->clear();
            ui->txtEdt_OCRStatus->setText(ocrStatus);

            if(statusLog == true)
            {
                StrLst_xmlData.append(list);
                widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
                widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
                widgetItem->setText(0, status);
                widgetItem->setToolTip(0, status);
                ui->treeWidget_log->insertTopLevelItem(i++, widgetItem);
            }
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
        if(MSG.firstChildElement().tagName()=="OCR_EVENT_RESPONSE" && m_rbtn == 1)
        {
            m_rbtn=0;
            on_pshBtn_StopCmd_clicked();
        }
        if(MSG.firstChildElement().tagName()=="OCR_COMMAND_REPLY" && m_rbtn == 2)
        {
            m_rbtn=0;
            on_pshBtn_StopCmd_clicked();
        }

    }
}
//=======Generating status and command list==============================================
//=======Generating status and command list==============================================
//=======Generating status and command list==============================================
QList<QString> CSSOpertion::generate_status_list()
{
    QList<QString>Status_value;
    Status_value << QString::number(status_msgId++);
    QString value;
    QSettings settings("Crane","Status");
    settings.beginGroup(GROUPSTATUS);
    QStringList StrLstsize = settings.allKeys();
    //qDebug() << "StrLstsize==" << StrLstsize.length();
    if(StrLstsize.size() == NO_STATUS_PARAMETERS)
    {
        for(int i=0; i < StrLstsize.length();i++)
        {
            value = settings.value(QString::number(i)).toString();
            Status_value << value;
        }
    }
    else
    {
        Status_value += {"String","10.00","10.00","10.00","10.00","10.00","10.00","20","10.00","1","Open","1","1","1","1","10.00","10.00","10.00","20","PICK",
                "String","String","20","20","INTERNAL","20","10.00","10.00","10.00"};
    }
    //qDebug() << "Status_value" << Status_value;
    settings.endGroup();
    return Status_value;
}
QList<QString> CSSOpertion::generate_command_list()
{
    QList<QString> Status_cmdvalue;
    Status_cmdvalue << QString::number(command_msgId++);
    QString value;
    QSettings settings_cmd("Crane","Commands");
    settings_cmd.beginGroup(GROUPCOMMAND);
    QStringList StrLstsize = settings_cmd.allKeys();
    //qDebug()<<settings_cmd.allKeys();
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

// ====Generating status and command XML == OCR Status,Command Reply,Event Response XML=====
// ====Generating status and command XML == OCR Status,Command Reply,Event Response XML=====
// ====Generating status and command XML == OCR Status,Command Reply,Event Response XML=====
QString CSSOpertion::generate_status_xml(QList<QString> data)
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
QString CSSOpertion::generate_command_xml(QList<QString> data)
{
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


QString CSSOpertion::generate_ocrstatus_xml(QList<QString> status_list)
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
QString CSSOpertion::generate_command_replay_xml(QList<QString> command_replay_list)
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
    QDomElement err =command_replay.createElement("ERROR");
    err.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CRANE_EVENT.appendChild(err);
    QDomElement ERROR_MSG=command_replay.createElement("ERROR_MSG");
    ERROR_MSG.appendChild(command_replay.createTextNode(command_replay_list[index++]));
    CRANE_EVENT.appendChild(ERROR_MSG);
    CRANE_EVENTS.appendChild(CRANE_EVENT);
    CR_COMMAND_REPLY.appendChild(CRANE_EVENTS);
    return command_replay.toString();
}
QString CSSOpertion::generate_event_response_xml(QList<QString> parameters,QList<QString> data)
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
void CSSOpertion::on_pshBtn_SimulateAction_clicked()
{
    ui->pshBtn_SimulateAction->setEnabled(false);
    ui->pshBtn_Run->setEnabled(false);
    m_socket_tcp->close();
    m_SimulateAction = new SimulateAction(strIPAddress,strIPPort);
    // m_SimulateAction->on_pshBtn_ClearLog_clicked();
    QObject::connect(m_SimulateAction, SIGNAL(simulationEnds()), this, SLOT(simulationEnds()));
    m_SimulateAction->show();
    m_SimulateAction->activateWindow();

    //    QString filename = qApp->applicationDirPath()+"/"+ui->cmbx_Action->currentText().trimmed()+".csv";
    //    QFile inputFile(filename);
    //    inputFile.open(QIODevice::ReadOnly|QIODevice::Text);
    //    QTextStream instream;
    //    instream.setDevice(&inputFile);
    //    action_data = instream.readAll().split("\n");
    //    //qDebug()<<"count"<<action_data.count();
    //    // qDebug()<<"last element"<<action_data[21];
    //    inputFile.close();
    //    action_index=0;
    //    t_action_command1.start(600);
    //    t_action_status.start(400);
}

//void CSSOpertion::send_action_status()
//{
//    QList<QString> t;
//    if(action_index==action_data.size()-3)
//    {
//        t_action_command2.start(200);
//    }
//    if(action_index < action_data.size()){
//        //qDebug()<<"connecton came"<<action_data[action_index];
//        QString line = action_data[action_index];
//        action_index++;
//        t = line.split(",");
//        if(t.length() == 29)
//        {
//            const QDateTime dateTime = QDateTime::currentDateTime();
//            time_stamp = dateTime.toString("dd-MM-yyyy hh:mm:ss.zzz");
//            QString time_s = dateTime.toString("yyyyMMddhhmmsszzz");
//            t.insert(0,QString::number(status_msgId++));
//            t.insert(1,time_s);

//            QString xmlstatus = generate_status_xml(t);


//            int num = i++;
//            QByteArray Total_StatusMsg;
//            Total_StatusMsg.append(0x02);
//            Total_StatusMsg.append(xmlstatus.toUtf8());
//            Total_StatusMsg.append(0x03);

//            m_socket_tcp->write(Total_StatusMsg);
//            QString sNoF = time_stamp + "#" + "Crane Status sent to OCR " +"\n";

//            //===============================================================================
//            QTreeWidgetItem *widgetItem;
//            ui->treeWidget_log->setSelectionMode(QAbstractItemView::SingleSelection);
//            ui->treeWidget_log->setColumnCount(1);

//            if(statusLog == true)
//            {
//                //qDebug() << "statusLog==" << statusLog;
//                StrLst_xmlData.append(t);
//                widgetItem = new QTreeWidgetItem(ui->treeWidget_log);
//                widgetItem->setTextAlignment(0, Qt::AlignLeft | Qt::AlignBottom);
//                widgetItem->setText(0, sNoF);
//                widgetItem->setToolTip(0, sNoF);
//                ui->treeWidget_log->insertTopLevelItem(num, widgetItem);
//            }
//        }
//    }
//    else{
//        t_action_status.stop();
//        ui->pshBtn_SimulateAction->setEnabled(true);
//    }
//}

//status = time_stamp + "#" + "Event response recieved from OCR " +"\n";
//QDomElement OCR_EVENT_RESPONSE=MSG.elementsByTagName("OCR_EVENT_RESPONSE").at(0).toElement();
//list.append(OCR_EVENT_RESPONSE.elementsByTagName("CRANE_ID").at(0).firstChild().nodeValue());

//QDomElement CRANE_EVENT=OCR_EVENT_RESPONSE.elementsByTagName("CRANE_EVENT").at(0).toElement();
//list.append(CRANE_EVENT.elementsByTagName("EVENT_ID").at(0).firstChild().nodeValue());
//list.append(CRANE_EVENT.elementsByTagName("CMD_ID").at(0).firstChild().nodeValue());

//QDomElement EVENT=OCR_EVENT_RESPONSE.elementsByTagName("EVENT").at(0).toElement();
//list.append(EVENT.elementsByTagName("EVENTNUMBER").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("SUPPLEMENTARY").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("CHECKPOINT").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("SPEED").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("LENGTH").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("UNITDETECTED").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("TRAILERDETECTED").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("DAMAGEDETECTED").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("BUNDLEDETECTED").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("TRUCKLIFTDETECTED").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("TOPTWISTLOCKDETECTED").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("BOTTOMWISTLOCKDETECTED").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("RADIATIONDETECTED").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("HOISTSTART").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("TROLLEYSTART").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("HOISTSTOP").at(0).firstChild().nodeValue());
//list.append(EVENT.elementsByTagName("TROLLEYSTOP").at(0).firstChild().nodeValue());

//QDomElement DATE=OCR_EVENT_RESPONSE.elementsByTagName("DATE").at(0).toElement();
//list.append(DATE.elementsByTagName("YEAR").at(0).firstChild().nodeValue());
//list.append(DATE.elementsByTagName("MONTH").at(0).firstChild().nodeValue());
//list.append(DATE.elementsByTagName("DAY").at(0).firstChild().nodeValue());
//list.append(DATE.elementsByTagName("HOUR").at(0).firstChild().nodeValue());
//list.append(DATE.elementsByTagName("MINUTE").at(0).firstChild().nodeValue());
//list.append(DATE.elementsByTagName("SECOND").at(0).firstChild().nodeValue());
//QDomElement CONTAINER=EVENT.elementsByTagName("CONTAINERS").at(0).toElement().elementsByTagName("CONTAINER").at(0).toElement();
//list.append(CONTAINER.elementsByTagName("ORDINAL").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("CONFIDENCE").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("CAMERA").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("ULC").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("ULR").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("LRC").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("LRR").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("IDENTIFICATION").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("ISOCODE").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("ISOCODECONFIDENCE").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("DOORTYPE").at(0).firstChild().nodeValue());
//list.append(CONTAINER.elementsByTagName("TIMESTAMP").at(0).firstChild().nodeValue());
