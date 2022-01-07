#pragma once
#include "PlayingField.h"
/////////////Visible Map Class/////////////
class Camera : public GlobalObject
{
private:
	RectangleSymbols* borderSymbols_ptr;
public:
	Camera(PointCoord upperLeft, int heightAdd, int widthAdd, RectangleSymbols* symbols_ptr) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{
		borderSymbols_ptr = symbols_ptr;
	}
	~Camera()
	{
		delete borderSymbols_ptr;
	}
	Direction CursorIsOnCameraCheck(Cursor* cursor_ptr);
	bool IsShift(PlayingField* field_ptr, Direction shiftDirection);
	RectangleSymbols* GetBorderSymbols() const;
};