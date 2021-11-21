#pragma once
using namespace std;
#include "GlobalObject and childs.h"
///////////////Parent Class of All Objects///////////////
PointCoord GlobalObject::getUpperLeft() const
{
	return UpperLeft;
}
PointCoord GlobalObject::getBottomRight() const
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
char GlobalObject::getSymbol() const
{
	return 0;
}
int GlobalObject::getConstructionCost() const
{
	return 0;
}
int GlobalObject::getDailyExpences() const 
{
	return 0;
}
string GlobalObject::getDescription() const
{
	string empty("error");
	return empty;
}
///////////////Ice Cream Shop Class///////////////
int IceCreamShop::ConstructionCost = 250;
int IceCreamShop::DailyExpences = 20;
char IceCreamShop::drawConstructionSymbol = '!';
char IceCreamShop::getSymbol() const
{
	return drawConstructionSymbol;
}
int IceCreamShop::getConstructionCost() const
{
	return ConstructionCost;
}
int IceCreamShop::getDailyExpences() const
{
	return DailyExpences;
}
/////////////Menu Icon of Ice Cream Shop/////////////
string IceCreamShopIcon::getDescription()
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
int Road::ConstructionCost = 50;
int Road::DailyExpences = 0;
int Road::getConstructionCost() const
{
	return ConstructionCost;
}
int Road::getDailyExpences() const
{
	return DailyExpences;
}
char Road::getSymbol() const
{
	char ch = '0';
	return ch;
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
string RoadIcon::getDescription()
{
	return description;
}