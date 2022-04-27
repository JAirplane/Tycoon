#pragma once
#include "ConstructionManager.h"
/////////////Building Manager has additional fields that are necessary for buildings/////////////
class BuildingManager : public ConstructionManager
{
public:
	BuildingManager(ConstructionDescriptor* bd_ptr) : ConstructionManager(bd_ptr)
	{}
	~BuildingManager()
	{}
	Construction* CreateConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const override;
	Construction* CreatePreliminaryConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const override;
};
class RoadManager : public ConstructionManager
{
public:
	RoadManager(ConstructionDescriptor* bd_ptr) : ConstructionManager(bd_ptr)
	{}
	~RoadManager() {}
	Construction* CreateConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const override;
	Construction* CreatePreliminaryConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const override;
};
class VisibleOutsideRoadManager : public RoadManager
{
public:
	VisibleOutsideRoadManager(ConstructionDescriptor* bd_ptr) : RoadManager(bd_ptr)
	{}
	~VisibleOutsideRoadManager() {}
	Construction* CreateConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const override;
	Construction* CreatePreliminaryConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const override;
};
class UnbreakableRoadManager : public RoadManager
{
public:
	UnbreakableRoadManager(ConstructionDescriptor* bd_ptr) : RoadManager(bd_ptr)
	{}
	~UnbreakableRoadManager() {}
	Construction* CreateConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const override;
	Construction* CreatePreliminaryConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const override;
};