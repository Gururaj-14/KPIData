/*
FileName	:version
Purpose     :This Files is used to CCS Simulation.
Authour     :Gururaj B M / Kasturi Rangan / Harsha.
*/
#ifndef CSSOPERTION_H
#define CSSOPERTION_H

#include <QWidget>
#include <QtWidgets>
#include <settings.h>
#include <version.h>
#include <defineaction.h>
#include <QHostAddress>
#include <QMessageBox>
#include <QTcpSocket>
#include <QTimer>
#include <QDomDocument>
#include <QDebug>
#include <QFile>
#include <QUdpSocket>
#include <QRandomGenerator>
#include <QObject>
#include <QDateTime>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QSettings>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QCloseEvent>
#include <simulateaction.h>

QT_BEGIN_NAMESPACE
namespace Ui { class CSSOpertion; }
QT_END_NAMESPACE

class CSSOpertion : public QWidget
{
    Q_OBJECT

public:
    CSSOpertion(QWidget *parent = nullptr);
    ~CSSOpertion();

    QTcpSocket *m_socket_tcp;
    int m_rbtn = 0;
    settings *m_settings;
    DefineAction *m_DefineAction;
    SimulateAction *m_SimulateAction;
    bool bFlag;
    bool checked = true;
    bool CheckIPAddress(QString strIPAddress,QString strIPPort);
    int m_event,i=0;
    void ReloadLastSelectedIPs();
    void DisableWidgets();
    void EnableWidgets();
    QString SelectedLog;
    QString filePath;
    bool status = false,statusLog = false;
    QString FnlTime;
    QString time_stamp;
    QList<QString> generate_status_list();
    QList<QString> generate_command_list();
    QString generate_status_xml(QList<QString>);
    QString generate_command_xml(QList<QString>);
    QString generate_ocrstatus_xml(QList<QString>);
    QString generate_command_replay_xml(QList<QString>);
    QString generate_event_response_xml(QList<QString>,QList<QString>);
    QList <QStringList> StrLst_xmlData;
    int status_msgId = 1;
    int command_msgId = 1;
    void FillOCRStatusAttributes();
    QStringList strLst_OCRStatusParam;
    void closeEvent(QCloseEvent *event);
    QStringList strList_EventIDs;
    QStringList strLIst_EventDesc;
    QString strIPAddress, strIPPort;
    //    //=============Actions==========
    //    QTimer t_action_status,t_action_command1,t_action_command2;
    //    QList<QString> action_data;
    //    int action_index;

public slots:
    //void AddAction(QString Action);
    void simulationEnds();
    // void send_action_status();

private slots:
    void readMessage();
    void send_status();
    void on_psbtn_settings_clicked();
    void on_pshBtn_Run_clicked();
    void on_pshBtn_StartCmd_clicked();
    void on_pshBtn_Test_clicked();
    void on_treeWidget_log_itemClicked(QTreeWidgetItem *item, int column);
    void on_pshBtn_Set_clicked();
    void on_chckBx_LogFile_clicked(bool checked);
    void on_pshBtn_StopCmd_clicked();
    void on_pshBtn_ClearLog_clicked();
    void on_chckBx_LogStatus_clicked(bool checked);
    void on_pshBtn_DefineAction_clicked();
    void on_pshBtn_SimulateAction_clicked();

private:
    Ui::CSSOpertion *ui;
    QTimer *timer_CraneStatus;

//================================parametes_defination===========================
//CRANE STATUS,CRANE COMMAND, OCR COMMAND REPLAY
QList<QString> m_crane_status_parametes={"<CRANE_STATUS>","CRANE_ID","<GANTRY>","LOCATION","SPEED","</GANTRY>","<TROLLEY>","LOCATION","SPEED","</TROLLEY>","<SPREADER>","LOCATION","SPEED","SPREADER_TRIM","SIZE","LOAD","LANDED","TWL_STATE",
"TWIN_CAPABLE","TWIN_FRONT","TWIN_BACK","</SPREADER>","<TRUCK>","TRUCK_PRESENT","TRUCK_REAR_POS","TRUCK_FRONT_POS","</TRUCK>","CONTAINER_TOP_HEIGHT","<JOB>","ID","OPERATION","CONTAINER_ID","<TRUCK>","ID","SECTION_NUMBER","TYPE","SUB_TYPE","</TRUCK>",
"<TARGET>","GANTRY_LOCATION","TROLLEY_LOCATION","HEIGHT","</TARGET>","</JOB>","</CRANE_STATUS>"};

QList<QString> m_crane_command_parametes={"<CRANE_COMMAND>","CRANE_ID","<CRANE_EVENTS>","<CRANE_EVENT>","CMD_ID","EVENT_ID","DESC","ACTION","JOB","<TRUCK>","TRUCK_TYPE","TRUCK_ID","DIRECTION","</TRUCK>","<CONTAINER>","CONTAINER_ID",
                                          "CONTAINER_ISO","CONTAINER_WIDTH","</CONTAINER>","</CRANE_EVENT>","</CRANE_EVENTS>","</CRANE_COMMAND>"};


QList<QString> m_cspre_event_response_total_parameters={"<OCR_EVENT_RESPONSE>","CRANE_ID","<CRANE_EVENT>","EVENT_ID","CMD_ID","</CRANE_EVENT>","<EVENT>","EVENTNUMBER","SUPPLEMENTARY","<CHECKPOINT>","ID","NAME","</CHECKPOINT>",
                                                        "<DATE>","YEAR","MONTH","DAY","HOUR","MINUTE","SECOND","</DATE>","<CONTAINERS>","<CONTAINER>",
                                                        "ORDINAL","IDENTIFICATION","ISOCODE","IDENTCONFIDENCE","ISOCONFIDENCE","</CONTAINER>","</CONTAINERS>","</EVENT>","</OCR_EVENT_RESPONSE>"};

QList<QString> m_botwl_event_response_total_parameters={"<OCR_EVENT_RESPONSE>","CRANE_ID","<CRANE_EVENT>","EVENT_ID","CMD_ID","</CRANE_EVENT>","<EVENT>","EVENTNUMBER","<CHECKPOINT>","ID",
                                                        "NAME","</CHECKPOINT>","<DATE>","YEAR","MONTH","DAY","HOUR","MINUTE","SECOND","</DATE>","<VISUALRESULTS>","<VISUALRESULT>",
                                                        "TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "<VISUALRESULT>","TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "<VISUALRESULT>","TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "<VISUALRESULT>","TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "<VISUALRESULT>","TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "<VISUALRESULT>","TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "<VISUALRESULT>","TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "<VISUALRESULT>","TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "<VISUALRESULT>","TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "<VISUALRESULT>","TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "<VISUALRESULT>","TYPE","RESULT","EVENTNUMBER","CAMERA","IMAGENUMBER","ULC","ULR","LRC","LRR","CONFIDENCE","</VISUALRESULT>",
                                                        "</VISUALRESULTS>","</EVENT>","</OCR_EVENT_RESPONSE>"};

};
#endif // CSSOPERTION_H
