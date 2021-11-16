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
	{ }
	void drawRectangle(int left_x, int up_y, int right_x, int bot_y);
	void drawPlayingField(int left_x, int up_y, int right_x, int bot_y);
	void drawMenu_RightSide(int Menu_left_x, int Menu_up_y, int Menu_right_x, int Menu_bot_y);
	void drawMenu_LeftSide(int Menu_left_x, int Menu_up_y, int Menu_right_x, int Menu_bot_y);
	void drawIceIcon(int left_x, int up_y, int Bcost, int dailyspend, const char symbol);
	void drawIcon(int left_x, int up_y, int Bcost, int dailyspend, const char symbol);
	void drawRoadIcon(int left_x, int up_y, int Rcost);
	void drawVisitor(int _x, int _y);
	void eraseVisitor(int _x, int _y);
	void drawBuilding(int left_x, int up_y, int right_x, int bot_y, const char ch);
	void eraseBuilding(int left_x, int up_y, int right_x, int bot_y);
	void drawRoad(int _x, int _y, const char ch);
	void eraseRoad(int _x, int _y);

};