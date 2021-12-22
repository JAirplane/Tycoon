#pragma once
#include "Cursor.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
class ConstructionDescriptor
{
private:
	unsigned int constructionHeightAddition;
	unsigned int constructionWidthAddition;
	unsigned int constructionCost;
	unsigned int dailyExpences;
	string description;
	wstring iconSymbol;
	color foreground;
	color background;
public:
	ConstructionDescriptor(unsigned int constructionCost, string description, wstring iconSymbol,
		color foreground, color background, unsigned int dailyExpences = 0, unsigned int constructionHeightAddition = 0,
		unsigned int constructionWidthAddition = 0)
	{
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