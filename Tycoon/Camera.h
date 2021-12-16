#pragma once
#include "ObjectContainers.h"
/////////////Visible Map Class/////////////
class Camera : public GlobalObject
{
public:
	Camera(PointCoord _ul) : GlobalObject(_ul)
	{
		SetHeightAddition(ConstructionOptions::GetAllOptions()->GetCameraHeightAdd());
		SetWidthAddition(ConstructionOptions::GetAllOptions()->GetCameraWidthAdd());
	}
	~Camera()
	{}
	Direction CursorBordersCheck(Cursor*);
};