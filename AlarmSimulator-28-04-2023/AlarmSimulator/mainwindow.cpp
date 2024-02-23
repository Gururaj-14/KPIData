#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "QStandardItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMinimumWidth(770);
    this->setMinimumHeight(600);
    this->setMaximumWidth(770);
    this->setMaximumHeight(600);

    ui->treeWidget->setHeaderHidden(true);
    ui->treeWidget->setAlternatingRowColors(true);
    ui->treeWidget->setFocusPolicy(Qt::NoFocus);
    ui->treeWidget->setStyleSheet("QTreeWidget{alternate-background-color: lightGray;background: White;}");

    ui->pushButton_2->setDisabled(true);
    ui->textEdit->setReadOnly(true);

    connect(&m_timer, &QTimer::timeout, this, &MainWindow::send_data, Qt::DirectConnection);


    QRegularExpression rx("([0-9]{1,3}[.]){3}[0-9]{1,3}");
    QValidator *validator = new QRegularExpressionValidator(rx);
    ui->Ipadress->setValidator(validator);
    ui->Ipadress->setText("192.168.1.82");

    QRegularExpression rx1("[0-9]{1,5}");
    QValidator *validator1 = new QRegularExpressionValidator(rx1);
    ui->port->setValidator(validator1);
    ui->port->setText("5679");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text()=="Disconnect")
    {
        m_udp_socket.disconnectFromHost();
        ui->port->setDisabled(false);
        ui->Ipadress->setDisabled(false);
        ui->pushButton_2->setDisabled(true);
        ui->pushButton->setText("Connect");
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        ui->textEdit->clear();
        ui->message_count->clear();
        m_message_count=0;
        ui->textEdit->clear();
    }
    else
    {
        m_udp_socket.connectToHost(ui->Ipadress->text(),ui->port->text().toInt());
        if(m_udp_socket.state()==QAbstractSocket::ConnectedState)
        {
            ui->port->setDisabled(true);
            ui->Ipadress->setDisabled(true);
            ui->pushButton_2->setDisabled(false);
            ui->pushButton->setText("Disconnect");
            ui->comboBox->addItems({"640","1280"});
            ui->comboBox_2->addItems({"10","20","30","100","300","500","1000","2000","5000"});
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    m_alarms = index==1?1280:(index==0?640:0);
    ui->treeWidget->clear();
    m_byte_array.clear();
    m_empty_byte_array.clear();
    for(int i=1;i<=m_alarms;i++)
    {
        QTreeWidgetItem* item=new QTreeWidgetItem();
        item->setText(0,QString::number(i));
        item->setCheckState(0,Qt::Unchecked);
        ui->treeWidget->addTopLevelItem(item);
        if(i%8==0)
        {
            m_byte_array.append(qint8(0));
            m_empty_byte_array.append(qint8(0));
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text()=="Stop Sending")
    {
        ui->comboBox->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->pushButton->setEnabled(true);
        m_timer.stop();
        ui->pushButton_2->setText("Start Sending");
    }
    else if(ui->pushButton_2->text()=="Start Sending")
    {
        ui->comboBox->setEnabled(false);
        ui->comboBox_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        m_timer.start(m_time_interval);
        if(m_time_interval>=2000)
        {
            m_packets_with_on=5;
        }
        else
        {
            m_packets_with_on=2000/m_time_interval;
        }
        m_packtes_with_off=0;
        ui->pushButton_2->setText("Stop Sending");
    }
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(item->checkState(column)==Qt::Checked)
        item->setCheckState(column,Qt::Unchecked);
    else
        item->setCheckState(column,Qt::Checked);
}

void MainWindow::on_treeWidget_itemChanged(QTreeWidgetItem *item, int column)
{
    if(item->checkState(column)==Qt::Checked)
    {
        int alarm = item->text(0).toInt()-1;
        m_map[alarm+1]=QDateTime::currentDateTime().toString();
        int bit=alarm%8;
        int byte=alarm/8;
        qint8 current=m_byte_array[byte];
        current=qint8(current|(1<<bit));
        m_byte_array[byte]=current;
        qDebug()<<"Byte : "<<byte+1<<"  Bit : "<<bit+1;
        unsigned char s=m_byte_array[byte];
        qDebug() << "Status "<<byte+1<<":"<< QString("%1").arg(s, 8, 2, QChar('0'));
    }
    else{
        ui->textEdit->append("Alarm : "+item->text(0)+"\n   Start Time: "+m_map[item->text(0).toInt()]+
                "\n   Stop Time : "+QDateTime::currentDateTime().toString());

        int alarm = item->text(0).toInt()-1;
        int bit=alarm%8;
        int byte=alarm/8;
        qint8 current=m_byte_array[byte];
        current=qint8(current&~(1<<bit));
        m_byte_array[byte]=current;
        unsigned char s=m_byte_array[byte];
        qDebug()<<"Byte : "<<byte+1<<"  Bit : "<<bit+1;
        qDebug() << "Status1:" << QString("%1").arg(s, 8, 2, QChar('0'));
    }
}
void MainWindow::send_data()
{
    m_message_count++;
    if(m_packets_with_on>=m_packtes_with_off)
    {
        m_udp_socket.write(m_byte_array);
        m_packtes_with_off++;
    }
    else if(m_packtes_with_off==m_packets_with_on*2)
    {
        m_udp_socket.write(m_empty_byte_array);
        m_packtes_with_off=0;
    }
    else if(m_packtes_with_off>m_packets_with_on)
    {
        m_udp_socket.write(m_empty_byte_array);
        m_packtes_with_off++;
    }
    qDebug()<<m_packets_with_on;
    //m_udp_socket.write(m_byte_array);
    for(int i=0;i<5;i++)
        qDebug()<< QString::number(m_byte_array[i],10);
    ui->message_count->setText("Sent Data Count : "+QString::number(m_message_count));
}


void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    m_time_interval=arg1.toInt();
}
