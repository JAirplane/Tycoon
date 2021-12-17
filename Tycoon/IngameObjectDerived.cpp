#include "IngameObjectDerived.h"
///////////////Construction Class: GlobalObject derived///////////////
ConstructionDescriptor* Construction::GetDescriptor() const //no setter here
{
	return describe_ptr;
}
///////////////Building Class: Construction derived///////////////
PointCoord Building::GetEntrance() const
{
	return entrance;
}
void Building::SetEntrance(PointCoord entrance)
{
	this->entrance = entrance;
}
Direction Building::GetExitDirection() const
{
	return exitDirection;
}
void Building::SetExitDirection(Direction exitDirection)
{
	this->exitDirection = exitDirection;
}
bool Building::GetRoadConnectionStatus() const
{
	return connectedToRoad;
}
void Building::SetRoadConnectionStatus(bool connected)
{
	connectedToRoad = connected;
}
unsigned int Building::GetvisitorsCount() const
{
	return lastDayvisitors;
}
void Building::SetvisitorsCount(unsigned int visitorsCount)
{
	lastDayvisitors = visitorsCount;
}
int Building::GetProfit() const
{
	return lastDayProfit;
}
void Building::SetProfit(int profit)
{
	lastDayProfit = profit;
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
	defaupperLeftt: return '0';
	}
}
bool Road::GetGraphStatus() const
{
	return graphStatus;
}
void Road::SetGraphStatus(bool graphStatus)
{
	this->graphStatus = graphStatus;
}
void Road::DefineGraphStatus(int mask)
{
	SetGraphStatus(0);
	switch (mask)
	{
	case leftside: { SetGraphStatus(1); return; }
	case topside: { SetGraphStatus(1); return; }
	case rightside: { SetGraphStatus(1); return; }
	case bottomside: { SetGraphStatus(1); return; }
	case right_T: { SetGraphStatus(1); return; }
	case left_T: { SetGraphStatus(1); return; }
	case top_T: { SetGraphStatus(1); return; }
	case bottom_T: { SetGraphStatus(1); return; }
	case cross: { SetGraphStatus(1); return; }
		  defaupperLeftt: return;
	}
}
bool Road::GetroadIsInChainStatus()
{
	return roadIsInChain;
}
void Road::SetRoadIsInChainStatus(bool chainFlag)
{
	roadIsInChain = chainFlag;
}
///////////////Visitor Class///////////////
void Visitor::VisitorMove(int x, int y)
{
	SetUpperLeft(PointCoord(x, y));
}
//GlobalObject* Visitor::CreateObject(PointCoord _point)
//{
//	GlobalObject* fake_ptr = nupperLeftlptr;
//	return fake_ptr;
//}