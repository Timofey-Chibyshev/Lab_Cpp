#include "Rectangle.h"

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this == &other)
	{
		return *this;
	}
	_w = other._w;
	_h = other._h;
	return *this;
}

void Rectangle::DrawText() const
{
	std::cout << "W: " << _w << " H: " << _h << std::endl;
}

void Rectangle::DrawGraphic() const
{
	for (size_t i = 0; i < _w; i++)
	{
		for (size_t j = 0; j < _h; j++)
		{
			std::cout << "# ";
		}
		std::cout << std::endl;
	}
}

std::string Rectangle::GetName() const
{
	return "Rectangle";
};

double Rectangle::GetArea() const
{
	return _w * _h;
};