#include "addkpis.h"
#include "ui_addkpis.h"
#define GROUPSAVE "IP_PORT_GROUP_SAVE"
#define GROUP "IP_PORT_GROUP"
#define KEY "IP_key"
#define DEFAULT_IP_PORT "10.96.46.55:9876"
#define DEFAULT_PORT "9876"
ADDKPIS::ADDKPIS(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ADDKPIS)
{
    ui->setupUi(this);
    this->setWindowTitle("Key Performance Indicator - Definition");

    m_pingThread = new QThread();
    m_pingTimer = new QTimer();
    m_pingTimer->setInterval(10000);
    m_pingTimer->moveToThread(m_pingThread);

    connect(m_pingThread,SIGNAL(started()),m_pingTimer,SLOT(start()));
    connect(m_pingTimer,SIGNAL(timeout()),this,SLOT(CheckConnection()));

    ReloadDefaultIps();
    ReloadLastSelectedIPs();
}

ADDKPIS::~ADDKPIS()
{
    delete ui;
}

void ADDKPIS::ReloadDefaultIps()
{
    QSettings setting("Finecho_IP_Port_Save","IP_Port_Details_Save");
    setting.beginGroup(GROUPSAVE);
    foreach (const QString &key, setting.childKeys())
    {
        QString value = setting.value(key).toString();
        ui->comboBox_ConnectedIPs->addItem(value);
    }
    setting.endGroup();
}

void ADDKPIS::ReloadLastSelectedIPs()
{
    QSettings settings("Finecho_IP_Port","IP_Port_Details");
    settings.beginGroup(GROUP);
    QString value = settings.value(KEY).toString();
    ui->comboBox_ConnectedIPs->setCurrentText(value);
    QStringList strlst = value.split(':');
    int dSize = value.length();
    QString strIP,strPort;
    if(dSize > 0){
        strIP = strlst.at(0);
        strPort = strlst.at(1);
        ConnectToIp_Port(strIP,strPort);
    }
    else
    {
        strIP = "127.0.0.1";
        strPort = "6789";
        ConnectToIp_Port(strIP,strPort);
    }
    settings.endGroup();
}
void ADDKPIS::ConnectToIp_Port(QString strIP, QString strPort)
{
    strList_ParameterName.clear();
    strList_kpiId.clear();
    strList_kpiName.clear();
    strList_bitMask.clear();
    map_KpiID.clear();
    strList_CmbxParameterName.clear();
    socket = new QTcpSocket(this);
    socket->connectToHost(strIP, strPort.toInt());
    if(socket->waitForConnected(10000))
    {
        m_pingThread->exit();
        QSettings setting("Finecho_IP_Port_Save","IP_Port_Details_Save");
        setting.beginGroup(GROUPSAVE);
        int i=0;
        QStringList lst = setting.allKeys();
        if(lst.length() == 0)
        {
            setting.setValue(strIP, strIP+":"+strPort);
        }
        foreach (const QString &key, setting.childKeys())
        {
            int num = lst.length();
            QString value = setting.value(key).toString();
            if(value != strIP+":"+strPort )
            {
                i++;
            }
            if(num == i)
            {
                setting.setValue(strIP, strIP+":"+strPort);
            }
        }
        QStringList strlst;
        foreach (const QString &key, setting.childKeys())
        {
            QString value = setting.value(key).toString();
            strlst << value;
            ui->comboBox_ConnectedIPs->addItem(value);
        }
        strlst.removeDuplicates();

        ui->comboBox_ConnectedIPs->clear();
        ui->comboBox_ConnectedIPs->addItems(strlst);
        ui->comboBox_ConnectedIPs->setCurrentText(strIP+":"+strPort);
        setting.endGroup();

        ui->lbl_Connection->setStyleSheet("background-color:green;");
        ui->lbl_error_msg->setText("");
        //============================================
        socket->write("[{\"username\":\"sateesh\",\"passcode\":\"1234\",\"authkey\":\"abcd\",\"endpoint\":\"listKpi\"}]");
        socket->waitForBytesWritten(30000);

        QJsonParseError json_error;
        QByteArray data;

        int iBytes=0;
        int m;
        for(m=0; m<100; m++)
        {
            socket->waitForReadyRead(100);
            iBytes = socket->bytesAvailable();
            if (socket->state() != QAbstractSocket::ConnectedState)
                break;

            data += socket->readAll();
            usleep(50000);
        }
        QJsonDocument loadDoc(QJsonDocument::fromJson(data, &json_error));
        if (json_error.error != QJsonParseError::NoError)
        {
            QMessageBox msgBox;
            msgBox.setText("JSON parse error: " + json_error.errorString());
            msgBox.exec();

            ui->lbl_error_msg->setText("ERROR: " + json_error.errorString());
            ui->lbl_Connection->setStyleSheet("background-color:red;");
        }

        QJsonObject rootObj = loadDoc.object();
        QJsonArray fieldDefJSONArray = rootObj.value("field").toArray();

        QJsonValue fieldSet;
        QJsonObject fieldObj;

        for(int i=0; i< fieldDefJSONArray.size(); i++)
        {
            fieldSet = fieldDefJSONArray.at(i);
            fieldObj = fieldSet.toObject();

            strList_ParameterName << fieldObj.value("paramName").toString();
            strList_kpiId << fieldObj.value("kpiId").toString();
            strList_kpiName << fieldObj.value("kpiName").toString();
            strList_bitMask << fieldObj.value("bitMask").toString();

            map_KpiID.insert(fieldObj.value("paramName").toString(),fieldObj.value("kpiId").toString());
        }
        socket->close();
        //==================================================================
        socket->connectToHost(strIP, strPort.toInt());
        if(socket->waitForConnected(10000))
        {
            socket->write("[{\"username\":\"rushikesh\",\"passcode\":\"finecho@178\",\"authkey\":\"abcd\",\"endpoint\":\"listParams\"}]");
            socket->waitForBytesWritten(30000);

            QJsonParseError json_error_param;
            QByteArray data_param;

            int iBytes_param=0;
            int m_param;
            for(m_param=0; m_param<100; m_param++)
            {
                socket->waitForReadyRead(100);
                iBytes_param = socket->bytesAvailable();
                if (socket->state() != QAbstractSocket::ConnectedState)
                    break;

                data_param += socket->readAll();
                usleep(50000);
            }
            QJsonDocument loadDoc_param(QJsonDocument::fromJson(data_param, &json_error_param));
            if (json_error_param.error != QJsonParseError::NoError)
            {
//                QMessageBox msgBox;
//                msgBox.setText("JSON parse error: " + json_error_param.errorString());
//                msgBox.exec();

            }

            QJsonObject rootObj_param = loadDoc_param.object();
            QJsonArray fieldDefJSONArray_param = rootObj_param.value("field").toArray();

            QJsonValue fieldSet_param;
            QJsonObject fieldObj_param;

            for(int i=0; i< fieldDefJSONArray_param.size(); i++)
            {
                fieldSet_param = fieldDefJSONArray_param.at(i);
                fieldObj_param = fieldSet_param.toObject();

                strList_CmbxParameterName << fieldObj_param.value("paramName").toString();
            }
            //======================== close the connection
            socket->close();
        }
        //============================
        Str_IPAddress = strIP;
        Str_port = strPort;

        QSettings settings("Finecho_IP_Port","IP_Port_Details");
        settings.beginGroup(GROUP);
        settings.setValue(KEY, strIP+":"+strPort);
        settings.endGroup();

        socket1 = new QTcpSocket(this);
        if(socket1->state() == QAbstractSocket::UnconnectedState)
        {
            socket1->connectToHost(strIP, strPort.toInt());
        }
        m_pingThread->start();
    }
    else
    {
        m_pingThread->exit();
        QMessageBox msgBox;
        msgBox.setText("Error: " + socket->errorString() + "\nPlease Check connectivity to server");
        msgBox.exec();
        ui->lbl_error_msg->setText("ERROR: " + socket->errorString());
        ui->lbl_Connection->setStyleSheet("background-color:red;");
    }
    ui->comboBox_param->addItems(strList_CmbxParameterName);
    FillDataToTable();
}

void ADDKPIS::CheckConnection()
{
    if(socket1->state() == QAbstractSocket::UnconnectedState)
    {
        socket1->connectToHost(Str_IPAddress, Str_port.toInt());
    }
    if(socket1->state() == QAbstractSocket::ConnectedState)
    {
        ui->lbl_Connection->setStyleSheet("background-color:green;");
        ui->lbl_error_msg->setText("");
    }
    else
    {
        ui->lbl_Connection->setStyleSheet("background-color:red;");
        ui->lbl_error_msg->setText("Connection lost");
    }
}
void ADDKPIS::FillDataToTable()
{
    ui->tableWidget->setRowCount(0);
    int i=0;
    while(i < strList_ParameterName.length())
    {
        ui->tableWidget->insertRow(i);
        QTableWidgetItem *item;
        QString kpi_name = strList_kpiName.at(i);
        QString kpi_id = strList_kpiId.at(i);
        QString Parameter_name = strList_ParameterName.at(i);

        item = new QTableWidgetItem(kpi_name);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(i,0,item);

        item = new QTableWidgetItem(kpi_id);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(i,1,item);

        item = new QTableWidgetItem(Parameter_name);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(i,2,item);

        m_pushbtn = new QPushButton();
        m_pushbtn->setText("Edit");
        ui->tableWidget->setCellWidget(i,3,m_pushbtn);
        connect(m_pushbtn,SIGNAL(clicked()),this,SLOT(PushBtnEditClicked()));

        m_pushbtnDel = new QPushButton();
        m_pushbtnDel->setText("Delete");
        ui->tableWidget->setCellWidget(i,4,m_pushbtnDel);
        connect(m_pushbtnDel,SIGNAL(clicked()),this,SLOT(PushBtnDelClicked()));

        i++;
    }

}
void ADDKPIS::PushBtnEditClicked()
{
    groupWidget = new QWidget();
    groupWidget->setGeometry(250,250,400,150);
    groupWidget->setFixedSize(400,150);
    groupWidget->setWindowTitle("Save kpi name as...");

    QLabel *lb = new QLabel("Enter Kpi name");
    lEdt = new QLineEdit();

    QString str_Validator = "[0-9A-Za-z_ -]{0,30}";
    lEdt->setValidator(new QRegExpValidator(QRegExp(str_Validator)));
    lEdt->setFixedSize(200,30);

    QLabel *lb1 = new QLabel("Enter parameter name");
    cmbx = new QComboBox();
    cmbx->addItems(strList_CmbxParameterName);
    cmbx->setFixedSize(200,30);

    QHBoxLayout *HLayout = new QHBoxLayout();
    HLayout->addWidget(lb);
    HLayout->addWidget(lEdt);

    QHBoxLayout *HLayout1 = new QHBoxLayout();
    HLayout1->addWidget(lb1);
    HLayout1->addWidget(cmbx);

    okBtn = new QPushButton();
    okBtn->setFixedSize(100,30);
    okBtn->setText("Ok");
    connect(okBtn, SIGNAL(clicked()), this, SLOT(saveKpis()));

    cancelBtn = new QPushButton();
    cancelBtn->setFixedSize(100,30);
    cancelBtn->setText("Cancel");
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(closewnd()));

    QHBoxLayout *H1Layout = new QHBoxLayout();
    H1Layout->addWidget(okBtn);
    H1Layout->addWidget(cancelBtn);

    QVBoxLayout *VLayout = new QVBoxLayout();
    VLayout->addLayout(HLayout);
    VLayout->addLayout(HLayout1);
    VLayout->addLayout(H1Layout);

    groupWidget->setLayout(VLayout);
    groupWidget->show();
}

void ADDKPIS::PushBtnDelClicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void ADDKPIS::saveKpis()
{
    row1 = ui->tableWidget->currentRow();
    QString ldt_text = lEdt->text();
    QString cmbx_text = cmbx->currentText();

    //QString kpi_id =  map_KpiID.value(cmbx_text);
    QString kpi_id = ui->tableWidget->item(row1,1)->text();

    QJsonObject jsonKeys;
    QJsonArray jsonArray,plot_array;

    jsonKeys.insert("username","rushikesh");
    jsonKeys.insert("passcode","finecho@178");
    jsonKeys.insert("authkey","abcd");
    jsonKeys.insert("endpoint","editKpi");

    auto data1 = QJsonObject(
    {
                    qMakePair(QString("kpi_id"), QJsonValue(kpi_id)),
                    qMakePair(QString("kpi_name"), QJsonValue(ldt_text)),
                    qMakePair(QString("parameter_name"), QJsonValue(cmbx_text))
                });

    plot_array.push_back(QJsonValue(data1));
    jsonKeys.insert("params",QJsonValue(plot_array));
    jsonArray.append(jsonKeys);
    QByteArray data;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument(jsonArray);
    socket->connectToHost(Str_IPAddress,Str_port.toInt());
    if(socket->waitForConnected(10000))
    {
        socket->write(jsonDoc.toJson().constData());
        socket->waitForBytesWritten(30000);
        int iBytes=0;
        for(int m=0; m<100; m++)
        {
            socket->waitForReadyRead(1000);
            iBytes = socket->bytesAvailable();
            if(socket->state() != QAbstractSocket::ConnectedState)
                break;
            data += socket->readAll();
            usleep(50000);
        }
    }
    QJsonValue fieldSet;
    QJsonObject fieldObj;
    QJsonParseError json_error;
    QJsonDocument loadDoc(QJsonDocument::fromJson(data, &json_error));
    if (json_error.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON parse error: "<< json_error.errorString();
    }

    QJsonObject rootObj = loadDoc.object();
    QJsonArray fieldDefJSONArray = rootObj.value("field").toArray();
    QString result;
    QString Description;

    fieldSet = fieldDefJSONArray.at(0);
    fieldObj = fieldSet.toObject();
    result = fieldObj.value("result").toString();

    fieldSet = fieldDefJSONArray.at(1);
    fieldObj = fieldSet.toObject();
    Description = fieldObj.value("reason").toString();

    socket->close();

    if(result == "Success")
    {
        ui->tableWidget->item(row1,0)->setText(ldt_text);
        ui->tableWidget->item(row1,2)->setText(cmbx_text);
    }

    QString message = QString("Edit KPI: " + result + "\n" + Description);
    QMessageBox::information(this,"Result", message );
}

void ADDKPIS::closewnd()
{
    groupWidget->close();
}


void ADDKPIS::on_m_PshBtn_Add_clicked()
{
    QString kpi_name = ui->lineEdit_name->text();
    QString kpi_paramname = ui->comboBox_param->currentText();    QJsonObject jsonKeys;
    QJsonArray jsonArray,plot_array;

    jsonKeys.insert("username","rushikesh");
    jsonKeys.insert("passcode","finecho@178");
    jsonKeys.insert("authkey","abcd");
    jsonKeys.insert("endpoint","addKpi");

    auto data1 = QJsonObject(
    {
                    qMakePair(QString("kpi_name"), QJsonValue(kpi_name)),
                    qMakePair(QString("parameter_name"), QJsonValue(kpi_paramname))
                });

    plot_array.push_back(QJsonValue(data1));
    jsonKeys.insert("params",QJsonValue(plot_array));
    jsonArray.append(jsonKeys);
    QByteArray data;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument(jsonArray);
    socket->connectToHost(Str_IPAddress,Str_port.toInt());
    if(socket->waitForConnected(10000))
    {
        socket->write(jsonDoc.toJson().constData());
        socket->waitForBytesWritten(30000);
        int iBytes=0;
        for(int m=0; m<100; m++)
        {
            socket->waitForReadyRead(1000);
            iBytes = socket->bytesAvailable();
            if(socket->state() != QAbstractSocket::ConnectedState)
                break;
            data += socket->readAll();
            usleep(50000);
        }
    }
    QJsonValue fieldSet;
    QJsonObject fieldObj;
    QJsonParseError json_error;
    QJsonDocument loadDoc(QJsonDocument::fromJson(data, &json_error));
    if (json_error.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON parse error: "<< json_error.errorString();
    }

    QJsonObject rootObj = loadDoc.object();
    QJsonArray fieldDefJSONArray = rootObj.value("field").toArray();
    QString result;
    QString Description;

    fieldSet = fieldDefJSONArray.at(0);
    fieldObj = fieldSet.toObject();
    result = fieldObj.value("result").toString();

    fieldSet = fieldDefJSONArray.at(1);
    fieldObj = fieldSet.toObject();
    Description = fieldObj.value("reason").toString();

    socket->close();

    QString message = QString("Add KPI: " + result + "\n" + Description);
    QMessageBox::information(this,"Result", message );
    showAddKpis();
}

void ADDKPIS::on_pushButton_connect_clicked()
{
    QString strIPAddress, strIPPort, strIP;
    QStringList strParts;
    bool bFlag=false;

    strIP = ui->comboBox_ConnectedIPs->currentText();
    strParts = strIP.split(":");
    strIPAddress = strParts.at(0);
    if(strParts.count()<2)
        strIPPort = DEFAULT_PORT;
    else
        strIPPort = strParts.at(1);

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
            QMessageBox::information(this,"Warning","Not a Valid IP Address");
            bFlag= false;
        }
    }
    else
    {
        QMessageBox::information(this,"Warning","Not a Valid IP Address");
        bFlag= false;
    }

    if(bFlag==true)
    {
        if(ui->comboBox_ConnectedIPs->findText(strIP,Qt::MatchExactly) == -1)
        {
            //Save to local disk here
        }
        ConnectToIp_Port(strIPAddress,strIPPort);
    }
}

void ADDKPIS::on_comboBox_ConnectedIPs_currentTextChanged(const QString &arg1)
{
    clearWidgets();
    m_pingThread->exit();
    ui->lbl_Connection->setStyleSheet("background-color:red;");
}
void ADDKPIS::clearWidgets()
{
    ui->tableWidget->setRowCount(0);
}

void ADDKPIS::showAddKpis()
{
    strList_ParameterName.clear();
    strList_kpiId.clear();
    strList_kpiName.clear();
    strList_bitMask.clear();
    map_KpiID.clear();
    QJsonParseError json_error;
    QByteArray data;
    socket->connectToHost(Str_IPAddress,Str_port.toInt());
    if(socket->waitForConnected(10000))
    {
        socket->write("[{\"username\":\"sateesh\",\"passcode\":\"1234\",\"authkey\":\"abcd\",\"endpoint\":\"listKpi\"}]");
        socket->waitForBytesWritten(30000);

        int iBytes=0;
        int m;
        for(m=0; m<100; m++)
        {
            socket->waitForReadyRead(100);
            iBytes = socket->bytesAvailable();
            if (socket->state() != QAbstractSocket::ConnectedState)
                break;

            data += socket->readAll();
            usleep(50000);
        }
    }
    QJsonDocument loadDoc(QJsonDocument::fromJson(data, &json_error));
    if (json_error.error != QJsonParseError::NoError)
    {
        QMessageBox msgBox;
        msgBox.setText("JSON parse error: " + json_error.errorString());
        msgBox.exec();
    }

    QJsonObject rootObj = loadDoc.object();
    QJsonArray fieldDefJSONArray = rootObj.value("field").toArray();

    QJsonValue fieldSet;
    QJsonObject fieldObj;

    for(int i=0; i< fieldDefJSONArray.size(); i++)
    {
        fieldSet = fieldDefJSONArray.at(i);
        fieldObj = fieldSet.toObject();

        strList_ParameterName << fieldObj.value("paramName").toString();
        strList_kpiId << fieldObj.value("kpiId").toString();
        strList_kpiName << fieldObj.value("kpiName").toString();
        strList_bitMask << fieldObj.value("bitMask").toString();

        map_KpiID.insert(fieldObj.value("paramName").toString(),fieldObj.value("kpiId").toString());
    }
    socket->close();
    FillDataToTable();
}

void ADDKPIS::on_toolButton_Versions_clicked()
{
    m_appVersions = new AppVersions(Str_IPAddress,Str_port);
    m_appVersions->show();
    m_appVersions->activateWindow();
}
