#include "Rectangle.h"
///////////////Rectangle///////////////
BorderAppearance* MyRectangle::GetBorder() const
{
	if (border_ptr == nullptr)
	{
		throw MyException("MyRectangle::GetBorder() border_ptr is nullptr.");
	}
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
	if (draw_ptr == nullptr)
	{
		throw MyException("MyRectangle::GetDrawPointer() draw_ptr is nullptr.");
	}
	return draw_ptr;
}
Cursor* MyRectangle::GetCursor() const
{
	if (cursor_ptr == nullptr)
	{
		throw MyException("MyRectangle::GetCursor() cursor_ptr is nullptr.");
	}
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
void MyRectangle::DrawBorder() const
{
	draw_ptr->DrawRectangle(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		GetBorder()->GetBorderSymbols()->GetVerticalSymbol(), GetBorder()->GetBorderSymbols()->GetHorizontalSymbol(), GetBorder()->GetBorderSymbols()->GetUpperLeftSymbol(),
		GetBorder()->GetBorderSymbols()->GetUpperRightSymbol(), GetBorder()->GetBorderSymbols()->GetBottomLeftSymbol(), GetBorder()->GetBorderSymbols()->GetBottomRightSymbol(),
		GetBorder()->GetBorderForegroundColor(), GetBorder()->GetBorderBackgroundColor());
}
void MyRectangle::EraseBorder() const
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
bool MyRectangle::IsLocationOnTheBorder(PointCoord location) const
{
	if (((GetUpperLeft().Get_x() == location.Get_x() || GetUpperLeft().Get_x() + GetWidthAddition() == location.Get_x()) && GetUpperLeft().Get_y() <= location.Get_y() &&
		GetUpperLeft().Get_y() + GetHeightAddition() >= location.Get_y()) || ((GetUpperLeft().Get_y() == location.Get_y() || GetUpperLeft().Get_y() + GetHeightAddition() == location.Get_y()) &&
			GetUpperLeft().Get_x() <= location.Get_x() && GetUpperLeft().Get_x() + GetWidthAddition() >= location.Get_x()))
	{
		return true;
	}
	return false;
}
bool MyRectangle::IsObjectInsideTheRectangle(const GlobalObject* object_ptr) const
{
	if (object_ptr == nullptr)
	{
		throw MyException("MyRectangle::IsObjectInsideTheRectangle(IngameObject* object_ptr) received nullptr argument object_ptr.");
	}
	int xCoord = object_ptr->GetUpperLeft().Get_x();
	int yCoord = object_ptr->GetUpperLeft().Get_y();
	int objectHeightAdd = object_ptr->GetHeightAddition();
	int objectWidthAdd = object_ptr->GetWidthAddition();
	for (yCoord; yCoord <= object_ptr->GetUpperLeft().Get_y() + objectHeightAdd; yCoord++)
	{
		for (xCoord; xCoord <= object_ptr->GetUpperLeft().Get_x() + objectWidthAdd; xCoord++)
		{
			if (yCoord <= GetUpperLeft().Get_y() || yCoord >= GetUpperLeft().Get_y() + GetHeightAddition() || xCoord <= GetUpperLeft().Get_x() || xCoord >= GetUpperLeft().Get_x() + GetWidthAddition())
			{
				return false;
			}
		}
		xCoord = object_ptr->GetUpperLeft().Get_x();
	}
	return true;
}