#pragma once
#include <iostream>
#include <windows.h>
#include "msoftcon.h"
#include "drawheader.h"
using namespace std;
///////////////////drawMap Class///////////////////
void Visualisation::drawRectangle(int left_x, int up_y, int right_x, int bot_y, color foreground, color background)
{
	set_color(foreground, background);
	for (int y = up_y + 1; y < bot_y; y++)
	{
		set_cursor_pos(left_x, y);
		cout << (char)186 << "\n";
	}
	for (int y = up_y + 1; y < bot_y; y++)
	{
		set_cursor_pos(right_x, y);
		cout << (char)186;
	}
	for (int x = left_x + 1; x < right_x; x++)
	{
		set_cursor_pos(x, up_y);
		cout << (char)205;
	}
	for (int x = left_x + 1; x < right_x; x++)
	{
		set_cursor_pos(x, bot_y);
		cout << (char)205;
	}
	set_cursor_pos(right_x, up_y);
	cout << (char)187;
	set_cursor_pos(right_x, bot_y);
	cout << (char)188;
	set_cursor_pos(left_x, bot_y);
	cout << (char)200;
	set_cursor_pos(left_x, up_y);
	cout << (char)201;
	set_color(cYELLOW);
}
void Visualisation::erasePixel(int _x, int _y)
{
	set_color(cBLACK);
	set_cursor_pos(_x, _y);
	cout << ' ';
}
void Visualisation::drawCursorPixel(int _x, int _y, color background)
{
	set_cursor_pos(_x, _y);
	set_color(cBLACK, background);
	cout << ' ';
	set_cursor_pos(_x, _y);
}
void Visualisation::drawVisitor(int _x, int _y)
{
	char VisitorSymbol = 'a';
	set_cursor_pos(_x, _y);
	cout << VisitorSymbol;
	set_color(cYELLOW);
}
void Visualisation::DrawConstruction(int left_x, int up_y, int right_x, int bot_y, const char ch, color foreground, color background)
{
	set_color(foreground, background);
	for (int j = up_y; j <= bot_y; j++)
	{
		for (int i = left_x; i <= right_x; i++)
		{
			set_cursor_pos(i, j);
			cout << ch;
		}
	}
	set_color(cYELLOW);
}
void Visualisation::EraseConstruction(int left_x, int up_y, int right_x, int bot_y)
{
	for (int j = up_y; j <= bot_y; j++)
	{
		for (int i = left_x; i <= right_x; i++)
		{
			erasePixel(i, j);
		}
	}
}
void Visualisation::drawIcon(int left_x, int up_y, int cost, int dailyspend, const char iconsymbol, string description, color foreground, color background) //icon border
{
	drawRectangle(left_x, up_y, left_x + 3, up_y + 3, cGREEN);
	DrawConstruction(left_x + 1, up_y + 1, left_x + 2, up_y + 2, iconsymbol, foreground, background);
	set_cursor_pos(left_x + 4, up_y);
	set_color(cLIGHT_GRAY);
	cout << description;
	set_cursor_pos(left_x + 4, up_y + 1);
	cout << "Construction Cost: " << cost;
	set_cursor_pos(left_x + 4, up_y + 2);
	if (dailyspend != 0)
	{
		cout << "Service will cost you " << dailyspend << " per day.";
	}
	set_color(cYELLOW);
}