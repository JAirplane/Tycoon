#include "ConstructionOptions.h"
/////////////Construction Options Class : Singleton patern/////////////
///////////////Height Addition Constants///////////////
const int ConstructionOptions::getIceCreamShopHeightAdd() const
{
	return 1;
}
const int ConstructionOptions::getMenuElementBordersHeight() const
{
	return 6;
}
const int ConstructionOptions::getRoadHeightAdd() const
{
	return 0;
}
const int ConstructionOptions::getVisitorHeightAdd() const
{
	return 0;
}
const int ConstructionOptions::getVisibleMapHeight() const
{
	return 34;
}
const int ConstructionOptions::getMenuHeightAdd() const
{
	return 34;
}
///////////////Width Addition Constants///////////////
const int ConstructionOptions::getIceCreamShopWidthAdd() const
{
	return 1;
}
const int ConstructionOptions::getRoadWidthAdd() const
{
	return 0;
}
const int ConstructionOptions::getVisitorWidthAdd() const
{
	return 0;
}
const int ConstructionOptions::getVisibleMapWidth() const
{
	return 69;
}
const int ConstructionOptions::getMenuWidthAdd() const
{
	return 45;
}
///////////////Cost Initialisation Constants///////////////
const int ConstructionOptions::getIceCreamShopCost() const
{
	return 250;
}
const int ConstructionOptions::getRoadCost() const
{
	return 20;
}
///////////////Daily Expences Initialisation Constants///////////////
const int ConstructionOptions::getIceCreamShopExpences() const
{
	return 20;
}
///////////////Description Initialisation Constants///////////////
const string ConstructionOptions::getIceCreamShopDescription() const
{
	return "Ice cream! Everybody loves it!";
}
const string ConstructionOptions::getRoadDescription() const
{
	return "Visitors can walk roads only";
}
///////////////Building Symbol Constants///////////////
const char ConstructionOptions::getIceCreamShopSymbol() const
{
	return '!';
}
///////////////Initialisation Coord Constants///////////////
const PointCoord ConstructionOptions::getVisibleMapInitialCoordUL() const
{
	return PointCoord(1, 1);
}
///////////////Building's Icon Symbol Constants///////////////
const char ConstructionOptions::getIceCreamShopIconSymbol() const
{
	return '!';
}
const char ConstructionOptions::getRoadIconSymbol() const
{
	return '+';
}
///////////////Color Construction Constants///////////////
color ConstructionOptions::getIceCreamShopForegroundColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::getIceCreamShopBackgroundColor() const
{
	return color::cDARK_CYAN;
}
color ConstructionOptions::getRoadForegroundColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::getRoadBackgroundColor() const
{
	return color::cDARK_GRAY;
}
color ConstructionOptions::getCursorBackgroundColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::getPlayingFieldColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::getMenuBorderInactiveColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::getMenuBorderActiveColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::getMenuBorderUnderConstructionColor() const
{
	return color::cRED;
}
///////////////ConstructionOptions Initialisation and using///////////////
ConstructionOptions* ConstructionOptions::getAllOptions()
{
	return ConstructionParameters;
}
ConstructionOptions* ConstructionOptions::ConstructionParameters = new ConstructionOptions();