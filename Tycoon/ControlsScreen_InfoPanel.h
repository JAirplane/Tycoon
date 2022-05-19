#pragma once
#include "SplitScreen.h"
class ControlsScreen : public SplitScreen
{
private:
	vector<string> controlsDescription;
public:
	ControlsScreen(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor, Visualisation* vis_ptr,
		Cursor* cur_ptr) : SplitScreen(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
	{}
	ControlsScreen(MyRectangle* someRectangle) : SplitScreen(someRectangle)
	{}
	virtual ~ControlsScreen()
	{}
	virtual void FillControlsDescriptions();
	void DisplayControls();
};