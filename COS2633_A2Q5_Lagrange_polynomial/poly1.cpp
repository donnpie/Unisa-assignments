#include "poly1.h"

Poly1::Poly1() : a(0), b(0)
{}

Poly1::Poly1(double a, double b) : a(a), b(b)
{}

void Poly1::print()
{
    if (b < 0)
        std::cout << a << ".x " << b << std::endl;
    else {
        std::cout << a << ".x + " << b << std::endl;
    }
}

void Poly1::seta(double a)
{
    this->a = a;
}
