#pragma once
#include "ObjectContainers.h"
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
	Direction CursorBordersCheck(Cursor* cursor_ptr);
	RectangleSymbols* GetBorderSymbols() const;
};