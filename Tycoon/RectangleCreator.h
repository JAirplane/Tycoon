#pragma once
#include "RectangleWithButtons.h"
class RectangleCreator
{
protected:
	static RectangleCreator* rectangleFactory;
	RectangleSymbols* CreateRectangleSymbols(wstring verticalSymbol, wstring horizontalSymbol, wstring upperLeftSymbol, wstring upperRightSymbol,
		wstring bottomLeftSymbol, wstring bottomRightSymbol) const;
	BorderAppearance* CreateBorderAppearance(RectangleSymbols* borderSymbols, color borderForegroundColor, color borderBackgroundColor) const;
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
	MyRectangle* CreateRectangle(PointCoord upperLeft, RectangleConstantsXML* downloadedConstants, Visualisation* draw_ptr, Cursor* cursor_ptr) const;
	Button* CreateButton(PointCoord upperLeft, RectangleConstantsXML* downloadedConstants, Visualisation* draw_ptr, Cursor* cursor_ptr) const;
};