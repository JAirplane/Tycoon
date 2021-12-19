#pragma once
#include "GlobalObject.h"
/////////////PlayingField Class/////////////
class PlayingField : public GlobalObject
{
private:
	wstring verticalBorderSymbol;
	wstring horizontalBorderSymbol;
	wstring upperLeftBorderSymbol;
	wstring upperRightBorderSymbol;
	wstring bottomLeftBorderSymbol;
	wstring bottomRightBorderSymbol;
public:
	PlayingField(PointCoord upperLeft, unsigned int heightAdd, unsigned int widthAdd, wstring verticalSymbol, wstring horizontalSymbol,
		wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{
		verticalBorderSymbol = verticalSymbol;
		horizontalBorderSymbol = horizontalSymbol;
		upperLeftBorderSymbol = upperLeftSymbol;
		upperRightBorderSymbol = upperRightSymbol;
		bottomLeftBorderSymbol = bottomLeftSymbol;
		bottomRightBorderSymbol = bottomRightSymbol;
	}
	~PlayingField() {}
	wstring GetVerticalSymbol() const;
	wstring GetHorizontalSymbol() const;
	wstring GetUpperLeftSymbol() const;
	wstring GetUpperRightSymbol() const;
	wstring GetBottomLeftSymbol() const;
	wstring GetBottomRightSymbol() const;
};