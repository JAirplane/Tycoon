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
	void drawRectangle(int left_x, int up_y, int right_x, int bot_y);
	void erasePixel(int _x, int _y);
	void drawPlayingField(int left_x, int up_y, int right_x, int bot_y);
	void drawMenuBorders(int Menu_left_x, int Menu_up_y, int Menu_right_x, int Menu_bot_y, color MenuBorders);
	void drawIconBorders(int left_x, int up_y, int right_x, int bot_y, color IconBorders);
	void drawIcon(int left_x, int up_y, int Bcost, int dailyspend, const char symbol, string description, color Icon);
	void drawVisitor(int _x, int _y);
	void eraseVisitor(int _x, int _y);
	void drawBuilding(int left_x, int up_y, int right_x, int bot_y, const char ch);
	void eraseBuilding(int left_x, int up_y, int right_x, int bot_y);
	void drawRoad(int _x, int _y, const char ch);
};