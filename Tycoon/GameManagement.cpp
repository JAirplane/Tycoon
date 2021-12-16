#include "Map.h"
///////////////GameManagement Class///////////////
void GameManagement::DisplayMenuBorders()
{
	int left_x = camera_ptr->GetUpperLeft().Get_x();
	int top_y = camera_ptr->GetUpperLeft().Get_y();
	int right_x = left_x + camera_ptr->GetWidthAddition();
	int bot_y = top_y + camera_ptr->GetHeightAddition();
	Menu_ptr->ShowMenuBorders();
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void GameManagement::DisplayIcons()
{
	int left_x = camera_ptr->GetUpperLeft().Get_x();
	int top_y = camera_ptr->GetUpperLeft().Get_y();
	int right_x = left_x + camera_ptr->GetWidthAddition();
	int bot_y = top_y + camera_ptr->GetHeightAddition();
	Menu_ptr->ShowIcons();
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void GameManagement::DisplayMenu()
{
	DisplayMenuBorders();
	DisplayIcons();
	color cl = ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor();
	draw_ptr->drawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), cl);
}
void GameManagement::HideMenu()
{
	Menu_ptr->EraseMenu();
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void GameManagement::eraseScreen()
{
	set_color(color::cBLACK);
	system("cls");
}
void GameManagement::DisplayPlayingField()
{
	int left_x = camera_ptr->GetUpperLeft().Get_x();
	int top_y = camera_ptr->GetUpperLeft().Get_y();
	int right_x = left_x + camera_ptr->GetWidthAddition();
	int bot_y = top_y + camera_ptr->GetHeightAddition();
	color foreground = ConstructionOptions::GetAllOptions()->GetPlayingFieldColor();
	draw_ptr->drawRectangle(left_x, top_y, right_x, bot_y, foreground);
	cursor_ptr->CursorMovement(PointCoord((left_x + right_x) / 2, (top_y + bot_y) / 2));
}
void GameManagement::GameProcess()
{
	char ch = 'a';
	Direction SD;
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
		SD = camera_ptr->CursorBordersCheck(cursor_ptr);
		if (SD != Direction::None)
		{
			AllObjects_ptr->EraseObjects();
			Shift(SD);
			DisplayAllObjects();
		}
		wait(100);
	}
}
void GameManagement::Shift(Direction SD)
{
	cursor_ptr->CursorShift(SD);
	if (!AllObjects_ptr->IsPartOfExistingObject(cursor_ptr->GetCursorConsoleLocation()) && !AllObjects_ptr->getLastElementFlag())
	{
		draw_ptr->drawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
	}
	list<IngameObject*>::const_iterator iter;
	for (iter = (AllObjects_ptr->getAllObjects()).begin(); iter != (AllObjects_ptr->getAllObjects()).end(); iter++)
	{
		PointCoord ul = (*iter)->GetUpperLeft();
		switch (SD)
		{
		case Direction::Right:
		{
			ul.set_coord(ul.Get_x() + 1, ul.Get_y());
			break;
		}
		case Direction::Down:
		{
			ul.set_coord(ul.Get_x(), ul.Get_y() + 1);
			break;
		}
		case Direction::Left:
		{
			ul.set_coord(ul.Get_x() - 1, ul.Get_y());
			break;
		}
		case Direction::Up:
		{
			ul.set_coord(ul.Get_x(), ul.Get_y() - 1);
			break;
		}
		}
		(*iter)->SetUpperLeft(ul);
	}
}
void GameManagement::Shift(Direction SD, int shiftvalue)
{
	list<IngameObject*>::iterator iter;
	for (iter = (AllObjects_ptr->getAllObjects()).begin(); iter != (AllObjects_ptr->getAllObjects()).end(); iter++)
	{
		PointCoord ul = (*iter)->GetUpperLeft();
		switch (SD)
		{
		case Direction::Right:
		{
			ul.set_coord(ul.Get_x() + shiftvalue, ul.Get_y());
			break;
		}
		case Direction::Left:
		{
			ul.set_coord(ul.Get_x() - shiftvalue, ul.Get_y());
			break;
		}
		}
		(*iter)->SetUpperLeft(ul);
	}
}
void GameManagement::DisplayAllObjects()
{
	buildings_ptr->Displaybuildings();
	Roads_ptr->DisplayRoads();
	Visitors_ptr->DisplayVisitors();
}
void GameManagement::PreliminaryBuildingAdd(IngameObject* preliminary_ptr)
{
	AllObjects_ptr->addObject(preliminary_ptr);
	AllObjects_ptr->setLastElementFlag(1);
}
void GameManagement::CreateManagers()
{
	int x_coord = (Menu_ptr->GetUpperLeft().Get_x() * 2 + Menu_ptr->GetWidthAddition()) / 2;
	int y_coord = Menu_ptr->GetUpperLeft().Get_y() + 1;
	PointCoord FirstManagerupperLeft(x_coord, y_coord);
	ConstructionDescriptor* BuildingDesc = new BuildingDescriptor(FirstManagerupperLeft, ConstructionOptions::GetAllOptions()->GetIceCreamShopCost(), ConstructionOptions::GetAllOptions()->GetIceCreamShopDescription(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopIconSymbol(), ConstructionOptions::GetAllOptions()->GetIceCreamShopForegroundColor(), ConstructionOptions::GetAllOptions()->GetIceCreamShopBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopSymbol(), ConstructionOptions::GetAllOptions()->GetIceCreamShopExpences(),
		ConstructionOptions::GetAllOptions()->GetIceCreamShopHeightAdd(), ConstructionOptions::GetAllOptions()->GetIceCreamShopWidthAdd());
	ConstructionManager* icecreammanager_ptr = new BuildingManager(FirstManagerupperLeft, cursor_ptr, BuildingDesc);
	PointCoord NextManagerUL(x_coord, y_coord + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight());
	ConstructionDescriptor* RoadDesc = new ConstructionDescriptor(NextManagerUL, ConstructionOptions::GetAllOptions()->GetRoadCost(), ConstructionOptions::GetAllOptions()->GetRoadDescription(),
		ConstructionOptions::GetAllOptions()->GetRoadIconSymbol(), ConstructionOptions::GetAllOptions()->GetRoadForegroundColor(), ConstructionOptions::GetAllOptions()->GetRoadBackgroundColor());
	ConstructionManager* roadmanager_ptr = new RoadManager(NextManagerUL, cursor_ptr, RoadDesc);
	Menu_ptr->addManager(icecreammanager_ptr);
	Menu_ptr->addManager(roadmanager_ptr);
}
void GameManagement::BuildingConnectedToRoadCheck()
{
	vector<PointCoord> potentialroads = buildings_ptr->getPotentialRoadCoords();
	vector<PointCoord> connectedroads = Roads_ptr->RoadConnectedToEntranceCheck(potentialroads);
	buildings_ptr->setRoadConnectionStatus(connectedroads);
}
void GameManagement::H_Key()
{
	if (!Menu_ptr->getHideMenuStatus())
	{
		HideMenu();
		Menu_ptr->setHideMenuStatus(1);
	}
	else
	{
		DisplayMenu();
		Menu_ptr->setHideMenuStatus(0);
	}
	return;
}
void GameManagement::S_Key()
{
	Shift(Menu_ptr->ChangeMenuSide(), Menu_ptr->GetWidthAddition());
	eraseScreen();
	DisplayPlayingField();
	DisplayMenu();
	DisplayAllObjects();
}
void GameManagement::Tab_Key_Playingfield()
{
	int camera_left_x = camera_ptr->GetUpperLeft().Get_x();
	int camera_right_x = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int camera_top_y = camera_ptr->GetUpperLeft().Get_y();
	int camera_borrom_y = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	if (!AllObjects_ptr->IsPartOfExistingObject(cursor_ptr->GetCursorConsoleLocation())
	{
		draw_ptr->erasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
	}
	int left_x = Menu_ptr->GetUpperLeft().Get_x();
		int right_x = Menu_ptr->GetUpperLeft().Get_x() + Menu_ptr->GetWidthAddition();
		if (AllObjects_ptr->getLastElementFlag())
		{
			IngameObject* preliminary_ptr = AllObjects_ptr->getPreliminaryElement();
				AllObjects_ptr->setLastElementFlag(0);
				if (!AllObjects_ptr->IsPartOfExistingObject(AllObjects_ptr->getPreliminaryElement(), camera_left_x, camera_right_x, camera_top_y, camera_borrom_y))
				{
					draw_ptr->EraseConstruction(preliminary_ptr->GetDescriptor()->GetUpperLeft().Get_x(), preliminary_ptr->GetDescriptor()->GetUpperLeft().Get_y(),
						preliminary_ptr->GetDescriptor()->GetUpperLeft().Get_x() + preliminary_ptr->GetDescriptor()->GetHeightAddition(),
						preliminary_ptr->GetDescriptor()->GetUpperLeft().Get_y() + preliminary_ptr->GetDescriptor()->GetWidthAddition());
				}
			draw_ptr->drawRectangle(left_x + 2, preliminary_ptr->GetDescriptor()->GetUpperLeft().Get_y(), right_x - 2,
				preliminary_ptr->GetDescriptor()->GetUpperLeft().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1, ConstructionOptions::GetAllOptions()->GetMenuBorderInactiveColor());	//draw external menu icon bordres
			AllObjects_ptr->ErasePreliminaryElement();
		}
	PointCoord UpperVisibleIcon = Menu_ptr->getNearestIconCoords(PointCoord(0, 0), IconsPosition::LOWER);
	draw_ptr->drawRectangle(left_x + 2, UpperVisibleIcon.Get_y(), right_x - 2, UpperVisibleIcon.Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1,
		ConstructionOptions::GetAllOptions()->GetMenuBorderActiveColor());	//draw external menu icon bordres
	cursor_ptr->CursorMovement(UpperVisibleIcon);
	return;
}
void GameManagement::Tab_Key_Menu()
{
	int Menu_left_x = Menu_ptr->GetUpperLeft().Get_x();
	int Menu_right_x = Menu_ptr->GetUpperLeft().Get_x() + Menu_ptr->GetWidthAddition();
	draw_ptr->drawRectangle(Menu_left_x + 2, cursor_ptr->GetCursorConsoleLocation().Get_y(), Menu_right_x - 2,
		cursor_ptr->GetCursorConsoleLocation().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1, ConstructionOptions::GetAllOptions()->GetMenuBorderInactiveColor());
	cursor_ptr->CursorMovement(PointCoord((camera_ptr->GetUpperLeft().Get_x() * 2 + camera_ptr->GetWidthAddition()) / 2, (camera_ptr->GetUpperLeft().Get_y() * 2 + camera_ptr->GetHeightAddition()) / 2));
	if (!AllObjects_ptr->IsPartOfExistingObject(cursor_ptr->GetCursorConsoleLocation())
	{
		draw_ptr->drawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
			cursor_ptr->setCursorConsoleLocation();
	}
	return;
}
void GameManagement::Enter_Key_PlayingField()
{
	int camera_left_x = camera_ptr->GetUpperLeft().Get_x();
		int camera_right_x = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
		int camera_top_y = camera_ptr->GetUpperLeft().Get_y();
	int camera_borrom_y = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	if (AllObjects_ptr->getLastElementFlag() && !AllObjects_ptr->IsPartOfExistingObject(AllObjects_ptr->getPreliminaryElement(), camera_left_x, camera_right_x, camera_top_y, camera_borrom_y))
	{
		ConstructionDescriptor* cd_ptr = AllObjects_ptr->getPreliminaryElement()->GetDescriptor();
		Construction* realobject_ptr = Menu_ptr->getManager(cd_ptr)->CreateConstruction(cursor_ptr->GetCursorConsoleLocation());
		int position = AllObjects_ptr->getAllObjects().size();
		AllObjects_ptr->addObject(realobject_ptr, position);
		if (Building* b_ptr = dynamic_cast<Building*>(realobject_ptr))
		{
			buildings_ptr->AddBuilding(b_ptr);
			draw_ptr->DrawConstruction(b_ptr->GetUpperLeft().Get_x(), b_ptr->GetUpperLeft().Get_y(), b_ptr->GetUpperLeft().Get_x() + b_ptr->GetWidthAddition(),
				b_ptr->GetUpperLeft().Get_y() + b_ptr->GetHeightAddition(), b_ptr->GetDescriptor()->GetBuildingSymbol(), b_ptr->GetDescriptor()->GetForegroundColor(), b_ptr->GetDescriptor()->GetBackgroundColor());
		}
		if (Road* r_ptr = dynamic_cast<Road*>(realobject_ptr))
		{
			Roads_ptr->addRoad(r_ptr);
			Roads_ptr->RedrawRoads(r_ptr);
		}
		cursor_ptr->setCursorConsoleLocation();
		AllObjects_ptr->getPreliminaryElement()->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
		if (!AllObjects_ptr->IsPartOfExistingObject(AllObjects_ptr->getPreliminaryElement(), camera_left_x, camera_right_x, camera_top_y, camera_borrom_y))
		{
			draw_ptr->DrawConstruction(AllObjects_ptr->getPreliminaryElement()->GetUpperLeft().Get_x(), AllObjects_ptr->getPreliminaryElement()->GetUpperLeft().Get_y(),
				AllObjects_ptr->getPreliminaryElement()->GetUpperLeft().Get_x() + AllObjects_ptr->getPreliminaryElement()->GetWidthAddition(),
				AllObjects_ptr->getPreliminaryElement()->GetUpperLeft().Get_y() + AllObjects_ptr->getPreliminaryElement()->GetHeightAddition(),
				cd_ptr->GetBuildingSymbol(), cd_ptr->GetForegroundColor(), cd_ptr->GetBackgroundColor());
			cursor_ptr->CursorMovement(AllObjects_ptr->getPreliminaryElement()->GetUpperLeft());
		}
	}
	return;
}
void GameManagement::Enter_Key_Menu()
{
	int Menu_left_x = Menu_ptr->GetUpperLeft().Get_x();
	int Menu_right_x = Menu_ptr->GetUpperLeft().Get_x() + Menu_ptr->GetWidthAddition();
	int camera_left_x = camera_ptr->GetUpperLeft().Get_x();
	int camera_right_x = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
	int camera_top_y = camera_ptr->GetUpperLeft().Get_y();
	int camera_borrom_y = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
	PreliminaryBuildingAdd(Menu_ptr->CreatePreliminaryObject(cursor_ptr->GetCursorConsoleLocation()));
	draw_ptr->drawRectangle(Menu_left_x + 2, cursor_ptr->GetCursorConsoleLocation().Get_y(), Menu_right_x - 2,
		cursor_ptr->GetCursorConsoleLocation().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1, ConstructionOptions::GetAllOptions()->GetMenuBorderUnderConstructionColor());
	cursor_ptr->CursorMovement(PointCoord((camera_ptr->GetUpperLeft().Get_x() * 2 + camera_ptr->GetWidthAddition()) / 2, (camera_ptr->GetUpperLeft().Get_y() * 2 + camera_ptr->GetHeightAddition()) / 2));
	AllObjects_ptr->getPreliminaryElement()->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
	bool objectintersection = AllObjects_ptr->IsPartOfExistingObject(AllObjects_ptr->getPreliminaryElement(), camera_left_x, camera_right_x, camera_top_y, camera_borrom_y);
	if (!objectintersection)
	{
		IngameObject* io_ptr = AllObjects_ptr->getPreliminaryElement();
		draw_ptr->DrawConstruction(io_ptr->GetUpperLeft().Get_x(), io_ptr->GetUpperLeft().Get_y(), io_ptr->GetUpperLeft().Get_x() + io_ptr->GetWidthAddition(), io_ptr->GetUpperLeft().Get_y() + io_ptr->GetHeightAddition(),
			io_ptr->GetDescriptor()->GetBuildingSymbol(), io_ptr->GetDescriptor()->GetForegroundColor(), io_ptr->GetDescriptor()->GetBackgroundColor());
		cursor_ptr->CursorMovement(io_ptr->GetUpperLeft());
	}
	return;
}
void GameManagement::Esc_Key_PlayingField()
{
	if (!AllObjects_ptr->getLastElementFlag())
	{
		return;
	}
	else
	{
		int left_x = Menu_ptr->GetUpperLeft().Get_x() + 2;
		int up_y = AllObjects_ptr->getPreliminaryElement()->GetDescriptor()->GetUpperLeft().Get_y();
		int right_x = Menu_ptr->GetUpperLeft().Get_x() + Menu_ptr->GetWidthAddition() - 2;
		int bot_y = up_y + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1;
		draw_ptr->drawRectangle(left_x, up_y, right_x, bot_y, color::cYELLOW);
		draw_ptr->EraseConstruction(AllObjects_ptr->getPreliminaryElement()->GetUpperLeft().Get_x(), AllObjects_ptr->getPreliminaryElement()->GetUpperLeft().Get_y(),
			AllObjects_ptr->getPreliminaryElement()->GetUpperLeft().Get_x() + AllObjects_ptr->getPreliminaryElement()->GetWidthAddition(),
			AllObjects_ptr->getPreliminaryElement()->GetUpperLeft().Get_y() + AllObjects_ptr->getPreliminaryElement()->GetHeightAddition());
		AllObjects_ptr->ErasePreliminaryElement();
		AllObjects_ptr->setLastElementFlag(0);
		cursor_ptr->CursorMovement(PointCoord((camera_ptr->GetUpperLeft().Get_x() * 2 + camera_ptr->GetWidthAddition()) / 2, (camera_ptr->GetUpperLeft().Get_y() * 2 + camera_ptr->GetHeightAddition()) / 2));
		if (!AllObjects_ptr->IsPartOfExistingObject(cursor_ptr->GetCursorConsoleLocation()))
		{
			draw_ptr->drawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
		}
		else
		{
			return;
		}
	}
}
void GameManagement::Arrows_PlayingField(PointCoord cursordestination)
{
	if (AllObjects_ptr->getLastElementFlag())
	{
		IngameObject* io_ptr = AllObjects_ptr->getPreliminaryElement();
		int camera_left_x = camera_ptr->GetUpperLeft().Get_x();
		int camera_right_x = camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition();
		int camera_top_y = camera_ptr->GetUpperLeft().Get_y();
		int camera_bottom_y = camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition();
		if (!AllObjects_ptr->IsPartOfExistingObject(io_ptr, camera_left_x, camera_right_x, camera_top_y, camera_bottom_y))
		{
			draw_ptr->EraseConstruction(io_ptr->GetUpperLeft().Get_x(), io_ptr->GetUpperLeft().Get_y(), io_ptr->GetUpperLeft().Get_x() + io_ptr->GetWidthAddition(),
				io_ptr->GetUpperLeft().Get_y() + io_ptr->GetHeightAddition());
		}
		cursor_ptr->CursorMovement(cursordestination);
		io_ptr->SetUpperLeft(cursor_ptr->GetCursorConsoleLocation());
		if (!AllObjects_ptr->IsPartOfExistingObject(io_ptr, camera_left_x, camera_right_x, camera_top_y, camera_bottom_y))
		{
			draw_ptr->DrawConstruction(io_ptr->GetUpperLeft().Get_x(), io_ptr->GetUpperLeft().Get_y(), io_ptr->GetUpperLeft().Get_x() + io_ptr->GetWidthAddition(), io_ptr->GetUpperLeft().Get_y() + io_ptr->GetHeightAddition(),
				io_ptr->GetDescriptor()->GetBuildingSymbol(), io_ptr->GetDescriptor()->GetForegroundColor(), io_ptr->GetDescriptor()->GetBackgroundColor());
			cursor_ptr->CursorMovement(io_ptr->GetUpperLeft());
		}
	}
	else if (!AllObjects_ptr->IsPartOfExistingObject(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y())) && cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x() &&
		cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() && cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y() &&
		cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition())
	{
		draw_ptr->erasePixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y());
		cursor_ptr->CursorMovement(cursordestination);
		if (!AllObjects_ptr->IsPartOfExistingObject(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y())) && cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x()
			&& cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() && cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y()
			&& cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition())
		{
			draw_ptr->drawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
		}
	}
	else
	{
		cursor_ptr->CursorMovement(cursordestination);
		if (!AllObjects_ptr->IsPartOfExistingObject(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y())) && cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x()
			&& cursor_ptr->GetCursorConsoleLocation().Get_x() != camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition() && cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y()
			&& cursor_ptr->GetCursorConsoleLocation().Get_y() != camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition())
		{
			draw_ptr->drawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(), ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
		}
	}

	return;
}
void GameManagement::UpArrow_Menu()
{
	cursor_ptr->CursorMovement(Menu_ptr->MenuNavigation(cursor_ptr->GetCursorConsoleLocation(), IconsPosition::UPPER));
}
void GameManagement::DownArrow_Menu()
{
	cursor_ptr->CursorMovement(Menu_ptr->MenuNavigation(cursor_ptr->GetCursorConsoleLocation(), IconsPosition::LOWER));
}
void GameManagement::UserActions(int key)
{
	MenuStatus MenuPosition = Menu_ptr->getCurrentSide();
	if ((cursor_ptr->GetCursorConsoleLocation().Get_x() < (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) && MenuPosition == MenuStatus::RIGHT) ||
		(cursor_ptr->GetCursorConsoleLocation().Get_x() > camera_ptr->GetUpperLeft().Get_x() && MenuPosition == MenuStatus::LEFT))	//this condition checks if the cursor is in the playing field or in the menu
	{
		switch (key)
		{
		case 104: { H_Key(); return; }	//'h' key hide or display Menu
		case 115: { S_Key(); return; }	//'s' key change placement of menu from right to left and vice versa
		case 75: { Arrows_PlayingField(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x() - 1, cursor_ptr->GetCursorConsoleLocation().Get_y())); return; }	//left arrow 
		case 72: { Arrows_PlayingField(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y() - 1)); return; }	//up arrow 
		case 77: { Arrows_PlayingField(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x() + 1, cursor_ptr->GetCursorConsoleLocation().Get_y())); return; }	//right arrow 
		case 80: { Arrows_PlayingField(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y() + 1)); return; }	//down arrow 
		case 9: { Tab_Key_Playingfield(); return; }		//tab key moves cursor from the playing field to the upper visible icon from menu
		case 13: { Enter_Key_PlayingField(); return; }	//enter key builds construction, choosen from side menu
		case 27: { Esc_Key_PlayingField(); return; }	//esc prevents from keep build choosen construction (tab key too)
		default:
			return;
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
		case 9: { Tab_Key_Menu(); return; }	//tab key moves cursor to the center of playing field
		case 13: { Enter_Key_Menu(); return; }	//enter key chooses building to create
		default:
			return;
		}
	}
}