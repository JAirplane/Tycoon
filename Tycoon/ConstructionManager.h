#pragma once
#include "IngameObjectDerived.h"
/////////////Construction Manager has all the information about Construction/////////////
class ConstructionManager : public GlobalObject
{
private:
	Cursor* C_ptr;
	ConstructionDescriptor* Describe_ptr;
public:
	ConstructionManager(PointCoord _upperleft, Cursor* _c_ptr, ConstructionDescriptor* _describe_ptr) : GlobalObject(_upperleft)
	{
		C_ptr = _c_ptr;
		Describe_ptr = _describe_ptr;
	}
	~ConstructionManager() 
	{
		delete Describe_ptr;
	}
	virtual Construction* CreateConstruction(PointCoord upperleft);
	ConstructionDescriptor* getDescriptor();
};
