#include "GlobalObject and childs.h"
///////////////Parent Class of All Objects///////////////
PointCoord GlobalObject::getUpperLeft() const
{
	return UpperLeft;
}
void GlobalObject::setUpperLeft(PointCoord pc)
{
	UpperLeft.set_coord(pc.get_x(), pc.get_y());
}
unsigned int GlobalObject::getHeight() const
{
	return Height;
}
void GlobalObject::setHeight(const int _h)
{
	Height = _h;
}
unsigned int GlobalObject::getWidth() const
{
	return Width;
}
void GlobalObject::setWidth(const int _w)
{
	Width = _w;
}
///////////////Construction Class: GlobalObject derived///////////////
int Construction::getConstructionCost() const
{
	return ConstructionCost;
}
void Construction::setConstructionCost(const int cost)
{
	ConstructionCost = cost;
}
///////////////Building Class: Construction derived///////////////
unsigned int Building::getDailyExpences() const
{
	return DailyExpences;
}
void Building::setDailyExpences(const int _de)
{
	DailyExpences = _de;
}
char Building::getSymbol() const
{
	return DrawSymbol;
}
void Building::setSymbol(const char _s)
{
	DrawSymbol = _s;
}
///////////////Ice Cream Shop Class: Building derived///////////////
GlobalObject* IceCreamShop::CreateObject(PointCoord _pc)
{
	GlobalObject* Obj_ptr = new IceCreamShop(_pc);
	return Obj_ptr;
}
///////////////Road Class: Construction derived///////////////
//GlobalObject* Road::CreateObject(PointCoord _pc)
//{
//	GlobalObject* Obj_ptr = new Road(_pc);
//	return Obj_ptr;
//}
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
///////////////Visitor Class///////////////
void Visitor::VisitorMove(int x, int y)
{
	setUpperLeft(PointCoord(x, y));
}
//GlobalObject* Visitor::CreateObject(PointCoord _pc)
//{
//	GlobalObject* fake_ptr = nullptr;
//	return fake_ptr;
//}