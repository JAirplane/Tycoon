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
		ConstructionOptions::GetAllOptions()->GetCameraHeightAdd(), ConstructionOptions::GetAllOptions()->GetCameraWidthAdd(),
		ConstructionOptions::GetAllOptions()->GetCameraVerticalSymbol(), ConstructionOptions::GetAllOptions()->GetCameraHorizontalSymbol(),
		ConstructionOptions::GetAllOptions()->GetCameraUpperLeftSymbol(), ConstructionOptions::GetAllOptions()->GetCameraUpperRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetCameraBottomLeftSymbol(), ConstructionOptions::GetAllOptions()->GetCameraBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetCameraBorderForegroundColor(), ConstructionOptions::GetAllOptions()->GetCameraBorderBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetCameraLetterColor(), ConstructionOptions::GetAllOptions()->GetCameraShadingColor(), draw_ptr, cursor_ptr);
	camera_ptr = new Camera(cameraRectangle);
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
		ConstructionOptions::GetAllOptions()->GetPlayingFieldHeightAdd(), ConstructionOptions::GetAllOptions()->GetPlayingFieldWidthAdd(),
		ConstructionOptions::GetAllOptions()->GetVerticalPlayingField(), ConstructionOptions::GetAllOptions()->GetHorizontalPlayingField(),
		ConstructionOptions::GetAllOptions()->GetUpperLeftPlayingField(), ConstructionOptions::GetAllOptions()->GetUpperRightPlayingField(),
		ConstructionOptions::GetAllOptions()->GetBottomLeftPlayingField(), ConstructionOptions::GetAllOptions()->GetBottomRightPlayingField(),
		ConstructionOptions::GetAllOptions()->GetPlayingFieldBorderForegroundColor(), ConstructionOptions::GetAllOptions()->GetPlayingFieldBorderBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetPlayingFieldLetterColor(), ConstructionOptions::GetAllOptions()->GetPlayingFieldShadingColor(), draw_ptr, cursor_ptr);
	field_ptr = new PlayingField(playingFieldRectangle);
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
	MyRectangle* menuRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(menuUpperLeft, ConstructionOptions::GetAllOptions()->GetMenuHeightAdd(),
		ConstructionOptions::GetAllOptions()->GetMenuWidthAdd(), ConstructionOptions::GetAllOptions()->GetMenuVerticalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuHorizontalSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuUpperLeftSymbol(), ConstructionOptions::GetAllOptions()->GetMenuUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuBottomRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuBorderForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetMenuBorderBackgroundColor(), ConstructionOptions::GetAllOptions()->GetMenuLetterColor(),
		ConstructionOptions::GetAllOptions()->GetMenuShadingColor(), draw_ptr, cursor_ptr);
	menu_ptr = new Menu(menuRectangle);
	delete menuRectangle; //
	menu_ptr->CreateGameStats();
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetRoadCost(), ConstructionOptions::GetAllOptions()->GetRoadDescription(),
		ConstructionOptions::GetAllOptions()->GetRoadIconSymbol(), ConstructionOptions::GetAllOptions()->GetRoadForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetRoadConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetRoadNotConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetRoadChosenBackgroundColor());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetToiletCost(), ConstructionOptions::GetAllOptions()->GetToiletDescription(),
		ConstructionOptions::GetAllOptions()->GetToiletIconSymbol(), ConstructionOptions::GetAllOptions()->GetToiletForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetToiletConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetToiletNotConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetToiletChosenBackgroundColor(), ConstructionOptions::GetAllOptions()->GetToiletSymbol(),
		ConstructionOptions::GetAllOptions()->GetToiletToiletNeed(), ConstructionOptions::GetAllOptions()->GetToiletHungerSatisfaction(),
		ConstructionOptions::GetAllOptions()->GetToiletVisitPrice(), ConstructionOptions::GetAllOptions()->GetToiletEntertainmentValue(),
		ConstructionOptions::GetAllOptions()->GetToiletIsExit(), ConstructionOptions::GetAllOptions()->GetToiletMaxVisitors(),
		ConstructionOptions::GetAllOptions()->GetToiletVisitTime(), ConstructionOptions::GetAllOptions()->GetToiletExpences(),
		ConstructionOptions::GetAllOptions()->GetToiletHeightAdd(), ConstructionOptions::GetAllOptions()->GetToiletWidthAdd());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetIceCreamShopCost(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopDescription(), ConstructionOptions::GetAllOptions()->GetIceCreamShopIconSymbol(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopForegroundColor(), ConstructionOptions::GetAllOptions()->GetIceCreamShopConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopNotConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetIceCreamShopChosenBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopSymbol(), ConstructionOptions::GetAllOptions()->GetIceCreamShopToiletNeed(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopHungerSatisfaction(), ConstructionOptions::GetAllOptions()->GetIceCreamShopVisitPrice(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopEntertainmentValue(), ConstructionOptions::GetAllOptions()->GetIceCreamShopIsExit(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopMaxVisitors(), ConstructionOptions::GetAllOptions()->GetIceCreamShopVisitTime(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopExpences(), ConstructionOptions::GetAllOptions()->GetIceCreamShopHeightAdd(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopWidthAdd());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetFoodCourtCost(), ConstructionOptions::GetAllOptions()->GetFoodCourtDescription(),
		ConstructionOptions::GetAllOptions()->GetFoodCourtIconSymbol(), ConstructionOptions::GetAllOptions()->GetFoodCourtForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetFoodCourtConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetFoodCourtNotConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetFoodCourtChosenBackgroundColor(), ConstructionOptions::GetAllOptions()->GetFoodCourtSymbol(),
		ConstructionOptions::GetAllOptions()->GetFoodCourtToiletNeed(), ConstructionOptions::GetAllOptions()->GetFoodCourtHungerSatisfaction(),
		ConstructionOptions::GetAllOptions()->GetFoodCourtVisitPrice(), ConstructionOptions::GetAllOptions()->GetFoodCourtEntertainmentValue(),
		ConstructionOptions::GetAllOptions()->GetFoodCourtIsExit(), ConstructionOptions::GetAllOptions()->GetFoodCourtMaxVisitors(),
		ConstructionOptions::GetAllOptions()->GetFoodCourtVisitTime(), ConstructionOptions::GetAllOptions()->GetFoodCourtExpences(),
		ConstructionOptions::GetAllOptions()->GetFoodCourtHeightAdd(), ConstructionOptions::GetAllOptions()->GetFoodCourtWidthAdd());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetCarouselCost(), ConstructionOptions::GetAllOptions()->GetCarouselDescription(),
		ConstructionOptions::GetAllOptions()->GetCarouselIconSymbol(), ConstructionOptions::GetAllOptions()->GetCarouselForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetCarouselConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetCarouselNotConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetCarouselChosenBackgroundColor(), ConstructionOptions::GetAllOptions()->GetCarouselSymbol(),
		ConstructionOptions::GetAllOptions()->GetCarouselToiletNeed(), ConstructionOptions::GetAllOptions()->GetCarouselHungerSatisfaction(),
		ConstructionOptions::GetAllOptions()->GetCarouselVisitPrice(), ConstructionOptions::GetAllOptions()->GetCarouselEntertainmentValue(),
		ConstructionOptions::GetAllOptions()->GetCarouselIsExit(), ConstructionOptions::GetAllOptions()->GetCarouselMaxVisitors(),
		ConstructionOptions::GetAllOptions()->GetCarouselVisitTime(), ConstructionOptions::GetAllOptions()->GetCarouselExpences(),
		ConstructionOptions::GetAllOptions()->GetCarouselHeightAdd(), ConstructionOptions::GetAllOptions()->GetCarouselWidthAdd());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetDumboRideCost(), ConstructionOptions::GetAllOptions()->GetDumboRideDescription(),
		ConstructionOptions::GetAllOptions()->GetDumboRideIconSymbol(), ConstructionOptions::GetAllOptions()->GetDumboRideForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetDumboRideConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetDumboRideNotConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetDumboRideChosenBackgroundColor(), ConstructionOptions::GetAllOptions()->GetDumboRideSymbol(),
		ConstructionOptions::GetAllOptions()->GetDumboRideToiletNeed(), ConstructionOptions::GetAllOptions()->GetDumboRideHungerSatisfaction(),
		ConstructionOptions::GetAllOptions()->GetDumboRideVisitPrice(), ConstructionOptions::GetAllOptions()->GetDumboRideEntertainmentValue(),
		ConstructionOptions::GetAllOptions()->GetDumboRideIsExit(), ConstructionOptions::GetAllOptions()->GetDumboRideMaxVisitors(),
		ConstructionOptions::GetAllOptions()->GetDumboRideVisitTime(), ConstructionOptions::GetAllOptions()->GetDumboRideExpences(),
		ConstructionOptions::GetAllOptions()->GetDumboRideHeightAdd(), ConstructionOptions::GetAllOptions()->GetDumboRideWidthAdd());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetFerrisWheelCost(), ConstructionOptions::GetAllOptions()->GetFerrisWheelDescription(),
		ConstructionOptions::GetAllOptions()->GetFerrisWheelIconSymbol(), ConstructionOptions::GetAllOptions()->GetFerrisWheelForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetFerrisWheelConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetFerrisWheelNotConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetFerrisWheelChosenBackgroundColor(), ConstructionOptions::GetAllOptions()->GetFerrisWheelSymbol(),
		ConstructionOptions::GetAllOptions()->GetFerrisWheelToiletNeed(), ConstructionOptions::GetAllOptions()->GetFerrisWheelHungerSatisfaction(),
		ConstructionOptions::GetAllOptions()->GetFerrisWheelVisitPrice(), ConstructionOptions::GetAllOptions()->GetFerrisWheelEntertainmentValue(),
		ConstructionOptions::GetAllOptions()->GetFerrisWheelIsExit(), ConstructionOptions::GetAllOptions()->GetFerrisWheelMaxVisitors(),
		ConstructionOptions::GetAllOptions()->GetFerrisWheelVisitTime(), ConstructionOptions::GetAllOptions()->GetFerrisWheelExpences(),
		ConstructionOptions::GetAllOptions()->GetFerrisWheelHeightAdd(), ConstructionOptions::GetAllOptions()->GetFerrisWheelWidthAdd());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetRollerCoasterCost(), ConstructionOptions::GetAllOptions()->GetRollerCoasterDescription(),
		ConstructionOptions::GetAllOptions()->GetRollerCoasterIconSymbol(), ConstructionOptions::GetAllOptions()->GetRollerCoasterForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetRollerCoasterConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetRollerCoasterNotConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetRollerCoasterChosenBackgroundColor(), ConstructionOptions::GetAllOptions()->GetRollerCoasterSymbol(),
		ConstructionOptions::GetAllOptions()->GetRollerCoasterToiletNeed(), ConstructionOptions::GetAllOptions()->GetRollerCoasterHungerSatisfaction(),
		ConstructionOptions::GetAllOptions()->GetRollerCoasterVisitPrice(), ConstructionOptions::GetAllOptions()->GetRollerCoasterEntertainmentValue(),
		ConstructionOptions::GetAllOptions()->GetRollerCoasterIsExit(), ConstructionOptions::GetAllOptions()->GetRollerCoasterMaxVisitors(),
		ConstructionOptions::GetAllOptions()->GetRollerCoasterVisitTime(), ConstructionOptions::GetAllOptions()->GetRollerCoasterExpences(),
		ConstructionOptions::GetAllOptions()->GetRollerCoasterHeightAdd(), ConstructionOptions::GetAllOptions()->GetRollerCoasterWidthAdd());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetBumperCarsCost(), ConstructionOptions::GetAllOptions()->GetBumperCarsDescription(),
		ConstructionOptions::GetAllOptions()->GetBumperCarsIconSymbol(), ConstructionOptions::GetAllOptions()->GetBumperCarsForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetBumperCarsConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetBumperCarsNotConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetBumperCarsChosenBackgroundColor(), ConstructionOptions::GetAllOptions()->GetBumperCarsSymbol(),
		ConstructionOptions::GetAllOptions()->GetBumperCarsToiletNeed(), ConstructionOptions::GetAllOptions()->GetBumperCarsHungerSatisfaction(),
		ConstructionOptions::GetAllOptions()->GetBumperCarsVisitPrice(), ConstructionOptions::GetAllOptions()->GetBumperCarsEntertainmentValue(),
		ConstructionOptions::GetAllOptions()->GetBumperCarsIsExit(), ConstructionOptions::GetAllOptions()->GetBumperCarsMaxVisitors(),
		ConstructionOptions::GetAllOptions()->GetBumperCarsVisitTime(), ConstructionOptions::GetAllOptions()->GetBumperCarsExpences(),
		ConstructionOptions::GetAllOptions()->GetBumperCarsHeightAdd(), ConstructionOptions::GetAllOptions()->GetBumperCarsWidthAdd());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetLogRideCost(), ConstructionOptions::GetAllOptions()->GetLogRideDescription(),
		ConstructionOptions::GetAllOptions()->GetLogRideIconSymbol(), ConstructionOptions::GetAllOptions()->GetLogRideForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetLogRideConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetLogRideNotConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetLogRideChosenBackgroundColor(), ConstructionOptions::GetAllOptions()->GetLogRideSymbol(),
		ConstructionOptions::GetAllOptions()->GetLogRideToiletNeed(), ConstructionOptions::GetAllOptions()->GetLogRideHungerSatisfaction(),
		ConstructionOptions::GetAllOptions()->GetLogRideVisitPrice(), ConstructionOptions::GetAllOptions()->GetLogRideEntertainmentValue(),
		ConstructionOptions::GetAllOptions()->GetLogRideIsExit(), ConstructionOptions::GetAllOptions()->GetLogRideMaxVisitors(),
		ConstructionOptions::GetAllOptions()->GetLogRideVisitTime(), ConstructionOptions::GetAllOptions()->GetLogRideExpences(),
		ConstructionOptions::GetAllOptions()->GetLogRideHeightAdd(), ConstructionOptions::GetAllOptions()->GetLogRideWidthAdd());
	menu_ptr->CreateVisitorManager();
}
void GameManagement::CreateInfoPanel()
{
	if (draw_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMenuAndElements() draw_ptr is nullptr");
	}
	if (cursor_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMenuAndElements() cursor_ptr is nullptr");
	}
	MyRectangle* infoPanelRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(ConstructionOptions::GetAllOptions()->GetInfoPanelUpperLeft(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelHeightAdd(), ConstructionOptions::GetAllOptions()->GetInfoPanelWidthAdd(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelVerticalSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelHorizontalSymbol(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelUpperLeftSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelUpperRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelBottomLeftSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelBorderForegroundColor(), ConstructionOptions::GetAllOptions()->GetInfoPanelBorderBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelTextColor(), ConstructionOptions::GetAllOptions()->GetInfoPanelShadingColor(), draw_ptr, cursor_ptr);
	infoPanel_ptr = new InfoPanel(infoPanelRectangle);
	delete infoPanelRectangle;
	infoPanel_ptr->CreateMenuScreen();
	infoPanel_ptr->CreateControlsScreen();
	infoPanel_ptr->CreateGameMessagesScreen();
	ChosenConstructionAttach(infoPanel_ptr);
	UserMessageAttach(infoPanel_ptr);
}
void GameManagement::CreateInitialSplashScreen()
{
	if (draw_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMenuAndElements() draw_ptr is nullptr");
	}
	if (cursor_ptr == nullptr)
	{
		throw MyException("GameManagement::CreateMenuAndElements() cursor_ptr is nullptr");
	}
	initialSplashScreen_ptr = RectangleCreator::GetRectangleFactory()->CreateRectangle(ConstructionOptions::GetAllOptions()->GetInitialSplashScreenUpperLeft(),
		camera_ptr->GetHeightAddition() + infoPanel_ptr->GetHeightAddition(), camera_ptr->GetWidthAddition() + menu_ptr->GetWidthAddition(),
		ConstructionOptions::GetAllOptions()->GetInitialSplashScreenVerticalSymbol(), ConstructionOptions::GetAllOptions()->GetInitialSplashScreenHorizontalSymbol(),
		ConstructionOptions::GetAllOptions()->GetInitialSplashScreenUpperLeftSymbol(), ConstructionOptions::GetAllOptions()->GetInitialSplashScreenUpperRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetInitialSplashScreenBottomLeftSymbol(), ConstructionOptions::GetAllOptions()->GetInitialSplashScreenBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetInitialSplashScreenBorderForegroundColor(), ConstructionOptions::GetAllOptions()->GetInitialSplashScreenBorderBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetInitialSplashScreenLetterColor(), ConstructionOptions::GetAllOptions()->GetInitialSplashScreenShadingColor(), draw_ptr, cursor_ptr);
}
//
void GameManagement::InitialDisplay() const
{
	gameElementsDrawer->DisplayCamera(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayMenu(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayInfoPanel(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayPlayingField(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayAllObjects(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
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
		menu_ptr->MenuElementRedrawBorder(preliminary_ptr->GetDescriptor()->GetMenuElementLocation().Get_y(),
			ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor());
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
				SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
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
		int key = _getch();
		if (key == 0 || key == 224)
		{
			key = _getch();
		}
		//cout << key;
		UserActions(key);
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
			current_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor());
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
	gameElementsDrawer->DisplayAllObjects(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
	gameElementsDrawer->DisplayPlayingField(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, allObjects_ptr, field_ptr);
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
	currentActiveElement_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor());
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
		MenuElement* elementOfPreliminary = menu_ptr->GetMenuElement(allObjects_ptr->GetPreliminaryElement()->GetDescriptor()->GetMenuElementLocation().Get_y());
		elementOfPreliminary->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor());
		elementOfPreliminary->DrawBorder();
		allObjects_ptr->ErasePreliminaryElement(camera_ptr, field_ptr);
	}
	MenuElement* upperVisibleElement = menu_ptr->GetUpperVisibleMenuElement();
	upperVisibleElement->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementActiveColor());
	upperVisibleElement->DrawBorder();
	cursor_ptr->CursorMovement(PointCoord(upperVisibleElement->GetHalfXAxis(), upperVisibleElement->GetUpperLeft().Get_y()));
}
void GameManagement::TabKey_Menu()
{
	MenuElement* currentElement = menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y());
	currentElement->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor());
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
				MenuElement* elementOfPreliminary = menu_ptr->GetMenuElement(preliminary_ptr->GetDescriptor()->GetMenuElementLocation().Get_y());
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
	menu_ptr->MenuElementRedrawBorder(menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y())->GetUpperLeft().Get_y(),
		ConstructionOptions::GetAllOptions()->GetMenuElementUnderConstructionColor());
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
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
			infoPanel_ptr->SwitchContent(InfoPanelContentType::SystemMessagesAndConstructionInfo);
			infoPanel_ptr->EraseInfoPanelMessage();
			infoPanel_ptr->DisplayInfoPanelMessage("Press 'esc' to get back to the previous screen");
			cursor_ptr->CursorMovement(PointCoord(infoPanel_ptr->GetMessagesScreen()->GetHalfXAxis(), infoPanel_ptr->GetMessagesScreen()->GetUpperLeft().Get_y()));
		}
		else if (cursor_ptr->GetCursorConsoleLocation().Get_x() == infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetHalfXAxis())
		{
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
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
					infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetBorder()->
						SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
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
			SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
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
	default: {throw MyException("GameManagement::Arrows_Menu() incorrect direction."); } //exception
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
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->DrawBorder();
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderActiveColor());
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->DrawBorder();
			cursor_ptr->CursorMovement(PointCoord(infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetHalfXAxis(),
				infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetUpperLeft().Get_y()));
		}
		if (cursor_ptr->GetCursorConsoleLocation() == PointCoord(infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetHalfXAxis(),
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetUpperLeft().Get_y()) && arrowDir == Direction::Right)
		{
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
			infoPanel_ptr->GetMenuScreen()->GetMessagesButton()->DrawBorder();
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderActiveColor());
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