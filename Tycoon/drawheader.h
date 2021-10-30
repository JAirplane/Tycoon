#pragma once
#include <iostream>
#include "msoftcon.h"
using namespace std;
class MapVisualisation
{
public:
	void drawWorld();
};
class MenuVisualisation
{
public:
	void drawRightSide();
};
class VisitorVisualisation
{
public:
	void drawVisitor();
};
class ConstructionVisualisation
{
public:
	void drawConstruction(int, int, int, int, const char);
};
class RoadVisualisation
{
public:
	void drawRoad(int, int, const char);
};