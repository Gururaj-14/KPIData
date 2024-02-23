#ifndef DEFINEACTION_H
#define DEFINEACTION_H

#include <QWidget>
#include <QtWidgets>
#include <QLineEdit>
#include <QMap>
#include <QDomDocument>
namespace Ui {
class DefineAction;
}

class DefineAction : public QWidget
{
    Q_OBJECT

public:
    explicit DefineAction(QWidget *parent = nullptr);
    ~DefineAction();
    QMap<QString,QStringList> mapCSPRE,mapCSIDE,mapCDOOR,mapITRUCK,mapETRUCK,mapETLPR,mapLIPRV,mapBOTWL,mapCDMG,mapCSEAL;
    QStringList strList_EventIDs;
    QLineEdit *m_timeForActions;
    QCheckBox *m_cmbxActions;
    void LoadAvailableXmlFiles();
    int rowval;
    QStringList strlstHeader;
    void closeEvent(QCloseEvent *event);
    QWidget *groupWidget,*saveWidget;
    QLineEdit *lEdt;
    void fillDefaluts();
    QCheckBox *chk;
    QLineEdit *ledt;
    QWidget *w;
    QList<QString> lst_responseName;
    QStringList values;
    QString generate_event_response_xml(QList<QString>,QList<QString>);
    QList<QStringList> lst_responseValue;

    QList<QString> m_cspre_event_response_display_parameters={"<OCR_EVENT_RESPONSE>","<EVENT>","EVENTNUMBER","SUPPLEMENTARY","<CHECKPOINT>","ID","NAME","</CHECKPOINT>","<CONTAINERS>","<CONTAINER>",
                                                            "ORDINAL","IDENTIFICATION","ISOCODE","IDENTCONFIDENCE","ISOCONFIDENCE","</CONTAINER>","</CONTAINERS>","</EVENT>","</OCR_EVENT_RESPONSE>"};

    QList<QString> m_cspre_event_response_total_parameters={"<OCR_EVENT_RESPONSE>","CRANE_ID","<CRANE_EVENT>","EVENT_ID","CMD_ID","</CRANE_EVENT>","<EVENT>","EVENTNUMBER","SUPPLEMENTARY","<CHECKPOINT>","ID","NAME","</CHECKPOINT>",
                                                            "<DATE>","YEAR","MONTH","DAY","HOUR","MINUTE","SECOND","</DATE>","<CONTAINERS>","<CONTAINER>",
                                                            "ORDINAL","IDENTIFICATION","ISOCODE","IDENTCONFIDENCE","ISOCONFIDENCE","</CONTAINER>","</CONTAINERS>","</EVENT>","</OCR_EVENT_RESPONSE>"};

    QList<QString> m_botwl_event_response_display_parameters={"<OCR_EVENT_RESPONSE>","<EVENT>","EVENTNUMBER","<CHECKPOINT>","ID","NAME","</CHECKPOINT>","<VISUALRESULTS>","<VISUALRESULT>",
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
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_pshBtn_DefineAction_clicked();
    void on_pshBtn_Save_clicked();

public slots:
    void saveGroupWidget();
    void closeGroupWidget();

signals:
    void AddAction(QString Action);
    void closeWindow();

private:
    Ui::DefineAction *ui;
};

#endif // DEFINEACTION_H
