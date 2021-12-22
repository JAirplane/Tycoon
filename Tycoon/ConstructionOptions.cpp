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
	return "visitors can walk roads only";
}
///////////////Building Symbol Constants///////////////
const wstring ConstructionOptions::GetIceCreamShopSymbol() const
{
	wstring symbol = L"\u25D9";
	return symbol;
}
///////////////PlayingField Symbol Constants///////////////
const wstring ConstructionOptions::GetVerticalPlayingField() const
{
	wstring symbol = L"\u2503";
	return symbol;
}
const wstring ConstructionOptions::GetHorizontalPlayingField() const
{
	wstring symbol = L"\u2501";
	return symbol;
}
const wstring ConstructionOptions::GetUpperLeftPlayingField() const
{
	wstring symbol = L"\u250f";
	return symbol;
}
const wstring ConstructionOptions::GetUpperRightPlayingField() const
{
	wstring symbol = L"\u2513";
	return symbol;
}
const wstring ConstructionOptions::GetBottomLeftPlayingField() const
{
	wstring symbol = L"\u2517";
	return symbol;
}
const wstring ConstructionOptions::GetBottomRightPlayingField() const
{
	wstring symbol = L"\u251b";
	return symbol;
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
const wstring ConstructionOptions::GetIceCreamShopIconSymbol() const
{
	wstring symbol = L"\u25D9";
	return symbol;
}
const wstring ConstructionOptions::GetRoadIconSymbol() const
{
	wstring symbol = L"\u2016";
	return symbol;
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
color ConstructionOptions::GetCameraColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetMenuColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetMenuIconColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetMenuItemInactiveColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::GetMenuItemActiveColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetMenuItemUnderConstructionColor() const
{
	return color::cRED;
}
///////////////Menu Border Symbol Constants///////////////
const wstring ConstructionOptions::GetMenuVerticalSymbol() const
{
	return wstring(L"\u2551");
}
const wstring ConstructionOptions::GetMenuHorizontalSymbol() const
{
	wstring(L"\u2550");
}
const wstring ConstructionOptions::GetMenuUpperLeftSymbol() const
{
	return wstring(L"\u255D");
}
const wstring ConstructionOptions::GetMenuUpperRightSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetMenuBottomLeftSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetMenuBottomRightSymbol() const
{
	return wstring(L"\u2554");
}
///////////////Camera Border Symbol Constants///////////////
const wstring ConstructionOptions::GetCameraVerticalSymbol() const
{
	return wstring(L"\u2551");
}
const wstring ConstructionOptions::GetCameraHorizontalSymbol() const
{
	return wstring(L"\u2550");
}
const wstring ConstructionOptions::GetCameraUpperLeftSymbol() const
{
	return wstring(L"\u255D");
}
const wstring ConstructionOptions::GetCameraUpperRightSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetCameraBottomLeftSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetCameraBottomRightSymbol() const
{
	return wstring(L"\u2554");
}
///////////////Menu Item Border Symbol Constants///////////////
const wstring ConstructionOptions::GetMenuItemVerticalSymbol() const
{
	return wstring(L"\u2551");
}
const wstring ConstructionOptions::GetMenuItemHorizontalSymbol() const
{
	return wstring(L"\u2550");
}
const wstring ConstructionOptions::GetMenuItemUpperLeftSymbol() const
{
	return wstring(L"\u255D");
}
const wstring ConstructionOptions::GetMenuItemUpperRightSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetMenuItemBottomLeftSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetMenuItemBottomRightSymbol() const
{
	return wstring(L"\u2554");
}
///////////////Menu Icon Border Symbol Constants///////////////
const wstring ConstructionOptions::GetMenuIconVerticalSymbol() const
{
	return wstring(L"\u2551");
}
const wstring ConstructionOptions::GetMenuIconHorizontalSymbol() const
{
	return wstring(L"\u2550");
}
const wstring ConstructionOptions::GetMenuIconUpperLeftSymbol() const
{
	return wstring(L"\u255D");
}
const wstring ConstructionOptions::GetMenuIconUpperRightSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetMenuIconBottomLeftSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetMenuIconBottomRightSymbol() const
{
	return wstring(L"\u2554");
}
///////////////ConstructionOptions Initialisation and using///////////////
ConstructionOptions* ConstructionOptions::GetAllOptions()
{
	return constructionParameters;
}
ConstructionOptions* ConstructionOptions::constructionParameters = new ConstructionOptions();