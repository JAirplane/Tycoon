#pragma once
#include "ObjectContainers.h"
/////////////Construction Manager has all the information about Construction/////////////
class ConstructionManager
{
private:
	Cursor* cursor_ptr;
	ConstructionDescriptor* describe_ptr;
public:
	ConstructionManager(Cursor* c_ptr, ConstructionDescriptor* descriptor_ptr)
	{
		cursor_ptr = c_ptr;
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