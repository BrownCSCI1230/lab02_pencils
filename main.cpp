#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.canvasSetup(QCoreApplication::arguments().at(1).toStdString());
    w.show();
    return a.exec();
}
