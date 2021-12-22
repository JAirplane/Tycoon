#pragma once
#include "PlayingField.h"
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
		delete borderSymbols_ptr;
	}
	virtual Construction* CreateConstruction(PointCoord upperLeft);
	ConstructionDescriptor* GetDescriptor();
};