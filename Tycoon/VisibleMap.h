#pragma once
#include "ObjectContainers.h"
/////////////Visible Map Class/////////////
class VisibleMap
{
private:
	PointCoord UpperLeftCorner;
	PointCoord BottomRightCorner;
public:
	VisibleMap()
	{
		UpperLeftCorner.set_coord(1, 1);
		BottomRightCorner.set_coord(UpperLeftCorner.get_x() + X_axis, UpperLeftCorner.get_y() + Y_axis);
	}
	~VisibleMap()
	{}
	PointCoord getUpperLeftCorner() const;
	PointCoord getBottomRightCorner() const;
	void SetCorners(PointCoord UL, PointCoord BR);
	ShiftDirection CursorBordersCheck(Cursor*);
};
