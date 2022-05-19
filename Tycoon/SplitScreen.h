#pragma once
#include "ConstructionInfoScreen.h"
class SplitScreen : public MyRectangle
{
public:
	SplitScreen(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor, Visualisation* vis_ptr,
		Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
	{}
	SplitScreen(MyRectangle* someRectangle) : MyRectangle(someRectangle)
	{}
	virtual ~SplitScreen()
	{}
	void DrawBorder();
	void EraseBorder();
};