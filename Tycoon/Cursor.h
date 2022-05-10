#pragma once
#include "GlobalObject.h"
/////////////Cursor Class/////////////
class Camera;
class Menu;
class InfoPanel;
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
	virtual ~Cursor()
	{}
	PointCoord GetCursorConsoleLocation() const;
	void SetCursorConsoleLocation();
	void CursorMovement(PointCoord cursorDestination);
	void CursorShift(Direction shiftDirection, int shiftValue = 1);
	CursorLocation GetCursorArea(const GlobalObject* camera_ptr, const GlobalObject* menu_ptr, const GlobalObject* infoPanel_ptr) const;
	void ReturnToCamera(const GlobalObject* camera_ptr, const GlobalObject* menu_ptr, const GlobalObject* infoPanel_ptr);
};