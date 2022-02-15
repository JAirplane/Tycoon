#pragma once
#include "ObserverInterface.h"
/////////////PlayingField Class/////////////
class PlayingField : public MyRectangle
{
public:
	PlayingField(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor,
		Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
		{}
	~PlayingField()
		{}
	void Shift(Direction shiftDirection, int shiftValue = 1);
};