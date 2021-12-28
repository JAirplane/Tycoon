#pragma once
#include "IngameObjectDerived.h"
/////////////PlayingField Class/////////////
class PlayingField : public GlobalObject
{
private:
	RectangleSymbols* rectangleSymbols_ptr;
public:
	PlayingField(PointCoord upperLeft, int heightAdd, int widthAdd, RectangleSymbols* rectangleSymbols_ptr) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{
		this->rectangleSymbols_ptr = rectangleSymbols_ptr;
	}
	~PlayingField()
	{
		delete rectangleSymbols_ptr;
	}
	RectangleSymbols* GetBorderSymbols() const;
	void Shift(Direction shiftDirection);
	void Shift(Direction shiftDirection, int shiftValue);
};