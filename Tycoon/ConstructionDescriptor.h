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
	char iconSymbol;
	color foreground;
	color background;
public:
	ConstructionDescriptor(PointCoord upperLeft, unsigned int constructionCost, string description, char iconSymbol,
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
	void SetConstructionheightAdd(unsigned int heightAddition);
	unsigned int GetConstructionWidthAdd() const;
	void SetConstructionwidthAdd(unsigned int widthAddition);
	unsigned int GetConstructionCost() const;
	void SetConstructionCost(const int constructionCost);
	string GetDescription() const;
	void SetDescription(string description);
	char GetIconSymbol();
	void SetIconSymbol(const char iconSymbol);
	unsigned int GetDailyExpences() const;
	void SetDailyExpences(unsigned int dailyExpences);
	color GetForegroundColor();
	void SetForegroundColor(color foreground);
	color GetBackgroundColor();
	void SetBackgroundColor(color background);
	virtual char GetBuildingSymbol();
	virtual void SetBuildingSymbol(const char buildingSymbol);
};