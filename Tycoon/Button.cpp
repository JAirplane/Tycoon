#include "Button.h"
///////////////InfoScreen Button///////////////
string Button::GetButtonTitle() const
{
	return title;
}
void Button::Display() const
{
	DrawBorder();
	int length = (int)title.length();
	set_color(GetTextColor(), GetShadingColor());
	if (length > GetWidthAddition() - 1)
	{
		string truncatedTitle = title.substr(0, (size_t)(GetWidthAddition() - 1));
		set_cursor_pos(GetUpperLeft().Get_x() + 1, GetHalfYAxis());
		cout << truncatedTitle;
	}
	else
	{
		int addToLeftX = (GetWidthAddition() - 1 - length) / 2;
		set_cursor_pos(GetUpperLeft().Get_x() + 1 + addToLeftX, GetHalfYAxis());
		cout << GetButtonTitle();
	}
}