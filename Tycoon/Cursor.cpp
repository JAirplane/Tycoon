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
void Cursor::CursorShift(Direction shiftDirection, int shiftValue)
{
	switch (shiftDirection)
	{
		case Direction::Right:
		{ CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() + shiftValue, GetCursorConsoleLocation().Get_y())); return; }
		case Direction::Down:
		{ CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x(), GetCursorConsoleLocation().Get_y() + shiftValue)); return; }
		case Direction::Left:
		{ CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() - shiftValue, GetCursorConsoleLocation().Get_y())); return; }
		case Direction::Up:
		{ CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x(), GetCursorConsoleLocation().Get_y() - shiftValue)); return; }
		default: {return; }
	}
}