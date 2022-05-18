#pragma once
#include <string>
#include "pugixml.hpp"
#include "StringToColor.h"
class ConstructionConstantsXML
{
private:
	int heightAdd;
	int widthAdd;
	int constructionCost;
	int dailyExpences;
	string description;
	wstring drawingSymbol;
	wstring iconSymbol;
	int hasToilet;
	int satisfiesHunger;
	int visitPrice;
	int entertainmentValue;
	int isExit;
	int maxVisitors;
	int visitTime;
	color foreground;
	color backgroundConnected;
	color backgroundDisconnected;
	color backgroundChosen;
public:
	ConstructionConstantsXML(int heightAdd, int widthAdd, int constructionCost, int dailyExpences, string description, wstring drawingSymbol, wstring iconSymbol,
		int hasToilet, int satisfiesHunger, int visitPrice, int entertainmentValue, int isExit, int maxVisitors, int visitTime, color foreground, color backgroundConnected,
		color backgroundDisconnected, color backgroundChosen)
	{
		this->heightAdd = heightAdd;
		this->widthAdd = widthAdd;
		this->constructionCost = constructionCost;
		this->dailyExpences = dailyExpences;
		this->description = description;
		this->drawingSymbol = drawingSymbol;
		this->iconSymbol = iconSymbol;
		this->hasToilet = hasToilet;
		this->satisfiesHunger = satisfiesHunger;
		this->visitPrice = visitPrice;
		this->entertainmentValue = entertainmentValue;
		this->isExit = isExit;
		this->maxVisitors = maxVisitors;
		this->visitTime = visitTime;
		this->foreground = foreground;
		this->backgroundConnected = backgroundConnected;
		this->backgroundDisconnected = backgroundDisconnected;
		this->backgroundChosen = backgroundChosen;
	}
	virtual ~ConstructionConstantsXML() {}
	int GetHeightAdd() const;
	__declspec(property(get = GetHeightAdd)) int heightAddition;
	int GetWidthAdd() const;
	__declspec(property(get = GetWidthAdd)) int widthAddition;
	int GetConstructionCost() const;
	__declspec(property(get = GetConstructionCost)) int cost;
	int GetDailyExpences() const;
	__declspec(property(get = GetDailyExpences)) int expences;
	string GetDescription() const;
	__declspec(property(get = GetDescription)) string textDescription;
	wstring GetDrawingSymbol() const;
	__declspec(property(get = GetDrawingSymbol)) wstring constructionSymbol;
	wstring GetIconSymbol() const;
	__declspec(property(get = GetIconSymbol)) wstring constructionIconSymbol;
	int GetHasToilet() const;
	__declspec(property(get = GetHasToilet)) int constructionHasToilet;
	int GetSatisfiesHunger() const;
	__declspec(property(get = GetSatisfiesHunger)) int constructionSatisfiesHunger;
	int GetVisitPrice() const;
	__declspec(property(get = GetVisitPrice)) int constructionVisitPrice;
	int GetEntertainmentValue() const;
	__declspec(property(get = GetEntertainmentValue)) int constructionIsEntertainment;
	int GetIsExit() const;
	__declspec(property(get = GetIsExit)) int constructionIsExit;
	int GetMaxVisitors() const;
	__declspec(property(get = GetMaxVisitors)) int constructionMaxVisitors;
	int GetVisitTime() const;
	__declspec(property(get = GetVisitTime)) int constructionVisitTime;
	color GetForegroundColor() const;
	__declspec(property(get = GetForegroundColor)) color constructionForegroundColor;
	color GetBackgroundConnectedColor() const;
	__declspec(property(get = GetBackgroundConnectedColor)) color constructionBackgroundConnectedColor;
	color GetBackgroundDisconnectedColor() const;
	__declspec(property(get = GetBackgroundDisconnectedColor)) color constructionBackgroundDisconnectedColor;
	color GetBackgroundChosenColor() const;
	__declspec(property(get = GetBackgroundChosenColor)) color constructionBackgroundChosenColor;
};