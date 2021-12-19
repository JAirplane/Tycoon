#include "PlayingField.h"
/////////////PlayingField Class/////////////
wstring PlayingField::GetVerticalSymbol() const
{
	return verticalBorderSymbol;
}
wstring PlayingField::GetHorizontalSymbol() const
{
	return horizontalBorderSymbol;
}
wstring PlayingField::GetUpperLeftSymbol() const
{
	return upperLeftBorderSymbol;
}
wstring PlayingField::GetUpperRightSymbol() const
{
	return upperRightBorderSymbol;
}
wstring PlayingField::GetBottomLeftSymbol() const
{
	return bottomLeftBorderSymbol;
}
wstring PlayingField::GetBottomRightSymbol() const
{
	return bottomRightBorderSymbol;
}