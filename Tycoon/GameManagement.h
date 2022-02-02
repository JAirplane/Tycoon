#pragma once
#include "InfoPanel.h"
/////////////Game Management Class/////////////
class GameManagement
{
private:
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
	AllObjects* allObjects_ptr;
	Camera* camera_ptr;
	PlayingField* field_ptr;
	Menu* menu_ptr;
	InfoPanel* infoPanel_ptr;
public:
	GameManagement()
	{
		cursor_ptr = nullptr;
		draw_ptr = nullptr;
		allObjects_ptr = nullptr;
		camera_ptr = nullptr;
		field_ptr = nullptr;
		menu_ptr = nullptr;
		infoPanel_ptr = nullptr;
	}
	~GameManagement()
	{
		delete cursor_ptr;
		delete camera_ptr;
		delete draw_ptr;
		delete allObjects_ptr;
		delete menu_ptr;
		delete field_ptr;
		delete infoPanel_ptr;
	}
	// create game elements
	virtual void CreateCursor();
	virtual void CreateDrawPointer();
	virtual void CreateAllObjects();
	virtual void CreateCamera();
	virtual void CreatePlayingField();
	virtual void CreateMenuAndElements();
	virtual void CreateInfoPanel();
	//
	void DisplayCamera();
	void DisplayMenu();
	void DisplayPlayingField();
	void DisplayInfoPanel();
	void HideInfoPanel();
	void ErasePlayingField();
	void HideMenu();
	void EraseScreen();
	void DisplayAllObjects();
	void GameProcess();
	void UserActions(int key);
	void H_Key();
	void S_Key();
	void R_Key();
	void I_Key_PlayingField();
	void I_Key_Menu();
	void I_Key_InfoPanel();
	void TabKey_Playingfield();
	void TabKey_Menu();
	void EnterKey_PlayingField();
	void EnterKey_Menu();
	void EscKey_PlayingField();
	void Arrows_PlayingField(PointCoord cursorDestination);
	void UpArrow_Menu();
	void DownArrow_Menu();
	CursorLocation CurrentCursorLoc();
};