#pragma once
#include "ConstructionDescriptor.h"
class buildingDescriptor : public ConstructionDescriptor
{
private:
	char buildingSymbol;
public:
	buildingDescriptor(PointCoord upperLeft, unsigned int constructionCost, string description, char iconSymbol, color foreground, color background, char buildingSymbol,
		unsigned int dailyExpences = 0, unsigned int constructionheightAdd = 0, unsigned int constructionwidthAdd = 0) :
		ConstructionDescriptor(upperLeft, constructionCost, description, iconSymbol, foreground, background, dailyExpences, constructionheightAdd, constructionwidthAdd)
	{
		this->buildingSymbol = buildingSymbol;
	}
	~buildingDescriptor() {}
	char GetBuildingSymbol() override;
	void SetBuildingSymbol(const char _symb);
};