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
public:
	BuildingDescriptor(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChoosen, wstring buildingSymbol, int restoreToiletNeed, int satisfactionOfHunger, int visitPrice, int entertainmentValue,
		int dailyExpences = 0, int constructionheightAdd = 0, int constructionwidthAdd = 0) : ConstructionDescriptor(menuElementLocation, constructionCost, description, iconSymbol,
			foreground, backgroundConnected, backgroundNotConnected, backgroundChoosen, dailyExpences, constructionheightAdd, constructionwidthAdd)
	{
		this->buildingSymbol = buildingSymbol;
		this->restoreToiletNeed = restoreToiletNeed;
		this->satisfactionOfHunger = satisfactionOfHunger;
		this->visitPrice = visitPrice;
		this->entertainmentValue = entertainmentValue;
	}
	~BuildingDescriptor() {}
	wstring GetConstructionSymbol(int mask = 0) override;
	int GetRestorationOfToiletNeed() const override;
	int GetSatisfactionOfHunger() const override;
	int GetVisitPrice() const override;
	int GetEntertainmentValue() const override;
};