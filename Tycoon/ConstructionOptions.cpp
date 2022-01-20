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
	return 62;
}
const int ConstructionOptions::GetInfoPanelHeightAdd() const
{
	return 10;
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
	return 129;
}
const int ConstructionOptions::GetInfoPanelWidthAdd() const
{
	return 115;
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
///////////////Initialisation Coord Constants///////////////
const PointCoord ConstructionOptions::GetCameraInitialUpperLeft() const
{
	return PointCoord(1, 1);
}
const PointCoord ConstructionOptions::GetPlayingFieldUpperLeft() const
{
	return PointCoord(-30, -30);
}
const PointCoord ConstructionOptions::GetInfoPanelUpperLeft() const
{
	return PointCoord(1, 36);
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
color ConstructionOptions::GetPlayingFieldColor() const
{
	return color::cDARK_GRAY;
}
color ConstructionOptions::GetInfoPanelColor() const
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
color ConstructionOptions::GetSplashScreenForegroundColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetSplashScreenBackgroundColor() const
{
	return cDARK_CYAN;
}
color ConstructionOptions::GetInfoScreenBorderForegroundColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetInfoScreenBorderBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetButtonBorderActiveColor() const
{
	return cGREEN;
}
color ConstructionOptions::GetButtonContentForegroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetButtonContentBackgroundColor() const
{
	return cDARK_CYAN;
}
color ConstructionOptions::GetControlsScreenForegroundColor() const
{
	return cCYAN;
}
color ConstructionOptions::GetControlsScreenBackgroundColor() const
{
	return cBLACK;
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
///////////////Menu Border Symbol Constants///////////////
const wstring ConstructionOptions::GetMenuVerticalSymbol() const
{
	return wstring(L"\u2551");
}
const wstring ConstructionOptions::GetMenuHorizontalSymbol() const
{
	return wstring(L"\u2550");
}
const wstring ConstructionOptions::GetMenuUpperLeftSymbol() const
{
	return wstring(L"\u2554");
}
const wstring ConstructionOptions::GetMenuUpperRightSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetMenuBottomLeftSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetMenuBottomRightSymbol() const
{
	return wstring(L"\u255D");
}
///////////////InfoPanel Border Symbol Constants///////////////
const wstring ConstructionOptions::GetInfoPanelVerticalSymbol() const
{
	return wstring(L"\u2551");
}
const wstring ConstructionOptions::GetInfoPanelHorizontalSymbol() const
{
	return wstring(L"\u2550");
}
const wstring ConstructionOptions::GetInfoPanelUpperLeftSymbol() const
{
	return wstring(L"\u2554");
}
const wstring ConstructionOptions::GetInfoPanelUpperRightSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetInfoPanelBottomLeftSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetInfoPanelBottomRightSymbol() const
{
	return wstring(L"\u255D");
}
//
const wstring ConstructionOptions::GetInfoScreenVerticalSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetInfoScreenHorizontalSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetInfoScreenUpperLeftSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetInfoScreenUpperRightSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetInfoScreenBottomLeftSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetInfoScreenBottomRightSymbol() const
{
	return wstring(L"#");
}
//
const wstring ConstructionOptions::GetInfoScreenButtonVerticalSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetInfoScreenButtonHorizontalSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetInfoScreenButtonUpperLeftSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetInfoScreenButtonUpperRightSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetInfoScreenButtonBottomLeftSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetInfoScreenButtonBottomRightSymbol() const
{
	return wstring(L"#");
}
//
const wstring ConstructionOptions::GetControlsVerticalSymbol() const
{
	return wstring(L"@");
}
const wstring ConstructionOptions::GetControlsHorizontalSymbol() const
{
	return wstring(L"@");
}
const wstring ConstructionOptions::GetControlsUpperLeftSymbol() const
{
	return wstring(L"@");
}
const wstring ConstructionOptions::GetControlsUpperRightSymbol() const
{
	return wstring(L"@");
}
const wstring ConstructionOptions::GetControlsBottomLeftSymbol() const
{
	return wstring(L"@");
}
const wstring ConstructionOptions::GetControlsBottomRightSymbol() const
{
	return wstring(L"@");
}
//
const string ConstructionOptions::GetControlsButtonTitle() const
{
	return "CONTROLS";
}
const string ConstructionOptions::GetInfoScreenButtonTitle() const
{
	return "MESSAGES AND INFO";
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
	return wstring(L"\u2554");
}
const wstring ConstructionOptions::GetCameraUpperRightSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetCameraBottomLeftSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetCameraBottomRightSymbol() const
{
	return wstring(L"\u255D");
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
	return wstring(L"\u2554");
}
const wstring ConstructionOptions::GetMenuItemUpperRightSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetMenuItemBottomLeftSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetMenuItemBottomRightSymbol() const
{
	return wstring(L"\u255D");
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
	return wstring(L"\u2554");
}
const wstring ConstructionOptions::GetMenuIconUpperRightSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetMenuIconBottomLeftSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetMenuIconBottomRightSymbol() const
{
	return wstring(L"\u255D");
}
///////////////Indent Constants///////////////
const int ConstructionOptions::GetInfoPanelAboveIndent() const
{
	return 2;
}
const int ConstructionOptions::GetInfoPanelBottomIndent() const
{
	return 2;
}
const int ConstructionOptions::GetInfoPanelLeftIndent() const
{
	return 2;
}
const int ConstructionOptions::GetInfoPanelRightIndent() const
{
	return 2;
}
///////////////ConstructionOptions Initialisation and using///////////////
ConstructionOptions* ConstructionOptions::GetAllOptions()
{
	return constructionParameters;
}
ConstructionOptions* ConstructionOptions::constructionParameters = new ConstructionOptions();