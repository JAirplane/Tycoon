#include "Coord_and_constants.h"
///////////////PointCoord Struct///////////////
int PointCoord::Get_x() const
{
	return x_coord;
}
int PointCoord::Get_y() const
{
	return y_coord;
}
void PointCoord::set_coord(int x, int y)
{
	x_coord = x;
	y_coord = y;
}
void PointCoord::set_coord(PointCoord pc)
{
	x_coord = pc.Get_x();
	y_coord = pc.Get_y();
}
bool PointCoord::operator == (PointCoord pc)
{
	return (x_coord == pc.x_coord && y_coord == pc.y_coord);
}