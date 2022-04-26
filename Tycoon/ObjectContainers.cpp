#include "ObjectContainers.h"
/////////////Containers of All Objects in the Game/////////////
void AllObjects::CreateExit(const PlayingField* playingField_ptr, Visualisation* draw_ptr)
{
	ConstructionDescriptor* exitDescriptor = new BuildingDescriptor(PointCoord(numeric_limits<int>::max(), numeric_limits<int>::max()),
		ConstructionOptions::GetAllOptions()->GetExitCost(), ConstructionOptions::GetAllOptions()->GetExitDescription(), ConstructionOptions::GetAllOptions()->GetExitIconSymbol(),
		ConstructionOptions::GetAllOptions()->GetExitForegroundColor(), ConstructionOptions::GetAllOptions()->GetExitConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetExitNotConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetExitChosenBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetExitSymbol(), ConstructionOptions::GetAllOptions()->GetExitToiletNeed(),
		ConstructionOptions::GetAllOptions()->GetExitHungerSatisfaction(), ConstructionOptions::GetAllOptions()->GetExitVisitPrice(),
		ConstructionOptions::GetAllOptions()->GetExitEntertainmentValue(), ConstructionOptions::GetAllOptions()->GetExitIsExit(),
		ConstructionOptions::GetAllOptions()->GetExitMaxVisitors(), ConstructionOptions::GetAllOptions()->GetExitExpences(),
		ConstructionOptions::GetAllOptions()->GetExitHeightAdd(), ConstructionOptions::GetAllOptions()->GetExitWidthAdd());
	Building* exit1 = new Building(PointCoord(playingField_ptr->GetHalfXAxis(), playingField_ptr->GetUpperLeft().Get_y() + playingField_ptr->GetHeightAddition() + 4),
		exitDescriptor, draw_ptr);
	exit1->SetExitDirection(Direction::Up);
	Building* exit2 = new Building(PointCoord(playingField_ptr->GetHalfXAxis() + 1, playingField_ptr->GetUpperLeft().Get_y() + playingField_ptr->GetHeightAddition() + 4),
		exitDescriptor, draw_ptr);
	exit2->SetExitDirection(Direction::Up);
	exit1->SetRoadConnectionStatus(true);
	exit2->SetRoadConnectionStatus(true);
	this->AddObject(exit1);
	this->AddObject(exit2);
}
void AllObjects::CreateParkEntrance(const PlayingField* playingField_ptr, ConstructionDescriptor* descriptor_ptr, Visualisation* draw_ptr)
{
	if (playingField_ptr == nullptr)
	{
		throw MyException("CreateParkEntrance(const PlayingField* playingField_ptr, ConstructionDescriptor* descriptor_ptr, Visualisation* draw_ptr) playingfield is nullptr");
	}
	if (draw_ptr == nullptr)
	{
		throw MyException("CreateParkEntrance(const PlayingField* playingField_ptr, ConstructionDescriptor* descriptor_ptr, Visualisation* draw_ptr) draw_ptr is nullptr");
	}
	if (!static_cast<RoadDescriptor*>(descriptor_ptr))
	{
		throw MyException("CreateParkEntrance(const PlayingField* playingField_ptr, ConstructionDescriptor* descriptor_ptr, Visualisation* draw_ptr) bad descriptor");
	}
	this->CreateExit(playingField_ptr, draw_ptr);
	for (int yAdd = 3; yAdd >= 0; yAdd--)
	{
		for (int xAdd = 0; xAdd <= 1; xAdd++)
		{
			VisibleOutsidePlayingfieldRoad* road_ptr = new VisibleOutsidePlayingfieldRoad(PointCoord(playingField_ptr->GetHalfXAxis() + xAdd,
				playingField_ptr->GetUpperLeft().Get_y() + playingField_ptr->GetHeightAddition() + yAdd), descriptor_ptr, draw_ptr);
			roads.push_back(road_ptr);
			road_ptr->SetRoadConnectionStatus(true);
			road_ptr->GraphStatusAttach(graph_ptr);
			auto roadEdges = GetRoadEdges(road_ptr);
			road_ptr->GraphStatusNotify(roadEdges);
		}
	}
	for (int xAdd = 0; xAdd <= 1; xAdd++)
	{
		UnbreakableRoad* undestractableRoad_ptr = new UnbreakableRoad(PointCoord(playingField_ptr->GetHalfXAxis() + xAdd,
			playingField_ptr->GetUpperLeft().Get_y() + playingField_ptr->GetHeightAddition() - 1), descriptor_ptr, draw_ptr);
		roads.push_back(undestractableRoad_ptr);
		undestractableRoad_ptr->SetRoadConnectionStatus(true);
		undestractableRoad_ptr->GraphStatusAttach(graph_ptr);
		auto roadEdges = GetRoadEdges(undestractableRoad_ptr);
		undestractableRoad_ptr->GraphStatusNotify(roadEdges);
	}
}
//
const list<Building*>& AllObjects::GetAllBuildings() const
{
	return buildings;
}
const list<Road*>& AllObjects::GetAllRoads() const
{
	return roads;
}
RoadGraph* AllObjects::GetGraph() const
{
	return graph_ptr;
}
void AllObjects::AddObject(Building* obj_ptr)
{
	if (obj_ptr == nullptr)
	{
		throw MyException("AllObjects::AddObject(Building* obj_ptr) received nullptr argument.");
	}
	buildings.push_back(obj_ptr);
}
void AllObjects::AddObject(Road* obj_ptr)
{
	if (obj_ptr == nullptr)
	{
		throw MyException("AllObjects::AddObject(Road* obj_ptr) received nullptr argument.");
	}
	roads.push_back(obj_ptr);
}
void AllObjects::AddObject(Visitor* obj_ptr)
{
	if (obj_ptr == nullptr)
	{
		throw MyException("AllObjects::AddObject(Road* obj_ptr) received nullptr argument.");
	}
	visitors.push_back(obj_ptr);
}
void AllObjects::AddPreliminaryElement(Construction* preliminary_ptr)
{
	if (preliminary_ptr == nullptr)
	{
		throw MyException("AllObjects::AddPreliminaryElement(Construction* preliminary_ptr) received nullptr argument.");
	}
	if (preliminaryConstruction_ptr == nullptr)
	{
		preliminaryConstruction_ptr = preliminary_ptr;
	}
	else
	{
		throw MyException("AllObjects::AddPreliminaryElement(Construction* preliminary_ptr) preliminaryConstruction_ptr not a nullptr."); // exception
	}
}
Construction* AllObjects::GetPreliminaryElement() const
{
	return preliminaryConstruction_ptr;
}
void AllObjects::ErasePreliminaryElement(Camera* camera_ptr, PlayingField* field_ptr)
{
	if (preliminaryConstruction_ptr != nullptr)
	{
		if (!ObjectImposition(preliminaryConstruction_ptr, camera_ptr, field_ptr))
		{
			draw_ptr->EraseConstruction(preliminaryConstruction_ptr->GetUpperLeft().Get_x(), preliminaryConstruction_ptr->GetUpperLeft().Get_y(),
				preliminaryConstruction_ptr->GetUpperLeft().Get_x() + preliminaryConstruction_ptr->GetWidthAddition(),
				preliminaryConstruction_ptr->GetUpperLeft().Get_y() + preliminaryConstruction_ptr->GetHeightAddition());
			PointCoord preliminaryElementNeibourRedraw = preliminaryConstruction_ptr->GetRedrawNeighboursPoint();
			delete preliminaryConstruction_ptr;
			preliminaryConstruction_ptr = nullptr;
			Construction::RedrawNeighbours(preliminaryElementNeibourRedraw, roads, buildings, preliminaryConstruction_ptr, camera_ptr);
			return;
		}
		delete preliminaryConstruction_ptr;
		preliminaryConstruction_ptr = nullptr;
	}
}
bool AllObjects::BuildingsImposition(PointCoord point) const
{
	list<Building*>::const_iterator buildingIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		PointCoord upperLeft = (*buildingIter)->GetUpperLeft();
		int heightAdd = (*buildingIter)->GetHeightAddition();
		int widthAdd = (*buildingIter)->GetWidthAddition();
		if (point.Get_x() >= upperLeft.Get_x() && point.Get_x() <= (upperLeft.Get_x() + widthAdd) && point.Get_y() >= upperLeft.Get_y() && point.Get_y() <= (upperLeft.Get_y() + heightAdd))
		{
			return true;
		}
	}
	return false;
}
bool AllObjects::BuildingsImposition(IngameObject* object_ptr) const
{
	if (object_ptr == nullptr)
	{
		throw MyException("AllObjects::BuildingsImposition(IngameObject* object_ptr) received nullptr argument object_ptr.");
	}
	list<Building*>::const_iterator buildingIter;
	int xCoord = object_ptr->GetUpperLeft().Get_x();
	int yCoord = object_ptr->GetUpperLeft().Get_y();
	int objectHeightAdd = object_ptr->GetHeightAddition();
	int objectWidthAdd = object_ptr->GetWidthAddition();
	for (yCoord; yCoord <= object_ptr->GetUpperLeft().Get_y() + objectHeightAdd; yCoord++)
	{
		for (xCoord; xCoord <= object_ptr->GetUpperLeft().Get_x() + objectWidthAdd; xCoord++)
		{
			if (yCoord == object_ptr->GetUpperLeft().Get_y() || yCoord == object_ptr->GetUpperLeft().Get_y() + objectHeightAdd,
				xCoord == object_ptr->GetUpperLeft().Get_x() || xCoord == object_ptr->GetUpperLeft().Get_x() + objectWidthAdd)
			{
				for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
				{
					if (object_ptr != (*buildingIter))
					{
						PointCoord upperLeft = (*buildingIter)->GetUpperLeft();
						int heightAdd = (*buildingIter)->GetHeightAddition();
						int widthAdd = (*buildingIter)->GetWidthAddition();
						if (xCoord >= upperLeft.Get_x() && xCoord <= (upperLeft.Get_x() + widthAdd) && yCoord >= upperLeft.Get_y() && yCoord <= (upperLeft.Get_y() + heightAdd))
						{
							return true;
						}
					}
				}
			}
		}
		xCoord = object_ptr->GetUpperLeft().Get_x();
	}
	return false;
}
bool AllObjects::RoadsImposition(PointCoord point) const
{
	list<Road*>::const_iterator roadIter;
	for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
	{
		if (point == (*roadIter)->GetUpperLeft())
		{
			return true;
		}
	}
	return false;
}
bool AllObjects::RoadsImposition(IngameObject* object_ptr) const
{
	if (object_ptr == nullptr)
	{
		throw MyException("AllObjects::RoadsImposition(IngameObject* object_ptr) received nullptr argument object_ptr.");
	}
	list<Road*>::const_iterator roadIter;
	int xCoord = object_ptr->GetUpperLeft().Get_x();
	int yCoord = object_ptr->GetUpperLeft().Get_y();
	int objectHeightAdd = object_ptr->GetHeightAddition();
	int objectWidthAdd = object_ptr->GetWidthAddition();
	for (yCoord; yCoord <= object_ptr->GetUpperLeft().Get_y() + objectHeightAdd; yCoord++)
	{
		for (xCoord; xCoord <= object_ptr->GetUpperLeft().Get_x() + objectWidthAdd; xCoord++)
		{
			for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
			{
				if (object_ptr != (*roadIter))
				{
					if (PointCoord(xCoord, yCoord) == (*roadIter)->GetUpperLeft())
					{
						return true;
					}
				}
			}
		}
		xCoord = object_ptr->GetUpperLeft().Get_x();
	}
	return false;
}
bool AllObjects::VisitorsImposition(PointCoord point) const
{
	list<Visitor*>::const_iterator visitorIter;
	for (visitorIter = visitors.begin(); visitorIter != visitors.end(); visitorIter++)
	{
		if (point == (*visitorIter)->GetUpperLeft())
		{
			return true;
		}
	}
	return false;
}
bool AllObjects::VisitorsImposition(IngameObject* object_ptr) const
{
	if (object_ptr == nullptr)
	{
		throw MyException("AllObjects::VisitorsImposition(IngameObject* object_ptr) received nullptr argument object_ptr.");
	}
	list<Visitor*>::const_iterator visitorIter;
	int xCoord = object_ptr->GetUpperLeft().Get_x();
	int yCoord = object_ptr->GetUpperLeft().Get_y();
	int objectHeightAdd = object_ptr->GetHeightAddition();
	int objectWidthAdd = object_ptr->GetWidthAddition();
	for (yCoord; yCoord <= object_ptr->GetUpperLeft().Get_y() + objectHeightAdd; yCoord++)
	{
		for (xCoord; xCoord <= object_ptr->GetUpperLeft().Get_x() + objectWidthAdd; xCoord++)
		{
			if (yCoord == object_ptr->GetUpperLeft().Get_y() || yCoord == object_ptr->GetUpperLeft().Get_y() + objectHeightAdd,
				xCoord == object_ptr->GetUpperLeft().Get_x() || xCoord == object_ptr->GetUpperLeft().Get_x() + objectWidthAdd)
			{
				for (visitorIter = visitors.begin(); visitorIter != visitors.end(); visitorIter++)
				{
					if (object_ptr != (*visitorIter))
					{
						if (PointCoord(xCoord, yCoord) == (*visitorIter)->GetUpperLeft())
						{
							return true;
						}
					}
				}
			}
		}
		xCoord = object_ptr->GetUpperLeft().Get_x();
	}
	return false;
}
bool AllObjects::ObjectImposition(PointCoord point, PlayingField* field_ptr) const
{
	if (field_ptr->IsLocationOnTheBorder(point))
	{
		return true;
	}
	if (BuildingsImposition(point))
	{
		return true;
	}
	if (RoadsImposition(point))
	{
		return true;
	}
	if (VisitorsImposition(point))
	{
		return true;
	}
	return false;
}
bool AllObjects::ObjectImposition(IngameObject* object_ptr, const Camera* camera_ptr, const PlayingField* field_ptr) const
{
	if (!camera_ptr->IsObjectInsideTheRectangle(object_ptr))
	{
		return true;
	}
	if (!field_ptr->IsObjectInsideTheRectangle(object_ptr) && !object_ptr->VisibleOutsidePlayingfield())
	{
		return true;
	}
	if (BuildingsImposition(object_ptr))
	{
		return true;
	}
	if (RoadsImposition(object_ptr))
	{
		return true;
	}
	if (VisitorsImposition(object_ptr))
	{
		return true;
	}
	return false;
}
void AllObjects::EraseObjects(Camera* camera_ptr)
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	list<Building*>::const_iterator buildingIter;
	list<Road*>::const_iterator roadIter;
	list<Visitor*>::const_iterator visitorIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		int leftX = (*buildingIter)->GetUpperLeft().Get_x();
		int topY = (*buildingIter)->GetUpperLeft().Get_y();
		int rightX = (*buildingIter)->GetUpperLeft().Get_x() + (*buildingIter)->GetWidthAddition();
		int bottomY = (*buildingIter)->GetUpperLeft().Get_y() + (*buildingIter)->GetHeightAddition();
		(*buildingIter)->CorrectBuildingCoordsForDraw(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY);
		if (leftX < cameraRightX && topY < cameraBottomY && rightX > cameraLeftX && bottomY > cameraTopY)
		{
			draw_ptr->EraseConstruction(leftX, topY, rightX, bottomY);
		}
	}
	for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
	{
		int leftX = (*roadIter)->GetUpperLeft().Get_x();
		int topY = (*roadIter)->GetUpperLeft().Get_y();
		if (leftX < cameraRightX && topY < cameraBottomY && leftX > cameraLeftX && topY > cameraTopY)
		{
			draw_ptr->ErasePixel(leftX, topY);
		}
	}
	for (visitorIter = visitors.begin(); visitorIter != visitors.end(); visitorIter++)
	{
		int leftX = (*visitorIter)->GetUpperLeft().Get_x();
		int topY = (*visitorIter)->GetUpperLeft().Get_y();
		if (leftX < cameraRightX && topY < cameraBottomY && leftX > cameraLeftX && topY > cameraTopY)
		{
			draw_ptr->ErasePixel(leftX, topY);
		}
	}
}
void AllObjects::ShiftBuildings(Direction shiftDirection, int shiftValue)
{
	list<Building*>::iterator buildingIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		(*buildingIter)->ShiftObject(shiftDirection, shiftValue); //already has an exception inside
	}
}
void AllObjects::ShiftRoads(Direction shiftDirection, int shiftValue)
{
	list<Road*>::iterator roadIter;
	for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
	{
		(*roadIter)->ShiftObject(shiftDirection, shiftValue); //already has an exception inside
	}
}
void AllObjects::ShiftVisitors(Direction shiftDirection, int shiftValue)
{
	list<Visitor*>::iterator visitorIter;
	for (visitorIter = visitors.begin(); visitorIter != visitors.end(); visitorIter++)
	{
		(*visitorIter)->ShiftObject(shiftDirection, shiftValue); //already has an exception inside
	}
}
void AllObjects::DisplayBuildings(const Camera* camera_ptr, const PlayingField* field_ptr) const
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	list<Building*>::const_iterator buildingIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		if (field_ptr->IsObjectInsideTheRectangle(*buildingIter) || (*buildingIter)->VisibleOutsidePlayingfield())
		{
			(*buildingIter)->DrawObject(0, cameraLeftX, cameraTopY, cameraRightX, cameraBottomY);
		}
	}
}
void AllObjects::DisplayVisitors(const Camera* camera_ptr)
{
	list< Visitor* >::iterator visitorIter;
	for (visitorIter = visitors.begin(); visitorIter != visitors.end(); visitorIter++)
	{
		if (camera_ptr->IsObjectInsideTheRectangle(*visitorIter))
		{
			(*visitorIter)->DrawObject();
		}
	}
}
void AllObjects::DisplayRoads(const Camera* camera_ptr, const PlayingField* field_ptr)
{
	list<Road*>::iterator iter;
	for (iter = roads.begin(); iter != roads.end(); iter++)
	{
		int mask = (*iter)->GetEnvironmentMask(roads, buildings, preliminaryConstruction_ptr);
		if (!ObjectImposition((*iter), camera_ptr, field_ptr))
		{
			(*iter)->DrawObject(mask);
		}
	}
}
Construction* AllObjects::FindConstruction(PointCoord location) const
{
	Road* desiredRoad_ptr = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(roads, location);
	if (desiredRoad_ptr != nullptr)
	{
		return desiredRoad_ptr;
	}
	Building* desiredBuilding_ptr = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(buildings, location);
	if (desiredBuilding_ptr != nullptr)
	{
		return desiredBuilding_ptr;
	}
	return nullptr;
}
void AllObjects::DeleteConstruction(Construction* forDeleting, function<bool(Construction*)> IsEqual)
{
	if (forDeleting == nullptr)
	{
		throw MyException("AllObjects::DeleteConstruction(Construction* forDeleting, function<bool(Construction*)> IsEqual) got nullptr construction");
	}
	auto buildingIter = find(buildings.begin(), buildings.end(), forDeleting);
	if (buildingIter == buildings.end())
	{
		auto roadIter = find(roads.begin(), roads.end(), forDeleting);
		if (roadIter == roads.end())
		{
			throw MyException("AllObjects::DeleteConstruction(Construction* forDeleting, function<bool(Construction*)> IsEqual) construction is out of containers");
		}
		else
		{
			int index = ElementIndexSearcher::GetElementIndexSearcher()->GetElementIndex(roads, (*roadIter));
			if (index == -1)
			{
				throw MyException("AllObjects::DeleteConstruction(Construction* forDeleting, function<bool(Construction*)> IsEqual) no node with such index");
			}
			ClearVisitorPathes(index);
			(*roadIter)->GraphStatusNotify(index);
			roads.remove_if(IsEqual);
		}
	}
	else
	{
		ClearVisitorPathes(forDeleting);
		buildings.remove_if(IsEqual);
	}
}
void AllObjects::DeleteVisitor(Visitor* forDeleting, function<bool(Visitor*)> IsEqual)
{
	visitors.remove_if(IsEqual);
}
//
void AllObjects::AddEdge(int mainRoadIndex, PointCoord location, Direction side, vector<pair<pair<int, int>, Direction> >& roadEdges) const
{
	Road* neighbour = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(roads, location.GetSideCoord(side));
	if (neighbour != nullptr)
	{
		int neighbourIndex = ElementIndexSearcher::GetElementIndexSearcher()->GetElementIndex(roads, neighbour);
		auto edge = make_pair(mainRoadIndex, neighbourIndex);
		roadEdges.push_back(make_pair(edge, side));
	}
}
vector<pair<pair<int, int>, Direction> > AllObjects::GetRoadEdges(Road* someRoad) const
{
	vector<pair<pair<int, int>, Direction> > roadEdges;
	int mainRoadIndex = ElementIndexSearcher::GetElementIndexSearcher()->GetElementIndex(roads, someRoad);
	if (mainRoadIndex == -1)
	{
		throw MyException("AllObjects::GetRoadEdges(Road* someRoad) const road is out of roads container");
	}
	AddEdge(mainRoadIndex, someRoad->GetUpperLeft(), Direction::Left, roadEdges);
	AddEdge(mainRoadIndex, someRoad->GetUpperLeft(), Direction::Up, roadEdges);
	AddEdge(mainRoadIndex, someRoad->GetUpperLeft(), Direction::Right, roadEdges);
	AddEdge(mainRoadIndex, someRoad->GetUpperLeft(), Direction::Down, roadEdges);
	if (roadEdges.empty())
	{
		roadEdges.push_back(make_pair(make_pair(mainRoadIndex, -1), Direction::None));
	}
	return roadEdges;
}
//
void AllObjects::ClearVisitorPathes(int roadIndex)
{
	for (auto visitor : visitors)
	{
		auto result = find(visitor->GetPath().begin(), visitor->GetPath().end(), roadIndex);
		if (result != visitor->GetPath().end())
		{
			visitor->ClearDestination();
			visitor->ClearPath();
		}
	}
}
void AllObjects::ClearVisitorPathes(Construction* destination)
{
	for (auto visitor : visitors)
	{
		if (destination == visitor->GetDestination())
		{
			visitor->ClearDestination();
			visitor->ClearPath();
		}
	}
}
vector<Visitor*> AllObjects::AllVisitorsStep(const Camera* camera_ptr, const PlayingField* field_ptr, GameStats* statistics, int lowestEntertainmentPrice)
{
	if (camera_ptr == nullptr)
	{
		throw MyException("AllObjects::AllVisitorsStep(const Camera* camera_ptr, const PlayingField* field_ptr) camera is nullptr");
	}
	if (field_ptr == nullptr)
	{
		throw MyException("AllObjects::AllVisitorsStep(const Camera* camera_ptr, const PlayingField* field_ptr) playingfield is nullptr");
	}
	vector<Visitor*> forDeleting;
	for (auto visitor : visitors)
	{
		if (visitor->GetDestination() == nullptr)
		{
			pair<vector<int>, int> result = visitor->ChooseDestination(buildings, roads, graph_ptr->GetWeightMatrix(), lowestEntertainmentPrice);
			if (result.second != -1)
			{
				visitor->SetPath(graph_ptr->GetPathIndices(result.first, result.second));
			}
		}
		else
		{
			if (!visitor->GetPath().empty())
			{
				Road* currentRoad = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(roads, visitor->GetUpperLeft());
				if (currentRoad == nullptr)
				{
					throw MyException("Visitor::GetNextPathIndex(const list<Road*>& allRoads) no road on visitor's point");
				}
				int nextRoadIndex = visitor->GetNextPathIndex(roads, currentRoad);
				if (nextRoadIndex == -1)
				{
					statistics->amountOfMoney += visitor->GetDestination()->GetDescriptor()->GetVisitPrice();
					bool exitAchieved = visitor->GoInside();
					if (exitAchieved)
					{
						forDeleting.push_back(visitor);
					}
				}
				else
				{
					visitor->MakeAStep(nextRoadIndex, roads, camera_ptr);
				}
				if (camera_ptr->IsObjectInsideTheRectangle(currentRoad) && !VisitorsImposition(currentRoad))
				{
					currentRoad->DrawObject(currentRoad->GetEnvironmentMask(roads, buildings, preliminaryConstruction_ptr));
				}
			}
			else
			{
				--visitor->buildingVisiting;
				if (visitor->buildingVisiting == 0)
				{
					bool noConnectedRoad = visitor->GoOutside(roads, visitors);
					if (noConnectedRoad)
					{
						forDeleting.push_back(visitor);
					}
					if (camera_ptr->IsObjectInsideTheRectangle(visitor))
					{
						visitor->DrawObject();
					}
				}
			}
		}
	}
	return forDeleting;
}
void AllObjects::DeleteVisitors(vector<Visitor*>& forDeleting)
{
	if (!forDeleting.empty())
	{
		for (auto visitor : forDeleting)
		{
			function<bool(Visitor*)> IsEqual = [visitor](Visitor* element)
			{
				return (visitor == element);
			};
			DeleteVisitor(visitor, IsEqual);
		}
	}
}