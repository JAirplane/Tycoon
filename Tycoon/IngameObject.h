#pragma once
#include "GraphStatusObserverInterface.h"
/////////////Parent Class of Every Object in Game/////////////
class IngameObject : public GlobalObject
{
private:
	Visualisation* draw_ptr;
public:
	IngameObject(PointCoord upperLeft, Visualisation* paint_ptr, int heightAdd = 0, int widthAdd = 0) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{
		draw_ptr = paint_ptr;
	}
	Visualisation* GetPainter() const;
	virtual void DrawObject(int mask = 0, int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const = 0;
	virtual void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const = 0;
	virtual void ShiftObject(Direction shiftDirection, int shiftValue = 1);
};