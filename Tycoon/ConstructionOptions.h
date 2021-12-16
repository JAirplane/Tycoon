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
	virtual const char GetIceCreamShopSymbol() const;
	///////////////PlayingField Symbol Constants///////////////
	virtual const char GetVerticalPlayingField() const;
	virtual const char GetHorizontalPlayingField() const;
	virtual const char GetUpperLeftPlayingField() const;
	virtual const char GetUpperRightPlayingField() const;
	virtual const char GetBottomLeftPlayingField() const;
	virtual const char GetBottomRightPlayingField() const;
	///////////////Initialisation Coord Constants///////////////
	virtual const PointCoord GetCameraInitialUpperLeft() const;
	const PointCoord GetPlayingFieldUpperLeft() const;
	///////////////Building's Icon Symbol Constants///////////////
	virtual const char GetIceCreamShopIconSymbol() const;
	virtual const char GetRoadIconSymbol() const;
	///////////////Color Construction Constants///////////////
	virtual color GetIceCreamShopForegroundColor() const;
	virtual color GetIceCreamShopBackgroundColor() const;
	virtual color GetRoadForegroundColor() const;
	virtual color GetRoadBackgroundColor() const;
	virtual color GetCursorBackgroundColor() const;
	virtual color GetPlayingFieldColor() const;
	virtual color GetMenuBorderInactiveColor() const;
	virtual color GetMenuBorderActiveColor() const;
	virtual color GetMenuBorderUnderConstructionColor() const;
};