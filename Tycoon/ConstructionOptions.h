#pragma once
#include "Coord_and_constants.h"
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
	static ConstructionOptions* GetAllOptions();
	///////////////Height Addition Constants///////////////
	virtual const int GetIceCreamShopHeightAdd() const;
	virtual const int GetMenuElementHeightAdd() const; //height of 1 element of menu
	virtual const int GetMenuIconHeightAdd() const;
	virtual const int GetRoadHeightAdd() const;
	virtual const int GetVisitorHeightAdd() const;
	virtual const int GetCameraHeightAdd() const;
	virtual const int GetMenuHeightAdd() const;
	virtual const int GetPlayingFieldHeightAdd() const;
	virtual const int GetInfoPanelHeightAdd() const;
	///////////////Width Addition Constants///////////////
	virtual const int GetIceCreamShopWidthAdd() const;
	virtual const int GetRoadWidthAdd() const;
	virtual const int GetVisitorWidthAdd() const;
	virtual const int GetCameraWidthAdd() const;
	virtual const int GetMenuWidthAdd() const;
	virtual const int GetMenuIconWidthAdd() const;
	virtual const int GetPlayingFieldWidthAdd() const;
	virtual const int GetInfoPanelWidthAdd() const;
	virtual const int GetInfoPanelButtonWidthAdd() const;
	///////////////Cost Initialisation Constants///////////////
	virtual const int GetIceCreamShopCost() const;
	virtual const int GetRoadCost() const;
	///////////////Daily Expences Initialisation Constants///////////////
	virtual const int GetIceCreamShopExpences() const;
	///////////////Description Initialisation Constants///////////////
	virtual const string GetIceCreamShopDescription() const;
	virtual const string GetRoadDescription() const;
	virtual const string GetArrowsDescription() const;
	virtual const string GetTabDescription() const;
	virtual const string GetEnterDescription() const;
	virtual const string GetEscDescription() const;
	virtual const string GetHKeyDescription() const;
	virtual const string GetSKeyDescription() const;
	virtual const string GetRKeyDescription() const;
	///////////////Building Symbol Constants///////////////
	virtual const wstring GetIceCreamShopSymbol() const;
	///////////////Initialisation Coord Constants///////////////
	virtual const PointCoord GetCameraInitialUpperLeft() const;
	virtual const PointCoord GetPlayingFieldUpperLeft() const;
	virtual const PointCoord GetInfoPanelUpperLeft() const;
	///////////////Constructions's Icon Symbol Constants///////////////
	virtual const wstring GetIceCreamShopIconSymbol() const;
	virtual const wstring GetRoadIconSymbol() const;
	///////////////Color Constants///////////////
	virtual color GetIceCreamShopForegroundColor() const;
	virtual color GetIceCreamShopBackgroundColor() const;
	virtual color GetRoadForegroundColor() const;
	virtual color GetRoadBackgroundColor() const;
	virtual color GetCursorBackgroundColor() const;
	virtual color GetCameraBorderForegroundColor() const;
	virtual color GetCameraBorderBackgroundColor() const;
	virtual color GetCameraLetterColor() const;
	virtual color GetCameraShadingColor() const;
	virtual color GetPlayingFieldBorderForegroundColor() const;
	virtual color GetPlayingFieldBorderBackgroundColor() const;
	virtual color GetPlayingFieldLetterColor() const;
	virtual color GetPlayingFieldShadingColor() const;
	virtual color GetInfoPanelBorderForegroundColor() const;
	virtual color GetInfoPanelBorderBackgroundColor() const;
	virtual color GetInfoPanelTextColor() const;
	virtual color GetInfoPanelShadingColor() const;
	virtual color GetSplashScreenForegroundColor() const;
	virtual color GetSplashScreenBackgroundColor() const;
	virtual color GetMenuScreenBorderForegroundColor() const;
	virtual color GetMenuScreenBorderBackgroundColor() const;
	virtual color GetMenuScreenTextColor() const;
	virtual color GetMenuScreenShadingColor() const;
	virtual color GetMenuBorderForegroundColor() const;
	virtual color GetMenuBorderBackgroundColor() const;
	virtual color GetMenuLetterColor() const;
	virtual color GetMenuShadingColor() const;
	virtual color GetMenuIconForegroundColor() const;
	virtual color GetMenuIconBackgroundColor() const;
	virtual color GetMenuIconLetterColor() const;
	virtual color GetMenuIconShadingColor() const;
	virtual color GetMenuElementInactiveColor() const;
	virtual color GetMenuElementActiveColor() const;
	virtual color GetMenuElementUnderConstructionColor() const;
	virtual color GetMenuElementBackgroundColor() const;
	virtual color GetMenuElementLetterColor() const;
	virtual color GetMenuElementShadingColor() const;
	virtual color GetButtonBorderActiveColor() const;
	virtual color GetButtonBorderInactiveColor() const;
	virtual color GetButtonBorderBackgroundColor() const;
	virtual color GetButtonContentForegroundColor() const;
	virtual color GetButtonContentBackgroundColor() const;
	virtual color GetControlsScreenBorderForegroundColor() const;
	virtual color GetControlsScreenBorderBackgroundColor() const;
	virtual color GetControlsScreenLetterColor() const;
	virtual color GetControlsScreenShadingColor() const;
	virtual color GetMessagesAndInfoScreenBorderForegroundColor() const;
	virtual color GetMessagesAndInfoScreenBorderBackgroundColor() const;
	virtual color GetMessagesAndInfoScreenLetterColor() const;
	virtual color GetMessagesAndInfoScreenShadingColor() const;
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
	virtual const string GetControlsButtonTitle() const;
	virtual const string GetInfoScreenButtonTitle() const;
	//
	///////////////Menu Border Symbol Constants///////////////
	virtual const wstring GetMenuVerticalSymbol() const;
	virtual const wstring GetMenuHorizontalSymbol() const;
	virtual const wstring GetMenuUpperLeftSymbol() const;
	virtual const wstring GetMenuUpperRightSymbol() const;
	virtual const wstring GetMenuBottomLeftSymbol() const;
	virtual const wstring GetMenuBottomRightSymbol() const;
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
	///////////////Indent Constants///////////////
	virtual const int GetInfoPanelAboveIndent() const;
	virtual const int GetInfoPanelBottomIndent() const;
	virtual const int GetInfoPanelLeftIndent() const;
	virtual const int GetInfoPanelRightIndent() const;
};