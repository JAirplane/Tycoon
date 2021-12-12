#include "IngameObjectDerived.h"
///////////////Construction Class: GlobalObject derived///////////////
ConstructionDescriptor* Construction::getDescriptor() const //no setter here
{
	return Describe_ptr;
}
///////////////Building Class: Construction derived///////////////
PointCoord Building::getEntrance() const
{
	return Entrance;
}
void Building::setEntrance(PointCoord _entrance)
{
	Entrance = _entrance;
}
Direction Building::getExitDirection() const
{
	return ExitDir;
}
void Building::setExitDirection(Direction _dir)
{
	ExitDir = _dir;
}
bool Building::getRoadConnectionStatus() const
{
	return ConnectedToRoad;
}
void Building::setRoadConnectionStatus(bool connected)
{
	ConnectedToRoad = connected;
}
unsigned int Building::getVisitorsCount() const
{
	return LastDayVisitors;
}
void Building::setVisitorsCount(unsigned int _visitorscount)
{
	LastDayVisitors = _visitorscount;
}
int Building::getProfit() const
{
	return LastDayProfit;
}
void Building::setProfit(int _profit)
{
	LastDayProfit = _profit;
}
///////////////Road Class: Construction derived///////////////
char Road::SetRoadSymbol(int mask) const
{
	switch (mask)
	{
	case none: return (char)186;
	case leftside: return (char)205;
	case topside: return (char)186;
	case rightside: return (char)205;
	case bottomside: return (char)186;
	case vertical: return (char)186;
	case horizontal: return (char)205;
	case lefttop_angle: return (char)188;
	case righttop_angle: return (char)200;
	case leftbottom_angle: return (char)187;
	case rightbottom_angle: return (char)201;
	case right_T: return (char)204;
	case left_T: return (char)185;
	case top_T: return (char)202;
	case bottom_T: return (char)203;
	case cross: return (char)206;
	default: return '0';
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