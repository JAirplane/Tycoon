#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <conio.h>
#include <cstdlib>
#include "ObjectContainers.h"
using namespace std;
enum class SideMenuStatus
{
	LEFT,
	RIGHT,
};
enum class IconsPosition
{
	UPPER,
	LOWER,
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
		BottomRightCorner.set_coord(UpperLeftCorner.get_x() + X_axis, UpperLeftCorner.get_y() + Y_axis);
	}
	~VisibleMap()
	{}
	PointCoord getUpperLeftCorner() const;
	PointCoord getBottomRightCorner() const;
	void SetCorners(PointCoord UL, PointCoord BR);
	ShiftDirection CursorBordersCheck(Cursor*);
};
/////////////Right Side Menu Class/////////////
class SideMenu
{
private:
	PointCoord MenuUpperLeft;
	PointCoord MenuBottomRight;
	Visualisation* Draw_ptr;
	VisibleMap* VM_ptr;
	vector<GlobalObject*> Icons;
	SideMenuStatus CurrentStatus;
	bool Hidden;
public:
	SideMenu(Visualisation* drawptr, VisibleMap* vmptr) : Draw_ptr(drawptr), VM_ptr(vmptr)
	{
		MenuUpperLeft = PointCoord(VM_ptr->getBottomRightCorner().get_x() + 1, VM_ptr->getUpperLeftCorner().get_y());
		MenuBottomRight = PointCoord(VM_ptr->getBottomRightCorner().get_x() + Menu_X_axis, VM_ptr->getBottomRightCorner().get_y());
		Hidden = 0;
		int _x = (MenuBottomRight.get_x() + MenuUpperLeft.get_x()) / 2;
		int _y = MenuUpperLeft.get_y() + 4;
		CurrentStatus = SideMenuStatus::RIGHT;
		GlobalObject* Ice_ptr = new IceCreamShopIcon(PointCoord(_x, _y));
		Icons.push_back(Ice_ptr);
		_y += 6;
		GlobalObject* Rd_ptr = new RoadIcon(PointCoord(_x, _y));
		Icons.push_back(Rd_ptr);
	}
	~SideMenu()
	{
		vector<GlobalObject*>::iterator iter;
		for (iter = Icons.begin(); iter != Icons.end(); iter++)
		{
			delete (*iter);
		}
	}
	void setMenuCoords(PointCoord UL, PointCoord BR);
	PointCoord getMenuUpperLeft() const;
	PointCoord getMenuBottomRight() const;
	bool getHideMenuStatus() const;
	void setHideMenuStatus(bool hideflag);
	SideMenuStatus getCurrentStatus();
	ShiftDirection ChangeMenuStatus();
	void ShowIcons();
	void ShowMenuBorders();
	PointCoord getNearestIconCoords(PointCoord currenticon, IconsPosition ip);
	void IconsShift(IconsPosition ip);
	GlobalObject* ChooseBuilding(PointCoord iconpos);
	PointCoord MenuNavigation(PointCoord currenticon, IconsPosition ip);
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
		SideMenu_ptr = new SideMenu(Draw_ptr, VM_ptr);
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
	void DisplayPlayingField();
	void DisplaySideMenuBorders();
	void DisplayIcons();
	void DisplaySideMenu();
	void HideSideMenu();
	void eraseScreen();
	void Shift(ShiftDirection SD);
	void Shift(ShiftDirection SD, int shiftvalue);
	void DisplayAllObjects();
	void eraseAllObjects();
	void GameProcess();
	void UserActions(int key);
	void PreliminaryBuildingCreation(GlobalObject* go_ptr);
};