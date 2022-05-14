#pragma once

#include <iostream>
#include <cmath>

void Interface();

class Solution
{
public:
	Solution(const int& rootCount, const double& x1, const double& x2) : _rootCount(rootCount), _x1(x1), _x2(x2) {};
	double GetX1() const { return _x1; }
	double GetX2() const { return _x2; }
	int GetCount() const { return _rootCount; }
	bool operator == (const Solution& toCompare);
private:
	int _rootCount;
	double _x1;
	double _x2;
};

class Equation
{
public:
	friend std::istream& operator >> (std::istream& is, Equation& eqn);
	Equation() : _a(0), _b(0), _c(0) {};
	Equation(std::istream& in)
	{
		if (!(in >> _a >> _b >> _c))
			throw std::runtime_error("Unable to read coefficients");
	}
	Solution Solve() const;
private:
	double _a;
	double _b;
	double _c;
};