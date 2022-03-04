#include "ObjectContainers.h"
/////////////Containers of All Objects in the Game/////////////
const list<Building*>& AllObjects::GetAllBuildings() const
{
	return buildings;
}
const list<Road*>& AllObjects::GetAllRoads() const
{
	return roads;
}
size_t AllObjects::GetBuildingsQuantity() const
{
	return buildings.size();
}
size_t AllObjects::GetRoadsQuantity() const
{
	return roads.size();
}
size_t AllObjects::GetVisitorsQuantity() const
{
	return visitors.size();
}
void AllObjects::AddObject(Building* obj_ptr)
{
	if(obj_ptr == nullptr)
	{
		throw MyException("AllObjects::AddObject(Building* obj_ptr) received nullptr argument.");
	}
	buildings.push_back(obj_ptr);
}
void AllObjects::AddObject(Road* obj_ptr)
{
	if(obj_ptr == nullptr)
	{
		throw MyException("AllObjects::AddObject(Road* obj_ptr) received nullptr argument.");
	}
	roads.push_back(obj_ptr);
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
void AllObjects::AddPreliminaryElement(Construction* preliminary_ptr)
{
	if(preliminary_ptr == nullptr)
	{
		throw MyException("AllObjects::AddPreliminaryElement(Construction* preliminary_ptr) received nullptr argument.");
	}
	if(preliminaryConstruction_ptr == nullptr)
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
			PointCoord preliminaryElementNeibourRedraw = preliminaryConstruction_ptr->GetRedrawNeiboursPoint();
			delete preliminaryConstruction_ptr;
			preliminaryConstruction_ptr = nullptr;
			Construction::RedrawNeibours(preliminaryElementNeibourRedraw, roads, buildings, preliminaryConstruction_ptr, camera_ptr);
			return;
		}
		delete preliminaryConstruction_ptr;
		preliminaryConstruction_ptr = nullptr;
	}
}
bool AllObjects::RectangleImposition(PointCoord point, const MyRectangle* rect_ptr) const
{
	if(rect_ptr == nullptr)
	{
		throw MyException("AllObjects::RectangleImposition(PointCoord point, MyRectangle* rect_ptr) received nullptr argument rect_ptr.");
	}
	int rectangleLeftX = rect_ptr->GetUpperLeft().Get_x();
	int rectangleRightX = rectangleLeftX + rect_ptr->GetWidthAddition();
	int rectangleTopY = rect_ptr->GetUpperLeft().Get_y();
	int rectangleBottomY = rectangleTopY + rect_ptr->GetHeightAddition();
	if (((rectangleLeftX == point.Get_x() || rectangleRightX == point.Get_x()) && rectangleTopY <= point.Get_y() && rectangleBottomY >= point.Get_y()) ||
		((rectangleTopY == point.Get_y() || rectangleBottomY == point.Get_y()) && rectangleLeftX <= point.Get_x() && rectangleRightX >= point.Get_x()))
	{
		return true;
	}
	return false;
}
bool AllObjects::RectangleImposition(IngameObject* object_ptr, const MyRectangle* rect_ptr) const
{
	if(rect_ptr == nullptr)
	{
		throw MyException("AllObjects::RectangleImposition(IngameObject* object_ptr, MyRectangle* rect_ptr) received nullptr argument rect_ptr.");
	}
	if(object_ptr == nullptr)
	{
		throw MyException("AllObjects::RectangleImposition(IngameObject* object_ptr, MyRectangle* rect_ptr) received nullptr argument object_ptr.");
	}
	int rectangleLeftX = rect_ptr->GetUpperLeft().Get_x();
	int rectangleRightX = rectangleLeftX + rect_ptr->GetWidthAddition();
	int rectangleTopY = rect_ptr->GetUpperLeft().Get_y();
	int rectangleBottomY = rectangleTopY + rect_ptr->GetHeightAddition();
	int xCoord = object_ptr->GetUpperLeft().Get_x();
	int yCoord = object_ptr->GetUpperLeft().Get_y();
	int objectHeightAdd = object_ptr->GetHeightAddition();
	int objectWidthAdd = object_ptr->GetWidthAddition();
	for (yCoord; yCoord <= object_ptr->GetUpperLeft().Get_y() + objectHeightAdd; yCoord++)
	{
		for (xCoord; xCoord <= object_ptr->GetUpperLeft().Get_x() + objectWidthAdd; xCoord++)
		{
			if (yCoord <= rectangleTopY || yCoord >= rectangleBottomY || xCoord <= rectangleLeftX || xCoord >= rectangleRightX)
			{
				return true;
			}
		}
		xCoord = object_ptr->GetUpperLeft().Get_x();
	}
	return false;
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
	if(object_ptr == nullptr)
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
	if(object_ptr == nullptr)
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
			if (yCoord == object_ptr->GetUpperLeft().Get_y() || yCoord == object_ptr->GetUpperLeft().Get_y() + objectHeightAdd,
				xCoord == object_ptr->GetUpperLeft().Get_x() || xCoord == object_ptr->GetUpperLeft().Get_x() + objectWidthAdd)
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
	if(object_ptr == nullptr)
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
	if(RectangleImposition(point, field_ptr))
	{
		return true;
	}
	if(BuildingsImposition(point))
	{
		return true;
	}
	if(RoadsImposition(point))
	{
		return true;
	}
	if(VisitorsImposition(point))
	{
		return true;
	}
	return false;
}
bool AllObjects::ObjectImposition(IngameObject* object_ptr, const Camera* camera_ptr, const PlayingField* field_ptr) const
{
	if(RectangleImposition(object_ptr, camera_ptr))
	{
		return true;
	}
	if(RectangleImposition(object_ptr, field_ptr))
	{
		return true;
	}
	if(BuildingsImposition(object_ptr))
	{
		return true;
	}
	if(RoadsImposition(object_ptr))
	{
		return true;
	}
	if(VisitorsImposition(object_ptr))
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
void AllObjects::DisplayBuildings(Camera* camera_ptr, PlayingField* field_ptr) const
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	list<Building*>::const_iterator buildingIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		if (!RectangleImposition((*buildingIter), field_ptr))
		{
			(*buildingIter)->DrawObject(0, cameraLeftX, cameraTopY, cameraRightX, cameraBottomY);
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
}
void AllObjects::DisplayRoads(Camera* camera_ptr, PlayingField* field_ptr)
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
	list<Building*>::const_iterator buildingIter;
	for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
	{
		for(int yCoord = (*buildingIter)->GetUpperLeft().Get_y(); yCoord <= (*buildingIter)->GetUpperLeft().Get_y() + (*buildingIter)->GetHeightAddition(); yCoord++)
		{
			for(int xCoord = (*buildingIter)->GetUpperLeft().Get_x(); xCoord <= (*buildingIter)->GetUpperLeft().Get_x() + (*buildingIter)->GetWidthAddition(); xCoord++)
			{
				if(PointCoord(xCoord, yCoord) == location)
				{
					return (*buildingIter);
				}
			}
		}
	}
	list<Road*>::const_iterator roadIter;
	for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
	{
		if((*roadIter)->GetUpperLeft() == location)
				{
					return (*roadIter);
				}
	}
	return nullptr;
}
void AllObjects::DeleteConstruction(Construction* forDeleting, function<bool(Construction*)> IsEqual)
{
	buildings.remove_if(IsEqual);
	roads.remove_if(IsEqual); //not quite correct?
}