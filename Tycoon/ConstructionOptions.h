#pragma once
#include "FindByPoint.h"
#include <string>
/////////////Construction Options Class : Singleton pattern/////////////
class ConstructionOptions
{
protected:
	ConstructionOptions() {}
	~ConstructionOptions()
	{
		delete constructionParameters;
	}
	static ConstructionOptions* constructionParameters;
public:
	ConstructionOptions(ConstructionOptions& other) = delete;
	void operator=(const ConstructionOptions&) = delete;
	static ConstructionOptions* CreateConstructionOptions();
	static ConstructionOptions* GetAllOptions();
	///////////////Height Addition Constants///////////////
	virtual const int GetMenuElementHeightAdd() const; //height of 1 element of menu
	virtual const int GetMenuIconHeightAdd() const;
	virtual const int GetGameStatsHeightAdd() const;
	virtual const int GetVisitorHeightAdd() const;
	virtual const int GetCameraHeightAdd() const;
	virtual const int GetMenuHeightAdd() const;
	virtual const int GetPlayingFieldHeightAdd() const;
	virtual const int GetInfoPanelHeightAdd() const;
	virtual const int GetConstructionInfoButtonHeightAdd() const;
	virtual const int GetPressAnyKeyHeightAdd() const;
	virtual const int GetNewGameButtonHeightAdd() const;
	virtual const int GetContinueButtonHeightAdd() const;
	virtual const int GetExitButtonHeightAdd() const;
	///////////////Width Addition Constants///////////////
	virtual const int GetVisitorWidthAdd() const;
	virtual const int GetCameraWidthAdd() const;
	virtual const int GetMenuWidthAdd() const;
	virtual const int GetMenuIconWidthAdd() const;
	virtual const int GetPlayingFieldWidthAdd() const;
	virtual const int GetInfoPanelWidthAdd() const;
	virtual const int GetInfoPanelButtonWidthAdd() const;
	virtual const int GetConstructionInfoButtonWidthAdd() const;
	virtual const int GetPressAnyKeyWidthAdd() const;
	virtual const int GetNewGameButtonWidthAdd() const;
	virtual const int GetContinueButtonWidthAdd() const;
	virtual const int GetExitButtonWidthAdd() const;
	///////////////Description Initialisation Constants///////////////
	virtual const string GetArrowsDescription() const;
	virtual const string GetTabDescription() const;
	virtual const string GetEnterDescription() const;
	virtual const string GetEscDescription() const;
	virtual const string GetHKeyDescription() const;
	virtual const string GetSKeyDescription() const;
	virtual const string GetRKeyDescription() const;
	///////////////Initialisation Coord Constants///////////////
	virtual const PointCoord GetCameraInitialUpperLeft() const;
	virtual const PointCoord GetPlayingFieldUpperLeft() const;
	virtual const PointCoord GetInfoPanelUpperLeft() const;
	virtual const PointCoord GetInitialSplashScreenUpperLeft() const;
	virtual const PointCoord GetMainMenuUpperLeft() const;
	///////////////Color Constants///////////////
	virtual color GetCursorBackgroundColor() const;
	//
	virtual color GetCameraBorderForegroundColor() const;
	virtual color GetCameraBorderBackgroundColor() const;
	virtual color GetCameraLetterColor() const;
	virtual color GetCameraShadingColor() const;
	//
	virtual color GetPlayingFieldBorderForegroundColor() const;
	virtual color GetPlayingFieldBorderBackgroundColor() const;
	virtual color GetPlayingFieldLetterColor() const;
	virtual color GetPlayingFieldShadingColor() const;
	//
	virtual color GetInfoPanelBorderForegroundColor() const;
	virtual color GetInfoPanelBorderBackgroundColor() const;
	virtual color GetInfoPanelTextColor() const;
	virtual color GetInfoPanelShadingColor() const;
	//
	virtual color GetSplashScreenForegroundColor() const;
	virtual color GetSplashScreenBackgroundColor() const;
	//
	virtual color GetMenuScreenBorderForegroundColor() const;
	virtual color GetMenuScreenBorderBackgroundColor() const;
	virtual color GetMenuScreenTextColor() const;
	virtual color GetMenuScreenShadingColor() const;
	//
	virtual color GetMenuBorderForegroundColor() const;
	virtual color GetMenuBorderBackgroundColor() const;
	virtual color GetMenuLetterColor() const;
	virtual color GetMenuShadingColor() const;
	//
	virtual color GetGameStatsBorderForegroundColor() const;
	virtual color GetGameStatsBorderBackgroundColor() const;
	virtual color GetGameStatsLetterColor() const;
	virtual color GetGameStatsShadingColor() const;
	//
	virtual color GetMenuIconForegroundColor() const;
	virtual color GetMenuIconBackgroundColor() const;
	virtual color GetMenuIconLetterColor() const;
	virtual color GetMenuIconShadingColor() const;
	//
	virtual color GetMenuElementInactiveColor() const;
	virtual color GetMenuElementActiveColor() const;
	virtual color GetMenuElementUnderConstructionColor() const;
	virtual color GetMenuElementBackgroundColor() const;
	virtual color GetMenuElementLetterColor() const;
	virtual color GetMenuElementShadingColor() const;
	//
	virtual color GetButtonBorderActiveColor() const;
	virtual color GetButtonBorderInactiveColor() const;
	virtual color GetButtonDisabledColor() const;
	virtual color GetButtonBorderBackgroundColor() const;
	virtual color GetButtonContentForegroundColor() const;
	virtual color GetButtonContentBackgroundColor() const;
	//
	virtual color GetControlsScreenBorderForegroundColor() const;
	virtual color GetControlsScreenBorderBackgroundColor() const;
	virtual color GetControlsScreenLetterColor() const;
	virtual color GetControlsScreenShadingColor() const;
	//
	virtual color GetMessagesAndInfoScreenBorderForegroundColor() const;
	virtual color GetMessagesAndInfoScreenBorderBackgroundColor() const;
	virtual color GetMessagesAndInfoScreenLetterColor() const;
	virtual color GetMessagesAndInfoScreenShadingColor() const;
	//
	virtual color GetMessagesPartScreenLetterColor() const;
	virtual color GetMessagesPartScreenShadingColor() const;
	//
	virtual color GetInfoPartScreenLetterColor() const;
	virtual color GetInfoPartScreenShadingColor() const;
	//
	virtual color GetConstructionInfoButtonBorderForegroundColor() const;
	virtual color GetConstructionInfoButtonBorderBackgroundColor() const;
	virtual color GetConstructionInfoButtonLetterColor() const;
	virtual color GetConstructionInfoButtonShadingColor() const;
	//
	virtual color GetConstructionInfoScreenIconBorderForegroundColor() const;
	virtual color GetConstructionInfoScreenIconBorderBackgroundColor() const;
	virtual color GetConstructionInfoScreenIconLetterColor() const;
	virtual color GetConstructionInfoScreenIconShadingColor() const;
	//
	virtual color GetInitialSplashScreenBorderForegroundColor() const;
	virtual color GetInitialSplashScreenBorderBackgroundColor() const;
	virtual color GetInitialSplashScreenLetterColor() const;
	virtual color GetInitialSplashScreenShadingColor() const;
	//
	virtual color GetPressAnyKeyBorderForegroundColor() const;
	virtual color GetPressAnyKeyBorderBackgroundColor() const;
	virtual color GetPressAnyKeyLetterColor() const;
	virtual color GetPressAnyKeyShadingColor() const;
	//
	virtual color GetMainMenuBorderForegroundColor() const;
	virtual color GetMainMenuBorderBackgroundColor() const;
	virtual color GetMainMenuLetterColor() const;
	virtual color GetMainMenuShadingColor() const;
	//
	virtual color GetNewGameButtonBorderForegroundColor() const;
	virtual color GetNewGameButtonBorderBackgroundColor() const;
	virtual color GetNewGameButtonLetterColor() const;
	virtual color GetNewGameButtonShadingColor() const;
	//
	virtual color GetContinueButtonBorderForegroundColor() const;
	virtual color GetContinueButtonBorderBackgroundColor() const;
	virtual color GetContinueButtonLetterColor() const;
	virtual color GetContinueButtonShadingColor() const;
	//
	virtual color GetExitButtonBorderForegroundColor() const;
	virtual color GetExitButtonBorderBackgroundColor() const;
	virtual color GetExitButtonLetterColor() const;
	virtual color GetExitButtonShadingColor() const;
	//
	virtual color GetVisitorForegroundColor() const;
	virtual color GetVisitorBackgroundColor() const;
	///////////////PlayingField Symbol Constants///////////////
	virtual const wstring GetVerticalPlayingField() const;
	virtual const wstring GetHorizontalPlayingField() const;
	virtual const wstring GetUpperLeftPlayingField() const;
	virtual const wstring GetUpperRightPlayingField() const;
	virtual const wstring GetBottomLeftPlayingField() const;
	virtual const wstring GetBottomRightPlayingField() const;
	///////////////InfoPanel Symbol Constants///////////////
	virtual const wstring GetInfoPanelVerticalSymbol() const;
	virtual const wstring GetInfoPanelHorizontalSymbol() const;
	virtual const wstring GetInfoPanelUpperLeftSymbol() const;
	virtual const wstring GetInfoPanelUpperRightSymbol() const;
	virtual const wstring GetInfoPanelBottomLeftSymbol() const;
	virtual const wstring GetInfoPanelBottomRightSymbol() const;
	//
	virtual const wstring GetMenuScreenVerticalSymbol() const;
	virtual const wstring GetMenuScreenHorizontalSymbol() const;
	virtual const wstring GetMenuScreenUpperLeftSymbol() const;
	virtual const wstring GetMenuScreenUpperRightSymbol() const;
	virtual const wstring GetMenuScreenBottomLeftSymbol() const;
	virtual const wstring GetMenuScreenBottomRightSymbol() const;
	//
	virtual const wstring GetMenuScreenButtonVerticalSymbol() const;
	virtual const wstring GetMenuScreenButtonHorizontalSymbol() const;
	virtual const wstring GetMenuScreenButtonUpperLeftSymbol() const;
	virtual const wstring GetMenuScreenButtonUpperRightSymbol() const;
	virtual const wstring GetMenuScreenButtonBottomLeftSymbol() const;
	virtual const wstring GetMenuScreenButtonBottomRightSymbol() const;
	//
	virtual const wstring GetControlsVerticalSymbol() const;
	virtual const wstring GetControlsHorizontalSymbol() const;
	virtual const wstring GetControlsUpperLeftSymbol() const;
	virtual const wstring GetControlsUpperRightSymbol() const;
	virtual const wstring GetControlsBottomLeftSymbol() const;
	virtual const wstring GetControlsBottomRightSymbol() const;
	//
	virtual const wstring GetMessagesAndInfoVerticalSymbol() const;
	virtual const wstring GetMessagesAndInfoHorizontalSymbol() const;
	virtual const wstring GetMessagesAndInfoUpperLeftSymbol() const;
	virtual const wstring GetMessagesAndInfoUpperRightSymbol() const;
	virtual const wstring GetMessagesAndInfoBottomLeftSymbol() const;
	virtual const wstring GetMessagesAndInfoBottomRightSymbol() const;
	//
	virtual const wstring GetConstructionInfoButtonVerticalSymbol() const;
	virtual const wstring GetConstructionInfoButtonHorizontalSymbol() const;
	virtual const wstring GetConstructionInfoButtonUpperLeftSymbol() const;
	virtual const wstring GetConstructionInfoButtonUpperRightSymbol() const;
	virtual const wstring GetConstructionInfoButtonBottomLeftSymbol() const;
	virtual const wstring GetConstructionInfoButtonBottomRightSymbol() const;
	//
	virtual const wstring GetConstructionInfoScreenIconVerticalSymbol() const;
	virtual const wstring GetConstructionInfoScreenIconHorizontalSymbol() const;
	virtual const wstring GetConstructionInfoScreenIconUpperLeftSymbol() const;
	virtual const wstring GetConstructionInfoScreenIconUpperRightSymbol() const;
	virtual const wstring GetConstructionInfoScreenIconBottomLeftSymbol() const;
	virtual const wstring GetConstructionInfoScreenIconBottomRightSymbol() const;
	//Empty Border Rectangle Symbol
	virtual const wstring GetEmptyRectangleBorderSymbol() const;
	//
	virtual const string GetControlsButtonTitle() const;
	virtual const string GetInfoScreenButtonTitle() const;
	virtual const string GetDeconstructButtonTitle() const;
	virtual const string GetNewGameButtonTitle() const;
	virtual const string GetContinueButtonTitle() const;
	virtual const string GetExitButtonTitle() const;
	//
	///////////////Menu Border Symbol Constants///////////////
	virtual const wstring GetMenuVerticalSymbol() const;
	virtual const wstring GetMenuHorizontalSymbol() const;
	virtual const wstring GetMenuUpperLeftSymbol() const;
	virtual const wstring GetMenuUpperRightSymbol() const;
	virtual const wstring GetMenuBottomLeftSymbol() const;
	virtual const wstring GetMenuBottomRightSymbol() const;
	///////////////Game Stats Border Symbol Constants///////////////
	virtual const wstring GetGameStatsVerticalSymbol() const;
	virtual const wstring GetGameStatsHorizontalSymbol() const;
	virtual const wstring GetGameStatsUpperLeftSymbol() const;
	virtual const wstring GetGameStatsUpperRightSymbol() const;
	virtual const wstring GetGameStatsBottomLeftSymbol() const;
	virtual const wstring GetGameStatsBottomRightSymbol() const;
	///////////////Camera Border Symbol Constants///////////////
	virtual const wstring GetCameraVerticalSymbol() const;
	virtual const wstring GetCameraHorizontalSymbol() const;
	virtual const wstring GetCameraUpperLeftSymbol() const;
	virtual const wstring GetCameraUpperRightSymbol() const;
	virtual const wstring GetCameraBottomLeftSymbol() const;
	virtual const wstring GetCameraBottomRightSymbol() const;
	///////////////Menu Item Border Symbol Constants///////////////
	virtual const wstring GetMenuItemVerticalSymbol() const;
	virtual const wstring GetMenuItemHorizontalSymbol() const;
	virtual const wstring GetMenuItemUpperLeftSymbol() const;
	virtual const wstring GetMenuItemUpperRightSymbol() const;
	virtual const wstring GetMenuItemBottomLeftSymbol() const;
	virtual const wstring GetMenuItemBottomRightSymbol() const;
	///////////////Menu Icon Border Symbol Constants///////////////
	virtual const wstring GetMenuIconVerticalSymbol() const;
	virtual const wstring GetMenuIconHorizontalSymbol() const;
	virtual const wstring GetMenuIconUpperLeftSymbol() const;
	virtual const wstring GetMenuIconUpperRightSymbol() const;
	virtual const wstring GetMenuIconBottomLeftSymbol() const;
	virtual const wstring GetMenuIconBottomRightSymbol() const;
	///////////////Initial Splash Screen Border Symbol Constants///////////////
	virtual const wstring GetInitialSplashScreenVerticalSymbol() const;
	virtual const wstring GetInitialSplashScreenHorizontalSymbol() const;
	virtual const wstring GetInitialSplashScreenUpperLeftSymbol() const;
	virtual const wstring GetInitialSplashScreenUpperRightSymbol() const;
	virtual const wstring GetInitialSplashScreenBottomLeftSymbol() const;
	virtual const wstring GetInitialSplashScreenBottomRightSymbol() const;
	//
	virtual const wstring GetPressAnyKeyVerticalSymbol() const;
	virtual const wstring GetPressAnyKeyHorizontalSymbol() const;
	virtual const wstring GetPressAnyKeyUpperLeftSymbol() const;
	virtual const wstring GetPressAnyKeyUpperRightSymbol() const;
	virtual const wstring GetPressAnyKeyBottomLeftSymbol() const;
	virtual const wstring GetPressAnyKeyBottomRightSymbol() const;
	//
	virtual const wstring GetMainMenuVerticalSymbol() const;
	virtual const wstring GetMainMenuHorizontalSymbol() const;
	virtual const wstring GetMainMenuUpperLeftSymbol() const;
	virtual const wstring GetMainMenuUpperRightSymbol() const;
	virtual const wstring GetMainMenuBottomLeftSymbol() const;
	virtual const wstring GetMainMenuBottomRightSymbol() const;
	//
	virtual const wstring GetNewGameButtonVerticalSymbol() const;
	virtual const wstring GetNewGameButtonHorizontalSymbol() const;
	virtual const wstring GetNewGameButtonUpperLeftSymbol() const;
	virtual const wstring GetNewGameButtonUpperRightSymbol() const;
	virtual const wstring GetNewGameButtonBottomLeftSymbol() const;
	virtual const wstring GetNewGameButtonBottomRightSymbol() const;
	//
	virtual const wstring GetContinueButtonVerticalSymbol() const;
	virtual const wstring GetContinueButtonHorizontalSymbol() const;
	virtual const wstring GetContinueButtonUpperLeftSymbol() const;
	virtual const wstring GetContinueButtonUpperRightSymbol() const;
	virtual const wstring GetContinueButtonBottomLeftSymbol() const;
	virtual const wstring GetContinueButtonBottomRightSymbol() const;
	//
	virtual const wstring GetExitButtonVerticalSymbol() const;
	virtual const wstring GetExitButtonHorizontalSymbol() const;
	virtual const wstring GetExitButtonUpperLeftSymbol() const;
	virtual const wstring GetExitButtonUpperRightSymbol() const;
	virtual const wstring GetExitButtonBottomLeftSymbol() const;
	virtual const wstring GetExitButtonBottomRightSymbol() const;
	//
	virtual const wstring GetVisitorSymbol() const;
	///////////////Indent Constants///////////////
	virtual const int GetInfoPanelAboveIndent() const;
	virtual const int GetInfoPanelBottomIndent() const;
	virtual const int GetInfoPanelLeftIndent() const;
	virtual const int GetInfoPanelRightIndent() const;
};