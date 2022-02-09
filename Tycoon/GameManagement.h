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
	CursorLocation GetCursorArea();
	void ReturnCursorToCamera();
	void DrawCursor();
	// display / erase main game elements
	void DisplayCamera();
	void DisplayMenu();
	void DisplayPlayingField();
	void DisplayInfoPanel();
	void HideInfoPanel();
	void ErasePlayingField();
	void HideMenu();
	void EraseScreen();
	void DisplayAllObjects();
	//
	void HideInterface();
	void ShowInterface();
	//
	void GameProcess();
	void UserActions(int key);
	void H_Key();
	void S_Key();
	void R_Key();
	//
	void IKey_Camera();
	void IKey_Menu();
	void IKey_InfoPanel();
	void I_Key();
	//
	void TabKey_Camera();
	void TabKey_Menu();
	void TabKey_InfoPanel();
	void Tab_Key();
	//
	void EnterKey_Camera();
	void EnterKey_Menu();
	void EnterKey_InfoPanel();
	void Enter_Key();
	//
	void EscKey_Camera();
	void EscKey_InfoPanel();
	void Esc_Key();
	void Arrows_PlayingField(PointCoord cursorDestination);
	void UpArrow_Menu();
	void DownArrow_Menu();
};