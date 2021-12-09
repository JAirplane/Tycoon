#include "VisibleMap.h"
///////////////VisibleMap Class///////////////
Direction VisibleMap::CursorBordersCheck(Cursor* C_ptr)
{
	Direction SD;
	if ((C_ptr->getCursorConsoleLocation()).get_x() == getUpperLeft().get_x())
	{
		SD = Direction::Right;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_y() == getUpperLeft().get_y())
	{
		SD = Direction::Down;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_x() == (getUpperLeft().get_x() + ConstructionOptions::getAllOptions()->getVisibleMapWidth()))
	{
		SD = Direction::Left;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_y() == (getUpperLeft().get_y() + ConstructionOptions::getAllOptions()->getVisibleMapHeight()))
	{
		SD = Direction::Up;
		return SD;
	}
	SD = Direction::None;
	return SD;
}