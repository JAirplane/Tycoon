#pragma once
#include "GlobalObject.h"
/////////////PlayingField Class/////////////
class PlayingField : public GlobalObject
{
private:
	wchar_t verticalBorderSymbol;
	wchar_t horizontalBorderSymbol;
	wchar_t upperLeftBorderSymbol;
	wchar_t upperRightBorderSymbol;
	wchar_t bottomLeftBorderSymbol;
	wchar_t bottomRightBorderSymbol;
public:
	PlayingField(PointCoord upperLeft, unsigned int heightAdd, unsigned int widthAdd, wchar_t verticalSymbol, wchar_t horizontalSymbol,
		wchar_t upperLeftSymbol, wchar_t upperRightSymbol, wchar_t bottomLeftSymbol, wchar_t bottomRightSymbol) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{
		verticalBorderSymbol = verticalSymbol;
		horizontalBorderSymbol = horizontalSymbol;
		upperLeftBorderSymbol = upperLeftSymbol;
		upperRightBorderSymbol = upperRightSymbol;
		bottomLeftBorderSymbol = bottomLeftSymbol;
		bottomRightBorderSymbol = bottomRightSymbol;
	}
	~PlayingField() {}
	wchar_t GetVerticalSymbol() const;
	wchar_t GetHorizontalSymbol() const;
	wchar_t GetUpperLeftSymbol() const;
	wchar_t GetUpperRightSymbol() const;
	wchar_t GetBottomLeftSymbol() const;
	wchar_t GetBottomRightSymbol() const;
};