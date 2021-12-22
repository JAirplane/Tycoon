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
	color foreground;
	color background;
public:
	RectangleSymbols(wstring verticalSymbol, wstring horizontalSymbol, wstring upperLeftSymbol, wstring upperRightSymbol,
		wstring bottomLeftSymbol, wstring bottomRightSymbol, color foreground = cBLACK, color background = cBLACK)
	{
		verticalBorderSymbol = verticalSymbol;
		horizontalBorderSymbol = horizontalSymbol;
		upperLeftBorderSymbol = upperLeftSymbol;
		upperRightBorderSymbol = upperRightSymbol;
		bottomLeftBorderSymbol = bottomLeftSymbol;
		bottomRightBorderSymbol = bottomRightSymbol;
		this->foreground = foreground;
		this->background = background;
	}
	~RectangleSymbols() {}
	wstring GetVerticalSymbol() const;
	wstring GetHorizontalSymbol() const;
	wstring GetUpperLeftSymbol() const;
	wstring GetUpperRightSymbol() const;
	wstring GetBottomLeftSymbol() const;
	wstring GetBottomRightSymbol() const;
	color GetForegroundColor() const;
	void SetForegroundColor(color foreground);
	color GetBackgroundColor() const;
	void SetBackgroundColor(color background);
};