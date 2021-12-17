#pragma once
#include "ObjectContainers.h"
/////////////Visible Map Class/////////////
class Camera : public GlobalObject
{
public:
	Camera(PointCoord upperLeft) : GlobalObject(upperLeft)
	{
		SetHeightAddition(ConstructionOptions::GetAllOptions()->GetCameraheightAdd());
		SetWidthAddition(ConstructionOptions::GetAllOptions()->GetCamerawidthAdd());
	}
	~Camera()
	{}
	Direction CursorBordersCheck(Cursor* cursor_ptr);
};