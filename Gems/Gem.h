#pragma once

#include <SFML/Graphics.hpp>

class Gem
{
private:
	float height, width;
	sf::Color color;
	sf::Color outline;

public:
	Gem(float gemHeight, float gemWidth, sf::Color gemColor);
	~Gem(void) {}

	bool IsEmpty(void);

	void SetEmpty(void);
	void SetColor(sf::Color newColor);
	void SetOutline(sf::Color newColor);

	sf::Color GetColor(void);

	void DrawGem(std::shared_ptr <sf::RenderWindow> window, float x, float y);
};