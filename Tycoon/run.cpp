#pragma once
#include <iostream>
#include <windows.h>
#include "msoftcon.h"
#include "drawheader.h"
#include "logicheader.h"
using namespace std;
int main()
{
	Visualisation Draw;
	Draw.drawWorld();
	init_graphics();
	WorldMap WM;
	set_cursor_pos(5, 5);
	WM.GameProcess();
	set_cursor_pos(1, 40);
	return 0;
}