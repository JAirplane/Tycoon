#pragma once
#include "BuildingDescriptor.h"
class RoadDescriptor : public ConstructionDescriptor
{
private:
	roads_ptr;
public:
	RoadDescriptor(PointCoord upperLeft, unsigned int constructionCost, string description, wstring iconSymbol, color foreground, color background, AllRoads* roads_ptr,
		unsigned int dailyExpences = 0, unsigned int constructionheightAdd = 0, unsigned int constructionwidthAdd = 0) :
		ConstructionDescriptor(upperLeft, constructionCost, description, iconSymbol, foreground, background, dailyExpences, constructionheightAdd, constructionwidthAdd)
	{
		this->roads_ptr = roads_ptr;
	}
	~RoadDescriptor() {}
	wstring GetConstructionSymbol() override;
};
