#pragma once
#include "Rectangle.h"
class RectangleCreator
{
protected:
	static RectangleCreator* rectangleFactory;
	RectangleSymbols* CreateRectangleSymbols(wstring verticalSymbol, wstring horizontalSymbol, wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol);
	BorderAppearance* CreateBorderAppearance(RectangleSymbols* borderSymbols, color borderForegroundColor, color borderBackgroundColor);
public:
	RectangleCreator() {}
	virtual ~RectangleCreator()
	{
		delete rectangleFactory;
	}
	RectangleCreator(RectangleCreator& other) = delete;
	void operator=(const RectangleCreator&) = delete;
	static RectangleCreator* CreateRectangleFactory();
	static RectangleCreator* GetRectangleFactory();
	MyRectangle* CreateRectangle(PointCoord upperLeft, int heightAdd, int widthAdd, wstring verticalSymbol, wstring horizontalSymbol,
		wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol, color borderForegroundColor,
		color borderBackgroundColor, color letterColor, color shadingColor, Visualisation* draw_ptr, Cursor* cursor_ptr);
};