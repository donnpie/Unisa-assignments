//This programm solves COS2633 A1Q2 using newton's method
//See secction 2.1 of Burden

#include <iostream>
#include <cmath>
#include <iomanip>

double myFunction(double x)
{
    //x is the independant variable
    //this function retruns the original function, that is f(x)

    //f(x) = (pow(x, 2)-sqrt(x+3)-25.11)
    return (pow(x, 2)-sqrt(x+3)-25.11);

    //Example 1 on p69
    //return cos(x)-x;

    //f'(x) = -2/sqrt(x+3)
    //retrun x + (sqrt(x+3)*(pow(x, 2)-sqrt(x+3)-25.11)/2);//x - f(x)/f'(x)
    //std::cout<<ans<<'\n';


}

double deriv(double x)
{
    //this function returns the derivative of the original function, that is f'(x)
    return 2*x - 2/sqrt(x+3);

    //Example 1 on p69
    //return -sin(x)-1;
}


double calcRoot(double p0, double p1, double tolerance, int maxIterations)
{
    //p1, p2: Iniitial guesses
    //tolerance: acceptable tolerance
    //maxIterations: the maximum number of iterations to do
    //output: returns an approximate value of the fixed point
    double q0 = myFunction(p0);
    double q1 = myFunction(p1);
    double q2;
    double p2;
    std::cout << std::fixed;
    std::cout << std::setprecision(11);
    for (int i = 2; i < maxIterations; i++)
    {
        std::cout<< "n: " << i << " ";
        p2 = p1 - q1*(p1-p0)/(q1-q0);//the secant algorithm is also used by regula falsi
        std::cout<<p2<<'\n';
        if (fabs(p2-p1) < tolerance)
        {
            return p2;
        }
        q2 = myFunction(p2);
        if (q2*q1 < 0)
        {
            p0 = p1;
            q0 = q1;
        }
        p1= p2;
        q1=q2;

    }
    return 0; //value not found

}

int main()
{//regula falsi
    std::cout << calcRoot(-1, -2, 0.00000001, 10) << '\n';

    //using the example 1 on p 69 as test case
    //std::cout << calcFixedPoint(M_PI/4, 0.00000001, 10) << '\n';
    //This works! Compare with results on p69.

    return 0;
}
