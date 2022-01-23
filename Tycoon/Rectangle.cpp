#include "Rectangle.h"
///////////////Rectangle///////////////
const BorderAppearance* MyRectangle::GetBorder() const
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
void MyRectangle::SetTextColor(color letterColor)
{
	textColor = letterColor;
}
void MyRectangle::SetShadingColor(color backgroundColor)
{
	shadingColor = backgroundColor;
}