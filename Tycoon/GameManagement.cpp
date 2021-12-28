#include "GameManagement.h"
///////////////GameManagement Class///////////////
void GameManagement::DisplayMenu()
{
	menu_ptr->ShowMenuBorders();
	PointCoord underConstruction(0, 0);
	if (allObjects_ptr->GetLastElementFlag())
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
	int leftX = camera_ptr->GetUpperLeft().Get_x();
	int topY = camera_ptr->GetUpperLeft().Get_y();
	int rightX = leftX + camera_ptr->GetWidthAddition();
	int bottomY = topY + camera_ptr->GetHeightAddition();
	cursor_ptr->CursorMovement(PointCoord((leftX + rightX) / 2, (topY + bottomY) / 2));
	if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
	{
		draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
	}
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
	cursor_ptr->CursorMovement(PointCoord((cameraLeftX + cameraRightX) / 2, (cameraTopY + cameraBottomY) / 2));
}
void GameManagement::GameProcess()
{
	char ch = 'a';
	Direction shiftDirection;
	while (true)
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
		shiftDirection = camera_ptr->CursorBordersCheck(cursor_ptr, field_ptr);
		if (shiftDirection != Direction::None)
		{
			allObjects_ptr->EraseObjects(camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(),
				camera_ptr->GetUpperLeft().Get_y(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
			cursor_ptr->CursorShift(shiftDirection);
			if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr) && !allObjects_ptr->GetLastElementFlag())
			{
				draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
			}
			allObjects_ptr->ShiftAllObjects(shiftDirection);
			field_ptr->Shift(shiftDirection);
			DisplayAllObjects();
			DisplayPlayingField();
		}
		wait(100);
	}
}
void GameManagement::DisplayAllObjects()
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraRightX = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int cameraBottomY = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	buildings_ptr->DisplayBuildings(cameraLeftX, cameraRightX, cameraTopY, cameraBottomY);
	roads_ptr->DisplayRoads(cameraLeftX, cameraRightX, cameraTopY, cameraBottomY);
	visitors_ptr->DisplayVisitors();
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
void GameManagement::BuildingConnectedToRoadCheck()
{
	vector<PointCoord> potentialRoads = buildings_ptr->GetPotentialRoadCoords();
	vector<PointCoord> connectedRoads = roads_ptr->RoadConnectedToEntranceCheck(potentialRoads);
	buildings_ptr->SetRoadConnectionStatus(connectedRoads);
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
	allObjects_ptr->ShiftAllObjects(menu_ptr->ChangeMenuSide(), menu_ptr->GetWidthAddition());
	EraseScreen();
	DisplayCamera();
	DisplayMenu();
	DisplayAllObjects();
	DisplayPlayingField();
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
	if (!allObjects_ptr->GetLastElementFlag())
	{
		if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
		{
			draw_ptr->ErasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
		}
	}
	else
	{
		IngameObject* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
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
		allObjects_ptr->ErasePreliminaryElement();
		allObjects_ptr->SetLastElementFlag(0);
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
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	if (allObjects_ptr->GetLastElementFlag() && !allObjects_ptr->ObjectImposition(allObjects_ptr->GetPreliminaryElement(), camera_ptr, field_ptr))
	{
		ConstructionDescriptor* cd_ptr = allObjects_ptr->GetPreliminaryElement()->GetDescriptor();
		Construction* realObject_ptr = menu_ptr->GetManager(cd_ptr)->CreateConstruction(cursor_ptr->GetCursorConsoleLocation(), draw_ptr);
		int position = allObjects_ptr->GetElementsQuantity();
		allObjects_ptr->AddObject(realObject_ptr, position);
		int mask = 0;
		if (Building* real_ptr = dynamic_cast<Building*>(realObject_ptr))
		{
			buildings_ptr->AddBuilding(real_ptr);
		}
		if (Road* real_ptr = dynamic_cast<Road*>(realObject_ptr))
		{
			roads_ptr->AddRoad(real_ptr);
			mask = roads_ptr->RoadEnvironment(real_ptr->GetUpperLeft());
			roads_ptr->RedrawNeibourRoads(real_ptr->GetUpperLeft());
		}
		realObject_ptr->DrawObject(mask);
		cursor_ptr->CursorMovement(PointCoord(realObject_ptr->GetUpperLeft().Get_x() + realObject_ptr->GetWidthAddition() + 1, realObject_ptr->GetUpperLeft().Get_y() + realObject_ptr->GetHeightAddition()));
		allObjects_ptr->GetPreliminaryElement()->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
		if (!allObjects_ptr->ObjectImposition(allObjects_ptr->GetPreliminaryElement(), camera_ptr, field_ptr))
		{
			if (Road* real_ptr = dynamic_cast<Road*>(allObjects_ptr->GetPreliminaryElement()))
			{
				mask = roads_ptr->RoadEnvironment(real_ptr->GetUpperLeft());
				roads_ptr->RedrawNeibourRoads(real_ptr->GetUpperLeft());
			}
			allObjects_ptr->GetPreliminaryElement()->DrawObject(mask);
			cursor_ptr->CursorMovement(allObjects_ptr->GetPreliminaryElement()->GetUpperLeft());
		}
	}
}
void GameManagement::EnterKey_Menu()
{
	int MenuLeftX = menu_ptr->GetUpperLeft().Get_x();
	int MenuRightX = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition();
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	Construction* preliminary_ptr = menu_ptr->CreatePreliminaryObject(cursor_ptr->GetCursorConsoleLocation());
	allObjects_ptr->AddPreliminaryElement(preliminary_ptr);
	draw_ptr->DrawRectangle(MenuLeftX + 2, preliminary_ptr->GetDescriptor()->GetManagerLocation().Get_y(), MenuRightX - 2,
		preliminary_ptr->GetDescriptor()->GetManagerLocation().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1,
		menu_ptr->GetItemSymbols()->GetVerticalSymbol(), menu_ptr->GetItemSymbols()->GetHorizontalSymbol(), menu_ptr->GetItemSymbols()->GetUpperLeftSymbol(),
		menu_ptr->GetItemSymbols()->GetUpperRightSymbol(), menu_ptr->GetItemSymbols()->GetBottomLeftSymbol(), menu_ptr->GetItemSymbols()->GetBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuItemUnderConstructionColor());
	cursor_ptr->CursorMovement(PointCoord((camera_ptr->GetUpperLeft().Get_x() * 2 + camera_ptr->GetWidthAddition()) / 2, (camera_ptr->GetUpperLeft().Get_y() * 2 + camera_ptr->GetHeightAddition()) / 2));
	preliminary_ptr->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
	bool objectIntersection = allObjects_ptr->ObjectImposition(preliminary_ptr, camera_ptr, field_ptr);
	int mask = 0;
	if (!objectIntersection)
	{
		if (Road* real_ptr = dynamic_cast<Road*>(preliminary_ptr))
		{
			mask = roads_ptr->RoadEnvironment(real_ptr->GetUpperLeft());
			roads_ptr->RedrawNeibourRoads(real_ptr->GetUpperLeft());
		}
		preliminary_ptr->DrawObject(mask);
		cursor_ptr->CursorMovement(preliminary_ptr->GetUpperLeft());
	}
	return;
}
void GameManagement::EscKey_PlayingField()
{
	if (!allObjects_ptr->GetLastElementFlag())
	{
		return;
	}
	else
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
		allObjects_ptr->ErasePreliminaryElement();
		allObjects_ptr->SetLastElementFlag(0);
		cursor_ptr->CursorMovement(PointCoord((camera_ptr->GetUpperLeft().Get_x() * 2 + camera_ptr->GetWidthAddition()) / 2, (camera_ptr->GetUpperLeft().Get_y() * 2 + camera_ptr->GetHeightAddition()) / 2));
		if (!allObjects_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr))
		{
			draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
		}
	}
}
void GameManagement::Arrows_PlayingField(PointCoord cursorDestination)
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	int mask = 0;
	if (allObjects_ptr->GetLastElementFlag())
	{
		IngameObject* io_ptr = allObjects_ptr->GetPreliminaryElement();
		if (!allObjects_ptr->ObjectImposition(io_ptr, camera_ptr, field_ptr))
		{
			draw_ptr->EraseConstruction(io_ptr->GetUpperLeft().Get_x(), io_ptr->GetUpperLeft().Get_y(), io_ptr->GetUpperLeft().Get_x() + io_ptr->GetWidthAddition(),
				io_ptr->GetUpperLeft().Get_y() + io_ptr->GetHeightAddition());
			roads_ptr->RedrawNeibourRoads(cursor_ptr->GetCursorConsoleLocation());
		}
		cursor_ptr->CursorMovement(cursorDestination);
		io_ptr->SetUpperLeft(cursorDestination);
		if (!allObjects_ptr->ObjectImposition(io_ptr, camera_ptr, field_ptr))
		{
			if (Road* real_ptr = dynamic_cast<Road*>(io_ptr))
			{
				mask = roads_ptr->RoadEnvironment(io_ptr->GetUpperLeft());
				roads_ptr->RedrawNeibourRoads(io_ptr->GetUpperLeft());
			}
			io_ptr->DrawObject(mask);
			cursor_ptr->CursorMovement(io_ptr->GetUpperLeft());
		}
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
			draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
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
	MenuStatus menuPosition = menu_ptr->GetCurrentSide();
	if ((cursor_ptr->GetCursorConsoleLocation().Get_x() < (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) && menuPosition == MenuStatus::RIGHT) ||
		(cursor_ptr->GetCursorConsoleLocation().Get_x() > camera_ptr->GetUpperLeft().Get_x() && menuPosition == MenuStatus::LEFT))	//this condition checks if the cursor is in the playing field or in the menu
	{
		switch (key)
		{
		case 104: { H_Key(); return; }	//'h' key hide or display Menu
		case 115: { S_Key(); return; }	//'s' key change placement of menu from right to left and vice versa
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
	else		//when the cursor is in the side menu
	{
		switch (key)
		{
		case 104: { H_Key(); return; }	//'h' key hide or display Menu
		case 115: { S_Key(); return; }	//'s' key change placement of menu from right to left and vice versa
		case 72: { UpArrow_Menu(); return; }	//up arrow
		case 80: { DownArrow_Menu(); return; }	//down arrow
		case 9: { TabKey_Menu(); return; }	//tab key moves cursor to the center of playing field
		case 13: { EnterKey_Menu(); return; }	//enter key chooses building to create
		default: return;
		}
	}
}