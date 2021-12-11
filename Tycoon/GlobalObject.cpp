#include "GlobalObject.h"
///////////////Parent Class of All Objects///////////////
PointCoord GlobalObject::getUpperLeft() const
{
	return UpperLeft;
}
void GlobalObject::setUpperLeft(PointCoord pc)
{
	UpperLeft.set_coord(pc.get_x(), pc.get_y());
}
unsigned int GlobalObject::getHeightAddition() const
{
	return HeightAddition;
}
void GlobalObject::setHeightAddition(const int _hadd)
{
	HeightAddition = _hadd;
}
unsigned int GlobalObject::getWidthAddition() const
{
	return WidthAddition;
}
void GlobalObject::setWidthAddition(const int _wadd)
{
	WidthAddition = _wadd;
}