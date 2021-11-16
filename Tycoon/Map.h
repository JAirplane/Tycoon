#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "ObjectContainers.h"
using namespace std;
const PointCoord IceIconUL_init(83, 5);
const PointCoord RoadIconUL_init(83, 12);
const PointCoord drawIconUL_1(74, 3);
const PointCoord drawIconUL_2(74, 10);
const PointCoord drawIconUL_3(74, 17);
const PointCoord drawIconUL_4(74, 24);
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
		BottomRightCorner.set_coord(UpperLeftCorner.get_x() + X_axis, UpperLeftCorner.get_y() + Y_axis);
	}
	~VisibleMap()
	{}
	PointCoord getUpperLeftCorner();
	PointCoord getBottomRightCorner();
	void SetCorners(PointCoord UL, PointCoord BR);
	ShiftDirection CursorBordersCheck(Cursor*);
};
/////////////Right Side Menu Class/////////////
class SideMenu
{
private:
	Visualisation* Draw_ptr;
	IceCreamShopIcon* IceIcon_ptr;
	RoadIcon* RoadIcon_ptr;
public:
	SideMenu(Visualisation* drawptr) : Draw_ptr(drawptr)
	{
		IceIcon_ptr = new IceCreamShopIcon(IceIconUL_init);
		RoadIcon_ptr = new RoadIcon(RoadIconUL_init);
	}
	~SideMenu()
	{
		delete IceIcon_ptr;
		delete RoadIcon_ptr;
	}
	IceCreamShop* getIceIcon();
	Road* getRoadIcon();
	void drawIceCreamShopIcon(PointCoord UpperLeft);
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
	SideMenu* SideMenu_ptr;
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
		SideMenu_ptr = new SideMenu(Draw_ptr);
	}
	~WorldMap()
	{
		delete C_ptr;
		delete VM_ptr;
		delete Draw_ptr;
		delete AllObjects_ptr;
		delete Buildings_ptr;
		delete Roads_ptr;
		delete Visitors_ptr;
		delete SideMenu_ptr;
	}
	void drawInitialGameCondition();
	void Shift(ShiftDirection);
	void drawAll();
	void eraseAll();
	void GameProcess();
	void UserActions(int key);
};