#include "buildingDescriptor.h"
wstring BuildingDescriptor::GetConstructionSymbol(int mask)
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