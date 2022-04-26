#include "Visitor.h"
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
int Visitor::GetInsideBuildingValue() const
{
	return insideBuilding;
}
void Visitor::SetInsideBuildingValue(int periodsInsideBuilding)
{
	insideBuilding = periodsInsideBuilding;
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
void Visitor::MakeAStep(int destinationRoadIndex, const list<Road*>& allRoads, const Camera* camera_ptr)
{
	auto roadIter = allRoads.begin();
	advance(roadIter, destinationRoadIndex);
	this->SetUpperLeft((*roadIter)->GetUpperLeft());
	if (camera_ptr->IsObjectInsideTheRectangle(this))
	{
		this->DrawObject();
	}
}
bool Visitor::GoInside()
{
	if (this->GetDestination()->GetDescriptor()->GetIsExit())
	{
		return true; // means that visitor should be deleted
	}
	pathIndices.clear();
	if (this->GetDestination()->GetDescriptor()->GetMaxVisitors() > this->GetDestination()->visitorsCounter)
	{
		++this->GetDestination()->visitorsCounter;
		this->SetUpperLeft(this->GetDestination()->GetUpperLeft());
		this->buildingVisiting = 10;
		this->visitorCash -= this->GetDestination()->GetDescriptor()->GetVisitPrice();
	}
	return false;
}
bool Visitor::GoOutside(const list<Road*>& allRoads, list<Visitor*> allVisitors)
{
	--destination_ptr->visitorsCounter;
	previousVisitedBuilding = destination_ptr;
	destination_ptr = nullptr;
	Road* entranceRoad = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(allRoads, previousVisitedBuilding->GetPotentialConnectedRoadPoint());
	if (entranceRoad == nullptr)
	{
		return true; //if user has deleted road connected to building while visitor is inside, visitor disappear. GameStats should be changed further
	}
	else
	{
		this->SetUpperLeft(entranceRoad->GetUpperLeft());
		return false;
	}
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
				continue;
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
int Visitor::SetDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances, int lowestEntertainmentPrice)
{
	vector<Building*> buildingsChoosenByProperty;
	if (toiletNeed < 10 || foodCapacity < 10 || this->visitorCash < lowestEntertainmentPrice)
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
			Building* chosen_ptr = buildingsChoosenByProperty.at(rand() % buildingsChoosenByProperty.size());
			if (chosen_ptr == nullptr)
			{
				throw MyException("Visitor::SetDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances) chosen buildings is nullptr");
			}
			Road* connectedToBuildingRoad = FindByPoint::GetElementSearcherByPoint()->GetElementByPoint(allRoads, chosen_ptr->GetPotentialConnectedRoadPoint());
			int connectedToBuildingRoadIndex = ElementIndexSearcher::GetElementIndexSearcher()->GetElementIndex(allRoads, connectedToBuildingRoad);
			if (distances.at(connectedToBuildingRoadIndex) != numeric_limits<int>::max() && chosen_ptr != previousVisitedBuilding &&
				this->visitorCash >= chosen_ptr->GetDescriptor()->GetVisitPrice())
			{
				destination_ptr = chosen_ptr;
				return connectedToBuildingRoadIndex;
			}
		}
		return -1;
	}
	if (!buildingsChoosenByProperty.empty())
	{
		pair<Building*, int> result = FindNearestDestination(buildingsChoosenByProperty, allRoads, distances);
		if (result.first != nullptr)
		{
			destination_ptr = result.first;
			return result.second;
		}
	}
	return -1;
}
pair<vector<int>, int> Visitor::ChooseDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<vector<int> > weightMatrix, int lowestEntertainmentPrice)
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
	int destinationRoadIndex = this->SetDestination(allBuildings, allRoads, distances, lowestEntertainmentPrice);
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
int Visitor::GetNextPathIndex(const list<Road*>& allRoads, Road* currentRoad)
{
	if (allRoads.empty())
	{
		throw MyException("Visitor::GetNextPathIndex(const list<Road*>& allRoads) empty roads container");
	}
	if (pathIndices.empty())
	{
		throw MyException("Visitor::GetNextPathIndex(const list<Road*>& allRoads) empty path container");
	}
	int currentRoadIndex = ElementIndexSearcher::GetElementIndexSearcher()->GetElementIndex(allRoads, currentRoad);
	if (currentRoadIndex == pathIndices.front())
	{
		return -1; // means that the visitor has finished the path
	}
	auto reverseIter = pathIndices.rbegin();
	for (reverseIter; reverseIter != pathIndices.rend(); reverseIter++)
	{
		if ((*reverseIter) == currentRoadIndex)
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