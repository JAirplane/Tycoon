#pragma once
#include "StartScreen.h"
/////////////PlayingField Class/////////////
class PlayingField : public MyRectangle
{
public:
	PlayingField(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, initial, vis_ptr, cur_ptr)
	{}
	PlayingField(MyRectangle& anotherRectangle) : MyRectangle(anotherRectangle)
	{}
	virtual ~PlayingField()
	{}
	void Shift(Direction shiftDirection, int shiftValue = 1);
};