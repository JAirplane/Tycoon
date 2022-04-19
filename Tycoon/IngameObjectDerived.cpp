#include "IngameObjectDerived.h"
#include <functional>
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
void Construction::RedrawNeighbours(PointCoord centralPoint, const list<Road*>& allRoads, const list<Building*>& allBuildings,
	Construction* preliminary_ptr, const Camera* camera_ptr)
{
	vector<Construction*> neighbours;
	for (auto everyRoad : allRoads)
	{
		if (everyRoad->GetUpperLeft() == centralPoint.GetSideCoord(Direction::Left) || everyRoad->GetUpperLeft() == centralPoint.GetSideCoord(Direction::Up) ||
			everyRoad->GetUpperLeft() == centralPoint.GetSideCoord(Direction::Right) || everyRoad->GetUpperLeft() == centralPoint.GetSideCoord(Direction::Down))
		{
			neighbours.push_back(everyRoad);
		}
	}
	for (auto everyBuilding : allBuildings)
	{
		if (centralPoint == everyBuilding->GetPotentialConnectedRoadPoint())
		{
			neighbours.push_back(everyBuilding);
		}
	}
	for (auto everyNeighbour : neighbours)
	{
		int mask = everyNeighbour->GetEnvironmentMask(allRoads, allBuildings, preliminary_ptr);
		everyNeighbour->Connected(allRoads, allBuildings, preliminary_ptr);
		everyNeighbour->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
			camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
	}
}
void Construction::CopyRotationProperties(Construction* another_ptr)
{
	this->SetWidthAddition(another_ptr->GetWidthAddition());
	this->SetHeightAddition(another_ptr->GetHeightAddition());
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
bool Construction::IsBreakable() const
{
	return true;
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
int Building::GetProfit() const
{
	return overallProfit;
}
void Building::SetProfit(int profit)
{
	overallProfit = profit;
}
vector<Construction*> Building::GetNeighbourRoads(const list<Road*>& allRoads) const
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
vector<Construction*> Building::GetNeighbourBuildings(const list<Building*>& allBuildings) const
{
	return vector<Construction*>();
}
Construction* Building::GetPreliminaryNeighbour(Construction* preliminary_ptr) const
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
void Building::RedrawNeighbours(const list<Road*>& allRoads, const list<Building*>& allBuildings, Construction* preliminary_ptr, const Camera* camera_ptr)
{
	PointCoord potentialRoad = GetPotentialConnectedRoadPoint();
	list<Road*>::const_iterator roadIter;
	for (roadIter = allRoads.begin(); roadIter != allRoads.end(); roadIter++)
	{
		if ((*roadIter)->GetUpperLeft() == potentialRoad)
		{
			int mask = (*roadIter)->GetEnvironmentMask(allRoads, allBuildings, preliminary_ptr);
			(*roadIter)->Connected(allRoads, allBuildings, preliminary_ptr);
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
vector<Building*> Building::ChooseFromBuildings(_Mem_fn<int (ConstructionDescriptor::*)() const> buildingProperty, const list<Building*>& allBuildings)
{
	vector<Building*> buildingsWithProperty;
	for (auto everyBuilding : allBuildings)
	{
		if (buildingProperty(everyBuilding->GetDescriptor()) != 0)
		{
			buildingsWithProperty.push_back(everyBuilding);
		}
	}
	return buildingsWithProperty;
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
Direction Road::GetExitDirection() const
{
	return Direction::None;
}
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
		roadEnvironmentMask |= this->GetMaskWithConstruction(everyBuilding);
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
bool Road::Connected(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
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
vector<Construction*> Road::GetNeighbourRoads(const list<Road*>& allRoads) const
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
vector<Construction*> Road::GetNeighbourBuildings(const list<Building*>& allBuildings) const
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
Construction* Road::GetPreliminaryNeighbour(Construction* preliminary_ptr) const
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
void Road::RedrawNeighbours(const list<Road*>& allRoads, const list<Building*>& allBuildings, Construction* preliminary_ptr, const Camera* camera_ptr)
{
	vector<Construction*> neighbours = this->GetNeighbourRoads(allRoads);
	vector<Construction*> neighbourBuildings = this->GetNeighbourBuildings(allBuildings);
	neighbours.insert(neighbours.end(), neighbourBuildings.begin(), neighbourBuildings.end());
	for (auto everyNeighbour : neighbours)
	{
		if (everyNeighbour != nullptr)
		{
			int mask = everyNeighbour->GetEnvironmentMask(allRoads, allBuildings, preliminary_ptr);
			everyNeighbour->Connected(allRoads, allBuildings, preliminary_ptr);
			everyNeighbour->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
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
///////////////UnbreakableRoad Class///////////////
bool UnbreakableRoad::IsBreakable() const
{
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
///////////////Visible Outside Playingfield Road Class///////////////
bool VisibleOutsidePlayingfieldRoad::VisibleOutsidePlayingfield() const
{
	return true;
}
int VisibleOutsidePlayingfieldRoad::GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr)
{
	int roadEnvironmentMask = 0;
	roadEnvironmentMask |= int(roadMask::TOP);
	roadEnvironmentMask |= int(roadMask::BOTTOM);
	return roadEnvironmentMask;
}
///////////////Visitor Class///////////////
VisitorDescriptor* Visitor::GetDescriptor() const
{
	return description_ptr;
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
int Visitor::GetMoneyAmount() const
{
	return moneyAmount;
}
void Visitor::SetMoneyAmount(int money)
{
	moneyAmount = money;
}
void Visitor::VisitorMove(PointCoord destination)
{
	SetUpperLeft(destination);
}
void Visitor::DrawObject(int mask, int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	GetPainter()->DrawVisitor(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), description_ptr->GetForegroundColor(),
		description_ptr->GetBackgroundColor(), description_ptr->GetVisitorSymbol());
}
void Visitor::EraseObject(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY) const
{
	GetPainter()->ErasePixel(GetUpperLeft().Get_x(), GetUpperLeft().Get_y());
}
void Visitor::MakeAStep(Construction* destinationRoadTile)
{
	this->SetUpperLeft(destinationRoadTile->GetUpperLeft());
}
pair<Building*, int> Visitor::FindNearestDestination(const vector<Building*>& suitableBuildings, const list<Road*>& allRoads, vector<int> distances) const
{
	if (suitableBuildings.empty())
	{
		throw MyException("Visitor::FindNearestToilet(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances) building container is empty");
	}
	if (allRoads.empty())
	{
		throw MyException("Visitor::FindNearestToilet(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances) roads container is empty");
	}
	if (distances.empty())
	{
		throw MyException("Visitor::FindNearestToilet(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances) distances container is empty");
	}
	Building* nearestOne = nullptr;
	int lowestDistance = numeric_limits<int>::max();
	int desiredRoadIndex = -1;
	for (auto building : suitableBuildings)
	{
		if (building->GetRoadConnectionStatus())
		{
			Road* connectedToBuildingRoad = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(allRoads, building->GetPotentialConnectedRoadPoint());
			if (connectedToBuildingRoad == nullptr)
			{
				throw MyException("Visitor::ChooseDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<vector<int> > weightMatrix) no road found near building entrance");
			}
			int roadIndex = ElementIndexSearcher::GetElementIndexSearcher()->GetElementIndex(allRoads, connectedToBuildingRoad);
			if (roadIndex == -1)
			{
				throw MyException("Visitor::ChooseDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<vector<int> > weightMatrix) road is out of container");
			}
			if (lowestDistance > distances.at(roadIndex))
			{
				lowestDistance = distances.at(roadIndex);
				nearestOne = building;
				desiredRoadIndex = roadIndex;
			}
		}
	}
	return pair<Building*, int>(nearestOne, desiredRoadIndex);
}
Building* Visitor::GetDestination() const
{
	return destination_ptr;
}
int Visitor::SetDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances)
{
	vector<Building*> buildingsChoosenByProperty;
	if (toiletNeed < 10 || foodCapacity < 10)
	{
		buildingsChoosenByProperty = Building::ChooseFromBuildings(mem_fn(&ConstructionDescriptor::GetIsExit), allBuildings);
	}
	else if (toiletNeed < 25)
	{
		buildingsChoosenByProperty = Building::ChooseFromBuildings(mem_fn(&ConstructionDescriptor::GetRestorationOfToiletNeed), allBuildings);
	}
	else if (foodCapacity < 25)
	{
		buildingsChoosenByProperty = Building::ChooseFromBuildings(mem_fn(&ConstructionDescriptor::GetSatisfactionOfHunger), allBuildings);
	}
	else
	{
		buildingsChoosenByProperty = Building::ChooseFromBuildings(mem_fn(&ConstructionDescriptor::GetEntertainmentValue), allBuildings);
		if (!buildingsChoosenByProperty.empty())
		{
			destination_ptr = buildingsChoosenByProperty.at(rand() % (buildingsChoosenByProperty.size() - 1));
			Road* connectedToBuildingRoad = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(allRoads, destination_ptr->GetPotentialConnectedRoadPoint());
			return ElementIndexSearcher::GetElementIndexSearcher()->GetElementIndex(allRoads, connectedToBuildingRoad);
		}
		return -1;
	}
	if (!buildingsChoosenByProperty.empty())
	{
		pair<Building*, int> result = FindNearestDestination(buildingsChoosenByProperty, allRoads, distances);
		if (result.first == nullptr)
		{
			throw MyException("Visitor::SetDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances) destination pointer is nullptr");
		}
		destination_ptr = result.first;
		return result.second;
	}
	return -1;
}
pair<vector<int>, int> Visitor::ChooseDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<vector<int> > weightMatrix)
{
	auto visitorRoad = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(allRoads, this->GetUpperLeft());
	if (visitorRoad == nullptr)
	{
		throw MyException("Visitor::ChooseDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<vector<int> > weightMatrix) visitor isn't on road");
	}
	int roadIndex = ElementIndexSearcher::GetElementIndexSearcher()->GetElementIndex(allRoads, visitorRoad);
	if (roadIndex == -1)
	{
		throw MyException("Visitor::ChooseDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<vector<int> > weightMatrix) road is out of container");
	}
	vector<int> distances = DijkstraAlgorithm::dijkstra->GetDistances(weightMatrix, roadIndex);
	int destinationRoadIndex = this->SetDestination(allBuildings, allRoads, distances);
	return pair<vector<int>, int>(distances, destinationRoadIndex);
}
void Visitor::ClearDestination()
{
	destination_ptr = nullptr;
}
const vector<int> Visitor::GetPath() const
{
	return pathIndices;
}
void Visitor::SetPath(vector<int> newPath)
{
	pathIndices = newPath;
}
void Visitor::ClearPath()
{
	pathIndices.clear();
}
int Visitor::GetNextPathIndex(int currentIndex)
{
	if (pathIndices.empty())
	{
		throw MyException("Visitor::GetNextPathIndex(int currentIndex) empty path container");
	}
	if (currentIndex == pathIndices.front())
	{
		return -1; // means that the visitor has finished the path
	}
	auto reverseIter = pathIndices.rbegin();
	for (reverseIter; reverseIter != pathIndices.rend(); reverseIter++)
	{
		if ((*reverseIter) == currentIndex)
		{
			auto nextElement = next(reverseIter, 1);
			if (nextElement != pathIndices.rend())
			{
				return (*nextElement);
			}
		}
	}
	throw MyException("Visitor::GetNextPathIndex(int currentIndex) failed to find next index");
}