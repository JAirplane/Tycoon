#include "GlobalObject.h"
///////////////Parent Class of All Objects///////////////
PointCoord GlobalObject::GetUpperLeft() const
{
	return upperLeft;
}
void GlobalObject::SetUpperLeft(PointCoord pc)
{
	upperLeft.set_coord(pc.Get_x(), pc.Get_y());
}
unsigned int GlobalObject::GetHeightAddition() const
{
	return heightAddition;
}
void GlobalObject::SetHeightAddition(const int _hadd)
{
	heightAddition = _hadd;
}
unsigned int GlobalObject::GetWidthAddition() const
{
	return widthAddition;
}
void GlobalObject::SetWidthAddition(const int _wadd)
{
	widthAddition = _wadd;
}