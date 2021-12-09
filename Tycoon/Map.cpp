#include "Map.h"
///////////////WorldMap Class///////////////
void WorldMap::DisplaySideMenuBorders()
{
	int left_x = VM_ptr->getUpperLeft().get_x();
	int top_y = VM_ptr->getUpperLeft().get_y();
	int right_x = left_x + VM_ptr->getWidthAddition();
	int bot_y = top_y + VM_ptr->getHeightAddition();
	SideMenu_ptr->ShowMenuBorders();
	C_ptr->CursorMovement(PointCoord((left_x + right_x) / 2, (top_y + bot_y) / 2));
}
void WorldMap::DisplayIcons()
{
	int left_x = VM_ptr->getUpperLeft().get_x();
	int top_y = VM_ptr->getUpperLeft().get_y();
	int right_x = left_x + VM_ptr->getWidthAddition();
	int bot_y = top_y + VM_ptr->getHeightAddition();
	SideMenu_ptr->ShowIcons();
	C_ptr->CursorMovement(PointCoord((left_x + right_x) / 2, (top_y + bot_y) / 2));
}
void WorldMap::DisplaySideMenu()
{
	DisplaySideMenuBorders();
	DisplayIcons();
}
void WorldMap::HideSideMenu()
{
	SideMenu_ptr->EraseMenu();
	C_ptr->CursorMovement(PointCoord((VM_ptr->getUpperLeft().get_x() + VM_ptr->getUpperLeft().get_x() + VM_ptr->getWidthAddition()) / 2,
		(VM_ptr->getUpperLeft().get_y() + VM_ptr->getUpperLeft().get_y() + VM_ptr->getHeightAddition()) / 2));
}
void WorldMap::eraseScreen()
{
	system("cls");
}
void WorldMap::DisplayPlayingField()
{
	int left_x = VM_ptr->getUpperLeft().get_x();
	int top_y = VM_ptr->getUpperLeft().get_y();
	int right_x = left_x + VM_ptr->getWidthAddition();
	int bot_y = top_y + VM_ptr->getHeightAddition();
	Draw_ptr->drawPlayingField(left_x, top_y, right_x, bot_y);
}
void WorldMap::GameProcess()
{
	char ch = 'a';
	Direction SD;
	while (true)
	{
		SD = VM_ptr->CursorBordersCheck(C_ptr);
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
		if (SD != Direction::None)
		{
			eraseAllObjects();
			Shift(SD);
			DisplayAllObjects();
		}
		wait(100);
	}
}
void WorldMap::Shift(Direction SD)
{
	C_ptr->CursorShift(SD);
	list<IngameObject*>::const_iterator iter;
	for (iter = (AllObjects_ptr->getAllObjects()).begin(); iter != (AllObjects_ptr->getAllObjects()).end(); iter++)
	{
		PointCoord ul = (*iter)->getUpperLeft();
		switch (SD)
		{
		case Direction::Right:
		{
			ul.set_coord(ul.get_x() + 1, ul.get_y());
			break;
		}
		case Direction::Down:
		{
			ul.set_coord(ul.get_x(), ul.get_y() + 1);
			break;
		}
		case Direction::Left:
		{
			ul.set_coord(ul.get_x() - 1, ul.get_y());
			break;
		}
		case Direction::Up:
		{
			ul.set_coord(ul.get_x(), ul.get_y() - 1);
			break;
		}
		}
		(*iter)->setUpperLeft(ul);
	}
}
void WorldMap::Shift(Direction SD, int shiftvalue)
{
	C_ptr->CursorShift(SD, shiftvalue);
	list<IngameObject*>::iterator iter;
	for (iter = (AllObjects_ptr->getAllObjects()).begin(); iter != (AllObjects_ptr->getAllObjects()).end(); iter++)
	{
		PointCoord ul = (*iter)->getUpperLeft();
		switch (SD)
		{
		case Direction::Right:
		{
			ul.set_coord(ul.get_x() + shiftvalue, ul.get_y());
			break;
		}
		case Direction::Left:
		{
			ul.set_coord(ul.get_x() - shiftvalue, ul.get_y());
			break;
		}
		}
		(*iter)->setUpperLeft(ul);
	}
}
void WorldMap::DisplayAllObjects()
{
	Buildings_ptr->DisplayBuildings();
	Roads_ptr->DisplayRoads();
	Visitors_ptr->DisplayVisitors();
}
void WorldMap::eraseAllObjects()
{
	Buildings_ptr->EraseBuildings();
	Roads_ptr->EraseRoads();
	Visitors_ptr->EraseVisitors();
}
void WorldMap::PreliminaryBuildingAdd(IngameObject* preliminary_ptr)
{
	AllObjects_ptr->addObject(preliminary_ptr);
	AllObjects_ptr->setLastElementFlag(1);
}
void WorldMap::CreateManagers()
{
	int x_coord = (SideMenu_ptr->getUpperLeft().get_x() * 2 + SideMenu_ptr->getWidthAddition()) / 2;
	int y_coord = SideMenu_ptr->getUpperLeft().get_y() + 4;
	PointCoord FirstManagerUpperLeft(x_coord, y_coord);
	ConstructionManager* icecreammanager_ptr = new BuildingManager(FirstManagerUpperLeft, C_ptr, ConstructionOptions::getAllOptions()->getIceCreamShopCost(), ConstructionOptions::getAllOptions()->getIceCreamShopDescription(),
		ConstructionOptions::getAllOptions()->getIceCreamShopIconSymbol(), ConstructionOptions::getAllOptions()->getIceCreamShopExpences(), ConstructionOptions::getAllOptions()->getIceCreamShopSymbol(),
		ConstructionOptions::getAllOptions()->getIceCreamShopHeightAdd(), ConstructionOptions::getAllOptions()->getIceCreamShopWidthAdd());
	PointCoord ManagerUL(x_coord, y_coord + ConstructionOptions::getAllOptions()->getMenuElementBordersHeight());
	ConstructionManager* roadmanager_ptr = new RoadManager(ManagerUL, C_ptr, ConstructionOptions::getAllOptions()->getRoadCost(), ConstructionOptions::getAllOptions()->getRoadDescription(),
		ConstructionOptions::getAllOptions()->getRoadIconSymbol());
	SideMenu_ptr->addManager(icecreammanager_ptr);
	SideMenu_ptr->addManager(roadmanager_ptr);
}
void WorldMap::BuildingConnectedToRoadCheck()
{
	vector<PointCoord> potentialroads = Buildings_ptr->getPotentialRoadCoords();
	vector<PointCoord> connectedroads = Roads_ptr->RoadConnectedToEntranceCheck(potentialroads);
	Buildings_ptr->setRoadConnectionStatus(connectedroads);
}
void WorldMap::H_Key()
{
	if (!SideMenu_ptr->getHideMenuStatus())
	{
		HideSideMenu();
		SideMenu_ptr->setHideMenuStatus(1);
	}
	else
	{
		DisplaySideMenu();
		SideMenu_ptr->setHideMenuStatus(0);
	}
	return;
}
void WorldMap::S_Key()
{
	Shift(SideMenu_ptr->ChangeMenuSide(), SideMenu_ptr->getWidthAddition());
	eraseScreen();
	DisplayPlayingField();
	DisplaySideMenu();
	DisplayAllObjects();
}
void WorldMap::Tab_Key_Playingfield()
{
	if (AllObjects_ptr->getLastElementFlag())
	{
		PointCoord MenuUL = SideMenu_ptr->getUpperLeft();
		PointCoord MenuBR(SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition(), SideMenu_ptr->getUpperLeft().get_y() + SideMenu_ptr->getHeightAddition());
		AllObjects_ptr->setLastElementFlag(0);
		IngameObject* preliminary_ptr = AllObjects_ptr->getPreliminaryElement();
		Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, preliminary_ptr->getManager()->getUpperLeft().get_y() - 3, MenuBR.get_x() - 2, preliminary_ptr->getManager()->getUpperLeft().get_y() + 2, color::cYELLOW);
		AllObjects_ptr->ErasePreliminaryElement();
	}
	PointCoord UpperVisibleIcon = SideMenu_ptr->getNearestIconCoords(PointCoord(0, 0), IconsPosition::LOWER);
	C_ptr->CursorMovement(UpperVisibleIcon);
	Draw_ptr->drawIconBorders(SideMenu_ptr->getUpperLeft().get_x() + 2, UpperVisibleIcon.get_y() - 3, SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition() - 2, UpperVisibleIcon.get_y() + 2, color::cGREEN);
	return;
}
void WorldMap::Enter_Key_PlayingField()
{
	if (AllObjects_ptr->getLastElementFlag())
	{
		Construction* realobject_ptr = AllObjects_ptr->getPreliminaryElement()->getManager()->CreateConstruction(C_ptr->getCursorConsoleLocation());
		int position = AllObjects_ptr->getAllObjects().size();
		AllObjects_ptr->addObject(realobject_ptr, position);
		if (Building* b_ptr = dynamic_cast<Building*>(realobject_ptr))
		{
			Buildings_ptr->addBuilding(realobject_ptr);
			Draw_ptr->drawBuilding(realobject_ptr->getUpperLeft().get_x(), realobject_ptr->getUpperLeft().get_y(), realobject_ptr->getUpperLeft().get_x() + realobject_ptr->getWidthAddition(),
				realobject_ptr->getUpperLeft().get_y() + realobject_ptr->getHeightAddition(), realobject_ptr->getManager()->getBuildingSymbol());
		}
		if (Road* b_ptr = dynamic_cast<Road*>(realobject_ptr))
		{
			Roads_ptr->addRoad(realobject_ptr);
			int roadmask = Roads_ptr->RoadEnvironment(realobject_ptr->getUpperLeft());
			char roadsymbol = realobject_ptr->SetRoadSymbol(roadmask);
			Draw_ptr->drawRoad(realobject_ptr->getUpperLeft().get_x(), realobject_ptr->getUpperLeft().get_y(), roadsymbol);
		}
	}
	return;
}
void WorldMap::Enter_Key_SideMenu()
{
	PointCoord MenuUL = SideMenu_ptr->getUpperLeft();
	PointCoord MenuBR(SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition(), SideMenu_ptr->getUpperLeft().get_y() + SideMenu_ptr->getHeightAddition());
	PreliminaryBuildingAdd(SideMenu_ptr->CreatePreliminaryObject(C_ptr->getCursorConsoleLocation()));
	Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, C_ptr->getCursorConsoleLocation().get_y() - 3, MenuBR.get_x() - 2, C_ptr->getCursorConsoleLocation().get_y() + 2, color::cRED);
	C_ptr->CursorMovement(PointCoord((VM_ptr->getUpperLeft().get_x() * 2 + VM_ptr->getWidthAddition()) / 2, (VM_ptr->getUpperLeft().get_y() * 2 + VM_ptr->getHeightAddition()) / 2));
	return;
}
void WorldMap::Esc_Key_PlayingField()
{
	if (!AllObjects_ptr->getLastElementFlag())
	{
		return;
	}
	else
	{
		int left_x = SideMenu_ptr->getUpperLeft().get_x() + 2;
		int up_y = AllObjects_ptr->getPreliminaryElement()->getManager()->getUpperLeft().get_y() - 3;
		int right_x = SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition() - 2;
		int bot_y = up_y + ConstructionOptions::getAllOptions()->getMenuElementBordersHeight() - 1;
		AllObjects_ptr->setLastElementFlag(0);
		Draw_ptr->drawIconBorders(left_x, up_y, right_x, bot_y, color::cYELLOW);
		AllObjects_ptr->ErasePreliminaryElement();
		C_ptr->CursorMovement(PointCoord((VM_ptr->getUpperLeft().get_x() * 2 + VM_ptr->getWidthAddition()) / 2, (VM_ptr->getUpperLeft().get_y() * 2 + VM_ptr->getHeightAddition()) / 2));
	}

}
void WorldMap::UserActions(int key)
{
	SideMenuStatus MenuPosition = SideMenu_ptr->getCurrentSide();
	if ((C_ptr->getCursorConsoleLocation().get_x() < (VM_ptr->getUpperLeft().get_x() + VM_ptr->getWidthAddition()) && MenuPosition == SideMenuStatus::RIGHT) ||	//this condition checks if the cursor is in the playing field or in the menu
		(C_ptr->getCursorConsoleLocation().get_x() > VM_ptr->getUpperLeft().get_x() && MenuPosition == SideMenuStatus::LEFT))
	{
		switch (key)
		{
		case 104: { H_Key(); return; }	//'h' key hide or display SideMenu
		case 115: { S_Key(); return; }	//'s' key change placement of menu from right to left and vice versa
		case 75: { C_ptr->CursorMovement(PointCoord(C_ptr->getCursorConsoleLocation().get_x() - 1, C_ptr->getCursorConsoleLocation().get_y())); return; }	//left arrow 
		case 72: { C_ptr->CursorMovement(PointCoord(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y() - 1)); return; }	//up arrow 
		case 77: { C_ptr->CursorMovement(PointCoord(C_ptr->getCursorConsoleLocation().get_x() + 1, C_ptr->getCursorConsoleLocation().get_y())); return; }	//right arrow 
		case 80: { C_ptr->CursorMovement(PointCoord(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y() + 1)); return; }	//down arrow 
		case 9: { Tab_Key_Playingfield(); return; }																											//tab key moves cursor from the playing field to the upper visible icon from menu
		case 13: { Enter_Key_PlayingField(); return; }																										//enter key builds construction, choosen from side menu
		case 27: { Esc_Key_PlayingField(); return; }																										//esc prevents from keep build choosen construction (tab key too)
		default:
			return;
		}
	}
	else		//when the cursor is in the side menu
	{
		switch (key)
		{
		case 104: { H_Key(); return; }	//'h' key hide or display SideMenu
		case 115: { S_Key(); return; }	//'s' key change placement of menu from right to left and vice versa
		case 72: {C_ptr->CursorMovement(SideMenu_ptr->MenuNavigation(C_ptr->getCursorConsoleLocation(), IconsPosition::UPPER)); return;	}				//up arrow
		case 80: { C_ptr->CursorMovement(SideMenu_ptr->MenuNavigation(C_ptr->getCursorConsoleLocation(), IconsPosition::LOWER)); return; }				//down arrow
		case 9:
		{
			PointCoord MenuUL = SideMenu_ptr->getUpperLeft();
			PointCoord MenuBR(SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition(), SideMenu_ptr->getUpperLeft().get_y() + SideMenu_ptr->getHeightAddition());
			Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, C_ptr->getCursorConsoleLocation().get_y() - 3, MenuBR.get_x() - 2, C_ptr->getCursorConsoleLocation().get_y() + 2, color::cYELLOW);
			C_ptr->CursorMovement(PointCoord((VM_ptr->getUpperLeft().get_x() * 2 + VM_ptr->getWidthAddition()) / 2, (VM_ptr->getUpperLeft().get_y() * 2 + VM_ptr->getHeightAddition()) / 2));
			return;
		}	//tab key moves cursor to the center of playing field
		case 13: { Enter_Key_SideMenu(); return; }																										//enter key chooses building to create
		default:
			return;
		}
	}
}