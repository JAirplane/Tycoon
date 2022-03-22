#include "Coord_and_constants.h"
///////////////PointCoord Struct///////////////
int PointCoord::Get_x() const
{
	return xCoord;
}
int PointCoord::Get_y() const
{
	return yCoord;
}
void PointCoord::SetCoord(int x, int y)
{
	xCoord = x;
	yCoord = y;
}
void PointCoord::SetCoord(PointCoord point)
{
	xCoord = point.Get_x();
	yCoord = point.Get_y();
}
bool PointCoord::operator == (PointCoord point)
{
	return (xCoord == point.xCoord && yCoord == point.yCoord);
}
bool PointCoord::operator != (PointCoord point)
{
	return (xCoord != point.xCoord || yCoord != point.yCoord);
}
PointCoord PointCoord::GetSideCoord(Direction dir) const
{
	switch (dir)
	{
	case Direction::Left: {return PointCoord(this->Get_x() - 1, this->Get_y()); }
	case Direction::Up: {return PointCoord(this->Get_x(), this->Get_y() - 1); }
	case Direction::Right: {return PointCoord(this->Get_x() + 1, this->Get_y()); }
	case Direction::Down: {return PointCoord(this->Get_x(), this->Get_y() + 1); }
	default: {throw MyException("PointCoord::GetSideCoord(Direction dir) const bad direction"); }
	}
}
//
NumberOfDigits* NumberOfDigits::GetDigitsCounter()
{
	return countDigits_ptr;
}
NumberOfDigits* NumberOfDigits::countDigits_ptr = new NumberOfDigits();
int NumberOfDigits::GetNumberOfDigits(int number)
{
	int digits = 0;
	while (number != 0)
	{
		number /= 10; digits++;
	}
	return digits;
}