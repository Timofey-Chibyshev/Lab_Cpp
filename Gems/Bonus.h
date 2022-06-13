#pragma once

#include "Field.h"

class Bonus
{
protected:
	unsigned x, y;
	unsigned type;

public:
	Bonus(unsigned newX, unsigned newY, unsigned newType);
	~Bonus(void) {}

	virtual unsigned Trigger(std::shared_ptr<Field> field) = 0;
	void DrawBonus(std::shared_ptr <sf::RenderWindow> window, std::shared_ptr<Field> field, float offsetHeight, float offsetWidth);
};

class Bomb :public Bonus
{
private:
	unsigned bombedNumber = 5;

public:
	Bomb(unsigned newX, unsigned newY) :Bonus(newX, newY, 0) {}
	unsigned Trigger(std::shared_ptr<Field> field) override;
	~Bomb(void) {}
};

class Painter :public Bonus
{
private:
	unsigned paintedNumber = 2;
	unsigned paintedRadius = 3;

public:
	Painter(unsigned newX, unsigned newY) :Bonus(newX, newY, 1) {}
	unsigned Trigger(std::shared_ptr<Field> field) override;
	bool GemIsBad(std::shared_ptr<Field> field, unsigned x, unsigned y, std::vector <std::array<unsigned, 2>> paintedGems);

	~Painter(void) {}
};