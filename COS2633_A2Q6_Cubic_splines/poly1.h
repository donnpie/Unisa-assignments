#ifndef POLY1_H
#define POLY1_H
//An object that represents a polynomical of order 1 (straigth line)
#include <iostream>


class Poly1
{
public:
    Poly1();
    Poly1(double a, double b);
    Poly1(double a, double b, double lb, double rb);
    double firstDeriv();
    void seta(double a);
    void setb(double b);
    double geta();
    double getb();
    void setBounds(double lb, double rb);
    void print();
    double eval(double x);
protected:
        double a, b, leftBound, rightBound;
};

#endif // POLY1_H
