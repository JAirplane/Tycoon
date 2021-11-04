#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "msoftcon.h"
#include "drawheader.h"
using namespace std;
///////////////Map Size///////////////
const int X_axis = 70;
const int Y_axis = 35;
///////////////Enum ShiftDirection///////////////
enum class ShiftDirection { Up, Right, Down, Left, Middle };
///////////////Enum RoadMask///////////////
enum class RoadMask {
	NONE = 0,
	LEFT = 1,
	TOP = 2,
	RIGHT = 4,
	BOTTOM = 8,
};
///////////////All Possible Types of Mask///////////////
const int none = int(RoadMask::NONE);
const int leftside = int(RoadMask::LEFT);
const int topside = int(RoadMask::TOP);
const int rightside = int(RoadMask::RIGHT);
const int bottomside = int(RoadMask::BOTTOM);
const int vertical = int(RoadMask::BOTTOM) | int(RoadMask::TOP);
const int horizontal = int(RoadMask::LEFT) | int(RoadMask::RIGHT);
const int lefttop_angle = int(RoadMask::LEFT) | int(RoadMask::TOP);
const int righttop_angle = int(RoadMask::RIGHT) | int(RoadMask::TOP);
const int leftbottom_angle = int(RoadMask::LEFT) | int(RoadMask::BOTTOM);
const int rightbottom_angle = int(RoadMask::RIGHT) | int(RoadMask::BOTTOM);
const int right_T = int(RoadMask::RIGHT) | int(RoadMask::BOTTOM) | int(RoadMask::TOP);
const int left_T = int(RoadMask::LEFT) | int(RoadMask::BOTTOM) | int(RoadMask::TOP);
const int top_T = int(RoadMask::RIGHT) | int(RoadMask::LEFT) | int(RoadMask::TOP);
const int bottom_T = int(RoadMask::RIGHT) | int(RoadMask::LEFT) | int(RoadMask::BOTTOM);
const int cross = int(RoadMask::RIGHT) | int(RoadMask::LEFT) | int(RoadMask::BOTTOM) | int(RoadMask::TOP);
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
	~PointCoord()
	{}
	PointCoord(int x, int y) : x_coord(x), y_coord(y)
	{}
	PointCoord(COORD crd)
	{
		x_coord = static_cast<int>(crd.X) + 1;
		y_coord = static_cast<int>(crd.Y) + 1;
	}
	PointCoord(const PointCoord& pc)
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
	int Xshift;
	int Yshift;
	PointCoord CursorConsoleLocation; // location according to console coords (1, 1 is minimum)
public:
	Cursor()
	{
		CursorConsoleLocation.set_coord(1, 1);
		Xshift = 0;
		Yshift = 0;
	}
	~Cursor()
	{}
	PointCoord getCursorConsoleLocation();
	void setCursorConsoleLocation();
	void CursorShift(ShiftDirection);
};
/////////////Parent Class of all constructions/////////////
class GlobalObject
{
private:
	PointCoord UpperLeft;
	PointCoord BottomRight;
	int StartCondition;
public:
	GlobalObject(PointCoord ul) : UpperLeft(ul), StartCondition(100)
	{}
	~GlobalObject()
	{}
	PointCoord getUpperLeft() const;
	PointCoord getBottomRight();
	void setUpperLeft(PointCoord);
	void setBottomRight(PointCoord);
	virtual const char getSymbol();
};
/////////////Child Classes of Construction/////////////
class IceCreamShop : public GlobalObject
{
private:
	static const int ConstructionCost;
	static const int DailyExpences;
	int LastDayVisitors;
	int LastDayProfit;
	static const char drawConstructionSymbol;
public:
	IceCreamShop(PointCoord _ul) : GlobalObject(_ul)
	{
		PointCoord pc;
		pc = getUpperLeft();
		setBottomRight(PointCoord(pc.get_x() - 1, pc.get_y() - 1));
		LastDayVisitors = 0;
		LastDayProfit = 0;
	}
	static const int getIceCreamShopCreateCost();
	virtual const char getSymbol();
};
class Road : public GlobalObject
{
private:
	int RoadEnvironmentMask;
	static const int RoadCost;
	static const char drawRoadSymbol;
public:
	Road(PointCoord _ul) : GlobalObject(_ul)
	{
		RoadEnvironmentMask = 0;
	}
	~Road()
	{}
	static const int getRoadCost();
	const char getRoadSymbol() const;
	PointCoord getRoadLocation() const;
	void setRoadLocation(PointCoord);
	int& get_set_RoadEnvironmentMask();
};
class Visitor : public GlobalObject
{
private:
	int FoodCapacity;
	int NeedToPee;
public:
	Visitor(PointCoord _ul, int fc, int ntp) : GlobalObject(_ul)
	{
		FoodCapacity = fc;
		NeedToPee = ntp;
	}
	~Visitor()
	{}
	PointCoord getLocation();
	void VisitorMove(int, int);
	void NeedsUp();
	void ChooseDir();
};
/////////////End of Constructions Classes/////////////
/////////////Container of All Objects in the Game/////////////
class AllObjects
{
private:
	list< GlobalObject* > EveryObject;
	Cursor* C_ptr;
public:
	AllObjects(Cursor* _C_ptr)
	{
		C_ptr = _C_ptr;
	}
	~AllObjects()
	{
		list< GlobalObject* >::iterator iter;
		for (iter = EveryObject.begin(); iter != EveryObject.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addObject(GlobalObject* obj_ptr);
	void CreateConstruction(char);
	list< GlobalObject* >& getAllObjects();
};
/////////////Container of All Types of Buildings Class/////////////
class AllBuildings
{
private:
	list< GlobalObject* > Buildings;
	Cursor* C_ptr;
	AllObjects* AllObjects_ptr;
	Visualisation* Draw_ptr;
public:
	AllBuildings(Cursor* _C_ptr, AllObjects* _AllObjects_ptr, Visualisation* _Draw_ptr)
	{
		C_ptr = _C_ptr;
		AllObjects_ptr = _AllObjects_ptr;
		Draw_ptr = _Draw_ptr;
	}
	~AllBuildings()
	{
		list< GlobalObject* >::iterator iter;
		for (iter = Buildings.begin(); iter != Buildings.end(); iter++)
		{
			delete (*iter);
		}
	}
	void CreateBuilding(char);
	list< GlobalObject* >& getAllBuildings();
};
/////////////Road Container Class/////////////
class AllRoads
{
private:
	list<Road*> Roads;
	Cursor* C_ptr;
	AllObjects* AllObjects_ptr;
	Visualisation* Draw_ptr;
public:
	AllRoads(Cursor* _C_ptr, AllObjects* _AllObjects_ptr, Visualisation* _Draw_ptr)
	{
		C_ptr = _C_ptr;
		AllObjects_ptr = _AllObjects_ptr;
		Draw_ptr = _Draw_ptr;
	}
	~AllRoads()
	{
		list<Road*>::iterator iter;
		for (iter = Roads.begin(); iter != Roads.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addRoad(Road* R_ptr);
	list<Road*>& getAllRoads();
	int RoadEnvironment(PointCoord pc1);
	char SetRoadSymbol(int mask) const;
};
/////////////Visitor Container Class/////////////
class AllVisitors
{
private:
	list<Visitor*> Visitors;
	Cursor* C_ptr;
	AllObjects* AllObjects_ptr;
	Visualisation* Draw_ptr;
public:
	AllVisitors(Cursor* _C_ptr, AllObjects* _AllObjects_ptr, Visualisation* _Draw_ptr)
	{
		C_ptr = _C_ptr;
		AllObjects_ptr = _AllObjects_ptr;
		Draw_ptr = _Draw_ptr;
	}
	~AllVisitors()
	{
		list<Visitor*>::iterator iter;
		for (iter = Visitors.begin(); iter != Visitors.end(); iter++)
		{
			delete (*iter);
		}
	}
	void VisitorAppear();
	bool LocationCheck(PointCoord);
	list<Visitor*>& getAllVisitors();
};
/////////////Visible Map Class/////////////
class VisibleMap
{
private:
	PointCoord UpperLeftCorner;
	PointCoord BottomRightCorner;
public:
	VisibleMap()
	{
		UpperLeftCorner.set_coord(1, 1);
		BottomRightCorner.set_coord(X_axis, Y_axis);
	}
	~VisibleMap()
	{}
	void SetCorners(int, int, int, int);
	ShiftDirection CursorBordersCheck(Cursor*);
};
/////////////World Map Class/////////////
class WorldMap
{
private:
	VisibleMap* VM_ptr;
	Cursor* C_ptr;
	Visualisation* Draw_ptr;
	AllObjects* AllObjects_ptr;
	AllBuildings* Buildings_ptr;
	AllRoads* Roads_ptr;
	AllVisitors* Visitors_ptr;
public:
	WorldMap()
	{
		C_ptr = new Cursor();
		VM_ptr = new VisibleMap();
		Draw_ptr = new Visualisation();
		AllObjects_ptr = new AllObjects(C_ptr);
		Buildings_ptr = new AllBuildings(C_ptr, AllObjects_ptr, Draw_ptr);
		Roads_ptr = new AllRoads(C_ptr, AllObjects_ptr, Draw_ptr);
		Visitors_ptr = new AllVisitors(C_ptr, AllObjects_ptr, Draw_ptr);
	}
	~WorldMap()
	{
		delete C_ptr;
		delete VM_ptr;
		delete Draw_ptr;
		delete AllObjects_ptr;
		delete Roads_ptr;
		delete Visitors_ptr;
	}
	void drawMapBorders();
	void Shift(ShiftDirection);
	void drawAll();
	void eraseAll();
	void GameProcess();
	void UserActions(int key);
};