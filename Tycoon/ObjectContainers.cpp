#include "ObjectContainers.h"
/////////////Containers of All Objects in the Game/////////////
int AllObjects::GetBuildingsQuantity() const
{
	return buildings.size();
}
int AllObjects::GetRoadsQuantity() const
{
	return roads.size();
}
int AllObjects::GetVisitorsQuantity() const
{
	return visitors.size();
}
void AllObjects::AddObject(Construction* obj_ptr)
{
	if (containsPreliminary == PreliminaryStatus::NONE)
	{
		if (Road* isRoad_ptr = dynamic_cast<Road*>(obj_ptr))
		{
			roads.push_back(isRoad_ptr);
			containsPreliminary = PreliminaryStatus::ROAD;
		}
		else
		{
			buildings.push_back(dynamic_cast<Building*>(obj_ptr));
			containsPreliminary = PreliminaryStatus::BUILDING;
		}
	}
	else if (containsPreliminary == PreliminaryStatus::BUILDING)
	{
		buildings.push_front(dynamic_cast<Building*>(obj_ptr));
	}
	else
	{
		roads.push_front(dynamic_cast<Road*>(obj_ptr));
	}
}
void AllObjects::AddObject(Visitor* obj_ptr, int position, bool isPreliminary)
{
	if (visitors.size() < position || position == -1)
	{
		visitors.push_back(obj_ptr);
	}
	else
	{
		list<Visitor*>::iterator iter = visitors.begin();
		iter = next(iter, position);
		visitors.insert(iter, obj_ptr);
	}
}
PreliminaryStatus AllObjects::GetPreliminaryStatus() const
{
	return containsPreliminary;
}
Construction* AllObjects::GetPreliminaryElement()
{
	if (containsPreliminary == PreliminaryStatus::BUILDING)
	{
		return buildings.back();
	}
	else if (containsPreliminary == PreliminaryStatus::ROAD)
	{
		return roads.back();
	}
	else
	{
		return nullptr;
	}
}
void AllObjects::ErasePreliminaryElement()
{
	if (containsPreliminary != PreliminaryStatus::NONE)
	{
		if (containsPreliminary == PreliminaryStatus::BUILDING)
		{
			buildings.pop_back();
		}
		else
		{
			roads.pop_back();
		}
		containsPreliminary = PreliminaryStatus::NONE;
	}
}
bool AllObjects::ObjectImposition(PointCoord point, PlayingField* field_ptr) const
{
	int playingFieldLeftX = field_ptr->GetUpperLeft().Get_x();
	int playingFieldRightX = playingFieldLeftX + field_ptr->GetWidthAddition();
	int playingFieldTopY = field_ptr->GetUpperLeft().Get_y();
	int playingFieldBottomY = playingFieldTopY + field_ptr->GetHeightAddition();
	if (playingFieldLeftX == point.Get_x() || playingFieldRightX == point.Get_x() || playingFieldTopY == point.Get_y() || playingFieldBottomY == point.Get_y())
	{
		return true;
	}
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
	list<Road*>::const_iterator roadIter;
	for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
	{
		PointCoord upperLeft = (*roadIter)->GetUpperLeft();
		if (point.Get_x() == upperLeft.Get_x() && point.Get_y() == upperLeft.Get_y())
		{
			return true;
		}
	}
	list<Visitor*>::const_iterator visitorIter;
	for (visitorIter = visitors.begin(); visitorIter != visitors.end(); visitorIter++)
	{
		PointCoord upperLeft = (*visitorIter)->GetUpperLeft();
		if (point.Get_x() == upperLeft.Get_x() && point.Get_y() == upperLeft.Get_y())
		{
			return true;
		}
	}
	return false;
}
bool AllObjects::ObjectImposition(IngameObject* object_ptr, Camera* camera_ptr, PlayingField* field_ptr) const
{
	list<Building*>::const_iterator buildingIter;
	list<Road*>::const_iterator roadIter;
	list<Visitor*>::const_iterator visitorIter;
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	int playingFieldLeftX = field_ptr->GetUpperLeft().Get_x();
	int playingFieldRightX = playingFieldLeftX + field_ptr->GetWidthAddition();
	int playingFieldTopY = field_ptr->GetUpperLeft().Get_y();
	int playingFieldBottomY = playingFieldTopY + field_ptr->GetHeightAddition();
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
				for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
				{
					if (object_ptr != (*roadIter))
					{
						PointCoord upperLeft = (*roadIter)->GetUpperLeft();
						if (xCoord == upperLeft.Get_x() && yCoord == upperLeft.Get_y())
						{
							return true;
						}
					}
				}
				for (visitorIter = visitors.begin(); visitorIter != visitors.end(); visitorIter++)
				{
					if (object_ptr != (*visitorIter))
					{
						PointCoord upperLeft = (*visitorIter)->GetUpperLeft();
						if (xCoord == upperLeft.Get_x() && yCoord >= upperLeft.Get_y())
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
			if (yCoord <= playingFieldTopY || yCoord >= playingFieldBottomY || xCoord <= playingFieldLeftX || xCoord >= playingFieldRightX)
			{
				return true;
			}
		}
		xCoord = object_ptr->GetUpperLeft().Get_x();
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
void AllObjects::ShiftAllObjects(Direction shiftDirection)
{
	list<Building*>::iterator buildingIter;
	list<Road*>::iterator roadIter;
	list<Visitor*>::iterator visitorIter;
	for (buildingIter = buildings.begin(), roadIter = roads.begin(), visitorIter = visitors.begin();
		buildingIter != buildings.end() && roadIter != roads.end() && visitorIter != visitors.end();
		buildingIter++, roadIter++, visitorIter++)
	{
		switch (shiftDirection)
		{
		case Direction::Right:
		{
			(*buildingIter)->SetUpperLeft(PointCoord((*buildingIter)->GetUpperLeft().Get_x() + 1, (*buildingIter)->GetUpperLeft().Get_y()));
			(*roadIter)->SetUpperLeft(PointCoord((*roadIter)->GetUpperLeft().Get_x() + 1, (*roadIter)->GetUpperLeft().Get_y()));
			(*visitorIter)->SetUpperLeft(PointCoord((*visitorIter)->GetUpperLeft().Get_x() + 1, (*visitorIter)->GetUpperLeft().Get_y()));
			break;
		}
		case Direction::Down:
		{
			(*buildingIter)->SetUpperLeft(PointCoord((*buildingIter)->GetUpperLeft().Get_x(), (*buildingIter)->GetUpperLeft().Get_y() + 1));
			(*roadIter)->SetUpperLeft(PointCoord((*roadIter)->GetUpperLeft().Get_x(), (*roadIter)->GetUpperLeft().Get_y() + 1));
			(*visitorIter)->SetUpperLeft(PointCoord((*visitorIter)->GetUpperLeft().Get_x(), (*visitorIter)->GetUpperLeft().Get_y() + 1));
			break;
		}
		case Direction::Left:
		{
			(*buildingIter)->SetUpperLeft(PointCoord((*buildingIter)->GetUpperLeft().Get_x() - 1, (*buildingIter)->GetUpperLeft().Get_y()));
			(*roadIter)->SetUpperLeft(PointCoord((*roadIter)->GetUpperLeft().Get_x() - 1, (*roadIter)->GetUpperLeft().Get_y()));
			(*visitorIter)->SetUpperLeft(PointCoord((*visitorIter)->GetUpperLeft().Get_x() - 1, (*visitorIter)->GetUpperLeft().Get_y()));
			break;
		}
		case Direction::Up:
		{
			(*buildingIter)->SetUpperLeft(PointCoord((*buildingIter)->GetUpperLeft().Get_x(), (*buildingIter)->GetUpperLeft().Get_y() - 1));
			(*roadIter)->SetUpperLeft(PointCoord((*roadIter)->GetUpperLeft().Get_x(), (*roadIter)->GetUpperLeft().Get_y() - 1));
			(*visitorIter)->SetUpperLeft(PointCoord((*visitorIter)->GetUpperLeft().Get_x(), (*visitorIter)->GetUpperLeft().Get_y() - 1));
			break;
		}
		}
	}
}
void AllObjects::ShiftAllObjects(Direction shiftDirection, int shiftValue)
{
	list<Building*>::iterator buildingIter;
	list<Road*>::iterator roadIter;
	list<Visitor*>::iterator visitorIter;
	for (buildingIter = buildings.begin(), roadIter = roads.begin(), visitorIter = visitors.begin();
		buildingIter != buildings.end() && roadIter != roads.end() && visitorIter != visitors.end();
		buildingIter++, roadIter++, visitorIter++)
	{
		switch (shiftDirection)
		{
		case Direction::Right:
		{
			(*buildingIter)->SetUpperLeft(PointCoord((*buildingIter)->GetUpperLeft().Get_x() + shiftValue, (*buildingIter)->GetUpperLeft().Get_y()));
			(*roadIter)->SetUpperLeft(PointCoord((*roadIter)->GetUpperLeft().Get_x() + shiftValue, (*roadIter)->GetUpperLeft().Get_y()));
			(*visitorIter)->SetUpperLeft(PointCoord((*visitorIter)->GetUpperLeft().Get_x() + shiftValue, (*visitorIter)->GetUpperLeft().Get_y()));
			break;
		}
		case Direction::Left:
		{
			(*buildingIter)->SetUpperLeft(PointCoord((*buildingIter)->GetUpperLeft().Get_x() - shiftValue, (*buildingIter)->GetUpperLeft().Get_y()));
			(*roadIter)->SetUpperLeft(PointCoord((*roadIter)->GetUpperLeft().Get_x() - shiftValue, (*roadIter)->GetUpperLeft().Get_y()));
			(*visitorIter)->SetUpperLeft(PointCoord((*visitorIter)->GetUpperLeft().Get_x() - shiftValue, (*visitorIter)->GetUpperLeft().Get_y()));
			break;
		}
		}
	}
}
void AllObjects::DisplayBuildings(Camera* camera_ptr) const
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	list<Building*>::const_iterator iter;
	for (iter = buildings.begin(); iter != buildings.end(); iter++)
	{
		int leftX = (*iter)->GetUpperLeft().Get_x();
		int topY = (*iter)->GetUpperLeft().Get_y();
		int rightX = (*iter)->GetUpperLeft().Get_x() + (*iter)->GetWidthAddition();
		int bottomY = (*iter)->GetUpperLeft().Get_y() + (*iter)->GetHeightAddition();
		if (leftX > cameraLeftX && rightX < cameraRightX && topY > cameraTopY && bottomY < cameraBottomY)
		{
			(*iter)->DrawObject();
			continue;
		}
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
			(*iter)->DrawPartly(leftX, rightX, topY, bottomY);
		}
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void AllObjects::SetRoadAndBuildingConnectionStatuses()
{
	PointCoord potentiallyRoad(0, 0);
	list<Building*>::iterator buildingIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		Direction exitDirection = (*buildingIter)->GetExitDirection();
		switch (exitDirection)
		{
		case Direction::Up: {potentiallyRoad.SetCoord(PointCoord((*buildingIter)->GetEntranceWidthAdd(), (*buildingIter)->GetEntranceHeightAdd() - 1)); break; }
		case Direction::Down: {potentiallyRoad.SetCoord(PointCoord((*buildingIter)->GetEntranceWidthAdd(), (*buildingIter)->GetEntranceHeightAdd() + 1)); break; }
		case Direction::Right: {potentiallyRoad.SetCoord(PointCoord((*buildingIter)->GetEntranceWidthAdd() + 1, (*buildingIter)->GetEntranceHeightAdd())); break; }
		case Direction::Left: {potentiallyRoad.SetCoord(PointCoord((*buildingIter)->GetEntranceWidthAdd() - 1, (*buildingIter)->GetEntranceHeightAdd())); break; }
		}
		list<Road*>::iterator roadIter;
		for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
		{
			if ((*roadIter)->GetUpperLeft() == potentiallyRoad)
			{
				(*roadIter)->SetGraphStatus(1);
				list<Building*>::iterator buildingIter2 = buildings.begin();
				do
				{
					PointCoord connectedRoad;
					switch ((*buildingIter)->GetExitDirection())
					{
					case Direction::Up: {connectedRoad = PointCoord((*buildingIter)->GetEntranceWidthAdd(), (*buildingIter)->GetEntranceHeightAdd() - 1); break; }
					case Direction::Down: {connectedRoad = PointCoord((*buildingIter)->GetEntranceWidthAdd(), (*buildingIter)->GetEntranceHeightAdd() + 1); break; }
					case Direction::Right: {connectedRoad = PointCoord((*buildingIter)->GetEntranceWidthAdd() + 1, (*buildingIter)->GetEntranceHeightAdd()); break; }
					case Direction::Left: {connectedRoad = PointCoord((*buildingIter)->GetEntranceWidthAdd() - 1, (*buildingIter)->GetEntranceHeightAdd()); break; }
					}
					if (connectedRoad == potentiallyRoad)
					{
						(*buildingIter2)->SetRoadConnectionStatus(1);
						break;
					}
					++buildingIter;
				} while (buildingIter != buildings.end());
			}

		}
	}
}
void AllObjects::VisitorAppear()
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
		vis_ptr = visitor_ptr = new Visitor(startVisitorPoint, food, pee, draw_ptr);
		visitors.push_back(visitor_ptr);
		draw_ptr->DrawVisitor((visitor_ptr->GetUpperLeft()).Get_x(), (visitor_ptr->GetUpperLeft()).Get_y());
	}
	cursor_ptr->SetCursorConsoleLocation();
}
bool AllObjects::LocationCheck(PointCoord point)
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
void AllObjects::DisplayVisitors()
{
	list< Visitor* >::iterator iter;
	for (iter = visitors.begin(); iter != visitors.end(); iter++)
	{
		PointCoord upperLeftVisitor = (*iter)->GetUpperLeft();
		draw_ptr->DrawVisitor(upperLeftVisitor.Get_x(), upperLeftVisitor.Get_y());
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
int AllObjects::RoadEnvironment(PointCoord point)
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
void AllObjects::DisplayRoads(Camera* camera_ptr)
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	list<Road*>::iterator iter;
	for (iter = roads.begin(); iter != roads.end(); iter++)
	{
		int leftX = (*iter)->GetUpperLeft().Get_x();
		int topY = (*iter)->GetUpperLeft().Get_y();
		int mask = RoadEnvironment((*iter)->GetUpperLeft());
		wstring roadSymbol = (*iter)->GetDescriptor()->GetConstructionSymbol(mask);
		if (leftX < cameraRightX && topY < cameraBottomY && leftX > cameraLeftX && topY > cameraTopY)
		{
			draw_ptr->DrawConstruction(leftX, topY, leftX, topY, roadSymbol, (*iter)->GetDescriptor()->GetForegroundColor(), (*iter)->GetDescriptor()->GetBackgroundColor());
		}
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void AllObjects::RedrawNeibourRoads(PointCoord roadUpperLeft)
{
	list<Road*>::iterator iter;
	PointCoord leftLocation(roadUpperLeft.Get_x() - 1, roadUpperLeft.Get_y());
	PointCoord rightLocation(roadUpperLeft.Get_x() + 1, roadUpperLeft.Get_y());
	PointCoord downLocation(roadUpperLeft.Get_x(), roadUpperLeft.Get_y() + 1);
	PointCoord topLocation(roadUpperLeft.Get_x(), roadUpperLeft.Get_y() - 1);
	for (iter = roads.begin(); iter != roads.end(); iter++)
	{
		if ((*iter)->GetUpperLeft() == leftLocation || (*iter)->GetUpperLeft() == rightLocation || (*iter)->GetUpperLeft() == downLocation || (*iter)->GetUpperLeft() == topLocation)
		{
			int mask = RoadEnvironment((*iter)->GetUpperLeft());
			(*iter)->DrawObject(mask);
		}
	}
}
void AllObjects::IsGraphRoadsOnly()
{
	list<Road*>::iterator iter;
	for (iter = roads.begin(); iter != roads.end(); iter++)
	{
		int mask = RoadEnvironment((*iter)->GetUpperLeft());
		(*iter)->DefineGraphStatus(mask);
	}
}