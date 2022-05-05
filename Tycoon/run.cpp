#pragma once
#include <iostream>
#include "msoftcon.h"
#include "drawheader.h"
#include "GameManagement.h"
using namespace std;
int main()
{
	GameManagement GameMaster;
	try
	{
		GameMaster.CreateCursor();
		GameMaster.CreateDrawPointer();
		GameMaster.CreateCamera();
		GameMaster.CreatePlayingField();
		GameMaster.CreateMenuAndElements();
		GameMaster.CreateAllObjects();
		GameMaster.CreateInfoPanel();
		//
		GameMaster.InitialDisplay();
	}
	catch (MyException& somethingOccured)
	{
		somethingOccured.AddToLogFile();
	}
	catch (exception& standardException)
	{
		ofstream logFile;
		logFile.open("Logs.txt", ios_base::out | ios_base::app);
		logFile << standardException.what() << endl;
	}
	GameMaster.GameProcess();
	set_cursor_pos(1, 40);
	return 0;
}