//squab.h
//COS2614
//Assignment 1, Question 2
//Student: JJ Pienaar
//Student number: 44169086

#ifndef SQUAB_H
#define SQUAB_H
#include "position.h"

class Squab
{
public:
    Squab();
    Squab(int x, int y);
    Squab(const Squab &); //copy constructor
    void operator=(const Squab & other); //Assignment operator
    ~Squab();
    int getScore() const;
    void incScore();
    Position getPos() const;
    void move(char dn, int de);
    bool lineOfSight(Squab s) const;
    Squab * clone() const;
private:
    int score;
    Position * pos;
};

#endif // SQUAB_H
