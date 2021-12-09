#include "GlobalObject+IngameObject.h"
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
/////////////Parent Class of Every Object in Game/////////////
ConstructionManager* IngameObject::getManager() const
{
	ConstructionManager* cm_ptr = nullptr;
	return cm_ptr;
}