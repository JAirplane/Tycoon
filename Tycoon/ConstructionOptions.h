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
	virtual const int GetIceCreamShopheightAdd() const;
	virtual const int GetMenuElementBordersHeight() const; //height of 1 element of menu
	virtual const int GetRoadheightAdd() const;
	virtual const int GetVisitorheightAdd() const;
	virtual const int GetCameraheightAdd() const;
	virtual const int GetMenuHeightAdd() const;
	virtual const int GetPlayingFieldheightAdd() const;
	///////////////Width Addition Constants///////////////
	virtual const int GetIceCreamShopwidthAdd() const;
	virtual const int GetRoadwidthAdd() const;
	virtual const int GetVisitorwidthAdd() const;
	virtual const int GetCamerawidthAdd() const;
	virtual const int GetMenuWidthAdd() const;
	virtual const int GetPlayingFieldwidthAdd() const;
	///////////////Cost Initialisation Constants///////////////
	virtual const int GetIceCreamShopointost() const;
	virtual const int GetRoadCost() const;
	///////////////Daily Expences Initialisation Constants///////////////
	virtual const int GetIceCreamShopExpences() const;
	///////////////Description Initialisation Constants///////////////
	virtual const string GetIceCreamShopDescription() const;
	virtual const string GetRoadDescription() const;
	///////////////Building Symbol Constants///////////////
	virtual const char GetIceCreamShopSymbol() const;
	///////////////PlayingField Symbol Constants///////////////
	virtual const wchar_t GetVerticalPlayingField() const;
	virtual const wchar_t GetHorizontalPlayingField() const;
	virtual const wchar_t GetUpperLeftPlayingField() const;
	virtual const wchar_t GetUpperRightPlayingField() const;
	virtual const wchar_t GetBottomLeftPlayingField() const;
	virtual const wchar_t GetBottomRightPlayingField() const;
	///////////////Initialisation Coord Constants///////////////
	virtual const PointCoord GetCameraInitialUpperLeft() const;
	const PointCoord GetPlayingFieldUpperLeft() const;
	///////////////COnstructions's Icon Symbol Constants///////////////
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