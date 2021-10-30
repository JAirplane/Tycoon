#pragma once
#include "logicheader.h"
#include "msoftcon.h"
#include <cstdlib>
using namespace std;
///////////////PointCoord Struct///////////////
int PointCoord::get_x() const
{
	return x_coord;
}
int PointCoord::get_y() const
{
	return y_coord;
}
void PointCoord::set_coord(int x, int y)
{
	x_coord = x;
	y_coord = y;
}
bool PointCoord::operator == (PointCoord pc)
{
	return (x_coord == pc.x_coord && y_coord == pc.y_coord);
}
///////////////Visitor Class///////////////
PointCoord Visitor::getLocation()
{
	return GlobalObject::getUpperLeft();
}
void Visitor::VisitorMove(int x, int y)
{
	GlobalObject::setUpperLeft(PointCoord(x, y));
	GlobalObject::setBottomRight(PointCoord(x, y));
}
///////////////AllCurrentVisitors Class///////////////
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
		Draw_ptr->drawVisitor();
	}
}
bool AllVisitors::LocationCheck(PointCoord pc)
{
	vector< Visitor* >::iterator iter;
	for (iter = Visitors.begin(); iter != Visitors.end(); iter++)
	{
		if (pc == (*iter)->getLocation())
		{
			return 0;
		}
	}
	return 1;
}
///////////////Cursor Class///////////////
PointCoord Cursor::getCursorConsoleLocation()
{
	return CursorConsoleLocation;
}
void Cursor::setCursorConsoleLocation()
{
	CursorConsoleLocation = GetConsoleCursorPosition();
}
void Cursor::CursorShift(ShiftDirection SD)
{
	switch (SD)
	{
	case ShiftDirection::Right:
	{
		Xshift += 1;
		break;
	}
	case ShiftDirection::Down:
	{
		Yshift -= 1;
		break;
	}
	case ShiftDirection::Left:
	{
		Xshift -= 1;
		break;
	}
	case ShiftDirection::Up:
	{
		Yshift += 1;
		break;
	}
	}
}
///////////////All Types of Objects Class///////////////
PointCoord GlobalObject::getUpperLeft() const
{
	return UpperLeft;
}
PointCoord GlobalObject::getBottomRight()
{
	return BottomRight;
}
void GlobalObject::setUpperLeft(PointCoord pc)
{
	UpperLeft.set_coord(pc.get_x(), pc.get_y());
}
void GlobalObject::setBottomRight(PointCoord pc)
{
	BottomRight.set_coord(pc.get_x(), pc.get_y());
}
const char GlobalObject::getSymbol()
{
	return 0;
}
///////////////Ice Cream Shop Class///////////////
const int IceCreamShop::ConstructionCost = 250;
const int IceCreamShop::DailyExpences = 20;
const char IceCreamShop::drawConstructionSymbol = '!';
const char IceCreamShop::getSymbol()
{
	return drawConstructionSymbol;
}
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
	PointCoord pc1 = GO_ptr->getUpperLeft();
	PointCoord pc2 = GO_ptr->getBottomRight();
	Draw_ptr -> drawBuilding(pc1.get_x(), pc1.get_y(), pc2.get_x(), pc2.get_y(), GO_ptr->getSymbol());
}
list< GlobalObject* >& AllBuildings::getAllBuildings()
{
	return Buildings;
}
///////////////Road Class///////////////
const int Road::RoadCost = 50;
const char Road::drawRoadSymbol = 'r';
const int Road::getRoadCost()
{
	return RoadCost;
}
const char Road::getRoadSymbol() const
{
	return drawRoadSymbol;
}
PointCoord Road::getRoadLocation() const
{
	return GlobalObject::getUpperLeft();
}
void Road::setRoadLocation(PointCoord loc)
{
	GlobalObject::setUpperLeft(loc);
}
///////////////AllRoads Class///////////////
void addRoad(Road* R_ptr)
{

}
///////////////WorldMap Class///////////////
void WorldMap::drawMapBorders()
{
	Draw_ptr -> drawWorld();
}
void WorldMap::GameProcess()
{
	char ch = 'a';
	ShiftDirection SD;
	drawMapBorders();
	set_cursor_pos(5, 5);
	C_ptr->setCursorConsoleLocation();
	Buildings_ptr->CreateBuilding(ch);
	while (true)
	{
		SD = VM_ptr->CursorBordersCheck(C_ptr);
		Shift(SD, AllObjects_ptr->getAllObjects());
		drawAll(AllObjects_ptr->getAllObjects());
	}
}
void WorldMap::Shift(ShiftDirection SD, list< GlobalObject* >& allobjects)
{
	if (SD != ShiftDirection::Middle)
	{
		C_ptr->CursorShift(SD);
		list< GlobalObject* >::iterator iter;
		for (iter = allobjects.begin(); iter != allobjects.end(); iter++)
		{
			PointCoord ul = (*iter)->getUpperLeft();
			PointCoord br = (*iter)->getBottomRight();
			switch (SD)
			{
			case ShiftDirection::Right:
			{
				ul.set_coord(ul.get_x() + 1, ul.get_y());
				br.set_coord(br.get_x() + 1, br.get_y());
				break;
			}
			case ShiftDirection::Down:
			{
				ul.set_coord(ul.get_x(), ul.get_y() - 1);
				br.set_coord(br.get_x(), br.get_y() - 1);
				break;
			}
			case ShiftDirection::Left:
			{
				ul.set_coord(ul.get_x() - 1, ul.get_y());
				br.set_coord(br.get_x() - 1, br.get_y());
				break;
			}
			case ShiftDirection::Up:
			{
				ul.set_coord(ul.get_x(), ul.get_y() + 1);
				br.set_coord(br.get_x(), br.get_y() + 1);
				break;
			}
			}
			(*iter)->setBottomRight(br);
			(*iter)->setUpperLeft(ul);
		}
	}
}
void WorldMap::drawAll(list< GlobalObject* >& allobjects)
{
	list< GlobalObject* >::iterator iter;
	for (iter = allobjects.begin(); iter != allobjects.end(); iter++)
	{
		PointCoord pc1 = (*iter)->getUpperLeft();
		PointCoord pc2 = (*iter)->getBottomRight();
		Draw_ptr->drawBuilding(pc1.get_x(), pc1.get_y(), pc2.get_x(), pc2.get_y(), (*iter)->getSymbol());
	}
}
///////////////VisibleMap Class///////////////
void VisibleMap::SetCorners(int left_x, int right_x, int up_y, int bot_y)
{
	UpperLeftCorner.set_coord(left_x, up_y);
	BottomRightCorner.set_coord(right_x, bot_y);
}
ShiftDirection VisibleMap::CursorBordersCheck(Cursor* C_ptr)
{
	ShiftDirection SD;
	if ((C_ptr->getCursorConsoleLocation()).get_x() == UpperLeftCorner.get_x())
	{
		SD = ShiftDirection::Right;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_y() == UpperLeftCorner.get_y())
	{
		SD = ShiftDirection::Down;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_x() == BottomRightCorner.get_x())
	{
		SD = ShiftDirection::Left;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_y() == BottomRightCorner.get_y())
	{
		SD = ShiftDirection::Up;
		return SD;
	}
	SD = ShiftDirection::Middle;
	return SD;
}