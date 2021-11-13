#pragma once
using namespace std;
#include "GlobalObject and childs.h"
///////////////Parent Class of All Objects///////////////
PointCoord GlobalObject::getUpperLeft() const
{
	return UpperLeft;
}
PointCoord GlobalObject::getBottomRight()
{
	return BottomRight;
}
void GlobalObject::setUpperLeft(PointCoord pc)
{
	UpperLeft.set_coord(pc.get_x(), pc.get_y());
}
void GlobalObject::setBottomRight(PointCoord pc)
{
	BottomRight.set_coord(pc.get_x(), pc.get_y());
}
const char GlobalObject::getSymbol()
{
	return 0;
}
///////////////Ice Cream Shop Class///////////////
const int IceCreamShop::ConstructionCost = 250;
const int IceCreamShop::DailyExpences = 20;
const char IceCreamShop::drawConstructionSymbol = '!';
const char IceCreamShop::getSymbol()
{
	return drawConstructionSymbol;
}
const int IceCreamShop::getIceCreamShopCreateCost()
{
	return ConstructionCost;
}
const int IceCreamShop::getIceCreamShopDailyExpences()
{
	return DailyExpences;
}
///////////////Visitor Class///////////////
PointCoord Visitor::getLocation()
{
	return GlobalObject::getUpperLeft();
}
void Visitor::VisitorMove(int x, int y)
{
	GlobalObject::setUpperLeft(PointCoord(x, y));
	GlobalObject::setBottomRight(PointCoord(x, y));
}
///////////////Road Class///////////////
const int Road::RoadCost = 50;
const char Road::drawRoadSymbol = 'r';
const int Road::getRoadCost()
{
	return RoadCost;
}
const char Road::getRoadSymbol() const
{
	return drawRoadSymbol;
}
PointCoord Road::getRoadLocation() const
{
	return GlobalObject::getUpperLeft();
}
void Road::setRoadLocation(PointCoord loc)
{
	GlobalObject::setUpperLeft(loc);
}
int& Road::get_set_RoadEnvironmentMask()
{
	return RoadEnvironmentMask;
}