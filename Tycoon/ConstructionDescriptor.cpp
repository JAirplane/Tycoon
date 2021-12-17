#include "ConstructionDescriptor.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
unsigned int ConstructionDescriptor::GetConstructionHeightAdd() const
{
	return constructionheightAddition;
}
void ConstructionDescriptor::SetConstructionheightAdd(unsigned int heightAdd)
{
	constructionheightAddition = heightAdd;
}
unsigned int ConstructionDescriptor::GetConstructionWidthAdd() const
{
	return constructionwidthAddition;
}
void ConstructionDescriptor::SetConstructionwidthAdd(unsigned int widthAdd)
{
	constructionwidthAddition = widthAdd;
}
unsigned int ConstructionDescriptor::GetConstructionCost() const
{
	return constructionCost;
}
void ConstructionDescriptor::SetConstructionCost(const int constructionCost)
{
	this->constructionCost = constructionCost;
}
string ConstructionDescriptor::GetDescription() const
{
	return description;
}
void ConstructionDescriptor::SetDescription(string description)
{
	this->description = description;
}
char ConstructionDescriptor::GetIconSymbol()
{
	return iconSymbol;
}
void ConstructionDescriptor::SetIconSymbol(const char iconSymbol)
{
	this->iconSymbol = iconSymbol;
}
unsigned int ConstructionDescriptor::GetDailyExpences() const
{
	return dailyExpences;
}
void ConstructionDescriptor::SetDailyExpences(unsigned int dailyExpences)
{
	this->dailyExpences = dailyExpences;
}
color ConstructionDescriptor::GetForegroundColor()
{
	return foreground;
}
void ConstructionDescriptor::SetForegroundColor(color foreground)
{
	this->foreground = foreground;
}
color ConstructionDescriptor::GetBackgroundColor()
{
	return background;
}
void ConstructionDescriptor::SetBackgroundColor(color background)
{
	this->background = background;
}
char ConstructionDescriptor::GetBuildingSymbol()
{
	return '0';
}
void ConstructionDescriptor::SetBuildingSymbol(const char buildingSymbol)
{}