#pragma once
#include "IngameObjectDerived.h"
/////////////Construction Manager has all the information about Construction/////////////
class ConstructionManager : public GlobalObject
{
private:
	Cursor* cursor_ptr;
	ConstructionDescriptor* Describe_ptr;
public:
	ConstructionManager(PointCoord _upperLeft, Cursor* _cursor_ptr, ConstructionDescriptor* _describe_ptr) : GlobalObject(_upperLeft)
	{
		cursor_ptr = _cursor_ptr;
		Describe_ptr = _describe_ptr;
	}
	~ConstructionManager()
	{
		delete Describe_ptr;
	}
	virtual Construction* CreateConstruction(PointCoord upperLeft);
	ConstructionDescriptor* GetDescriptor();
};