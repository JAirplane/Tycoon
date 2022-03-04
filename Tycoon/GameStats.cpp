#include "GameStats.h"
int GameStats::GetCurrentVisitors() const
{
	return currentVisitors;
}
void GameStats::SetCurrentVisitors(int quantity)
{
	currentVisitors = quantity;
}
int GameStats::GetAmountOfMoney() const
{
	return moneyAmount;
}
void GameStats::SetAmountOfMoney(int amount)
{
	moneyAmount = amount;
}