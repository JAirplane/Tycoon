#pragma once
#include "SideMenu.h"

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
		VM_ptr = new VisibleMap(ConstructionOptions::getAllOptions()->getVisibleMapInitialCoordUL());
		Draw_ptr = new Visualisation();
		AllObjects_ptr = new AllObjects(C_ptr);
		Buildings_ptr = new AllBuildings(C_ptr, Draw_ptr);
		Roads_ptr = new AllRoads(C_ptr, Draw_ptr);
		Visitors_ptr = new AllVisitors(C_ptr, AllObjects_ptr, Draw_ptr);
		PointCoord SideMenuUL(VM_ptr->getUpperLeft().get_x() + VM_ptr->getWidthAddition() + 1, VM_ptr->getUpperLeft().get_y());
		SideMenu_ptr = new SideMenu(Draw_ptr, VM_ptr, C_ptr, SideMenuUL);
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
	void Shift(Direction SD);
	void Shift(Direction SD, int shiftvalue);
	void DisplayAllObjects();
	void eraseAllObjects();
	void GameProcess();
	void UserActions(int key);
	void PreliminaryBuildingAdd(IngameObject* go_ptr);
	void BuildingConnectedToRoadCheck(); //sets true status to every building object that is connected to road and sets true "IsGraph" status to every connected road as well
	virtual void CreateManagers();
	void H_Key();
	void S_Key();
	void Tab_Key_Playingfield();
	void Enter_Key_PlayingField();
	void Enter_Key_SideMenu();
	void Esc_Key_PlayingField();
};