#pragma once
#include "BuildingDescriptor.h"
/////////////Parent Class of Every Object in Game/////////////
class IngameObject : public GlobalObject
{
public:
	IngameObject(PointCoord ul, unsigned int _heightadd = 0, unsigned int _widthadd = 0) : GlobalObject(ul, _heightadd, _widthadd)
	{}
	virtual ConstructionDescriptor* GetDescriptor() const;
};