#pragma once
#include "ConstructionDescriptor.h"
class BuildingDescriptor : public ConstructionDescriptor
{
private:
	wstring buildingSymbol;
	bool restoreToiletNeed;
	int satisfactionOfHunger;
	int visitPrice;
public:
	BuildingDescriptor(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChoosen, wstring buildingSymbol, bool restoreToiletNeed, int satisfactionOfHunger, int visitPrice, int dailyExpences = 0,
		int constructionheightAdd = 0, int constructionwidthAdd = 0) : ConstructionDescriptor(menuElementLocation, constructionCost, description, iconSymbol, foreground,
			backgroundConnected, backgroundNotConnected, backgroundChoosen, dailyExpences, constructionheightAdd, constructionwidthAdd)
	{
		this->buildingSymbol = buildingSymbol;
		this->restoreToiletNeed = restoreToiletNeed;
		this->satisfactionOfHunger = satisfactionOfHunger;
		this->visitPrice = visitPrice;
	}
	~BuildingDescriptor() {}
	wstring GetConstructionSymbol(int mask = 0) override;
	bool GetRestorationOfToiletNeed() const override;
	int GetSatisfactionOfHunger() const override;
	int GetVisitPrice() const override;
};