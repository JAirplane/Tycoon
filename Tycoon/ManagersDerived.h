#pragma once
#include "ConstructionManager.h"
/////////////Building Manager has additional fields that are necessary for buildings/////////////
class BuildingManager : public ConstructionManager
{
public:
	BuildingManager(PointCoord _upperleft, Cursor* _c_ptr, ConstructionDescriptor* _bd_ptr) :
		ConstructionManager(_upperleft, _c_ptr, _bd_ptr)
	{}
	~BuildingManager() {}
	Construction* CreateConstruction(PointCoord upperleft) override;
};
class RoadManager : public ConstructionManager
{
public:
	RoadManager(PointCoord _upperleft, Cursor* _c_ptr, ConstructionDescriptor* _bd_ptr) :
		ConstructionManager(_upperleft, _c_ptr, _bd_ptr)
	{}
	~RoadManager() {}
	Construction* CreateConstruction(PointCoord upperleft) override;
};
