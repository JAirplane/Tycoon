#include "VisibleMap.h"
///////////////VisibleMap Class///////////////
PointCoord VisibleMap::getUpperLeftCorner() const
{
	return UpperLeftCorner;
}
PointCoord VisibleMap::getBottomRightCorner() const
{
	return BottomRightCorner;
}
void VisibleMap::SetCorners(PointCoord UL, PointCoord BR)
{
	UpperLeftCorner.set_coord(UL);
	BottomRightCorner.set_coord(BR);
}
ShiftDirection VisibleMap::CursorBordersCheck(Cursor* C_ptr)
{
	ShiftDirection SD;
	if ((C_ptr->getCursorConsoleLocation()).get_x() == UpperLeftCorner.get_x())
	{
		SD = ShiftDirection::Right;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_y() == UpperLeftCorner.get_y())
	{
		SD = ShiftDirection::Down;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_x() == BottomRightCorner.get_x())
	{
		SD = ShiftDirection::Left;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_y() == BottomRightCorner.get_y())
	{
		SD = ShiftDirection::Up;
		return SD;
	}
	SD = ShiftDirection::Middle;
	return SD;
}