#include "buildingDescriptor.h"
wstring BuildingDescriptor::GetConstructionSymbol(int mask) const
{
	return buildingSymbol;
}
int BuildingDescriptor::GetRestorationOfToiletNeed() const
{
	return restoreToiletNeed;
}
int BuildingDescriptor::GetSatisfactionOfHunger() const
{
	return satisfactionOfHunger;
}
int BuildingDescriptor::GetVisitPrice() const
{
	return visitPrice;
}
int BuildingDescriptor::GetEntertainmentValue() const
{
	return entertainmentValue;
}
int BuildingDescriptor::GetIsExit() const
{
	return isExit;
}
int BuildingDescriptor::GetMaxVisitors() const
{
	return maxVisitors;
}
int BuildingDescriptor::GetVisitTime() const
{
	return visitTime;
}