#pragma once
#include "Menu.h"
/////////////World Map Class/////////////
class GameManagement
{
private:
	Camera* camera_ptr;
	Cursor* cursor_ptr;
	PlayingField* field_ptr;
	Visualisation* draw_ptr;
	AllObjects* allObjects_ptr;
	AllBuildings* buildings_ptr;
	AllRoads* roads_ptr;
	AllVisitors* visitors_ptr;
	Menu* menu_ptr;
public:
	GameManagement()
	{
		cursor_ptr = new Cursor();
		camera_ptr = new Camera(ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft());
		field_ptr = new PlayingField(ConstructionOptions::GetAllOptions()->GetPlayingFieldUpperLeft(), ConstructionOptions::GetAllOptions()->GetPlayingFieldheightAdd(),
			ConstructionOptions::GetAllOptions()->GetPlayingFieldwidthAdd(), ConstructionOptions::GetAllOptions()->GetVerticalPlayingField(),
			ConstructionOptions::GetAllOptions()->GetHorizontalPlayingField(), ConstructionOptions::GetAllOptions()->GetUpperLeftPlayingField(),
			ConstructionOptions::GetAllOptions()->GetUpperRightPlayingField(), ConstructionOptions::GetAllOptions()->GetBottomLeftPlayingField(),
			ConstructionOptions::GetAllOptions()->GetBottomRightPlayingField());
		draw_ptr = new Visualisation();
		allObjects_ptr = new AllObjects(cursor_ptr, draw_ptr);
		buildings_ptr = new AllBuildings(cursor_ptr, draw_ptr);
		roads_ptr = new AllRoads(cursor_ptr, draw_ptr);
		visitors_ptr = new AllVisitors(cursor_ptr, allObjects_ptr, draw_ptr);
		PointCoord menuUpperLeft(camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() + 1, camera_ptr->GetUpperLeft().Get_y());
		menu_ptr = new Menu(draw_ptr, camera_ptr, cursor_ptr, menuUpperLeft);
	}
	~GameManagement()
	{
		delete cursor_ptr;
		delete camera_ptr;
		delete draw_ptr;
		delete allObjects_ptr;
		delete buildings_ptr;
		delete roads_ptr;
		delete visitors_ptr;
		delete menu_ptr;
	}
	void DisplayPlayingField();
	void DisplayMenuBorders();
	void DisplayIcons();
	void DisplayMenu();
	void HideMenu();
	void EraseScreen();
	void Shift(Direction shiftDirection);
	void Shift(Direction shiftDirection, int shiftvalue);
	void DisplayAllObjects();
	void GameProcess();
	void UserActions(int key);
	void PreliminaryBuildingAdd(IngameObject* go_ptr);
	void BuildingconnectedToRoadCheck(); //sets true status to every building object that is connected to road and sets true "IsGraph" status to every connected road as well
	virtual void Createmanagers();
	void H_Key();
	void S_Key();
	void TabKey_Playingfield();
	void TabKey_Menu();
	void EnterKey_PlayingField();
	void EnterKey_Menu();
	void EscKey_PlayingField();
	void Arrows_PlayingField(PointCoord cursorDestination);
	void UpArrow_Menu();
	void DownArrow_Menu();
};