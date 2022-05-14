#pragma once

#include "Equation.h"
#include <string>

class Student
{
public:
    Student() : _name("Undefined Student") {};
    Student(const std::string& name) : _name(name) {};
    std::string getName() const { return _name; }
    virtual Solution Solve(const Equation& eqn) const = 0;
    virtual ~Student() {};
private:
    std::string _name;
};

class BadStudent : public Student
{
public:
    BadStudent() : Student() {};
    BadStudent(const std::string& name) : Student(name) {};
    Solution Solve(const Equation& eqn) const override;
};

class GoodStudent : public Student
{
public:
    GoodStudent() : Student() {};
    GoodStudent(const std::string& name) : Student(name) {};
    Solution Solve(const Equation& eqn) const override;
};

class AverageStudent : public Student
{
public:
    AverageStudent() : Student() {};
    AverageStudent(const std::string name) : Student(name) {};
    Solution Solve(const Equation& eqn) const override;
};