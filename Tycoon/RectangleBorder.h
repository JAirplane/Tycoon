#pragma once
#include "ConstructionOptions.h"
/////////////Contains Symbols to Draw Rectangle/////////////
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
	RectangleSymbols(wstring verticalSymbol, wstring horizontalSymbol, wstring upperLeftSymbol, wstring upperRightSymbol,
		wstring bottomLeftSymbol, wstring bottomRightSymbol)
	{
		verticalBorderSymbol = verticalSymbol;
		horizontalBorderSymbol = horizontalSymbol;
		upperLeftBorderSymbol = upperLeftSymbol;
		upperRightBorderSymbol = upperRightSymbol;
		bottomLeftBorderSymbol = bottomLeftSymbol;
		bottomRightBorderSymbol = bottomRightSymbol;
	}
	RectangleSymbols(const RectangleSymbols& symbols_ptr)
	{
		verticalBorderSymbol = symbols_ptr.GetVerticalSymbol();
		horizontalBorderSymbol = symbols_ptr.GetHorizontalSymbol();
		upperLeftBorderSymbol = symbols_ptr.GetUpperLeftSymbol();
		upperRightBorderSymbol = symbols_ptr.GetUpperRightSymbol();
		bottomLeftBorderSymbol = symbols_ptr.GetBottomLeftSymbol();
		bottomRightBorderSymbol = symbols_ptr.GetBottomRightSymbol();
	}
	~RectangleSymbols() {}
	wstring GetVerticalSymbol() const;
	wstring GetHorizontalSymbol() const;
	wstring GetUpperLeftSymbol() const;
	wstring GetUpperRightSymbol() const;
	wstring GetBottomLeftSymbol() const;
	wstring GetBottomRightSymbol() const;
};
///////////////Border Appearance: Symbols plus Color///////////////
class BorderAppearance
{
private:
	RectangleSymbols* borderSymbols_ptr;
	color borderForegroundColor;
	color borderBackgroundColor;
public:
	BorderAppearance(RectangleSymbols* symbols_ptr, color foreground, color background) : 
		borderSymbols_ptr(symbols_ptr), borderForegroundColor(foreground), borderBackgroundColor(background)
		{}
	BorderAppearance(const BorderAppearance& borderVisual)
	{
		borderSymbols_ptr = new RectangleSymbols(*(borderVisual.GetBorderSymbols()));
		borderForegroundColor = borderVisual.GetBorderForegroundColor();
		borderBackgroundColor = borderVisual.GetBorderBackgroundColor();
	}
	~BorderAppearance()
	{
		delete borderSymbols_ptr;
	}
	const RectangleSymbols* GetBorderSymbols() const;
	color GetBorderForegroundColor() const;
	color GetBorderBackgroundColor() const;
	void SetBorderForegroundColor(color newColor);
	void SetBorderBackgroundColor(color newColor);
};
