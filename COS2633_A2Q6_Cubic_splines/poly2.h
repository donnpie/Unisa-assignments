#ifndef POLY2_H
#define POLY2_H
//An object that represents a polynomical of order 2 (parabola)
#include <iostream>
#include "poly1.h"

class Poly2 : public Poly1
{
public:
    Poly2();
    Poly2(double a, double b, double c);
    Poly2(double a, double b, double c, double lb, double rb);
    void print();
    Poly1 firstDeriv();
    double secondDeriv();
    void setc(double c);
    double eval(double x);
protected:
    double c; //coefficient for x^2
};

#endif // POLY2_H
