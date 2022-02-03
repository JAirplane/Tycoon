#pragma once
#include "MenuScreen_InfoPanel.h"
class ControlsScreen : public MyRectangle
{
private:
	vector<string> controlsDescription;
public:
	ControlsScreen(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor, Visualisation* vis_ptr,
		Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
		{}
	~ControlsScreen()
		{}
	virtual void FillControlsDescriptions();
	void DisplayControls();
};
