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
	virtual const int GetMenuElementBordersHeight() const; //height of 1 element of menu
	virtual const int GetRoadHeightAdd() const;
	virtual const int GetVisitorHeightAdd() const;
	virtual const int GetCameraHeightAdd() const;
	virtual const int GetMenuHeightAdd() const;
	virtual const int GetPlayingFieldHeightAdd() const;
	///////////////Width Addition Constants///////////////
	virtual const int GetIceCreamShopWidthAdd() const;
	virtual const int GetRoadWidthAdd() const;
	virtual const int GetVisitorWidthAdd() const;
	virtual const int GetCameraWidthAdd() const;
	virtual const int GetMenuWidthAdd() const;
	virtual const int GetPlayingFieldWidthAdd() const;
	///////////////Cost Initialisation Constants///////////////
	virtual const int GetIceCreamShopCost() const;
	virtual const int GetRoadCost() const;
	///////////////Daily Expences Initialisation Constants///////////////
	virtual const int GetIceCreamShopExpences() const;
	///////////////Description Initialisation Constants///////////////
	virtual const string GetIceCreamShopDescription() const;
	virtual const string GetRoadDescription() const;
	///////////////Building Symbol Constants///////////////
	virtual const wstring GetIceCreamShopSymbol() const;
	///////////////Initialisation Coord Constants///////////////
	virtual const PointCoord GetCameraInitialUpperLeft() const;
	const PointCoord GetPlayingFieldUpperLeft() const;
	///////////////Constructions's Icon Symbol Constants///////////////
	virtual const wstring GetIceCreamShopIconSymbol() const;
	virtual const wstring GetRoadIconSymbol() const;
	///////////////Color Construction Constants///////////////
	virtual color GetIceCreamShopForegroundColor() const;
	virtual color GetIceCreamShopBackgroundColor() const;
	virtual color GetRoadForegroundColor() const;
	virtual color GetRoadBackgroundColor() const;
	virtual color GetCursorBackgroundColor() const;
	virtual color GetCameraColor() const;
	virtual color GetPlayingFieldColor() const;
	virtual color GetMenuColor() const;
	virtual color GetMenuIconColor() const;
	virtual color GetMenuItemInactiveColor() const;
	virtual color GetMenuItemActiveColor() const;
	virtual color GetMenuItemUnderConstructionColor() const;
	///////////////PlayingField Symbol Constants///////////////
	virtual const wstring GetVerticalPlayingField() const;
	virtual const wstring GetHorizontalPlayingField() const;
	virtual const wstring GetUpperLeftPlayingField() const;
	virtual const wstring GetUpperRightPlayingField() const;
	virtual const wstring GetBottomLeftPlayingField() const;
	virtual const wstring GetBottomRightPlayingField() const;
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
};