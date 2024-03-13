#include "addkpis.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ADDKPIS w;
    w.show();
    return a.exec();
}
