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
void GameManagement::CreateAllObjects()
{
	allObjects_ptr = new AllObjects(cursor_ptr, draw_ptr);
}
void GameManagement::CreateCamera()
{
	RectangleSymbols* cameraSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetCameraVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetCameraHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetCameraUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetCameraUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetCameraBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetCameraBottomRightSymbol());
	color cameraBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetCameraBorderForegroundColor();
	color cameraBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetCameraBorderBackgroundColor();
	BorderAppearance* cameraBorder_ptr = new BorderAppearance(cameraSymbols_ptr, cameraBorderForegroundColor, cameraBorderBackgroundColor);
	color cameraLetterColor = ConstructionOptions::GetAllOptions()->GetCameraLetterColor();
	color cameraShadingColor = ConstructionOptions::GetAllOptions()->GetCameraShadingColor();
	camera_ptr = new Camera(ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft(), ConstructionOptions::GetAllOptions()->GetCameraHeightAdd(),
		ConstructionOptions::GetAllOptions()->GetCameraWidthAdd(), cameraBorder_ptr, cameraLetterColor, cameraShadingColor, draw_ptr, cursor_ptr);
}
void GameManagement::CreatePlayingField()
{
	RectangleSymbols* playingFieldSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetVerticalPlayingField(),
		ConstructionOptions::GetAllOptions()->GetHorizontalPlayingField(), ConstructionOptions::GetAllOptions()->GetUpperLeftPlayingField(),
		ConstructionOptions::GetAllOptions()->GetUpperRightPlayingField(), ConstructionOptions::GetAllOptions()->GetBottomLeftPlayingField(),
		ConstructionOptions::GetAllOptions()->GetBottomRightPlayingField());
	color playingFieldBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetPlayingFieldBorderForegroundColor();
	color playingFieldBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetPlayingFieldBorderBackgroundColor();
	BorderAppearance* playingFieldBorder_ptr = new BorderAppearance(playingFieldSymbols_ptr, playingFieldBorderForegroundColor, playingFieldBorderBackgroundColor);
	color playingFieldLetterColor = ConstructionOptions::GetAllOptions()->GetPlayingFieldLetterColor();
	color playingFieldShadingColor = ConstructionOptions::GetAllOptions()->GetPlayingFieldShadingColor();
	field_ptr = new PlayingField(ConstructionOptions::GetAllOptions()->GetPlayingFieldUpperLeft(), ConstructionOptions::GetAllOptions()->GetPlayingFieldHeightAdd(),
		ConstructionOptions::GetAllOptions()->GetPlayingFieldWidthAdd(), playingFieldBorder_ptr, playingFieldLetterColor, playingFieldShadingColor, draw_ptr, cursor_ptr);
}
void GameManagement::CreateMenuAndElements()
{
	PointCoord menuUpperLeft(camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() + 1, camera_ptr->GetUpperLeft().Get_y());
	RectangleSymbols* menuSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuBottomRightSymbol());
	color menuBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetMenuBorderForegroundColor();
	color menuBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetMenuBorderBackgroundColor();
	BorderAppearance* menuBorder = new BorderAppearance(menuSymbols_ptr, menuBorderForegroundColor, menuBorderBackgroundColor);
	color menuLetterColor = ConstructionOptions::GetAllOptions()->GetMenuLetterColor();
	color menuShadingColor = ConstructionOptions::GetAllOptions()->GetMenuShadingColor();
	menu_ptr = new Menu(draw_ptr, cursor_ptr, menuUpperLeft, ConstructionOptions::GetAllOptions()->GetMenuHeightAdd(),
		ConstructionOptions::GetAllOptions()->GetMenuWidthAdd(), menuBorder, menuLetterColor, menuShadingColor);
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetIceCreamShopCost(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopDescription(), ConstructionOptions::GetAllOptions()->GetIceCreamShopIconSymbol(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopForegroundColor(), ConstructionOptions::GetAllOptions()->GetIceCreamShopConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopNotConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetIceCreamShopChosenBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopSymbol(), ConstructionOptions::GetAllOptions()->GetIceCreamShopExpences(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopHeightAdd(), ConstructionOptions::GetAllOptions()->GetIceCreamShopWidthAdd());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetRoadCost(), ConstructionOptions::GetAllOptions()->GetRoadDescription(),
		ConstructionOptions::GetAllOptions()->GetRoadIconSymbol(), ConstructionOptions::GetAllOptions()->GetRoadForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetRoadConnectedBackgroundColor(), ConstructionOptions::GetAllOptions()->GetRoadNotConnectedBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetRoadChosenBackgroundColor());
}
void GameManagement::CreateInfoPanel()
{
	RectangleSymbols* infoPanelBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetInfoPanelVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelBottomRightSymbol());
	color borderForegroundColor = ConstructionOptions::GetAllOptions()->GetInfoPanelBorderForegroundColor();
	color borderBackgroundColor = ConstructionOptions::GetAllOptions()->GetInfoPanelBorderBackgroundColor();
	BorderAppearance* externalBorder = new BorderAppearance(infoPanelBorderSymbols_ptr, borderForegroundColor, borderBackgroundColor);
	color letterColor = ConstructionOptions::GetAllOptions()->GetInfoPanelTextColor();
	color shadingColor = ConstructionOptions::GetAllOptions()->GetInfoPanelShadingColor();
	infoPanel_ptr = new InfoPanel(ConstructionOptions::GetAllOptions()->GetInfoPanelUpperLeft(), ConstructionOptions::GetAllOptions()->GetInfoPanelHeightAdd(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelWidthAdd(), externalBorder, letterColor, shadingColor, draw_ptr, cursor_ptr);
	infoPanel_ptr->CreateMenuScreen();
	infoPanel_ptr->CreateControlsScreen();
	infoPanel_ptr->CreateGameMessagesScreen();
	ChosenConstructionAttach(infoPanel_ptr);
	UserMessageAttach(infoPanel_ptr);
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
	if(choosenConstruction_ptr == nullptr)
	{
		//TODO exception
	}
	else
	{
		choosenConstruction_ptr->SetChosenStatus(true);
		int mask = choosenConstruction_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), allObjects_ptr->GetPreliminaryElement());
		choosenConstruction_ptr->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(), camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(),
			camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
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
	if(message.empty())
	{
		//TODO exception
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
CursorLocation GameManagement::GetCursorArea()
{
	if (cursor_ptr->GetCursorConsoleLocation().Get_x() < (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_x() > camera_ptr->GetUpperLeft().Get_x() &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() < (camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() > camera_ptr->GetUpperLeft().Get_y())	//this condition checks if the cursor is within the camera borders
	{
		return CursorLocation::Camera;
	}
	else if (cursor_ptr->GetCursorConsoleLocation().Get_x() < (menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_x() > menu_ptr->GetUpperLeft().Get_x() &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() < (menu_ptr->GetUpperLeft().Get_y() + menu_ptr->GetHeightAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() > menu_ptr->GetUpperLeft().Get_y())		//when the cursor is in the Menu
	{
		return CursorLocation::Menu;
	}
	else if (cursor_ptr->GetCursorConsoleLocation().Get_x() < (infoPanel_ptr->GetUpperLeft().Get_x() + infoPanel_ptr->GetWidthAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_x() > infoPanel_ptr->GetUpperLeft().Get_x() &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() < (infoPanel_ptr->GetUpperLeft().Get_y() + infoPanel_ptr->GetHeightAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() > infoPanel_ptr->GetUpperLeft().Get_y())	//when the cursor is in the InfoPanel
	{
		return CursorLocation::InfoPanel;
	}
	else
	{
		return CursorLocation::Unknown;
	}
}
void GameManagement::ReturnCursorToCamera()
{
	if (GetCursorArea() == CursorLocation::Camera)
	{
		cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
	}
	else
	{
		cursor_ptr->CursorMovement(PointCoord(camera_ptr->GetHalfXAxis(), camera_ptr->GetHalfYAxis()));
	}
}
void GameManagement::DrawCursor()
{
	if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr) && allObjects_ptr->GetPreliminaryElement() == nullptr)
	{
		draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(),
			ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
	}
}
void GameManagement::DisplayMenu()
{
	menu_ptr->DrawBorder();
	menu_ptr->ShowMenuItems();
	ReturnCursorToCamera();
	DrawCursor();
}
void GameManagement::HideMenu()
{
	menu_ptr->ClearContent();
	menu_ptr->EraseBorder();
	ReturnCursorToCamera();
	DrawCursor();
}
void GameManagement::DisplayInfoPanel()
{
	infoPanel_ptr->DrawBorder();
	infoPanel_ptr->ShowSplashScreen(ConstructionOptions::GetAllOptions()->GetSplashScreenForegroundColor(), ConstructionOptions::GetAllOptions()->GetSplashScreenBackgroundColor());
	ReturnCursorToCamera();
	DrawCursor();
}
void GameManagement::HideInfoPanel()
{
	infoPanel_ptr->ClearContent();
	infoPanel_ptr->EraseBorder();
	ReturnCursorToCamera();
	DrawCursor();
}
void GameManagement::EraseScreen()
{
	set_color(color::cBLACK);
	system("cls");
}
void GameManagement::DisplayCamera()
{
	camera_ptr->DrawBorder();
	ReturnCursorToCamera();
	DrawCursor();
}
void GameManagement::DisplayPlayingField()
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	int leftX = field_ptr->GetUpperLeft().Get_x();
	int topY = field_ptr->GetUpperLeft().Get_y();
	int rightX = leftX + field_ptr->GetWidthAddition();
	int bottomY = topY + field_ptr->GetHeightAddition();
	draw_ptr->DrawPartOfRectangle(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY,
		field_ptr->GetBorder()->GetBorderSymbols()->GetVerticalSymbol(), field_ptr->GetBorder()->GetBorderSymbols()->GetHorizontalSymbol(),
		field_ptr->GetBorder()->GetBorderSymbols()->GetUpperLeftSymbol(), field_ptr->GetBorder()->GetBorderSymbols()->GetUpperRightSymbol(),
		field_ptr->GetBorder()->GetBorderSymbols()->GetBottomLeftSymbol(), field_ptr->GetBorder()->GetBorderSymbols()->GetBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetPlayingFieldBorderForegroundColor());
	ReturnCursorToCamera();
	DrawCursor();
}
void GameManagement::ErasePlayingField()
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	int leftX = field_ptr->GetUpperLeft().Get_x();
	int topY = field_ptr->GetUpperLeft().Get_y();
	int rightX = leftX + field_ptr->GetWidthAddition();
	int bottomY = topY + field_ptr->GetHeightAddition();
	draw_ptr->ErasePartOfRectangle(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY);
	ReturnCursorToCamera();
	DrawCursor();
}
void GameManagement::DisplayAllObjects()
{
	allObjects_ptr->DisplayBuildings(camera_ptr, field_ptr);
	allObjects_ptr->DisplayRoads(camera_ptr, field_ptr);
	allObjects_ptr->DisplayVisitors();
	ReturnCursorToCamera();
	DrawCursor();
}
//
void GameManagement::HideInterface()
{
	HideMenu();
	HideInfoPanel();
	menu_ptr->SetHideMenuStatus(1);
}
void GameManagement::ShowInterface()
{
	DisplayMenu();
	DisplayInfoPanel();
	menu_ptr->SetHideMenuStatus(0);
}
//
void GameManagement::GameProcess()
{
	char ch = 'a';
	while (true)
	{
		try
		{
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
				if (shifting)
				{
					allObjects_ptr->EraseObjects(camera_ptr);
					ErasePlayingField();
					allObjects_ptr->ShiftBuildings(shiftDirection);
					allObjects_ptr->ShiftRoads(shiftDirection);
					allObjects_ptr->ShiftVisitors(shiftDirection);
					field_ptr->Shift(shiftDirection);
					DisplayAllObjects();
					DisplayPlayingField();
				}
				DrawCursor();
			}
			wait(100);
		}
		catch (const MyException& error)
		{
			infoPanel_ptr->GetMessagesScreen()->AddMessage(error.what());
		}
	}
}

void GameManagement::H_Key()
{
	if (!menu_ptr->GetHideMenuStatus())
	{
		HideInterface();
	}
	else
	{
		ShowInterface();
	}
}
void GameManagement::S_Key()
{
	allObjects_ptr->ErasePreliminaryElement(camera_ptr, field_ptr);
	Direction shiftDirection = menu_ptr->ChangeMenuSide(camera_ptr);
	allObjects_ptr->ShiftBuildings(shiftDirection, menu_ptr->GetWidthAddition());
	allObjects_ptr->ShiftRoads(shiftDirection, menu_ptr->GetWidthAddition());
	allObjects_ptr->ShiftVisitors(shiftDirection, menu_ptr->GetWidthAddition());
	field_ptr->Shift(shiftDirection, menu_ptr->GetWidthAddition());
	EraseScreen();
	DisplayCamera();
	DisplayMenu();
	DisplayAllObjects();
	DisplayPlayingField();
	DisplayInfoPanel();
	UserMessageNotify("Menu side changed");
}
void GameManagement::R_Key()
{
	if (GetCursorArea() == CursorLocation::Camera)
	{
		Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
		if (preliminary_ptr != nullptr)
		{
			if(!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
			{
				PointCoord preliminaryElementNeibourRedraw = preliminary_ptr->GetRedrawNeiboursPoint();
				int rotateRes = preliminary_ptr->RotateConstruction();
				if(rotateRes == -1)
				{
					UserMessageNotify("Rotation failed");
				}
				else
				{
					draw_ptr->EraseConstruction(preliminary_ptr->GetUpperLeft().Get_x(), preliminary_ptr->GetUpperLeft().Get_y(),
						preliminary_ptr->GetUpperLeft().Get_x() + preliminary_ptr->GetWidthAddition(), preliminary_ptr->GetUpperLeft().Get_y() + preliminary_ptr->GetHeightAddition());
					Construction::RedrawNeibours(preliminaryElementNeibourRedraw, allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr, camera_ptr);
					preliminary_ptr->ConnectedToRoad(allObjects_ptr->GetAllRoads(), preliminary_ptr);
					int mask = preliminary_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
					preliminary_ptr->DrawObject(mask, camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_y(), camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(),
						camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
					preliminary_ptr->RedrawNeibours(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr, camera_ptr);
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
void GameManagement::IKey_Camera()
{
	EscKey_Camera();
	if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
	{
		draw_ptr->ErasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
	}
	if (menu_ptr->GetHideMenuStatus())
	{
		ShowInterface();
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
	ReturnCursorToCamera();
	DrawCursor();
}
void GameManagement::I_Key()
{
	switch (GetCursorArea())
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
			ReturnCursorToCamera();
			//TODO can throw exception here
			return; 
		}
	}
}
void GameManagement::TabKey_Camera()
{
	if (menu_ptr->GetHideMenuStatus())
	{
		ShowInterface();
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
	ReturnCursorToCamera();
	DrawCursor();
}
void GameManagement::TabKey_InfoPanel()
{
	infoPanel_ptr->EndInteractionDisplayRule();
	ReturnCursorToCamera();
	DrawCursor();
}
void GameManagement::Tab_Key()
{
	switch (GetCursorArea())
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
			ReturnCursorToCamera();
			//TODO can throw exception here
			return; 
		}
	}
}
void GameManagement::EnterKey_Camera()
{
	Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
	if (preliminary_ptr != nullptr)
	{
		if(!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
		{
			MenuElement* elementOfPreliminary = menu_ptr->GetMenuElement(preliminary_ptr->GetDescriptor()->GetMenuElementLocation().Get_y());
			Construction* realObject_ptr = elementOfPreliminary->GetManager()->CreateConstruction(cursor_ptr->GetCursorConsoleLocation(), draw_ptr, allObjects_ptr);
			int mask = realObject_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
			realObject_ptr->RedrawNeibours(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), nullptr);
			realObject_ptr->ConnectedToRoad(allObjects_ptr->GetAllRoads(), preliminary_ptr);
			realObject_ptr->IsGraph(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
			realObject_ptr->DrawObject(mask);
			cursor_ptr->CursorMovement(PointCoord(realObject_ptr->GetUpperLeft().Get_x() + realObject_ptr->GetWidthAddition() + 1,
				realObject_ptr->GetUpperLeft().Get_y() + realObject_ptr->GetHeightAddition()));
			preliminary_ptr->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
			if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
			{
				mask = preliminary_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
				preliminary_ptr->RedrawNeibours(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
				preliminary_ptr->ConnectedToRoad(allObjects_ptr->GetAllRoads(), preliminary_ptr);
				preliminary_ptr->DrawObject(mask);
				cursor_ptr->CursorMovement(preliminary_ptr->GetUpperLeft());
			}
		}
		else
		{
			UserMessageNotify("Can't build in this location");
		}
	}
	else
	{
		Construction* userChoice_ptr = allObjects_ptr->FindConstruction(cursor_ptr->GetCursorConsoleLocation());
		if(userChoice_ptr == nullptr)
		{
			UserMessageNotify("No construction found");
		}
		else
		{
			ChosenConstructionNotify(userChoice_ptr);
		}
	}
}
void GameManagement::EnterKey_Menu()
{
	MenuElement* currentElement = menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y());
	currentElement->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementUnderConstructionColor());
	currentElement->DrawBorder();
	Construction* preliminary_ptr = menu_ptr->CreatePreliminaryObject(allObjects_ptr, camera_ptr);
	cursor_ptr->CursorMovement(PointCoord(camera_ptr->GetHalfXAxis(), camera_ptr->GetHalfYAxis()));
	preliminary_ptr->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
	if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
	{
		int mask = preliminary_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
		preliminary_ptr->RedrawNeibours(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
		preliminary_ptr->ConnectedToRoad(allObjects_ptr->GetAllRoads(), preliminary_ptr);
		preliminary_ptr->DrawObject(mask);
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
		}
		else if (cursor_ptr->GetCursorConsoleLocation().Get_x() == infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetHalfXAxis())
		{
			infoPanel_ptr->GetMenuScreen()->GetControlsButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
			infoPanel_ptr->SwitchContent(InfoPanelContentType::Controls);
		}
		else
		{
			return; //TODO throw exception
		}
	}
	else if (infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::SystemMessagesAndConstructionInfo)
	{
		int buttonHalfX = infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetHalfXAxis();
		int topY = infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetDeconstructButton()->GetUpperLeft().Get_y();
		if (cursor_ptr->GetCursorConsoleLocation() == PointCoord(buttonHalfX, topY))
		{
			Construction* chosen_ptr = infoPanel_ptr->GetMessagesScreen()->GetConstructionInfoScreen()->GetChosenConstruction();
			auto isEqual = [chosen_ptr](Construction* element)->bool
			{
				return (chosen_ptr == element);
			}
			chosen_ptr->EraseConstruction();
			allObjects_ptr->DeleteConstruction(chosen_ptr, isEqual);
		}
	}
	else
	{
		return;
	}
}
void GameManagement::Enter_Key()
{
	switch (GetCursorArea())
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
			ReturnCursorToCamera();
			//TODO can throw exception here
			return;
		} 
	}
}
void GameManagement::EscKey_Camera()
{
	Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
	if (preliminary_ptr != nullptr)
	{
		MenuElement* elementOfPreliminary = menu_ptr->GetMenuElement(preliminary_ptr->GetDescriptor()->GetMenuElementLocation().Get_y());
		elementOfPreliminary->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor());
		if (!menu_ptr->GetHideMenuStatus())
		{
			elementOfPreliminary->DrawBorder();
		}
		allObjects_ptr->ErasePreliminaryElement(camera_ptr, field_ptr);
		ReturnCursorToCamera();
		DrawCursor();
	}
}
void GameManagement::EscKey_InfoPanel()
{
	if (infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::Controls || infoPanel_ptr->GetCurrentContent() == InfoPanelContentType::SystemMessagesAndConstructionInfo)
	{
		infoPanel_ptr->SwitchContent(InfoPanelContentType::MenuScreen);
	}
}
void GameManagement::Esc_Key()
{
	switch (GetCursorArea())
	{
	case CursorLocation::Camera:
	{
		EscKey_Camera();
		return;
	}
	case CursorLocation::Menu:
	{
		return; //TODO exception with message
	}
	case CursorLocation::InfoPanel:
	{
		EscKey_InfoPanel();
		return;
	}
	default: {return; } //TODO can throw exception here
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
	default: {return; } //TODO exception
	}
	Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
	if (preliminary_ptr != nullptr)
	{
		if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
		{
			draw_ptr->EraseConstruction(preliminary_ptr->GetUpperLeft().Get_x(), preliminary_ptr->GetUpperLeft().Get_y(),
				preliminary_ptr->GetUpperLeft().Get_x() + preliminary_ptr->GetWidthAddition(), preliminary_ptr->GetUpperLeft().Get_y() + preliminary_ptr->GetHeightAddition());
		}
		PointCoord preliminaryElementNeibourRedraw = preliminary_ptr->GetRedrawNeiboursPoint();
		preliminary_ptr->SetUpperLeft(PointCoord(preliminary_ptr->GetUpperLeft().Get_x() + changeX, preliminary_ptr->GetUpperLeft().Get_y() + changeY));
		cursor_ptr->CursorMovement(PointCoord(preliminary_ptr->GetUpperLeft().Get_x() + changeX, preliminary_ptr->GetUpperLeft().Get_y() + changeY));
		Construction::RedrawNeibours(preliminaryElementNeibourRedraw, allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
		if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
		{
			int mask = preliminary_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
			preliminary_ptr->RedrawNeibours(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
			preliminary_ptr->ConnectedToRoad(allObjects_ptr->GetAllRoads(), preliminary_ptr);
			preliminary_ptr->DrawObject(mask);
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
	default: {return; } //TODO exception
	}
	MenuElement* nearest = menu_ptr->MenuNavigation(menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y()), upperOrLower);
	cursor_ptr->CursorMovement(PointCoord(nearest->GetHalfXAxis(), nearest->GetUpperLeft().Get_y()));
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
	switch (GetCursorArea())
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
	default: {return; } //TODO can throw exception here
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
	default: {return; } //TODO another exception
	}
}