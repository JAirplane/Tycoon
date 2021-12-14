#include "ConstructionDescriptor.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
unsigned int ConstructionDescriptor::getConstructionHeightAdd() const
{
	return ConstructionHeightAddition;
}
void ConstructionDescriptor::setConstructionHeightAdd(unsigned int _heightadd)
{
	ConstructionHeightAddition = _heightadd;
}
unsigned int ConstructionDescriptor::getConstructionWidthAdd() const
{
	return ConstructionWidthAddition;
}
void ConstructionDescriptor::setConstructionWidthAdd(unsigned int _widthadd)
{
	ConstructionWidthAddition = _widthadd;
}
unsigned int ConstructionDescriptor::getConstructionCost() const
{
	return ConstructionCost;
}
void ConstructionDescriptor::setConstructionCost(const int _constructioncost)
{
	ConstructionCost = _constructioncost;
}
string ConstructionDescriptor::getDescription() const
{
	return Description;
}
void ConstructionDescriptor::setDescription(string _desc)
{
	Description = _desc;
}
char ConstructionDescriptor::getIconSymbol()
{
	return IconSymbol;
}
void ConstructionDescriptor::setIconSymbol(const char symbol)
{
	IconSymbol = symbol;
}
unsigned int ConstructionDescriptor::getDailyExpences() const
{
	return DailyExpences;
}
void ConstructionDescriptor::setDailyExpences(unsigned int _dailyexpences)
{
	DailyExpences = _dailyexpences;
}
color ConstructionDescriptor::getForegroundColor()
{
	return Foreground;
}
void ConstructionDescriptor::setForegroundColor(color _somecolor)
{
	Foreground = _somecolor;
}
color ConstructionDescriptor::getBackgroundColor()
{
	return Background;
}
void ConstructionDescriptor::setBackgroundColor(color _somecolor)
{
	Background = _somecolor;
}
char ConstructionDescriptor::getBuildingSymbol()
{
	return '0';
}
void ConstructionDescriptor::setBuildingSymbol(const char _buildingsymbol)
{}