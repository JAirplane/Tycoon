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
		//Menu initialisation
		PointCoord menuUpperLeft(camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() + 1, camera_ptr->GetUpperLeft().Get_y());
		RectangleSymbols* menuSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuBottomRightSymbol());
		color menuBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetMenuBorderForegroundColor();
		color menuBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetMenuBorderBackgroundColor();
		BorderAppearance* menuBorder = new BorderAppearance(menuSymbols_ptr, menuBorderForegroundColor, menuBorderBackgroundColor);
		color menuLetterColor = ConstructionOptions::GetAllOptions()->GetMenuLetterColor();
		color menuShadingColor = ConstructionOptions::GetAllOptions()->GetMenuShadingColor();
		menu_ptr = new Menu(draw_ptr, camera_ptr, cursor_ptr, menuUpperLeft, ConstructionOptions::GetAllOptions()->GetMenuHeightAdd(),
			ConstructionOptions::GetAllOptions()->GetMenuWidthAdd(), menuBorder, menuLetterColor, menuShadingColor);
		//InfoPanel initialisation
		RectangleSymbols* infoPanelBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetInfoPanelVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoPanelHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoPanelUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoPanelBottomRightSymbol());
		color borderForegroundColor = ConstructionOptions::GetAllOptions()->GetInfoPanelBorderForegroundColor();
		color borderBackgroundColor = ConstructionOptions::GetAllOptions()->GetInfoPanelBorderBackgroundColor();
		BorderAppearance* externalBorder = new BorderAppearance(infoPanelBorderSymbols_ptr, borderForegroundColor, borderBackgroundColor);
		color letterColor = ConstructionOptions::GetAllOptions()->GetInfoPanelTextColor();
		color shadingColor = ConstructionOptions::GetAllOptions()->GetInfoPanelShadingColor();
		infoPanel_ptr = new InfoPanel(ConstructionOptions::GetAllOptions()->GetInfoPanelUpperLeft(), ConstructionOptions::GetAllOptions()->GetInfoPanelHeightAdd(), 
			ConstructionOptions::GetAllOptions()->GetInfoPanelWidthAdd(), externalBorder, letterColor, shadingColor, draw_ptr, cursor_ptr);
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