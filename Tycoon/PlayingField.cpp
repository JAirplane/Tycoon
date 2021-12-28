#include "PlayingField.h"
/////////////PlayingField Class/////////////
RectangleSymbols* PlayingField::GetBorderSymbols() const
{
	return rectangleSymbols_ptr;
}
void PlayingField::Shift(Direction shiftDirection)
{
	switch (shiftDirection)
	{
	case Direction::Right:
	{
		GetUpperLeft().SetCoord(GetUpperLeft().Get_x() + 1, GetUpperLeft().Get_y());
		return;
	}
	case Direction::Down:
	{
		GetUpperLeft().SetCoord(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() + 1);
		return;
	}
	case Direction::Left:
	{
		GetUpperLeft().SetCoord(GetUpperLeft().Get_x() - 1, GetUpperLeft().Get_y());
		return;
	}
	case Direction::Up:
	{
		GetUpperLeft().SetCoord(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() - 1);
		return;
	}
	}
}
void PlayingField::Shift(Direction shiftDirection, int shiftValue)
{
	switch (shiftDirection)
	{
	case Direction::Right:
	{
		GetUpperLeft().SetCoord(GetUpperLeft().Get_x() + shiftValue, GetUpperLeft().Get_y());
		break;
	}
	case Direction::Left:
	{
		GetUpperLeft().SetCoord(GetUpperLeft().Get_x() - shiftValue, GetUpperLeft().Get_y());
		break;
	}
	}
}