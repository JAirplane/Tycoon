#include "ConstructionOptions.h"
/////////////Construction Options Class : Singleton patern/////////////
///////////////Height Addition Constants///////////////
const int ConstructionOptions::GetIceCreamShopHeightAdd() const
{
	return 1;
}
const int ConstructionOptions::GetMenuElementHeightAdd() const
{
	return 5;
}
const int ConstructionOptions::GetMenuIconHeightAdd() const
{
	return 3;
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
const int ConstructionOptions::GetConstructionInfoButtonHeightAdd() const
{
	return 2;
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
const int ConstructionOptions::GetMenuIconWidthAdd() const
{
	return 3;
}
const int ConstructionOptions::GetPlayingFieldWidthAdd() const
{
	return 129;
}
const int ConstructionOptions::GetInfoPanelWidthAdd() const
{
	return 115;
}
const int ConstructionOptions::GetInfoPanelButtonWidthAdd() const
{
	return 30;
}
const int ConstructionOptions::GetConstructionInfoButtonWidthAdd() const
{
	return 12;
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
const string ConstructionOptions::GetArrowsDescription() const
{
	return "Arrows to navigate on the playingfield / in menu";
}
const string ConstructionOptions::GetTabDescription() const
{
	return "Tab to switch between main screen and menu";
}
const string ConstructionOptions::GetEnterDescription() const
{
	return "Enter to press buttons / to build constructions";
}
const string ConstructionOptions::GetEscDescription() const
{
	return "Esc to deselect construction";
}
const string ConstructionOptions::GetHKeyDescription() const
{
	return "'H' key to hide / show menu elements";
}
const string ConstructionOptions::GetSKeyDescription() const
{
	return "'S' key to switch menu side";
}
const string ConstructionOptions::GetRKeyDescription() const
{
	return "'R' key rotates buildings";
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
color ConstructionOptions::GetIceCreamShopConnectedBackgroundColor() const
{
	return color::cDARK_CYAN;
}
color ConstructionOptions::GetIceCreamShopBackgroundColor() const
{
	return color::cDARK_CYAN;
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
color ConstructionOptions::GetCameraBorderForegroundColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetCameraBorderBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetCameraLetterColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetCameraShadingColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetPlayingFieldBorderForegroundColor() const
{
	return color::cDARK_GRAY;
}
color ConstructionOptions::GetPlayingFieldBorderBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetPlayingFieldLetterColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetPlayingFieldShadingColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetInfoPanelBorderForegroundColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetInfoPanelBorderBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetInfoPanelTextColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetInfoPanelShadingColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetSplashScreenForegroundColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetSplashScreenBackgroundColor() const
{
	return cDARK_CYAN;
}
color ConstructionOptions::GetMenuScreenBorderForegroundColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetMenuScreenBorderBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetMenuScreenTextColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetMenuScreenShadingColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetMenuBorderForegroundColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetMenuBorderBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetMenuLetterColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetMenuShadingColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetMenuIconForegroundColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetMenuIconBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetMenuIconLetterColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetMenuIconShadingColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetMenuElementInactiveColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::GetMenuElementActiveColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetMenuElementUnderConstructionColor() const
{
	return color::cRED;
}
color ConstructionOptions::GetMenuElementBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetMenuElementLetterColor() const
{
	return cDARK_GRAY;
}
color ConstructionOptions::GetMenuElementShadingColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetButtonBorderActiveColor() const
{
	return cGREEN;
}
color ConstructionOptions::GetButtonBorderInactiveColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetButtonBorderBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetButtonContentForegroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetButtonContentBackgroundColor() const
{
	return cDARK_CYAN;
}
color ConstructionOptions::GetControlsScreenBorderForegroundColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetControlsScreenBorderBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetControlsScreenLetterColor() const
{
	return cDARK_GREEN;
}
color ConstructionOptions::GetControlsScreenShadingColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetMessagesAndInfoScreenBorderForegroundColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetMessagesAndInfoScreenBorderBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetMessagesAndInfoScreenLetterColor() const
{
	return cDARK_GREEN;
}
color ConstructionOptions::GetMessagesAndInfoScreenShadingColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetMessagesPartScreenLetterColor() const
{
	return cBLUE;
}
color ConstructionOptions::GetMessagesPartScreenShadingColor() const
{
	return cYELLOW;
}
color ConstructionOptions::GetInfoPartScreenLetterColor() const
{
	return cGREEN;
}
color ConstructionOptions::GetInfoPartScreenShadingColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetConstructionInfoButtonBorderForegroundColor() const
{
	return cYELLOW;
}
color ConstructionOptions::GetConstructionInfoButtonBorderBackgroundColor() const
{
	return cGREEN;
}
color ConstructionOptions::GetConstructionInfoButtonLetterColor() const
{
	return cRED;
}
color ConstructionOptions::GetConstructionInfoButtonShadingColor() const
{
	return cBLACK;
}
//
color ConstructionOptions::GetConstructionInfoScreenIconBorderForegroundColor() const
{
	return cRED;
}
color ConstructionOptions::GetConstructionInfoScreenIconBorderBackgroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetConstructionInfoScreenIconLetterColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetConstructionInfoScreenIconShadingColor() const
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
const wstring ConstructionOptions::GetMenuScreenVerticalSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetMenuScreenHorizontalSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetMenuScreenUpperLeftSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetMenuScreenUpperRightSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetMenuScreenBottomLeftSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetMenuScreenBottomRightSymbol() const
{
	return wstring(L"#");
}
//
const wstring ConstructionOptions::GetMenuScreenButtonVerticalSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetMenuScreenButtonHorizontalSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetMenuScreenButtonUpperLeftSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetMenuScreenButtonUpperRightSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetMenuScreenButtonBottomLeftSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetMenuScreenButtonBottomRightSymbol() const
{
	return wstring(L"#");
}
//
const wstring ConstructionOptions::GetControlsVerticalSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetControlsHorizontalSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetControlsUpperLeftSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetControlsUpperRightSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetControlsBottomLeftSymbol() const
{
	return wstring(L"#");
}
const wstring ConstructionOptions::GetControlsBottomRightSymbol() const
{
	return wstring(L"#");
}
//
const wstring ConstructionOptions::GetMessagesAndInfoVerticalSymbol() const
{
	return wstring(L"@");
}
const wstring ConstructionOptions::GetMessagesAndInfoHorizontalSymbol() const
{
	return wstring(L"@");
}
const wstring ConstructionOptions::GetMessagesAndInfoUpperLeftSymbol() const
{
	return wstring(L"@");
}
const wstring ConstructionOptions::GetMessagesAndInfoUpperRightSymbol() const
{
	return wstring(L"@");
}
const wstring ConstructionOptions::GetMessagesAndInfoBottomLeftSymbol() const
{
	return wstring(L"@");
}
const wstring ConstructionOptions::GetMessagesAndInfoBottomRightSymbol() const
{
	return wstring(L"@");
}
//
const wstring ConstructionOptions::GetConstructionInfoButtonVerticalSymbol() const
{
	return wstring(L"*");
}
const wstring ConstructionOptions::GetConstructionInfoButtonHorizontalSymbol() const
{
	return wstring(L"*");
}
const wstring ConstructionOptions::GetConstructionInfoButtonUpperLeftSymbol() const
{
	return wstring(L"*");
}
const wstring ConstructionOptions::GetConstructionInfoButtonUpperRightSymbol() const
{
	return wstring(L"*");
}
const wstring ConstructionOptions::GetConstructionInfoButtonBottomLeftSymbol() const
{
	return wstring(L"*");
}
const wstring ConstructionOptions::GetConstructionInfoButtonBottomRightSymbol() const
{
	return wstring(L"*");
}
//
const wstring ConstructionOptions::GetConstructionInfoScreenIconVerticalSymbol() const
{
	return wstring(L"\u2593");
}
const wstring ConstructionOptions::GetConstructionInfoScreenIconHorizontalSymbol() const
{
	return wstring(L"\u2593");
}
const wstring ConstructionOptions::GetConstructionInfoScreenIconUpperLeftSymbol() const
{
	return wstring(L"\u2593");
}
const wstring ConstructionOptions::GetConstructionInfoScreenIconUpperRightSymbol() const
{
	return wstring(L"\u2593");
}
const wstring ConstructionOptions::GetConstructionInfoScreenIconBottomLeftSymbol() const
{
	return wstring(L"\u2593");
}
const wstring ConstructionOptions::GetConstructionInfoScreenIconBottomRightSymbol() const
{
	return wstring(L"\u2593");
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
const string ConstructionOptions::GetDeconstructButtonTitle() const
{
	return "Deconstruct";
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
///////////////Empty Border Rectangle Symbol///////////////
const wstring ConstructionOptions::GetEmptyRectangleBorderSymbol() const
{
	return wstring(L" ");
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