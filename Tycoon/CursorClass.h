#pragma once
#include "Coord and constants.h"
/////////////Cursor Class/////////////
class Cursor
{
private:
	int Xshift;
	int Yshift;
	PointCoord CursorConsoleLocation; // location according to console coords (1, 1 is minimum)
public:
	Cursor()
	{
		CursorConsoleLocation.set_coord(1, 1);
		Xshift = 0;
		Yshift = 0;
	}
	~Cursor()
	{}
	PointCoord getCursorConsoleLocation();
	void setCursorConsoleLocation();
	void CursorMovement(PointCoord cursordestination);
	void CursorShift(ShiftDirection);
	void CursorShift(ShiftDirection SD, int shiftvalue);
};