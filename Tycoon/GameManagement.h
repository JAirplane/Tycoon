#pragma once
#include <chrono>
#include "SaveLoad.h"
/////////////Game Management Class/////////////
class GameManagement : public MessageSubjectInterface, public ConstructionInfoSubjectInterface
{
private:
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
	SaveLoad* saverAndLoader_ptr;
	Display* gameElementsDrawer;
	AllObjects* allObjects_ptr;
	Camera* camera_ptr;
	PlayingField* field_ptr;
	Menu* menu_ptr;
	InfoPanel* infoPanel_ptr;
	InitialScreen* startScreen_ptr;
	MainMenu* mainMenu_ptr;
	//
	list<ConstructionInfoObserverInterface*> choosenConstructionObservers;
	list<MessageObserverInterface*> userMessageObservers;
public:
	GameManagement()
	{
		cursor_ptr = nullptr;
		draw_ptr = nullptr;
		saverAndLoader_ptr = nullptr;
		gameElementsDrawer = nullptr;
		allObjects_ptr = nullptr;
		camera_ptr = nullptr;
		field_ptr = nullptr;
		menu_ptr = nullptr;
		infoPanel_ptr = nullptr;
		startScreen_ptr = nullptr;
		mainMenu_ptr = nullptr;
	}
	virtual ~GameManagement()
	{
		delete cursor_ptr;
		delete draw_ptr;
		delete saverAndLoader_ptr;
		delete gameElementsDrawer;
		delete allObjects_ptr;
		delete camera_ptr;
		delete field_ptr;
		delete menu_ptr;
		delete infoPanel_ptr;
		delete startScreen_ptr;
		delete mainMenu_ptr;
	}
	// create game elements
	virtual void CreateCursor();
	virtual void CreateDrawPointer();
	virtual void CreateSaverLoader();
	virtual void CreateGameElementsDrawer();
	virtual void CreateAllObjects();
	virtual void NewGameObjectsCreation();
	virtual void CreateCamera();
	virtual void CreatePlayingField();
	virtual void CreateMenuAndElements();
	virtual void CreateInfoPanel();
	virtual void CreateStartScreen();
	virtual void CreateMainMenu();
	//
	int GetPressedKey() const;
	int MainMenuUserActions(int key);
	void MainMenuInteraction();
	void InitialSplashScreenPlay();
	void BeforeGameStartDrawing();
	void MainMenuPlay();
	// notifies InfoPanel if user choose some construction on the playing field
	void ChosenConstructionAttach(ConstructionInfoObserverInterface* observer) override;
	void ChosenConstructionDetach(ConstructionInfoObserverInterface* observer) override;
	void ChosenConstructionNotify(Construction* choosenConstruction_ptr) override;
	// notifies InfoPanel about various issues with a message
	void UserMessageAttach(MessageObserverInterface* observer) override;
	void UserMessageDetach(MessageObserverInterface* observer) override;
	void UserMessageNotify(const string message) override;
	//
	void ErasePreliminaryElementAndMenuRedraw();
	void ClearChosenElementAndInfoPanelRedraw();
	//
	void UserActionsCycle(chrono::milliseconds& lastLaunch);
	void VisitorCreationCycle(chrono::milliseconds& lastLaunch);
	void VisitorStepCycle(chrono::milliseconds& lastLaunch);
	void VisitorStatusReductionCycle(chrono::milliseconds& lastLaunch);
	void PayDailyExpencesCycle(chrono::milliseconds& lastLaunch);
	void GameProcess();
	//
	void H_Key();
	void S_Key();
	void R_Key();
	//
	void Z_Key(); //display matrix
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
	int EnterKey_MainMenu();
	//
	void EscKey_Camera();
	void EscKey_InfoPanel();
	void Esc_Key();
	//
	void Arrows_PlayingField(Direction arrowDir);
	void Arrows_Menu(Direction arrowDir);
	void Arrows_InfoPanel(Direction arrowDir);
	void Arrows(Direction arrowDir);
	void Arrows_MainMenu(Direction arrowDir);
	//
	void UserActions(int key);
};