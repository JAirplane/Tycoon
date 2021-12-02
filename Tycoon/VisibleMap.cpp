#include "VisibleMap.h"
///////////////VisibleMap Class///////////////
ShiftDirection VisibleMap::CursorBordersCheck(Cursor* C_ptr)
{
	ShiftDirection SD;
	if ((C_ptr->getCursorConsoleLocation()).get_x() == getUpperLeft().get_x())
	{
		SD = ShiftDirection::Right;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_y() == getUpperLeft().get_y())
	{
		SD = ShiftDirection::Down;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_x() == (getUpperLeft().get_x() + VisibleMapWidth - 1))
	{
		SD = ShiftDirection::Left;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_y() == (getUpperLeft().get_y() + VisibleMapHeight - 1))
	{
		SD = ShiftDirection::Up;
		return SD;
	}
	SD = ShiftDirection::Middle;
	return SD;
}