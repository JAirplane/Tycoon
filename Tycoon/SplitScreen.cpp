#include "SplitScreen.h"
void SplitScreen::DrawBorder()
{
	MyRectangle::DrawBorder();
	int midX = GetHalfXAxis();
	int topY = GetUpperLeft().Get_y();
	int bottomY = GetUpperLeft().Get_y() + GetHeightAddition();
	_setmode(_fileno(stdout), _O_U16TEXT);
	set_color(GetBorder()->GetBorderForegroundColor(), GetBorder()->GetBorderBackgroundColor());
	for (int y = topY + 1; y < bottomY; y++)
	{
		set_cursor_pos(midX, y);
		wcout << L"\u205E";
	}
	_setmode(_fileno(stdout), _O_TEXT);
}
void SplitScreen::EraseBorder()
{
	MyRectangle::EraseBorder();
	int midX = GetHalfXAxis();
	int topY = GetUpperLeft().Get_y();
	int bottomY = GetUpperLeft().Get_y() + GetHeightAddition();
	set_color(GetBorder()->GetBorderForegroundColor(), GetBorder()->GetBorderBackgroundColor());
	for (int y = topY + 1; y < bottomY; y++)
	{
		set_cursor_pos(midX, y);
		cout << " ";
	}
}