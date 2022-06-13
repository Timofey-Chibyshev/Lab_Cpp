#pragma once

#include "Field.h"
#include "Bonus.h"

class GameLoop 
{ 
private:
	unsigned userWindowHeight, userWindowWidth; 
	unsigned fieldWindowHeight, fieldWindowWidth; 
	unsigned numberGemsInRow, numberGemsInColumn; 
	unsigned score; 
	float offsetHeight, offsetWidth; 

	bool drop;
	bool secondClick;
	bool swap, firstswap;

	unsigned gem1X, gem1Y, gem2X, gem2Y; 

	std::shared_ptr <sf::RenderWindow> window; 
	std::shared_ptr <Field> field; 
	std::vector<std::shared_ptr<Bonus>> bonusesMatrix; 

public:
	GameLoop(void);
	~GameLoop(void) {} 

	void FieldOffset(void); 
	void Start(void);

	void SpawnBonus(void); 
	void BonusCoordinates(unsigned& bonusX, unsigned& bonusY, unsigned k); 
	void BonusTrigger(void);
	void GemsDeletion(void); 

	void SelectFirstGem(float xInMatrix, float yInMatrix, float offsetX, float offsetY);
	void SelectSecondGem(float xInMatrix, float yInMatrix, float offsetX, float offsetY); 
	void CancelClick(void); 
	void GemsPermutation(void); 
	void Swap(void);

	void DrawGameLoop(void);
	void CreateText(void);

	void Win(void); 
};