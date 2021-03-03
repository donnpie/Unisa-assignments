#include <iostream>
#include "poly1.h"
#include "poly2.h"
#include "poly4.h"
#include "poly5.h"

int main()
{


    std::cout << "L0(x): " << std::endl;
    Poly1 p1a_1(1, -1);
    Poly1 p1a_2(1, -2);
    Poly1 p1a_3(1, -3);
    Poly1 p1a_4(1, -4);
    Poly1 p1a_5(1, -5);

    p1a_1.print();
    p1a_2.print();
    p1a_3.print();
    p1a_4.print();
    p1a_5.print();

    Poly2 p2a_1(p1a_1, p1a_2);
    p2a_1.print();
    Poly2 p2a_2(p1a_3, p1a_4);
    p2a_2.print();

    Poly4 p4a_1(p2a_1, p2a_2);
    p4a_1.print();

    Poly5 p5a_1(p4a_1, p1a_5);
    p5a_1.print();
    p5a_1.denominator = -1*-2*-3*-4*-5;
    p5a_1.f_x = 1843318;
    std::cout << std::endl;

    std::cout << "L1(x): " << std::endl;
    Poly1 p1b_1(1, 0);
    Poly1 p1b_2(1, -2);
    Poly1 p1b_3(1, -3);
    Poly1 p1b_4(1, -4);
    Poly1 p1b_5(1, -5);

    p1b_1.print();
    p1b_2.print();
    p1b_3.print();
    p1b_4.print();
    p1b_5.print();

    Poly2 p2b_1(p1b_1, p1b_2);
    p2b_1.print();
    Poly2 p2b_2(p1b_3, p1b_4);
    p2b_2.print();

    Poly4 p4b_1(p2b_1, p2b_2);
    p4b_1.print();

    Poly5 p5b_1(p4b_1, p1b_5);
    p5b_1.print();
    p5b_1.denominator = -1*-2*-3*-4;
    p5b_1.f_x = 1863705;
    std::cout << std::endl;

    std::cout << "L2(x): " << std::endl;
    Poly1 p1c_1(1, 0);
    Poly1 p1c_2(1, -1);
    Poly1 p1c_3(1, -3);
    Poly1 p1c_4(1, -4);
    Poly1 p1c_5(1, -5);

    p1c_1.print();
    p1c_2.print();
    p1c_3.print();
    p1c_4.print();
    p1c_5.print();

    Poly2 p2c_1(p1c_1, p1c_2);
    p2c_1.print();
    Poly2 p2c_2(p1c_3, p1c_4);
    p2c_2.print();

    Poly4 p4c_1(p2c_1, p2c_2);
    p4c_1.print();

    Poly5 p5c_1(p4c_1, p1c_5);
    p5c_1.print();
    p5c_1.denominator = 2*-1*-2*-3;
    p5c_1.f_x = 1884627;
    std::cout << std::endl;

    std::cout << "L3(x): " << std::endl;
    Poly1 p1d_1(1, 0);
    Poly1 p1d_2(1, -1);
    Poly1 p1d_3(1, -2);
    Poly1 p1d_4(1, -4);
    Poly1 p1d_5(1, -5);

    p1d_1.print();
    p1d_2.print();
    p1d_3.print();
    p1d_4.print();
    p1d_5.print();

    Poly2 p2d_1(p1d_1, p1d_2);
    p2d_1.print();
    Poly2 p2d_2(p1d_3, p1d_4);
    p2d_2.print();

    Poly4 p4d_1(p2d_1, p2d_2);
    p4d_1.print();

    Poly5 p5d_1(p4d_1, p1d_5);
    p5d_1.print();
    p5d_1.denominator = 3*2*-1*-2;
    p5d_1.f_x = 1889101;
    std::cout << std::endl;

    std::cout << "L4(x): " << std::endl;
    Poly1 p1e_1(1, 0);
    Poly1 p1e_2(1, -1);
    Poly1 p1e_3(1, -2);
    Poly1 p1e_4(1, -3);
    Poly1 p1e_5(1, -5);

    p1e_1.print();
    p1e_2.print();
    p1e_3.print();
    p1e_4.print();
    p1e_5.print();

    Poly2 p2e_1(p1e_1, p1e_2);
    p2e_1.print();
    Poly2 p2e_2(p1e_3, p1e_4);
    p2e_2.print();

    Poly4 p4e_1(p2e_1, p2e_2);
    p4e_1.print();

    Poly5 p5e_1(p4e_1, p1e_5);
    p5e_1.print();
    p5e_1.denominator = 4*3*2*-1;
    p5e_1.f_x = 1897054;
    std::cout << std::endl;

    std::cout << "L5(x): " << std::endl;
    Poly1 p1f_1(1, 0);
    Poly1 p1f_2(1, -1);
    Poly1 p1f_3(1, -2);
    Poly1 p1f_4(1, -3);
    Poly1 p1f_5(1, -4);

    p1f_1.print();
    p1f_2.print();
    p1f_3.print();
    p1f_4.print();
    p1f_5.print();

    Poly2 p2f_1(p1f_1, p1f_2);
    p2f_1.print();
    Poly2 p2f_2(p1f_3, p1f_4);
    p2f_2.print();

    Poly4 p4f_1(p2f_1, p2f_2);
    p4f_1.print();

    Poly5 p5f_1(p4f_1, p1f_5);
    p5f_1.print();
    p5f_1.denominator = 5*4*3*2;
    p5f_1.f_x = 1911890;
    std::cout << std::endl;

    std::cout<< std::fixed;
    std::cout.precision(0);

    double x, sum;
    //Evaluate at a given x:
    for (int i = -2; i<8; i++)
    {
        x = static_cast<double>(i);
        sum = 0;
        sum += p5a_1.eval(x);
        sum += p5b_1.eval(x);
        sum += p5c_1.eval(x);
        sum += p5d_1.eval(x);
        sum += p5e_1.eval(x);
        sum += p5f_1.eval(x);

        std::cout << "The estimate of f at x = " << x << " is: " << sum << std::endl;
    }








    return 0;
}
