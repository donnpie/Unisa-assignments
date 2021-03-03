#include "poly5.h"

Poly5::Poly5()
{

}

Poly5::Poly5(const Poly4 &p4_1, const Poly1 &p1_1)
{
    this->a = p4_1.a*p1_1.a;//x^5
    this->b = p4_1.a*p1_1.b + p4_1.b*p1_1.a;//x^4
    this->c = p4_1.b*p1_1.b + p4_1.c*p1_1.a; //x^3
    this->d = p4_1.c*p1_1.b + p4_1.d*p1_1.a;//x^2
    this->e = p4_1.d*p1_1.b + p4_1.e*p1_1.a;//x^1
    this->f = p4_1.e*p1_1.b;//x^0
}

void Poly5::print()
{
    if (b < 0)
        std::cout << a << ".x^5 " << b << ".x^4 ";
    else {
        std::cout << a << ".x^5 + " << b << ".x^4 ";
    }
    if (c < 0)
        std::cout << c << ".x^3 ";
    else {
        std::cout << " + " << c << ".x^3 ";
    }
    if (d < 0)
        std::cout << d << ".x^2 ";
    else {
        std::cout << " + " << d << ".x^2 ";
    }
    if (e < 0)
        std::cout << e << ".x ";
    else {
        std::cout << " + " << e << ".x ";
    }
    if (f < 0)
        std::cout << f << std::endl;
    else {
        std::cout << " + " << f << std::endl;
    }
}

double Poly5::eval(double x)
{
    double numerator = f_x*(a*pow(x, 5) + b*pow(x, 4) + c*pow(x, 3) + d*pow(x, 2) + e*x + f);
    return numerator/denominator;
}
