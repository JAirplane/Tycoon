#pragma once
#include "BuildingDescriptor.h"
class RoadDescriptor : public ConstructionDescriptor
{
public:
	RoadDescriptor(PointCoord managerLocation, unsigned int constructionCost, string description, wstring iconSymbol, color foreground, color background) :
		ConstructionDescriptor(managerLocation, constructionCost, description, iconSymbol, foreground, background)
		{}
	~RoadDescriptor() {}
	wstring GetConstructionSymbol(int mask = 0) override;
};
