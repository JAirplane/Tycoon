#pragma once
#include "ControlsScreen_InfoPanel.h"
class GameMessagesScreen : public MyRectangle
{
private:
	list<string> messages;
public:
	GameMessagesScreen(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor, Visualisation* vis_ptr,
		Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
		{}
	~GameMessagesScreen()
		{}

};
