#ifndef POLY3_H
#define POLY3_H
//An object that represents a polynomical of order 3 (cubic polynomial)
#include <iostream>
#include "poly1.h"
#include "poly2.h"

class Poly3 : public Poly2
{
public:
    Poly3();
    Poly3(double a, double b, double c, double d, double lb, double rb);
    double d; //coefficient for x^3
    void setd(double d);
    void print();
    Poly2 firstDeriv();
    Poly1 secondDeriv();
    //double thirdDeriv();
    double eval(double x);
};

#endif // POLY3_H
