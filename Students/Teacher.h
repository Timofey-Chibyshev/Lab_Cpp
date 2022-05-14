#pragma once

#include <map>
#include <queue>
#include <tuple>
#include "Equation.h"

class Teacher
{
public:
	Teacher(std::map <std::string, int >& res) : _results(res) {};
	void Review(std::queue < std::tuple <Equation, Solution, std::string> >& studQueue);
	void PublishResults();
private:
	std::map <std::string, int> _results;
};