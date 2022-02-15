#pragma once
#include <fcntl.h>
#include <io.h>
#include "MessagesAndInfoScreen_InfoPanel.h"
#include "Alphabet.h"
class InfoPanel : public MyRectangle, MessageObserverInterface, ConstructionInfoObserverInterface
{
private:
	MenuScreen* mainScreen_ptr;
	ControlsScreen* gameControlInfo_ptr;
	MessagesAndInfoScreen* messagesAndInfoScreen_ptr;
	InfoPanelContentType currentScreen;
public:
	InfoPanel(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* externalBorder, color letterColor,
		color shadingColor, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, externalBorder, letterColor, shadingColor, vis_ptr, cur_ptr)
	{
		mainScreen_ptr = nullptr;
		gameControlInfo_ptr = nullptr;
		messagesAndInfoScreen_ptr = nullptr;
		currentScreen = InfoPanelContentType::None;
	}
	~InfoPanel()
	{
		delete mainScreen_ptr;
		delete gameControlInfo_ptr;
		delete messagesAndInfoScreen_ptr;
	}
	// create Screens
	virtual void CreateMenuScreen();
	virtual void CreateControlsScreen();
	virtual void CreateGameMessagesScreen();
	// when receive notification from GameManagement that user choose some construction on the playing field
	void ChoosenConstructionUpdate(Construction* choice_ptr) override;
	// when receive user message from GameManagement
	void UserMessageUpdate(const string message) override;
	//
	const MenuScreen* GetMenuScreen();
	const ControlsScreen* GetControlsScreen();
	MessagesAndInfoScreen* GetMessagesScreen();
	InfoPanelContentType GetCurrentContent() const;
	//
	void ShowSplashScreen(color foreground, color background);
	void ShowMenuScreen();
	void ShowControls();
	void ShowMessagesScreen();
	void SwitchContent(InfoPanelContentType choosenContent);
	void GetToInfoPanelDisplayRule();
	void EndInteractionDisplayRule();
	void SetChoosenConstruction(Construction* choice_ptr);
	void ClearChoosenConstruction(); //do not free memory
};