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
void GameManagement::DisplayMenu()
{
	menu_ptr->DrawBorder();
	menu_ptr->ShowMenuItems();
	color cursorBackgroundColor = ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor();
	if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
	{
		draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), cursorBackgroundColor);
	}
}
void GameManagement::HideMenu()
{
	menu_ptr->ClearContent();
	menu_ptr->EraseBorder();
	if (cursor_ptr->GetCursorConsoleLocation().Get_x() < camera_ptr->GetUpperLeft().Get_x() ||
		cursor_ptr->GetCursorConsoleLocation().Get_x() > camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() ||
		cursor_ptr->GetCursorConsoleLocation().Get_y() < camera_ptr->GetUpperLeft().Get_y() ||
		cursor_ptr->GetCursorConsoleLocation().Get_y() > camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition())
	{
		int leftX = camera_ptr->GetUpperLeft().Get_x();
		int topY = camera_ptr->GetUpperLeft().Get_y();
		int rightX = leftX + camera_ptr->GetWidthAddition();
		int bottomY = topY + camera_ptr->GetHeightAddition();
		cursor_ptr->CursorMovement(PointCoord((leftX + rightX) / 2, (topY + bottomY) / 2));
	}
	else
	{
		cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
	}
	if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
	{
		draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), 
			ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
	}
}
void GameManagement::DisplayInfoPanel()
{
	infoPanel_ptr->DrawBorder();
	infoPanel_ptr->DrawSplashScreen(ConstructionOptions::GetAllOptions()->GetSplashScreenForegroundColor(), ConstructionOptions::GetAllOptions()->GetSplashScreenBackgroundColor());
}
void GameManagement::HideInfoPanel()
{
	infoPanel_ptr->ClearContent();
	infoPanel_ptr->EraseBorder();
}
void GameManagement::EraseScreen()
{
	set_color(color::cBLACK);
	system("cls");
}
void GameManagement::DisplayCamera()
{
	int leftX = camera_ptr->GetUpperLeft().Get_x();
	int topY = camera_ptr->GetUpperLeft().Get_y();
	int rightX = leftX + camera_ptr->GetWidthAddition();
	int bottomY = topY + camera_ptr->GetHeightAddition();
	camera_ptr->DrawBorder();
	cursor_ptr->CursorMovement(PointCoord((leftX + rightX) / 2, (topY + bottomY) / 2));
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
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
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
}
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
				if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr) && allObjects_ptr->GetPreliminaryElement() == nullptr)
				{
					draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(),
						ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
				}
			}
			wait(100);
		}
		catch (const MyException& error)
		{
			infoPanel_ptr->GetMessagesScreen()->AddMessage(error.what());
		}
	}
}
void GameManagement::DisplayAllObjects()
{
	allObjects_ptr->DisplayBuildings(camera_ptr, field_ptr);
	allObjects_ptr->DisplayRoads(camera_ptr, field_ptr);
	allObjects_ptr->DisplayVisitors();
}
void GameManagement::H_Key()
{
	if (!menu_ptr->GetHideMenuStatus())
	{
		HideMenu();
		HideInfoPanel();
		menu_ptr->SetHideMenuStatus(1);
	}
	else
	{
		DisplayMenu();
		DisplayInfoPanel();
		menu_ptr->SetHideMenuStatus(0);
	}
	return;
}
void GameManagement::S_Key()
{
	allObjects_ptr->ErasePreliminaryElement();
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
		cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
	}
}
void GameManagement::I_Key_PlayingField()
{
	EscKey_PlayingField();
	if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
	{
		draw_ptr->ErasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
	}
	if (menu_ptr->GetHideMenuStatus())
	{
		DisplayMenu();
		infoPanel_ptr->DrawBorder();
		menu_ptr->SetHideMenuStatus(0);
	}
	else
	{
		infoPanel_ptr->ClearContent();
	}
	infoPanel_ptr->DrawMenuScreen();
}
void GameManagement::I_Key_Menu()
{
	TabKey_Menu();
	I_Key_PlayingField();
}
void GameManagement::I_Key_InfoPanel()
{
	infoPanel_ptr->EndInteraction();
	cursor_ptr->CursorMovement(PointCoord(camera_ptr->GetUpperLeft().Get_x() + (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) / 2,
		camera_ptr->GetUpperLeft().Get_y() + (camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition()) / 2));
	if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
	{
		draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(),
			ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
	}
}
void GameManagement::TabKey_Playingfield()
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	int leftX = menu_ptr->GetUpperLeft().Get_x();
	int rightX = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition();
	if (menu_ptr->GetHideMenuStatus())
	{
		DisplayMenu();
		menu_ptr->SetHideMenuStatus(0);
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
		Construction* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
		if (!allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr))
		{
			draw_ptr->EraseConstruction(preliminary_ptr->GetUpperLeft().Get_x(), preliminary_ptr->GetUpperLeft().Get_y(),
				preliminary_ptr->GetUpperLeft().Get_x() + preliminary_ptr->GetHeightAddition(),
				preliminary_ptr->GetUpperLeft().Get_y() + preliminary_ptr->GetWidthAddition());
		}
		MenuElement* elementOfPreliminary = menu_ptr->GetMenuElement(preliminary_ptr->GetDescriptor()->GetMenuElementLocation().Get_y());
		elementOfPreliminary->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor());
		elementOfPreliminary->DrawBorder();
		PointCoord preliminaryElementNeibourRedraw = preliminary_ptr->GetRedrawNeiboursPoint();
		allObjects_ptr->ErasePreliminaryElement();
		Construction::RedrawNeibours(preliminaryElementNeibourRedraw, allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), allObjects_ptr->GetPreliminaryElement());
	}
	MenuElement* upperVisibleElement = menu_ptr->GetUpperVisibleMenuElement();
	upperVisibleElement->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementActiveColor());
	upperVisibleElement->DrawBorder();
	cursor_ptr->CursorMovement(PointCoord(upperVisibleElement->GetUpperLeft().Get_x() + upperVisibleElement->GetWidthAddition() / 2, upperVisibleElement->GetUpperLeft().Get_y()));
}
void GameManagement::TabKey_Menu()
{
	MenuElement* currentElement = menu_ptr->GetMenuElement(cursor_ptr->GetCursorConsoleLocation().Get_y());
	currentElement->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor());
	currentElement->DrawBorder();
	cursor_ptr->CursorMovement(PointCoord(camera_ptr->GetUpperLeft().Get_x() + (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) / 2,
		camera_ptr->GetUpperLeft().Get_y() + (camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition()) / 2));
	if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
	{
		draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
		cursor_ptr->SetCursorConsoleLocation();
	}
	return;
}
void GameManagement::EnterKey_PlayingField()
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
	Construction* preliminary_ptr = menu_ptr->CreatePreliminaryObject(allObjects_ptr, camera_ptr);
	currentElement->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementUnderConstructionColor());
	currentElement->DrawBorder();
	cursor_ptr->CursorMovement(PointCoord((camera_ptr->GetUpperLeft().Get_x() * 2 + camera_ptr->GetWidthAddition()) / 2,
		(camera_ptr->GetUpperLeft().Get_y() * 2 + camera_ptr->GetHeightAddition()) / 2));
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
void GameManagement::EscKey_PlayingField()
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
		if (!allObjects_ptr->ObjectImposition(allObjects_ptr->GetPreliminaryElement(), camera_ptr, field_ptr))
		{
			draw_ptr->EraseConstruction(allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_x(), allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_y(),
				allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_x() + allObjects_ptr->GetPreliminaryElement()->GetWidthAddition(),
				allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_y() + allObjects_ptr->GetPreliminaryElement()->GetHeightAddition());
		}
		PointCoord preliminaryElementNeibourRedraw = allObjects_ptr->GetPreliminaryElement()->GetRedrawNeiboursPoint();
		allObjects_ptr->ErasePreliminaryElement();
		cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
		Construction::RedrawNeibours(preliminaryElementNeibourRedraw, allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), allObjects_ptr->GetPreliminaryElement());
		if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
		{
			draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(),
				ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
		}
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
CursorLocation GameManagement::CurrentCursorLoc()
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
		case 13: { EnterKey_PlayingField(); return; }	//enter key builds construction, choosen from side menu
		case 27: { EscKey_PlayingField(); return; }	//esc prevents from keep build choosen construction (tab key too)
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