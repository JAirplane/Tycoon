#include "Cursor.h"
///////////////Cursor Class///////////////
PointCoord Cursor::GetCursorConsoleLocation()
{
	return CursorConsoleLocation;
}
void Cursor::setCursorConsoleLocation()
{
	CursorConsoleLocation = GetConsoleCursorPosition();
}
void Cursor::CursorMovement(PointCoord cursordestination)
{
	set_cursor_pos(cursordestination.Get_x(), cursordestination.Get_y());
	setCursorConsoleLocation();
}
void Cursor::CursorShift(Direction SD)
{
	switch (SD)
	{
	case Direction::Right:
	{
		Xshift -= 1;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() + 1, GetCursorConsoleLocation().Get_y()));
		return;
	}
	case Direction::Down:
	{
		Yshift -= 1;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x(), GetCursorConsoleLocation().Get_y() + 1));
		return;
	}
	case Direction::Left:
	{
		Xshift += 1;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() - 1, GetCursorConsoleLocation().Get_y()));
		return;
	}
	case Direction::Up:
	{
		Yshift += 1;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x(), GetCursorConsoleLocation().Get_y() - 1));
		return;
	}
	}
}
void Cursor::CursorShift(Direction SD, int shiftvalue)
{
	switch (SD)
	{
	case Direction::Right:
	{
		Xshift -= shiftvalue;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() - shiftvalue, GetCursorConsoleLocation().Get_y()));
		return;
	}
	case Direction::Left:
	{
		Xshift += shiftvalue;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() + shiftvalue, GetCursorConsoleLocation().Get_y()));
		return;
	}
	}
}