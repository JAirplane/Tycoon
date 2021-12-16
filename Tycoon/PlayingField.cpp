#include "PlayingField.h"
/////////////PlayingField Class/////////////
char PlayingField::GetVerticalSymbol() const
{
	return verticalBorderSymbol;
}
char PlayingField::GetHorizontalSymbol() const
{
	return horizontalBorderSymbol;
}
char PlayingField::GetUpperLeftSymbol() const
{
	return upperLeftBorderSymbol;
}
char PlayingField::GetUpperRightSymbol() const
{
	return upperRightBorderSymbol;
}
char PlayingField::GetBottomLeftSymbol() const
{
	return bottomLeftBorderSymbol;
}
char PlayingField::GetBottomRightSymbol() const
{
	return bottomRightBorderSymbol;
}