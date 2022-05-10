#pragma once
#include "PlayingField.h"
/////////////Visible Map Class/////////////
class Camera : public MyRectangle
{
public:
	Camera(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor,
		Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
	{}
	Camera(MyRectangle*& anotherRectangle) : MyRectangle(anotherRectangle)
	{}
	virtual ~Camera()
	{}
	Direction CursorIsOnCameraBorder(); // returns shift direction if cursor is on camera border
	bool IsShift(PlayingField* field_ptr, Direction shiftDirection);
};