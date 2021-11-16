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
/////////////Menu Icon of Ice Cream Shop/////////////
string IceCreamShopIcon::getIceCreamDescription()
{
	return description;
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
const int Road::getRoadCost()
{
	return RoadCost;
}
PointCoord Road::getRoadLocation() const
{
	return GlobalObject::getUpperLeft();
}
void Road::setRoadLocation(PointCoord loc)
{
	GlobalObject::setUpperLeft(loc);
}
/////////////Menu Road Icon/////////////