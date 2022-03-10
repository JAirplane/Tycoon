#pragma once
#include "VisitorManager.h"
/////////////Construction Manager has all the information about Construction/////////////
class ConstructionManager : public IngameObjectManager
{
private:
	ConstructionDescriptor* describe_ptr;
public:
	ConstructionManager(ConstructionDescriptor* descriptor_ptr)
	{
		describe_ptr = descriptor_ptr;
	}
	~ConstructionManager()
	{
		delete describe_ptr;
	}
	virtual Construction* CreateConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr) = 0;
	virtual Construction* CreatePreliminaryConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr) = 0;
	ConstructionDescriptor* GetDescriptor();
};