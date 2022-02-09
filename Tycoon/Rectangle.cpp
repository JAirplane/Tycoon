#include "Rectangle.h"
///////////////Rectangle///////////////
BorderAppearance* MyRectangle::GetBorder() const
{
	return border_ptr;
}
color MyRectangle::GetTextColor() const
{
	return textColor;
}
color MyRectangle::GetShadingColor() const
{
	return shadingColor;
}
Visualisation* MyRectangle::GetDrawPointer() const
{
	return draw_ptr;
}
Cursor* MyRectangle::GetCursor() const
{
	return cursor_ptr;
}
void MyRectangle::SetTextColor(color letterColor)
{
	textColor = letterColor;
}
void MyRectangle::SetShadingColor(color backgroundColor)
{
	shadingColor = backgroundColor;
}
void MyRectangle::DrawBorder()
{
	draw_ptr->DrawRectangle(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		GetBorder()->GetBorderSymbols()->GetVerticalSymbol(), GetBorder()->GetBorderSymbols()->GetHorizontalSymbol(), GetBorder()->GetBorderSymbols()->GetUpperLeftSymbol(),
		GetBorder()->GetBorderSymbols()->GetUpperRightSymbol(), GetBorder()->GetBorderSymbols()->GetBottomLeftSymbol(), GetBorder()->GetBorderSymbols()->GetBottomRightSymbol(),
		GetBorder()->GetBorderForegroundColor(), GetBorder()->GetBorderBackgroundColor());
}
void MyRectangle::EraseBorder()
{
	int leftX = GetUpperLeft().Get_x();
	int topY = GetUpperLeft().Get_y();
	for (topY; topY <= GetUpperLeft().Get_y() + GetHeightAddition(); topY++)
	{
		draw_ptr->ErasePixel(leftX, topY);
		draw_ptr->ErasePixel(leftX + GetWidthAddition(), topY);
	}
	topY = GetUpperLeft().Get_y();
	for (leftX; leftX <= GetUpperLeft().Get_x() + GetWidthAddition(); leftX++)
	{
		draw_ptr->ErasePixel(leftX, topY);
		draw_ptr->ErasePixel(leftX, topY + GetHeightAddition());
	}
}
void MyRectangle::ClearContent()
{
	int leftX = GetUpperLeft().Get_x() + 1;
	int topY = GetUpperLeft().Get_y() + 1;
	for (topY; topY < GetUpperLeft().Get_y() + GetHeightAddition(); topY++)
	{
		for (leftX; leftX < GetUpperLeft().Get_x() + GetWidthAddition(); leftX++)
		{
			draw_ptr->ErasePixel(leftX, topY);
		}
		leftX = GetUpperLeft().Get_x() + 1;
	}
}