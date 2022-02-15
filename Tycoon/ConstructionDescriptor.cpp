#include "ConstructionDescriptor.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
int ConstructionDescriptor::GetConstructionHeightAdd() const
{
	return constructionHeightAddition;
}
int ConstructionDescriptor::GetConstructionWidthAdd() const
{
	return constructionWidthAddition;
}
int ConstructionDescriptor::GetConstructionCost() const
{
	return constructionCost;
}
string ConstructionDescriptor::GetDescription() const
{
	return description;
}
wstring ConstructionDescriptor::GetIconSymbol()
{
	return iconSymbol;
}
int ConstructionDescriptor::GetDailyExpences() const
{
	return dailyExpences;
}
color ConstructionDescriptor::GetForegroundColor()
{
	return foreground;
}
color ConstructionDescriptor::GetConnectedBackgroundColor()
{
	return backgroundConnected;
}
color ConstructionDescriptor::GetNotConnectedBackgroundColor()
{
	return backgroundNotConnected;
}
color ConstructionDescriptor::GetChosenBackgroundColor()
{
	return backgroundChoosen;
}
wstring ConstructionDescriptor::GetConstructionSymbol(int mask)
{
	wstring empty = L"0";
	return empty;
}
PointCoord ConstructionDescriptor::GetMenuElementLocation() const
{
	return menuElementLocation;
}
void ConstructionDescriptor::SetMenuElementLocation(PointCoord Location)
{
	menuElementLocation = Location;
}