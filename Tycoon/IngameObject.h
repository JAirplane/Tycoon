#pragma once
#include "RoadDescriptor.h"
/////////////Parent Class of Every Object in Game/////////////
class IngameObject : public GlobalObject
{
public:
	IngameObject(PointCoord upperLeft, unsigned int heightAdd = 0, unsigned int widthAdd = 0) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{}
	virtual ConstructionDescriptor* GetDescriptor() const;
};