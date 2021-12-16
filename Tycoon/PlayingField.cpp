#include "PlayingField.h"
/////////////PlayingField Class/////////////
wchar_t PlayingField::GetVerticalSymbol() const
{
	return verticalBorderSymbol;
}
wchar_t PlayingField::GetHorizontalSymbol() const
{
	return horizontalBorderSymbol;
}
wchar_t PlayingField::GetUpperLeftSymbol() const
{
	return upperLeftBorderSymbol;
}
wchar_t PlayingField::GetUpperRightSymbol() const
{
	return upperRightBorderSymbol;
}
wchar_t PlayingField::GetBottomLeftSymbol() const
{
	return bottomLeftBorderSymbol;
}
wchar_t PlayingField::GetBottomRightSymbol() const
{
	return bottomRightBorderSymbol;
}