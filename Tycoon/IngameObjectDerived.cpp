#include "IngameObjectDerived.h"
///////////////Construction Class: GlobalObject derived///////////////
ConstructionDescriptor* Construction::GetDescriptor() const //no setter here
{
	return describe_ptr;
}
bool Construction::GetRoadConnectionStatus() const
{
	return connectedToRoad;
}
void Construction::SetRoadConnectionStatus(bool connected)
{
	connectedToRoad = connected;
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
void Construction::DrawObject(int mask) const
{}
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
wstring Building::GetEntranceSymbol(Direction exit) const
{
	switch (exitDirection)
	{
	case Direction::Up: {return wstring(L"\u2191"); }
	case Direction::Right: {return wstring(L"\u2192"); }
	case Direction::Down: {return wstring(L"\u2193"); }
	case Direction::Left: {return wstring(L"\u2190"); }
	default: {return wstring(L""); }
	}
}
void Building::CopyEntrance(Construction* preliminary_ptr)
{
	SetEntranceHeightAdd(preliminary_ptr->GetEntranceHeightAdd());
	SetEntranceWidthAdd(preliminary_ptr->GetEntranceWidthAdd());
	SetExitDirection(preliminary_ptr->GetExitDirection());
}
int Building::GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings)
{
	return 0;
}
void Building::ConnectedToRoad(const list<Road*>& allRoads)
{
	PointCoord potentialRoad;
	switch (exitDirection)
	{
	case Direction::Up: {potentialRoad = PointCoord(GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition() - 1); }
	case Direction::Right: {potentialRoad = PointCoord(GetUpperLeft().Get_x() + GetWidthAddition() + 1, GetUpperLeft().Get_y() + GetHeightAddition()); }
	case Direction::Down: {potentialRoad = PointCoord(GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition() + 1); }
	case Direction::Left: {potentialRoad = PointCoord(GetUpperLeft().Get_x() + GetWidthAddition() - 1, GetUpperLeft().Get_y() + GetHeightAddition()); }
	default: {return; }
	}
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if ((*roadIter)->GetUpperLeft() == potentialRoad)
		{
			SetRoadConnectionStatus(true);
			return;
		}
	}
	SetRoadConnectionStatus(false);
}
void Building::IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings)
	{}
int Building::GetVisitorsCount() const
{
	return lastDayVisitors;
}
void Building::SetVisitorsCount(int visitorsCount)
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
color Building::GetBackgroundColor() const
{
	if (GetRoadConnectionStatus() == false)
	{
		return cBLACK;
	}
	else
	{
		return GetDescriptor()->GetBackgroundColor();
	}
}
void Building::RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings)
{
	PointCoord entrance = PointCoord(GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition());
	PointCoord potentialRoad;
	switch (GetExitDirection())
	{
	case Direction::Left: { potentialRoad = PointCoord(entrance.Get_x() - 1, entrance.Get_y()); break; }
	case Direction::Up: { potentialRoad = PointCoord(entrance.Get_x(), entrance.Get_y() - 1); break; }
	case Direction::Right: { potentialRoad = PointCoord(entrance.Get_x() + 1, entrance.Get_y()); break; }
	case Direction::Down: { potentialRoad = PointCoord(entrance.Get_x(), entrance.Get_y() + 1); break; }
	default: { return; }
	}
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if ((*roadIter)->GetUpperLeft() == potentialRoad)
		{
			int mask = (*roadIter)->GetEnvironmentMask(allRoads, allBuildings);
			(*roadIter)->ConnectedToRoad(allRoads);
			(*roadIter)->DrawObject(mask);
		}
	}
}
void Building::DrawObject(int mask) const
{
	color backgroundColor = GetBackgroundColor();
	GetPainter()->DrawConstruction(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		GetDescriptor()->GetConstructionSymbol(), GetDescriptor()->GetForegroundColor(), GetEntranceSymbol(exitDirection), entranceHeightAdd, entranceWidthAdd,
		backgroundColor);
}
void Building::DrawPartly(int leftX, int rightX, int topY, int bottomY) const
{
	color backgroundColor = GetBackgroundColor();
	GetPainter()->DrawConstruction(leftX, topY, rightX, bottomY, GetDescriptor()->GetConstructionSymbol(), GetDescriptor()->GetForegroundColor(),
		GetEntranceSymbol(exitDirection), entranceHeightAdd, entranceWidthAdd, backgroundColor);
}
///////////////Road Class: Construction derived///////////////
bool Road::GetGraphStatus() const
{
	return graphStatus;
}
void Road::SetGraphStatus(bool graphStatus)
{
	this->graphStatus = graphStatus;
}
void Road::DefineGraphStatus(int mask) // use NeibourRoadMask here!
{
	switch (mask)
	{
	case leftside: { SetGraphStatus(true); return; }
	case topside: { SetGraphStatus(true); return; }
	case rightside: { SetGraphStatus(true); return; }
	case bottomside: { SetGraphStatus(true); return; }
	case right_T: { SetGraphStatus(true); return; }
	case left_T: { SetGraphStatus(true); return; }
	case top_T: { SetGraphStatus(true); return; }
	case bottom_T: { SetGraphStatus(true); return; }
	case cross: { SetGraphStatus(true); return; }
	default: { SetGraphStatus(false); return; }
	}
}
bool Road::RoadIsAnEntrance(const list<Building*>& allBuildings)
{
	list<Building*>::const_iterator buildingIter;
	for (buildingIter = allBuildings.begin(); buildingIter != allBuildings.end(); buildingIter++)
	{
		PointCoord entrance((*buildingIter)->GetUpperLeft().Get_x() + (*buildingIter)->GetEntranceWidthAdd(),
			(*buildingIter)->GetUpperLeft().Get_y() + (*buildingIter)->GetEntranceHeightAdd());
		PointCoord potentialRoad;
		switch ((*buildingIter)->GetExitDirection())
		{
		case Direction::Down: { potentialRoad = PointCoord(entrance.Get_x(), entrance.Get_y() + 1); }
		case Direction::Left: { PointCoord potentialRoad(entrance.Get_x() - 1, entrance.Get_y()); }
		case Direction::Up: { PointCoord potentialRoad(entrance.Get_x(), entrance.Get_y() - 1); }
		case Direction::Right: { PointCoord potentialRoad(entrance.Get_x() + 1, entrance.Get_y()); }
		default: { return false; }
		}
		if (potentialRoad == GetUpperLeft())
		{
			return true;
		}
	}
	return false;
}
int Road::GetNeibourRoadMask(const list<Road*>& allRoads)
{
	PointCoord leftLocation(GetUpperLeft().Get_x() - 1, GetUpperLeft().Get_y());
	PointCoord rightLocation(GetUpperLeft().Get_x() + 1, GetUpperLeft().Get_y());
	PointCoord downLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() + 1);
	PointCoord upLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() - 1);
	int roadEnvironmentMask = 0;
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if ((*roadIter)->GetUpperLeft() == leftLocation)
		{
			roadEnvironmentMask |= int(roadMask::LEFT);
		}
		if ((*roadIter)->GetUpperLeft() == rightLocation)
		{
			roadEnvironmentMask |= int(roadMask::RIGHT);
		}
		if ((*roadIter)->GetUpperLeft() == upLocation)
		{
			roadEnvironmentMask |= int(roadMask::TOP);
		}
		if ((*roadIter)->GetUpperLeft() == downLocation)
		{
			roadEnvironmentMask |= int(roadMask::BOTTOM);
		}
	}
	return roadEnvironmentMask;
}
int Road::GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings)
{
	PointCoord leftLocation(GetUpperLeft().Get_x() - 1, GetUpperLeft().Get_y());
	PointCoord rightLocation(GetUpperLeft().Get_x() + 1, GetUpperLeft().Get_y());
	PointCoord downLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() + 1);
	PointCoord upLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() - 1);
	int roadEnvironmentMask = GetNeibourRoadMask(allRoads);
	list<Building*>::const_iterator buildingIter;
	for (buildingIter = allBuildings.begin(); buildingIter != allBuildings.end(); buildingIter++)
	{
		PointCoord entrance = PointCoord((*buildingIter)->GetUpperLeft().Get_x() + (*buildingIter)->GetEntranceWidthAdd(),
			(*buildingIter)->GetUpperLeft().Get_y() + (*buildingIter)->GetEntranceHeightAdd());
		if (entrance == leftLocation && entrance == rightLocation && entrance == upLocation && entrance == downLocation)
		{
			if ((*buildingIter)->GetExitDirection() == Direction::Right)
			{
				roadEnvironmentMask |= int(roadMask::LEFT);
			}
			if ((*buildingIter)->GetExitDirection() == Direction::Left)
			{
				roadEnvironmentMask |= int(roadMask::RIGHT);
			}
			if ((*buildingIter)->GetExitDirection() == Direction::Down)
			{
				roadEnvironmentMask |= int(roadMask::TOP);
			}
			if ((*buildingIter)->GetExitDirection() == Direction::Up)
			{
				roadEnvironmentMask |= int(roadMask::BOTTOM);
			}
		}
	}
	return roadEnvironmentMask;
}
void Road::IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings)
{
	if (RoadIsAnEntrance(allBuildings))
	{
		SetGraphStatus(true);
		return;
	}
	int mask = GetNeibourRoadMask(allRoads);
	DefineGraphStatus(mask);
}
void Road::ConnectedToRoad(const list<Road*>& allRoads)
{
	PointCoord leftLocation(GetUpperLeft().Get_x() - 1, GetUpperLeft().Get_y());
	PointCoord rightLocation(GetUpperLeft().Get_x() + 1, GetUpperLeft().Get_y());
	PointCoord downLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() + 1);
	PointCoord upLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() - 1);
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if (GetUpperLeft() == leftLocation || GetUpperLeft() == rightLocation || GetUpperLeft() == downLocation || GetUpperLeft() == upLocation)
		{
			SetRoadConnectionStatus(true);
			return;
		}
	}
	SetRoadConnectionStatus(false);
}
void Road::RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings)
{
	PointCoord leftLocation(GetUpperLeft().Get_x() - 1, GetUpperLeft().Get_y());
	PointCoord rightLocation(GetUpperLeft().Get_x() + 1, GetUpperLeft().Get_y());
	PointCoord downLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() + 1);
	PointCoord upLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() - 1);
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if ((*roadIter)->GetUpperLeft() == leftLocation || (*roadIter)->GetUpperLeft() == rightLocation || 
			(*roadIter)->GetUpperLeft() == downLocation || (*roadIter)->GetUpperLeft() == upLocation)
		{
			int mask = (*roadIter)->GetEnvironmentMask(allRoads, allBuildings);
			(*roadIter)->IsGraph(allRoads, allBuildings);
			(*roadIter)->ConnectedToRoad(allRoads);
			(*roadIter)->DrawObject(mask);
		}
	}
	list<Building*>::const_iterator buildingIter;
	for (buildingIter = allBuildings.begin(); buildingIter != allBuildings.end(); buildingIter++)
	{
		PointCoord entrance = PointCoord((*buildingIter)->GetUpperLeft().Get_x() + (*buildingIter)->GetWidthAddition(),
			(*buildingIter)->GetUpperLeft().Get_y() + (*buildingIter)->GetHeightAddition());
		PointCoord potentialRoad;
		switch ((*buildingIter)->GetExitDirection())
		{
		case Direction::Left: { potentialRoad = PointCoord(entrance.Get_x() - 1, entrance.Get_y()); break; }
		case Direction::Up: { potentialRoad = PointCoord(entrance.Get_x(), entrance.Get_y() - 1); break; }
		case Direction::Right: { potentialRoad = PointCoord(entrance.Get_x() + 1, entrance.Get_y()); break; }
		case Direction::Down: { potentialRoad = PointCoord(entrance.Get_x(), entrance.Get_y() + 1); break; }
		default: { return; }
		}
		if (GetUpperLeft() == potentialRoad)
		{
			(*buildingIter)->SetRoadConnectionStatus(true);
			(*buildingIter)->DrawObject();
		}
	}
}
void Road::DrawObject(int mask) const
{
	GetPainter()->DrawConstruction(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		GetDescriptor()->GetConstructionSymbol(mask), GetDescriptor()->GetForegroundColor(), GetDescriptor()->GetBackgroundColor());
}
///////////////Visitor Class///////////////
void Visitor::VisitorMove(int x, int y)
{
	SetUpperLeft(PointCoord(x, y));
}
void Visitor::DrawObject(int mask) const
{

}