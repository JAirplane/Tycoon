#include "GameStats.h"
int GameStats::GetPreviousVisitorsNumber() const
{
	return previousVisitorsNumber;
}
void GameStats::SetPreviousVisitorsNumber()
{
	previousVisitorsNumber = currentVisitorsNumber;
}
int GameStats::GetCurrentVisitorsNumber() const
{
	return currentVisitorsNumber;
}
void GameStats::SetCurrentVisitorsNumber(int quantity)
{
	if (quantity > 9999)
	{
		currentVisitorsNumber = 9999;
	}
	else
	{
		currentVisitorsNumber = quantity;
	}
}
int GameStats::GetPreviousAmountOfMoney() const
{
	return previousMoneyAmount;
}
void GameStats::SetPreviousAmountOfMoney()
{
	previousMoneyAmount = moneyAmount;
}
int GameStats::GetAmountOfMoney() const
{
	return moneyAmount;
}
void GameStats::SetAmountOfMoney(int amount)
{
	if (amount > 99999)
	{
		moneyAmount = 99999;
	}
	else
	{
		moneyAmount = amount;
	}
}
int GameStats::GetCurrentParkLevel() const
{
	return currentParkLevel;
}
void GameStats::SetCurrentParkLevel(int lvl)
{
	if (lvl > 5)
	{
		currentParkLevel = 5;
	}
	else
	{
		currentParkLevel = lvl;
	}
}
void GameStats::DrawContent()
{
	string moneyMsg = "Money amount: ";
	string visitorsMsg = "Visitors: ";
	int moneyDigits = NumberOfDigits::GetDigitsCounter()->GetNumberOfDigits(amountOfMoney);
	int visitorsDigits = NumberOfDigits::GetDigitsCounter()->GetNumberOfDigits(NumberOfVisitors);
	int xCoordAdditionMoney = (GetWidthAddition() + 1 - static_cast<int>(moneyMsg.length() + moneyDigits)) / 2;
	int xCoordAdditionVisitors = (GetWidthAddition() + 1 - static_cast<int>(visitorsMsg.length() + visitorsDigits)) / 2;
	set_cursor_pos(GetUpperLeft().Get_x() + xCoordAdditionMoney, GetUpperLeft().Get_y() + 1);
	set_color(GetTextColor(), GetShadingColor());
	cout << "Money amount: " << amountOfMoney;
	set_cursor_pos(GetUpperLeft().Get_x() + xCoordAdditionVisitors, GetUpperLeft().Get_y() + 2);
	cout << "Visitors: " << NumberOfVisitors;
}