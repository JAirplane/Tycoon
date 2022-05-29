#pragma once
#include "BuildingDescriptor.h"
class RoadDescriptor : public ConstructionDescriptor
{
public:
	RoadDescriptor(int uniqueId, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChoosen) :
		ConstructionDescriptor(uniqueId, constructionCost, description, iconSymbol, foreground, backgroundConnected, backgroundNotConnected, backgroundChoosen)
	{}
	RoadDescriptor(ConstructionConstantsXML setOfConstants) : ConstructionDescriptor(setOfConstants)
	{}
	virtual ~RoadDescriptor() {}
	wstring GetConstructionSymbol(int mask = 0) const override;
};