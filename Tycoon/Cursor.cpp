#include "Cursor.h"
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
void Cursor::CursorShift(Direction SD)
{
	switch (SD)
	{
	case Direction::Right:
	{
		Xshift -= 1;
		CursorMovement(PointCoord(getCursorConsoleLocation().get_x() + 1, getCursorConsoleLocation().get_y()));
		return;
	}
	case Direction::Down:
	{
		Yshift -= 1;
		CursorMovement(PointCoord(getCursorConsoleLocation().get_x(), getCursorConsoleLocation().get_y() + 1));
		return;
	}
	case Direction::Left:
	{
		Xshift += 1;
		CursorMovement(PointCoord(getCursorConsoleLocation().get_x() - 1, getCursorConsoleLocation().get_y()));
		return;
	}
	case Direction::Up:
	{
		Yshift += 1;
		CursorMovement(PointCoord(getCursorConsoleLocation().get_x(), getCursorConsoleLocation().get_y() - 1));
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
		CursorMovement(PointCoord(getCursorConsoleLocation().get_x() - shiftvalue, getCursorConsoleLocation().get_y()));
		return;
	}
	case Direction::Left:
	{
		Xshift += shiftvalue;
		CursorMovement(PointCoord(getCursorConsoleLocation().get_x() + shiftvalue, getCursorConsoleLocation().get_y()));
		return;
	}
	}
}
bool Cursor::getIntersectionFlag() const
{
	return Intersection;
}
void Cursor::setIntersectionFlag(bool superposition)
{
	Intersection = superposition;
}