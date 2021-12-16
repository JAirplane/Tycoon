#pragma once
#include "ConstructionManager.h"
/////////////Building Manager has additional fields that are necessary for buildings/////////////
class BuildingManager : public ConstructionManager
{
public:
	BuildingManager(PointCoord _upperLeft, Cursor* _cursor_ptr, ConstructionDescriptor* _bd_ptr) :
		ConstructionManager(_upperLeft, _cursor_ptr, _bd_ptr)
	{}
	~BuildingManager() {}
	Construction* CreateConstruction(PointCoord upperLeft) override;
};
class RoadManager : public ConstructionManager
{
public:
	RoadManager(PointCoord _upperLeft, Cursor* _cursor_ptr, ConstructionDescriptor* _bd_ptr) :
		ConstructionManager(_upperLeft, _cursor_ptr, _bd_ptr)
	{}
	~RoadManager() {}
	Construction* CreateConstruction(PointCoord upperLeft) override;
};