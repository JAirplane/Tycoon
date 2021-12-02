#pragma once
#include "ObjectContainers.h"
/////////////Visible Map Class/////////////
class VisibleMap : public GlobalObject
{
public:
	VisibleMap(PointCoord _ul) : GlobalObject(_ul)
	{
		setHeight(VisibleMapHeight);
		setWidth(VisibleMapWidth);
	}
	~VisibleMap()
	{}
	ShiftDirection CursorBordersCheck(Cursor*);
};
