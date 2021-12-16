#include "ConstructionDescriptor.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
unsigned int ConstructionDescriptor::getConstructionHeightAdd() const
{
	return ConstructionheightAddition;
}
void ConstructionDescriptor::setConstructionHeightAdd(unsigned int _heightadd)
{
	ConstructionheightAddition = _heightadd;
}
unsigned int ConstructionDescriptor::getConstructionWidthAdd() const
{
	return ConstructionwidthAddition;
}
void ConstructionDescriptor::setConstructionWidthAdd(unsigned int _widthadd)
{
	ConstructionwidthAddition = _widthadd;
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
color ConstructionDescriptor::GetForegroundColor()
{
	return Foreground;
}
void ConstructionDescriptor::setForegroundColor(color _somecolor)
{
	Foreground = _somecolor;
}
color ConstructionDescriptor::GetBackgroundColor()
{
	return Background;
}
void ConstructionDescriptor::setBackgroundColor(color _somecolor)
{
	Background = _somecolor;
}
char ConstructionDescriptor::GetBuildingSymbol()
{
	return '0';
}
void ConstructionDescriptor::setbuildingsymbol(const char _buildingsymbol)
{}