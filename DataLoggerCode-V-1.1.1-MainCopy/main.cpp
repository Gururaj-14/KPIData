/*
FileName	:main
Purpose     :This Files is used to SetUp the main application functionality.
Authour     :Gururaj B M
*/

#include "selection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Selection w;
    w.show();
    w.activateWindow();
    return a.exec();
}
