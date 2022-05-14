#include "AddFuncs.h"

vector <Student*> buildList(istream& in)
{
	vector <Student*> studentList;
	while (!in.eof())
	{
		string name;
		getline(in, name);
		switch (rand() % 3)
		{
		case 0:
			studentList.push_back(new BadStudent(name));
			break;
		case 1:
			studentList.push_back(new AverageStudent(name));
			break;
		case 2:
			studentList.push_back(new BadStudent(name));
			break;
		}
	}
	return studentList;
}
queue <tuple <Equation, Solution, string>> buildQueue(vector <Student*>& list, vector <Equation>& equations)
{
	queue <tuple <Equation, Solution, string>> answers;
	for (auto curStudent : list)
	{
		for (auto& curEq : equations)
		{
			Solution sol = curStudent->Solve(curEq);
			answers.push({ curEq, sol, curStudent->getName() });
		}
	}
	return answers;
}
vector <Equation> readEquations(istream& in)
{
	vector <Equation> equations;
	while (!in.eof())
	{
		Equation tmp;
		in >> tmp;
		equations.push_back(tmp);
	}
	return equations;
}

void Interface()
{
	srand(time(0));
	ifstream l("students.txt");
	ifstream eq("coeffs.txt");
	vector <Student*> students = buildList(l);
	vector <Equation> equations = readEquations(eq);
	auto answers = buildQueue(students, equations);
	map <string, int> results;
	Teacher master(results);
	master.Review(answers);
	master.PublishResults();
	return;
}