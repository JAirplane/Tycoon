#pragma once
#include "ConstructionDescriptor.h"
class BuildingDescriptor : public ConstructionDescriptor
{
private:
	wstring buildingSymbol;
	int restoreToiletNeed;
	int satisfactionOfHunger;
	int visitPrice;
	int entertainmentValue;
	int isExit;
	int maxVisitors;
	int visitTime;
public:
	BuildingDescriptor(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChosen, wstring buildingSymbol, int restoreToiletNeed, int satisfactionOfHunger, int visitPrice, int entertainmentValue,
		int isExit, int maxVisitors, int visitTime, int dailyExpences = 0, int constructionHeightAdd = 0, int constructionWidthAdd = 0) :
		ConstructionDescriptor(menuElementLocation, constructionCost, description, iconSymbol, foreground, backgroundConnected,
			backgroundNotConnected, backgroundChosen, dailyExpences, constructionHeightAdd, constructionWidthAdd)
	{
		this->buildingSymbol = buildingSymbol;
		this->restoreToiletNeed = restoreToiletNeed;
		this->satisfactionOfHunger = satisfactionOfHunger;
		this->visitPrice = visitPrice;
		this->entertainmentValue = entertainmentValue;
		this->isExit = isExit;
		this->maxVisitors = maxVisitors;
		this->visitTime = visitTime;
	}
	~BuildingDescriptor() {}
	wstring GetConstructionSymbol(int mask = 0) const override;
	int GetRestorationOfToiletNeed() const override;
	int GetSatisfactionOfHunger() const override;
	int GetVisitPrice() const override;
	int GetEntertainmentValue() const override;
	int GetIsExit() const override;
	int GetMaxVisitors() const override;
	int GetVisitTime() const override;
};