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
	virtual const int GetIceCreamShopHeightAdd() const;
	virtual const int GetToiletHeightAdd() const;
	virtual const int GetFoodCourtHeightAdd() const;
	virtual const int GetCarouselHeightAdd() const;
	virtual const int GetDumboRideHeightAdd() const;
	virtual const int GetFerrisWheelHeightAdd() const;
	virtual const int GetRollerCoasterHeightAdd() const;
	virtual const int GetBumperCarsHeightAdd() const;
	virtual const int GetLogRideHeightAdd() const;
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
	virtual const int GetPressAnyKeyHeightAdd() const;
	virtual const int GetNewGameButtonHeightAdd() const;
	virtual const int GetContinueButtonHeightAdd() const;
	virtual const int GetExitButtonHeightAdd() const;
	///////////////Width Addition Constants///////////////
	virtual const int GetIceCreamShopWidthAdd() const;
	virtual const int GetToiletWidthAdd() const;
	virtual const int GetFoodCourtWidthAdd() const;
	virtual const int GetCarouselWidthAdd() const;
	virtual const int GetDumboRideWidthAdd() const;
	virtual const int GetFerrisWheelWidthAdd() const;
	virtual const int GetRollerCoasterWidthAdd() const;
	virtual const int GetBumperCarsWidthAdd() const;
	virtual const int GetLogRideWidthAdd() const;
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
	virtual const int GetPressAnyKeyWidthAdd() const;
	virtual const int GetNewGameButtonWidthAdd() const;
	virtual const int GetContinueButtonWidthAdd() const;
	virtual const int GetExitButtonWidthAdd() const;
	///////////////Cost Initialisation Constants///////////////
	virtual const int GetIceCreamShopCost() const;
	virtual const int GetToiletCost() const;
	virtual const int GetFoodCourtCost() const;
	virtual const int GetCarouselCost() const;
	virtual const int GetDumboRideCost() const;
	virtual const int GetFerrisWheelCost() const;
	virtual const int GetRollerCoasterCost() const;
	virtual const int GetBumperCarsCost() const;
	virtual const int GetLogRideCost() const;
	virtual const int GetExitCost() const;
	virtual const int GetRoadCost() const;
	///////////////Daily Expences Initialisation Constants///////////////
	virtual const int GetIceCreamShopExpences() const;
	virtual const int GetToiletExpences() const;
	virtual const int GetFoodCourtExpences() const;
	virtual const int GetCarouselExpences() const;
	virtual const int GetDumboRideExpences() const;
	virtual const int GetFerrisWheelExpences() const;
	virtual const int GetRollerCoasterExpences() const;
	virtual const int GetBumperCarsExpences() const;
	virtual const int GetLogRideExpences() const;
	virtual const int GetExitExpences() const;
	///////////////Description Initialisation Constants///////////////
	virtual const string GetIceCreamShopDescription() const;
	virtual const string GetToiletDescription() const;
	virtual const string GetFoodCourtDescription() const;
	virtual const string GetCarouselDescription() const;
	virtual const string GetDumboRideDescription() const;
	virtual const string GetFerrisWheelDescription() const;
	virtual const string GetRollerCoasterDescription() const;
	virtual const string GetBumperCarsDescription() const;
	virtual const string GetLogRideDescription() const;
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
	virtual const wstring GetFerrisWheelSymbol() const;
	virtual const wstring GetRollerCoasterSymbol() const;
	virtual const wstring GetBumperCarsSymbol() const;
	virtual const wstring GetLogRideSymbol() const;
	virtual const wstring GetToiletSymbol() const;
	virtual const wstring GetExitSymbol() const;
	///////////////Toilet Need Constants///////////////
	virtual const int GetIceCreamShopToiletNeed() const;
	virtual const int GetFoodCourtToiletNeed() const;
	virtual const int GetCarouselToiletNeed() const;
	virtual const int GetDumboRideToiletNeed() const;
	virtual const int GetFerrisWheelToiletNeed() const;
	virtual const int GetRollerCoasterToiletNeed() const;
	virtual const int GetBumperCarsToiletNeed() const;
	virtual const int GetLogRideToiletNeed() const;
	virtual const int GetToiletToiletNeed() const;
	virtual const int GetExitToiletNeed() const;
	///////////////Hunger Satisfaction Constants///////////////
	virtual const int GetIceCreamShopHungerSatisfaction() const;
	virtual const int GetFoodCourtHungerSatisfaction() const;
	virtual const int GetCarouselHungerSatisfaction() const;
	virtual const int GetDumboRideHungerSatisfaction() const;
	virtual const int GetFerrisWheelHungerSatisfaction() const;
	virtual const int GetRollerCoasterHungerSatisfaction() const;
	virtual const int GetBumperCarsHungerSatisfaction() const;
	virtual const int GetLogRideHungerSatisfaction() const;
	virtual const int GetToiletHungerSatisfaction() const;
	virtual const int GetExitHungerSatisfaction() const;
	///////////////Visit Price Constants///////////////
	virtual const int GetIceCreamShopVisitPrice() const;
	virtual const int GetFoodCourtVisitPrice() const;
	virtual const int GetCarouselVisitPrice() const;
	virtual const int GetDumboRideVisitPrice() const;
	virtual const int GetFerrisWheelVisitPrice() const;
	virtual const int GetRollerCoasterVisitPrice() const;
	virtual const int GetBumperCarsVisitPrice() const;
	virtual const int GetLogRideVisitPrice() const;
	virtual const int GetToiletVisitPrice() const;
	virtual const int GetExitVisitPrice() const;
	///////////////Entertainment Constants///////////////
	virtual const int GetIceCreamShopEntertainmentValue() const;
	virtual const int GetFoodCourtEntertainmentValue() const;
	virtual const int GetCarouselEntertainmentValue() const;
	virtual const int GetDumboRideEntertainmentValue() const;
	virtual const int GetFerrisWheelEntertainmentValue() const;
	virtual const int GetRollerCoasterEntertainmentValue() const;
	virtual const int GetBumperCarsEntertainmentValue() const;
	virtual const int GetLogRideEntertainmentValue() const;
	virtual const int GetToiletEntertainmentValue() const;
	virtual const int GetExitEntertainmentValue() const;
	///////////////Is Building Exit Constants///////////////
	virtual const int GetIceCreamShopIsExit() const;
	virtual const int GetFoodCourtIsExit() const;
	virtual const int GetCarouselIsExit() const;
	virtual const int GetDumboRideIsExit() const;
	virtual const int GetFerrisWheelIsExit() const;
	virtual const int GetRollerCoasterIsExit() const;
	virtual const int GetBumperCarsIsExit() const;
	virtual const int GetLogRideIsExit() const;
	virtual const int GetToiletIsExit() const;
	virtual const int GetExitIsExit() const;
	///////////////Max Visitors Constants///////////////
	virtual const int GetIceCreamShopMaxVisitors() const;
	virtual const int GetFoodCourtMaxVisitors() const;
	virtual const int GetCarouselMaxVisitors() const;
	virtual const int GetDumboRideMaxVisitors() const;
	virtual const int GetFerrisWheelMaxVisitors() const;
	virtual const int GetRollerCoasterMaxVisitors() const;
	virtual const int GetBumperCarsMaxVisitors() const;
	virtual const int GetLogRideMaxVisitors() const;
	virtual const int GetToiletMaxVisitors() const;
	virtual const int GetExitMaxVisitors() const;
	///////////////Visit Time Constants///////////////
	virtual const int GetIceCreamShopVisitTime() const;
	virtual const int GetFoodCourtVisitTime() const;
	virtual const int GetCarouselVisitTime() const;
	virtual const int GetDumboRideVisitTime() const;
	virtual const int GetFerrisWheelVisitTime() const;
	virtual const int GetRollerCoasterVisitTime() const;
	virtual const int GetBumperCarsVisitTime() const;
	virtual const int GetLogRideVisitTime() const;
	virtual const int GetToiletVisitTime() const;
	virtual const int GetExitVisitTime() const;
	///////////////Initialisation Coord Constants///////////////
	virtual const PointCoord GetCameraInitialUpperLeft() const;
	virtual const PointCoord GetPlayingFieldUpperLeft() const;
	virtual const PointCoord GetInfoPanelUpperLeft() const;
	virtual const PointCoord GetInitialSplashScreenUpperLeft() const;
	virtual const PointCoord GetMainMenuUpperLeft() const;
	///////////////Constructions's Icon Symbol Constants///////////////
	virtual const wstring GetIceCreamShopIconSymbol() const;
	virtual const wstring GetToiletIconSymbol() const;
	virtual const wstring GetFoodCourtIconSymbol() const;
	virtual const wstring GetCarouselIconSymbol() const;
	virtual const wstring GetDumboRideIconSymbol() const;
	virtual const wstring GetFerrisWheelIconSymbol() const;
	virtual const wstring GetRollerCoasterIconSymbol() const;
	virtual const wstring GetBumperCarsIconSymbol() const;
	virtual const wstring GetLogRideIconSymbol() const;
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
	virtual color GetFerrisWheelForegroundColor() const;
	virtual color GetFerrisWheelConnectedBackgroundColor() const;
	virtual color GetFerrisWheelNotConnectedBackgroundColor() const;
	virtual color GetFerrisWheelChosenBackgroundColor() const;
	//
	virtual color GetRollerCoasterForegroundColor() const;
	virtual color GetRollerCoasterConnectedBackgroundColor() const;
	virtual color GetRollerCoasterNotConnectedBackgroundColor() const;
	virtual color GetRollerCoasterChosenBackgroundColor() const;
	//
	virtual color GetBumperCarsForegroundColor() const;
	virtual color GetBumperCarsConnectedBackgroundColor() const;
	virtual color GetBumperCarsNotConnectedBackgroundColor() const;
	virtual color GetBumperCarsChosenBackgroundColor() const;
	//
	virtual color GetLogRideForegroundColor() const;
	virtual color GetLogRideConnectedBackgroundColor() const;
	virtual color GetLogRideNotConnectedBackgroundColor() const;
	virtual color GetLogRideChosenBackgroundColor() const;
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