using namespace std;
#include "Coord and constants.h"
///////////////PointCoord Struct///////////////
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
bool PointCoord::operator == (PointCoord pc)
{
	return (x_coord == pc.x_coord && y_coord == pc.y_coord);
}