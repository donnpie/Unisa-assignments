#include "mainwindow.h"
#include <QApplication>
#include "referencemodel.h"
#include <QDebug>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(nullptr, new ReferenceModel);
    w.show();
    return a.exec();
}
