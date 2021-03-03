#ifndef POLY2_H
#define POLY2_H
#include <iostream>
#include "poly1.h"


class Poly2
{
public:
    Poly2();
    Poly2(const Poly1 & p1_1, const Poly1 & p1_2);
    void print();
    double a, b, c;
};

#endif // POLY2_H
