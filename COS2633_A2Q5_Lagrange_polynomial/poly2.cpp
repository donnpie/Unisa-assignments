#include "poly2.h"


Poly2::Poly2()
{

}

Poly2::Poly2(const Poly1 &p1_1, const Poly1 &p1_2)
{
    this->a = p1_1.a*p1_2.a;
    this->b = p1_1.a*p1_2.b + p1_1.b*p1_2.a;
    this->c = p1_1.b*p1_2.b;
}

void Poly2::print()
{
    if (b < 0)
        std::cout << a << ".x^2 " << b << ".x ";
    else {
        std::cout << a << ".x^2 + " << b << ".x ";
    }
    if (c < 0)
        std::cout << c << std::endl;
    else {
        std::cout << " + " << c << std::endl;
    }
}

