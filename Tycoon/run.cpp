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
	GameMaster.CreateManagers();
	GameMaster.DisplayCamera();
	GameMaster.DisplayMenu();
	GameMaster.DisplayInfoPanel();
	GameMaster.DisplayPlayingField();
	GameMaster.GameProcess();
	set_cursor_pos(1, 40);
	return 0;
}