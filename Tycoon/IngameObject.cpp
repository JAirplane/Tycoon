#include "IngameObject.h"
/////////////Parent Class of Every Object in Game/////////////
ConstructionDescriptor* IngameObject::GetDescriptor() const
{
	ConstructionDescriptor* cd_ptr = nullptr;
	return cd_ptr;
}
Visualisation* IngameObject::GetPainter() const
{
	return draw_ptr;
}
void IngameObject::ShiftObject(Direction shiftDirection, int shiftValue)
{
	switch (shiftDirection)
	{
		case Direction::Right: {SetUpperLeft(PointCoord(GetUpperLeft().Get_x() + shiftValue, GetUpperLeft().Get_y())); return; }
		case Direction::Down: {SetUpperLeft(PointCoord(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() + shiftValue)); return; }
		case Direction::Left: {SetUpperLeft(PointCoord(GetUpperLeft().Get_x() - shiftValue, GetUpperLeft().Get_y())); return; }
		case Direction::Up: {SetUpperLeft(PointCoord(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() - shiftValue)); return; }
		default: {return;} //TODO exception
	}
}