#include <QtGui/QApplication>
#include "mainwindow.h"
#include "Custom/test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //default mainwindow...
    //MainWindow w;
    //w.show();

    //run engine...
    Test *test = new Test();

    return a.exec();
}
