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


double newton(double guess, double tolerance, int maxIterations)
{
    //guess: intitial guess
    //tolerance: acceptable tolerance
    //maxIterations: the maximum number of iterations to do
    //output: returns an approximate value of the fixed point
    double currentResult;
    double previousResult = guess;
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    for (int i = 0; i < maxIterations; i++)
    {
        std::cout<< "n: " << i << " ";
        //currentResult = myFunction(previousResult);
        currentResult = previousResult - (myFunction(previousResult)/deriv(previousResult));
        std::cout<<currentResult<<'\n';
        if (fabs(currentResult - previousResult) < tolerance)
        {
            return currentResult;
        }
        previousResult = currentResult;
    }
    return 0; //value not found

}

int main()
{
    std::cout << newton(0.5, 0.00000001, 10) << '\n';

    //using the example 1 on p 69 as test case
    //std::cout << calcFixedPoint(M_PI/4, 0.00000001, 10) << '\n';
    //This works! Compare with results on p69.

    return 0;
}
