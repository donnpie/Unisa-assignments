#include "poly2.h"

Poly2::Poly2() : Poly1 (0, 0, 0, 0), c(0)
{}

Poly2::Poly2(double a, double b, double c) : Poly1 (a, b), c(c)
{}

Poly2::Poly2(double a, double b, double c, double lb, double rb) : Poly1 (a, b, lb, rb), c(c)
{}

void Poly2::print()
{
    std::cout << a;
    if (b < 0)
        std::cout << " " << b << ".x";
    else
        std::cout << " + " << b <<  ".x";
    if (c < 0)
        std::cout << " " << c << ".x^2" << std::endl;
    else
        std::cout << " + " << c <<  ".x^2" << std::endl;
}

Poly1 Poly2::firstDeriv()
{
    return Poly1(b, 2*c);
}

double Poly2::secondDeriv()
{
    return 2*c;
}

void Poly2::setc(double c)
{
    this->c = c;
}

double Poly2::eval(double x)
{
    return a + b*x + c*x*x;
}


