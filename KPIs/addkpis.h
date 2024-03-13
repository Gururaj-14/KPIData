#ifndef ADDKPIS_H
#define ADDKPIS_H

#include <QWidget>
#include <QTcpSocket>
#include <QMap>
#include <QJsonParseError>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <unistd.h>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QThread>
#include <QTimer>
#include <QSettings>
#include <QHostAddress>
#include <appversions.h>
QT_BEGIN_NAMESPACE
namespace Ui { class ADDKPIS; }
QT_END_NAMESPACE

class ADDKPIS : public QWidget
{
    Q_OBJECT

public:
    ADDKPIS(QWidget *parent = nullptr);
    ~ADDKPIS();
    QTcpSocket *socket,*socket1;
    AppVersions *m_appVersions;
    void FillDataToTable();
    QStringList strList_kpiId,strList_ParameterName,strList_CmbxParameterName,strList_kpiName,strList_bitMask,strList_offSet,strList_alramId;
    QPushButton *m_pushbtn,*m_pushbtnDel;
    QWidget *groupWidget,*saveWidget;
    QLineEdit *lEdt;
    QComboBox *cmbx;
    int row,col,row1,col1;
    QString str;
    QPushButton *okBtn,*cancelBtn;
    QThread *m_pingThread;
    QTimer *m_pingTimer;
    QString Str_IPAddress,Str_port;
    void ReloadDefaultIps();
    void ReloadLastSelectedIPs();
    void ConnectToIp_Port(QString,QString);
    void clearWidgets();
    void showAddKpis();
    QMap<QString,QString> map_KpiID;
private:
    Ui::ADDKPIS *ui;

public slots:
    void PushBtnEditClicked();
    void PushBtnDelClicked();
    void saveKpis();
    void closewnd();
    void CheckConnection();

private slots:
    void on_m_PshBtn_Add_clicked();
    void on_pushButton_connect_clicked();
    void on_comboBox_ConnectedIPs_currentTextChanged(const QString &arg1);
    void on_toolButton_Versions_clicked();
};
#endif // ADDKPIS_H
