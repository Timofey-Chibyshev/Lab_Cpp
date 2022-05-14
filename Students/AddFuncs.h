#pragma once

#include <queue>
#include <map>
#include <tuple>
#include <vector>
#include <iterator>
#include <fstream>
#include <time.h>
#include "Students.h"
#include "Teacher.h"
#include "Equation.h"

using namespace std;

vector <Student*> buildList(istream& in);

queue <tuple <Equation, Solution, string>> buildQueue(vector <Student*>& list, vector <Equation>& equations);

vector <Equation> readEquations(istream& in);