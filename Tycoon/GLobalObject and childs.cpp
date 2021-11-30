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
void GlobalObject::DefineGraphStatus(int mask)
{}
char GlobalObject::SetRoadSymbol(int mask) const
{
	char ch = '0';
	return ch;
}
///////////////Ice Cream Shop Class///////////////
int IceCreamShop::ConstructionCost = 250;
int IceCreamShop::DailyExpences = 20;
char IceCreamShop::drawConstructionSymbol = '!';
GlobalObject* IceCreamShop::CreateObject(PointCoord _pc)
{
	GlobalObject* Obj_ptr = new IceCreamShop(_pc);
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
/////////////Menu Icon of Ice Cream Shop/////////////
string IceCreamShopIcon::getDescription() const
{
	return description;
}
///////////////Visitor Class///////////////
void Visitor::VisitorMove(int x, int y)
{
	GlobalObject::setUpperLeft(PointCoord(x, y));
	GlobalObject::setBottomRight(PointCoord(x, y));
}
GlobalObject* Visitor::CreateObject(PointCoord _pc)
{
	GlobalObject* fake_ptr = nullptr;
	return fake_ptr;
}
///////////////Road Class///////////////
int Road::ConstructionCost = 50;
int Road::DailyExpences = 0;
GlobalObject* Road::CreateObject(PointCoord _pc)
{
	GlobalObject* Obj_ptr = new Road(_pc);
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
char Road::SetRoadSymbol(int mask) const
{
	char RoadSymbol = 'a';
	switch (mask)
	{
	case none: return RoadSymbol = '+';
	case leftside: return RoadSymbol = '+';
	case topside: return RoadSymbol = '+';
	case rightside: return RoadSymbol = '+';
	case bottomside: return RoadSymbol = '+';
	case vertical: return RoadSymbol = '+';
	case horizontal: return RoadSymbol = '+';
	case lefttop_angle: return RoadSymbol = '+';
	case righttop_angle: return RoadSymbol = '+';
	case leftbottom_angle: return RoadSymbol = '+';
	case rightbottom_angle: return RoadSymbol = '+';
	case right_T: return RoadSymbol = '+';
	case left_T: return RoadSymbol = '+';
	case top_T: return RoadSymbol = '+';
	case bottom_T: return RoadSymbol = '+';
	case cross: return RoadSymbol = '+';
	default: return RoadSymbol = '-';
	}
}
bool Road::getGraphStatus() const
{
	return GraphStatus;
}
void Road::setGraphStatus(bool status)
{
	GraphStatus = status;
}
void Road::DefineGraphStatus(int mask)
{
	setGraphStatus(0);
	switch (mask)
	{
	case leftside: { setGraphStatus(1); return; }
	case topside: { setGraphStatus(1); return; }
	case rightside: { setGraphStatus(1); return; }
	case bottomside: { setGraphStatus(1); return; }
	case right_T: { setGraphStatus(1); return; }
	case left_T: { setGraphStatus(1); return; }
	case top_T: { setGraphStatus(1); return; }
	case bottom_T: { setGraphStatus(1); return; }
	case cross: { setGraphStatus(1); return; }
	default: return;
	}
}
bool Road::getRoadIsInChainStatus()
{
	return RoadIsInChain;
}
void Road::setRoadIsInChainStatus(bool chainflag)
{
	RoadIsInChain = chainflag;
}
/////////////Menu Road Icon/////////////
string RoadIcon::getDescription() const
{
	return description;
}