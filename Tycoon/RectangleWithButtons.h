#pragma once
#include "Button.h"
class RectangleWithButtons : public MyRectangle
{
public:
	RectangleWithButtons() : MyRectangle() {}
	RectangleWithButtons(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, initial, vis_ptr, cur_ptr) {}
	RectangleWithButtons(MyRectangle& anotherRectangle) : MyRectangle(anotherRectangle) {}
	virtual ~RectangleWithButtons() {}
	virtual Button* CreateButton(PointCoord upperLeft, string buttonTitle) const = 0;
	virtual void CreateButtons() = 0;
};