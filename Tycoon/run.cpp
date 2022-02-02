#pragma once
#include <iostream>
#include <windows.h>
#include "msoftcon.h"
#include "drawheader.h"
#include "GameManagement.h"
using namespace std;
int main()
{
	GameManagement GameMaster;
	GameMaster.CreateCursor();
	GameMaster.CreateDrawPointer();
	GameMaster.CreateAllObjects();
	GameMaster.CreateCamera();
	GameMaster.CreatePlayingField();
	GameMaster.CreateMenuAndElements();
	GameMaster.CreateInfoPanel();
	//
	GameMaster.DisplayCamera();
	GameMaster.DisplayMenu();
	GameMaster.DisplayInfoPanel();
	GameMaster.DisplayPlayingField();
	GameMaster.GameProcess();
	set_cursor_pos(1, 40);
	return 0;
}