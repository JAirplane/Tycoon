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
	static ConstructionOptions* GetAllOptions();
	///////////////Height Addition Constants///////////////
	virtual const int GetIceCreamShopHeightAdd() const;
	virtual const int GetToiletHeightAdd() const;
	virtual const int GetFoodCourtHeightAdd() const;
	virtual const int GetCarouselHeightAdd() const;
	virtual const int GetDumboRideHeightAdd() const;
	virtual const int GetExitHeightAdd() const;
	virtual const int GetMenuElementHeightAdd() const; //height of 1 element of menu
	virtual const int GetMenuIconHeightAdd() const;
	virtual const int GetGameStatsHeightAdd() const;
	virtual const int GetRoadHeightAdd() const;
	virtual const int GetVisitorHeightAdd() const;
	virtual const int GetCameraHeightAdd() const;
	virtual const int GetMenuHeightAdd() const;
	virtual const int GetPlayingFieldHeightAdd() const;
	virtual const int GetInfoPanelHeightAdd() const;
	virtual const int GetConstructionInfoButtonHeightAdd() const;
	///////////////Width Addition Constants///////////////
	virtual const int GetIceCreamShopWidthAdd() const;
	virtual const int GetToiletWidthAdd() const;
	virtual const int GetFoodCourtWidthAdd() const;
	virtual const int GetCarouselWidthAdd() const;
	virtual const int GetDumboRideWidthAdd() const;
	virtual const int GetExitWidthAdd() const;
	virtual const int GetRoadWidthAdd() const;
	virtual const int GetVisitorWidthAdd() const;
	virtual const int GetCameraWidthAdd() const;
	virtual const int GetMenuWidthAdd() const;
	virtual const int GetMenuIconWidthAdd() const;
	virtual const int GetPlayingFieldWidthAdd() const;
	virtual const int GetInfoPanelWidthAdd() const;
	virtual const int GetInfoPanelButtonWidthAdd() const;
	virtual const int GetConstructionInfoButtonWidthAdd() const;
	///////////////Cost Initialisation Constants///////////////
	virtual const int GetIceCreamShopCost() const;
	virtual const int GetToiletCost() const;
	virtual const int GetFoodCourtCost() const;
	virtual const int GetCarouselCost() const;
	virtual const int GetDumboRideCost() const;
	virtual const int GetExitCost() const;
	virtual const int GetRoadCost() const;
	///////////////Daily Expences Initialisation Constants///////////////
	virtual const int GetIceCreamShopExpences() const;
	virtual const int GetToiletExpences() const;
	virtual const int GetFoodCourtExpences() const;
	virtual const int GetCarouselExpences() const;
	virtual const int GetDumboRideExpences() const;
	virtual const int GetExitExpences() const;
	///////////////Description Initialisation Constants///////////////
	virtual const string GetIceCreamShopDescription() const;
	virtual const string GetToiletDescription() const;
	virtual const string GetFoodCourtDescription() const;
	virtual const string GetCarouselDescription() const;
	virtual const string GetDumboRideDescription() const;
	virtual const string GetExitDescription() const;
	virtual const string GetRoadDescription() const;
	//
	virtual const string GetArrowsDescription() const;
	virtual const string GetTabDescription() const;
	virtual const string GetEnterDescription() const;
	virtual const string GetEscDescription() const;
	virtual const string GetHKeyDescription() const;
	virtual const string GetSKeyDescription() const;
	virtual const string GetRKeyDescription() const;
	///////////////Building Symbol Constants///////////////
	virtual const wstring GetIceCreamShopSymbol() const;
	virtual const wstring GetFoodCourtSymbol() const;
	virtual const wstring GetCarouselSymbol() const;
	virtual const wstring GetDumboRideSymbol() const;
	virtual const wstring GetToiletSymbol() const;
	virtual const wstring GetExitSymbol() const;
	///////////////Toilet Need Constants///////////////
	virtual const int GetIceCreamShopToiletNeed() const;
	virtual const int GetFoodCourtToiletNeed() const;
	virtual const int GetCarouselToiletNeed() const;
	virtual const int GetDumboRideToiletNeed() const;
	virtual const int GetToiletToiletNeed() const;
	virtual const int GetExitToiletNeed() const;
	///////////////Hunger Satisfaction Constants///////////////
	virtual const int GetIceCreamShopHungerSatisfaction() const;
	virtual const int GetFoodCourtHungerSatisfaction() const;
	virtual const int GetCarouselHungerSatisfaction() const;
	virtual const int GetDumboRideHungerSatisfaction() const;
	virtual const int GetToiletHungerSatisfaction() const;
	virtual const int GetExitHungerSatisfaction() const;
	///////////////Visit Price Constants///////////////
	virtual const int GetIceCreamShopVisitPrice() const;
	virtual const int GetFoodCourtVisitPrice() const;
	virtual const int GetCarouselVisitPrice() const;
	virtual const int GetDumboRideVisitPrice() const;
	virtual const int GetToiletVisitPrice() const;
	virtual const int GetExitVisitPrice() const;
	///////////////Entertainment Constants///////////////
	virtual const int GetIceCreamShopEntertainmentValue() const;
	virtual const int GetFoodCourtEntertainmentValue() const;
	virtual const int GetCarouselEntertainmentValue() const;
	virtual const int GetDumboRideEntertainmentValue() const;
	virtual const int GetToiletEntertainmentValue() const;
	virtual const int GetExitEntertainmentValue() const;
	///////////////Is Building Exit Constants///////////////
	virtual const int GetIceCreamShopIsExit() const;
	virtual const int GetFoodCourtIsExit() const;
	virtual const int GetCarouselIsExit() const;
	virtual const int GetDumboRideIsExit() const;
	virtual const int GetToiletIsExit() const;
	virtual const int GetExitIsExit() const;
	///////////////Max Visitors Constants///////////////
	virtual const int GetIceCreamShopMaxVisitors() const;
	virtual const int GetFoodCourtMaxVisitors() const;
	virtual const int GetCarouselMaxVisitors() const;
	virtual const int GetDumboRideMaxVisitors() const;
	virtual const int GetToiletMaxVisitors() const;
	virtual const int GetExitMaxVisitors() const;
	///////////////Initialisation Coord Constants///////////////
	virtual const PointCoord GetCameraInitialUpperLeft() const;
	virtual const PointCoord GetPlayingFieldUpperLeft() const;
	virtual const PointCoord GetInfoPanelUpperLeft() const;
	///////////////Constructions's Icon Symbol Constants///////////////
	virtual const wstring GetIceCreamShopIconSymbol() const;
	virtual const wstring GetToiletIconSymbol() const;
	virtual const wstring GetFoodCourtIconSymbol() const;
	virtual const wstring GetCarouselIconSymbol() const;
	virtual const wstring GetDumboRideIconSymbol() const;
	virtual const wstring GetExitIconSymbol() const;
	virtual const wstring GetRoadIconSymbol() const;
	///////////////Color Constants///////////////
	virtual color GetIceCreamShopForegroundColor() const;
	virtual color GetIceCreamShopConnectedBackgroundColor() const;
	virtual color GetIceCreamShopNotConnectedBackgroundColor() const;
	virtual color GetIceCreamShopChosenBackgroundColor() const;
	//
	virtual color GetFoodCourtForegroundColor() const;
	virtual color GetFoodCourtConnectedBackgroundColor() const;
	virtual color GetFoodCourtNotConnectedBackgroundColor() const;
	virtual color GetFoodCourtChosenBackgroundColor() const;
	//
	virtual color GetCarouselForegroundColor() const;
	virtual color GetCarouselConnectedBackgroundColor() const;
	virtual color GetCarouselNotConnectedBackgroundColor() const;
	virtual color GetCarouselChosenBackgroundColor() const;
	//
	virtual color GetDumboRideForegroundColor() const;
	virtual color GetDumboRideConnectedBackgroundColor() const;
	virtual color GetDumboRideNotConnectedBackgroundColor() const;
	virtual color GetDumboRideChosenBackgroundColor() const;
	//
	virtual color GetToiletForegroundColor() const;
	virtual color GetToiletConnectedBackgroundColor() const;
	virtual color GetToiletNotConnectedBackgroundColor() const;
	virtual color GetToiletChosenBackgroundColor() const;
	//
	virtual color GetExitForegroundColor() const;
	virtual color GetExitConnectedBackgroundColor() const;
	virtual color GetExitNotConnectedBackgroundColor() const;
	virtual color GetExitChosenBackgroundColor() const;
	//
	virtual color GetRoadForegroundColor() const;
	virtual color GetRoadConnectedBackgroundColor() const;
	virtual color GetRoadNotConnectedBackgroundColor() const;
	virtual color GetRoadChosenBackgroundColor() const;
	//
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
	//
	virtual const wstring GetVisitorSymbol() const;
	///////////////Indent Constants///////////////
	virtual const int GetInfoPanelAboveIndent() const;
	virtual const int GetInfoPanelBottomIndent() const;
	virtual const int GetInfoPanelLeftIndent() const;
	virtual const int GetInfoPanelRightIndent() const;
};