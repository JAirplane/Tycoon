#pragma once
#include "InfoPanel.h"
/////////////Game Management Class/////////////
class GameManagement
{
private:
	Camera* camera_ptr;
	Cursor* cursor_ptr;
	PlayingField* field_ptr;
	Visualisation* draw_ptr;
	AllObjects* allObjects_ptr;
	Menu* menu_ptr;
	InfoPanel* infoPanel_ptr;
public:
	GameManagement()
	{
		cursor_ptr = new Cursor();
		RectangleSymbols* cameraSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetCameraVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetCameraHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetCameraUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetCameraUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetCameraBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetCameraBottomRightSymbol());
		camera_ptr = new Camera(ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft(), ConstructionOptions::GetAllOptions()->GetCameraHeightAdd(),
			ConstructionOptions::GetAllOptions()->GetCameraWidthAdd(), cameraSymbols_ptr);
		RectangleSymbols* playingFieldSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetVerticalPlayingField(),
			ConstructionOptions::GetAllOptions()->GetHorizontalPlayingField(), ConstructionOptions::GetAllOptions()->GetUpperLeftPlayingField(),
			ConstructionOptions::GetAllOptions()->GetUpperRightPlayingField(), ConstructionOptions::GetAllOptions()->GetBottomLeftPlayingField(),
			ConstructionOptions::GetAllOptions()->GetBottomRightPlayingField());
		field_ptr = new PlayingField(ConstructionOptions::GetAllOptions()->GetPlayingFieldUpperLeft(), ConstructionOptions::GetAllOptions()->GetPlayingFieldHeightAdd(),
			ConstructionOptions::GetAllOptions()->GetPlayingFieldWidthAdd(), playingFieldSymbols_ptr);
		draw_ptr = new Visualisation();
		allObjects_ptr = new AllObjects(cursor_ptr, draw_ptr);
		PointCoord menuUpperLeft(camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() + 1, camera_ptr->GetUpperLeft().Get_y());
		RectangleSymbols* menuSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuBottomRightSymbol());
		RectangleSymbols* itemSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuItemVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuItemHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuItemUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuItemBottomRightSymbol());
		RectangleSymbols* iconSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuIconVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuIconHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuIconUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuIconUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuIconBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuIconBottomRightSymbol());
		menu_ptr = new Menu(draw_ptr, camera_ptr, cursor_ptr, menuUpperLeft, menuSymbols_ptr, itemSymbols_ptr, iconSymbols_ptr,
			ConstructionOptions::GetAllOptions()->GetMenuHeightAdd(), ConstructionOptions::GetAllOptions()->GetMenuWidthAdd());
		RectangleSymbols* externalBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetInfoPanelVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoPanelHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoPanelUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoPanelBottomRightSymbol());
		RectangleSymbols* infoScreenBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetInfoScreenVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoScreenHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetInfoScreenUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoScreenUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetInfoScreenBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoScreenBottomRightSymbol());
		RectangleSymbols* buttonBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetInfoScreenButtonVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoScreenButtonHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetInfoScreenButtonUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoScreenButtonUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetInfoScreenButtonBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoScreenButtonBottomRightSymbol());
		RectangleSymbols* controlsBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetControlsVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetControlsHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetControlsUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetControlsUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetControlsBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetControlsBottomRightSymbol());
		infoPanel_ptr = new InfoPanel(draw_ptr, cursor_ptr, ConstructionOptions::GetAllOptions()->GetInfoPanelUpperLeft(), externalBorderSymbols_ptr,
			infoScreenBorderSymbols_ptr, buttonBorderSymbols_ptr, controlsBorderSymbols_ptr, ConstructionOptions::GetAllOptions()->GetInfoPanelHeightAdd(),
			ConstructionOptions::GetAllOptions()->GetInfoPanelWidthAdd());
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
	virtual void CreateManagers();
	void H_Key();
	void S_Key();
	void R_Key();
	void I_Key_OutOfInfoPanel();
	void TabKey_Playingfield();
	void TabKey_Menu();
	void EnterKey_PlayingField();
	void EnterKey_Menu();
	void EscKey_PlayingField();
	void Arrows_PlayingField(PointCoord cursorDestination);
	void UpArrow_Menu();
	void DownArrow_Menu();
};