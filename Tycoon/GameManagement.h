#pragma once
#include "Menu.h"

/////////////World Map Class/////////////
class GameManagement
{
private:
	Camera* camera_ptr;
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
	AllObjects* AllObjects_ptr;
	Allbuildings* buildings_ptr;
	AllRoads* Roads_ptr;
	AllVisitors* Visitors_ptr;
	Menu* Menu_ptr;
public:
	GameManagement()
	{
		cursor_ptr = new Cursor();
		camera_ptr = new Camera(ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft());
		playingfield_ptr = new PlayingField(ConstructionOptions::GetAllOptions()->GetPlayingFieldUpperLeft(), ConstructionOptions::GetAllOptions()->GetPlayingFieldHeightAdd(),
			ConstructionOptions::GetAllOptions()->GetPlayingFieldWidthAdd(), ConstructionOptions::GetAllOptions()->GetVerticalPlayingField(),
			ConstructionOptions::GetAllOptions()->GetHorizontalPlayingField(), ConstructionOptions::GetAllOptions()->GetUpperLeftPlayingField(),
			ConstructionOptions::GetAllOptions()->GetUpperRightPlayingField(), ConstructionOptions::GetAllOptions()->GetBottomLeftPlayingField(),
			ConstructionOptions::GetAllOptions()->GetBottomRightPlayingField());
		draw_ptr = new Visualisation();
		AllObjects_ptr = new AllObjects(cursor_ptr);
		buildings_ptr = new Allbuildings(cursor_ptr, draw_ptr);
		Roads_ptr = new AllRoads(cursor_ptr, draw_ptr);
		Visitors_ptr = new AllVisitors(cursor_ptr, AllObjects_ptr, draw_ptr);
		PointCoord MenuUL(camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() + 1, camera_ptr->GetUpperLeft().Get_y());
		Menu_ptr = new Menu(draw_ptr, camera_ptr, cursor_ptr, MenuUL);
	}
	~GameManagement()
	{
		delete cursor_ptr;
		delete camera_ptr;
		delete draw_ptr;
		delete AllObjects_ptr;
		delete buildings_ptr;
		delete Roads_ptr;
		delete Visitors_ptr;
		delete Menu_ptr;
	}
	void DisplayPlayingField();
	void DisplayMenuBorders();
	void DisplayIcons();
	void DisplayMenu();
	void HideMenu();
	void eraseScreen();
	void Shift(Direction SD);
	void Shift(Direction SD, int shiftvalue);
	void DisplayAllObjects();
	void GameProcess();
	void UserActions(int key);
	void PreliminaryBuildingAdd(IngameObject* go_ptr);
	void BuildingConnectedToRoadCheck(); //sets true status to every building object that is connected to road and sets true "IsGraph" status to every connected road as well
	virtual void CreateManagers();
	void H_Key();
	void S_Key();
	void Tab_Key_Playingfield();
	void Tab_Key_Menu();
	void Enter_Key_PlayingField();
	void Enter_Key_Menu();
	void Esc_Key_PlayingField();
	void Arrows_PlayingField(PointCoord cursordestination);
	void UpArrow_Menu();
	void DownArrow_Menu();
};