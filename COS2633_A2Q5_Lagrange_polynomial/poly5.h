#ifndef POLY5_H
#define POLY5_H
#include <iostream>
#include "poly1.h"
#include "poly4.h"
#include <math.h>


class Poly5
{
public:
    Poly5();
    Poly5(const Poly4 & p4_1, const Poly1 & p1_1);
    void print();
    double a, b, c, d, e, f;
    double f_x; //the known value of f at x
    double denominator;
    double eval(double x);
        //evaluates the polynomial at x
};

#endif // POLY5_H
