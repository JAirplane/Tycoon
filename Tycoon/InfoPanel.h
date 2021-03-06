#pragma once
#include <fcntl.h>
#include <io.h>
#include "MessagesAndInfoScreen_InfoPanel.h"
class InfoPanel : public MyRectangle, public MessageObserverInterface, public ConstructionInfoObserverInterface
{
private:
	MenuScreen* mainScreen_ptr;
	ControlsScreen* gameControlInfo_ptr;
	SaveAndExitScreen* leaveOrStay_ptr;
	MessagesAndInfoScreen* messagesAndInfoScreen_ptr;
	InfoPanelContentType currentScreen;
	MyRectangle* CreateScreenRectangle(string screenTitle); //applied "infoPanelMenuScreen", "infoPanelControlsScreen", "infoPanelMessagesAndInfoScreen", "infoPanelSaveAndExitScreen"
public:
	InfoPanel(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, initial, vis_ptr, cur_ptr)
	{
		mainScreen_ptr = nullptr;
		gameControlInfo_ptr = nullptr;
		leaveOrStay_ptr = nullptr;
		messagesAndInfoScreen_ptr = nullptr;
		currentScreen = InfoPanelContentType::None;
	}
	InfoPanel(MyRectangle& infoPanelRectangle) : MyRectangle(infoPanelRectangle)
	{
		mainScreen_ptr = nullptr;
		gameControlInfo_ptr = nullptr;
		leaveOrStay_ptr = nullptr;
		messagesAndInfoScreen_ptr = nullptr;
		currentScreen = InfoPanelContentType::None;
	}
	virtual ~InfoPanel()
	{
		delete mainScreen_ptr;
		delete gameControlInfo_ptr;
		delete leaveOrStay_ptr;
		delete messagesAndInfoScreen_ptr;
	}
	// create Screens
	virtual void CreateMenuScreen();
	virtual void CreateControlsScreen();
	virtual void CreateGameMessagesScreen();
	virtual void CreateSaveAndExitScreen();
	// when receive notification from GameManagement that user choose some construction on the playing field
	void ChosenConstructionUpdate(Construction* choice_ptr) override;
	// when receive user message from GameManagement
	void UserMessageUpdate(const string message) override;
	//
	const MenuScreen* GetMenuScreen() const;
	const ControlsScreen* GetControlsScreen() const;
	MessagesAndInfoScreen* GetMessagesScreen() const;
	const SaveAndExitScreen* GetSaveAndExitScreen() const;
	InfoPanelContentType GetCurrentContent() const;
	//
	void DisplayInfoPanelMessage(string msg);
	void EraseInfoPanelMessage();
	void ShowSplashScreen(color foreground, color background);
	void ShowMenuScreen();
	void ShowControls();
	void ShowMessagesScreen();
	void ShowSaveAndExitScreen();
	void UpdateConstructionInfo() const;
	void SwitchContent(InfoPanelContentType choosenContent);
	void GetToInfoPanelDisplayRule();
	void EndInteractionDisplayRule();
	void SetChosenConstruction(Construction* choice_ptr);
	void ClearChoosenConstruction(); //do not free memory
};