#pragma once
#include <iostream>
#include <windows.h>
#include "msoftcon.h"
#include "logicheader.h"
using namespace std;
///////////////////drawMap Class///////////////////
void drawMap::drawWorld()
{
	init_graphics();
	set_color(cBLUE);
	//for (int i = 0; i < 256; i++)
	//{
	//	cout << i << ": " << (char)i;
	//}
	for (int y = 2; y < 35; y++)
	{
		set_cursor_pos(1, y);
		cout << (char)186 << "\n";
	}
	for (int y = 2; y < 35; y++)
	{
		set_cursor_pos(70, y);
		cout << (char)186;
	}
	for (int x = 2; x < 70; x++)
	{
		set_cursor_pos(x, 1);
		cout << (char)205;
	}
	for (int x = 2; x < 70; x++)
	{
		set_cursor_pos(x, 35);
		cout << (char)205;
	}
	for (int x = 33; x < 38; x++)
	{
		set_cursor_pos(x, 35);
		set_color(cGREEN);
		cout << (char)23;
	}
	set_color(cBLUE);
	set_cursor_pos(70, 1);
	cout << (char)187;
	set_cursor_pos(70, 35);
	cout << (char)188;
	set_cursor_pos(1, 35);
	cout << (char)200;
	set_cursor_pos(1, 1);
	cout << (char)201;
	set_cursor_pos(1, 36);
	set_color(cYELLOW);
}
void drawVisitor::drawVis()
{

}
void drawConstruction::drawConst(int right_x, int up_y, int left_x, int bot_y)
{
	set_cursor_pos(right_x, up_y);
	cout << "!";
	set_cursor_pos(left_x, up_y);
	cout << "!";
	set_cursor_pos(right_x, bot_y);
	cout << "!";
	set_cursor_pos(left_x, bot_y);
	cout << "!";
}