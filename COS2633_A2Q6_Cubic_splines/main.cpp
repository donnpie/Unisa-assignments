#include <iostream>
#include "poly1.h"
#include "poly2.h"
#include "poly3.h"


int main()
{
    Poly1 p1_1(1, -1, 0, 5);
    std::cout << "First derivative: " << p1_1.firstDeriv() << std::endl;
    std::cout << "Evaluated at 2: " << p1_1.eval(2) << std::endl;
    p1_1.print();

    Poly2 p2_1(1, -1, 2, 0, 5);
    std::cout << "First derivative: ";
    p2_1.firstDeriv().print();
    std::cout << "Second derivative: " << p2_1.secondDeriv() << std::endl;
    p2_1.print();
    std::cout << "Evaluated at 2: " << p2_1.eval(2) << std::endl;

    Poly3 p3_1(1, -1, 2, 1, 0, 5);
    p3_1.print();
    std::cout << "First derivative: ";
    p3_1.firstDeriv().print();
    std::cout << "Second derivative: ";
    p3_1.secondDeriv().print();
    std::cout << "Evaluated at 2: " << p3_1.eval(2) << std::endl;

    return 0;
}
