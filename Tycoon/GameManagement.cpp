#include "GameManagement.h"
///////////////GameManagement Class///////////////
void GameManagement::DisplayMenu()
{
	menu_ptr->ShowMenuBorders();
	DisplayInfoPanel();
	PointCoord underConstruction(0, 0);
	if (allObjects_ptr->GetPreliminaryElement() != nullptr)
	{
		underConstruction = allObjects_ptr->GetPreliminaryElement()->GetDescriptor()->GetManagerLocation();
	}
	menu_ptr->ShowMenuItems(underConstruction);
	color cursorBackgroundColor = ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor();
	if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
	{
		draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), cursorBackgroundColor);
	}
}
void GameManagement::HideMenu()
{
	menu_ptr->EraseMenu();
	HideInfoPanel();
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
		draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
	}
}
void GameManagement::DisplayInfoPanel()
{
	infoPanel_ptr->DrawInfoPanelExternalBorders();
	infoPanel_ptr->DrawInfoPanelSplashScreen(ConstructionOptions::GetAllOptions()->GetSplashScreenForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetSplashScreenBackgroundColor());
}
void GameManagement::HideInfoPanel()
{
	infoPanel_ptr->ClearInfoPanelContent();
	infoPanel_ptr->EraseInfoPanelExternalBorders();
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
	draw_ptr->DrawRectangle(leftX, topY, rightX, bottomY, camera_ptr->GetBorderSymbols()->GetVerticalSymbol(), camera_ptr->GetBorderSymbols()->GetHorizontalSymbol(),
		camera_ptr->GetBorderSymbols()->GetUpperLeftSymbol(), camera_ptr->GetBorderSymbols()->GetUpperRightSymbol(), camera_ptr->GetBorderSymbols()->GetBottomLeftSymbol(),
		camera_ptr->GetBorderSymbols()->GetBottomRightSymbol(), ConstructionOptions::GetAllOptions()->GetCameraColor());
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
	draw_ptr->DrawPartOfRectangle(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY, field_ptr->GetBorderSymbols()->GetVerticalSymbol(), field_ptr->GetBorderSymbols()->GetHorizontalSymbol(),
		field_ptr->GetBorderSymbols()->GetUpperLeftSymbol(), field_ptr->GetBorderSymbols()->GetUpperRightSymbol(), field_ptr->GetBorderSymbols()->GetBottomLeftSymbol(), field_ptr->GetBorderSymbols()->GetBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetPlayingFieldColor());
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
			Direction shiftDirection = camera_ptr->CursorIsOnCameraCheck(cursor_ptr);
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
			infoPanel_ptr->AddMessage(error.what());
		}
	}
}
void GameManagement::DisplayAllObjects()
{
	allObjects_ptr->DisplayBuildings(camera_ptr, field_ptr);
	allObjects_ptr->DisplayRoads(camera_ptr, field_ptr);
	allObjects_ptr->DisplayVisitors();
}
void GameManagement::CreateManagers()
{
	int xCoord = (menu_ptr->GetUpperLeft().Get_x() * 2 + menu_ptr->GetWidthAddition()) / 2;
	int yCoord = menu_ptr->GetUpperLeft().Get_y() + 1;
	PointCoord firstManagerUpperLeft(xCoord, yCoord);
	ConstructionDescriptor* iceCreamDesc = new BuildingDescriptor(firstManagerUpperLeft, ConstructionOptions::GetAllOptions()->GetIceCreamShopCost(), ConstructionOptions::GetAllOptions()->GetIceCreamShopDescription(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopIconSymbol(), ConstructionOptions::GetAllOptions()->GetIceCreamShopForegroundColor(), ConstructionOptions::GetAllOptions()->GetIceCreamShopBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopSymbol(), ConstructionOptions::GetAllOptions()->GetIceCreamShopExpences(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopHeightAdd(), ConstructionOptions::GetAllOptions()->GetIceCreamShopWidthAdd());
	ConstructionManager* iceCreamManager_ptr = new BuildingManager(firstManagerUpperLeft, cursor_ptr, iceCreamDesc);
	PointCoord nextManagerUpperLeft(xCoord, yCoord + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight());
	ConstructionDescriptor* roadDesc = new RoadDescriptor(nextManagerUpperLeft, ConstructionOptions::GetAllOptions()->GetRoadCost(), ConstructionOptions::GetAllOptions()->GetRoadDescription(),
		ConstructionOptions::GetAllOptions()->GetRoadIconSymbol(), ConstructionOptions::GetAllOptions()->GetRoadForegroundColor(), ConstructionOptions::GetAllOptions()->GetRoadBackgroundColor());
	ConstructionManager* roadManager_ptr = new RoadManager(nextManagerUpperLeft, cursor_ptr, roadDesc);
	menu_ptr->AddManager(iceCreamManager_ptr);
	menu_ptr->AddManager(roadManager_ptr);
}
void GameManagement::H_Key()
{
	if (!menu_ptr->GetHideMenuStatus())
	{
		HideMenu();
		menu_ptr->SetHideMenuStatus(1);
	}
	else
	{
		DisplayMenu();
		menu_ptr->SetHideMenuStatus(0);
	}
	return;
}
void GameManagement::S_Key()
{
	allObjects_ptr->ErasePreliminaryElement();
	Direction shiftDirection = menu_ptr->ChangeMenuSide();
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
void GameManagement::I_Key_OutOfInfoPanel()
{
	if (menu_ptr->GetHideMenuStatus())
	{
		DisplayMenu();
		infoPanel_ptr->DrawInfoPanelExternalBorders();
		menu_ptr->SetHideMenuStatus(0);
	}
	else
	{
		infoPanel_ptr->ClearInfoPanelContent();
	}
	infoPanel_ptr->DrawInfoScreen(ConstructionOptions::GetAllOptions()->GetInfoPanelButtonWidth(), ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetButtonContentBackgroundColor(), ConstructionOptions::GetAllOptions()->GetInfoScreenBorderForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetButtonBorderActiveColor(), ConstructionOptions::GetAllOptions()->GetInfoScreenBorderBackgroundColor());
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
		draw_ptr->DrawRectangle(leftX + 2, preliminary_ptr->GetDescriptor()->GetManagerLocation().Get_y(), rightX - 2,
			preliminary_ptr->GetDescriptor()->GetManagerLocation().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1,
			menu_ptr->GetItemSymbols()->GetVerticalSymbol(), menu_ptr->GetItemSymbols()->GetHorizontalSymbol(), menu_ptr->GetItemSymbols()->GetUpperLeftSymbol(),
			menu_ptr->GetItemSymbols()->GetUpperRightSymbol(), menu_ptr->GetItemSymbols()->GetBottomLeftSymbol(), menu_ptr->GetItemSymbols()->GetBottomRightSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuItemInactiveColor());	//draw external menu icon bordres
		PointCoord preliminaryElementNeibourRedraw = preliminary_ptr->GetRedrawNeiboursPoint();
		allObjects_ptr->ErasePreliminaryElement();
		Construction::RedrawNeibours(preliminaryElementNeibourRedraw, allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), allObjects_ptr->GetPreliminaryElement());
	}
	PointCoord upperVisibleItem = menu_ptr->GetNearestIconCoords(PointCoord(0, 0), IconsPosition::LOWER);
	draw_ptr->DrawRectangle(leftX + 2, upperVisibleItem.Get_y(), rightX - 2, upperVisibleItem.Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1,
		menu_ptr->GetItemSymbols()->GetVerticalSymbol(), menu_ptr->GetItemSymbols()->GetHorizontalSymbol(), menu_ptr->GetItemSymbols()->GetUpperLeftSymbol(),
		menu_ptr->GetItemSymbols()->GetUpperRightSymbol(), menu_ptr->GetItemSymbols()->GetBottomLeftSymbol(), menu_ptr->GetItemSymbols()->GetBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuItemActiveColor());	//draw external menu icon bordres
	cursor_ptr->CursorMovement(upperVisibleItem);
}
void GameManagement::TabKey_Menu()
{
	int MenuLeftX = menu_ptr->GetUpperLeft().Get_x();
	int MenuRightX = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition();
	draw_ptr->DrawRectangle(MenuLeftX + 2, cursor_ptr->GetCursorConsoleLocation().Get_y(), MenuRightX - 2,
		cursor_ptr->GetCursorConsoleLocation().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1,
		menu_ptr->GetItemSymbols()->GetVerticalSymbol(), menu_ptr->GetItemSymbols()->GetHorizontalSymbol(), menu_ptr->GetItemSymbols()->GetUpperLeftSymbol(),
		menu_ptr->GetItemSymbols()->GetUpperRightSymbol(), menu_ptr->GetItemSymbols()->GetBottomLeftSymbol(), menu_ptr->GetItemSymbols()->GetBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuItemInactiveColor());
	cursor_ptr->CursorMovement(PointCoord((camera_ptr->GetUpperLeft().Get_x() * 2 + camera_ptr->GetWidthAddition()) / 2, (camera_ptr->GetUpperLeft().Get_y() * 2 + camera_ptr->GetHeightAddition()) / 2));
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
		ConstructionDescriptor* cd_ptr = preliminary_ptr->GetDescriptor();
		Construction* realObject_ptr = menu_ptr->GetManager(cd_ptr)->CreateConstruction(cursor_ptr->GetCursorConsoleLocation(), draw_ptr, allObjects_ptr);
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
	int menuLeftX = menu_ptr->GetUpperLeft().Get_x();
	int menuRightX = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition();
	Construction* preliminary_ptr = menu_ptr->CreatePreliminaryObject(cursor_ptr->GetCursorConsoleLocation(), allObjects_ptr);
	draw_ptr->DrawRectangle(menuLeftX + 2, preliminary_ptr->GetDescriptor()->GetManagerLocation().Get_y(), menuRightX - 2,
		preliminary_ptr->GetDescriptor()->GetManagerLocation().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1,
		menu_ptr->GetItemSymbols()->GetVerticalSymbol(), menu_ptr->GetItemSymbols()->GetHorizontalSymbol(), menu_ptr->GetItemSymbols()->GetUpperLeftSymbol(),
		menu_ptr->GetItemSymbols()->GetUpperRightSymbol(), menu_ptr->GetItemSymbols()->GetBottomLeftSymbol(), menu_ptr->GetItemSymbols()->GetBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuItemUnderConstructionColor());
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
	return;
}
void GameManagement::EscKey_PlayingField()
{
	if (allObjects_ptr->GetPreliminaryElement() != nullptr)
	{
		int leftX = menu_ptr->GetUpperLeft().Get_x() + 2;
		int topY = allObjects_ptr->GetPreliminaryElement()->GetDescriptor()->GetManagerLocation().Get_y();
		int rightX = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition() - 2;
		int bottomY = topY + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1;
		if (!menu_ptr->GetHideMenuStatus())
		{
			draw_ptr->DrawRectangle(leftX, topY, rightX, bottomY, menu_ptr->GetItemSymbols()->GetVerticalSymbol(), menu_ptr->GetItemSymbols()->GetHorizontalSymbol(),
				menu_ptr->GetItemSymbols()->GetUpperLeftSymbol(), menu_ptr->GetItemSymbols()->GetUpperRightSymbol(), menu_ptr->GetItemSymbols()->GetBottomLeftSymbol(),
				menu_ptr->GetItemSymbols()->GetBottomRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemInactiveColor());
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
	cursor_ptr->CursorMovement(menu_ptr->MenuNavigation(cursor_ptr->GetCursorConsoleLocation(), IconsPosition::UPPER));
}
void GameManagement::DownArrow_Menu()
{
	cursor_ptr->CursorMovement(menu_ptr->MenuNavigation(cursor_ptr->GetCursorConsoleLocation(), IconsPosition::LOWER));
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
		case 105: { I_Key_OutOfInfoPanel(); return; }
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
		case 105: { I_Key_OutOfInfoPanel(); return; }
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
			//case 75: { LeftArrow_InfoPanel(); return; }
			//case 77: { RightArrow_InfoPanel(); return; }
			//case 105: { I_key_InfoPanel(); return; }
		default: return;
		}
	}
}