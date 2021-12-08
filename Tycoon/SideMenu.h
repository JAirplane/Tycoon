#pragma once
#include "VisibleMap.h"
#include <vector>
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
	IngameObject* CreatePreliminaryObject(PointCoord iconpos);
	PointCoord MenuNavigation(PointCoord currenticon, IconsPosition ip);
	void EraseMenu();
	void addManager(ConstructionManager* manager_ptr);
};