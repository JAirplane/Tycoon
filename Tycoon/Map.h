#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "ObjectContainers.h"
using namespace std;
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