#pragma once
#include "ObjectContainers.h"
/////////////Visible Map Class/////////////
class Camera : public GlobalObject
{
private:

public:
	Camera(PointCoord upperLeft, int heightAdd, int widthAdd) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{
		SetHeightAddition(ConstructionOptions::GetAllOptions()->GetCameraHeightAdd());
		SetWidthAddition(ConstructionOptions::GetAllOptions()->GetCameraWidthAdd());
	}
	~Camera()
	{}
	Direction CursorBordersCheck(Cursor* cursor_ptr);
};