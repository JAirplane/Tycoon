#pragma once
#include "RectangleSymbols.h"
/////////////Cursor Class/////////////
class Cursor
{
private:
	int xShift;
	int yShift;
	PointCoord cursorConsoleLocation; // location according to console coords (1, 1 is minimum)
public:
	Cursor()
	{
		cursorConsoleLocation.SetCoord(1, 1);
		xShift = 0;
		yShift = 0;
	}
	~Cursor()
	{}
	PointCoord GetCursorConsoleLocation();
	void SetCursorConsoleLocation();
	void CursorMovement(PointCoord cursorDestination);
	void CursorShift(Direction shiftDirection);
	void CursorShift(Direction shiftDirection, int shiftValue);
};