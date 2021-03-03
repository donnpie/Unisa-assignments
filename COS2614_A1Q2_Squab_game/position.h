//position.h
//COS2614
//Assignment 1, Question 2
//Student: JJ Pienaar
//Student number: 44169086

#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
    Position();
    Position(int x, int y);
    void changePos(int x, int y);
        //Relative change to postition
    int getX() const;
    int getY() const;
private:
    int x;
    int y;
};

#endif // POSITION_H
