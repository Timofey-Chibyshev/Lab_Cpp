#include "Square.h"

Square& Square::operator=(const Square& other)
{
	if (this == &other)
	{
		return *this;
	}
	_a = other._a;
	return *this;
}

void Square::DrawText() const
{
	std::cout << "W: " << _a << " H: " << _a << std::endl;
}

void Square::DrawGraphic() const
{
	for (size_t i = 0; i < _a; i++)
	{
		for (size_t j = 0; j < _a; j++)
		{
			std::cout << "# ";

		}
		std::cout << std::endl;
	}
}

std::string Square::GetName() const
{
	return "Square";
};

double Square::GetArea() const
{
	return _a * _a;
};