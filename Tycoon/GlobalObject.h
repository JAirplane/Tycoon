#pragma once
#include "Cursor.h"
/////////////Parent Class of All Objects/////////////
class GlobalObject
{
private:
	PointCoord upperLeft;
	unsigned int heightAddition;
	unsigned int widthAddition;
public:
	GlobalObject(PointCoord upperLeft, unsigned int heightAdd = 0, unsigned int widthAdd = 0) : upperLeft(upperLeft), heightAddition(heightAdd), widthAddition(widthAdd)
	{}
	~GlobalObject()
	{}
	PointCoord GetUpperLeft() const;
	void SetUpperLeft(PointCoord point);
	unsigned int GetHeightAddition() const;
	void SetHeightAddition(const int heightAdd);
	unsigned int GetWidthAddition() const;
	void SetWidthAddition(const int widthAdd);
};