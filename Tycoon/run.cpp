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
	GameMaster.DisplayPlayingField();
	GameMaster.DisplayMenu();
	GameMaster.GameProcess();
	set_cursor_pos(1, 40);
	return 0;
}