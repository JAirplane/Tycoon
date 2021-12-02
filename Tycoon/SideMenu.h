#pragma once
#include "VisibleMap.h"
#include <vector>
/////////////Side Menu Class/////////////
class SideMenu : public GlobalObject
{
private:
	Visualisation* Draw_ptr;
	VisibleMap* VM_ptr;
	vector<Icon<T>*> Icons;
	SideMenuStatus CurrentStatus;
	bool Hidden;
public:
	SideMenu(Visualisation* drawptr, VisibleMap* vmptr, PointCoord _ul) : GlobalObject(_ul), Draw_ptr(drawptr), VM_ptr(vmptr)
	{
		setHeight(VisibleMapHeight);
		setWidth(MenuWidth);
		Hidden = 0;
		CurrentStatus = SideMenuStatus::RIGHT;
		int _x = (getUpperLeft().get_x() * 2 + getWidth() - 1) / 2;
		int _y = getUpperLeft().get_y() + 4;
		Icon<T>* icecreamicon_ptr = new Icon(PointCoord(_x, _y), IceCreamShopIconDescription, IceCreamShopCost, IceCreamShopExpences, IceSymbol);
		Icons.push_back(icecreamicon_ptr);
		_y += 6;
		Icon<T>* road_ptr = new Icon(PointCoord(_x, _y), RoadDescription, RoadCost, RoadExpences, RoadSymbol);
		Icons.push_back(road_ptr);
	}
	~SideMenu()
	{
		vector<Icon<T>*>::iterator iter;
		for (iter = Icons.begin(); iter != Icons.end(); iter++)
		{
			delete (*iter);
		}
	}
	bool getHideMenuStatus() const;
	void setHideMenuStatus(bool hideflag);
	SideMenuStatus getSideStatus();
	ShiftDirection ChangeMenuStatus();
	void ShowIcons();
	void ShowMenuBorders();
	PointCoord getNearestIconCoords(PointCoord currenticon, IconsPosition ip);
	void IconsShift(IconsPosition ip);
	GlobalObject* ChooseBuilding(PointCoord iconpos);
	PointCoord MenuNavigation(PointCoord currenticon, IconsPosition ip);
	void EraseMenu();
};