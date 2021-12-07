#pragma once
#include "ObjectContainers.h"
/////////////Visible Map Class/////////////
class VisibleMap : public GlobalObject
{
public:
	VisibleMap(PointCoord _ul) : GlobalObject(_ul)
	{
		setHeightAddition(ConstructionOptions::getAllOptions()->getVisibleMapHeight());
		setWidthAddition(ConstructionOptions::getAllOptions()->getVisibleMapWidth());
	}
	~VisibleMap()
	{}
	ShiftDirection CursorBordersCheck(Cursor*);
};