#pragma once

#include <cmath>
#include <conio.h>
#include <iostream>

#define SUCCESS true
#define FAIL    false

using std::cout;
using std::cin;
using std::endl;

class QuadEquation
{
public:
    QuadEquation() : _a(1), _b(0), _c(0), _x1(0), _x2(0) {}
    QuadEquation(const double a, const double b, const double c) : _a(a), _b(b), _c(c), _x1(0), _x2(0) {}

    void SetCoeffs(const double, const double, const double);

    bool Solve();             // false - NO ROOTS, true - ROOTS
    double GetX1() const { return _x1; }
    double GetX2() const { return _x2; }

private:
    double _a, _b, _c;
    double _x1, _x2;
    double FindDiscrim() { return (_b * _b) - (4 * _a * _c); }
};
