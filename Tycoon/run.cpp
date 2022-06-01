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
		DTOCollector::GetCollector()->DownloadAllData();
		GameMaster.CreateCursor();
		GameMaster.CreateDrawPointer();
		GameMaster.CreateSaverLoader();
		GameMaster.CreateGameElementsDrawer();
		GameMaster.CreateCamera();
		GameMaster.CreatePlayingField();
		GameMaster.CreateMenuAndElements();
		GameMaster.CreateAllObjects();
		GameMaster.CreateInfoPanel();
		GameMaster.CreateStartScreen();
		GameMaster.CreateMainMenu();
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