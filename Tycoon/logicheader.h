#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "msoftcon.h"
#include "drawheader.h"
using namespace std;
/////////////Point Coord Class/////////////
struct PointCoord
{
private:
	int x_coord;
	int y_coord;
public:
	PointCoord()
	{
		x_coord = 1;
		y_coord = 1;
	}
	PointCoord(int x, int y) : x_coord(x), y_coord(y)
	{}
	PointCoord(COORD crd)
	{
		x_coord = static_cast<int>(crd.X) + 1;
		y_coord = static_cast<int>(crd.Y) + 1;
	}
	PointCoord(const PointCoord &pc)
	{
		x_coord = pc.get_x();
		y_coord = pc.get_y();
	}
	int get_x() const;
	int get_y() const;
	void set_coord(int, int);
	bool operator == (PointCoord);
};
/////////////Cursor Class/////////////
class Cursor
{
private:
	PointCoord CursorLocation;
public:
	Cursor()
	{
		set_cursor_pos(1, 1);
		CursorLocation.set_coord(1, 1);
	}
	PointCoord getCursorLocation();
};
/////////////Parent Class of all constructions/////////////
class Construction
{
private:
	PointCoord UpperRight;
	PointCoord BottomLeft;
	int StartCondition;
public:
	Construction(PointCoord ur) : UpperRight(ur), StartCondition(100)
	{}
	PointCoord getUpperRight();
	PointCoord getBottomLeft();
	void setBottomLeft(PointCoord);
	void setUpperRight(PointCoord);
};
/////////////Child Classes of Construction/////////////
class IceCreamShop : public Construction
{
private:
	static const int ConstructionCost;
	static const int DailyExpences;
	int LastDayVisitors;
	int LastDayProfit;
public:
	IceCreamShop(PointCoord _ur) : Construction(_ur)
	{
		PointCoord pc;
		pc = getUpperRight();
		setBottomLeft(pc);
		LastDayVisitors = 0;
		LastDayProfit = 0;
	}
	static const int getIceCreamShopCreateCost();
};
class Road : public Construction
{
private:
	static const int ConstructionCost;
public:
	Road(PointCoord _ur) : Construction(_ur)
	{}
	static const int getRoadCost();
};
/////////////End of Constructions Classes/////////////
/////////////Visitor Classes/////////////
class Visitor
{
private:
	PointCoord Location;
	int FoodCapacity;
	int NeedToPee;
public:
	Visitor(PointCoord loc, int fc, int ntp) : Location(loc), FoodCapacity(fc), NeedToPee(ntp)
	{}
	PointCoord getLocation();
	void VisitorMove(int, int);
	void NeedsUp();
	void ChooseDir();
};
class AllCurrentVisitors
{
private:
	vector<Visitor*> AllVisitors;
	vector<Visitor*>::iterator iter;
public:
	void addVisitor(Visitor* vptr);
	bool LocationCheck(PointCoord);
};
class VisitorsLife
{
private:
	AllCurrentVisitors* ACVptr;
	drawVisitor* dVptr;
public:
	VisitorsLife(AllCurrentVisitors* acv) : ACVptr(acv)
	{}
	void VisitorAppear();
	void VisitorDisappear();
	bool VisitorLocationCheck(PointCoord);
	void MoveAllVisitors();
};
/////////////World Map Class/////////////
class WorldMap
{
private:
	list< Construction* > WMConstructions;
	list< Construction* >::iterator iter;
	PointCoord UpperLeft;
	PointCoord UpperRight;
	PointCoord BottomLeft;
	PointCoord BottomRight;
	Cursor* Cptr;
	drawMap* dMptr;
	drawConstruction* dCptr;
public:
	WorldMap()
	{
		Cptr = new Cursor;
	}
	void SetCorners(int, int, int, int);
	void CreateConstruction();
	void addConst(Construction* cstrptr);
	void Shift(int ShiftSide);
};