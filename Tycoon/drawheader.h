#pragma once
#include <iostream>
#include "msoftcon.h"
using namespace std;
class Visualisation
{
public:
	void drawWorld();
	void drawRightSide();
	void drawVisitor();
	void drawBuilding(int, int, int, int, const char);
	void drawRoad(int, int, const char);
};