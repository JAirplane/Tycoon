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
wstring Construction::GetEntranceSymbol() const
{
	return wstring(L"");
}
color Construction::GetBackgroundColor() const
{
	color background = cBLACK;
	if (GetNodeStatus())
	{
		return cRED;
	}
	if (GetChosenStatus()) // GetChosenStatus() has an exception
	{
		background = GetDescriptor()->GetChosenBackgroundColor();
	}
	else
	{
		if (!GetRoadConnectionStatus())
		{
			background = GetDescriptor()->GetBackgroundColor();
		}
		else
		{
			background = GetDescriptor()->GetConnectedBackgroundColor();
		}
	}
	return background;
}
PointCoord Construction::GetPotentialConnectedRoadPoint() const
{
	return PointCoord(0, 0);
}
bool Construction::GetNodeStatus() const
{
	return false;
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
			(*roadIter)->Connected(allRoads, allBuildings, preliminary_ptr);
			if (preliminary_ptr == nullptr)
			{
				(*roadIter)->IsNode(allRoads, allBuildings, preliminary_ptr);
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
			(*buildingIter)->Connected(allRoads, allBuildings, preliminary_ptr);
			(*buildingIter)->DrawObject(0, cameraLeftX, cameraTopY, cameraRightX, cameraBottomY);
		}
	}
}
void Construction::DrawObject(const wstring drawingSymbol) const
{
	GetPainter()->DrawConstruction(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		drawingSymbol, GetDescriptor()->GetForegroundColor(), GetBackgroundColor());
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
int Building::GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	return 0;
}
bool Building::Connected(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	PointCoord potentialRoad = GetPotentialConnectedRoadPoint();
	list<Road*>::const_iterator roadIter;
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
bool Building::IsNode(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
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
vector<Construction*> Building::GetNeibourRoads(const list<Road*>& allRoads) const
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
vector<Construction*> Building::GetNeibourBuildings(const list<Building*>& allBuildings) const
{
	return vector<Construction*>();
}
Construction* Building::PreliminaryNeibour(Construction* preliminary_ptr) const
{
	if (preliminary_ptr != nullptr)
	{
		if (dynamic_cast<Road*>(preliminary_ptr) && this->GetPotentialConnectedRoadPoint() == preliminary_ptr->GetUpperLeft())
		{
			return preliminary_ptr;
		}
	}
	return nullptr;
	
}
void Building::RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, Construction* preliminary_ptr, const Camera* camera_ptr)
{
	PointCoord potentialRoad = GetPotentialConnectedRoadPoint();
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if ((*roadIter)->GetUpperLeft() == potentialRoad)
		{
			int mask = (*roadIter)->GetEnvironmentMask(allRoads, allBuildings, preliminary_ptr);
			(*roadIter)->Connected(allRoads, allBuildings, preliminary_ptr);
			if (preliminary_ptr == nullptr)
			{
				(*roadIter)->IsNode(allRoads, allBuildings, preliminary_ptr);
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
			GetEntranceSymbol(), entranceHeightAdd, entranceWidthAdd, GetBackgroundColor());
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
void Road::GraphStatusNotify() //notifies if graphStatus changed, so it can be as true as false
{
	for (auto observer : graphStatusObservers)
	{
		observer->GraphStatusUpdate(this);
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
Direction Road::GetExitDirection() const
{
	return Direction::None;
}
int Road::RotateConstruction()
{
	return -1;
}
bool Road::GetNodeStatus() const
{
	return graphStatus;
}
void Road::SetNodeStatus(bool graphStatus)
{
	this->graphStatus = graphStatus;
}
int Road::GetProfit() const
{
	return -1;
}
void Road::DefineNodeStatus(int mask) // use NeibourRoadMask here!
{
	switch (mask)
	{
	case leftside: { SetNodeStatus(true); return; }
	case topside: { SetNodeStatus(true); return; }
	case rightside: { SetNodeStatus(true); return; }
	case bottomside: { SetNodeStatus(true); return; }
	case right_T: { SetNodeStatus(true); return; }
	case left_T: { SetNodeStatus(true); return; }
	case top_T: { SetNodeStatus(true); return; }
	case bottom_T: { SetNodeStatus(true); return; }
	case cross: { SetNodeStatus(true); return; }
	default: { SetNodeStatus(false); return; }
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
int Road::GetMaskWithRealRoads(const list<Road*>& allRoads) const
{
	int roadEnvironmentMask = 0;
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		roadEnvironmentMask |= this->GetMaskWithConstruction((*roadIter));
	}
	return roadEnvironmentMask;
}
int Road::GetMaskWithRealBuildings(const list<Building*>& allBuildings) const
{
	int roadEnvironmentMask = 0;
	for (auto everyBuilding : allBuildings)
	{
		this->GetMaskWithConstruction(everyBuilding);
	}
	return roadEnvironmentMask;
}
int Road::GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	int roadEnvironmentMask = GetMaskWithRealRoads(allRoads);
	roadEnvironmentMask |= GetMaskWithConstruction(preliminary_ptr);
	roadEnvironmentMask |= GetMaskWithRealBuildings(allBuildings);
	return roadEnvironmentMask;
}
bool Road::IsNode(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	if (this != preliminary_ptr)
	{
		bool previousNodeStatus = GetNodeStatus();
		if (RoadIsAnEntrance(allBuildings))
		{
			SetNodeStatus(true);
		}
		else
		{
			int mask = GetMaskWithRealRoads(allRoads);
			DefineNodeStatus(mask);
		}
		bool newNodeStatus = GetNodeStatus();
		if (previousNodeStatus == newNodeStatus)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false; //preliminary construction never become a node
	}
}
bool Road::Connected(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	if (!GetNeibourRoads(allRoads).empty())
	{
		SetRoadConnectionStatus(true);
		return true;
	}
	if (!GetNeibourBuildings(allBuildings).empty())
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
vector<Construction*> Road::GetNeibourRoads(const list<Road*>& allRoads) const
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
vector<Construction*> Road::GetNeibourBuildings(const list<Building*>& allBuildings) const
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
Construction* Road::PreliminaryNeibour(Construction* preliminary_ptr) const
{
	if (preliminary_ptr == nullptr)
	{
		return nullptr;
	}
	else
	{
		int maskWithPreliminary = GetMaskWithConstruction(preliminary_ptr);
		if (maskWithPreliminary != 0)
		{
			return preliminary_ptr;
		}
		else
		{
			return nullptr;
		}
	}
}
void Road::RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, Construction* preliminary_ptr, const Camera* camera_ptr)
{
	vector<Construction*> neibours = this->GetNeibourRoads(allRoads);
	vector<Construction*> neibourBuildings = this->GetNeibourBuildings(allBuildings);
	neibours.insert(neibours.end(), neibourBuildings.begin(), neibourBuildings.end());
	if (preliminary_ptr != nullptr)
	{
		neibours.push_back(this->PreliminaryNeibour(preliminary_ptr));
	}
	for (auto everyNeibour : neibours)
	{
		if (everyNeibour != nullptr)
		{
			if (everyNeibour != preliminary_ptr)
			{
				bool nodeStatusChanged = everyNeibour->IsNode(allRoads, allBuildings, preliminary_ptr);
			}
			int mask = everyNeibour->GetEnvironmentMask(allRoads, allBuildings, preliminary_ptr);
			everyNeibour->Connected(allRoads, allBuildings, preliminary_ptr);
			everyNeibour->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
				camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
		}
	}
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
bool Road::IsBreakable() const
{
	return true;
}
///////////////UnbreakableRoad Class///////////////
bool UnbreakableRoad::IsBreakable() const
{
	return false;
}
bool UnbreakableRoad::IsNode(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	Road::SetNodeStatus(true);
	return false;
}
void UnbreakableRoad::SetRoadConnectionStatus(bool connected)
{
	Construction::SetRoadConnectionStatus(true); //this roads are always connected
}
int UnbreakableRoad::GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	int roadEnvironmentMask = GetMaskWithRealRoads(allRoads);
	roadEnvironmentMask |= GetMaskWithConstruction(preliminary_ptr);
	roadEnvironmentMask |= GetMaskWithRealBuildings(allBuildings);
	roadEnvironmentMask |= int(roadMask::TOP);
	roadEnvironmentMask |= int(roadMask::BOTTOM);
	return roadEnvironmentMask;
}
///////////////Visitor Class///////////////
VisitorDescriptor* Visitor::GetDescriptor() const
{
	return description_ptr;
}
const Road* Visitor::GetDestination() const
{
	return destination_ptr;
}
void Visitor::SetDestination(Road* pathClue)
{
	destination_ptr = pathClue;
}
const Road* Visitor::GetLastVisitedGraph() const
{
	return lastVisitedGraph_ptr;
}
void Visitor::SetLastVisitedGraph(Road* lastNode)
{
	lastVisitedGraph_ptr = lastNode;
}
int Visitor::GetFoorCapacity() const
{
	return foodCapacity;
}
void Visitor::SetFoodCapacity(int foodCapacity)
{
	this->foodCapacity = foodCapacity;
}
int Visitor::GetNeedToPee() const
{
	return needToPee;
}
void Visitor::SetNeedToPee(int newNeed)
{
	needToPee = newNeed;
}
MovementStatus Visitor::GetMovementPurpose() const
{
	return CurrentPurpose;
}
void Visitor::SetMovementPurpose(MovementStatus newPurpose)
{
	CurrentPurpose = newPurpose;
}
void Visitor::VisitorMove(PointCoord destination)
{
	SetUpperLeft(destination);
}
void Visitor::DrawObject(int mask, int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	GetPainter()->DrawVisitor(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), description_ptr->GetForegroundColor(), description_ptr->GetBackgroundColor(), description_ptr->GetVisitorSymbol());
}
void Visitor::EraseObject(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	GetPainter()->ErasePixel(GetUpperLeft().Get_x(), GetUpperLeft().Get_y());
}
void Visitor::MakeAStep(Construction* destinationRoadTile)
{
	this->SetUpperLeft(destinationRoadTile->GetUpperLeft());
}