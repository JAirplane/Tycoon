#pragma once
#include "GlobalObject.h"
/////////////Parent Class of Every Object in Game/////////////
class IngameObject : public GlobalObject
{
private:
	Visualisation* draw_ptr;
public:
	IngameObject(PointCoord upperLeft, unsigned int heightAdd = 0, unsigned int widthAdd = 0, Visualisation* paint_ptr) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{
		draw_ptr = paint_ptr;
	}
	virtual ConstructionDescriptor* GetDescriptor() const;
	Visualisation* GetPainter() const;
	virtual void DrawObject(int mask = 0) const = 0;
};