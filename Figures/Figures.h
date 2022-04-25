#pragma once

#include <iostream>
#include <string>

class Figure // абстрактный  класс (интерфейс) для всех наследуемых фигур («Квадрат», «Прямоугольник»)
{
public:
    virtual void DrawGraphic(void) const = 0;
    virtual void DrawText(void) const = 0;
    virtual std::string GetName() const = 0;
    virtual double GetArea() const = 0;
    virtual ~Figure() {};
};
