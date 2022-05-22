#pragma once
#include "Button.h"
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
	MyRectangle& CreateRectangle(PointCoord upperLeft, int heightAdd, int widthAdd, wstring verticalSymbol, wstring horizontalSymbol,
		wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol, color borderForegroundColor,
		color borderBackgroundColor, color letterColor, color shadingColor, Visualisation* draw_ptr, Cursor* cursor_ptr) const;
	MyRectangle& CreateRectangle(PointCoord upperLeft, RectangleConstantsXML downloadedConstants, Visualisation* draw_ptr, Cursor* cursor_ptr) const;
	Button& CreateButton(PointCoord upperLeft, int heightAdd, int widthAdd, wstring verticalSymbol, wstring horizontalSymbol,
		wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol, color borderForegroundColor,
		color borderBackgroundColor, color letterColor, color shadingColor, string buttonTitle, color activeColor,
		color pressedButtonColor, Visualisation* draw_ptr, Cursor* cursor_ptr) const;
	Button& CreateButton(PointCoord upperLeft, ButtonConstantsXML downloadedConstants, Visualisation* draw_ptr, Cursor* cursor_ptr) const;
};