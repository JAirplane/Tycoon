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
		ConstructionOptions::GetAllOptions()->GetIceCreamShopForegroundColor(), ConstructionOptions::GetAllOptions()->GetIceCreamShopBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopSymbol(), ConstructionOptions::GetAllOptions()->GetIceCreamShopExpences(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopHeightAdd(), ConstructionOptions::GetAllOptions()->GetIceCreamShopWidthAdd());
	menu_ptr->CreateMenuElement(ConstructionOptions::GetAllOptions()->GetRoadCost(), ConstructionOptions::GetAllOptions()->GetRoadDescription(),
		ConstructionOptions::GetAllOptions()->GetRoadIconSymbol(), ConstructionOptions::GetAllOptions()->GetRoadForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetRoadBackgroundColor());
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
}
void GameManagement::R_Key()
{
	if (GetCursorArea() == CursorLocation::Camera)
	{
		Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
		if (preliminary_ptr != nullptr && !allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
		{
			PointCoord preliminaryElementNeibourRedraw = preliminary_ptr->GetRedrawNeiboursPoint();
			preliminary_ptr->RotateConstruction();
			draw_ptr->EraseConstruction(preliminary_ptr->GetUpperLeft().Get_x(), preliminary_ptr->GetUpperLeft().Get_y(),
				preliminary_ptr->GetUpperLeft().Get_x() + preliminary_ptr->GetWidthAddition(), preliminary_ptr->GetUpperLeft().Get_y() + preliminary_ptr->GetHeightAddition());
			Construction::RedrawNeibours(preliminaryElementNeibourRedraw, allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
			preliminary_ptr->ConnectedToRoad(allObjects_ptr->GetAllRoads(), preliminary_ptr);
			preliminary_ptr->DrawObject();
			preliminary_ptr->RedrawNeibours(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), preliminary_ptr);
			cursor_ptr->CursorMovement(preliminary_ptr->GetUpperLeft());
		}
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
		infoPanel_ptr->ClearContent();
	}
	infoPanel_ptr->ShowMenuScreen();
}
void GameManagement::IKey_Menu()
{
	MenuElement* currentActiveElement_ptr = menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y());
	currentActiveElement_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor());
	currentActiveElement_ptr->DrawBorder();
	infoPanel_ptr->ClearContent();
	infoPanel_ptr->ShowMenuScreen();
}
void GameManagement::IKey_InfoPanel()
{
	infoPanel_ptr->EndInteraction();
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
		default: {return;}//TODO can throw exception here
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
	infoPanel_ptr->EndInteraction();
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
			TabKey_Camera();
			return;
		}
		case CursorLocation::InfoPanel:
		{
			TabKey_InfoPanel();
			return;
		}
		default: {return;} //TODO can throw exception here
	}
}
void GameManagement::EnterKey_Camera()
{
	Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
	if (preliminary_ptr != nullptr && !allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
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
		default: {return;} //TODO can throw exception here
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
void GameManagement::Arrows_PlayingField(PointCoord cursorDestination)
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
	if (preliminary_ptr != nullptr)
	{
		if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
		{
			draw_ptr->EraseConstruction(preliminary_ptr->GetUpperLeft().Get_x(), preliminary_ptr->GetUpperLeft().Get_y(),
				preliminary_ptr->GetUpperLeft().Get_x() + preliminary_ptr->GetWidthAddition(), preliminary_ptr->GetUpperLeft().Get_y() + preliminary_ptr->GetHeightAddition());
		}
		PointCoord preliminaryElementNeibourRedraw = preliminary_ptr->GetRedrawNeiboursPoint();
		preliminary_ptr->SetUpperLeft(cursorDestination);
		cursor_ptr->CursorMovement(cursorDestination);
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
			cursor_ptr->GetCursorConsoleLocation().Get_x() != cameraLeftX && cursor_ptr->GetCursorConsoleLocation().Get_x() != cameraRightX &&
			cursor_ptr->GetCursorConsoleLocation().Get_y() != cameraTopY && cursor_ptr->GetCursorConsoleLocation().Get_y() != cameraBottomY)
		{
			draw_ptr->ErasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
		}
		cursor_ptr->CursorMovement(cursorDestination);
		if (!allObjects_ptr->ObjectImposition(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y()), field_ptr) &&
			cursor_ptr->GetCursorConsoleLocation().Get_x() != cameraLeftX && cursor_ptr->GetCursorConsoleLocation().Get_x() != cameraRightX &&
			cursor_ptr->GetCursorConsoleLocation().Get_y() != cameraTopY && cursor_ptr->GetCursorConsoleLocation().Get_y() != cameraBottomY)
		{
			draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(),
				ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
		}
	}
	return;
}
void GameManagement::UpArrow_Menu()
{
	MenuElement* nearest = menu_ptr->MenuNavigation(menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y()), IconsPosition::UPPER);
	cursor_ptr->CursorMovement(PointCoord(nearest->GetUpperLeft().Get_x() + nearest->GetWidthAddition() / 2, nearest->GetUpperLeft().Get_y()));
}
void GameManagement::DownArrow_Menu()
{
	MenuElement* nearest = menu_ptr->MenuNavigation(menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y()), IconsPosition::LOWER);
	cursor_ptr->CursorMovement(PointCoord(nearest->GetUpperLeft().Get_x() + nearest->GetWidthAddition() / 2, nearest->GetUpperLeft().Get_y()));
}
void GameManagement::UserActions(int key)
{
	switch (key)
	{
	case 104: { H_Key(); return; }	//'h' key hide or display Menu
	case 115: { S_Key(); return; }	//'s' key change placement of menu from right to left and vice versa
	default: break;
	}
	if (cursor_ptr->GetCursorConsoleLocation().Get_x() < (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_x() > camera_ptr->GetUpperLeft().Get_x() &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() < (camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() > camera_ptr->GetUpperLeft().Get_y())	//this condition checks if the cursor is within the camera borders
	{
		switch (key)
		{
		case 114: { R_Key(); return; }	//'r' key rotate preliminary building
		case 105: { I_Key_PlayingField(); return; }
		case 75: { Arrows_PlayingField(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x() - 1, cursor_ptr->GetCursorConsoleLocation().Get_y())); return; }	//left arrow 
		case 72: { Arrows_PlayingField(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y() - 1)); return; }	//up arrow 
		case 77: { Arrows_PlayingField(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x() + 1, cursor_ptr->GetCursorConsoleLocation().Get_y())); return; }	//right arrow 
		case 80: { Arrows_PlayingField(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y() + 1)); return; }	//down arrow 
		case 9: { TabKey_Playingfield(); return; }		//tab key moves cursor from the playing field to the upper visible icon from menu
		case 13: { EnterKey_Camera(); return; }	//enter key builds construction, choosen from side menu
		case 27: { EscKey_Camera(); return; }	//esc prevents from keep build choosen construction (tab key too)
		default: return;
		}
	}
	else if (cursor_ptr->GetCursorConsoleLocation().Get_x() < (menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_x() > menu_ptr->GetUpperLeft().Get_x() &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() < (menu_ptr->GetUpperLeft().Get_y() + menu_ptr->GetHeightAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() > menu_ptr->GetUpperLeft().Get_y())		//when the cursor is in the side menu
	{
		switch (key)
		{
		case 105: { I_Key_Menu(); return; }
		case 72: { UpArrow_Menu(); return; }	//up arrow
		case 80: { DownArrow_Menu(); return; }	//down arrow
		case 9: { TabKey_Menu(); return; }	//tab key moves cursor to the center of playing field
		case 13: { EnterKey_Menu(); return; }	//enter key chooses building to create
		default: return;
		}
	}
	else if (cursor_ptr->GetCursorConsoleLocation().Get_x() < (infoPanel_ptr->GetUpperLeft().Get_x() + infoPanel_ptr->GetWidthAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_x() > infoPanel_ptr->GetUpperLeft().Get_x() &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() < (infoPanel_ptr->GetUpperLeft().Get_y() + infoPanel_ptr->GetHeightAddition()) &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() > infoPanel_ptr->GetUpperLeft().Get_y())
	{
		switch (key)
		{
		case 75: { infoPanel_ptr->Arrows(Direction::Left); return; }
		case 77: { infoPanel_ptr->Arrows(Direction::Right); return; }
		case 105: { I_Key_InfoPanel(); return; }
		default: return;
		}
	}
}