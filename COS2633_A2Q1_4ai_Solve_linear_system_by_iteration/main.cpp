///COS2633 A2A1.4_a_i///
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

void scaleMatrix(double m[][4], int r, int c, double s)
//Scales matrix m by the scalar s
//m has r rows and c columns
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m[i][j] = s*m[i][j];
        }
    }
}

void scaleColVect(double v[4], int r, double s)
//Multiplies the entries in column vector v by scalar
{
    for (int i = 0; i < r; i++)
    {
        v[i] = s*v[i];
    }
}

void addMatrix(double result[][4], double m1[][4], double m2[][4],int r, int c)
//Adds matrix m1 to m2 and stores the result in matrix result
//m has r rows and c columns
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = m1[i][j]+m2[i][j];
        }
    }
}

void addColVect(double result[], double v1[], double v2[],int r)
//Adds vector v1 to v2 and stores the result in vector result
{

    for (int i = 0; i < r; i++)
    {
            result[i] = v1[i]+v2[i];
    }
}

void multMatrixVect(double result[], double m[][4], double v[],int r, int c)
//Multiplies matrix m by column vector v and stores the result in column vector result
//m has r rows and c columns
{
    double sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum += m[i][j]*v[j];
        }
        result[i] = sum;
        sum = 0;
    }
}


void assignMatrix(double left[][4], double right[][4], int r, int c)
//Assigns the right matrix to the left matrix (iow performs = operatation)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            left[i][j] = right[i][j];
        }

    }
}

void assignColVect(double left[4], double right[4], int r)
//Assigns the right vector to the left vector (iow performs = operatation)
{
    for (int i = 0; i < r; i++)
    {
        left[i] = right[i];
    }
}

void solveXvect(double result[], double m[][4], double v[],int r)
//Solves vector x in Ax = b where A is a square matrix containing only diagonal entries and b is a column vector
//The result is stored in column vector result
{
    for (int i = 0; i < r; i++)
    {
        result[i] = v[i]/m[i][i];
    }
}

int main()
{
//Declare variables
    double A[4][4] = {{0.06, 0.08, 0.07, 0.08},
                      {0.08, 0.2, 0.09, 0.07},
                      {0.07, 0.09, 0.2, 0.1},
                      {0.06, 0.08, 0.1, 0.2}};
    double M[4][4] = {{0.06, 0.0, 0.00, 0.0},
                      {0.0, 0.2, 0.0, 0.0},
                      {0.0, 0.0, 0.2, 0.0},
                      {0.0, 0.0, 0.0, 0.2}};
    double b[4] = {0.29, 0.44, 0.46, 0.44};

//Textbook example
//    double A[4][4] = {{10, -1, 2, 0.0},
//                      {-1, 11, -1, 3},
//                      {2, -1, 10, -1},
//                      {0, 3, -1, 8}};
//    double M[4][4] = {{10, 0, 0, 0},
//                      {0, 11, 0, 0},
//                      {0, 0, 10, 0},
//                      {0, 0, 0, 8}};
//    double b[4] = {6, 25, -11, 15};

    double omegaA[4][4];
    double fact[4][4];
    double resultV[4];
    double xZero[4];
    double xOne[4];
    double xTwo[4];
    double xThree[4];
    double omega = 1;

//test code for functions
//    printMatrix(A, 4, 4);
//    cout << endl;
//    scaleMatrix(A, 4, 4, 2);
//    printMatrix(A, 4, 4);
//    cout << endl;
//    addMatrix(result, A, A, 4, 4);
//    printMatrix(result, 4, 4);
//    cout << endl;
//    printColVect(b, 4);
//    cout << endl;
//    assignColVect(xZero, b, 4);
//    scaleColVect(xZero, 4, 2);
//    printColVect(b, 4);
//    cout << endl;
//    printColVect(xZero, 4);

    //Print matrix M
    cout << "M:" << endl;
    printMatrix(M, 4, 4);
    cout << endl;

    //Calculate x(0)
    cout << "x(0):" << endl;
    assignColVect(xZero, b, 4);
    scaleColVect(xZero, 4, omega);
    printColVect(xZero, 4);
    cout << endl;

    //calculate M-omega*A, call it fact
    assignMatrix(omegaA, A, 4, 4);
    scaleMatrix(omegaA, 4, 4, -omega); //scale A by omega
    addMatrix(fact, M, omegaA, 4, 4);
    cout << "M-omega*A:" << endl;
    printMatrix(fact, 4, 4);
    cout << endl;

    ///First iteration///
    //calculate  fact*x(0);
    multMatrixVect(resultV, fact, xZero, 4, 4);
    cout << "(M-omega*A)*x(0):" << endl;
    printColVect(resultV, 4);
    cout << endl;

    //Calculate omega*b + fact*x(0);
    addColVect(resultV, xZero, resultV, 4);
    cout << "omega*b + fact*x(0):" << endl;
    printColVect(resultV, 4);
    cout << endl;

    //Solve for x(1)
    cout << "x(1):" << endl;
    solveXvect(resultV, M, resultV, 4);
    assignColVect(xOne, resultV, 4);
    printColVect(resultV, 4);
    cout << endl;

    ///Second iteration///
    //calculate  fact*x(1);
    multMatrixVect(resultV, fact, xOne, 4, 4);
    cout << "(M-omega*A)*x(1):" << endl;
    printColVect(resultV, 4);
    cout << endl;

    //Calculate omega*b + fact*x(1);
    addColVect(resultV, xZero, resultV, 4);
    cout << "omega*b + fact*x(1):" << endl;
    printColVect(resultV, 4);
    cout << endl;

    //Solve for x(2)
    cout << "x(2):" << endl;
    solveXvect(resultV, M, resultV, 4);
    assignColVect(xTwo, resultV, 4);
    printColVect(resultV, 4);
    cout << endl;

    ///Third iteration///
    //calculate  fact*x(2);
    multMatrixVect(resultV, fact, xTwo, 4, 4);
    cout << "(M-omega*A)*x(2):" << endl;
    printColVect(resultV, 4);
    cout << endl;

    //Calculate omega*b + fact*x(2);
    addColVect(resultV, xZero, resultV, 4);
    cout << "omega*b + fact*x(2):" << endl;
    printColVect(resultV, 4);
    cout << endl;

    //Solve for x(3)
    cout << "x(3):" << endl;
    solveXvect(resultV, M, resultV, 4);
    assignColVect(xThree, resultV, 4);
    printColVect(resultV, 4);
    cout << endl;

    return 0;
}
