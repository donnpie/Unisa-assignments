#ifndef POLY4_H
#define POLY4_H
#include "poly1.h"
#include "poly2.h"

class Poly4
{
public:
    Poly4();
    Poly4(const Poly2 & p2_1, const Poly2 & p2_2);
    void print();
    double a, b, c, d, e;
};

#endif // POLY4_H
