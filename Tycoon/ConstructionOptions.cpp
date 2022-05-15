#include "ConstructionOptions.h"
/////////////Construction Options Class : Singleton patern/////////////
///////////////Height Addition Constants///////////////
const int ConstructionOptions::GetMenuElementHeightAdd() const
{
	return 5;
}
const int ConstructionOptions::GetMenuIconHeightAdd() const
{
	return 3;
}
const int ConstructionOptions::GetGameStatsHeightAdd() const
{
	return 3;
}
const int ConstructionOptions::GetVisitorHeightAdd() const
{
	return 0;
}
const int ConstructionOptions::GetCameraHeightAdd() const
{
	return 35;
}
const int ConstructionOptions::GetMenuHeightAdd() const
{
	return 35;
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
const int ConstructionOptions::GetPressAnyKeyHeightAdd() const
{
	return 2;
}
const int ConstructionOptions::GetNewGameButtonHeightAdd() const
{
	return 4;
}
const int ConstructionOptions::GetContinueButtonHeightAdd() const
{
	return 4;
}
const int ConstructionOptions::GetExitButtonHeightAdd() const
{
	return 4;
}
///////////////Width Addition Constants///////////////
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
const int ConstructionOptions::GetPressAnyKeyWidthAdd() const
{
	return 14;
}
const int ConstructionOptions::GetNewGameButtonWidthAdd() const
{
	return 20;
}
const int ConstructionOptions::GetContinueButtonWidthAdd() const
{
	return 20;
}
const int ConstructionOptions::GetExitButtonWidthAdd() const
{
	return 20;
}
///////////////Description Initialisation Constants///////////////
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
	return PointCoord(1, 37);
}
const PointCoord ConstructionOptions::GetInitialSplashScreenUpperLeft() const
{
	return PointCoord(1, 1);
}
const PointCoord ConstructionOptions::GetMainMenuUpperLeft() const
{
	return PointCoord(1, 1);
}
///////////////Color Construction Constants///////////////
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
	return color::cBLACK;
}
color ConstructionOptions::GetCameraLetterColor() const
{
	return color::cWHITE;
}
color ConstructionOptions::GetCameraShadingColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetPlayingFieldBorderForegroundColor() const
{
	return color::cDARK_GRAY;
}
color ConstructionOptions::GetPlayingFieldBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetPlayingFieldLetterColor() const
{
	return color::cWHITE;
}
color ConstructionOptions::GetPlayingFieldShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetInfoPanelBorderForegroundColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetInfoPanelBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetInfoPanelTextColor() const
{
	return color::cCYAN;
}
color ConstructionOptions::GetInfoPanelShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetSplashScreenForegroundColor() const
{
	return color::cWHITE;
}
color ConstructionOptions::GetSplashScreenBackgroundColor() const
{
	return cDARK_CYAN;
}
//
color ConstructionOptions::GetMenuScreenBorderForegroundColor() const
{
	return color::cWHITE;
}
color ConstructionOptions::GetMenuScreenBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetMenuScreenTextColor() const
{
	return color::cWHITE;
}
color ConstructionOptions::GetMenuScreenShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetMenuBorderForegroundColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetMenuBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetMenuLetterColor() const
{
	return color::cWHITE;
}
color ConstructionOptions::GetMenuShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetGameStatsBorderForegroundColor() const
{
	return color::cCYAN;
}
color ConstructionOptions::GetGameStatsBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetGameStatsLetterColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetGameStatsShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetMenuIconForegroundColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetMenuIconBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetMenuIconLetterColor() const
{
	return color::cWHITE;
}
color ConstructionOptions::GetMenuIconShadingColor() const
{
	return color::cBLACK;
}
//
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
	return color::cBLACK;
}
color ConstructionOptions::GetMenuElementLetterColor() const
{
	return color::cDARK_GRAY;
}
color ConstructionOptions::GetMenuElementShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetButtonBorderActiveColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetButtonBorderInactiveColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::GetButtonDisabledColor() const
{
	return cDARK_GRAY;
}
color ConstructionOptions::GetButtonBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetButtonContentForegroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetButtonContentBackgroundColor() const
{
	return color::cDARK_CYAN;
}
//
color ConstructionOptions::GetControlsScreenBorderForegroundColor() const
{
	return color::cWHITE;
}
color ConstructionOptions::GetControlsScreenBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetControlsScreenLetterColor() const
{
	return color::cDARK_GREEN;
}
color ConstructionOptions::GetControlsScreenShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetMessagesAndInfoScreenBorderForegroundColor() const
{
	return color::cWHITE;
}
color ConstructionOptions::GetMessagesAndInfoScreenBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetMessagesAndInfoScreenLetterColor() const
{
	return color::cDARK_GREEN;
}
color ConstructionOptions::GetMessagesAndInfoScreenShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetMessagesPartScreenLetterColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetMessagesPartScreenShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetInfoPartScreenLetterColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetInfoPartScreenShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetConstructionInfoButtonBorderForegroundColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::GetConstructionInfoButtonBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetConstructionInfoButtonLetterColor() const
{
	return color::cRED;
}
color ConstructionOptions::GetConstructionInfoButtonShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetConstructionInfoScreenIconBorderForegroundColor() const
{
	return color::cYELLOW;
}
color ConstructionOptions::GetConstructionInfoScreenIconBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetConstructionInfoScreenIconLetterColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetConstructionInfoScreenIconShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetInitialSplashScreenBorderForegroundColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetInitialSplashScreenBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetInitialSplashScreenLetterColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetInitialSplashScreenShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetPressAnyKeyBorderForegroundColor() const
{
	return color::cWHITE;
}
color ConstructionOptions::GetPressAnyKeyBorderBackgroundColor() const
{
	return color::cRED;
}
color ConstructionOptions::GetPressAnyKeyLetterColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetPressAnyKeyShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetMainMenuBorderForegroundColor() const
{
	return color::cBLUE;
}
color ConstructionOptions::GetMainMenuBorderBackgroundColor() const
{
	return color::cBLACK;
}
color ConstructionOptions::GetMainMenuLetterColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetMainMenuShadingColor() const
{
	return color::cBLACK;
}
//
color ConstructionOptions::GetNewGameButtonBorderForegroundColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetNewGameButtonBorderBackgroundColor() const
{
	return cBROWN;
}
color ConstructionOptions::GetNewGameButtonLetterColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetNewGameButtonShadingColor() const
{
	return cBLACK;
}
//
color ConstructionOptions::GetContinueButtonBorderForegroundColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetContinueButtonBorderBackgroundColor() const
{
	return cBROWN;
}
color ConstructionOptions::GetContinueButtonLetterColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetContinueButtonShadingColor() const
{
	return cBLACK;
}
//
color ConstructionOptions::GetExitButtonBorderForegroundColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetExitButtonBorderBackgroundColor() const
{
	return cBROWN;
}
color ConstructionOptions::GetExitButtonLetterColor() const
{
	return cWHITE;
}
color ConstructionOptions::GetExitButtonShadingColor() const
{
	return cBLACK;
}
//
color ConstructionOptions::GetVisitorForegroundColor() const
{
	return cYELLOW;
}
color ConstructionOptions::GetVisitorBackgroundColor() const
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
///////////////Game Stats Border Symbol Constants///////////////
const wstring ConstructionOptions::GetGameStatsVerticalSymbol() const
{
	return wstring(L"\u2551");
}
const wstring ConstructionOptions::GetGameStatsHorizontalSymbol() const
{
	return wstring(L"\u2550");
}
const wstring ConstructionOptions::GetGameStatsUpperLeftSymbol() const
{
	return wstring(L"\u2554");
}
const wstring ConstructionOptions::GetGameStatsUpperRightSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetGameStatsBottomLeftSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetGameStatsBottomRightSymbol() const
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
	return wstring(L"\u2551");
}
const wstring ConstructionOptions::GetConstructionInfoButtonHorizontalSymbol() const
{
	return wstring(L"\u2550");
}
const wstring ConstructionOptions::GetConstructionInfoButtonUpperLeftSymbol() const
{
	return wstring(L"\u2554");
}
const wstring ConstructionOptions::GetConstructionInfoButtonUpperRightSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetConstructionInfoButtonBottomLeftSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetConstructionInfoButtonBottomRightSymbol() const
{
	return wstring(L"\u255D");
}
//
const wstring ConstructionOptions::GetConstructionInfoScreenIconVerticalSymbol() const
{
	return wstring(L"\u00A7");
}
const wstring ConstructionOptions::GetConstructionInfoScreenIconHorizontalSymbol() const
{
	return wstring(L"\u00A7");
}
const wstring ConstructionOptions::GetConstructionInfoScreenIconUpperLeftSymbol() const
{
	return wstring(L"\u00A7");
}
const wstring ConstructionOptions::GetConstructionInfoScreenIconUpperRightSymbol() const
{
	return wstring(L"\u00A7");
}
const wstring ConstructionOptions::GetConstructionInfoScreenIconBottomLeftSymbol() const
{
	return wstring(L"\u00A7");
}
const wstring ConstructionOptions::GetConstructionInfoScreenIconBottomRightSymbol() const
{
	return wstring(L"\u00A7");
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
const string ConstructionOptions::GetNewGameButtonTitle() const
{
	return "New Game";
}
const string ConstructionOptions::GetContinueButtonTitle() const
{
	return "Continue";
}
const string ConstructionOptions::GetExitButtonTitle() const
{
	return "Exit";
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
///////////////Initial Splash Screen Border Symbol Constants///////////////
const wstring ConstructionOptions::GetInitialSplashScreenVerticalSymbol() const
{
	return wstring(L"\u2551");
}
const wstring ConstructionOptions::GetInitialSplashScreenHorizontalSymbol() const
{
	return wstring(L"\u2550");
}
const wstring ConstructionOptions::GetInitialSplashScreenUpperLeftSymbol() const
{
	return wstring(L"\u2554");
}
const wstring ConstructionOptions::GetInitialSplashScreenUpperRightSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetInitialSplashScreenBottomLeftSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetInitialSplashScreenBottomRightSymbol() const
{
	return wstring(L"\u255D");
}
//
const wstring ConstructionOptions::GetPressAnyKeyVerticalSymbol() const
{
	return L"*";
}
const wstring ConstructionOptions::GetPressAnyKeyHorizontalSymbol() const
{
	return L"*";
}
const wstring ConstructionOptions::GetPressAnyKeyUpperLeftSymbol() const
{
	return L"*";
}
const wstring ConstructionOptions::GetPressAnyKeyUpperRightSymbol() const
{
	return L"*";
}
const wstring ConstructionOptions::GetPressAnyKeyBottomLeftSymbol() const
{
	return L"*";
}
const wstring ConstructionOptions::GetPressAnyKeyBottomRightSymbol() const
{
	return L"*";
}
//
const wstring ConstructionOptions::GetMainMenuVerticalSymbol() const
{
	return wstring(L"\u2551");
}
const wstring ConstructionOptions::GetMainMenuHorizontalSymbol() const
{
	return wstring(L"\u2550");
}
const wstring ConstructionOptions::GetMainMenuUpperLeftSymbol() const
{
	return wstring(L"\u2554");
}
const wstring ConstructionOptions::GetMainMenuUpperRightSymbol() const
{
	return wstring(L"\u2557");
}
const wstring ConstructionOptions::GetMainMenuBottomLeftSymbol() const
{
	return wstring(L"\u255A");
}
const wstring ConstructionOptions::GetMainMenuBottomRightSymbol() const
{
	return wstring(L"\u255D");
}
//
const wstring ConstructionOptions::GetNewGameButtonVerticalSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetNewGameButtonHorizontalSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetNewGameButtonUpperLeftSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetNewGameButtonUpperRightSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetNewGameButtonBottomLeftSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetNewGameButtonBottomRightSymbol() const
{
	return L"#";
}
//
const wstring ConstructionOptions::GetContinueButtonVerticalSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetContinueButtonHorizontalSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetContinueButtonUpperLeftSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetContinueButtonUpperRightSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetContinueButtonBottomLeftSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetContinueButtonBottomRightSymbol() const
{
	return L"#";
}
//
const wstring ConstructionOptions::GetExitButtonVerticalSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetExitButtonHorizontalSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetExitButtonUpperLeftSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetExitButtonUpperRightSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetExitButtonBottomLeftSymbol() const
{
	return L"#";
}
const wstring ConstructionOptions::GetExitButtonBottomRightSymbol() const
{
	return L"#";
}
//
const wstring ConstructionOptions::GetVisitorSymbol() const
{
	return L"\u263A";
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
ConstructionOptions* ConstructionOptions::CreateConstructionOptions()
{
	return new ConstructionOptions();
}
ConstructionOptions* ConstructionOptions::constructionParameters = ConstructionOptions::CreateConstructionOptions();