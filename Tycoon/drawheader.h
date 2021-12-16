#pragma once
#include <iostream>
#include "msoftcon.h"
using namespace std;
const int Menu_left_x = 71;
const int Menu_up_y = 1;
const int Menu_right_x = 95;
const int Menu_bot_y = 35;
class Visualisation
{
public:
	Visualisation()
	{
		init_graphics();
	}
	void drawRectangle(int left_x, int up_y, int right_x, int bot_y, color foreground, color background = cBLACK);
	void drawCursorPixel(int _x, int _y, color background = cBLACK);
	void erasePixel(int _x, int _y);
	void drawIcon(int left_x, int up_y, int Bcost, int dailyspend, const char symbol, string description, color foreground, color background = cBLACK);
	void drawVisitor(int _x, int _y);
	void DrawConstruction(int left_x, int up_y, int right_x, int bot_y, const char ch, color foreground, color background = cBLACK);
	void EraseConstruction(int left_x, int up_y, int right_x, int bot_y);
};