#include "buildingDescriptor.h"
wstring BuildingDescriptor::GetConstructionSymbol(int mask)
{
	return buildingSymbol;
}
bool BuildingDescriptor::GetRestorationOfToiletNeed() const
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