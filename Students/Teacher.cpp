#include "Teacher.h"
#include "Equation.h"
#include <tuple>
#include <iterator>

void Teacher::Review(std::queue < std::tuple <Equation, Solution, std::string> >& studQueue)
{
	while (!studQueue.empty())
	{
		auto pending = studQueue.front();
		studQueue.pop();
		std::string studentName = std::get<std::string>(pending);
		Solution teacherSol = std::get<Equation>(pending).Solve();
		if (_results.find(studentName) == _results.end())
		{
			_results.insert({ studentName, 0 });
		}
		bool solvedRight = teacherSol == std::get<Solution>(pending);
		std::map <std::string, int> ::iterator curMap;
		curMap = _results.find(studentName);
		if (solvedRight)
		{
			curMap->second++;
		}
	}
	return;
}

void Teacher::PublishResults()
{
	for (auto i : _results)
	{
		std::cout << i.first << " solved " << i.second << " tasks" << std::endl;
	}
	return;
}
