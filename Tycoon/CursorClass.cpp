#pragma once
using namespace std;
#include "CursorClass.h"
///////////////Cursor Class///////////////
PointCoord Cursor::getCursorConsoleLocation()
{
	return CursorConsoleLocation;
}
void Cursor::setCursorConsoleLocation()
{
	CursorConsoleLocation = GetConsoleCursorPosition();
}
void Cursor::CursorMovement(PointCoord cursordestination)
{
	set_cursor_pos(cursordestination.get_x(), cursordestination.get_y());
	setCursorConsoleLocation();
}
void Cursor::CursorShift(ShiftDirection SD)
{
	switch (SD)
	{
		case ShiftDirection::Right:
		{
			Xshift -= 1;
			CursorMovement(PointCoord(getCursorConsoleLocation().get_x() - 1, getCursorConsoleLocation().get_y()));
			break;
		}
		case ShiftDirection::Down:
		{
			Yshift -= 1;
			CursorMovement(PointCoord(getCursorConsoleLocation().get_x(), getCursorConsoleLocation().get_y() + 1));
			break;
		}
		case ShiftDirection::Left:
		{
			Xshift += 1;
			CursorMovement(PointCoord(getCursorConsoleLocation().get_x() + 1, getCursorConsoleLocation().get_y()));
			break;
		}
		case ShiftDirection::Up:
		{
			Yshift += 1;
			CursorMovement(PointCoord(getCursorConsoleLocation().get_x(), getCursorConsoleLocation().get_y() - 1));
			break;
		}
	}
}