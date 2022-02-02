#pragma once
#include "MessagesAndInfoScreen_InfoPanel.h"
#include "Alphabet.h"
class InfoPanel : public MyRectangle
{
private:
	MenuScreen* mainScreen_ptr;
	ControlsScreen* gameControlInfo_ptr;
	GameMessagesScreen* messagesAndInfoScreen_ptr;
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
	//
	void DrawSplashScreen(color foreground, color background);
	void AddMessage(const string);
	void DeleteMessage();
	void DisplayMessage(int initialX, int initialY, string message, color letterColor, color background = cBLACK);
	void DeleteOldMessages();
	void DisplayMessages();
	void DrawMenuScreenButton(Button* button_ptr);
	void DrawMenuScreen();
	void ShowControls();
	void SwitchContent(InfoPanelContentType choosenContent);
	void Arrows(Direction arrowDir);
	void EndInteraction();
};