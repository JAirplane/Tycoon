#include "ObjectContainers.h"
/////////////Container of All Objects in the Game/////////////
list<IngameObject*>& AllObjects::GetAllObjects()
{
	return everyObject;
}
void AllObjects::AddObject(IngameObject* obj_ptr)
{
	everyObject.push_back(obj_ptr);
}
void AllObjects::AddObject(IngameObject* obj_ptr, int position)
{
	if (everyObject.size() < position)
	{
		everyObject.push_back(obj_ptr);
	}
	else
	{
		list<IngameObject*>::iterator iter = everyObject.begin();
		iter = next(iter, position - 1);
		everyObject.insert(iter, obj_ptr);
	}
}
void AllObjects::SetLastElementFlag(bool changer)
{
	lastElementIsPreliminary = changer;
}
bool AllObjects::GetLastElementFlag()
{
	return lastElementIsPreliminary;
}
IngameObject* AllObjects::GetPreliminaryElement()
{
	return everyObject.back();
}
void AllObjects::ErasePreliminaryElement()
{
	everyObject.pop_back();
}
bool AllObjects::IsPartOfExistingObject(PointCoord point)
{
	list<IngameObject*>::iterator iter;
	for (iter = everyObject.begin(); iter != everyObject.end(); iter++)
	{
		PointCoord upperLeft = (*iter)->GetUpperLeft();
		unsigned int heightAdd = (*iter)->GetHeightAddition();
		unsigned int widthAdd = (*iter)->GetWidthAddition();
		if (point.Get_x() >= upperLeft.Get_x() && point.Get_x() <= (upperLeft.Get_x() + widthAdd) && point.Get_y() >= upperLeft.Get_y() && point.Get_y() <= (upperLeft.Get_y() + heightAdd))
		{
			return true;
		}
	}
	return false;
}
bool AllObjects::IsPartOfExistingObject(IngameObject* object_ptr, int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY)
{
	list<IngameObject*>::iterator iter;
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
				for (iter = everyObject.begin(); iter != everyObject.end(); iter++)
				{
					if (object_ptr != (*iter))
					{
						PointCoord upperLeft = (*iter)->GetUpperLeft();
						unsigned int heightAdd = (*iter)->GetHeightAddition();
						unsigned int widthAdd = (*iter)->GetWidthAddition();
						if (xCoord >= upperLeft.Get_x() && xCoord <= (upperLeft.Get_x() + widthAdd) && yCoord >= upperLeft.Get_y() && yCoord <= (upperLeft.Get_y() + heightAdd))
						{
							return true;
						}
					}
				}
			}
			if (yCoord == cameraTopY || yCoord == cameraBottomY || xCoord == cameraLeftX || xCoord == cameraRightX)
			{
				return true;
			}
		}
		xCoord = object_ptr->GetUpperLeft().Get_x();
	}

	return false;
}
void AllObjects::EraseObjects(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY)
{
	list<IngameObject*>::iterator iter;
	for (iter = everyObject.begin(); iter != everyObject.end(); iter++)
	{
		int leftX = (*iter)->GetUpperLeft().Get_x();
		int topY = (*iter)->GetUpperLeft().Get_y();
		int rightX = (*iter)->GetUpperLeft().Get_x() + (*iter)->GetWidthAddition();
		int bottomY = (*iter)->GetUpperLeft().Get_y() + (*iter)->GetHeightAddition();
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
		if (leftX < cameraRightX && topY < cameraBottomY && rightX > cameraLeftX && bottomY > cameraTopY)
		{
			draw_ptr->EraseConstruction(leftX, topY, rightX, bottomY);
		}
	}
}
///////////////All buildings Class///////////////
void AllBuildings::AddBuilding(Building* go_ptr)
{
	buildings.push_back(go_ptr);
}
void AllBuildings::DisplayBuildings(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY)
{
	list<Building*>::iterator iter;
	for (iter = buildings.begin(); iter != buildings.end(); iter++)
	{
		int leftX = (*iter)->GetUpperLeft().Get_x();
		int topY = (*iter)->GetUpperLeft().Get_y();
		int rightX = (*iter)->GetUpperLeft().Get_x() + (*iter)->GetWidthAddition();
		int bottomY = (*iter)->GetUpperLeft().Get_y() + (*iter)->GetHeightAddition();
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
		if (leftX < cameraRightX && topY < cameraBottomY && rightX > cameraLeftX && bottomY > cameraTopY)
		{
			draw_ptr->DrawConstruction(leftX, topY, rightX, bottomY, (*iter)->GetDescriptor()->GetConstructionSymbol(),
				(*iter)->GetDescriptor()->GetForegroundColor(), (*iter)->GetDescriptor()->GetBackgroundColor());
		}
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
const list<Building*> AllBuildings::GetAllBuildings()
{
	return buildings;
}
vector<PointCoord> AllBuildings::GetPotentialRoadCoords()
{
	vector<PointCoord> potentiallyRoad;
	list<Building*>::iterator iter;
	for (iter = buildings.begin(); iter != buildings.end(); iter++)
	{
		PointCoord entrance = (*iter)->GetEntrance();
		Direction exitDirection = (*iter)->GetExitDirection();
		switch (exitDirection)
		{
		case Direction::Up: {potentiallyRoad.push_back(PointCoord(entrance.Get_x(), entrance.Get_y() - 1)); break; }
		case Direction::Down: {potentiallyRoad.push_back(PointCoord(entrance.Get_x(), entrance.Get_y() + 1)); break; }
		case Direction::Right: {potentiallyRoad.push_back(PointCoord(entrance.Get_x() + 1, entrance.Get_y())); break; }
		case Direction::Left: {potentiallyRoad.push_back(PointCoord(entrance.Get_x() - 1, entrance.Get_y())); break; }
		}
	}
	return potentiallyRoad;
}
void AllBuildings::SetRoadConnectionStatus(vector<PointCoord> connectedRoads)
{
	vector<PointCoord>::iterator pointIter;
	list<Building*>::iterator buildingIter;
	for (pointIter = connectedRoads.begin(); pointIter != connectedRoads.end(); pointIter++)
	{
		buildingIter = buildings.begin();
		do
		{
			PointCoord connectedRoad;
			switch ((*buildingIter)->GetExitDirection())
			{
			case Direction::Up: {connectedRoad = PointCoord((*buildingIter)->GetEntrance().Get_x(), (*buildingIter)->GetEntrance().Get_y() - 1); break; }
			case Direction::Down: {connectedRoad = PointCoord((*buildingIter)->GetEntrance().Get_x(), (*buildingIter)->GetEntrance().Get_y() + 1); break; }
			case Direction::Right: {connectedRoad = PointCoord((*buildingIter)->GetEntrance().Get_x() + 1, (*buildingIter)->GetEntrance().Get_y()); break; }
			case Direction::Left: {connectedRoad = PointCoord((*buildingIter)->GetEntrance().Get_x() - 1, (*buildingIter)->GetEntrance().Get_y()); break; }
			}
			if (connectedRoad == (*pointIter))
			{
				(*buildingIter)->SetRoadConnectionStatus(1);
				break;
			}
			++buildingIter;
		} while (buildingIter != buildings.end());
	}
}
///////////////AllVisitors Class///////////////
void AllVisitors::VisitorAppear()
{
	int randomX = rand() % 5 + 1; //5 possible cells to appear
	const int constY = 80; //80 is example, depends on entrance in a world map, but const
	PointCoord startVisitorPoint(randomX, constY);
	if (LocationCheck(startVisitorPoint))
	{
		int food = 100;
		int pee = 100;
		Visitor* visitor_ptr;
		IngameObject* vis_ptr;
		vis_ptr = visitor_ptr = new Visitor(startVisitorPoint, food, pee);
		visitors.push_back(visitor_ptr);
		allObjects_ptr->AddObject(vis_ptr);
		draw_ptr->DrawVisitor((visitor_ptr->GetUpperLeft()).Get_x(), (visitor_ptr->GetUpperLeft()).Get_y());
	}
	cursor_ptr->SetCursorConsoleLocation();
}
bool AllVisitors::LocationCheck(PointCoord point)
{
	list< Visitor* >::iterator iter;
	for (iter = visitors.begin(); iter != visitors.end(); iter++)
	{
		if (point == (*iter)->GetUpperLeft())
		{
			return 0;
		}
	}
	return 1;
}
list<Visitor*>& AllVisitors::GetAllVisitors()
{
	return visitors;
}
void AllVisitors::DisplayVisitors()
{
	list< Visitor* >::iterator iter;
	for (iter = visitors.begin(); iter != visitors.end(); iter++)
	{
		PointCoord upperLeftVisitor = (*iter)->GetUpperLeft();
		draw_ptr->DrawVisitor(upperLeftVisitor.Get_x(), upperLeftVisitor.Get_y());
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
///////////////AllRoads Class///////////////
void AllRoads::AddRoad(Road* go_ptr)
{
	roads.push_back(go_ptr);
}
list<Road*>& AllRoads::GetAllRoads()
{
	return roads;
}
int AllRoads::RoadEnvironment(PointCoord point)
{
	list<Road*>::iterator iter;
	PointCoord leftLocation(point.Get_x() - 1, point.Get_y());
	PointCoord rightLocation(point.Get_x() + 1, point.Get_y());
	PointCoord downLocation(point.Get_x(), point.Get_y() + 1);
	PointCoord upLocation(point.Get_x(), point.Get_y() - 1);
	int roadEnvironmentMask = 0;
	for (iter = roads.begin(); iter != roads.end(); iter++)
	{
		if ((*iter)->GetUpperLeft() == leftLocation)
		{
			roadEnvironmentMask |= int(roadMask::LEFT);
		}
		if ((*iter)->GetUpperLeft() == rightLocation)
		{
			roadEnvironmentMask |= int(roadMask::RIGHT);
		}
		if ((*iter)->GetUpperLeft() == upLocation)
		{
			roadEnvironmentMask |= int(roadMask::TOP);
		}
		if ((*iter)->GetUpperLeft() == downLocation)
		{
			roadEnvironmentMask |= int(roadMask::BOTTOM);
		}
	}
	return roadEnvironmentMask;
}
void AllRoads::DisplayRoads(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY)
{
	list<Road*>::iterator iter;
	for (iter = roads.begin(); iter != roads.end(); iter++)
	{
		int leftX = (*iter)->GetUpperLeft().Get_x();
		int topY = (*iter)->GetUpperLeft().Get_y();
		int rightX = (*iter)->GetUpperLeft().Get_x() + (*iter)->GetWidthAddition();
		int bottomY = (*iter)->GetUpperLeft().Get_y() + (*iter)->GetHeightAddition();
		int mask1 = RoadEnvironment((*iter)->GetUpperLeft());
		char roadSymbol = (*iter)->SetRoadSymbol(mask1);
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
		if (leftX < cameraRightX && topY < cameraBottomY && rightX > cameraLeftX && bottomY > cameraTopY)
		{
			draw_ptr->DrawConstruction(leftX, topY, rightX, bottomY, roadSymbol, (*iter)->GetDescriptor()->GetForegroundColor(), (*iter)->GetDescriptor()->GetBackgroundColor());
		}
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void AllRoads::RedrawrRoads(Road* r_ptr)
{
	int roadMask = RoadEnvironment(r_ptr->GetUpperLeft());
	unsigned char roadSymbol = r_ptr->SetRoadSymbol(roadMask);
	list<Road*>::iterator iter;
	PointCoord leftLocation(r_ptr->GetUpperLeft().Get_x() - 1, r_ptr->GetUpperLeft().Get_y());
	PointCoord rightLocation(r_ptr->GetUpperLeft().Get_x() + 1, r_ptr->GetUpperLeft().Get_y());
	PointCoord downLocation(r_ptr->GetUpperLeft().Get_x(), r_ptr->GetUpperLeft().Get_y() + 1);
	PointCoord upLocation(r_ptr->GetUpperLeft().Get_x(), r_ptr->GetUpperLeft().Get_y() - 1);
	for (iter = roads.begin(); iter != roads.end(); iter++)
	{
		if ((*iter)->GetUpperLeft() == leftLocation || (*iter)->GetUpperLeft() == rightLocation || (*iter)->GetUpperLeft() == downLocation || (*iter)->GetUpperLeft() == upLocation)
		{
			int sideRoadMask = RoadEnvironment((*iter)->GetUpperLeft());
			unsigned char sideRoadSymbol = (*iter)->SetRoadSymbol(sideRoadMask);
			PointCoord upperLeft = (*iter)->GetUpperLeft();
			int heightAdd = (*iter)->GetHeightAddition();
			int widthAdd = (*iter)->GetWidthAddition();
			draw_ptr->DrawConstruction(upperLeft.Get_x(), upperLeft.Get_y(), upperLeft.Get_x() + widthAdd, upperLeft.Get_y() + heightAdd, sideRoadSymbol, (*iter)->GetDescriptor()->GetForegroundColor(), (*iter)->GetDescriptor()->GetBackgroundColor());
		}
	}
	PointCoord centralUpperLeft = r_ptr->GetUpperLeft();
	int centralRoadHeightAdd = r_ptr->GetHeightAddition();
	int centralRoadWidthAdd = r_ptr->GetWidthAddition();
	draw_ptr->DrawConstruction(centralUpperLeft.Get_x(), centralUpperLeft.Get_y(), centralUpperLeft.Get_x() + centralRoadWidthAdd, centralUpperLeft.Get_y() + centralRoadHeightAdd, roadSymbol,
		r_ptr->GetDescriptor()->GetForegroundColor(), r_ptr->GetDescriptor()->GetBackgroundColor());
}
void AllRoads::IsGraphRoadsOnly()
{
	list<Road*>::iterator iter;
	for (iter = roads.begin(); iter != roads.end(); iter++)
	{
		int mask = RoadEnvironment((*iter)->GetUpperLeft());
		(*iter)->DefineGraphStatus(mask);
	}
}
vector<PointCoord> AllRoads::RoadConnectedToEntranceCheck(vector<PointCoord> possibleRoads)
{
	list<Road*>::iterator roadIter;
	vector<PointCoord>::iterator pointIter;
	vector<PointCoord> roadsNearBuildingEntrance;
	for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
	{
		for (pointIter = possibleRoads.begin(); pointIter != possibleRoads.end(); pointIter++)
		{
			if ((*roadIter)->GetUpperLeft() == (*pointIter))
			{
				(*roadIter)->SetGraphStatus(1);
				roadsNearBuildingEntrance.push_back((*roadIter)->GetUpperLeft());
			}
		}
	}
	return roadsNearBuildingEntrance;
}
void AllRoads::SetChainStatus()
{
	//////////////////////////////////
}