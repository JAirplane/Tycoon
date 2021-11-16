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
void Visualisation::drawPlayingField(int left_x, int up_y, int right_x, int bot_y)
{
	init_graphics();
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
void Visualisation::eraseVisitor(int _x, int _y)
{
	set_cursor_pos(_x, _y);
	cout << ' ';
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
void Visualisation::drawMenu_RightSide(int Menu_left_x, int Menu_up_y, int Menu_right_x, int Menu_bot_y)
{
	set_color(cBLUE);
	drawRectangle(Menu_left_x, Menu_up_y, Menu_right_x, Menu_bot_y); //right side menu borders

	set_color(cYELLOW);
	drawRectangle(Menu_left_x + 2, Menu_up_y + 9, Menu_right_x - 2, Menu_up_y + 15); //external border
	set_color(cGREEN);
	drawRectangle(Menu_left_x + 3, Menu_up_y + 10, Menu_left_x + 7, Menu_up_y + 14); //icon border
	set_color(cYELLOW);
	drawRectangle(Menu_left_x + 2, Menu_up_y + 17, Menu_right_x - 2, Menu_up_y + 23); //external border
	set_color(cGREEN);
	drawRectangle(Menu_left_x + 3, Menu_up_y + 18, Menu_left_x + 7, Menu_up_y + 22); //icon border
	set_color(cYELLOW);
	drawRectangle(Menu_left_x + 2, Menu_up_y + 25, Menu_right_x - 2, Menu_up_y + 31); //external border
	set_color(cGREEN);
	drawRectangle(Menu_left_x + 3, Menu_up_y + 26, Menu_left_x + 7, Menu_up_y + 30); //icon border
}
void Visualisation::drawIcon(int left_x, int up_y, int Bcost, int dailyspend, const char symbol)
{
	set_color(cYELLOW);
	drawRectangle(left_x, up_y, left_x + 20, up_y + 6); //external border
	set_color(cGREEN);
	drawRectangle(left_x + 1, up_y + 1, left_x + 5, up_y + 5); //icon border
	set_color(cDARK_GRAY);
	drawBuilding(left_x, up_y, left_x + 1, up_y + 1, symbol);
	set_cursor_pos(left_x + 3, up_y);
	set_color(cLIGHT_GRAY);
	cout << "Ice Cream Shop! Everybody loves it!";
	set_cursor_pos(left_x + 3, up_y + 1);
	cout << "Construction Cost: " << Bcost;
	set_cursor_pos(left_x + 3, up_y + 2);
	cout << "Service will cost you " << dailyspend << " per day.";
}
void drawRoadIcon(int left_x, int up_y, int Rcost)
{
	set_color(cDARK_GRAY);
	set_cursor_pos(left_x, up_y);
	cout << '+';
	set_color(cLIGHT_GRAY);
	cout << "Your visitors can walk roads only";
	set_cursor_pos(left_x + 3, up_y + 1);
	cout << "Construction Cost: " << Rcost;
}