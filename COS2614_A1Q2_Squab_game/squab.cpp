//squab.cpp
//COS2614
//Assignment 1, Question 2
//Student: JJ Pienaar
//Student number: 44169086

#include "squab.h"
#include <QString>
#include <QtDebug>

Squab::Squab() : score(0), pos(new Position()) {}

Squab::Squab(int x, int y) : score(0), pos(new Position(x, y)) {}

Squab::Squab(const Squab & other) : score(other.score), pos(new Position(other.getPos().getX(), other.getPos().getY())) {}

void Squab::operator=(const Squab & other)
{
    score = other.score;
    *pos=Position(other.pos->getX(), other.pos->getY());
}

Squab::~Squab() {
    delete pos;
}

int Squab::getScore() const
{
    return score;
}

void Squab::incScore()
{
    ++score;
}

Position Squab::getPos() const
{
    return *pos;
}

void Squab::move(char dn, int de)
{
    switch (dn) {
    case 'n':
        pos->changePos(0, de);
        qDebug() << "Moving north..." << '\n';
        break;
    case 's':
        pos->changePos(0, -de);
        qDebug() << "Moving south..." << '\n';
        break;
    case 'e':
        pos->changePos(de, 0);
        qDebug() << "Moving east..." << '\n';
        break;
    case 'w':
        pos->changePos(-de, 0);
        qDebug() << "Moving west..." << '\n';
        break;
    }
    qDebug() << "After move position is: (" << QString::number(this->pos->getX()) << ", "
             << QString::number(this->pos->getY()) << ")" << '\n';
}

bool Squab::lineOfSight(Squab s) const
{
    bool isSameRow = false;
    bool isSameCol = false;
    if (this->pos->getX() == s.pos->getX())
        isSameRow = true;
    if (this->pos->getY() == s.pos->getY())
        isSameCol = true;
    return  (isSameRow || isSameCol);
}

Squab * Squab::clone() const
{
    Squab * newSquab = new Squab(this->pos->getX(), this->pos->getY());
    newSquab->score = this->score;
    return newSquab;
}
