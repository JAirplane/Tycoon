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
		delete ConstructionParameters;
	}
	static ConstructionOptions* ConstructionParameters;
public:
	ConstructionOptions(ConstructionOptions& other) = delete;
	void operator=(const ConstructionOptions&) = delete;
	static ConstructionOptions* getAllOptions();
	///////////////Height Addition Constants///////////////
	virtual const int getIceCreamShopHeightAdd() const;
	virtual const int getMenuElementBordersHeight() const; //height of 1 element of menu
	virtual const int getRoadHeightAdd() const;
	virtual const int getVisitorHeightAdd() const;
	virtual const int getVisibleMapHeight() const;
	virtual const int getMenuHeightAdd() const;
	///////////////Width Addition Constants///////////////
	virtual const int getIceCreamShopWidthAdd() const;
	virtual const int getRoadWidthAdd() const;
	virtual const int getVisitorWidthAdd() const;
	virtual const int getVisibleMapWidth() const;
	virtual const int getMenuWidthAdd() const;
	///////////////Cost Initialisation Constants///////////////
	virtual const int getIceCreamShopCost() const;
	virtual const int getRoadCost() const;
	///////////////Daily Expences Initialisation Constants///////////////
	virtual const int getIceCreamShopExpences() const;
	///////////////Description Initialisation Constants///////////////
	virtual const string getIceCreamShopDescription() const;
	virtual const string getRoadDescription() const;
	///////////////Building Symbol Constants///////////////
	virtual const char getIceCreamShopSymbol() const;
	///////////////Initialisation Coord Constants///////////////
	virtual const PointCoord getVisibleMapInitialCoordUL() const;
	///////////////Building's Icon Symbol Constants///////////////
	virtual const char getIceCreamShopIconSymbol() const;
	virtual const char getRoadIconSymbol() const;
};