#include "RectangleSymbols.h"
/////////////Symbols to Draw Rectangle Class/////////////
wstring RectangleSymbols::GetVerticalSymbol() const
{
	return verticalBorderSymbol;
}
wstring RectangleSymbols::GetHorizontalSymbol() const
{
	return horizontalBorderSymbol;
}
wstring RectangleSymbols::GetUpperLeftSymbol() const
{
	return upperLeftBorderSymbol;
}
wstring RectangleSymbols::GetUpperRightSymbol() const
{
	return upperRightBorderSymbol;
}
wstring RectangleSymbols::GetBottomLeftSymbol() const
{
	return bottomLeftBorderSymbol;
}
wstring RectangleSymbols::GetBottomRightSymbol() const
{
	return bottomRightBorderSymbol;
}
color RectangleSymbols::GetForegroundColor() const
{
	return foreground;
}
void RectangleSymbols::SetForegroundColor(color foreground)
{
	this->foreground = foreground;
}
color RectangleSymbols::GetBackgroundColor() const
{
	return background;
}
void RectangleSymbols::SetBackgroundColor(color background)
{
	this->background = background;
}