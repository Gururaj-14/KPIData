#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QDialog>
#include <QUdpSocket>
#include <QTreeWidgetItem>
#include <QRegularExpression>
#include <QRegularExpressionValidator>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void send_data();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemChanged(QTreeWidgetItem *item, int column);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QUdpSocket m_udp_socket;
    QTimer m_timer;
    QByteArray m_byte_array;

    int m_alarms=0;
    int m_time_interval=0;
    int m_message_count=0;

    QMap <int,QString> m_map;

    int m_packets_with_on=10;
    int m_packtes_with_off=0;
    QByteArray m_empty_byte_array;
};
#endif // MAINWINDOW_H
