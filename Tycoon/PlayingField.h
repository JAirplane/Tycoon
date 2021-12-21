#pragma once
#include "RectangleSymbols.h"
/////////////PlayingField Class/////////////
class PlayingField : public GlobalObject
{
private:
	RectangleSymbols* rectangleSymbols_ptr;
public:
	PlayingField(PointCoord upperLeft, unsigned int heightAdd, unsigned int widthAdd, RectangleSymbols* rectangleSymbols_ptr) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{
		this->rectangleSymbols_ptr = rectangleSymbols_ptr;
	}
	~PlayingField()
	{
		delete rectangleSymbols_ptr;
	}
	RectangleSymbols* GetRectangleSymbolsPointer() const;
};