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
	GlobalObject(PointCoord ul, unsigned int heightadd = 0, unsigned int widthadd = 0) : upperLeft(ul), heightAddition(heightadd), widthAddition(widthadd)
	{}
	~GlobalObject()
	{}
	PointCoord GetUpperLeft() const;
	void SetUpperLeft(PointCoord _pc);
	unsigned int GetHeightAddition() const;
	void SetHeightAddition(const int _ha);
	unsigned int GetWidthAddition() const;
	void SetWidthAddition(const int _wa);
};