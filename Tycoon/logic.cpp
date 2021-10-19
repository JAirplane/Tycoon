#include "logicheader.h"
#include "drawheader.h"
#include <cstdlib>
#include <iostream>
using namespace std;
///////////////PointCoord Struct///////////////
int PointCoord::get_x()
{
	return x_coord;
}
int PointCoord::get_y()
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
PointCoord Visitor::getLoc()
{
	return Location;
}
///////////////VisitorsLife Class///////////////
bool VisitorsLife::VisitorLocCheck(PointCoord pc)
{
	return ACVptr->LocationCheck(pc);
}
void VisitorsLife::VisitorAppear()
{
	int random_x = rand() % 4 + 1; //4 possible cells to appear
	const int const_y = 80; //80 is example, depends on entrance in a world map, but const
	PointCoord StartVisitorPoint(random_x, const_y);
	if (VisitorLocCheck(StartVisitorPoint))
	{
		int food = 100;
		int pee = 100;
		Visitor* Visptr = new Visitor(StartVisitorPoint, food, pee);
		ACVptr->addVisitor(Visptr);
		dVptr->drawVis();
	}

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
		if (pc == (*iter) -> getLoc())
		{
			return 0;
		}
	}
	return 1;
}