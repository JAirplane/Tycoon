#include "ConstructionOptions.h"
/////////////Construction Options Class : Singleton patern/////////////
///////////////Height Addition Constants///////////////
const int ConstructionOptions::GetIceCreamShopheightAdd() const
{
	return 1;
}
const int ConstructionOptions::GetMenuElementBordersHeight() const
{
	return 6;
}
const int ConstructionOptions::GetRoadheightAdd() const
{
	return 0;
}
const int ConstructionOptions::GetVisitorheightAdd() const
{
	return 0;
}
const int ConstructionOptions::GetCameraheightAdd() const
{
	return 34;
}
const int ConstructionOptions::GetMenuHeightAdd() const
{
	return 34;
}
const int ConstructionOptions::GetPlayingFieldheightAdd() const
{
	return 64;
}
///////////////Width Addition Constants///////////////
const int ConstructionOptions::GetIceCreamShopwidthAdd() const
{
	return 1;
}
const int ConstructionOptions::GetRoadwidthAdd() const
{
	return 0;
}
const int ConstructionOptions::GetVisitorwidthAdd() const
{
	return 0;
}
const int ConstructionOptions::GetCamerawidthAdd() const
{
	return 69;
}
const int ConstructionOptions::GetMenuWidthAdd() const
{
	return 45;
}
const int ConstructionOptions::GetPlayingFieldwidthAdd() const
{
	return 130;
}
///////////////Cost Initialisation Constants///////////////
const int ConstructionOptions::GetIceCreamShopointost() const
{
	return 250;
}
const int ConstructionOptions::GetRoadCost() const
{
	return 20;
}
///////////////Daily Expences Initialisation Constants///////////////
const int ConstructionOptions::GetIceCreamShopExpences() const
{
	return 20;
}
///////////////Description Initialisation Constants///////////////
const string ConstructionOptions::GetIceCreamShopDescription() const
{
	return "Ice cream! Everybody loves it!";
}
const string ConstructionOptions::GetRoadDescription() const
{
	return "visitors can walk roads only";
}
///////////////Building Symbol Constants///////////////
const char ConstructionOptions::GetIceCreamShopSymbol() const
{
	return '!';
}
///////////////PlayingField Symbol Constants///////////////
const wchar_t ConstructionOptions::GetVerticalPlayingField() const
{
	return '\u2503';
}
const wchar_t ConstructionOptions::GetHorizontalPlayingField() const
{
	return '\u2501';
}
const wchar_t ConstructionOptions::GetUpperLeftPlayingField() const
{
	return '\u250f';
}
const wchar_t ConstructionOptions::GetUpperRightPlayingField() const
{
	return '\u2513';
}
const wchar_t ConstructionOptions::GetBottomLeftPlayingField() const
{
	return '\u2517';
}
const wchar_t ConstructionOptions::GetBottomRightPlayingField() const
{
	return '\u251b';
}
///////////////Initialisation Coord Constants///////////////
const PointCoord ConstructionOptions::GetCameraInitialUpperLeft() const
{
	return PointCoord(1, 1);
}
const PointCoord ConstructionOptions::GetPlayingFieldUpperLeft() const
{
	return PointCoord(-30, -30);
}
///////////////Building's Icon Symbol Constants///////////////
const char ConstructionOptions::GetIceCreamShopIconSymbol() const
{
	return '!';
}
const char ConstructionOptions::GetRoadIconSymbol() const
{
	return '+';
}
///////////////Color Construction Constants///////////////
color ConstructionOptions::GetIceCreamShopForegroundColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::GetIceCreamShopBackgroundColor() const
{
	return color::cDARK_CYAN;
}
color ConstructionOptions::GetRoadForegroundColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetRoadBackgroundColor() const
{
	return color::cDARK_GRAY;
}
color ConstructionOptions::GetCursorBackgroundColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::GetPlayingFieldColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetMenuBorderInactiveColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::GetMenuBorderActiveColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetMenuBorderUnderConstructionColor() const
{
	return color::cRED;
}
///////////////ConstructionOptions Initialisation and using///////////////
ConstructionOptions* ConstructionOptions::GetAllOptions()
{
	return constructionParameters;
}
ConstructionOptions* ConstructionOptions::constructionParameters = new ConstructionOptions();