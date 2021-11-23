#pragma once
#include <iostream>
#include <windows.h>
#include "msoftcon.h"
#include "drawheader.h"
using namespace std;
///////////////////drawMap Class///////////////////
void Visualisation::drawRectangle(int left_x, int up_y, int right_x, int bot_y)
{
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
}
void Visualisation::erasePixel(int _x, int _y)
{
	set_cursor_pos(_x, _y);
	cout << ' ';
}
void Visualisation::drawPlayingField(int left_x, int up_y, int right_x, int bot_y)
{
	set_color(cBLUE);
	drawRectangle(left_x, up_y, right_x, bot_y);
	for (int x = left_x + 32; x < right_x - 32; x++)
	{
		set_cursor_pos(x, bot_y);
		set_color(cGREEN);
		cout << (char)23;
	}
}
void Visualisation::drawVisitor(int _x, int _y)
{
	char VisitorSymbol = 'a';
	set_cursor_pos(_x, _y);
	cout << VisitorSymbol;
}
void Visualisation::drawBuilding(int left_x, int up_y, int right_x, int bot_y, const char ch)
{
	for (int j = up_y; j <= bot_y; j++)
	{
		for (int i = left_x; i <= right_x; i++)
		{
			set_cursor_pos(i, j);
			cout << ch;
		}
	}
}
void Visualisation::eraseBuilding(int left_x, int up_y, int right_x, int bot_y)
{
	for (int j = up_y; j <= bot_y; j++)
	{
		for (int i = left_x; i <= right_x; i++)
		{
			erasePixel(i, j);
		}
	}
}
void Visualisation::drawRoad(int _x, int _y, const char ch)
{
	set_cursor_pos(_x, _y);
	cout << ch;
}
void Visualisation::drawMenuBorders(int Menu_left_x, int Menu_up_y, int Menu_right_x, int Menu_bot_y, color MenuBorders)
{
	set_color(MenuBorders);
	drawRectangle(Menu_left_x, Menu_up_y, Menu_right_x, Menu_bot_y); //side menu borders
}
void Visualisation::drawIconBorders(int left_x, int up_y, int right_x, int bot_y, color IconBorders) //external border
{
	set_color(IconBorders);
	drawRectangle(left_x, up_y, right_x, bot_y);
}
void Visualisation::drawIcon(int left_x, int up_y, int cost, int dailyspend, const char symbol, string description, color Icon) //icon border
{
	set_color(cGREEN);
	drawRectangle(left_x, up_y, left_x + 3, up_y + 3);
	set_color(cDARK_GRAY);
	if (dailyspend != 0)
	{
		drawBuilding(left_x + 1, up_y + 1, left_x + 2, up_y + 2, symbol);
	}
	else
	{
		drawRoad(left_x + 1, up_y + 1, symbol);
	}
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
}