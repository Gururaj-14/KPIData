/*
FileName	:version
Purpose     :This Files is used to Simulation Actions.
Authour     :Gururaj B M / Kasturi Rangan / Harsha.
*/
#ifndef SIMULATEACTION_H
#define SIMULATEACTION_H

#include <QWidget>
#include <QtWidgets>
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

namespace Ui {
class SimulateAction;
}

class SimulateAction : public QWidget
{
    Q_OBJECT

public:
    explicit SimulateAction(const QString & strIp = QString(),
                            const QString & strPort = QString(),QWidget *parent = nullptr);
    ~SimulateAction();
    QString IPAddress,IPPort;
    QStringList strList_EventIDs,strLIst_EventDesc;
     void reLoadActions();
     void closeEvent(QCloseEvent *event);
    //=============Actions==========
    QTimer t_action_status,t_action_command1,t_action_command2;
    QList<QString> action_data;
    int action_index;
    QString time_stamp;
    int status_msgId = 1;
    int i = 0;
    int command_msgId = 1;

    QList<QString> generate_command_list();
    QTcpSocket *m_socket_tcp;
    QList <QStringList> StrLst_xmlData;

    QString generate_status_xml(QList<QString>);
    QString generate_command_xml(QList<QString> data);
    QString generate_ocrstatus_xml(QList<QString>);
    QString generate_command_replay_xml(QList<QString>);
    QString generate_event_response_xml(QList<QString>,QList<QString>);
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


public slots:
    void readMessage();
    void send_action_status();
    void StartCmd();
    void StopCmd();

public slots:
    void AddAction(QString Action);
    void on_pshBtn_ClearLog_clicked();

private slots:

    void on_treeWidget_log_itemClicked(QTreeWidgetItem *item, int column);

    void on_pshBtn_Run_clicked();

    void on_cmbx_Action_currentIndexChanged(int index);

signals:
    void simulationEnds();

private:
    Ui::SimulateAction *ui;
};

#endif // SIMULATEACTION_H
