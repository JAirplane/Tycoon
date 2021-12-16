#include "ObjectContainers.h"
/////////////Container of All Objects in the Game/////////////
list<IngameObject*>& AllObjects::getAllObjects()
{
	return EveryObject;
}
void AllObjects::addObject(IngameObject* obj_ptr)
{
	EveryObject.push_back(obj_ptr);
}
void AllObjects::addObject(IngameObject* obj_ptr, int _position)
{
	if (EveryObject.size() < _position)
	{
		EveryObject.push_back(obj_ptr);
	}
	else
	{
		list<IngameObject*>::iterator it = EveryObject.begin();
		it = next(it, _position - 1);
		EveryObject.insert(it, obj_ptr);
	}
}
void AllObjects::setLastElementFlag(bool changer)
{
	LastElementIsPreliminary = changer;
}
bool AllObjects::getLastElementFlag()
{
	return LastElementIsPreliminary;
}
IngameObject* AllObjects::getPreliminaryElement()
{
	return EveryObject.back();
}
void AllObjects::ErasePreliminaryElement()
{
	EveryObject.pop_back();
}
bool AllObjects::IsPartOfExistingObject(PointCoord _pc)
{
	list<IngameObject*>::iterator iter;
	for (iter = EveryObject.begin(); iter != EveryObject.end(); iter++)
	{
		PointCoord UL = (*iter)->GetUpperLeft();
		unsigned int heightadd = (*iter)->GetHeightAddition();
		unsigned int widthadd = (*iter)->GetWidthAddition();
		if (_pc.Get_x() >= UL.Get_x() && _pc.Get_x() <= (UL.Get_x() + widthadd) && _pc.Get_y() >= UL.Get_y() && _pc.Get_y() <= (UL.Get_y() + heightadd))
		{
			return true;
		}
	}
	return false;
}
bool AllObjects::IsPartOfExistingObject(IngameObject* object_ptr, int camera_left_x, int camera_right_x, int camera_up_y, int camera_bottom_y)
{
	list<IngameObject*>::iterator iter;
	int x_coord = object_ptr->GetUpperLeft().Get_x();
	int y_coord = object_ptr->GetUpperLeft().Get_y();
	int objectheightadd = object_ptr->GetHeightAddition();
	int objectwidthadd = object_ptr->GetWidthAddition();
	for (y_coord; y_coord <= object_ptr->GetUpperLeft().Get_y() + objectheightadd; y_coord++)
	{
		for (x_coord; x_coord <= object_ptr->GetUpperLeft().Get_x() + objectwidthadd; x_coord++)
		{
			if (y_coord == object_ptr->GetUpperLeft().Get_y() || y_coord == object_ptr->GetUpperLeft().Get_y() + objectheightadd,
				x_coord == object_ptr->GetUpperLeft().Get_x() || x_coord == object_ptr->GetUpperLeft().Get_x() + objectwidthadd)
			{
				for (iter = EveryObject.begin(); iter != EveryObject.end(); iter++)
				{
					if (object_ptr != (*iter))
					{
						PointCoord UL = (*iter)->GetUpperLeft();
						unsigned int heightadd = (*iter)->GetHeightAddition();
						unsigned int widthadd = (*iter)->GetWidthAddition();
						if (x_coord >= UL.Get_x() && x_coord <= (UL.Get_x() + widthadd) && y_coord >= UL.Get_y() && y_coord <= (UL.Get_y() + heightadd))
						{
							return true;
						}
					}
				}
			}
			if (y_coord == camera_up_y || y_coord == camera_bottom_y || x_coord == camera_left_x || x_coord == camera_right_x)
			{
				return true;
			}
		}
		x_coord = object_ptr->GetUpperLeft().Get_x();
	}

	return false;
}
void AllObjects::EraseObjects()
{
	list<IngameObject*>::iterator iter;
	int camera_left_x = camera_ptr->GetUpperLeft().Get_x();
	int camera_top_y = camera_ptr->GetUpperLeft().Get_y();
	int camera_right_x = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int camera_bottom_y = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	for (iter = EveryObject.begin; iter != EveryObject.end(); iter++)
	{
		int left_x = (*iter)->GetUpperLeft().Get_x();
		int top_y = (*iter)->GetUpperLeft().Get_y();
		int right_x = (*iter)->GetUpperLeft().Get_x() + (*iter)->GetWidthAddition();
		int bottom_y = (*iter)->GetUpperLeft().Get_y() + (*iter)->GetHeightAddition();
		if (left_x <= camera_left_x && right_x > camera_left_x)
		{
			left_x = camera_left_x + 1;
		}
		if (top_y <= camera_top_y && bottom_y > camera_top_y)
		{
			top_y = camera_top_y + 1;
		}
		if (right_x >= camera_right_x && left_x < camera_right_x)
		{
			right_x = camera_right_x - 1;
		}
		if (bottom_y >= camera_bottom_y && top_y < camera_bottom_y)
		{
			bottom_y = camera_bottom_y - 1;
		}
		if (left_x < camera_right_x && top_y < camera_bottom_y && right_x > camera_left_x && bottom_y > camera_top_y)
		{
			draw_ptr->EraseConstruction(left_x, top_y, right_x, bottom_y);
		}
	}
}
///////////////All buildings Class///////////////
void Allbuildings::AddBuilding(Building* go_ptr)
{
	buildings.push_back(go_ptr);
}
void Allbuildings::DisplayBuildings()
{
	list<Building*>::iterator iter;
	int camera_left_x = camera_ptr->GetUpperLeft().Get_x();
	int camera_top_y = camera_ptr->GetUpperLeft().Get_y();
	int camera_right_x = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int camera_bottom_y = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	for (iter = buildings.begin(); iter != buildings.end(); iter++)
	{
		int left_x = (*iter)->GetUpperLeft().Get_x();
		int top_y = (*iter)->GetUpperLeft().Get_y();
		int right_x = (*iter)->GetUpperLeft().Get_x() + (*iter)->GetWidthAddition();
		int bottom_y = (*iter)->GetUpperLeft().Get_y() + (*iter)->GetHeightAddition();
		if (left_x <= camera_left_x && right_x > camera_left_x)
		{
			left_x = camera_left_x + 1;
		}
		if (top_y <= camera_top_y && bottom_y > camera_top_y)
		{
			top_y = camera_top_y + 1;
		}
		if (right_x >= camera_right_x && left_x < camera_right_x)
		{
			right_x = camera_right_x - 1;
		}
		if (bottom_y >= camera_bottom_y && top_y < camera_bottom_y)
		{
			bottom_y = camera_bottom_y - 1;
		}
		if (left_x < camera_right_x && top_y < camera_bottom_y && right_x > camera_left_x && bottom_y > camera_top_y)
		{
			draw_ptr->DrawConstruction(left_x, top_y, right_x, bottom_y, (*iter)->GetDescriptor()->GetBuildingSymbol(),
				(*iter)->GetDescriptor()->GetForegroundColor(), (*iter)->GetDescriptor()->GetBackgroundColor());
		}
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
const list<Building*> Allbuildings::getAllbuildings()
{
	return buildings;
}
vector<PointCoord> Allbuildings::getPotentialRoadCoords()
{
	vector<PointCoord> PotentiallyRoad;
	list<Building*>::iterator iter;
	for (iter = buildings.begin(); iter != buildings.end(); iter++)
	{
		PointCoord Entrance = (*iter)->getEntrance();
		Direction ExitDir = (*iter)->getExitDirection();
		switch (ExitDir)
		{
		case Direction::Up: {PotentiallyRoad.push_back(PointCoord(Entrance.Get_x(), Entrance.Get_y() - 1)); break; }
		case Direction::Down: {PotentiallyRoad.push_back(PointCoord(Entrance.Get_x(), Entrance.Get_y() + 1)); break; }
		case Direction::Right: {PotentiallyRoad.push_back(PointCoord(Entrance.Get_x() + 1, Entrance.Get_y())); break; }
		case Direction::Left: {PotentiallyRoad.push_back(PointCoord(Entrance.Get_x() - 1, Entrance.Get_y())); break; }
		}
	}
	return PotentiallyRoad;
}
void Allbuildings::setRoadConnectionStatus(vector<PointCoord> connectedroads)
{
	vector<PointCoord>::iterator pointiter;
	list<Building*>::iterator buildingiter;
	for (pointiter = connectedroads.begin(); pointiter != connectedroads.end(); pointiter++)
	{
		buildingiter = buildings.begin();
		do
		{
			PointCoord connectedroad;
			switch ((*buildingiter)->getExitDirection())
			{
			case Direction::Up: {connectedroad = PointCoord((*buildingiter)->getEntrance().Get_x(), (*buildingiter)->getEntrance().Get_y() - 1); break; }
			case Direction::Down: {connectedroad = PointCoord((*buildingiter)->getEntrance().Get_x(), (*buildingiter)->getEntrance().Get_y() + 1); break; }
			case Direction::Right: {connectedroad = PointCoord((*buildingiter)->getEntrance().Get_x() + 1, (*buildingiter)->getEntrance().Get_y()); break; }
			case Direction::Left: {connectedroad = PointCoord((*buildingiter)->getEntrance().Get_x() - 1, (*buildingiter)->getEntrance().Get_y()); break; }
			}
			if (connectedroad == (*pointiter))
			{
				(*buildingiter)->setRoadConnectionStatus(1);
				break;
			}
			++buildingiter;
		} while (buildingiter != buildings.end());
	}
}
///////////////AllVisitors Class///////////////
void AllVisitors::VisitorAppear()
{
	int random_x = rand() % 5 + 1; //5 possible cells to appear
	const int const_y = 80; //80 is example, depends on entrance in a world map, but const
	PointCoord StartVisitorPoint(random_x, const_y);
	if (LocationCheck(StartVisitorPoint))
	{
		int food = 100;
		int pee = 100;
		Visitor* V_ptr;
		IngameObject* Vis_ptr;
		Vis_ptr = V_ptr = new Visitor(StartVisitorPoint, food, pee);
		Visitors.push_back(V_ptr);
		AllObjects_ptr->addObject(Vis_ptr);
		draw_ptr->drawVisitor((V_ptr->GetUpperLeft()).Get_x(), (V_ptr->GetUpperLeft()).Get_y());
	}
	cursor_ptr->setCursorConsoleLocation();
}
bool AllVisitors::LocationCheck(PointCoord pc)
{
	list< Visitor* >::iterator iter;
	for (iter = Visitors.begin(); iter != Visitors.end(); iter++)
	{
		if (pc == (*iter)->GetUpperLeft())
		{
			return 0;
		}
	}
	return 1;
}
list<Visitor*>& AllVisitors::getAllVisitors()
{
	return Visitors;
}
void AllVisitors::DisplayVisitors()
{
	list< Visitor* >::iterator iter;
	for (iter = Visitors.begin(); iter != Visitors.end(); iter++)
	{
		PointCoord ULVisitor = (*iter)->GetUpperLeft();
		draw_ptr->drawVisitor(ULVisitor.Get_x(), ULVisitor.Get_y());
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
///////////////AllRoads Class///////////////
void AllRoads::addRoad(Road* go_ptr)
{
	Roads.push_back(go_ptr);
}
list<Road*>& AllRoads::getAllRoads()
{
	return Roads;
}
int AllRoads::RoadEnvironment(PointCoord _pc)
{
	list<Road*>::iterator iter;
	PointCoord LeftLocation(_pc.Get_x() - 1, _pc.Get_y());
	PointCoord RightLocation(_pc.Get_x() + 1, _pc.Get_y());
	PointCoord DownLocation(_pc.Get_x(), _pc.Get_y() + 1);
	PointCoord UpLocation(_pc.Get_x(), _pc.Get_y() - 1);
	int RoadEnvironmentMask = 0;
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		if ((*iter)->GetUpperLeft() == LeftLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::LEFT);
		}
		if ((*iter)->GetUpperLeft() == RightLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::RIGHT);
		}
		if ((*iter)->GetUpperLeft() == UpLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::TOP);
		}
		if ((*iter)->GetUpperLeft() == DownLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::BOTTOM);
		}
	}
	return RoadEnvironmentMask;
}
void AllRoads::DisplayRoads()
{
	list<Road*>::iterator iter;
	int camera_left_x = camera_ptr->GetUpperLeft().Get_x();
	int camera_top_y = camera_ptr->GetUpperLeft().Get_y();
	int camera_right_x = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int camera_bottom_y = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		int left_x = (*iter)->GetUpperLeft().Get_x();
		int top_y = (*iter)->GetUpperLeft().Get_y();
		int right_x = (*iter)->GetUpperLeft().Get_x() + (*iter)->GetWidthAddition();
		int bottom_y = (*iter)->GetUpperLeft().Get_y() + (*iter)->GetHeightAddition();
		int mask1 = RoadEnvironment(ULRoad);
		char RoadSymbol = (*iter)->SetRoadSymbol(mask1);
		if (left_x <= camera_left_x && right_x > camera_left_x)
		{
			left_x = camera_left_x + 1;
		}
		if (top_y <= camera_top_y && bottom_y > camera_top_y)
		{
			top_y = camera_top_y + 1;
		}
		if (right_x >= camera_right_x && left_x < camera_right_x)
		{
			right_x = camera_right_x - 1;
		}
		if (bottom_y >= camera_bottom_y && top_y < camera_bottom_y)
		{
			bottom_y = camera_bottom_y - 1;
		}
		if (left_x < camera_right_x && top_y < camera_bottom_y && right_x > camera_left_x && bottom_y > camera_top_y)
		{
			draw_ptr->DrawConstruction(left_x, top_y, right_x, bottom_y, RoadSymbol, (*iter)->GetDescriptor()->GetForegroundColor(), (*iter)->GetDescriptor()->GetBackgroundColor());
		}
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void AllRoads::RedrawRoads(Road* r_ptr)
{
	int roadmask = RoadEnvironment(r_ptr->GetUpperLeft());
	unsigned char roadsymbol = r_ptr->SetRoadSymbol(roadmask);
	list<Road*>::iterator iter;
	PointCoord LeftLocation(r_ptr->GetUpperLeft().Get_x() - 1, r_ptr->GetUpperLeft().Get_y());
	PointCoord RightLocation(r_ptr->GetUpperLeft().Get_x() + 1, r_ptr->GetUpperLeft().Get_y());
	PointCoord DownLocation(r_ptr->GetUpperLeft().Get_x(), r_ptr->GetUpperLeft().Get_y() + 1);
	PointCoord UpLocation(r_ptr->GetUpperLeft().Get_x(), r_ptr->GetUpperLeft().Get_y() - 1);
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		if ((*iter)->GetUpperLeft() == LeftLocation || (*iter)->GetUpperLeft() == RightLocation || (*iter)->GetUpperLeft() == DownLocation || (*iter)->GetUpperLeft() == UpLocation)
		{
			int sideroadmask = RoadEnvironment((*iter)->GetUpperLeft());
			unsigned char sideroadsymbol = (*iter)->SetRoadSymbol(sideroadmask);
			PointCoord UL = (*iter)->GetUpperLeft();
			int heightadd = (*iter)->GetHeightAddition();
			int widthadd = (*iter)->GetWidthAddition();
			draw_ptr->DrawConstruction(UL.Get_x(), UL.Get_y(), UL.Get_x() + widthadd, UL.Get_y() + heightadd, sideroadsymbol, (*iter)->GetDescriptor()->GetForegroundColor(), (*iter)->GetDescriptor()->GetBackgroundColor());
		}
	}
	PointCoord CentralUL = r_ptr->GetUpperLeft();
	int centralroadheightadd = r_ptr->GetHeightAddition();
	int centralroadwidthadd = r_ptr->GetWidthAddition();
	draw_ptr->DrawConstruction(CentralUL.Get_x(), CentralUL.Get_y(), CentralUL.Get_x() + centralroadwidthadd, CentralUL.Get_y() + centralroadheightadd, roadsymbol,
		r_ptr->GetDescriptor()->GetForegroundColor(), r_ptr->GetDescriptor()->GetBackgroundColor());
}
void AllRoads::IsGraph_RoadsOnly()
{
	list<Road*>::iterator iter;
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		int mask = RoadEnvironment((*iter)->GetUpperLeft());
		(*iter)->DefineGraphStatus(mask);
	}
}
vector<PointCoord> AllRoads::RoadConnectedToEntranceCheck(vector<PointCoord> possibleroads)
{
	list<Road*>::iterator roaditer;
	vector<PointCoord>::iterator pointiter;
	vector<PointCoord> RoadsNearBuildingEntrance;
	for (roaditer = Roads.begin(); roaditer != Roads.end(); roaditer++)
	{
		for (pointiter = possibleroads.begin(); pointiter != possibleroads.end(); pointiter++)
		{
			if ((*roaditer)->GetUpperLeft() == (*pointiter))
			{
				(*roaditer)->setGraphStatus(1);
				RoadsNearBuildingEntrance.push_back((*roaditer)->GetUpperLeft());
			}
		}
	}
	return RoadsNearBuildingEntrance;
}
void AllRoads::setChainStatus()
{
	//////////////////////////////////
}