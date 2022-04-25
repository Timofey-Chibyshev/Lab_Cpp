#pragma once

#include "Figures.h"

class Rectangle : public Figure
{
    double _w;
    double _h;
public:

    Rectangle(double w = 0.0, double h = 0.0) : _w(w), _h(h) {};

    Rectangle(const Rectangle& rect) : _w(rect._w), _h(rect._h) {};

    Rectangle(Rectangle&& rect) : _w(rect._w), _h(rect._h) { rect._h = 0.0; }

    Rectangle& operator=(const Rectangle& other);

    virtual void DrawGraphic(void) const override;

    virtual void DrawText(void) const override;

    virtual std::string GetName() const override;

    double GetArea() const override;

    virtual ~Rectangle() {};
};