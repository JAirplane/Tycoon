#include "ConstructionOptions.h"
/////////////Construction Options Class : Singleton patern/////////////
///////////////Height Addition Constants///////////////
const int ConstructionOptions::GetIceCreamShopHeightAdd() const
{
	return 1;
}
const int ConstructionOptions::GetMenuElementBordersHeight() const
{
	return 6;
}
const int ConstructionOptions::GetRoadHeightAdd() const
{
	return 0;
}
const int ConstructionOptions::GetVisitorHeightAdd() const
{
	return 0;
}
const int ConstructionOptions::GetCameraHeightAdd() const
{
	return 34;
}
const int ConstructionOptions::GetMenuHeightAdd() const
{
	return 34;
}
const int ConstructionOptions::GetPlayingFieldHeightAdd() const
{
	return 64;
}
///////////////Width Addition Constants///////////////
const int ConstructionOptions::GetIceCreamShopWidthAdd() const
{
	return 1;
}
const int ConstructionOptions::GetRoadWidthAdd() const
{
	return 0;
}
const int ConstructionOptions::GetVisitorWidthAdd() const
{
	return 0;
}
const int ConstructionOptions::GetCameraWidthAdd() const
{
	return 69;
}
const int ConstructionOptions::GetMenuWidthAdd() const
{
	return 45;
}
const int ConstructionOptions::GetPlayingFieldWidthAdd() const
{
	return 130;
}
///////////////Cost Initialisation Constants///////////////
const int ConstructionOptions::GetIceCreamShopCost() const
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
	return "Visitors can walk roads only";
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