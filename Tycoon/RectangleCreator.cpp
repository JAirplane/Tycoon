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
	wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol) const
{
	return new RectangleSymbols(verticalSymbol, horizontalSymbol, upperLeftSymbol, upperRightSymbol, bottomLeftSymbol, bottomRightSymbol);
}
BorderAppearance* RectangleCreator::CreateBorderAppearance(RectangleSymbols* borderSymbols, color borderForegroundColor, color borderBackgroundColor) const
{
	return new BorderAppearance(borderSymbols, borderForegroundColor, borderBackgroundColor);
}
MyRectangle* RectangleCreator::CreateRectangle(PointCoord upperLeft, RectangleConstantsXML downloadedConstants, Visualisation* draw_ptr, Cursor* cursor_ptr) const
{
	RectangleSymbols* borderSymbols = CreateRectangleSymbols(downloadedConstants.borderSymbolVertical, downloadedConstants.borderSymbolHorizontal,
		downloadedConstants.borderSymbolUpperLeft, downloadedConstants.borderSymbolUpperRight, downloadedConstants.borderSymbolBottomLeft,
		downloadedConstants.borderSymbolBottomRight);
	BorderAppearance* border = CreateBorderAppearance(borderSymbols, downloadedConstants.foregroundBorderColor, downloadedConstants.backgroundBorderColor);
	MyRectangle* created = new MyRectangle(upperLeft, &downloadedConstants, draw_ptr, cursor_ptr);
	return created;
}
Button* RectangleCreator::CreateButton(PointCoord upperLeft, RectangleConstantsXML downloadedConstants, Visualisation* draw_ptr, Cursor* cursor_ptr) const
{
	RectangleSymbols* borderSymbols = CreateRectangleSymbols(downloadedConstants.borderSymbolVertical, downloadedConstants.borderSymbolHorizontal,
		downloadedConstants.borderSymbolUpperLeft, downloadedConstants.borderSymbolUpperRight, downloadedConstants.borderSymbolBottomLeft,
		downloadedConstants.borderSymbolBottomRight);
	BorderAppearance* border = CreateBorderAppearance(borderSymbols, downloadedConstants.foregroundBorderColor, downloadedConstants.backgroundBorderColor);
	Button* created = new Button(upperLeft, &downloadedConstants, draw_ptr, cursor_ptr);
	return created;
}
RectangleCreator* RectangleCreator::rectangleFactory = RectangleCreator::CreateRectangleFactory();