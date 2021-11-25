#include "Coord and constants.h"
///////////////PointCoord Struct///////////////
//UChar32 ucharrrrrrrrrrrr = 'a';
int PointCoord::get_x() const
{
	return x_coord;
}
int PointCoord::get_y() const
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
	x_coord = pc.get_x();
	y_coord = pc.get_y();
}
bool PointCoord::operator == (PointCoord pc)
{
	return (x_coord == pc.x_coord && y_coord == pc.y_coord);
}