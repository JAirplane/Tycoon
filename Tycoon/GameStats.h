#pragma once
#include "RoadGraph.h"
class GameStats : public MyRectangle
{
private:
	int previousVisitorsNumber;
	int currentVisitorsNumber;
	int previousMoneyAmount;
	int moneyAmount;
	int currentParkLevel; // hidden stat depends on how many buildings we have
public:
	GameStats(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor, Visualisation* vis_ptr,
		Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
	{
		previousVisitorsNumber = 0;
		currentVisitorsNumber = 0;
		previousMoneyAmount = 2000;
		moneyAmount = 2000;
		currentParkLevel = 0;
	}
	~GameStats()	{}
	int GetPreviousVisitorsNumber() const;
	void SetPreviousVisitorsNumber();
	__declspec(property(get = GetPreviousVisitorsNumber, put = SetPreviousVisitorsNumber)) int previousNumberOfVisitors;
	int GetCurrentVisitorsNumber() const;
	void SetCurrentVisitorsNumber(int quantity);
	__declspec(property(get = GetCurrentVisitorsNumber, put = SetCurrentVisitorsNumber)) int NumberOfVisitors;
	int GetPreviousAmountOfMoney() const;
	void SetPreviousAmountOfMoney();
	__declspec(property(get = GetPreviousAmountOfMoney, put = SetPreviousAmountOfMoney)) int previousAmountOfMoney;
	int GetAmountOfMoney() const;
	void SetAmountOfMoney(int amount);
	__declspec(property(get = GetAmountOfMoney, put = SetAmountOfMoney)) int amountOfMoney;
	int GetCurrentParkLevel() const;
	void SetCurrentParkLevel(int lvl);
	__declspec(property(get = GetCurrentParkLevel, put = SetCurrentParkLevel)) int parkLevel;
	void DrawContent();
};
