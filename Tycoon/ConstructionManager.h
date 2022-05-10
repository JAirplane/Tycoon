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
	virtual ~ConstructionManager()
	{
		delete describe_ptr;
	}
	virtual Construction* CreateConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const = 0;
	virtual Construction* CreatePreliminaryConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const = 0;
	ConstructionDescriptor* GetDescriptor() const;
};