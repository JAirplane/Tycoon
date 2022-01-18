#pragma once
#include "Menu.h"
#include "Alphabet.h"
class InfoPanel : public GlobalObject
{
private:
	Visualisation* draw_ptr;
	Cursor* cursor_ptr;
	RectangleSymbols* infoPanelBorderSymbols_ptr;
	list<pair<string, bool> > messages;
public:
	InfoPanel(Visualisation* drawptr, Cursor* cursorptr, PointCoord upperLeft, RectangleSymbols* BorderSymbols_ptr, int heightAdd, int widthAdd) :
		GlobalObject(upperLeft, heightAdd, widthAdd), draw_ptr(drawptr), cursor_ptr(cursorptr), infoPanelBorderSymbols_ptr(BorderSymbols_ptr)
	{}
	~InfoPanel()
	{
		delete infoPanelBorderSymbols_ptr;
	}
	void DrawInfoPanelBorders();
	void EraseInfoPanelBorders();
	void ClearInfoPanelContent();
	void DrawInfoPanelSplashScreen(color foreground, color background);
	void AddMessage(const string);
	void DeleteMessage();
	void DisplayMessage();
};