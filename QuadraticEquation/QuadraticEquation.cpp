#include "QuadraticEquation.h"

void QuadEquation::SetCoeffs(const double a, const double b, const double c)
{
    _a = a;
    _b = b;
    _c = c;
}

bool QuadEquation::Solve()
{
    double d = FindDiscrim();

    if (_a != 0.0 && d >= 0.0)
    {
        _x1 = (-_b + (sqrt(d))) / (2 * _a);
        _x2 = (-_b - (sqrt(d))) / (2 * _a);
        return SUCCESS;
    }
    else if (_a == 0.0 || d < 0.0)
    {
        return FAIL;
    }
}