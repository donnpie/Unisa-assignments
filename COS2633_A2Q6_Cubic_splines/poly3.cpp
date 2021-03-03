#include "poly3.h"

Poly3::Poly3() : Poly2(), d(0)
{}

Poly3::Poly3(double a, double b, double c, double d, double lb, double rb) : Poly2 (a, b, c, lb, rb), d(d)
{}

void Poly3::setd(double d)
{
    this->d = d;
}

void Poly3::print()
{
    std::cout << a;
    if (b < 0)
        std::cout << " " << b << ".x";
    else
        std::cout << " + " << b <<  ".x";
    if (c < 0)
        std::cout << " " << c << ".x^2";
    else
        std::cout << " + " << c <<  ".x^2";
    if (d < 0)
        std::cout << " " << d << ".x^3" << std::endl;
    else
        std::cout << " + " << d <<  ".x^3" << std::endl;
}

Poly2 Poly3::firstDeriv()
{
    return Poly2(b, 2*c, 3*d);
}

Poly1 Poly3::secondDeriv()
{
    return Poly1(2*c, 6*d);
}

double Poly3::eval(double x)
{
    return a + b*x + c*x*x + d*x*x*x;
}
