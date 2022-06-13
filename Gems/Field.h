#pragma once

#include <array>

#include "Gem.h"

class Field
{
private:
	float height, width;
	unsigned gemsInRow, gemsInColumn;

	std::vector <std::vector <Gem>> gemsMatrix;
	std::array <sf::Color, 6> colorsMatrix = { sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan };
	std::vector <std::array <unsigned, 2>> reiteration;
	std::vector <sf::Texture> textureMatrix;

public:
	Field(float fieldWindowHeight, float fieldWindowWidth, unsigned numberGemsInRow, unsigned numberGemsInColumn);
	~Field(void) {}

	void GenerateField(void);
	void DrawField(std::shared_ptr <sf::RenderWindow> window, float offsetHeight, float offsetWidth);

	unsigned GetGemsInRow(void);
	unsigned GetGemsInColumn(void);
	float GetFieldHeight(void);
	float GetFieldWidth(void);

	void CheckField(unsigned i, unsigned j);
	bool NeighborIsGood(unsigned i, unsigned j, unsigned neighborI, unsigned neighborJ);
	bool AlreadyChoose(unsigned i, unsigned j, std::vector <std::array <unsigned, 2>> checkVector);
	unsigned DeleteChoosedGems(std::vector <std::array <unsigned, 2>> forDeletion);
	unsigned FindGemsReiteration(void);

	bool GemsDrop(void);
	void FieldRefilling(void);

	void SetHighlight(unsigned x, unsigned y, sf::Color newColor);
	void GemsSwap(unsigned x1, unsigned y1, unsigned x2, unsigned y2);

	void SetNewGemsColor(std::vector <std::array <unsigned, 2>> paintedGems, unsigned i, unsigned j);

	sf::Texture* GetTexture(unsigned type);
	bool GemIsEmpty(unsigned i, unsigned j);
	std::vector <std::array <unsigned, 2>> GetReiterationVector(void);
};