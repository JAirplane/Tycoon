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
///////////////VisitorsLife Class///////////////
bool VisitorsLife::VisitorLocationCheck(PointCoord pc)
{
	return ACVptr->LocationCheck(pc);
}
void VisitorsLife::VisitorAppear()
{
	int random_x = rand() % 5 + 1; //4 possible cells to appear
	const int const_y = 80; //80 is example, depends on entrance in a world map, but const
	PointCoord StartVisitorPoint(random_x, const_y);
	if (VisitorLocationCheck(StartVisitorPoint))
	{
		int food = 100;
		int pee = 100;
		Visitor* Visptr = new Visitor(StartVisitorPoint, food, pee);
		ACVptr->addVisitor(Visptr);
		dVptr->drawVis();
	}

}
void VisitorsLife::MoveAllVisitors()
{

}
///////////////AllCurrentVisitors Class///////////////
void AllCurrentVisitors::addVisitor(Visitor* vptr)
{
	AllVisitors.push_back(vptr);
}
bool AllCurrentVisitors::LocationCheck(PointCoord pc)
{
	for (iter = AllVisitors.begin(); iter != AllVisitors.end(); iter++)
	{
		if (pc == (*iter) -> getLocation())
		{
			return 0;
		}
	}
	return 1;
}
///////////////Cursor Class///////////////
PointCoord Cursor::getCursorLocation()
{
	CursorLocation = GetConsoleCursorPosition();
	return CursorLocation;
}
///////////////Construction Class///////////////
PointCoord Construction::getUpperRight()
{
	return UpperRight;
}
PointCoord Construction::getBottomLeft()
{
	return BottomLeft;
}
void Construction::setBottomLeft(PointCoord pc)
{
	BottomLeft.set_coord(pc.get_x() - 1, pc.get_y() - 1);
}
void Construction::setUpperRight(PointCoord pc)
{
	UpperRight.set_coord(pc.get_x() - 1, pc.get_y() - 1);
}
///////////////Ice Cream Shop Class///////////////

///////////////WorldMap Class///////////////
void WorldMap::SetCorners(int left_x, int right_x, int up_y, int bot_y)
{
	UpperLeft.set_coord(left_x, up_y);
	UpperRight.set_coord(right_x, up_y);
	BottomLeft.set_coord(left_x, bot_y);
	BottomRight.set_coord(right_x, bot_y);
}
void WorldMap::CreateConstruction()
{
	Construction* CSTRptr = new IceCreamShop(PointCoord(Cptr->getCursorLocation()));
	WMConstructions.push_back(CSTRptr);
	PointCoord pc1 = CSTRptr->getUpperRight();
	PointCoord pc2 = CSTRptr->getBottomLeft();
	dCptr->drawConst(pc1.get_x(), pc1.get_y(), pc2.get_x(), pc2.get_y());
}
void WorldMap::Shift(int ShiftSide)
{
	switch (ShiftSide)
	{
	case 1:
	{
		for (iter = WMConstructions.begin(); iter != WMConstructions.end(); iter++)
		{
			PointCoord ur = (*iter)->getUpperRight();
			PointCoord bl = (*iter)->getBottomLeft();
			ur.set_coord(ur.get_x() - 1, ur.get_y());
			bl.set_coord(ur.get_x() - 1, ur.get_y());
			(*iter)->setBottomLeft(ur);
			(*iter)->setUpperRight(bl);
		}
	}
	}
}