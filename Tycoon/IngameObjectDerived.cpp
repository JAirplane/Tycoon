#include "IngameObjectDerived.h"
///////////////Construction Class: GlobalObject derived///////////////
ConstructionDescriptor* Construction::GetDescriptor() const //no setter here
{
	return describe_ptr;
}
int Construction::GetEntranceHeightAdd() const
{
	return -1;
}
int Construction::GetEntranceWidthAdd() const
{
	return -1;
}
Direction Construction::GetExitDirection() const
{
	return Direction::None;
}
wstring Construction::GetEntranceSymbol(Direction out) const
{
	return wstring(L"");
}
///////////////Building Class: Construction derived///////////////
int Building::GetEntranceHeightAdd() const
{
	return entranceHeightAdd;
}
void Building::SetEntranceHeightAdd(int heightAdd)
{
	entranceHeightAdd = heightAdd;
}
int Building::GetEntranceWidthAdd() const
{
	return entranceWidthAdd;
}
void Building::SetEntranceWidthAdd(int widthAdd)
{
	entranceWidthAdd = widthAdd;
}
Direction Building::GetExitDirection() const
{
	return exitDirection;
}
void Building::SetExitDirection(Direction exit)
{
	exitDirection = exit;
}
wstring Building::GetEntranceSymbol() const
{
	switch(exitDirection)
	{
	case Direction::Up: {return wstring(L"\u2191"); }
	case Direction::Right: {return wstring(L"\u2192"); }
	case Direction::Down: {return wstring(L"\u2193"); }
	case Direction::Left: {return wstring(L"\u2190"); }
	case Direction::None: {return; }
	}
}
bool Building::GetRoadConnectionStatus() const
{
	return connectedToRoad;
}
void Building::SetRoadConnectionStatus(bool connected)
{
	connectedToRoad = connected;
}
unsigned int Building::GetVisitorsCount() const
{
	return lastDayVisitors;
}
void Building::SetVisitorsCount(unsigned int visitorsCount)
{
	lastDayVisitors = visitorsCount;
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
wstring Road::SetRoadSymbol(int mask) const
{
	switch (mask)
	{
	case none: return wstring(L"\u2551");
	case leftside: return wstring(L"\u2550");
	case topside: return wstring(L"\u2551");
	case rightside: return wstring(L"\u2550");
	case bottomside: return wstring(L"\u2551");
	case vertical: return wstring(L"\u2551");
	case horizontal: return wstring(L"\u2550");
	case lefttop_angle: return wstring(L"\u2554");
	case righttop_angle: return wstring(L"\u2557");
	case leftbottom_angle: return wstring(L"\u255A");
	case rightbottom_angle: return wstring(L"\u255D");
	case right_T: return wstring(L"\u2560");
	case left_T: return wstring(L"\u2563");
	case top_T: return wstring(L"\u2569");
	case bottom_T: return wstring(L"\u2566");
	case cross: return wstring(L"\u256C");
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
	default: return;
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