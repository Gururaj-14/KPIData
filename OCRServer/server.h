/*
FileName	:version
Purpose     :This Files is used to server connections.
Authour     :Gururaj B M / Kasturi Rangan.
*/
#ifndef SERVER_H
#define SERVER_H

#include <version.h>
#include <defineaction.h>
#include <QWidget>
#include <QtWidgets>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostAddress>
#include <QMessageBox>
#include <QTimer>
#include <QDomDocument>
#include <QCloseEvent>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class server; }
QT_END_NAMESPACE

class server : public QWidget
{
    Q_OBJECT

public:
    server(QWidget *parent = nullptr);
    ~server();
    DefineAction *m_dActions;
    QTimer m_event_timer;
    bool m_event_status = false;
    QString m_event = "", m_event_cmd_id = "",m_crane_id="";
    QList<QString> read_crane_command(QString);
    void send_event_responce();
    void closeEvent(QCloseEvent *event);
    QCheckBox *m_chckBox;
    //================
    QString generate_status_xml(QList<QString>);
    QString generate_command_xml(QList<QString>);
    QString generate_command_replay_xml(QList<QString>);
    QString generate_ocrstatus_xml(QList<QString>);
    QString generate_event_response_xml(QList<QString>,QList<QString>);
    void addDefineActions();
    QComboBox *m_cmbxActions[10];
    QLineEdit *m_timeForActions[10];
    QStringList strList_EventIDs;
    bool status=false,statusLog=false;
    QString filePath;
    QList <QStringList> StrLst_xmlData;
    int i = 0;
    int m_event_number=1;


signals:

public slots:
    void AddAction(QString Action);
    void newConnection();
    void onReadyRead();
    void closeWindow();
     QList<QString> read_crane_status(QString);
     void on_treeWidget_log_itemClicked(QTreeWidgetItem *item, int column);

private slots:
   void on_chckBx_LogStatus_clicked(bool checked);
    void on_pshBtn_StartServer_clicked();
    void on_pshBtn_ClearLog_clicked();
    void on_pshBtn_DefineAction_clicked();
    void on_chckBx_LogFile_clicked(bool checked);
    // void on_pshBtn_StopServer_clicked();
    void on_pshBtn_Set_clicked();

private:
    QTcpServer *m_Tcpserver;
    QTcpSocket *m_Tcpsocket;
    Ui::server *ui;

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
#endif // SERVER_H
