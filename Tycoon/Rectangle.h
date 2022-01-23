#pragma once
#include "GlobalObject.h"
class MyRectangle : public GlobalObject
{
private:
	BorderAppearance* border_ptr;
	color textColor;
	color shadingColor;
public:
	MyRectangle(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor) : GlobalObject(upperLeft, heightAdd, widthAdd)
	{
		border_ptr = borderApp_ptr;
		textColor = letterColor;
		shadingColor = backgroundColor;
	}
	~MyRectangle()
	{
		delete border_ptr;
	}
	const BorderAppearance* GetBorder() const;
	color GetTextColor() const;
	color GetShadingColor() const;
	void SetTextColor(color letterColor);
	void SetShadingColor(color backgroundColor);
};
