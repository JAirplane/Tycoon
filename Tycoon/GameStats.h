#pragma once
#include "MenuElement.h"
class GameStats : public MyRectangle
{
private:
	int currentVisitors;
	int moneyAmount;
	int currentParkLevel; // hidden stat depends on how many buildings we have
public:
	GameStats(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor, Visualisation* vis_ptr,
		Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
	{
		currentVisitors = 0;
		moneyAmount = 2000;
		currentParkLevel = 0;
	}
	~GameStats()	{}
	int GetCurrentVisitors() const;
	void SetCurrentVisitors(int quantity);
	int GetAmountOfMoney() const;
	void SetAmountOfMoney(int amount);
	int GetCurrentParkLevel() const;
	void SetCurrentParkLevel(int lvl);
	__declspec(property(get = GetCurrentVisitors, put = SetCurrentVisitors)) int visitorsCounter;
	__declspec(property(get = GetAmountOfMoney, put = SetAmountOfMoney)) int amountOfMoney;
	__declspec(property(get = GetCurrentParkLevel, put = SetCurrentParkLevel)) int parkLevel;
	void DrawContent();
};
