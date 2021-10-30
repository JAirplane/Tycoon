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
class Construction
{
private:
	PointCoord UpperLeft;
	PointCoord BottomRight;
	int StartCondition;
public:
	Construction(PointCoord ul) : UpperLeft(ul), StartCondition(100)
	{}
	~Construction()
	{}
	PointCoord getUpperLeft();
	PointCoord getBottomRight();
	void setUpperLeft(PointCoord);
	void setBottomRight(PointCoord);
	virtual const char getSymbol();
};
/////////////Child Classes of Construction/////////////
class IceCreamShop : public Construction
{
private:
	static const int ConstructionCost;
	static const int DailyExpences;
	int LastDayVisitors;
	int LastDayProfit;
	static const char drawConstructionSymbol;
public:
	IceCreamShop(PointCoord _ur) : Construction(_ur)
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
/////////////End of Constructions Classes/////////////
/////////////Container of Constructions and Management Classes/////////////
class AllConstructions
{
private:
	list< Construction* > WMConstructions;
	list< Construction* >::iterator iter;

public:
	AllConstructions()
	{}
	~AllConstructions()
	{
		for (iter = WMConstructions.begin(); iter != WMConstructions.end(); iter++)
		{
			delete (*iter);
		}
	}
	void CreateConstruction(char);
	list< Construction* >& getAllConstructions();
	list< Construction* >::iterator& getConstructionsIter();
};
class ManageConstructions
{
private:
	AllConstructions* AllC_ptr;
	Cursor* C_ptr;
	ConstructionVisualisation* CV_ptr;
public:
	ManageConstructions(Cursor* _C_ptr) : C_ptr(_C_ptr)
	{
		AllC_ptr = new AllConstructions();
	}
	~ManageConstructions()
	{
		delete AllC_ptr;
	}
};
/////////////Road Classes/////////////
class Road
{
private:
	PointCoord RoadLocation;
	static const int RoadCost;
	static const char drawRoadSymbol;
public:
	Road(PointCoord rloc) : RoadLocation(rloc)
	{ }
	~Road()
	{}
	static const int getRoadCost();
	const char getRoadSymbol() const;
	PointCoord getRoadLocation() const;
	void setRoadLocation(PointCoord);
};
class AllCurrentRoads
{
private:
	vector<Road*> Roads;
	vector<Road*>::iterator iter;
public:
	AllCurrentRoads()
	{}
	~AllCurrentRoads()
	{
		for (iter = Roads.begin(); iter != Roads.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addRoad(Road* R_ptr);
};
class ManageRoads
{
private:
	AllCurrentRoads* ACR_ptr;
	RoadVisualisation* RV_ptr;
	Cursor* C_ptr;
public:
	ManageRoads(Cursor* _C_ptr)
	{
		C_ptr = _C_ptr;
		ACR_ptr = new AllCurrentRoads();
	}
	~ManageRoads()
	{
		delete ACR_ptr;
	}
	void BuildRoad();
};
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
	~Visitor()
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
	AllCurrentVisitors()
	{}
	~AllCurrentVisitors()
	{
		for (iter = AllVisitors.begin(); iter != AllVisitors.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addVisitor(Visitor* vptr);
	bool LocationCheck(PointCoord);
};
class ManageVisitors
{
private:
	AllCurrentVisitors* ACV_ptr;
	VisitorVisualisation* VV_ptr;
public:
	ManageVisitors(VisitorVisualisation* _VV_ptr)
	{
		ACV_ptr = new AllCurrentVisitors();
		VV_ptr = _VV_ptr;
	}
	~ManageVisitors()
	{
		delete ACV_ptr;
	}
	void VisitorAppear();
	void VisitorDisappear();
	bool VisitorLocationCheck(PointCoord);
	void MoveAllVisitors();
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
	MapVisualisation* MV_ptr;
	VisitorVisualisation* VV_ptr;
	ConstructionVisualisation* CV_ptr;
	ManageRoads* MR_ptr;
	ManageVisitors* ManVis_ptr;
	ManageConstructions* MC_ptr;
public:
	WorldMap()
	{
		C_ptr = new Cursor();
		VM_ptr = new VisibleMap();
		VV_ptr = new VisitorVisualisation();
		MV_ptr = new MapVisualisation();
		CV_ptr = new ConstructionVisualisation();
		ManVis_ptr = new ManageVisitors(VV_ptr);
		MR_ptr = new ManageRoads(C_ptr);
		MC_ptr = new ManageConstructions(C_ptr);
	}
	~WorldMap()
	{
		delete C_ptr;
		delete VM_ptr;
		delete VV_ptr;
		delete MV_ptr;
		delete CV_ptr;
		delete ManVis_ptr;
		delete MR_ptr;
		delete MC_ptr;
	}
	void drawMapBorders();
	void Shift(ShiftDirection, list< Construction* >&, list< Construction* >::iterator&);
	void drawAll(list< Construction* >&, list< Construction* >::iterator&);
	void GameProcess();
};