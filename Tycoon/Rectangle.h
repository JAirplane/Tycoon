#pragma once
#include "Cursor.h"
#include "drawheader.h"
class MyRectangle : public GlobalObject
{
private:
	Visualisation* draw_ptr;
	Cursor* cursor_ptr;
	BorderAppearance* border_ptr;
	color textColor;
	color shadingColor;
	RectangleConstantsXML* initialCondition;
public:
	MyRectangle(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) :
		GlobalObject(upperLeft, initial->heightAddition, initial->widthAddition), draw_ptr(vis_ptr), cursor_ptr(cur_ptr)
	{
		RectangleSymbols* borderSymbols = new RectangleSymbols(initial->borderSymbolVertical, initial->borderSymbolHorizontal, initial->borderSymbolUpperLeft,
			initial->borderSymbolUpperRight, initial->borderSymbolBottomLeft, initial->borderSymbolBottomRight);
		border_ptr = new BorderAppearance(borderSymbols, initial->foregroundBorderColor, initial->backgroundBorderColor);
		textColor = initial->foregroundContentColor;
		shadingColor = initial->backgroundContentColor;
		initialCondition = initial;
	}
	MyRectangle()
	{
		draw_ptr = nullptr;
		cursor_ptr = nullptr;
		border_ptr = nullptr;
		textColor = cBLACK;
		shadingColor = cBLACK;
		initialCondition = nullptr;
	}
	MyRectangle(MyRectangle& anotherRectangle) : GlobalObject(anotherRectangle.GetUpperLeft(), anotherRectangle.GetHeightAddition(), anotherRectangle.GetWidthAddition())
	{
		border_ptr = new BorderAppearance(anotherRectangle.GetBorder());
		textColor = anotherRectangle.GetTextColor();
		shadingColor = anotherRectangle.GetShadingColor();
		draw_ptr = anotherRectangle.GetDrawPointer();
		cursor_ptr = anotherRectangle.GetCursor();
		initialCondition = anotherRectangle.GetInitialCondition();
	}
	virtual ~MyRectangle()
	{
		delete border_ptr;
	}
	BorderAppearance* GetBorder() const;
	RectangleConstantsXML* GetInitialCondition() const;
	color GetTextColor() const;
	color GetShadingColor() const;
	Visualisation* GetDrawPointer() const;
	Cursor* GetCursor() const;
	void SetTextColor(color letterColor);
	void SetShadingColor(color backgroundColor);
	virtual void DrawBorder() const;
	virtual void EraseBorder() const;
	void ClearContent() const;
	bool IsLocationOnTheBorder(PointCoord location) const;
	bool IsObjectInsideTheRectangle(const GlobalObject* object_ptr) const;
};