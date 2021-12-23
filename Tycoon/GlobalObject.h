#pragma once
#include "RoadDescriptor.h"
/////////////Parent Class of All Objects/////////////
class GlobalObject
{
private:
	PointCoord upperLeft;
	int heightAddition;
	int widthAddition;
public:
	GlobalObject(PointCoord upperLeft, int heightAdd = 0, int widthAdd = 0) : upperLeft(upperLeft), heightAddition(heightAdd), widthAddition(widthAdd)
	{}
	~GlobalObject()
	{}
	PointCoord GetUpperLeft() const;
	virtual void SetUpperLeft(PointCoord point);
	int GetHeightAddition() const;
	void SetHeightAddition(const int heightAdd);
	int GetWidthAddition() const;
	void SetWidthAddition(const int widthAdd);
};