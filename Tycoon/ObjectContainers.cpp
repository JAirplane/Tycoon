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
		Draw_ptr->drawBuilding(ULBuilding.get_x(), ULBuilding.get_y(), ULBuilding.get_x() + widthadd, ULBuilding.get_y() + heightadd, (*iter)->getManager()->getBuildingSymbol());
	}
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
void AllRoads::setChainStatus()
{
	//////////////////////////////////
}