#pragma once
#include <iostream>
#include "msoftcon.h"
using namespace std;
class Visualisation
{
public:
	Visualisation()
	{
		init_graphics();
	}
	void drawWorld();
	void drawRightSide();
	void drawVisitor(int _x, int _y);
	void eraseVisitor(int _x, int _y);
	void drawBuilding(int right_x, int up_y, int left_x, int bot_y, const char ch);
	void eraseBuilding(int right_x, int up_y, int left_x, int bot_y);
	void drawRoad(int _x, int _y, const char ch);
	void eraseRoad(int _x, int _y);
};