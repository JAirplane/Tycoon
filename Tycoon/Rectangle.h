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
public:
	MyRectangle(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor,
		Visualisation* vis_ptr, Cursor* cur_ptr) : GlobalObject(upperLeft, heightAdd, widthAdd), draw_ptr(vis_ptr), cursor_ptr(cur_ptr)
	{
		border_ptr = borderApp_ptr;
		textColor = letterColor;
		shadingColor = backgroundColor;
	}
	MyRectangle()
	{
		draw_ptr = nullptr;
		cursor_ptr = nullptr;
		border_ptr = nullptr;
		textColor = cBLACK;
		shadingColor = cBLACK;
	}
	MyRectangle(MyRectangle& anotherRectangle) : GlobalObject(anotherRectangle.GetUpperLeft(), anotherRectangle.GetHeightAddition(), anotherRectangle.GetWidthAddition())
	{
		border_ptr = new BorderAppearance(anotherRectangle.GetBorder());
		textColor = anotherRectangle.GetTextColor();
		shadingColor = anotherRectangle.GetShadingColor();
		draw_ptr = anotherRectangle.GetDrawPointer();
		cursor_ptr = anotherRectangle.GetCursor();
	}
	virtual ~MyRectangle()
	{
		delete border_ptr;
	}
	BorderAppearance* GetBorder() const;
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