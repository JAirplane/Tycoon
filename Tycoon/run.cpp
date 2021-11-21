#pragma once
#include <iostream>
#include <windows.h>
#include "msoftcon.h"
#include "drawheader.h"
#include "Map.h"
using namespace std;
int main()
{
	WorldMap WM;
	WM.DisplayPlayingField();
	WM.DisplaySideMenu();
	WM.GameProcess();
	set_cursor_pos(1, 40);
	return 0;
}