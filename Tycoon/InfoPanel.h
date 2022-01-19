#pragma once
#include "Menu.h"
#include "Alphabet.h"
class InfoPanel : public GlobalObject
{
private:
	Visualisation* draw_ptr;
	Cursor* cursor_ptr;
	RectangleSymbols* infoPanelBorderSymbols_ptr;
	RectangleSymbols* infoScreenBorderSymbols_ptr;
	RectangleSymbols* infoScreenButtonBorderSymbols_ptr;
	list<string> messages;
	vector<string> controls;
public:
	InfoPanel(Visualisation* drawptr, Cursor* cursorptr, PointCoord upperLeft, RectangleSymbols* externalBorderSymbols_ptr, 
		RectangleSymbols* infoScreenSymbols_ptr, RectangleSymbols* buttonBorders_ptr, int heightAdd, int widthAdd) : GlobalObject(upperLeft, heightAdd, widthAdd), 
		draw_ptr(drawptr), cursor_ptr(cursorptr), infoPanelBorderSymbols_ptr(externalBorderSymbols_ptr), infoScreenBorderSymbols_ptr(infoScreenSymbols_ptr),
		infoScreenButtonBorderSymbols_ptr(buttonBorders_ptr)
	{
		controls.push_back("Use arrows to move cursor on the playingfield / navigate in menu");
		controls.push_back("Tab to switch between main screen and menu");
		controls.push_back("Enter to select construction in the menu / to build it on the playingfield");
		controls.push_back("Esc to deselect construction");
		controls.push_back("'H' key to hide / show menu elements");
		controls.push_back("'S' key to switch menu side");
		controls.push_back("'R' key rotates buildings");
	}
	~InfoPanel()
	{
		delete infoPanelBorderSymbols_ptr;
	}
	void DrawInfoPanelExternalBorders();
	void EraseInfoPanelExternalBorders();
	void ClearInfoPanelContent();
	void DrawInfoPanelSplashScreen(color foreground, color background);
	void AddMessage(const string);
	void DeleteMessage();
	void DisplayMessage(int initialX, int initialY, string message, color letterColor, color background = cBLACK);
	void DeleteOldMessages();
	void DisplayMessages();
	void DrawInfoScreenBorders(int leftX, int topY, int rightX, int bottomY, color foreground, color background = cBLACK);
	void DrawInfoScreenButton(int leftX, int topY, int rightX, int bottomY, color foreground, color background = cBLACK);
	void DrawInfoScreen(int leftX, int topY, int rightX, int bottomY, color foreground, color background = cBLACK);
};