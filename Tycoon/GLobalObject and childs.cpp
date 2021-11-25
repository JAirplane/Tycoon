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
GlobalObject* IceCreamShop::CreateObject()
{
	GlobalObject* Obj_ptr = new IceCreamShop();
	return Obj_ptr;
}
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
PointCoord IceCreamShop::getRoadLocation() const
{
	return PointCoord(0, 0);
}
/////////////Menu Icon of Ice Cream Shop/////////////
string IceCreamShopIcon::getDescription() const
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
PointCoord Visitor::getRoadLocation() const
{
	return PointCoord(0, 0);
}
GlobalObject* Visitor::CreateObject()
{
	GlobalObject* fake_ptr = nullptr;
	return fake_ptr;
}
///////////////Road Class///////////////
int Road::ConstructionCost = 50;
int Road::DailyExpences = 0;
GlobalObject* Road::CreateObject()
{
	GlobalObject* Obj_ptr = new Road();
	return Obj_ptr;
}
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
string RoadIcon::getDescription() const
{
	return description;
}