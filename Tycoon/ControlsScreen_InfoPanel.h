#pragma once
#include "SaveAndExit_InfoPanel.h"
class ControlsScreen : public SplitScreen
{
private:
	vector<string> controlsDescription;
public:
	ControlsScreen(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : SplitScreen(upperLeft, initial, vis_ptr, cur_ptr)
	{}
	ControlsScreen(MyRectangle& someRectangle) : SplitScreen(someRectangle)
	{}
	virtual ~ControlsScreen()
	{}
	virtual void FillControlsDescriptions();
	void DisplayControls();
};