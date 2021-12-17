#include "Cursor.h"
///////////////Cursor Class///////////////
PointCoord Cursor::GetCursorConsoleLocation()
{
	return cursorConsoleLocation;
}
void Cursor::SetCursorConsoleLocation()
{
	cursorConsoleLocation = GetConsoleCursorPosition();
}
void Cursor::CursorMovement(PointCoord cursorDestination)
{
	set_cursor_pos(cursorDestination.Get_x(), cursorDestination.Get_y());
	SetCursorConsoleLocation();
}
void Cursor::CursorShift(Direction shiftDirection)
{
	switch (shiftDirection)
	{
	case Direction::Right:
	{
		xShift -= 1;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() + 1, GetCursorConsoleLocation().Get_y()));
		return;
	}
	case Direction::Down:
	{
		yShift -= 1;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x(), GetCursorConsoleLocation().Get_y() + 1));
		return;
	}
	case Direction::Left:
	{
		xShift += 1;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() - 1, GetCursorConsoleLocation().Get_y()));
		return;
	}
	case Direction::Up:
	{
		yShift += 1;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x(), GetCursorConsoleLocation().Get_y() - 1));
		return;
	}
	}
}
void Cursor::CursorShift(Direction shiftDirection, int shiftValue)
{
	switch (shiftDirection)
	{
	case Direction::Right:
	{
		xShift -= shiftValue;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() - shiftValue, GetCursorConsoleLocation().Get_y()));
		return;
	}
	case Direction::Left:
	{
		xShift += shiftValue;
		CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() + shiftValue, GetCursorConsoleLocation().Get_y()));
		return;
	}
	}
}