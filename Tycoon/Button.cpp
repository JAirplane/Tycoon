#include "Button.h"
///////////////InfoScreen Button///////////////
string Button::GetButtonTitle() const
{
	return title;
}
void Button::Display() const
{
	DrawBorder();
	if(title.empty())
	{
		throw MyException("Button::Display() button has an empty title string.");
	}
	int length = (int)title.length();
	set_color(GetTextColor(), GetShadingColor());
	int addToLeftX = (GetWidthAddition() - 1 - length) / 2;
	set_cursor_pos(GetUpperLeft().Get_x() + 1 + addToLeftX, GetHalfYAxis());
	cout << title;
}