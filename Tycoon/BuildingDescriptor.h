#pragma once
#include "ConstructionDescriptor.h"
class buildingDescriptor : public ConstructionDescriptor
{
private:
	wstring buildingSymbol;
public:
	buildingDescriptor(PointCoord upperLeft, unsigned int constructionCost, string description, wstring iconSymbol, color foreground, color background, wstring buildingSymbol,
		unsigned int dailyExpences = 0, unsigned int constructionheightAdd = 0, unsigned int constructionwidthAdd = 0) :
		ConstructionDescriptor(upperLeft, constructionCost, description, iconSymbol, foreground, background, dailyExpences, constructionheightAdd, constructionwidthAdd)
	{
		this->buildingSymbol = buildingSymbol;
	}
	~buildingDescriptor() {}
	wstring GetConstructionSymbol() override;
};