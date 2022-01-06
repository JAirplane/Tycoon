#include "PlayingField.h"
/////////////PlayingField Class/////////////
RectangleSymbols* PlayingField::GetBorderSymbols() const
{
	return rectangleSymbols_ptr;
}
void PlayingField::Shift(Direction shiftDirection, int shiftValue)
{
	PointCoord upperLeft = GetUpperLeft();
	switch (shiftDirection)
	{
		case Direction::Right:
		{SetUpperLeft(PointCoord(GetUpperLeft().Get_x() + shiftValue, GetUpperLeft().Get_y())); return;}
		case Direction::Down:
		{SetUpperLeft(PointCoord(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() + shiftValue)); return;}
		case Direction::Left:
		{SetUpperLeft(PointCoord(GetUpperLeft().Get_x() - shiftValue, GetUpperLeft().Get_y())); return;}
		case Direction::Up:
		{SetUpperLeft(PointCoord(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() - shiftValue)); return;}
	}
}