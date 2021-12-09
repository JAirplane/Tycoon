#include "IngameObjectDerived.h"
///////////////Construction Class: GlobalObject derived///////////////
ConstructionManager* Construction::getManager() const //no setter here
{
	return Manager_ptr;
}
char Construction::SetRoadSymbol(int mask) const
{
	return '0';
}
void Construction::DefineGraphStatus(int mask)
{}
PointCoord Construction::getEntrance() const
{
	 return PointCoord();
}
Direction  Construction::getExitDirection() const
{
	return Direction::None;
}
void Construction::setGraphStatus(bool status)
	{}
void Construction::setRoadConnectionStatus(bool connected)
	{}
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
	icu::UnicodeString RoadSymbol;
	switch (mask)
	{
	case none: return RoadSymbol((UChar32)9473);
	case leftside: return RoadSymbol = (UChar32)9473;
	case topside: return RoadSymbol = (UChar32)9475;
	case rightside: return RoadSymbol = (UChar32)9473;
	case bottomside: return RoadSymbol = (UChar32)9475;
	case vertical: return RoadSymbol = (UChar32)9475;
	case horizontal: return RoadSymbol = (UChar32)9473;
	case lefttop_angle: return RoadSymbol = (UChar32)201;
	case righttop_angle: return RoadSymbol = (UChar32)187;
	case leftbottom_angle: return RoadSymbol = (UChar32)200;
	case rightbottom_angle: return RoadSymbol = (UChar32)188;
	case right_T: return RoadSymbol = (UChar32)'+';
	case left_T: return RoadSymbol = (UChar32)'+';
	case top_T: return RoadSymbol = (UChar32)'+';
	case bottom_T: return RoadSymbol = (UChar32)'+';
	case cross: return RoadSymbol = (UChar32)'+';
	default: return RoadSymbol = (UChar32)'-';
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