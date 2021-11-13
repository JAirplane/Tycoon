#pragma once
using namespace std;
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
///////////////All Buildings Class///////////////
void AllBuildings::CreateBuilding(char ChoosenBuilding)
{
	GlobalObject* GO_ptr = new IceCreamShop(PointCoord(C_ptr->getCursorConsoleLocation()));
	Buildings.push_back(GO_ptr);
	AllObjects_ptr->getAllObjects().push_back(GO_ptr);
	PointCoord pc1 = GO_ptr->getUpperLeft();
	PointCoord pc2 = GO_ptr->getBottomRight();
	Draw_ptr->drawBuilding(pc1.get_x(), pc1.get_y(), pc2.get_x(), pc2.get_y(), GO_ptr->getSymbol());
	C_ptr->setCursorConsoleLocation();
}
list< GlobalObject* >& AllBuildings::getAllBuildings()
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
		Draw_ptr->drawVisitor((V_ptr->getLocation()).get_x(), (V_ptr->getLocation()).get_y());
	}
}
bool AllVisitors::LocationCheck(PointCoord pc)
{
	list< Visitor* >::iterator iter;
	for (iter = Visitors.begin(); iter != Visitors.end(); iter++)
	{
		if (pc == (*iter)->getLocation())
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
///////////////AllRoads Class///////////////
void addRoad(Road* R_ptr)
{

}
list<Road*>& AllRoads::getAllRoads()
{
	return Roads;
}
int AllRoads::RoadEnvironment(PointCoord _pc)
{
	list< Road* >::iterator iter;
	PointCoord LeftLocation(_pc.get_x() - 1, _pc.get_y());
	PointCoord RightLocation(_pc.get_x() + 1, _pc.get_y());
	PointCoord UpLocation(_pc.get_x(), _pc.get_y() + 1);
	PointCoord DownLocation(_pc.get_x(), _pc.get_y() - 1);
	int RoadEnvironmentMask = 0;
	for (iter = Roads.begin(); iter != Roads.end(); iter++)
	{
		if ((*iter)->getRoadLocation() == LeftLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::LEFT);
		}
		if ((*iter)->getRoadLocation() == RightLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::RIGHT);
		}
		if ((*iter)->getRoadLocation() == UpLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::TOP);
		}
		if ((*iter)->getRoadLocation() == DownLocation)
		{
			RoadEnvironmentMask |= int(RoadMask::BOTTOM);
		}
	}
	return RoadEnvironmentMask;
}
char AllRoads::SetRoadSymbol(int mask) const
{
	char RoadSymbol = 'a';
	switch (mask)
	{
	case none: return RoadSymbol = '+';
	case leftside: return RoadSymbol = '+';
	case topside: return RoadSymbol = '+';
	case rightside: return RoadSymbol = '+';
	case bottomside: return RoadSymbol = '+';
	case vertical: return RoadSymbol = '+';
	case horizontal: return RoadSymbol = '+';
	case lefttop_angle: return RoadSymbol = '+';
	case righttop_angle: return RoadSymbol = '+';
	case leftbottom_angle: return RoadSymbol = '+';
	case rightbottom_angle: return RoadSymbol = '+';
	case right_T: return RoadSymbol = '+';
	case left_T: return RoadSymbol = '+';
	case top_T: return RoadSymbol = '+';
	case bottom_T: return RoadSymbol = '+';
	case cross: return RoadSymbol = '+';
	default: return RoadSymbol = '-';
	}
}