#pragma once
#include "ObjectContainers.h"
/////////////Visible Map Class/////////////
class Camera : public GlobalObject
{
private:
	RectangleSymbols* borderSymbols_ptr;
public:
	Camera(PointCoord upperLeft, int heightAdd, int widthAdd, RectangleSymbols* borderSymbols_ptr) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{
		this->borderSymbols_ptr = borderSymbols_ptr;
	}
	~Camera()
	{
		delete borderSymbols_ptr;
	}
	Direction CursorBordersCheck(Cursor* cursor_ptr);
};