#pragma once
#include "BuildingDescriptor.h"
class RoadDescriptor : public ConstructionDescriptor
{
public:
	RoadDescriptor(PointCoord managerLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChoosen) :
		ConstructionDescriptor(managerLocation, constructionCost, description, iconSymbol, foreground, backgroundConnected, backgroundNotConnected, backgroundChoosen)
	{}
	RoadDescriptor(PointCoord managerLocation, ConstructionConstantsXMLDownload* setOfConstants) : ConstructionDescriptor(managerLocation, setOfConstants)
	{}
	virtual ~RoadDescriptor() {}
	wstring GetConstructionSymbol(int mask = 0) const override;
};