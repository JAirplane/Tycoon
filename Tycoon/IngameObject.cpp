#include "IngameObject.h"
/////////////Parent Class of Every Object in Game/////////////
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
		default: {throw MyException("IngameObject::ShiftObject(Direction shiftDirection, int shiftValue) got bad Direction.");} //TODO exception
	}
}