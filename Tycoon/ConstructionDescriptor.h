#pragma once
#include "VisitorDescriptor.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
class ConstructionDescriptor : public IngameObjectDescriptor
{
private:
	int constructionCost;
	int dailyExpences;
	string description;
	wstring iconSymbol;
	color backgroundConnected;
	color backgroundChoosen;
	PointCoord menuElementLocation;
public:
	ConstructionDescriptor(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChoosen, int dailyExpences = 0, int constructionHeightAddition = 0, int constructionWidthAddition = 0) :
		IngameObjectDescriptor(foreground, backgroundNotConnected, constructionHeightAddition, constructionWidthAddition)
	{
		this->menuElementLocation = menuElementLocation;
		this->constructionCost = constructionCost;
		this->dailyExpences = dailyExpences;
		this->description = description;
		this->iconSymbol = iconSymbol;
		this->backgroundConnected = backgroundConnected;
		this->backgroundChoosen = backgroundChoosen;
	}
	~ConstructionDescriptor() {}
	int GetConstructionCost() const;
	string GetDescription() const;
	wstring GetIconSymbol() const;
	int GetDailyExpences() const;
	color GetConnectedBackgroundColor() const;
	color GetChosenBackgroundColor() const;
	virtual wstring GetConstructionSymbol(int mask = 0) = 0;
	PointCoord GetMenuElementLocation() const;
	void SetMenuElementLocation(PointCoord mLocation);
};