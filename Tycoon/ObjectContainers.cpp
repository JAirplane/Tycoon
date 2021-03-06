#include "ObjectContainers.h"
/////////////Containers of All Objects in the Game/////////////
const list<Construction*>& AllObjects::GetAllBuildings() const
{
	return buildings;
}
const list<Construction*>& AllObjects::GetAllRoads() const
{
	return roads;
}
const list<Visitor*>& AllObjects::GetAllVisitors() const
{
	return visitors;
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
			this->RedrawNeighbours(preliminaryElementNeibourRedraw, camera_ptr);
			return;
		}
		delete preliminaryConstruction_ptr;
		preliminaryConstruction_ptr = nullptr;
	}
}
bool AllObjects::BuildingsImposition(PointCoord point) const
{
	list<Construction*>::const_iterator buildingIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		PointCoord upperLeft = (*buildingIter)->GetUpperLeft();
		int heightAdd = (*buildingIter)->GetHeightAddition();
		int widthAdd = (*buildingIter)->GetWidthAddition();
		if (point.Get_x() >= upperLeft.Get_x() && point.Get_x() <= (upperLeft.Get_x() + widthAdd) &&
			point.Get_y() >= upperLeft.Get_y() && point.Get_y() <= (upperLeft.Get_y() + heightAdd))
		{
			return true;
		}
	}
	return false;
}
bool AllObjects::BuildingsImposition(const IngameObject* object_ptr) const
{
	if (object_ptr == nullptr)
	{
		throw MyException("AllObjects::BuildingsImposition(IngameObject* object_ptr) received nullptr argument object_ptr.");
	}
	list<Construction*>::const_iterator buildingIter;
	int xCoord = object_ptr->GetUpperLeft().Get_x();
	int yCoord = object_ptr->GetUpperLeft().Get_y();
	int objectHeightAdd = object_ptr->GetHeightAddition();
	int objectWidthAdd = object_ptr->GetWidthAddition();
	for (yCoord; yCoord <= object_ptr->GetUpperLeft().Get_y() + objectHeightAdd; yCoord++)
	{
		for (xCoord; xCoord <= object_ptr->GetUpperLeft().Get_x() + objectWidthAdd; xCoord++)
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
		xCoord = object_ptr->GetUpperLeft().Get_x();
	}
	return false;
}
bool AllObjects::RoadsImposition(PointCoord point) const
{
	list<Construction*>::const_iterator roadIter;
	for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
	{
		if (point == (*roadIter)->GetUpperLeft())
		{
			return true;
		}
	}
	return false;
}
bool AllObjects::RoadsImposition(const IngameObject* object_ptr) const
{
	if (object_ptr == nullptr)
	{
		throw MyException("AllObjects::RoadsImposition(IngameObject* object_ptr) received nullptr argument object_ptr.");
	}
	list<Construction*>::const_iterator roadIter;
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
bool AllObjects::VisitorsImposition(const IngameObject* object_ptr) const
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
bool AllObjects::ObjectImposition(PointCoord point, const PlayingField* field_ptr) const
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
bool AllObjects::ObjectImposition(const IngameObject* object_ptr, const Camera* camera_ptr, const PlayingField* field_ptr) const
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
	list<Construction*>::const_iterator buildingIter;
	list<Construction*>::const_iterator roadIter;
	list<Visitor*>::const_iterator visitorIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		int leftX = (*buildingIter)->GetUpperLeft().Get_x();
		int topY = (*buildingIter)->GetUpperLeft().Get_y();
		int rightX = (*buildingIter)->GetUpperLeft().Get_x() + (*buildingIter)->GetWidthAddition();
		int bottomY = (*buildingIter)->GetUpperLeft().Get_y() + (*buildingIter)->GetHeightAddition();
		(*buildingIter)->CorrectConstructionCoordsForDraw(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY);
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
	list<Construction*>::iterator buildingIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		(*buildingIter)->ShiftObject(shiftDirection, shiftValue); //already has an exception inside
	}
}
void AllObjects::ShiftRoads(Direction shiftDirection, int shiftValue)
{
	list<Construction*>::iterator roadIter;
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
	list<Construction*>::const_iterator buildingIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		if (field_ptr->IsObjectInsideTheRectangle(*buildingIter) || (*buildingIter)->VisibleOutsidePlayingfield())
		{
			(*buildingIter)->DrawObject(0, cameraLeftX, cameraTopY, cameraRightX, cameraBottomY);
		}
	}
}
void AllObjects::DisplayVisitors(const Camera* camera_ptr) const
{
	list<Visitor*>::const_iterator visitorIter;
	for (visitorIter = visitors.begin(); visitorIter != visitors.end(); visitorIter++)
	{
		if (camera_ptr->IsObjectInsideTheRectangle(*visitorIter) && !BuildingsImposition(*visitorIter))
		{
			(*visitorIter)->DrawObject();
		}
	}
}
void AllObjects::DisplayRoads(const Camera* camera_ptr, const PlayingField* field_ptr) const
{
	list<Construction*>::const_iterator iter;
	for (iter = roads.begin(); iter != roads.end(); iter++)
	{
		if (!ObjectImposition((*iter), camera_ptr, field_ptr))
		{
			int mask = (*iter)->GetEnvironmentMask(roads, buildings, preliminaryConstruction_ptr);
			(*iter)->DrawObject(mask);
		}
	}
}
//
void AllObjects::CheckAllConnections()
{
	for (auto building : buildings)
	{
		building->Connected(roads, buildings, preliminaryConstruction_ptr);
	}
	for (auto road : roads)
	{
		road->Connected(roads, buildings, preliminaryConstruction_ptr);
	}
}
void AllObjects::SetVisitorsDestinations()
{
	for (auto everyVisitor : visitors)
	{
		if (everyVisitor->buildingVisiting != 0)
		{
			Construction* currentVisitedBuilding = this->FindConstruction(everyVisitor->GetUpperLeft());
			everyVisitor->SetDestination(currentVisitedBuilding);
		}
	}
}
//
void AllObjects::RedrawNeighbours(PointCoord centralPoint, const Camera* camera_ptr)
{
	vector<Construction*> neighbours;
	for (auto everyRoad : roads)
	{
		if (everyRoad->GetUpperLeft() == centralPoint.GetSideCoord(Direction::Left) || everyRoad->GetUpperLeft() == centralPoint.GetSideCoord(Direction::Up) ||
			everyRoad->GetUpperLeft() == centralPoint.GetSideCoord(Direction::Right) || everyRoad->GetUpperLeft() == centralPoint.GetSideCoord(Direction::Down))
		{
			neighbours.push_back(everyRoad);
		}
	}
	for (auto everyBuilding : buildings)
	{
		if (centralPoint == everyBuilding->GetPotentialConnectedRoadPoint())
		{
			neighbours.push_back(everyBuilding);
		}
	}
	for (auto everyNeighbour : neighbours)
	{
		everyNeighbour->Connected(roads, buildings, preliminaryConstruction_ptr);
		everyNeighbour->Redraw_VisitorCheck(camera_ptr, roads, buildings, visitors, preliminaryConstruction_ptr);
	}
}
void AllObjects::RedrawNeighbours(const Construction* centralConstruction, const Camera* camera_ptr)
{
	vector<Construction*> neighbours = centralConstruction->GetNeighbourRoads(roads);
	vector<Construction*> neighbourBuildings = centralConstruction->GetNeighbourBuildings(buildings);
	neighbours.insert(neighbours.end(), neighbourBuildings.begin(), neighbourBuildings.end());
	for (auto everyNeighbour : neighbours)
	{
		if (everyNeighbour != nullptr && FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(visitors, everyNeighbour->GetUpperLeft()) == nullptr)
		{
			int mask = everyNeighbour->GetEnvironmentMask(roads, buildings, preliminaryConstruction_ptr);
			everyNeighbour->Connected(roads, buildings, preliminaryConstruction_ptr);
			everyNeighbour->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
				camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
		}
	}
}
//
Construction* AllObjects::FindConstruction(PointCoord location) const
{
	Construction* desiredRoad_ptr = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(roads, location);
	if (desiredRoad_ptr != nullptr)
	{
		return desiredRoad_ptr;
	}
	Construction* desiredBuilding_ptr = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(buildings, location);
	if (desiredBuilding_ptr != nullptr)
	{
		return desiredBuilding_ptr;
	}
	return nullptr;
}
void AllObjects::DeleteConstruction(Construction* forDeleting, function<bool(Construction*)> IsEqual, GameStats* statistic)
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
		DeleteVisitorsInsideBuilding(forDeleting, statistic);
		buildings.remove_if(IsEqual);
	}
}
void AllObjects::DeleteVisitor(Visitor* forDeleting, function<bool(Visitor*)> IsEqual)
{
	visitors.remove_if(IsEqual);
}
void AllObjects::DeleteVisitors(vector<Visitor*>& forDeleting, GameStats* statistic)
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
			--statistic->NumberOfVisitors;
		}
	}
}
void AllObjects::DeleteVisitorsInsideBuilding(const Construction* someBuilding, GameStats* statistic)
{
	if (someBuilding == nullptr)
	{
		throw MyException("AllObjects::DeleteVisitorsInsideBuilding(const Construction* someBuilding) received nullptr someBuilding");
	}
	if (statistic == nullptr)
	{
		throw MyException("AllObjects::DeleteVisitorsInsideBuilding(const Construction* someBuilding) received nullptr statistic");
	}
	vector<Visitor*> forDeleting;
	forDeleting = FindByPoint::GetElementSearcherByPoint()->GetAllElementsByPoint(visitors, someBuilding->GetUpperLeft());
	this->DeleteVisitors(forDeleting, statistic);
}
//
void AllObjects::AddEdge(int mainRoadIndex, PointCoord location, Direction side, vector<pair<pair<int, int>, Direction> >& roadEdges) const
{
	Construction* neighbourRoad = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(roads, location.GetSideCoord(side));
	if (neighbourRoad != nullptr)
	{
		int neighbourRoadIndex = ElementIndexSearcher::GetElementIndexSearcher()->GetElementIndex(roads, neighbourRoad);
		auto edge = make_pair(mainRoadIndex, neighbourRoadIndex);
		roadEdges.push_back(make_pair(edge, side));
	}
}
vector<pair<pair<int, int>, Direction> > AllObjects::GetRoadEdges(const Construction* someRoad) const
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
		const vector<int> visitorPath = visitor->GetPath();
		auto result = find(visitorPath.begin(), visitorPath.end(), roadIndex);
		if (result != visitorPath.end())
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
		throw MyException("AllObjects::AllVisitorsStep(const Camera* camera_ptr, const PlayingField* field_ptr, GameStats* statistics, int lowestEntertainmentPrice) camera is nullptr");
	}
	if (field_ptr == nullptr)
	{
		throw MyException("AllObjects::AllVisitorsStep(const Camera* camera_ptr, const PlayingField* field_ptr, GameStats* statistics, int lowestEntertainmentPrice) playingfield is nullptr");
	}
	if (statistics == nullptr)
	{
		throw MyException("AllObjects::AllVisitorsStep(const Camera* camera_ptr, const PlayingField* field_ptr, GameStats* statistics, int lowestEntertainmentPrice) statistics is nullptr");
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
				Construction* currentRoad = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(roads, visitor->GetUpperLeft());
				if (currentRoad == nullptr)
				{
					throw MyException("Visitor::GetNextPathIndex(const list<Road*>& allRoads) no road on visitor's point");
				}
				++currentRoad->allTimeVisited;
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
				if (visitor->buildingVisiting <= 0)
				{
					bool noConnectedRoad = visitor->GoOutside(roads, visitors);
					if (noConnectedRoad)
					{
						forDeleting.push_back(visitor);
					}
					else
					{
						if (camera_ptr->IsObjectInsideTheRectangle(visitor))
						{
							visitor->DrawObject();
						}
					}
				}
			}
		}
	}
	return forDeleting;
}
void AllObjects::VisitorsFoodCapacityReduction()
{
	for (auto everyVisitor : visitors)
	{
		if (everyVisitor->buildingVisiting == 0)
		{
			everyVisitor->starvation -= rand() % 3;
		}
	}
}
void AllObjects::VisitorsToiletNeedReduction()
{
	for (auto everyVisitor : visitors)
	{
		if (everyVisitor->buildingVisiting == 0)
		{
			everyVisitor->toiletNeed -= rand() % 2 + 1;
		}
	}
}
void AllObjects::PayDailyExpences(GameStats* statistics)
{
	if (statistics == nullptr)
	{
		throw MyException("AllObjects::PayDailyExpences(GameStats* statistics) statistics is nullptr");
	}
	int overallExpences = 0;
	for (auto everyBuilding : buildings)
	{
		overallExpences += everyBuilding->GetDescriptor()->GetDailyExpences();
	}
	statistics->amountOfMoney -= overallExpences;
}