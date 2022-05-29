#include "GameManagement.h"
///////////////GameManagement Class///////////////
// create game elements
void GameManagement::CreateCursor()
{
	cursor_ptr = new Cursor();
}
void GameManagement::CreateDrawPointer()
{
	draw_ptr = new Visualisation();
}
void GameManagement::CreateGameElementsDrawer()
{
	gameElementsDrawer = new Display(draw_ptr);
}
void GameManagement::CreateAllObjects()
{
	allObjects_ptr = new AllObjects(cursor_ptr, draw_ptr);
	for (auto menuItem : menu_ptr->GetMenuItems())
	{
		if (dynamic_cast<RoadManager*>(menuItem->GetManager()) != nullptr)
		{
			menu_ptr->CreateParkEntrance(field_ptr, draw_ptr, menuItem->GetManager()->GetDescriptor(), allObjects_ptr);
			return;
		}
	}
	throw MyException("GameManagement::CreateAllObjects() failed to find RoadManager* from menu elements");
}
void GameManagement::CreateCamera()
{
	if (draw_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateCamera() draw_ptr is nullptr");
	}
	if (cursor_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateCamera() cursor_ptr is nullptr");
	}
	MyRectangle* cameraRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft(),
		DTOCollector::GetCollector()->GetFigureConstants("camera"), draw_ptr, cursor_ptr);
	camera_ptr = new Camera(*cameraRectangle);
	delete cameraRectangle;
}
void GameManagement::CreatePlayingField()
{
	if (draw_ptr == nullptr)
	{
		throw MyException("GameManagement::CreatePlayingField() draw_ptr is nullptr");
	}
	if (cursor_ptr == nullptr)
	{
		throw MyException("GameManagement::CreatePlayingField() cursor_ptr is nullptr");
	}
	MyRectangle* playingFieldRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(ConstructionOptions::GetAllOptions()->GetPlayingFieldUpperLeft(),
		DTOCollector::GetCollector()->GetFigureConstants("playingField"), draw_ptr, cursor_ptr);
	field_ptr = new PlayingField(*playingFieldRectangle);
	delete playingFieldRectangle;
}
void GameManagement::CreateMenuAndElements()
{
	if (draw_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMenuAndElements() draw_ptr is nullptr");
	}
	if (cursor_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMenuAndElements() cursor_ptr is nullptr");
	}
	if (camera_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMenuAndElements() camera_ptr is nullptr");
	}
	PointCoord menuUpperLeft(camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() + 1, camera_ptr->GetUpperLeft().Get_y());
	MyRectangle* menuRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(menuUpperLeft,
		DTOCollector::GetCollector()->GetFigureConstants("sideMenu"), draw_ptr, cursor_ptr);
	menuRectangle->SetHeightAddition(camera_ptr->GetHeightAddition());
	menu_ptr = new Menu(*menuRectangle);
	delete menuRectangle;
	menu_ptr->CreateGameStats();
	menu_ptr->CreateMenuElement("road");
	menu_ptr->CreateMenuElement("toilet");
	menu_ptr->CreateMenuElement("iceCreamShop");
	menu_ptr->CreateMenuElement("foodCourt");
	menu_ptr->CreateMenuElement("carousel");
	menu_ptr->CreateMenuElement("dumboRide");
	menu_ptr->CreateMenuElement("ferrisWheel");
	menu_ptr->CreateMenuElement("rollerCoaster");
	menu_ptr->CreateMenuElement("bumperCars");
	menu_ptr->CreateMenuElement("logRide");
	//
	menu_ptr->CreateVisitorManager();
}
void GameManagement::CreateInfoPanel()
{
	if (draw_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateInfoPanel() draw_ptr is nullptr");
	}
	if (cursor_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateInfoPanel() cursor_ptr is nullptr");
	}
	if (camera_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateInfoPanel() camera_ptr is nullptr");
	}
	if (menu_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateInfoPanel() menu_ptr is nullptr");
	}
	MyRectangle* infoPanelRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(ConstructionOptions::GetAllOptions()->GetInfoPanelUpperLeft(),
		DTOCollector::GetCollector()->GetFigureConstants("infoPanel"), draw_ptr, cursor_ptr);
	infoPanelRectangle->SetWidthAddition(camera_ptr->GetWidthAddition() + menu_ptr->GetWidthAddition() + 1);
	infoPanel_ptr = new InfoPanel(*infoPanelRectangle);
	delete infoPanelRectangle;
	infoPanel_ptr->CreateMenuScreen();
	infoPanel_ptr->CreateControlsScreen();
	infoPanel_ptr->CreateGameMessagesScreen();
	ChosenConstructionAttach(infoPanel_ptr);
	UserMessageAttach(infoPanel_ptr);
}
void GameManagement::CreateStartScreen()
{
	if (draw_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateStartScreen() draw_ptr is nullptr");
	}
	if (cursor_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateStartScreen() cursor_ptr is nullptr");
	}
	if (camera_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateStartScreen() camera_ptr is nullptr");
	}
	if (infoPanel_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateStartScreen() infoPanel_ptr is nullptr");
	}
	if (menu_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateStartScreen() menu_ptr is nullptr");
	}
	MyRectangle* startScreenRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(ConstructionOptions::GetAllOptions()->GetInitialSplashScreenUpperLeft(),
		DTOCollector::GetCollector()->GetFigureConstants("startScreen"), draw_ptr, cursor_ptr);
	startScreenRectangle->SetHeightAddition(camera_ptr->GetHeightAddition() + infoPanel_ptr->GetHeightAddition() + 1);
	startScreenRectangle->SetWidthAddition(camera_ptr->GetWidthAddition() + menu_ptr->GetWidthAddition() + 1);
	startScreen_ptr = new InitialScreen(*startScreenRectangle);
	delete startScreenRectangle;
	startScreen_ptr->CreatePressAnyKey();
}
//
void GameManagement::CreateMainMenu()
{
	if (draw_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMainMenu() draw_ptr is nullptr");
	}
	if (cursor_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMainMenu() cursor_ptr is nullptr");
	}
	if (camera_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMainMenu() camera_ptr is nullptr");
	}
	if (infoPanel_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMainMenu() infoPanel_ptr is nullptr");
	}
	if (menu_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMainMenu() menu_ptr is nullptr");
	}
	MyRectangle* mainMenuRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(ConstructionOptions::GetAllOptions()->GetMainMenuUpperLeft(),
		DTOCollector::GetCollector()->GetFigureConstants("mainMenuScreen"), draw_ptr, cursor_ptr);
	mainMenuRectangle->SetHeightAddition(camera_ptr->GetHeightAddition() + infoPanel_ptr->GetHeightAddition());
	mainMenuRectangle->SetWidthAddition(camera_ptr->GetWidthAddition() + menu_ptr->GetWidthAddition());
	mainMenu_ptr = new MainMenu(*mainMenuRectangle);
	delete mainMenuRectangle;
	mainMenu_ptr->CreateButtons();
}
//
int GameManagement::GetPressedKey() const
{
	int key = _getch();
	if (key == 0 || key == 224)
	{
		key = _getch();
	}
	return key;
}
int GameManagement::MainMenuUserActions(int key)
{
	switch (key)
	{
	case 72: { Arrows_MainMenu(Direction::Up); return 0; }		//up arrow 
	case 80: { Arrows_MainMenu(Direction::Down); return 0; }	//down arrow 
	case 13: { return EnterKey_MainMenu(); }	//enter key
	case 27: { exit(0); }	//esc in main menu is equal to effect of pressing exit button
	default: {return 0; }
	}
}
int GameManagement::MainMenuInteraction()
{
	while (true)
	{
		if (_kbhit() != 0)
		{
			int response = this->MainMenuUserActions(this->GetPressedKey());
			if (response == 0)
			{
				continue;
			}
			else
			{
				return response;
			}
		}
	}
}
void GameManagement::SaveAndExit()
{
	

}
int GameManagement::InitialDisplay()
{
	gameElementsDrawer->DisplayInitialScreen(startScreen_ptr);
	gameElementsDrawer->EraseScreen();
	//
	gameElementsDrawer->DisplayMainMenu(mainMenu_ptr, cursor_ptr);
	int response = this->MainMenuInteraction();
	if (response == 1)
	{
		return response;
	}
	gameElementsDrawer->EraseScreen();
	//
	gameElementsDrawer->DisplayCamera(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayMenu(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayInfoPanel(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayPlayingField(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayAllObjects(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	return 0;
}
// notifies InfoPanel if user choose some construction on the playing field
void GameManagement::ChosenConstructionAttach(ConstructionInfoObserverInterface* observer)
{
	choosenConstructionObservers.push_back(observer);
}
void GameManagement::ChosenConstructionDetach(ConstructionInfoObserverInterface* observer)
{
	choosenConstructionObservers.remove(observer);
}
void GameManagement::ChosenConstructionNotify(Construction* choosenConstruction_ptr)
{
	if (choosenConstruction_ptr == nullptr)
	{
		throw MyException("GameManagement::ChosenConstructionNotify() received nullptr.");
	}
	else
	{
		choosenConstruction_ptr->SetChosenStatus(true);
		list<ConstructionInfoObserverInterface*>::iterator observerIter = choosenConstructionObservers.begin();
		while (observerIter != choosenConstructionObservers.end())
		{
			(*observerIter)->ChosenConstructionUpdate(choosenConstruction_ptr);
			++observerIter;
		}
	}
}
// notifies InfoPanel about various issues with a message
void GameManagement::UserMessageAttach(MessageObserverInterface* observer)
{
	userMessageObservers.push_back(observer);
}
void GameManagement::UserMessageDetach(MessageObserverInterface* observer)
{
	userMessageObservers.remove(observer);
}
void GameManagement::UserMessageNotify(const string message)
{
	if (message.empty())
	{
		throw MyException("GameManagement::UserMessageNotify() received empty message.");
	}
	else
	{
		list<MessageObserverInterface*>::iterator observerIter = userMessageObservers.begin();
		while (observerIter != userMessageObservers.end())
		{
			(*observerIter)->UserMessageUpdate(message);
			++observerIter;
		}
	}
}
//
void GameManagement::ErasePreliminaryElementAndMenuRedraw()
{
	Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
	if (preliminary_ptr != nullptr)
	{
		MenuElement* elementOfPreliminary = menu_ptr->GetMenuElementByDescriptorId(preliminary_ptr->GetDescriptor()->uniqueId);
		menu_ptr->MenuElementRedrawBorder(elementOfPreliminary, "inactive");
		allObjects_ptr->ErasePreliminaryElement(camera_ptr, field_ptr);
	}
}
void GameManagement::ClearChosenElementAndInfoPanelRedraw()
{
	Construction* chosen_ptr = infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetChosenConstruction();
	if (chosen_ptr != nullptr)
	{
		infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->DeselectConstruction(camera_ptr, allObjects_ptr);
		if (infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::SystemMessagesAndConstructionInfo)
		{
			infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetBorder()->
				SetBorderForegroundColor(infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetInitialCondition()->foregroundBorderColor);
			infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->ClearContent();
			infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->DisplayConstructionInfo();
		}
	}
	infoPanel_ptr->EraseInfoPanelMessage();
	infoPanel_ptr->DisplayInfoPanelMessage("Press 'i' to get to the InfoPanel");
}
void GameManagement::UserActionsCycle(chrono::milliseconds& lastLaunch)
{
	lastLaunch = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	if (_kbhit() != 0)
	{
		UserActions(this->GetPressedKey());
	}
	Direction shiftDirection = camera_ptr->CursorIsOnCameraBorder();
	bool shifting = camera_ptr->IsShift(field_ptr, shiftDirection);
	if (shiftDirection != Direction::None)
	{
		cursor_ptr->CursorShift(shiftDirection);
		if (allObjects_ptr->GetPreliminaryElement() != nullptr)
		{
			allObjects_ptr->GetPreliminaryElement()->ShiftObject(shiftDirection);
		}
		if (shifting)
		{
			allObjects_ptr->EraseObjects(camera_ptr);
			gameElementsDrawer->ErasePlayingField(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
			allObjects_ptr->ShiftBuildings(shiftDirection);
			allObjects_ptr->ShiftRoads(shiftDirection);
			allObjects_ptr->ShiftVisitors(shiftDirection);
			field_ptr->Shift(shiftDirection);
			gameElementsDrawer->DisplayPlayingField(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
			gameElementsDrawer->DisplayAllObjects(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
		}
		gameElementsDrawer->DrawCursor(cursor_ptr, allObjects_ptr, field_ptr);
	}
}
void GameManagement::VisitorCreationCycle(chrono::milliseconds& lastLaunch)
{
	lastLaunch = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	if (allObjects_ptr->GetAllBuildings().size() <= 2)
	{
		return;
	}
	menu_ptr->VisitorAddition(field_ptr, camera_ptr, allObjects_ptr);
	menu_ptr->UpdateStatsDisplay();
}
void GameManagement::VisitorStepCycle(chrono::milliseconds& lastLaunch)
{
	lastLaunch = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	int lowestEntertainmentPrice = menu_ptr->GetLowestEntertainmentVisitPrice();
	vector<Visitor*> forDeleting = allObjects_ptr->AllVisitorsStep(camera_ptr, field_ptr, menu_ptr->GetGameStats(), lowestEntertainmentPrice);
	allObjects_ptr->DeleteVisitors(forDeleting, menu_ptr->GetGameStats());
	menu_ptr->UpdateStatsDisplay();
	infoPanel_ptr->UpdateConstructionInfo();
}
void GameManagement::VisitorStatusReductionCycle(chrono::milliseconds& lastLaunch)
{
	lastLaunch = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	allObjects_ptr->VisitorsFoodCapacityReduction();
	allObjects_ptr->VisitorsToiletNeedReduction();
}
void GameManagement::PayDailyExpencesCycle(chrono::milliseconds& lastLaunch)
{
	lastLaunch = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	allObjects_ptr->PayDailyExpences(menu_ptr->GetGameStats());
}
void GameManagement::GameProcess()
{
	srand(static_cast<unsigned int>(time(0)));
	char ch = 'a';
	chrono::milliseconds userActionDelay = chrono::milliseconds(16);
	chrono::milliseconds userActionsLastLaunch = chrono::milliseconds(0);
	chrono::milliseconds visitorCreationDelay = chrono::milliseconds((rand() % 8 + 1) * 1000);
	chrono::milliseconds visitorCreationLastLaunch = chrono::milliseconds(0);
	chrono::milliseconds visitorsStepDelay = chrono::milliseconds(1000);
	chrono::milliseconds visitorsStepLastLaunch = chrono::milliseconds(0);
	chrono::milliseconds visitorsStatusReductionDelay = chrono::milliseconds(2000);
	chrono::milliseconds visitorsStatusReductionLastLaunch = chrono::milliseconds(0);
	chrono::milliseconds payDailyExpencesDelay = chrono::milliseconds(40000);
	chrono::milliseconds payDailyExpencesLastLaunch = chrono::milliseconds(0);
	chrono::milliseconds allCycleLastEnding = chrono::milliseconds(17);
	while (true)
	{
		try
		{
			if (allCycleLastEnding - userActionsLastLaunch > userActionDelay)
			{
				UserActionsCycle(userActionsLastLaunch);
			}
			if (allCycleLastEnding - visitorCreationLastLaunch > visitorCreationDelay)
			{
				visitorCreationDelay = chrono::milliseconds((rand() % 3 + 1) * 5000);
				VisitorCreationCycle(visitorCreationLastLaunch);
			}
			if (allCycleLastEnding - visitorsStepLastLaunch > visitorsStepDelay)
			{
				VisitorStepCycle(visitorsStepLastLaunch);
			}
			if (allCycleLastEnding - visitorsStatusReductionLastLaunch > visitorsStatusReductionDelay)
			{
				VisitorStatusReductionCycle(visitorsStatusReductionLastLaunch);
			}
			if (allCycleLastEnding - payDailyExpencesLastLaunch > payDailyExpencesDelay)
			{
				PayDailyExpencesCycle(payDailyExpencesLastLaunch);
			}
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
		allCycleLastEnding = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	}
}
void GameManagement::H_Key()
{
	if (!menu_ptr->GetHideMenuStatus())
	{
		switch (cursor_ptr->GetCursorArea(camera_ptr, menu_ptr, infoPanel_ptr))
		{
		case CursorLocation::Camera: {break; }
		case CursorLocation::Menu:
		{
			MenuElement* current_ptr = menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y());
			current_ptr->GetBorder()->SetBorderForegroundColor(current_ptr->GetInitialCondition()->foregroundBorderColor);
			break;
		}
		case CursorLocation::InfoPanel:
		{
			infoPanel_ptr->EndInteractionDisplayRule();
			break;
		}
		default:
		{
			cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
			break;
		}
		}
		gameElementsDrawer->HideInterface(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	}
	else
	{
		gameElementsDrawer->ShowInterface(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	}
}
void GameManagement::S_Key()
{
	if (allObjects_ptr->GetPreliminaryElement() != nullptr)
	{
		allObjects_ptr->ErasePreliminaryElement(camera_ptr, field_ptr);
	}
	if (infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetChosenConstruction() != nullptr)
	{
		infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->DeselectConstruction(camera_ptr, allObjects_ptr);
	}
	if (cursor_ptr->GetCursorArea(camera_ptr, menu_ptr, infoPanel_ptr) == CursorLocation::Menu)
	{
		TabKey_Menu();
	}
	if (cursor_ptr->GetCursorArea(camera_ptr, menu_ptr, infoPanel_ptr) == CursorLocation::InfoPanel)
	{
		infoPanel_ptr->EndInteractionDisplayRule();
	}
	Direction shiftDirection = menu_ptr->ChangeMenuSide(camera_ptr);
	allObjects_ptr->ShiftBuildings(shiftDirection, menu_ptr->GetWidthAddition());
	allObjects_ptr->ShiftRoads(shiftDirection, menu_ptr->GetWidthAddition());
	allObjects_ptr->ShiftVisitors(shiftDirection, menu_ptr->GetWidthAddition());
	field_ptr->Shift(shiftDirection, menu_ptr->GetWidthAddition());
	gameElementsDrawer->EraseScreen();
	gameElementsDrawer->DisplayCamera(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayMenu(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayPlayingField(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayAllObjects(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayInfoPanel(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
}
void GameManagement::R_Key()
{
	if (cursor_ptr->GetCursorArea(camera_ptr, menu_ptr, infoPanel_ptr) == CursorLocation::Camera)
	{
		Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
		if (preliminary_ptr != nullptr)
		{
			if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
			{
				preliminary_ptr->EraseObject(camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
					camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
				PointCoord preliminaryElementNeibourRedraw = preliminary_ptr->GetRedrawNeighboursPoint();
				int rotateRes = preliminary_ptr->RotateConstruction();
				if (rotateRes == 0)
				{
					UserMessageNotify("Rotation failed");
				}
				else
				{
					allObjects_ptr->RedrawNeighbours(preliminaryElementNeibourRedraw, camera_ptr);
					if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
					{
						preliminary_ptr->Connected(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
						int mask = preliminary_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
						preliminary_ptr->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
							camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
						allObjects_ptr->RedrawNeighbours(preliminary_ptr, camera_ptr);
					}
				}
				cursor_ptr->CursorMovement(preliminary_ptr->GetUpperLeft());
			}
			else
			{
				UserMessageNotify("Can't rotate here");
			}
		}
		else
		{
			UserMessageNotify("Nothing to rotate");
		}
	}
	else
	{
		UserMessageNotify("'R' key do nothing here");
	}
}
void GameManagement::Z_Key()
{
	int xCoord = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition() + 1;
	int yCoord = menu_ptr->GetUpperLeft().Get_y();
	set_color(cBLACK);
	set_cursor_pos(xCoord, yCoord);
	for (yCoord; yCoord < menu_ptr->GetUpperLeft().Get_y() + 20; yCoord++)
	{
		for (xCoord; xCoord < menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition() + 1 + 20; xCoord++)
		{
			cout << " ";
		}
		xCoord = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition() + 1;
		set_cursor_pos(xCoord, yCoord);
	}
	vector<vector<int> > matrix = allObjects_ptr->GetGraph()->GetWeightMatrix();
	xCoord = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition() + 1;
	yCoord = menu_ptr->GetUpperLeft().Get_y();
	int xIndex = 0;
	int yIndex = 0;
	set_color(cWHITE);
	set_cursor_pos(xCoord, yCoord);
	for (yIndex; yIndex < matrix.size(); yIndex++)
	{
		for (xIndex; xIndex < matrix.size(); xIndex++)
		{
			cout << matrix.at(yIndex)[xIndex] << " ";
		}
		++yCoord;
		set_cursor_pos(xCoord, yCoord);
		xIndex = 0;
	}
}
void GameManagement::IKey_Camera()
{
	if (allObjects_ptr->GetPreliminaryElement() == nullptr)
	{
		if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
		{
			draw_ptr->ErasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
		}
	}
	else
	{
		ErasePreliminaryElementAndMenuRedraw();
	}
	if (menu_ptr->GetHideMenuStatus())
	{
		gameElementsDrawer->ShowInterface(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	}
	else
	{
		infoPanel_ptr->GetToInfoPanelDisplayRule();
	}
}
void GameManagement::IKey_Menu()
{
	MenuElement* currentActiveElement_ptr = menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y());
	currentActiveElement_ptr->GetBorder()->SetBorderForegroundColor(currentActiveElement_ptr->GetInitialCondition()->foregroundBorderColor);
	currentActiveElement_ptr->DrawBorder();
	infoPanel_ptr->GetToInfoPanelDisplayRule();
}
void GameManagement::IKey_InfoPanel()
{
	infoPanel_ptr->EndInteractionDisplayRule();
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	gameElementsDrawer->DrawCursor(cursor_ptr, allObjects_ptr, field_ptr);
}
void GameManagement::I_Key()
{
	switch (cursor_ptr->GetCursorArea(camera_ptr, menu_ptr, infoPanel_ptr))
	{
	case CursorLocation::Camera:
	{
		IKey_Camera();
		return;
	}
	case CursorLocation::Menu:
	{
		IKey_Menu();
		return;
	}
	case CursorLocation::InfoPanel:
	{
		IKey_InfoPanel();
		return;
	}
	default:
	{
		cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
		return;
	}
	}
}
void GameManagement::TabKey_Camera()
{
	if (menu_ptr->GetHideMenuStatus())
	{
		gameElementsDrawer->ShowInterface(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	}
	if (allObjects_ptr->GetPreliminaryElement() == nullptr)
	{
		if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
		{
			draw_ptr->ErasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
		}
	}
	else
	{
		MenuElement* ElementIfPreliminary = menu_ptr->GetMenuElementByDescriptorId(allObjects_ptr->GetPreliminaryElement()->GetDescriptor()->uniqueId);
		menu_ptr->MenuElementRedrawBorder(ElementIfPreliminary, "inactive");
		allObjects_ptr->ErasePreliminaryElement(camera_ptr, field_ptr);
	}
	MenuElement* upperVisibleElement = menu_ptr->GetUpperVisibleMenuElement();
	menu_ptr->MenuElementRedrawBorder(upperVisibleElement, "active");
	cursor_ptr->CursorMovement(PointCoord(upperVisibleElement->GetHalfXAxis(), upperVisibleElement->GetUpperLeft().Get_y()));
}
void GameManagement::TabKey_Menu()
{
	MenuElement* currentElement = menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y());
	currentElement->GetBorder()->SetBorderForegroundColor(currentElement->GetInitialCondition()->foregroundBorderColor);
	currentElement->DrawBorder();
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	gameElementsDrawer->DrawCursor(cursor_ptr, allObjects_ptr, field_ptr);
}
void GameManagement::TabKey_InfoPanel()
{
	infoPanel_ptr->EndInteractionDisplayRule();
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	gameElementsDrawer->DrawCursor(cursor_ptr, allObjects_ptr, field_ptr);
}
void GameManagement::Tab_Key()
{
	switch (cursor_ptr->GetCursorArea(camera_ptr, menu_ptr, infoPanel_ptr))
	{
	case CursorLocation::Camera:
	{
		TabKey_Camera();
		return;
	}
	case CursorLocation::Menu:
	{
		TabKey_Menu();
		return;
	}
	case CursorLocation::InfoPanel:
	{
		TabKey_InfoPanel();
		return;
	}
	default:
	{
		cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
		return;
	}
	}
}
void GameManagement::EnterKey_Camera()
{
	Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
	if (preliminary_ptr != nullptr)
	{
		if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
		{
			if (preliminary_ptr->GetDescriptor()->GetConstructionCost() <= menu_ptr->GetGameStats()->amountOfMoney)
			{
				menu_ptr->GetGameStats()->amountOfMoney -= preliminary_ptr->GetDescriptor()->GetConstructionCost();
				menu_ptr->GetGameStats()->ClearContent();
				menu_ptr->GetGameStats()->DrawContent();
				MenuElement* elementOfPreliminary = menu_ptr->GetMenuElementByDescriptorId(preliminary_ptr->GetDescriptor()->uniqueId);
				Construction* realObject_ptr = elementOfPreliminary->GetManager()->CreateConstruction(cursor_ptr->GetCursorConsoleLocation(), draw_ptr, allObjects_ptr);
				realObject_ptr->CopyRotationProperties(preliminary_ptr);
				menu_ptr->ParkLevelCheck(allObjects_ptr);
				int mask = realObject_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
				realObject_ptr->Connected(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
				allObjects_ptr->RedrawNeighbours(realObject_ptr, camera_ptr);
				realObject_ptr->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
					camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
				cursor_ptr->CursorMovement(PointCoord(realObject_ptr->GetUpperLeft().Get_x() + realObject_ptr->GetWidthAddition() + 1,
					realObject_ptr->GetUpperLeft().Get_y() + realObject_ptr->GetHeightAddition()));
				preliminary_ptr->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
				if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
				{
					mask = preliminary_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
					allObjects_ptr->RedrawNeighbours(preliminary_ptr, camera_ptr);
					preliminary_ptr->Connected(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
					preliminary_ptr->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
						camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
					cursor_ptr->CursorMovement(preliminary_ptr->GetUpperLeft());
				}
			}
			else
			{
				UserMessageNotify("Not enough money");
			}
		}
		else
		{
			UserMessageNotify("Can't build in this location");
		}
	}
	else
	{
		infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->DeselectConstruction(camera_ptr, allObjects_ptr);
		Construction* userChoice_ptr = allObjects_ptr->FindConstruction(cursor_ptr->GetCursorConsoleLocation());
		if (userChoice_ptr == nullptr)
		{
			UserMessageNotify("No construction found");
		}
		else
		{
			ChosenConstructionNotify(userChoice_ptr);
			userChoice_ptr->Redraw_VisitorCheck(camera_ptr, allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(),
				allObjects_ptr->GetAllVisitors(), allObjects_ptr->GetPreliminaryElement());
			cursor_ptr->CursorMovement(userChoice_ptr->GetUpperLeft());
		}
	}
}
void GameManagement::EnterKey_Menu()
{
	infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->DeselectConstruction(camera_ptr, allObjects_ptr);
	if (infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::SystemMessagesAndConstructionInfo)
	{
		infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->ClearContent();
		infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->DisplayConstructionInfo();
		infoPanel_ptr->EraseInfoPanelMessage();
		infoPanel_ptr->DisplayInfoPanelMessage("Press 'i' to get to the InfoPanel");
	}
	menu_ptr->MenuElementRedrawBorder(menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y()), "chosen");
	Construction* preliminary_ptr = menu_ptr->CreatePreliminaryObject(allObjects_ptr, camera_ptr);
	cursor_ptr->CursorMovement(PointCoord(camera_ptr->GetHalfXAxis(), camera_ptr->GetHalfYAxis()));
	preliminary_ptr->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
	if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
	{
		int mask = preliminary_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
		allObjects_ptr->RedrawNeighbours(preliminary_ptr, camera_ptr);
		preliminary_ptr->Connected(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
		preliminary_ptr->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
			camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
		cursor_ptr->CursorMovement(preliminary_ptr->GetUpperLeft());
	}
}
void GameManagement::EnterKey_InfoPanel()
{
	if (infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::MenuScreen)
	{
		if (cursor_ptr->GetCursorConsoleLocation().Get_x() == infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetHalfXAxis())
		{
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetBorder()->
				SetBorderForegroundColor(infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetInitialCondition()->foregroundBorderColor);
			infoPanel_ptr->SwitchContent(InfoPanelContentType::SystemMessagesAndConstructionInfo);
			infoPanel_ptr->EraseInfoPanelMessage();
			infoPanel_ptr->DisplayInfoPanelMessage("Press 'esc' to get back to the previous screen");
			cursor_ptr->CursorMovement(PointCoord(infoPanel_ptr->GetMessagesScreen()->GetHalfXAxis(), infoPanel_ptr->GetMessagesScreen()->GetUpperLeft().Get_y()));
		}
		else if (cursor_ptr->GetCursorConsoleLocation().Get_x() == infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetHalfXAxis())
		{
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetBorder()->
				SetBorderForegroundColor(infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetInitialCondition()->foregroundBorderColor);
			infoPanel_ptr->SwitchContent(InfoPanelContentType::Controls);
		}
		else
		{
			throw MyException("GameManagement::EnterKey_InfoPanel() cursor is out of buttons.");
		}
	}
	else if (infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::SystemMessagesAndConstructionInfo)
	{
		int buttonHalfX = infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetHalfXAxis();
		int topY = infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetUpperLeft().Get_y();
		if (cursor_ptr->GetCursorConsoleLocation() == PointCoord(buttonHalfX, topY))
		{
			Construction* chosen_ptr = infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetChosenConstruction();
			if (chosen_ptr != nullptr)
			{
				if (chosen_ptr->IsBreakable())
				{
					function<bool(Construction*)> IsEqual = [chosen_ptr](Construction* element)
					{
						return (chosen_ptr == element);
					};
					chosen_ptr->EraseObject(camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
						camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
					PointCoord redrawPoint = chosen_ptr->GetRedrawNeighboursPoint();
					allObjects_ptr->DeleteConstruction(chosen_ptr, IsEqual, menu_ptr->GetGameStats());
					infoPanel_ptr->ClearChoosenConstruction();
					allObjects_ptr->RedrawNeighbours(redrawPoint, camera_ptr);
					infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetBorder()->SetBorderForegroundColor(
						infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetInitialCondition()->foregroundBorderColor);
					infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->ClearContent();
				}
				else
				{
					UserMessageNotify("Can't break construction");
				}

				infoPanel_ptr->EndInteractionDisplayRule();
				cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
				gameElementsDrawer->DrawCursor(cursor_ptr, allObjects_ptr, field_ptr);
			}
		}
	}
	else
	{
		return;
	}
}
void GameManagement::Enter_Key()
{
	switch (cursor_ptr->GetCursorArea(camera_ptr, menu_ptr, infoPanel_ptr))
	{
	case CursorLocation::Camera:
	{
		EnterKey_Camera();
		return;
	}
	case CursorLocation::Menu:
	{
		EnterKey_Menu();
		return;
	}
	case CursorLocation::InfoPanel:
	{
		EnterKey_InfoPanel();
		return;
	}
	default:
	{
		cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
		return;
	}
	}
}
int GameManagement::EnterKey_MainMenu()
{
	int response = mainMenu_ptr->PressButton(cursor_ptr);
	if (response == 1)
	{
		exit(0);
	}
	else
	{
		return response;
	}
}
void GameManagement::EscKey_Camera()
{
	if (allObjects_ptr->GetPreliminaryElement() == nullptr && infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetChosenConstruction() == nullptr)
	{
		UserMessageNotify("No construction chosen");
		return;
	}
	ErasePreliminaryElementAndMenuRedraw();
	ClearChosenElementAndInfoPanelRedraw();
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	gameElementsDrawer->DrawCursor(cursor_ptr, allObjects_ptr, field_ptr);
}
void GameManagement::EscKey_InfoPanel()
{
	if (infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::SystemMessagesAndConstructionInfo &&
		infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetChosenConstruction() != nullptr)
	{
		infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetBorder()->
			SetBorderForegroundColor(infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetInitialCondition()->foregroundBorderColor);
	}
	if (infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::Controls || infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::SystemMessagesAndConstructionInfo)
	{

		infoPanel_ptr->SwitchContent(InfoPanelContentType::MenuScreen);
	}
}
void GameManagement::Esc_Key()
{
	switch (cursor_ptr->GetCursorArea(camera_ptr, menu_ptr, infoPanel_ptr))
	{
	case CursorLocation::Camera:
	{
		EscKey_Camera();
		return;
	}
	case CursorLocation::Menu:
	{
		UserMessageNotify("Esc do nothing in Menu");
		return;
	}
	case CursorLocation::InfoPanel:
	{
		EscKey_InfoPanel();
		return;
	}
	default: {return; }
	}
}
void GameManagement::Arrows_PlayingField(Direction arrowDir)
{
	int changeX = 0;
	int changeY = 0;
	switch (arrowDir)
	{
	case Direction::Left: {changeX = -1; break; }
	case Direction::Up: {changeY = -1; break; }
	case Direction::Right: {changeX = 1; break; }
	case Direction::Down: {changeY = 1; break; }
	default: {throw MyException("GameManagement::Arrows_PlayingField() incorrect direction."); }
	}
	Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
	if (preliminary_ptr != nullptr)
	{
		PointCoord preliminaryElementNeibourRedraw = preliminary_ptr->GetRedrawNeighboursPoint();
		bool imposition = allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr);
		if (!imposition)
		{
			preliminary_ptr->EraseObject(camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(), camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(),
				camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
		}
		cursor_ptr->CursorMovement(PointCoord(preliminary_ptr->GetUpperLeft().Get_x() + changeX, preliminary_ptr->GetUpperLeft().Get_y() + changeY));
		preliminary_ptr->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
		if (!imposition)
		{
			allObjects_ptr->RedrawNeighbours(preliminaryElementNeibourRedraw, camera_ptr);
		}
		imposition = allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr);
		if (!imposition)
		{
			int mask = preliminary_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
			allObjects_ptr->RedrawNeighbours(preliminary_ptr, camera_ptr);
			preliminary_ptr->Connected(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
			preliminary_ptr->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(),
				camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
		}
		cursor_ptr->CursorMovement(preliminary_ptr->GetUpperLeft());
	}
	else
	{
		if (!allObjects_ptr->ObjectImposition(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y()), field_ptr) &&
			camera_ptr->CursorIsOnCameraBorder() == Direction::None)
		{
			draw_ptr->ErasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
		}
		cursor_ptr->CursorMovement(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x() + changeX, cursor_ptr->GetCursorConsoleLocation().Get_y() + changeY));
		if (!allObjects_ptr->ObjectImposition(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y()), field_ptr) &&
			camera_ptr->CursorIsOnCameraBorder() == Direction::None)
		{
			draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(),
				ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
		}
	}
}
void GameManagement::Arrows_Menu(Direction arrowDir)
{
	IconsPosition upperOrLower = IconsPosition::NONE;
	switch (arrowDir)
	{
	case Direction::Up: {upperOrLower = IconsPosition::UPPER; break; }
	case Direction::Down: {upperOrLower = IconsPosition::LOWER; break; }
	default: {throw MyException("GameManagement::Arrows_Menu() incorrect direction."); }
	}
	MenuElement* nearest = menu_ptr->MenuNavigation(menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y()), upperOrLower);
	if (nearest != nullptr)
	{
		cursor_ptr->CursorMovement(PointCoord(nearest->GetHalfXAxis(), nearest->GetUpperLeft().Get_y()));
	}
}
void GameManagement::Arrows_InfoPanel(Direction arrowDir)
{
	if (infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::MenuScreen)
	{
		if (cursor_ptr->GetCursorConsoleLocation() == PointCoord(infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetHalfXAxis(),
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetUpperLeft().Get_y()) && arrowDir == Direction::Left)
		{
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetBorder()->
				SetBorderForegroundColor(infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetInitialCondition()->foregroundBorderColor);
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->DrawBorder();
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetBorder()->
				SetBorderForegroundColor(infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetInitialCondition()->activeButtonColor);
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->DrawBorder();
			cursor_ptr->CursorMovement(PointCoord(infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetHalfXAxis(),
				infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetUpperLeft().Get_y()));
		}
		if (cursor_ptr->GetCursorConsoleLocation() == PointCoord(infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetHalfXAxis(),
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetUpperLeft().Get_y()) && arrowDir == Direction::Right)
		{
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetBorder()->
				SetBorderForegroundColor(infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetInitialCondition()->foregroundBorderColor);
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->DrawBorder();
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetBorder()->
				SetBorderForegroundColor(infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetInitialCondition()->activeButtonColor);
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->DrawBorder();
			cursor_ptr->CursorMovement(PointCoord(infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetHalfXAxis(),
				infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetUpperLeft().Get_y()));
		}
	}
}
void GameManagement::Arrows(Direction arrowDir)
{
	switch (cursor_ptr->GetCursorArea(camera_ptr, menu_ptr, infoPanel_ptr))
	{
	case CursorLocation::Camera:
	{
		Arrows_PlayingField(arrowDir);
		return;
	}
	case CursorLocation::Menu:
	{
		Arrows_Menu(arrowDir);
		return;
	}
	case CursorLocation::InfoPanel:
	{
		Arrows_InfoPanel(arrowDir);
		return;
	}
	default: {return; }
	}
}
void GameManagement::Arrows_MainMenu(Direction arrowDir)
{
	switch (arrowDir)
	{
	case Direction::Up: {mainMenu_ptr->ActiveButtonUp(cursor_ptr); return; }
	case Direction::Down: {mainMenu_ptr->ActiveButtonDown(cursor_ptr); return; }
	default: {throw MyException("GameManagement::Arrows_MainMenu(Direction arrowDir) bad direction"); }
	}
}
void GameManagement::UserActions(int key)
{
	switch (key)
	{
	case 104: { H_Key(); return; }	//'h' key hides or display Menu
	case 115: { S_Key(); return; }	//'s' key changes placement of menu from right to left and vice versa
	case 114: { R_Key(); return; }	//'r' key rotates preliminary building
	case 105: { I_Key(); return; }	//'i' key used to navigate to the info panel and vice versa
	case 75: { Arrows(Direction::Left); return; }	//left arrow 
	case 72: { Arrows(Direction::Up); return; }		//up arrow 
	case 77: { Arrows(Direction::Right); return; }	//right arrow 
	case 80: { Arrows(Direction::Down); return; }	//down arrow 
	case 9: { Tab_Key(); return; }		//tab key used to navigate between interface elements
	case 13: { Enter_Key(); return; }	//enter key: usual enter key functional
	case 27: { Esc_Key(); return; }	//esc cancel choices, usual functional as well
	case 122: {Z_Key(); return; }
	default: {UserMessageNotify("Unknown command"); return; } //TODO another exception
	}
}