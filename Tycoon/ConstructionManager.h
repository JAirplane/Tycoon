#pragma once
#include "ObjectContainers.h"
/////////////Construction Manager has all the information about Construction/////////////
class ConstructionManager : public GlobalObject
{
private:
	Cursor* cursor_ptr;
	ConstructionDescriptor* describe_ptr;
public:
	ConstructionManager(PointCoord upperLeft, Cursor* c_ptr, ConstructionDescriptor* descriptor_ptr) : GlobalObject(upperLeft)
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
	void SetUpperLeft(PointCoord point) override;
	ConstructionDescriptor* GetDescriptor();
};