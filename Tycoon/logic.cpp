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
	return Location;
}
void Visitor::VisitorMove(int x, int y)
{
	Location.set_coord(x, y);
}
///////////////ManageVisitors Class///////////////
bool ManageVisitors::VisitorLocationCheck(PointCoord pc)
{
	return ACV_ptr->LocationCheck(pc);
}
void ManageVisitors::VisitorAppear()
{
	int random_x = rand() % 5 + 1; //4 possible cells to appear
	const int const_y = 80; //80 is example, depends on entrance in a world map, but const
	PointCoord StartVisitorPoint(random_x, const_y);
	if (VisitorLocationCheck(StartVisitorPoint))
	{
		int food = 100;
		int pee = 100;
		Visitor* Vis_ptr = new Visitor(StartVisitorPoint, food, pee);
		ACV_ptr->addVisitor(Vis_ptr);
		VV_ptr->drawVisitor();
	}
}
void ManageVisitors::MoveAllVisitors()
{

}
///////////////AllCurrentVisitors Class///////////////
void AllCurrentVisitors::addVisitor(Visitor* v_ptr)
{
	AllVisitors.push_back(v_ptr);
}
bool AllCurrentVisitors::LocationCheck(PointCoord pc)
{
	for (iter = AllVisitors.begin(); iter != AllVisitors.end(); iter++)
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
///////////////Construction Class///////////////
PointCoord Construction::getUpperLeft()
{
	return UpperLeft;
}
PointCoord Construction::getBottomRight()
{
	return BottomRight;
}
void Construction::setUpperLeft(PointCoord pc)
{
	UpperLeft.set_coord(pc.get_x(), pc.get_y());
}
void Construction::setBottomRight(PointCoord pc)
{
	BottomRight.set_coord(pc.get_x(), pc.get_y());
}
const char Construction::getSymbol()
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
///////////////All Constrations Class///////////////
void AllConstructions::CreateConstruction(char ChoosenBuilding)
{
	Construction* CSTR_ptr = new IceCreamShop(PointCoord(C_ptr->getCursorConsoleLocation()));
	WMConstructions.push_back(CSTR_ptr);
	PointCoord pc1 = CSTR_ptr->getUpperLeft();
	PointCoord pc2 = CSTR_ptr->getBottomRight();
	CV_ptr->drawConstruction(pc1.get_x(), pc1.get_y(), pc2.get_x(), pc2.get_y(), CSTR_ptr->getSymbol());
}
list< Construction* >& AllConstructions::getAllConstructions()
{
	return WMConstructions;
}
list< Construction* >::iterator& AllConstructions::getConstructionsIter()
{
	return iter;
}
///////////////Manage Constructions Class///////////////

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
	return RoadLocation;
}
void Road::setRoadLocation(PointCoord loc)
{
	RoadLocation = loc;
}
///////////////AllRoads Class///////////////
void addRoad(Road* R_ptr)
{

}
///////////////WorldMap Class///////////////
void WorldMap::drawMapBorders()
{
	MV_ptr->drawWorld();
}
void WorldMap::GameProcess()
{
	char ch = 'a';
	ShiftDirection SD;
	drawMapBorders();
	set_cursor_pos(5, 5);
	C_ptr->setCursorConsoleLocation();
	AC_ptr->CreateConstruction(ch);
	while (true)
	{
		SD = VM_ptr->CursorBordersCheck(C_ptr);
		Shift(SD, AC_ptr->getAllConstructions(), AC_ptr->getConstructionsIter());
		drawAll(AC_ptr->getAllConstructions(), AC_ptr->getConstructionsIter());
	}
}
void WorldMap::Shift(ShiftDirection SD, list< Construction* >& WMConstructions, list< Construction* >::iterator& iter)
{
	if (SD != ShiftDirection::Middle)
	{
		C_ptr->CursorShift(SD);
		for (iter = WMConstructions.begin(); iter != WMConstructions.end(); iter++)
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
void WorldMap::drawAll(list< Construction* >& WMConstructions, list< Construction* >::iterator& iter)
{
	for (iter = WMConstructions.begin(); iter != WMConstructions.end(); iter++)
	{
		PointCoord pc1 = (*iter)->getUpperLeft();
		PointCoord pc2 = (*iter)->getBottomRight();
		CV_ptr->drawConstruction(pc1.get_x(), pc1.get_y(), pc2.get_x(), pc2.get_y(), (*iter)->getSymbol());
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