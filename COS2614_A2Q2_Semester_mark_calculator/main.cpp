//COS2614 Assignment 2 Question 2

#include "mainwindow.h"
#include <QApplication>
#include "mark.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

/*    //Test code for class Mark
    qDebug() << "Create a Mark object";
    Mark m(70, 80, 90, 60, 34, 33, 33, 60);
    m.print();

    qDebug() << "Try to set marks and weights that are out of range";
    m.setExamMark(200);
    m.setExamWeight(500);
    m.setAssignmentMark(101, 0);
    m.setAssignmentWeight(-1, 0);
    m.print();
*/

    MainWindow w;
    w.show();

    return a.exec();
}
