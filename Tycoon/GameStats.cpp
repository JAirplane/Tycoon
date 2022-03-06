#include "GameStats.h"
int GameStats::GetCurrentVisitors() const
{
	return currentVisitors;
}
void GameStats::SetCurrentVisitors(int quantity)
{
	if (quantity > 9999)
	{
		currentVisitors = 9999;
	}
	else
	{
		currentVisitors = quantity;
	}
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
void GameStats::DrawContent()
{
	string moneyMsg = "Money amount: ";
	string visitorsMsg = "Visitors: ";
	int moneyDigits = NumberOfDigits::GetDigitsCounter()->GetNumberOfDigits(amountOfMoney);
	int visitorsDigits = NumberOfDigits::GetDigitsCounter()->GetNumberOfDigits(visitorsCounter);
	int xCoordAdditionMoney = (GetWidthAddition() + 1 - static_cast<int>(moneyMsg.length() + moneyDigits)) / 2;
	int xCoordAdditionVisitors = (GetWidthAddition() + 1 - static_cast<int>(visitorsMsg.length() + visitorsDigits)) / 2;
	set_cursor_pos(GetUpperLeft().Get_x() + xCoordAdditionMoney, GetUpperLeft().Get_y() + 1);
	set_color(GetTextColor(), GetShadingColor());
	cout << "Money amount: " << amountOfMoney;
	set_cursor_pos(GetUpperLeft().Get_x() + xCoordAdditionVisitors, GetUpperLeft().Get_y() + 2);
	cout << "Visitors: " << visitorsCounter;
}