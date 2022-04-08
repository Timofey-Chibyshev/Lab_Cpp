#include "QuadraticEquation.h"

void InputCoeffs(double*, double*, double*);
void PrintRoots(QuadEquation);

int main()
{
    double a, b, c;
    InputCoeffs(&a, &b, &c);

    QuadEquation equation(a, b, c);

    if (!equation.Solve())
    {
        cout << "No real roots." << endl;
    }
    else
    {
        PrintRoots(equation);
    }
    return 0;
}

void InputCoeffs(double* a, double* b, double* c)
{
    cout << "Enter a, b, c of quadratic equation ax^2 + bx + c = 0: ";
    cin >> *a >> *b >> *c;
}

void PrintRoots(QuadEquation equation)
{
    double x1 = equation.GetX1(), x2 = equation.GetX2();

    if (x1 != x2)
    {
        cout << "x1 = " << x1 << " or x2 = " << x2 << ".";
    }
    else
    {
        cout << "x1 = " << x1 << ".";
    }
}