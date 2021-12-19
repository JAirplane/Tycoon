#include "ConstructionDescriptor.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
unsigned int ConstructionDescriptor::GetConstructionHeightAdd() const
{
	return constructionheightAddition;
}
unsigned int ConstructionDescriptor::GetConstructionWidthAdd() const
{
	return constructionwidthAddition;
}
unsigned int ConstructionDescriptor::GetConstructionCost() const
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
unsigned int ConstructionDescriptor::GetDailyExpences() const
{
	return dailyExpences;
}
color ConstructionDescriptor::GetForegroundColor()
{
	return foreground;
}
color ConstructionDescriptor::GetBackgroundColor()
{
	return background;
}
wstring ConstructionDescriptor::GetConstructionSymbol()
{
	wstring empty = L"0";
	return empty;
}