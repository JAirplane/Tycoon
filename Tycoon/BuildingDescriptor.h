#pragma once
#include "ConstructionDescriptor.h"
class BuildingDescriptor : public ConstructionDescriptor
{
private:
	wstring buildingSymbol;
public:
	BuildingDescriptor(PointCoord managerLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color background, wstring buildingSymbol,
		int dailyExpences = 0, int constructionheightAdd = 0, int constructionwidthAdd = 0) :
		ConstructionDescriptor(managerLocation, constructionCost, description, iconSymbol, foreground, background, dailyExpences, constructionheightAdd, constructionwidthAdd)
	{
		this->buildingSymbol = buildingSymbol;
	}
	~BuildingDescriptor() {}
	wstring GetConstructionSymbol(int mask = 0) override;
};