#pragma once
#include "MenuElement.h"
class GameStats : public MyRectangle
{
private:
	int currentVisitors;
	int moneyAmount;
public:
	GameStats(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor, Visualisation* vis_ptr,
		Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
	{
		currentVisitors = 0;
		moneyAmount = 1000;
	}
	~GameStats()	{}
	int GetCurrentVisitors() const;
	void SetCurrentVisitors(int quantity);
	int GetAmountOfMoney() const;
	void SetAmountOfMoney(int amount);
	__declspec(property(get = GetCurrentVisitors, put = SetCurrentVisitors)) int visitorsCounter;
	__declspec(property(get = GetAmountOfMoney, put = SetAmountOfMoney)) int amountOfMoney;
	void DrawContent();
};
