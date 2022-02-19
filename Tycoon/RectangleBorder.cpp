#include "RectangleBorder.h"
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
///////////////Border Appearance///////////////
const RectangleSymbols* BorderAppearance::GetBorderSymbols() const
{
	if(borderSymbols_ptr == nullptr)
	{
		throw MyException("BorderAppearance::GetBorderSymbols() borderSymbols_ptr is nullptr.");
	}
	return borderSymbols_ptr;
}
color BorderAppearance::GetBorderForegroundColor() const
{
	return borderForegroundColor;
}
color BorderAppearance::GetBorderBackgroundColor() const
{
	return borderBackgroundColor;
}
void BorderAppearance::SetBorderForegroundColor(color newColor)
{
	borderForegroundColor = newColor;
}
void BorderAppearance::SetBorderBackgroundColor(color newColor)
{
	borderBackgroundColor = newColor;
}