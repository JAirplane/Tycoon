#pragma once
#include "ConstructionInfoScreen.h"
class SplitScreen : public MyRectangle
{
public:
	SplitScreen(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, initial, vis_ptr, cur_ptr)
	{}
	SplitScreen(MyRectangle& someRectangle) : MyRectangle(someRectangle)
	{}
	virtual ~SplitScreen()
	{}
	void DrawBorder();
	void EraseBorder();
};