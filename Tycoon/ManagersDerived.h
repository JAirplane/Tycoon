#pragma once
#include "ConstructionManager.h"
/////////////Building Manager has additional fields that are necessary for buildings/////////////
class BuildingManager : public ConstructionManager
{
public:
	BuildingManager(Cursor* cursor_ptr, ConstructionDescriptor* bd_ptr) :
		ConstructionManager(cursor_ptr, bd_ptr)
	{}
	~BuildingManager() {}
	Construction* CreateConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr) override;
	Construction* CreatePreliminaryConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr) override;
};
class RoadManager : public ConstructionManager
{
public:
	RoadManager(Cursor* cursor_ptr, ConstructionDescriptor* bd_ptr) :
		ConstructionManager(cursor_ptr, bd_ptr)
	{}
	~RoadManager() {}
	Construction* CreateConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr) override;
	Construction* CreatePreliminaryConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr) override;
};