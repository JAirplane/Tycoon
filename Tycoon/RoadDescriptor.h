#pragma once
#include "BuildingDescriptor.h"
class RoadDescriptor : public ConstructionDescriptor
{
public:
	RoadDescriptor(unsigned int constructionCost, string description, wstring iconSymbol, color foreground, color background,
		unsigned int dailyExpences = 0, unsigned int constructionheightAdd = 0, unsigned int constructionwidthAdd = 0) :
		ConstructionDescriptor(constructionCost, description, iconSymbol, foreground, background, dailyExpences, constructionheightAdd, constructionwidthAdd)
		{}
	~RoadDescriptor() {}
	wstring GetConstructionSymbol() override;
};
