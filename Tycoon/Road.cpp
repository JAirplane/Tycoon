#include "Road.h"
///////////////Road Class: Construction derived///////////////
void Road::GraphStatusAttach(GraphStatusObserverInterface* observer)
{
	if (observer == nullptr)
	{
		throw MyException("Road::GraphStatusAttach(GraphStatusObserverInterface* observer) received nullptr.");
	}
	graphStatusObservers.push_back(observer);
}
void Road::GraphStatusDetach(GraphStatusObserverInterface* observer)
{
	if (observer == nullptr)
	{
		throw MyException("Road::GraphStatusDetach(GraphStatusObserverInterface* observer) received nullptr.");
	}
	graphStatusObservers.remove(observer);
}
void Road::GraphStatusNotify(vector<pair<pair<int, int>, Direction> > edges) // true to adding node, false - to remove
{
	for (auto observer : graphStatusObservers)
	{
		observer->GraphStatusUpdate(edges);
	}
}
void Road::GraphStatusNotify(int roadIndex)
{
	for (auto observer : graphStatusObservers)
	{
		observer->GraphStatusUpdate(roadIndex);
	}
}
//
int Road::GetEntranceHeightAdd() const
{
	return 0;
}
int Road::GetEntranceWidthAdd() const
{
	return 0;
}
//
int Road::GetVisitorsInside() const
{
	return 0;
}
void Road::SetVisitorsInside(int visitorsValue)
{}
//
Direction Road::GetExitDirection() const
{
	return Direction::None;
}
void Road::SetExitDirection(Direction exit)
{}
int Road::RotateConstruction()
{
	return -1;
}
int Road::GetProfit() const
{
	return -1;
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
PointCoord Road::GetRedrawNeighboursPoint() const
{
	return GetUpperLeft();
}
int Road::GetMaskWithConstruction(const Construction* someConstruction_ptr) const
{
	int roadEnvironmentMask = 0;
	if (someConstruction_ptr != nullptr)
	{
		if (someConstruction_ptr->GetExitDirection() == Direction::None)
		{
			if (someConstruction_ptr->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Left))
			{
				roadEnvironmentMask |= int(roadMask::LEFT);
			}
			if (someConstruction_ptr->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Right))
			{
				roadEnvironmentMask |= int(roadMask::RIGHT);
			}
			if (someConstruction_ptr->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Up))
			{
				roadEnvironmentMask |= int(roadMask::TOP);
			}
			if (someConstruction_ptr->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Down))
			{
				roadEnvironmentMask |= int(roadMask::BOTTOM);
			}
		}
		else
		{
			PointCoord preliminaryConstructionEntrance = someConstruction_ptr->GetEntrancePoint();
			if (preliminaryConstructionEntrance == GetUpperLeft().GetSideCoord(Direction::Left) && someConstruction_ptr->GetExitDirection() == Direction::Right)
			{
				roadEnvironmentMask |= int(roadMask::LEFT);
			}
			if (preliminaryConstructionEntrance == GetUpperLeft().GetSideCoord(Direction::Right) && someConstruction_ptr->GetExitDirection() == Direction::Left)
			{
				roadEnvironmentMask |= int(roadMask::RIGHT);
			}
			if (preliminaryConstructionEntrance == GetUpperLeft().GetSideCoord(Direction::Up) && someConstruction_ptr->GetExitDirection() == Direction::Down)
			{
				roadEnvironmentMask |= int(roadMask::TOP);
			}
			if (preliminaryConstructionEntrance == GetUpperLeft().GetSideCoord(Direction::Down) && someConstruction_ptr->GetExitDirection() == Direction::Up)
			{
				roadEnvironmentMask |= int(roadMask::BOTTOM);
			}
		}
	}
	return roadEnvironmentMask;
}
int Road::GetMaskWithRealRoads(const list<Construction*>& allRoads) const
{
	int roadEnvironmentMask = 0;
	list<Construction*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		roadEnvironmentMask |= this->GetMaskWithConstruction((*roadIter));
	}
	return roadEnvironmentMask;
}
int Road::GetMaskWithRealBuildings(const list<Construction*>& allBuildings) const
{
	int roadEnvironmentMask = 0;
	for (auto everyBuilding : allBuildings)
	{
		roadEnvironmentMask |= this->GetMaskWithConstruction(everyBuilding);
	}
	return roadEnvironmentMask;
}
int Road::GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr)
{
	int roadEnvironmentMask = GetMaskWithRealRoads(allRoads);
	roadEnvironmentMask |= GetMaskWithConstruction(preliminary_ptr);
	roadEnvironmentMask |= GetMaskWithRealBuildings(allBuildings);
	return roadEnvironmentMask;
}
bool Road::Connected(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr)
{
	if (!GetNeighbourRoads(allRoads).empty())
	{
		SetRoadConnectionStatus(true);
		return true;
	}
	if (!GetNeighbourBuildings(allBuildings).empty())
	{
		SetRoadConnectionStatus(true);
		return true;
	}
	if (preliminary_ptr != nullptr && this != preliminary_ptr)
	{
		Direction exit = preliminary_ptr->GetExitDirection();
		if (exit == Direction::None)
		{
			if (preliminary_ptr->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Left) || preliminary_ptr->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Right) ||
				preliminary_ptr->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Down) || preliminary_ptr->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Up))
			{
				SetRoadConnectionStatus(true);
				return true;
			}
		}
		else
		{
			if (preliminary_ptr->GetPotentialConnectedRoadPoint() == GetUpperLeft())
			{
				SetRoadConnectionStatus(true);
				return true;
			}
		}
	}
	SetRoadConnectionStatus(false);
	return false;
}
vector<Construction*> Road::GetNeighbourRoads(const list<Construction*>& allRoads) const
{
	vector<Construction*> neibourRoads;
	for (auto everyRoad : allRoads)
	{
		if (everyRoad->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Left) || everyRoad->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Right) ||
			everyRoad->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Down) || everyRoad->GetUpperLeft() == GetUpperLeft().GetSideCoord(Direction::Up))
		{
			neibourRoads.push_back(everyRoad);
		}
	}
	return neibourRoads;
}
vector<Construction*> Road::GetNeighbourBuildings(const list<Construction*>& allBuildings) const
{
	vector<Construction*> neibourBuildings;
	for (auto everyBuilding : allBuildings)
	{
		if (GetUpperLeft() == everyBuilding->GetPotentialConnectedRoadPoint())
		{
			neibourBuildings.push_back(everyBuilding);
		}
	}
	return neibourBuildings;
}
void Road::DrawObject(int mask, int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	GetPainter()->DrawConstruction(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		GetDescriptor()->GetConstructionSymbol(mask), GetDescriptor()->GetForegroundColor(), GetBackgroundColor());
}
void Road::DrawObject(const wstring drawingSymbol) const
{
	this->Construction::DrawObject(drawingSymbol);
}
void Road::EraseObject(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	GetPainter()->ErasePixel(GetUpperLeft().Get_x(), GetUpperLeft().Get_y());
}
///////////////UnbreakableRoad Class///////////////
bool UnbreakableRoad::IsBreakable() const
{
	return false;
}
void UnbreakableRoad::SetRoadConnectionStatus(bool connected)
{
	Construction::SetRoadConnectionStatus(true); //this roads are always connected
}
int UnbreakableRoad::GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr)
{
	int roadEnvironmentMask = GetMaskWithRealRoads(allRoads);
	roadEnvironmentMask |= GetMaskWithConstruction(preliminary_ptr);
	roadEnvironmentMask |= GetMaskWithRealBuildings(allBuildings);
	roadEnvironmentMask |= int(roadMask::TOP);
	roadEnvironmentMask |= int(roadMask::BOTTOM);
	return roadEnvironmentMask;
}
///////////////Visible Outside Playingfield Road Class///////////////
bool VisibleOutsidePlayingfieldRoad::VisibleOutsidePlayingfield() const
{
	return true;
}
int VisibleOutsidePlayingfieldRoad::GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr)
{
	int roadEnvironmentMask = 0;
	roadEnvironmentMask |= int(roadMask::TOP);
	roadEnvironmentMask |= int(roadMask::BOTTOM);
	return roadEnvironmentMask;
}