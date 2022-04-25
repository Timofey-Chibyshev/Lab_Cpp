#pragma once

#include "Figures.h"

class Square : public Figure
{
	double _a;
public:
	Square(double a = 0.0) : _a(a) {};

	Square(const Square& square) : _a(square._a) {};

	Square(Square&& square) : _a(square._a) { square._a = 0.0; };

	Square& operator=(const Square& other);

	virtual void DrawGraphic(void) const override;

	virtual void DrawText(void) const override;

	virtual std::string GetName() const override;

	double GetArea() const override;

	virtual ~Square() = default;
};