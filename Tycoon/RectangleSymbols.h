#pragma once
#include "ConstructionOptions.h"
/////////////Symbols to Draw Rectangle Class/////////////
class RectangleSymbols
{
private:
	wstring verticalBorderSymbol;
	wstring horizontalBorderSymbol;
	wstring upperLeftBorderSymbol;
	wstring upperRightBorderSymbol;
	wstring bottomLeftBorderSymbol;
	wstring bottomRightBorderSymbol;
public:
	RectangleSymbols(wstring verticalSymbol, wstring horizontalSymbol, wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol)
	{
		verticalBorderSymbol = verticalSymbol;
		horizontalBorderSymbol = horizontalSymbol;
		upperLeftBorderSymbol = upperLeftSymbol;
		upperRightBorderSymbol = upperRightSymbol;
		bottomLeftBorderSymbol = bottomLeftSymbol;
		bottomRightBorderSymbol = bottomRightSymbol;
	}
	~RectangleSymbols() {}
	wstring GetVerticalSymbol() const;
	wstring GetHorizontalSymbol() const;
	wstring GetUpperLeftSymbol() const;
	wstring GetUpperRightSymbol() const;
	wstring GetBottomLeftSymbol() const;
	wstring GetBottomRightSymbol() const;
};