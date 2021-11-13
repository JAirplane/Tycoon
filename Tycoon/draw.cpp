#pragma once
#include <iostream>
#include <windows.h>
#include "msoftcon.h"
#include "drawheader.h"
using namespace std;
///////////////////drawMap Class///////////////////
void Visualisation::drawRectangle(int right_x, int up_y, int left_x, int bot_y)
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
void Visualisation::drawWorld()
{
	init_graphics();
	set_color(cBLUE);
	//for (int i = 0; i < 256; i++)
	//{
	//	cout << i << ": " << (char)i;
	//}
	drawRectangle(70, 1, 1, 35);
	for (int x = 33; x < 38; x++)
	{
		set_cursor_pos(x, 35);
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
void Visualisation::eraseVisitor(int _x, int _y)
{
	set_cursor_pos(_x, _y);
	cout << ' ';
}
void Visualisation::drawBuilding(int right_x, int up_y, int left_x, int bot_y, const char ch)
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
void Visualisation::eraseBuilding(int right_x, int up_y, int left_x, int bot_y)
{
	for (int j = up_y; j >= bot_y; j--)
	{
		for (int i = left_x; i <= right_x; i++)
		{
			set_cursor_pos(i, j);
			cout << ' ';
		}
	}
}
void Visualisation::drawRoad(int _x, int _y, const char ch)
{
	set_cursor_pos(_x, _y);
	cout << ch;
}
void Visualisation::eraseRoad(int _x, int _y)
{
	set_cursor_pos(_x, _y);
	cout << ' ';
}
void Visualisation::drawMenu()
{
	set_color(cBLUE);
	drawRectangle(95, 1, 71, 35);
}
void Visualisation::drawIceCreamIcon(int right_x, int up_y, int left_x, int bot_y, int Bcost, int dailyspend)
{
	set_color(cGREEN);
	drawRectangle(right_x, up_y, left_x, bot_y);
	set_color(cYELLOW);
	drawBuilding(right_x - 1, up_y + 1, left_x + 1, bot_y - 1, '!');
	set_cursor_pos(right_x + 2, up_y);
	set_color(cLIGHT_GRAY);
	cout << "Ice Cream Shop! Everybody loves it!";
	set_cursor_pos(right_x + 2, up_y + 1);
	cout << "Building Cost: " << Bcost;
	set_cursor_pos(right_x + 2, up_y + 2);
	cout << "Service will cost you " << dailyspend << " per day.";
}