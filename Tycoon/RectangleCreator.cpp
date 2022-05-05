#include "RectangleCreator.h"
RectangleCreator* RectangleCreator::CreateRectangleFactory()
{
	return new RectangleCreator();
}
RectangleCreator* RectangleCreator::GetRectangleFactory()
{
	return rectangleFactory;
}
RectangleSymbols* RectangleCreator::CreateRectangleSymbols(wstring verticalSymbol, wstring horizontalSymbol, wstring upperLeftSymbol,
	wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol)
{
	return new RectangleSymbols(verticalSymbol, horizontalSymbol, upperLeftSymbol, upperRightSymbol, bottomLeftSymbol, bottomRightSymbol);
}
BorderAppearance* RectangleCreator::CreateBorderAppearance(RectangleSymbols* borderSymbols, color borderForegroundColor, color borderBackgroundColor)
{
	return new BorderAppearance(borderSymbols, borderForegroundColor, borderBackgroundColor);
}
MyRectangle* RectangleCreator::CreateRectangle(PointCoord upperLeft, int heightAdd, int widthAdd, wstring verticalSymbol, wstring horizontalSymbol,
	wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol, color borderForegroundColor,
	color borderBackgroundColor, color letterColor, color shadingColor, Visualisation* draw_ptr, Cursor* cursor_ptr)
{
	RectangleSymbols* borderSymbols = CreateRectangleSymbols(verticalSymbol, horizontalSymbol, upperLeftSymbol, upperRightSymbol,
		bottomLeftSymbol, bottomRightSymbol);
	BorderAppearance* border = CreateBorderAppearance(borderSymbols, borderForegroundColor, borderBackgroundColor);
	return new MyRectangle(upperLeft, heightAdd, widthAdd, border, letterColor, shadingColor, draw_ptr, cursor_ptr);
}
RectangleCreator* RectangleCreator::rectangleFactory = RectangleCreator::CreateRectangleFactory();