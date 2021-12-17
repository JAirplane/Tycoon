#pragma once
#include "IngameObjectDerived.h"
/////////////Construction Manager has all the information about Construction/////////////
class ConstructionManager : public GlobalObject
{
private:
	Cursor* cursor_ptr;
	ConstructionDescriptor* describe_ptr;
public:
	ConstructionManager(PointCoord upperLeft, Cursor* cursor_ptr, ConstructionDescriptor* describe_ptr) : GlobalObject(upperLeft)
	{
		this->cursor_ptr = cursor_ptr;
		this->describe_ptr = describe_ptr;
	}
	~ConstructionManager()
	{
		delete describe_ptr;
	}
	virtual Construction* CreateConstruction(PointCoord upperLeft);
	ConstructionDescriptor* GetDescriptor();
};