#include <iostream>

using namespace std;

void printMatrix(double m[][4], int r, int c)
//Prints to console the entries in matrix m
//m has r rows and c columns
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void printColVect(double v[4], int r)
//Prints to console the entries in column vector v
//m has r rows and c columns
{
    for (int i = 0; i < r; i++)
    {
        cout << v[i] << "\t" << endl;
    }
}

void nextX(double resultV[], const double M[][4], const double x[], const double b[], int r = 4)
//Calculates the next vector x, given matrix M, vector b and previous vector x
{
    //cout << "Starting nextX..." << endl;
    double sum = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (i!=j)
            {
                sum +=  -M[i][j]*x[j];
                //cout << "\ti: " << i << ", j: " << j << ", m[i][j]: " << M[i][j] << ", x[j]: " << x[j] << ", sum: " << sum << endl;
            }
        }

        sum += b[i];
        sum = sum/M[i][i];
        //cout << "\tb[i]: " << b[i] << ", M[i][i]: " << M[i][i] <<  endl;
        resultV[i] = sum;
        //cout << "ResultV[i]: " << resultV[i] << endl;
        sum = 0;
    }
    //cout << "...nextX is done" << endl;
}

void assignColVect(double left[4], double right[4], int r)
//Assigns the right vector to the left vector (iow performs = operatation)
{
    for (int i = 0; i < r; i++)
    {
        left[i] = right[i];
    }
}

int main()
{
    //Declare variables
//Given problem
    double A[4][4] = {{0.06, 0.08, 0.07, 0.08},
                      {0.08, 0.2, 0.09, 0.07},
                      {0.07, 0.09, 0.2, 0.1},
                      {0.06, 0.08, 0.1, 0.2}};
    double b[4] = {0.29, 0.44, 0.46, 0.44};
    double xZero[4] = {0.9, 0.9, 0.9, 0.9};

//Textbook example - Tested this and it works 100%
//    double A[4][4] = {{10, -1, 2, 0.0},
//                      {-1, 11, -1, 3},
//                      {2, -1, 10, -1},
//                      {0, 3, -1, 8}};
//    double b[4] = {6, 25, -11, 15};
//
//    double xZero[4] = {0, 0, 0, 0};
    double xOne[4];
    double xTwo[4];

    double resultV[4];


    //Print matrix A
    cout << "A:" << endl;
    printMatrix(A, 4, 4);
    cout << endl;

    //Print vector b
    cout << "b:" << endl;
    printColVect(b, 4);
    cout << endl;

    //Print x(0)
    cout << "x(0):" << endl;
    printColVect(xZero, 4);
    cout << endl;

    //Calculate x(1)
    nextX(resultV, A, xZero, b, 4);
    cout << "x(1):" << endl;
    assignColVect(xOne, resultV, 4);
    printColVect(resultV, 4);
    cout << endl;

    //Calculate x(2)
    nextX(resultV, A, xOne, b, 4);
    cout << "x(2):" << endl;
    assignColVect(xTwo, resultV, 4);
    printColVect(resultV, 4);
    cout << endl;

    //Calculate x(3)
    nextX(resultV, A, xTwo, b, 4);
    cout << "x(3):" << endl;
    //assignColVect(xThree, resultV, 4);
    printColVect(resultV, 4);
    cout << endl;






    return 0;
}
