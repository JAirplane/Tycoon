#pragma once
#include "ConstructionOptions.h"
/////////////Cursor Class/////////////
class Cursor
{
private:
	int Xshift;
	int Yshift;
	PointCoord CursorConsoleLocation; // location according to console coords (1, 1 is minimum)
	bool Intersection; // cursor and ingame object at the same coord
public:
	Cursor()
	{
		CursorConsoleLocation.set_coord(1, 1);
		Xshift = 0;
		Yshift = 0;
		Intersection = 0;
	}
	~Cursor()
	{}
	PointCoord getCursorConsoleLocation();
	void setCursorConsoleLocation();
	void CursorMovement(PointCoord cursordestination);
	void CursorShift(Direction);
	void CursorShift(Direction SD, int shiftvalue);
	bool getIntersectionFlag() const;
	void setIntersectionFlag(bool superposition);
};