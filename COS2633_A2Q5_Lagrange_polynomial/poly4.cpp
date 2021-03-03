#include "poly4.h"

Poly4::Poly4()
{

}

Poly4::Poly4(const Poly2 &p2_1, const Poly2 &p2_2)
{
    this->a = p2_1.a*p2_2.a;//x^4
    this->b = p2_1.a*p2_2.b + p2_1.b*p2_2.a;//x^3
    this->c = p2_1.a*p2_2.c + p2_1.c*p2_2.a + p2_1.b*p2_2.b;//x^2
    this->d = p2_1.b*p2_2.c + p2_1.c*p2_2.b;//x^1
    this->e = p2_1.c*p2_2.c;//x^0
}

void Poly4::print()
{
    if (b < 0)
        std::cout << a << ".x^4 " << b << ".x^3 ";
    else {
        std::cout << a << ".x^4 + " << b << ".x^3 ";
    }
    if (c < 0)
        std::cout << c << ".x^2 ";
    else {
        std::cout << " + " << c << ".x^2 ";
    }
    if (d < 0)
        std::cout << d << ".x ";
    else {
        std::cout << " + " << d << ".x ";
    }
    if (e < 0)
        std::cout << e << std::endl;
    else {
        std::cout << " + " << e << std::endl;
    }
}


