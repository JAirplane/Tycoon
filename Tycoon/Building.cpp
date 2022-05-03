#include "Building.h"
///////////////Building Class: Construction derived///////////////
int Building::GetVisitorsInside() const
{
	return visitorsInside;
}
void Building::SetVisitorsInside(int visitorsValue)
{
	visitorsInside = visitorsValue;
}
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
		if (GetWidthAddition() < 2)
		{
			SetEntranceWidthAdd(GetWidthAddition() / 2 + 1);
		}
		else
		{
			SetEntranceWidthAdd(GetWidthAddition() / 2);
		}
		return 1;
	}
	case Direction::Up:
	{
		SetExitDirection(Direction::Right);
		if (GetHeightAddition() < 2)
		{
			SetEntranceHeightAdd(GetHeightAddition() / 2 + 1);
		}
		else
		{
			SetEntranceHeightAdd(GetHeightAddition() / 2);
		}
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
PointCoord Building::GetRedrawNeighboursPoint() const
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
	default: { throw MyException("Building::GetPotentialConnectedRoadPoint() building has bad exitDirection."); }
	}
}
wstring Building::GetEntranceSymbol() const
{
	switch (exitDirection)
	{
	case Direction::Up: {return wstring(L"\u2191"); }
	case Direction::Right: {return wstring(L"\u2192"); }
	case Direction::Down: {return wstring(L"\u2193"); }
	case Direction::Left: {return wstring(L"\u2190"); }
	default: {throw MyException("Building::GetEntranceSymbol() building has bad exitDirection."); }
	}
}
void Building::CopyEntrance(Construction* preliminary_ptr)
{
	if (preliminary_ptr == nullptr)
	{
		throw MyException("Building::CopyEntrance(Construction* preliminary_ptr) received nullptr argument.");
	}
	SetEntranceHeightAdd(preliminary_ptr->GetEntranceHeightAdd());
	SetEntranceWidthAdd(preliminary_ptr->GetEntranceWidthAdd());
	SetExitDirection(preliminary_ptr->GetExitDirection());
}
void Building::CopyRotationProperties(Construction* another_ptr)
{
	Construction::CopyRotationProperties(another_ptr);
	this->CopyEntrance(another_ptr);
}
int Building::GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) const
{
	return 0;
}
bool Building::Connected(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr)
{
	PointCoord potentialRoad = GetPotentialConnectedRoadPoint();
	list<Construction*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if ((*roadIter)->GetUpperLeft() == potentialRoad)
		{
			SetRoadConnectionStatus(true);
			return true;
		}
	}
	if (preliminary_ptr != nullptr)
	{
		if (preliminary_ptr->GetUpperLeft() == potentialRoad && preliminary_ptr->GetExitDirection() == Direction::None)
		{
			SetRoadConnectionStatus(true);
			return true;
		}
	}
	SetRoadConnectionStatus(false);
	return false;
}
int Building::GetProfit() const
{
	return overallProfit;
}
void Building::SetProfit(int profit)
{
	overallProfit = profit;
}
vector<Construction*> Building::GetNeighbourRoads(const list<Construction*>& allRoads) const
{
	vector<Construction*> neibourRoads;
	for (auto everyRoad : allRoads)
	{
		if (everyRoad->GetUpperLeft() == GetPotentialConnectedRoadPoint())
		{
			neibourRoads.push_back(everyRoad);
			break;
		}
	}
	return neibourRoads;
}
vector<Construction*> Building::GetNeighbourBuildings(const list<Construction*>& allBuildings) const
{
	return vector<Construction*>();
}
void Building::CorrectConstructionCoordsForDraw(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int& leftX, int& topY, int& rightX, int& bottomY) const
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
	CorrectConstructionCoordsForDraw(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY);
	if (leftX < cameraRightX && topY < cameraBottomY && rightX > cameraLeftX && bottomY > cameraTopY)
	{
		GetPainter()->DrawConstruction(leftX, topY, rightX, bottomY, GetDescriptor()->GetConstructionSymbol(), GetDescriptor()->GetForegroundColor(),
			GetEntranceSymbol(), entranceHeightAdd, entranceWidthAdd, GetBackgroundColor());
	}
}
void Building::EraseObject(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	int leftX = GetUpperLeft().Get_x();
	int topY = GetUpperLeft().Get_y();
	int rightX = GetUpperLeft().Get_x() + GetWidthAddition();
	int bottomY = GetUpperLeft().Get_y() + GetHeightAddition();
	CorrectConstructionCoordsForDraw(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY);
	if (leftX < cameraRightX && topY < cameraBottomY && rightX > cameraLeftX && bottomY > cameraTopY)
	{
		GetPainter()->EraseConstruction(leftX, topY, rightX, bottomY);
	}
}
void Building::Redraw_VisitorCheck(const Camera* cam_ptr, const list<Construction*>& allRoads, const list<Construction*>& allBuildings,
	const list<Visitor*>& allVisitors, const Construction* preliminary_ptr) const
{
	int mask = this->GetEnvironmentMask(allRoads, allBuildings, preliminary_ptr);
	this->DrawObject(mask, cam_ptr->GetUpperLeft().Get_x(), cam_ptr->GetUpperLeft().Get_y(), cam_ptr->GetUpperLeft().Get_x() + cam_ptr->GetWidthAddition(),
		cam_ptr->GetUpperLeft().Get_y() + cam_ptr->GetHeightAddition());
}