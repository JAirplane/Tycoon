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
	list< IngameObject* >::iterator iter;
	for (iter = EveryObject.begin(); iter != EveryObject.end(); iter++)
	{
		PointCoord UL = (*iter)->getUpperLeft();
		unsigned int heightadd = (*iter)->getHeightAddition();
		unsigned int widthadd = (*iter)->getWidthAddition();
		if (_pc.get_x() >= UL.get_x() && _pc.get_x() <= (UL.get_x() + widthadd) && _pc.get_y() >= UL.get_y() && _pc.get_y() <= (UL.get_y() + heightadd))
		{
			return true;
		}
	}
	return false;
}
///////////////All Buildings Class///////////////
void AllBuildings::addBuilding(Construction* go_ptr)
{
	Buildings.push_back(go_ptr);
}
void AllBuildings::DisplayBuildings()
{
	list<Construction*>::iterator iter;
	for (iter = Buildings.begin(); iter != Buildings.end(); iter++)
	{
		PointCoord ULBuilding = (*iter)->getUpperLeft();
		unsigned int heightadd = (*iter)->getHeightAddition();
		unsigned int widthadd = (*iter)->getWidthAddition();
		Draw_ptr->drawBuilding(ULBuilding.get_x(), ULBuilding.get_y(), ULBuilding.get_x() + widthadd, ULBuilding.get_y() + heightadd, (*iter)->getDescriptor()->getBuildingSymbol());
	}
	C_ptr->setCursorConsoleLocation();
}
void AllBuildings::EraseBuildings()
{
	list<Construction*>::iterator iter;
	for (iter = Buildings.begin(); iter != Buildings.end(); iter++)
	{
		PointCoord ULBuilding = (*iter)->getUpperLeft();
		unsigned int heightadd = (*iter)->getHeightAddition();
		unsigned int widthadd = (*iter)->getWidthAddition();
		Draw_ptr->eraseBuilding(ULBuilding.get_x(), ULBuilding.get_y(), ULBuilding.get_x() + widthadd, ULBuilding.get_y() + heightadd);
	}
}
const list<Construction*> AllBuildings::getAllBuildings()
{
	return Buildings;
}
vector<PointCoord> AllBuildings::getPotentialRoadCoords()
{
	vector<PointCoord> PotentiallyRoad;
	list<Construction*>::iterator iter;
	for (iter = Buildings.begin(); iter != Buildings.end(); iter++)
	{
		PointCoord Entrance = (*iter)->getEntrance();
		Direction ExitDir = (*iter)->getExitDirection();
		switch (ExitDir)
		{
		case Direction::Up: {PotentiallyRoad.push_back(PointCoord(Entrance.get_x(), Entrance.get_y() - 1)); break; }
		case Direction::Down: {PotentiallyRoad.push_back(PointCoord(Entrance.get_x(), Entrance.get_y() + 1)); break; }
		case Direction::Right: {PotentiallyRoad.push_back(PointCoord(Entrance.get_x() + 1, Entrance.get_y())); break; }
		case Direction::Left: {PotentiallyRoad.push_back(PointCoord(Entrance.get_x() - 1, Entrance.get_y())); break; }
		}
	}
	return PotentiallyRoad;
}
void AllBuildings::setRoadConnectionStatus(vector<PointCoord> connectedroads)
{
	vector<PointCoord>::iterator pointiter;
	list<Construction*>::iterator buildingiter;
	for (pointiter = connectedroads.begin(); pointiter != connectedroads.end(); pointiter++)
	{
		buildingiter = Buildings.begin();
		do
		{
			PointCoord connectedroad;
			switch ((*buildingiter)->getExitDirection())
			{
			case Direction::Up: {connectedroad = PointCoord((*buildingiter)->getEntrance().get_x(), (*buildingiter)->getEntrance().get_y() - 1); break; }
			case Direction::Down: {connectedroad = PointCoord((*buildingiter)->getEntrance().get_x(), (*buildingiter)->getEntrance().get_y() + 1); break; }
			case Direction::Right: {connectedroad = PointCoord((*buildingiter)->getEntrance().get_x() + 1, (*buildingiter)->getEntrance().get_y()); break; }
			case Direction::Left: {connectedroad = PointCoord((*buildingiter)->getEntrance().get_x() - 1, (*buildingiter)->getEntrance().get_y()); break; }
			}
			if (connectedroad == (*pointiter))
			{
				(*buildingiter)->setRoadConnectionStatus(1);
				break;
			}
			++buildingiter;
		} while (buildingiter != Buildings.end());
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
		Draw_ptr->drawVisitor((V_ptr->getUpperLeft()).get_x(), (V_ptr->getUpperLeft()).get_y());
	}
	C_ptr->setCursorConsoleLocation();
}
bool AllVisitors::LocationCheck(PointCoord pc)
{
	list< Visitor* >::iterator iter;
	for (iter = Visitors.begin(); iter != Visitors.end(); iter++)
	{
		if (pc == (*iter)->getUpperLeft())
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
		PointCoord ULVisitor = (*iter)->getUpperLeft();
		Draw_ptr->drawVisitor(ULVisitor.get_x(), ULVisitor.get_y());
	}
	C_ptr->setCursorConsoleLocation();
}
void AllVisitors::EraseVisitors()
{
	list< Visitor* >::iterator iter;
	for (iter = Visitors.begin(); iter != Visitors.end(); iter++)
	{
		PointCoord ULVisitor = (*iter)->getUpperLeft();
		Draw_ptr->erasePixel(ULVisitor.get_x(), ULVisitor.get_y());
	}
}
///////////////AllRoads Class///////////////
void AllRoads::addRoad(Construction* go_ptr)
{
	Roads.push_back(go_ptr);
}
list<Construction*>& AllRoads::getAllRoads()
{
	return Roads;
}
int AllRoads::RoadEnvironment(PointCoord _pc)
{
	list<Construction*>::iterator iter;
	PointCoord LeftLocation(_pc.get_x() - 1, _pc.get_y());
	PointCoord RightLocation(_pc.get_x() + 1, _pc.get_y());
	PointCoord UpLocation(_pc.get_x(), _pc.get_y() + 1);
	PointCoord DownLocation(_pc.get_x(), _pc.get_y() - 1);
	int RoadEnvironmentMask = 0;
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		if ((*iter)->getUpperLeft() == LeftLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::LEFT);
		}
		if ((*iter)->getUpperLeft() == RightLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::RIGHT);
		}
		if ((*iter)->getUpperLeft() == UpLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::TOP);
		}
		if ((*iter)->getUpperLeft() == DownLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::BOTTOM);
		}
	}
	return RoadEnvironmentMask;
}
void AllRoads::DisplayRoads()
{
	list<Construction*>::iterator iter;
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		PointCoord ULRoad = (*iter)->getUpperLeft();
		int mask1 = RoadEnvironment(ULRoad);
		char RoadSymbol = (*iter)->SetRoadSymbol(mask1);
		Draw_ptr->drawRoad(ULRoad.get_x(), ULRoad.get_y(), RoadSymbol);
	}
	C_ptr->setCursorConsoleLocation();
}
void AllRoads::EraseRoads()
{
	list<Construction*>::iterator iter;
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		PointCoord ULRoad = (*iter)->getUpperLeft();
		Draw_ptr->erasePixel(ULRoad.get_x(), ULRoad.get_y());
	}
}
void AllRoads::IsGraph_RoadsOnly()
{
	list<Construction*>::iterator iter;
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		int mask = RoadEnvironment((*iter)->getUpperLeft());
		(*iter)->DefineGraphStatus(mask);
	}
}
vector<PointCoord> AllRoads::RoadConnectedToEntranceCheck(vector<PointCoord> possibleroads)
{
	list<Construction*>::iterator roaditer;
	vector<PointCoord>::iterator pointiter;
	vector<PointCoord> RoadsNearBuildingEntrance;
	for (roaditer = Roads.begin(); roaditer != Roads.end(); roaditer++)
	{
		for (pointiter = possibleroads.begin(); pointiter != possibleroads.end(); pointiter++)
		{
			if ((*roaditer)->getUpperLeft() == (*pointiter))
			{
				(*roaditer)->setGraphStatus(1);
				RoadsNearBuildingEntrance.push_back((*roaditer)->getUpperLeft());
			}
		}
	}
	return RoadsNearBuildingEntrance;
}
void AllRoads::setChainStatus()
{
	//////////////////////////////////
}