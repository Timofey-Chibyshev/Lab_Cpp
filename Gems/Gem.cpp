#include "Gem.h"

Gem::Gem(float gemHeight, float gemWidth, sf::Color gemColor)
{
	height = gemHeight; width = gemWidth;
	color = gemColor;
	outline = sf::Color::Black;
}

bool Gem::IsEmpty(void)
{
	if (color == sf::Color::Black)
	{
		return true;
	}
	return false;
}

void Gem::SetEmpty(void)
{
	color = sf::Color::Black;
}

sf::Color Gem::GetColor(void)
{
	return color;
}

void Gem::SetColor(sf::Color newColor)
{
	color = newColor;
}

void Gem::SetOutline(sf::Color newColor)
{
	outline = newColor;
}

void Gem::DrawGem(std::shared_ptr <sf::RenderWindow> window, float x, float y)
{
	sf::RectangleShape shape(sf::Vector2f(width, height));

	shape.setFillColor(color);
	shape.setPosition(x, y);
	shape.setOutlineThickness((height + width) / -40);
	shape.setOutlineColor(outline);

	window->draw(shape);
}