#include "ConstructionDescriptor.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
int ConstructionDescriptor::GetConstructionCost() const
{
	return constructionCost;
}
string ConstructionDescriptor::GetDescription() const
{
	return description;
}
wstring ConstructionDescriptor::GetIconSymbol() const
{
	return iconSymbol;
}
int ConstructionDescriptor::GetDailyExpences() const
{
	return dailyExpences;
}
color ConstructionDescriptor::GetConnectedBackgroundColor() const
{
	return backgroundConnected;
}
color ConstructionDescriptor::GetChosenBackgroundColor() const
{
	return backgroundChoosen;
}
PointCoord ConstructionDescriptor::GetMenuElementLocation() const
{
	return menuElementLocation;
}
void ConstructionDescriptor::SetMenuElementLocation(PointCoord Location)
{
	menuElementLocation = Location;
}
bool ConstructionDescriptor::GetRestorationOfToiletNeed() const
{
	return false;
}
int ConstructionDescriptor::GetSatisfactionOfHunger() const
{
	return 0;
}
int ConstructionDescriptor::GetVisitPrice() const
{
	return 0;
}