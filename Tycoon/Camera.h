#pragma once
#include "PlayingField.h"
/////////////Visible Map Class/////////////
class Camera : public MyRectangle
{
public:
	Camera(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, initial, vis_ptr, cur_ptr)
	{}
	Camera(MyRectangle& anotherRectangle) : MyRectangle(anotherRectangle)
	{}
	virtual ~Camera()
	{}
	Direction CursorIsOnCameraBorder(); // returns shift direction if cursor is on camera border
	bool IsShift(PlayingField* field_ptr, Direction shiftDirection);
};