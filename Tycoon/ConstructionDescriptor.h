#pragma once
#include "Cursor.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
class ConstructionDescriptor
{
private:
	int constructionHeightAddition;
	int constructionWidthAddition;
	int constructionCost;
	int dailyExpences;
	string description;
	wstring iconSymbol;
	color foreground;
	color background;
	PointCoord menuElementLocation;
public:
	ConstructionDescriptor(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol,
		color foreground, color background, int dailyExpences = 0, int constructionHeightAddition = 0, int constructionWidthAddition = 0)
	{
		this->menuElementLocation = menuElementLocation;
		this->constructionHeightAddition = constructionHeightAddition;
		this->constructionWidthAddition = constructionWidthAddition;
		this->constructionCost = constructionCost;
		this->dailyExpences = dailyExpences;
		this->description = description;
		this->iconSymbol = iconSymbol;
		this->foreground = foreground;
		this->background = background;
	}
	~ConstructionDescriptor() {}
	int GetConstructionHeightAdd() const;
	int GetConstructionWidthAdd() const;
	int GetConstructionCost() const;
	string GetDescription() const;
	wstring GetIconSymbol();
	int GetDailyExpences() const;
	color GetForegroundColor();
	color GetBackgroundColor();
	void SetBackgroundColor(color background); // the only setter needed in descriptor
	virtual wstring GetConstructionSymbol(int mask = 0);
	PointCoord GetMenuElementLocation() const;
	void SetMenuElementLocation(PointCoord mLocation);
};