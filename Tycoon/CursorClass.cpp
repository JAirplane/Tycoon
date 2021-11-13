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
void Cursor::CursorShift(ShiftDirection SD)
{
	switch (SD)
	{
	case ShiftDirection::Right:
	{
		Xshift -= 1;
		set_cursor_pos(getCursorConsoleLocation().get_x() - 1, getCursorConsoleLocation().get_y());
		setCursorConsoleLocation();
		break;
	}
	case ShiftDirection::Down:
	{
		Yshift -= 1;
		set_cursor_pos(getCursorConsoleLocation().get_x(), getCursorConsoleLocation().get_y() + 1);
		setCursorConsoleLocation();
		break;
	}
	case ShiftDirection::Left:
	{
		Xshift += 1;
		set_cursor_pos(getCursorConsoleLocation().get_x() + 1, getCursorConsoleLocation().get_y());
		setCursorConsoleLocation();
		break;
	}
	case ShiftDirection::Up:
	{
		Yshift += 1;
		set_cursor_pos(getCursorConsoleLocation().get_x(), getCursorConsoleLocation().get_y() - 1);
		setCursorConsoleLocation();
		break;
	}
	}
}