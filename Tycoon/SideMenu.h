#pragma once
#include "VisibleMap.h"
#include <vector>
/////////////Current Position of Side Menu/////////////
enum class SideMenuStatus
{
	LEFT,
	RIGHT,
};
/////////////Icons Position higher or lower than current active icon or coord/////////////
enum class IconsPosition
{
	UPPER,
	LOWER,
};
/////////////Side Menu Class/////////////
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
	void EraseMenu();
};