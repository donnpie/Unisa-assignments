#include "poly1.h"

Poly1::Poly1() : a(0), b(0), leftBound(0), rightBound(0)
{}

Poly1::Poly1(double a, double b) : a(a), b(b), leftBound(0), rightBound(0)
{}

Poly1::Poly1(double a, double b, double lb, double rb) : a(a), b(b), leftBound(lb), rightBound(rb)
{}

double Poly1::firstDeriv()
{
    return b;
}

void Poly1::seta(double a)
{
    this->a = a;
}

void Poly1::setb(double b)
{
    this->b = b;
}

double Poly1::geta()
{
    return a;
}

double Poly1::getb()
{
    return b;
}



void Poly1::setBounds(double lb, double rb)
{
    leftBound = lb;
    rightBound = rb;
}

void Poly1::print()
{
    std::cout << a;
    if (b < 0)
        std::cout << " " << b << ".x" << std::endl;
    else
        std::cout << " + " << b <<  ".x" << std::endl;
}

double Poly1::eval(double x)
{
    return a+b*x;
}
