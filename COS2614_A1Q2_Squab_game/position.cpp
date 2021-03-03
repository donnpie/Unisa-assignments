//position.cpp
//COS2614
//Assignment 1, Question 2
//Student: JJ Pienaar
//Student number: 44169086

#include "position.h"
#include <QtDebug>
#include <QString>

Position::Position() : x(0), y(0) {}
Position::Position(int x, int y) : x(x), y(y) {}

void Position::changePos(int x, int y)
{
    //qDebug() << "Start x position: " << QString::number(this->x) << '\n';
    this->x += x;
    //qDebug() << "End x position: " << QString::number(this->x) << '\n';
    //qDebug() << "Start y position: " << QString::number(this->y) << '\n';
    this->y += y;
    //qDebug() << "End y position: " << QString::number(this->y) << '\n';
}
int Position::getX() const
{
    return  x;
}
int Position::getY() const
{
    return this->y;
}
