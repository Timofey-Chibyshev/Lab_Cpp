#include "Students.h"

const Solution badSolution = { 1,0,0 };

Solution BadStudent::Solve(const Equation& eqn) const
{
	return badSolution;
}

Solution GoodStudent::Solve(const Equation& eqn) const
{
	return eqn.Solve();
}

Solution AverageStudent::Solve(const Equation& eqn) const
{
	return (rand() % 2) ? eqn.Solve() : badSolution;
}