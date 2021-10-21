#pragma once
#include <iostream>
#include "msoftcon.h"
using namespace std;
class drawMap
{
public:
	void drawWorld();
};
class drawMenu
{
public:
	void drawRightSide();
};
class drawVisitor
{
public:
	void drawVis();
};
class drawConstruction
{
public:
	void drawConst(int, int, int , int);
};