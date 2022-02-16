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
bool Construction::GetChosenStatus() const
{
	return isChosen;
}
void Construction::SetChosenStatus(bool chosen)
{
	isChosen = chosen;
}
wstring Construction::GetEntranceSymbol(Direction out) const
{
	return wstring(L"");
}
color Construction::GetBackgroundColor() const
{
	color background = cBLACK;
	if (GetChosenStatus())
	{
		background = GetDescriptor()->GetChosenBackgroundColor();
	}
	else
	{
		if (!GetRoadConnectionStatus())
		{
			background = GetDescriptor()->GetNotConnectedBackgroundColor();
		}
		else
		{
			background = GetDescriptor()->GetConnectedBackgroundColor();
		}
	}
	return background;
}
void Construction::RedrawNeibours(PointCoord centralPoint, const list<Road*>& allRoads, const list<Building*>& allBuildings,
	const Construction* preliminary_ptr, const Camera* camera_ptr)
{
	list<Road*>::const_iterator roadIter;
	PointCoord leftLocation(centralPoint.Get_x() - 1, centralPoint.Get_y());
	PointCoord rightLocation(centralPoint.Get_x() + 1, centralPoint.Get_y());
	PointCoord downLocation(centralPoint.Get_x(), centralPoint.Get_y() + 1);
	PointCoord topLocation(centralPoint.Get_x(), centralPoint.Get_y() - 1);
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if (((*roadIter)->GetUpperLeft() == leftLocation || (*roadIter)->GetUpperLeft() == rightLocation || (*roadIter)->GetUpperLeft() == downLocation ||
			(*roadIter)->GetUpperLeft() == topLocation) && (*roadIter) != preliminary_ptr)
		{
			int mask = (*roadIter)->GetEnvironmentMask(allRoads, allBuildings, preliminary_ptr);
			(*roadIter)->ConnectedToRoad(allRoads, preliminary_ptr);
			if (preliminary_ptr == nullptr)
			{
				(*roadIter)->IsGraph(allRoads, allBuildings, preliminary_ptr);
			}
			(*roadIter)->DrawObject(mask);
		}
	}
	list<Building*>::const_iterator buildingIter;
	for (buildingIter = allBuildings.begin(); buildingIter != allBuildings.end(); buildingIter++)
	{
		PointCoord potentialRoad = (*buildingIter)->GetPotentialConnectedRoadPoint();
		if (centralPoint == potentialRoad && (*buildingIter) != preliminary_ptr)
		{
			(*buildingIter)->ConnectedToRoad(allRoads, preliminary_ptr);
			(*buildingIter)->DrawObject(0, cameraLeftX, cameraTopY, cameraRightX, cameraBottomY);
		}
	}
}
int Construction::GetVisitorsCount() const
{
	return visitorsCount;
}
void Construction::SetVisitorsCount(int visitorsCount)
{
	this->visitorsCount = visitorsCount;
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
PointCoord Building::GetEntrancePoint() const
{
	return PointCoord(GetUpperLeft().Get_x() + GetEntranceWidthAdd(), GetUpperLeft().Get_y() + GetEntranceHeightAdd());
}
int Building::RotateConstruction()
{
	int heightAdd = GetHeightAddition();
	int widthAdd = GetWidthAddition();
	SetHeightAddition(widthAdd);
	SetWidthAddition(heightAdd);
	switch (GetExitDirection())
	{
	case Direction::Down:
	{
		SetExitDirection(Direction::Left);
		SetEntranceHeightAdd(GetHeightAddition() / 2);
		SetEntranceWidthAdd(0);
		return 1;
	}
	case Direction::Left:
	{
		SetExitDirection(Direction::Up);
		SetEntranceHeightAdd(0);
		SetEntranceWidthAdd(GetWidthAddition() / 2 + 1);
		return 1;
	}
	case Direction::Up:
	{
		SetExitDirection(Direction::Right);
		SetEntranceHeightAdd(GetHeightAddition() / 2 + 1);
		SetEntranceWidthAdd(GetWidthAddition());
		return 1;
	}
	case Direction::Right:
	{
		SetExitDirection(Direction::Down);
		SetEntranceHeightAdd(GetHeightAddition());
		SetEntranceWidthAdd(GetWidthAddition() / 2);
		return 1;
	}
	default:
		return 0;
	}
}
PointCoord Building::GetRedrawNeiboursPoint() const
{
	return GetEntrancePoint();
}
PointCoord Building::GetPotentialConnectedRoadPoint() const
{
	switch (exitDirection)
	{
	case Direction::Left: { return PointCoord(GetEntrancePoint().Get_x() - 1, GetEntrancePoint().Get_y()); }
	case Direction::Up: { return PointCoord(GetEntrancePoint().Get_x(), GetEntrancePoint().Get_y() - 1); }
	case Direction::Right: { return PointCoord(GetEntrancePoint().Get_x() + 1, GetEntrancePoint().Get_y()); }
	case Direction::Down: { return PointCoord(GetEntrancePoint().Get_x(), GetEntrancePoint().Get_y() + 1); }
	default: { return PointCoord(0, 0); }
	}
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
int Building::GetNeibourRoadMask(const list<Road*>& allRoads, const Construction* preliminary_ptr) const
{
	return -1;
}
int Building::GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	return 0;
}
void Building::ConnectedToRoad(const list<Road*>& allRoads, const Construction* preliminary_ptr)
{
	PointCoord potentialRoad = GetPotentialConnectedRoadPoint();
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if ((*roadIter)->GetUpperLeft() == potentialRoad)
		{
			SetRoadConnectionStatus(true);
			return;
		}
	}
	if (preliminary_ptr->GetUpperLeft() == potentialRoad && preliminary_ptr->GetExitDirection() == Direction::None)
	{
		SetRoadConnectionStatus(true);
		return;
	}
	SetRoadConnectionStatus(false);
}
void Building::IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
	{}
int Building::GetProfit() const
{
	return overallProfit;
}
void Building::SetProfit(int profit)
{
	overallProfit = profit;
}
void Building::RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr, const Camera* camera_ptr)
{
	PointCoord potentialRoad = GetPotentialConnectedRoadPoint();
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if ((*roadIter)->GetUpperLeft() == potentialRoad)
		{
			int mask = (*roadIter)->GetEnvironmentMask(allRoads, allBuildings, preliminary_ptr);
			(*roadIter)->ConnectedToRoad(allRoads, preliminary_ptr);
			if (preliminary_ptr == nullptr)
			{
				(*roadIter)->IsGraph(allRoads, allBuildings, preliminary_ptr);
			}
			(*roadIter)->DrawObject(mask);
		}
	}
}
void Building::CorrectBuildingCoordsForDraw(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int& leftX, int& topY, int& rightX, int& bottomY) const
{
	if (leftX <= cameraLeftX && rightX > cameraLeftX)
	{
		leftX = cameraLeftX + 1;
	}
	if (topY <= cameraTopY && bottomY > cameraTopY)
	{
		topY = cameraTopY + 1;
	}
	if (rightX >= cameraRightX && leftX < cameraRightX)
	{
		rightX = cameraRightX - 1;
	}
	if (bottomY >= cameraBottomY && topY < cameraBottomY)
	{
		bottomY = cameraBottomY - 1;
	}
}
void Building::DrawObject(int mask, int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	int leftX = GetUpperLeft().Get_x();
	int topY = GetUpperLeft().Get_y();
	int rightX = GetUpperLeft().Get_x() + GetWidthAddition();
	int bottomY = GetUpperLeft().Get_y() + GetHeightAddition();
	CorrectBuildingCoordsForDraw(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY);
	if (leftX < cameraRightX && topY < cameraBottomY && rightX > cameraLeftX && bottomY > cameraTopY)
	{
		GetPainter()->DrawConstruction(leftX, topY, rightX, bottomY, GetDescriptor()->GetConstructionSymbol(), GetDescriptor()->GetForegroundColor(),
			GetEntranceSymbol(exitDirection), entranceHeightAdd, entranceWidthAdd, GetBackgroundColor());
	}
}
void Building::EraseObject(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	int leftX = GetUpperLeft().Get_x();
	int topY = GetUpperLeft().Get_y();
	int rightX = GetUpperLeft().Get_x() + GetWidthAddition();
	int bottomY = GetUpperLeft().Get_y() + GetHeightAddition();
	CorrectBuildingCoordsForDraw(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY);
	if (leftX < cameraRightX && topY < cameraBottomY && rightX > cameraLeftX && bottomY > cameraTopY)
	{
		GetPainter()->EraseConstruction(leftX, topY, rightX, bottomY);
	}
}
///////////////Road Class: Construction derived///////////////
int Road::GetEntranceHeightAdd() const
{
	return 0;
}
int Road::GetEntranceWidthAdd() const
{
	return 0;
}
Direction Road::GetExitDirection() const
{
	return Direction::None;
}
int Road::RotateConstruction()
{
	return -1;
}
bool Road::GetGraphStatus() const
{
	return graphStatus;
}
void Road::SetGraphStatus(bool graphStatus)
{
	this->graphStatus = graphStatus;
}
int Road::GetProfit() const
{
	return -1;
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
		PointCoord potentialRoad = (*buildingIter)->GetPotentialConnectedRoadPoint();
		if (potentialRoad == GetUpperLeft())
		{
			return true;
		}
	}
	return false;
}
PointCoord Road::GetEntrancePoint() const
{
	return GetUpperLeft();
}
PointCoord Road::GetRedrawNeiboursPoint() const
{
	return GetUpperLeft();
}
int Road::GetNeibourRoadMask(const list<Road*>& allRoads, const Construction* preliminary_ptr) const
{
	PointCoord leftLocation(GetUpperLeft().Get_x() - 1, GetUpperLeft().Get_y());
	PointCoord rightLocation(GetUpperLeft().Get_x() + 1, GetUpperLeft().Get_y());
	PointCoord downLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() + 1);
	PointCoord upLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() - 1);
	int roadEnvironmentMask = 0;
	if (preliminary_ptr != nullptr)
	{
		PointCoord preliminaryUpperLeft(0, 0);
		if (preliminary_ptr->GetExitDirection() == Direction::None)
		{
			preliminaryUpperLeft = preliminary_ptr->GetUpperLeft();
		}
		if (preliminaryUpperLeft == leftLocation)
		{
			roadEnvironmentMask |= int(roadMask::LEFT);
		}
		if (preliminaryUpperLeft == rightLocation)
		{
			roadEnvironmentMask |= int(roadMask::RIGHT);
		}
		if (preliminaryUpperLeft == upLocation)
		{
			roadEnvironmentMask |= int(roadMask::TOP);
		}
		if (preliminaryUpperLeft == downLocation)
		{
			roadEnvironmentMask |= int(roadMask::BOTTOM);
		}
	}
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
int Road::GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	PointCoord leftLocation(GetUpperLeft().Get_x() - 1, GetUpperLeft().Get_y());
	PointCoord rightLocation(GetUpperLeft().Get_x() + 1, GetUpperLeft().Get_y());
	PointCoord downLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() + 1);
	PointCoord upLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() - 1);
	int roadEnvironmentMask = GetNeibourRoadMask(allRoads, preliminary_ptr);
	if (preliminary_ptr != nullptr && preliminary_ptr->GetExitDirection() != Direction::None)
	{
		PointCoord preliminaryConstructionEntrance = preliminary_ptr->GetEntrancePoint();
		if (preliminaryConstructionEntrance == leftLocation && preliminary_ptr->GetExitDirection() == Direction::Right)
		{
			roadEnvironmentMask |= int(roadMask::LEFT);
		}
		if (preliminaryConstructionEntrance == rightLocation && preliminary_ptr->GetExitDirection() == Direction::Left)
		{
			roadEnvironmentMask |= int(roadMask::RIGHT);
		}
		if (preliminaryConstructionEntrance == upLocation && preliminary_ptr->GetExitDirection() == Direction::Down)
		{
			roadEnvironmentMask |= int(roadMask::TOP);
		}
		if (preliminaryConstructionEntrance == downLocation && preliminary_ptr->GetExitDirection() == Direction::Up)
		{
			roadEnvironmentMask |= int(roadMask::BOTTOM);
		}
	}
	list<Building*>::const_iterator buildingIter;
	for (buildingIter = allBuildings.begin(); buildingIter != allBuildings.end(); buildingIter++)
	{
		PointCoord entrance = (*buildingIter)->GetEntrancePoint();
		if (entrance == leftLocation && (*buildingIter)->GetExitDirection() == Direction::Right)
		{
			roadEnvironmentMask |= int(roadMask::LEFT);
		}
		if (entrance == rightLocation && (*buildingIter)->GetExitDirection() == Direction::Left)
		{
			roadEnvironmentMask |= int(roadMask::RIGHT);
		}
		if (entrance == upLocation && (*buildingIter)->GetExitDirection() == Direction::Down)
		{
			roadEnvironmentMask |= int(roadMask::TOP);
		}
		if (entrance == downLocation && (*buildingIter)->GetExitDirection() == Direction::Up)
		{
			roadEnvironmentMask |= int(roadMask::BOTTOM);
		}
	}
	return roadEnvironmentMask;
}
void Road::IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	if (RoadIsAnEntrance(allBuildings))
	{
		SetGraphStatus(true);
		return;
	}
	int mask = GetNeibourRoadMask(allRoads, preliminary_ptr);
	DefineGraphStatus(mask);
}
void Road::ConnectedToRoad(const list<Road*>& allRoads, const Construction* preliminary_ptr)
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
			SetRoadConnectionStatus(true);
			return;
		}
	}
	if (preliminary_ptr->GetUpperLeft() == leftLocation || preliminary_ptr->GetUpperLeft() == rightLocation ||
		preliminary_ptr->GetUpperLeft() == downLocation || preliminary_ptr->GetUpperLeft() == upLocation)
	{
		SetRoadConnectionStatus(true);
		return;
	}
	SetRoadConnectionStatus(false);
}
void Road::RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr, const Camera* camera_ptr)
{
	PointCoord leftLocation(GetUpperLeft().Get_x() - 1, GetUpperLeft().Get_y());
	PointCoord rightLocation(GetUpperLeft().Get_x() + 1, GetUpperLeft().Get_y());
	PointCoord downLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() + 1);
	PointCoord upLocation(GetUpperLeft().Get_x(), GetUpperLeft().Get_y() - 1);
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if ((*roadIter)->GetUpperLeft() == leftLocation || (*roadIter)->GetUpperLeft() == rightLocation ||
			(*roadIter)->GetUpperLeft() == downLocation || (*roadIter)->GetUpperLeft() == upLocation)
		{
			int mask = (*roadIter)->GetEnvironmentMask(allRoads, allBuildings, preliminary_ptr);
			if (preliminary_ptr == nullptr)
			{
				(*roadIter)->IsGraph(allRoads, allBuildings, preliminary_ptr);
			}
			(*roadIter)->ConnectedToRoad(allRoads, preliminary_ptr);
			(*roadIter)->DrawObject(mask);
		}
	}
	list<Building*>::const_iterator buildingIter;
	for (buildingIter = allBuildings.begin(); buildingIter != allBuildings.end(); buildingIter++)
	{
		PointCoord potentialRoad = (*buildingIter)->GetPotentialConnectedRoadPoint();
		if (GetUpperLeft() == potentialRoad)
		{
			(*buildingIter)->ConnectedToRoad(allRoads, preliminary_ptr);
			(*buildingIter)->DrawObject(0, cameraLeftX, cameraTopY, cameraRightX, cameraBottomY);
		}
	}
}
void Road::DrawObject(int mask, int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	GetPainter()->DrawConstruction(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		GetDescriptor()->GetConstructionSymbol(mask), GetDescriptor()->GetForegroundColor(), GetBackgroundColor());
}
void Road::EraseObject(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	GetPainter()->ErasePixel(GetUpperLeft().Get_x(), GetUpperLeft().Get_y());
}
///////////////Visitor Class///////////////
void Visitor::VisitorMove(int x, int y)
{
	SetUpperLeft(PointCoord(x, y));
}
void Visitor::DrawObject(int mask, int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{

}
void Visitor::EraseObject(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{

}