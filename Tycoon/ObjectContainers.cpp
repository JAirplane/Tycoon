#include "ObjectContainers.h"
/////////////Container of All Objects in the Game/////////////
list< GlobalObject* >& AllObjects::getAllObjects()
{
	return EveryObject;
}
void AllObjects::addObject(GlobalObject* obj_ptr)
{
	EveryObject.push_back(obj_ptr);
}
void AllObjects::addBeforePreliminary(GlobalObject* obj_ptr)
{
	list<GlobalObject*>::iterator it = EveryObject.end();
	--it;
	EveryObject.insert(it, obj_ptr);
}
void AllObjects::setLastElementFlag(bool changer)
{
	LastElementIsPreliminary = changer;
}
bool AllObjects::getLastElementFlag()
{
	return LastElementIsPreliminary;
}
GlobalObject* AllObjects::getPreliminaryElement()
{
	return EveryObject.back();
}
void AllObjects::ErasePreliminaryElement()
{
	EveryObject.pop_back();
}
BuildingType AllObjects::DefinePointerType(GlobalObject* go_ptr)
{
	Road* Test_ptr;
	if (Test_ptr = dynamic_cast<Road*>(go_ptr))
	{
		return BuildingType::Road;
	}
	else
	{
		return BuildingType::IceCreamShop;
	}
}
bool AllObjects::IsPartOfExistingObject(PointCoord _pc)
{
	list< GlobalObject* >::iterator iter;
	for (iter = EveryObject.begin(); iter != EveryObject.end(); iter++)
	{
		PointCoord UL = (*iter)->getUpperLeft();
		unsigned int height = (*iter)->getHeight();
		unsigned int width = (*iter)->getWidth();
		if (_pc.get_x() >= UL.get_x() && _pc.get_x() <= (UL.get_x() + width - 1) && _pc.get_y() >= UL.get_y() && _pc.get_y() <= (UL.get_y() + height - 1))
		{
			return true;
		}
	}
	return false;
}
///////////////All Buildings Class///////////////
void AllBuildings::addBuilding(Building* go_ptr)
{
	Buildings.push_back(go_ptr);
}
void AllBuildings::addBeforePreliminary(Building* obj_ptr)
{
	list<Building*>::iterator it = Buildings.end();
	--it;
	Buildings.insert(it, obj_ptr);
}
void AllBuildings::DisplayBuildings()
{
	list<Building*>::iterator iter;
	for (iter = Buildings.begin(); iter != Buildings.end(); iter++)
	{
		PointCoord ULBuilding = (*iter)->getUpperLeft();
		unsigned int height = (*iter)->getHeight();
		unsigned int width = (*iter)->getWidth();
		Draw_ptr->drawBuilding(ULBuilding.get_x(), ULBuilding.get_y(), ULBuilding.get_x() + width - 1, ULBuilding.get_y() + height - 1, (*iter)->getSymbol());
	}
}
void AllBuildings::EraseBuildings()
{
	list<Building*>::iterator iter;
	for (iter = Buildings.begin(); iter != Buildings.end(); iter++)
	{
		PointCoord ULBuilding = (*iter)->getUpperLeft();
		unsigned int height = (*iter)->getHeight();
		unsigned int width = (*iter)->getWidth();
		Draw_ptr->eraseBuilding(ULBuilding.get_x(), ULBuilding.get_y(), ULBuilding.get_x() + width - 1, ULBuilding.get_y() + height - 1);
	}
}
list<Building*>& AllBuildings::getAllBuildings()
{
	return Buildings;
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
		GlobalObject* Vis_ptr;
		Vis_ptr = V_ptr = new Visitor(StartVisitorPoint, food, pee);
		Visitors.push_back(V_ptr);
		AllObjects_ptr->addObject(Vis_ptr);
		Draw_ptr->drawVisitor((V_ptr->getUpperLeft()).get_x(), (V_ptr->getUpperLeft()).get_y());
	}
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
void AllRoads::addRoad(Road* go_ptr)
{
	Roads.push_back(go_ptr);
}
void AllRoads::addBeforePreliminary(Road* obj_ptr)
{
	list<Road*>::iterator it = Roads.end();
	--it;
	Roads.insert(it, obj_ptr);
}
list<Road*>& AllRoads::getAllRoads()
{
	return Roads;
}
int AllRoads::RoadEnvironment(PointCoord _pc)
{
	list<Road*>::iterator iter;
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
	list<Road*>::iterator iter;
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		PointCoord ULRoad = (*iter)->getUpperLeft();
		int mask1 = RoadEnvironment(ULRoad);
		char RoadSymbol = (*iter)->SetRoadSymbol(mask1);
		Draw_ptr->drawRoad(ULRoad.get_x(), ULRoad.get_y(), RoadSymbol);
	}
}
void AllRoads::EraseRoads()
{
	list< Road* >::iterator iter;
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		PointCoord ULRoad = (*iter)->getUpperLeft();
		Draw_ptr->erasePixel(ULRoad.get_x(), ULRoad.get_y());
	}
}
void AllRoads::IsGraph_RoadsOnly()
{
	list<Road*>::iterator iter;
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		int mask = RoadEnvironment((*iter)->getUpperLeft());
		(*iter)->DefineGraphStatus(mask);
	}
}
void AllRoads::setChainStatus()
{
	//////////////////////////////////
}