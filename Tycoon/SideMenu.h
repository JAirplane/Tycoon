#pragma once
#include "VisibleMap.h"
#include <vector>
//enum class ManagerType
//{
//	Building,
//	Road,
//};
/////////////Side Menu Class/////////////
class SideMenu : public GlobalObject
{
private:
	Visualisation* Draw_ptr;
	VisibleMap* VM_ptr;
	Cursor* C_ptr;
	vector<ConstructionManager*> Managers;
	SideMenuStatus CurrentSide;
	bool Hidden;
public:
	SideMenu(Visualisation* drawptr, VisibleMap* vmptr, Cursor* _c_ptr, PointCoord _ul) : GlobalObject(_ul), Draw_ptr(drawptr), VM_ptr(vmptr), C_ptr(_c_ptr)
	{
		setHeightAddition(ConstructionOptions::getAllOptions()->getMenuHeightAdd());
		setWidthAddition(ConstructionOptions::getAllOptions()->getMenuWidthAdd());
		Hidden = 0;
		CurrentSide = SideMenuStatus::RIGHT;
		/*int _x = (getUpperLeft().get_x() * 2 + getWidthAddition()) / 2;
		int _y = getUpperLeft().get_y() + 4;
		IceCreamShop* ics_ptr = nullptr;
		Construction* icecreamicon_ptr = new Icon<IceCreamShop*>(PointCoord(_x, _y), ics_ptr, IceCreamShopIconDescription, IceCreamShopCost, IceCreamShopExpences, IceSymbol);
		Icons.push_back(icecreamicon_ptr);
		_y += 6;
		Road* r_ptr = nullptr;
		Construction* road_ptr = new Icon<Road*>(PointCoord(_x, _y), r_ptr, RoadDescription, RoadCost, RoadExpences, RoadSymbol);
		Icons.push_back(road_ptr);*/
	}
	~SideMenu()
	{
		vector<ConstructionManager*>::iterator iter;
		for (iter = Managers.begin(); iter != Managers.end(); iter++)
		{
			delete (*iter);
		}
	}
	bool getHideMenuStatus() const;
	void setHideMenuStatus(bool hideflag);
	SideMenuStatus getCurrentSide();
	ShiftDirection ChangeMenuSide();
	void ShowIcons();
	void ShowMenuBorders();
	PointCoord getNearestIconCoords(PointCoord currenticon, IconsPosition ip);
	void IconsShift(IconsPosition ip);
	GlobalObject* ChooseBuilding(PointCoord iconpos);
	PointCoord MenuNavigation(PointCoord currenticon, IconsPosition ip);
	void EraseMenu();
};