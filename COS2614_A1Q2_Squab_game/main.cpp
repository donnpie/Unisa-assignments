//main.cpp
//COS2614
//Assignment 1, Question 2
//Student: JJ Pienaar
//Student number: 44169086

#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include "squab.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    qDebug() << "--- Test program for Squab class ---" << '\n';
    Squab s(5, 5);

    qDebug() << "Test 1 - Get score and inc score:" << '\n';
    for (int i = 0; i < 5; i++)
    {
        s.incScore();
        qDebug() << "Score: " << QString::number(s.getScore()) << '\n';
    }

    qDebug() << "-------------------------------" << '\n';
    qDebug() << "Test 2 - Get position and move:" << '\n';
    qDebug() << "Start position: (" << QString::number(s.getPos().getX()) << ", "
             << QString::number(s.getPos().getY()) << ")" << '\n';
    s.move('n', 2);
    s.move('e', 4);
    s.move('s', 3);
    s.move('w', 3);

    qDebug() << "-------------------------------" << '\n';
    qDebug() << "Test 3 - clone:" << '\n';
    Squab * sPtr1 = nullptr;
    Squab * sPtr2 = nullptr;
    sPtr1 = s.clone();
    sPtr2 = s.clone();
    qDebug() << "\tThe position of clone 1 is: (" << QString::number(sPtr1->getPos().getX()) << ", "
             << QString::number(sPtr1->getPos().getY()) << ")" << '\n';
    qDebug() << "\tThe score of clone 1 is: " << QString::number(sPtr1->getScore()) << '\n';
    qDebug() << "\tThe position of clone 2 is: (" << QString::number(sPtr2->getPos().getX()) << ", "
             << QString::number(sPtr2->getPos().getY()) << ")" << '\n';
    qDebug() << "\tThe score of clone 2 is: " << QString::number(sPtr2->getScore()) << '\n';
    //Move the original and test if the clone changed:
    s.move('e', 4);
    qDebug() << "\tThe position of clone 1 is: (" << QString::number(sPtr1->getPos().getX()) << ", "
             << QString::number(sPtr1->getPos().getY()) << ")" << '\n';

    qDebug() << "-------------------------------" << '\n';
    qDebug() << "Test 4 - Test line of sight:" << '\n';
    qDebug() << "Comparing positions of orignal and clone 1" << '\n';
    qDebug() << "\tThe position of original is: (" << QString::number(s.getPos().getX()) << ", "
             << QString::number(s.getPos().getY()) << ")" << '\n';
    qDebug() << "\tThe position of clone 1 is: (" << QString::number(sPtr1->getPos().getX()) << ", "
             << QString::number(sPtr1->getPos().getY()) << ")" << '\n';
    qDebug() << "Line of sight:" << s.lineOfSight(*sPtr1) << '\n';
    qDebug() << "Moving orignal..." << '\n';
    s.move('w', 3); //move w
    qDebug() << "Line of sight:" << s.lineOfSight(*sPtr1) << '\n';
    qDebug() << "Moving orignal..." << '\n';
    s.move('n', 3); //move n
    qDebug() << "Line of sight:" << s.lineOfSight(*sPtr1) << '\n';
    qDebug() << "Moving orignal..." << '\n';
    s.move('w', 1); //move e
    qDebug() << "Line of sight:" << s.lineOfSight(*sPtr1) << '\n';

    qDebug() << "-------------------------------" << '\n';
    qDebug() << "Test 5 - Test assignment operator:" << '\n';
    Squab s2; //create a new squab object
    qDebug() << "Values for new object before assignment:" << '\n';
    qDebug() << "\tThe position of new object is: (" << QString::number(s2.getPos().getX()) << ", "
             << QString::number(s2.getPos().getY()) << ")" << '\n';
    qDebug() << "\tThe score of new object is: " << QString::number(s2.getScore()) << '\n';
    s2 = s;
    qDebug() << "Values for new object after assignment:" << '\n';
    qDebug() << "\tThe position of new object is: (" << QString::number(s2.getPos().getX()) << ", "
             << QString::number(s2.getPos().getY()) << ")" << '\n';
    qDebug() << "\tThe score of new object is: " << QString::number(s2.getScore()) << '\n';
    s.move('w', 1); //change orinal and confirm that new has remain unchanged
    qDebug() << "Values for new object after original object was changed:" << '\n';
    qDebug() << "\tThe position of new object is: (" << QString::number(s2.getPos().getX()) << ", "
             << QString::number(s2.getPos().getY()) << ")" << '\n';
    qDebug() << "\tThe score of new object is: " << QString::number(s2.getScore()) << '\n';

    return 0;
    //return a.exec();


}
