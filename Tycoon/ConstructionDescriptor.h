#pragma once
#include "PlayingField.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
class ConstructionDescriptor : public GlobalObject
{
private:
	unsigned int constructionheightAddition;
	unsigned int constructionwidthAddition;
	unsigned int constructionCost;
	unsigned int dailyExpences;
	string description;
	wstring iconSymbol;
	color foreground;
	color background;
public:
	ConstructionDescriptor(PointCoord upperLeft, unsigned int constructionCost, string description, wstring iconSymbol,
		color foreground, color background, unsigned int dailyExpences = 0, unsigned int constructionheightAddition = 0,
		unsigned int constructionwidthAddition = 0) : GlobalObject(upperLeft)
	{
		this->constructionheightAddition = constructionheightAddition;
		this->constructionwidthAddition = constructionwidthAddition;
		this->constructionCost = constructionCost;
		this->dailyExpences = dailyExpences;
		this->description = description;
		this->iconSymbol = iconSymbol;
		this->foreground = foreground;
		this->background = background;
	}
	~ConstructionDescriptor() {}
	unsigned int GetConstructionHeightAdd() const;
	unsigned int GetConstructionWidthAdd() const;
	unsigned int GetConstructionCost() const;
	string GetDescription() const;
	wstring GetIconSymbol();
	unsigned int GetDailyExpences() const;
	color GetForegroundColor();
	color GetBackgroundColor();
	virtual wstring GetConstructionSymbol();
};