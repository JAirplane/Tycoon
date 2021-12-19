#include "GameManagement.h"
///////////////GameManagement Class///////////////
void GameManagement::DisplayMenuBorders()
{
	int leftX = camera_ptr->GetUpperLeft().Get_x();
	int topY = camera_ptr->GetUpperLeft().Get_y();
	int rightX = leftX + camera_ptr->GetWidthAddition();
	int bottomY = topY + camera_ptr->GetHeightAddition();
	menu_ptr->ShowMenuBorders();
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void GameManagement::DisplayIcons()
{
	int leftX = camera_ptr->GetUpperLeft().Get_x();
	int topY = camera_ptr->GetUpperLeft().Get_y();
	int rightX = leftX + camera_ptr->GetWidthAddition();
	int bottomY = topY + camera_ptr->GetHeightAddition();
	menu_ptr->ShowIcons();
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void GameManagement::DisplayMenu()
{
	DisplayMenuBorders();
	DisplayIcons();
	color cursorBackgroundColor = ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor();
	draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), cursorBackgroundColor);
}
void GameManagement::HideMenu()
{
	menu_ptr->EraseMenu();
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void GameManagement::EraseScreen()
{
	set_color(color::cBLACK);
	system("cls");
}
void GameManagement::DisplayPlayingField()
{
	int leftX = camera_ptr->GetUpperLeft().Get_x();
	int topY = camera_ptr->GetUpperLeft().Get_y();
	int rightX = leftX + camera_ptr->GetWidthAddition();
	int bottomY = topY + camera_ptr->GetHeightAddition();
	color foreground = ConstructionOptions::GetAllOptions()->GetPlayingFieldColor();
	draw_ptr->DrawRectangle(leftX, topY, rightX, bottomY, foreground);
	cursor_ptr->CursorMovement(PointCoord((leftX + rightX) / 2, (topY + bottomY) / 2));
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
		shiftDirection = camera_ptr->CursorBordersCheck(cursor_ptr);
		if (shiftDirection != Direction::None)
		{
			allObjects_ptr->EraseObjects(camera_ptr->GetUpperLeft().Get_x(), camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition(),
				camera_ptr->GetUpperLeft().Get_y(), camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition());
			Shift(shiftDirection);
			DisplayAllObjects();
		}
		wait(100);
	}
}
void GameManagement::Shift(Direction shiftDirection)
{
	cursor_ptr->CursorShift(shiftDirection);
	if (!allObjects_ptr->IsPartOfExistingObject(cursor_ptr->GetCursorConsoleLocation()) && !allObjects_ptr->GetLastElementFlag())
	{
		draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
	}
	list<IngameObject*>::const_iterator iter;
	for (iter = (allObjects_ptr->GetAllObjects()).begin(); iter != (allObjects_ptr->GetAllObjects()).end(); iter++)
	{
		PointCoord upperLeft = (*iter)->GetUpperLeft();
		switch (shiftDirection)
		{
		case Direction::Right:
		{
			upperLeft.SetCoord(upperLeft.Get_x() + 1, upperLeft.Get_y());
			break;
		}
		case Direction::Down:
		{
			upperLeft.SetCoord(upperLeft.Get_x(), upperLeft.Get_y() + 1);
			break;
		}
		case Direction::Left:
		{
			upperLeft.SetCoord(upperLeft.Get_x() - 1, upperLeft.Get_y());
			break;
		}
		case Direction::Up:
		{
			upperLeft.SetCoord(upperLeft.Get_x(), upperLeft.Get_y() - 1);
			break;
		}
		}
		(*iter)->SetUpperLeft(upperLeft);
	}
}
void GameManagement::Shift(Direction shiftDirection, int shiftValue)
{
	list<IngameObject*>::iterator iter;
	for (iter = (allObjects_ptr->GetAllObjects()).begin(); iter != (allObjects_ptr->GetAllObjects()).end(); iter++)
	{
		PointCoord upperLeft = (*iter)->GetUpperLeft();
		switch (shiftDirection)
		{
		case Direction::Right:
		{
			upperLeft.SetCoord(upperLeft.Get_x() + shiftValue, upperLeft.Get_y());
			break;
		}
		case Direction::Left:
		{
			upperLeft.SetCoord(upperLeft.Get_x() - shiftValue, upperLeft.Get_y());
			break;
		}
		}
		(*iter)->SetUpperLeft(upperLeft);
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
void GameManagement::PreliminaryBuildingAdd(IngameObject* preliminary_ptr)
{
	allObjects_ptr->AddObject(preliminary_ptr);
	allObjects_ptr->SetLastElementFlag(1);
}
void GameManagement::CreateManagers()
{
	int xCoord = (menu_ptr->GetUpperLeft().Get_x() * 2 + menu_ptr->GetWidthAddition()) / 2;
	int yCoord = menu_ptr->GetUpperLeft().Get_y() + 1;
	PointCoord firstManagerUpperLeft(xCoord, yCoord);
	ConstructionDescriptor* buildingDesc = new buildingDescriptor(firstManagerUpperLeft, ConstructionOptions::GetAllOptions()->GetIceCreamShopointost(), ConstructionOptions::GetAllOptions()->GetIceCreamShopDescription(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopIconSymbol(), ConstructionOptions::GetAllOptions()->GetIceCreamShopForegroundColor(), ConstructionOptions::GetAllOptions()->GetIceCreamShopBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopSymbol(), ConstructionOptions::GetAllOptions()->GetIceCreamShopExpences(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopheightAdd(), ConstructionOptions::GetAllOptions()->GetIceCreamShopwidthAdd());
	ConstructionManager* icecreammanager_ptr = new BuildingManager(firstManagerUpperLeft, cursor_ptr, buildingDesc);
	PointCoord nextManagerupperLeft(xCoord, yCoord + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight());
	ConstructionDescriptor* RoadDesc = new ConstructionDescriptor(nextManagerupperLeft, ConstructionOptions::GetAllOptions()->GetRoadCost(), ConstructionOptions::GetAllOptions()->GetRoadDescription(),
		ConstructionOptions::GetAllOptions()->GetRoadIconSymbol(), ConstructionOptions::GetAllOptions()->GetRoadForegroundColor(), ConstructionOptions::GetAllOptions()->GetRoadBackgroundColor());
	ConstructionManager* roadmanager_ptr = new RoadManager(nextManagerupperLeft, cursor_ptr, RoadDesc);
	menu_ptr->AddManager(icecreammanager_ptr);
	menu_ptr->AddManager(roadmanager_ptr);
}
void GameManagement::BuildingconnectedToRoadCheck()
{
	vector<PointCoord> potentialroads = buildings_ptr->GetPotentialRoadCoords();
	vector<PointCoord> connectedRoads = roads_ptr->RoadConnectedToEntranceCheck(potentialroads);
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
	Shift(menu_ptr->ChangeMenuSide(), menu_ptr->GetWidthAddition());
	EraseScreen();
	DisplayPlayingField();
	DisplayMenu();
	DisplayAllObjects();
}
void GameManagement::TabKey_Playingfield()
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	if (menu_ptr->GetHideMenuStatus())
	{
		DisplayMenu();
		menu_ptr->SetHideMenuStatus(0);
	}
	if (!allObjects_ptr->IsPartOfExistingObject(cursor_ptr->GetCursorConsoleLocation()))
	{
		draw_ptr->ErasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
	}
	int leftX = menu_ptr->GetUpperLeft().Get_x();
	int rightX = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition();
	if (allObjects_ptr->GetLastElementFlag())
	{
		IngameObject* preliminary_ptr = allObjects_ptr->GetPreliminaryElement();
		if (!allObjects_ptr->IsPartOfExistingObject(preliminary_ptr, cameraLeftX, cameraRightX, cameraTopY, cameraBottomY))
		{
			draw_ptr->EraseConstruction(preliminary_ptr->GetUpperLeft().Get_x(), preliminary_ptr->GetUpperLeft().Get_y(),
				preliminary_ptr->GetUpperLeft().Get_x() + preliminary_ptr->GetHeightAddition(),
				preliminary_ptr->GetUpperLeft().Get_y() + preliminary_ptr->GetWidthAddition());
		}
		draw_ptr->DrawRectangle(leftX + 2, preliminary_ptr->GetDescriptor()->GetUpperLeft().Get_y(), rightX - 2,
			preliminary_ptr->GetDescriptor()->GetUpperLeft().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1, ConstructionOptions::GetAllOptions()->GetMenuBorderInactiveColor());	//draw external menu icon bordres
		allObjects_ptr->ErasePreliminaryElement();
		allObjects_ptr->SetLastElementFlag(0);
	}
	PointCoord upperVisibleIcon = menu_ptr->GetNearestIconCoords(PointCoord(0, 0), IconsPosition::LOWER);
	draw_ptr->DrawRectangle(leftX + 2, upperVisibleIcon.Get_y(), rightX - 2, upperVisibleIcon.Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1,
		ConstructionOptions::GetAllOptions()->GetMenuBorderActiveColor());	//draw external menu icon bordres
	cursor_ptr->CursorMovement(upperVisibleIcon);
	return;
}
void GameManagement::TabKey_Menu()
{
	int MenupperLefteftX = menu_ptr->GetUpperLeft().Get_x();
	int MenuRightX = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition();
	draw_ptr->DrawRectangle(MenupperLefteftX + 2, cursor_ptr->GetCursorConsoleLocation().Get_y(), MenuRightX - 2,
		cursor_ptr->GetCursorConsoleLocation().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1, ConstructionOptions::GetAllOptions()->GetMenuBorderInactiveColor());
	cursor_ptr->CursorMovement(PointCoord((camera_ptr->GetUpperLeft().Get_x() * 2 + camera_ptr->GetWidthAddition()) / 2, (camera_ptr->GetUpperLeft().Get_y() * 2 + camera_ptr->GetHeightAddition()) / 2));
	if (!allObjects_ptr->IsPartOfExistingObject(cursor_ptr->GetCursorConsoleLocation()))
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
	if (allObjects_ptr->GetLastElementFlag() && !allObjects_ptr->IsPartOfExistingObject(allObjects_ptr->GetPreliminaryElement(), cameraLeftX, cameraRightX, cameraTopY, cameraBottomY))
	{
		ConstructionDescriptor* cd_ptr = allObjects_ptr->GetPreliminaryElement()->GetDescriptor();
		Construction* realObject_ptr = menu_ptr->GetManager(cd_ptr)->CreateConstruction(cursor_ptr->GetCursorConsoleLocation());
		int position = allObjects_ptr->GetAllObjects().size();
		allObjects_ptr->AddObject(realObject_ptr, position);
		if (Building* b_ptr = dynamic_cast<Building*>(realObject_ptr))
		{
			buildings_ptr->AddBuilding(b_ptr);
			draw_ptr->DrawConstruction(b_ptr->GetUpperLeft().Get_x(), b_ptr->GetUpperLeft().Get_y(), b_ptr->GetUpperLeft().Get_x() + b_ptr->GetWidthAddition(),
				b_ptr->GetUpperLeft().Get_y() + b_ptr->GetHeightAddition(), b_ptr->GetDescriptor()->GetConstructionSymbol(), b_ptr->GetDescriptor()->GetForegroundColor(), b_ptr->GetDescriptor()->GetBackgroundColor());
		}
		if (Road* r_ptr = dynamic_cast<Road*>(realObject_ptr))
		{
			roads_ptr->AddRoad(r_ptr);
			roads_ptr->RedrawrRoads(r_ptr);
		}
		cursor_ptr->SetCursorConsoleLocation();
		allObjects_ptr->GetPreliminaryElement()->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
		if (!allObjects_ptr->IsPartOfExistingObject(allObjects_ptr->GetPreliminaryElement(), cameraLeftX, cameraRightX, cameraTopY, cameraBottomY))
		{
			draw_ptr->DrawConstruction(allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_x(), allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_y(),
				allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_x() + allObjects_ptr->GetPreliminaryElement()->GetWidthAddition(),
				allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_y() + allObjects_ptr->GetPreliminaryElement()->GetHeightAddition(),
				cd_ptr->GetConstructionSymbol(), cd_ptr->GetForegroundColor(), cd_ptr->GetBackgroundColor());
			cursor_ptr->CursorMovement(allObjects_ptr->GetPreliminaryElement()->GetUpperLeft());
		}
	}
	return;
}
void GameManagement::EnterKey_Menu()
{
	int MenupperLefteftX = menu_ptr->GetUpperLeft().Get_x();
	int MenuRightX = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition();
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraRightX = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraBottomY = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	PreliminaryBuildingAdd(menu_ptr->CreatePreliminaryObject(cursor_ptr->GetCursorConsoleLocation()));
	draw_ptr->DrawRectangle(MenupperLefteftX + 2, cursor_ptr->GetCursorConsoleLocation().Get_y(), MenuRightX - 2,
		cursor_ptr->GetCursorConsoleLocation().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1, ConstructionOptions::GetAllOptions()->GetMenuBorderUnderConstructionColor());
	cursor_ptr->CursorMovement(PointCoord((camera_ptr->GetUpperLeft().Get_x() * 2 + camera_ptr->GetWidthAddition()) / 2, (camera_ptr->GetUpperLeft().Get_y() * 2 + camera_ptr->GetHeightAddition()) / 2));
	allObjects_ptr->GetPreliminaryElement()->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
	bool objectIntersection = allObjects_ptr->IsPartOfExistingObject(allObjects_ptr->GetPreliminaryElement(), cameraLeftX, cameraRightX, cameraTopY, cameraBottomY);
	if (!objectIntersection)
	{
		IngameObject* io_ptr = allObjects_ptr->GetPreliminaryElement();
		draw_ptr->DrawConstruction(io_ptr->GetUpperLeft().Get_x(), io_ptr->GetUpperLeft().Get_y(), io_ptr->GetUpperLeft().Get_x() + io_ptr->GetWidthAddition(), io_ptr->GetUpperLeft().Get_y() + io_ptr->GetHeightAddition(),
			io_ptr->GetDescriptor()->GetConstructionSymbol(), io_ptr->GetDescriptor()->GetForegroundColor(), io_ptr->GetDescriptor()->GetBackgroundColor());
		cursor_ptr->CursorMovement(io_ptr->GetUpperLeft());
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
		int topY = allObjects_ptr->GetPreliminaryElement()->GetDescriptor()->GetUpperLeft().Get_y();
		int rightX = menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition() - 2;
		int bottomY = topY + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1;
		draw_ptr->DrawRectangle(leftX, topY, rightX, bottomY, color::cYELLOW);
		draw_ptr->EraseConstruction(allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_x(), allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_y(),
			allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_x() + allObjects_ptr->GetPreliminaryElement()->GetWidthAddition(),
			allObjects_ptr->GetPreliminaryElement()->GetUpperLeft().Get_y() + allObjects_ptr->GetPreliminaryElement()->GetHeightAddition());
		allObjects_ptr->ErasePreliminaryElement();
		allObjects_ptr->SetLastElementFlag(0);
		cursor_ptr->CursorMovement(PointCoord((camera_ptr->GetUpperLeft().Get_x() * 2 + camera_ptr->GetWidthAddition()) / 2, (camera_ptr->GetUpperLeft().Get_y() * 2 + camera_ptr->GetHeightAddition()) / 2));
		if (!allObjects_ptr->IsPartOfExistingObject(cursor_ptr->GetCursorConsoleLocation()))
		{
			draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
		}
		else
		{
			return;
		}
	}
}
void GameManagement::Arrows_PlayingField(PointCoord cursorDestination)
{
	if (allObjects_ptr->GetLastElementFlag())
	{
		IngameObject* io_ptr = allObjects_ptr->GetPreliminaryElement();
		int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
		int cameraRightX = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
		int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
		int cameraBottomY = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
		if (!allObjects_ptr->IsPartOfExistingObject(io_ptr, cameraLeftX, cameraRightX, cameraTopY, cameraBottomY))
		{
			draw_ptr->EraseConstruction(io_ptr->GetUpperLeft().Get_x(), io_ptr->GetUpperLeft().Get_y(), io_ptr->GetUpperLeft().Get_x() + io_ptr->GetWidthAddition(),
				io_ptr->GetUpperLeft().Get_y() + io_ptr->GetHeightAddition());
		}
		cursor_ptr->CursorMovement(cursorDestination);
		io_ptr->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
		if (!allObjects_ptr->IsPartOfExistingObject(io_ptr, cameraLeftX, cameraRightX, cameraTopY, cameraBottomY))
		{
			draw_ptr->DrawConstruction(io_ptr->GetUpperLeft().Get_x(), io_ptr->GetUpperLeft().Get_y(), io_ptr->GetUpperLeft().Get_x() + io_ptr->GetWidthAddition(), io_ptr->GetUpperLeft().Get_y() + io_ptr->GetHeightAddition(),
				io_ptr->GetDescriptor()->GetConstructionSymbol(), io_ptr->GetDescriptor()->GetForegroundColor(), io_ptr->GetDescriptor()->GetBackgroundColor());
			cursor_ptr->CursorMovement(io_ptr->GetUpperLeft());
		}
	}
	else if (!allObjects_ptr->IsPartOfExistingObject(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y())) && cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x() &&
		cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() && cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y() &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition())
	{
		draw_ptr->ErasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
		cursor_ptr->CursorMovement(cursorDestination);
		if (!allObjects_ptr->IsPartOfExistingObject(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y())) && cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x()
			&& cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() && cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y()
			&& cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition())
		{
			draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
		}
	}
	else
	{
		cursor_ptr->CursorMovement(cursorDestination);
		if (!allObjects_ptr->IsPartOfExistingObject(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y())) && cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x()
			&& cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() && cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y()
			&& cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition())
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