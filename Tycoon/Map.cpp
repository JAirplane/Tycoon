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
	Draw_ptr->drawCursorPixel(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y(), color::cYELLOW);
}
void WorldMap::HideSideMenu()
{
	SideMenu_ptr->EraseMenu();
	C_ptr->CursorMovement(PointCoord((VM_ptr->getUpperLeft().get_x() + VM_ptr->getUpperLeft().get_x() + VM_ptr->getWidthAddition()) / 2,
		(VM_ptr->getUpperLeft().get_y() + VM_ptr->getUpperLeft().get_y() + VM_ptr->getHeightAddition()) / 2));
}
void WorldMap::eraseScreen()
{
	set_color(color::cBLACK, color::cBLACK);
	system("cls");
}
void WorldMap::DisplayPlayingField()
{
	int left_x = VM_ptr->getUpperLeft().get_x();
	int top_y = VM_ptr->getUpperLeft().get_y();
	int right_x = left_x + VM_ptr->getWidthAddition();
	int bot_y = top_y + VM_ptr->getHeightAddition();
	Draw_ptr->drawRectangle(left_x, top_y, right_x, bot_y, color::cBLUE);
	C_ptr->setCursorConsoleLocation();
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
	Draw_ptr->drawCursorPixel(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y(), ConstructionOptions::getAllOptions()->getCursorBackgroundColor());
	C_ptr->setIntersectionFlag(false);
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
	int y_coord = SideMenu_ptr->getUpperLeft().get_y() + 1;
	PointCoord FirstManagerUpperLeft(x_coord, y_coord);
	ConstructionDescriptor* BuildingDesc = new BuildingDescriptor(FirstManagerUpperLeft, ConstructionOptions::getAllOptions()->getIceCreamShopCost(), ConstructionOptions::getAllOptions()->getIceCreamShopDescription(),
		ConstructionOptions::getAllOptions()->getIceCreamShopIconSymbol(), ConstructionOptions::getAllOptions()->getIceCreamShopForegroundColor(), ConstructionOptions::getAllOptions()->getIceCreamShopBackgroundColor(),
		ConstructionOptions::getAllOptions()->getIceCreamShopSymbol(), ConstructionOptions::getAllOptions()->getIceCreamShopExpences(),
		ConstructionOptions::getAllOptions()->getIceCreamShopHeightAdd(), ConstructionOptions::getAllOptions()->getIceCreamShopWidthAdd());
	ConstructionManager* icecreammanager_ptr = new BuildingManager(FirstManagerUpperLeft, C_ptr, BuildingDesc);
	PointCoord NextManagerUL(x_coord, y_coord + ConstructionOptions::getAllOptions()->getMenuElementBordersHeight());
	ConstructionDescriptor* RoadDesc = new ConstructionDescriptor(NextManagerUL, ConstructionOptions::getAllOptions()->getRoadCost(), ConstructionOptions::getAllOptions()->getRoadDescription(),
		ConstructionOptions::getAllOptions()->getRoadIconSymbol(), ConstructionOptions::getAllOptions()->getRoadForegroundColor(), ConstructionOptions::getAllOptions()->getRoadBackgroundColor());
	ConstructionManager* roadmanager_ptr = new RoadManager(NextManagerUL, C_ptr, RoadDesc);
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
	if (!C_ptr->getIntersectionFlag())
	{
		Draw_ptr->erasePixel(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y());
	}
	if (AllObjects_ptr->getLastElementFlag())
	{
		PointCoord MenuUL = SideMenu_ptr->getUpperLeft();
		PointCoord MenuBR(SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition(), SideMenu_ptr->getUpperLeft().get_y() + SideMenu_ptr->getHeightAddition());
		AllObjects_ptr->setLastElementFlag(0);
		IngameObject* preliminary_ptr = AllObjects_ptr->getPreliminaryElement();
		Draw_ptr->eraseConstruction(preliminary_ptr->getDescriptor()->getUpperLeft().get_x(), preliminary_ptr->getDescriptor()->getUpperLeft().get_y(),
			preliminary_ptr->getDescriptor()->getUpperLeft().get_x() + preliminary_ptr->getDescriptor()->getHeightAddition(),
			preliminary_ptr->getDescriptor()->getUpperLeft().get_y() + preliminary_ptr->getDescriptor()->getWidthAddition());
		Draw_ptr->drawRectangle(MenuUL.get_x() + 2, preliminary_ptr->getDescriptor()->getUpperLeft().get_y(), MenuBR.get_x() - 2,
			preliminary_ptr->getDescriptor()->getUpperLeft().get_y() + ConstructionOptions::getAllOptions()->getMenuElementBordersHeight() - 1, color::cYELLOW);	//draw external menu icon bordres
		AllObjects_ptr->ErasePreliminaryElement();
	}
	PointCoord UpperVisibleIcon = SideMenu_ptr->getNearestIconCoords(PointCoord(0, 0), IconsPosition::LOWER);
	Draw_ptr->drawRectangle(SideMenu_ptr->getUpperLeft().get_x() + 2, UpperVisibleIcon.get_y(), SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition() - 2,
		UpperVisibleIcon.get_y() + ConstructionOptions::getAllOptions()->getMenuElementBordersHeight() - 1, color::cGREEN);	//draw external menu icon bordres
	C_ptr->CursorMovement(UpperVisibleIcon);
	return;
}
void WorldMap::Tab_Key_SideMenu()
{
	PointCoord MenuUL = SideMenu_ptr->getUpperLeft();
	PointCoord MenuBR(SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition(), SideMenu_ptr->getUpperLeft().get_y() + SideMenu_ptr->getHeightAddition());
	Draw_ptr->drawRectangle(MenuUL.get_x() + 2, C_ptr->getCursorConsoleLocation().get_y(), MenuBR.get_x() - 2,
		C_ptr->getCursorConsoleLocation().get_y() + ConstructionOptions::getAllOptions()->getMenuElementBordersHeight() - 1, color::cYELLOW);
	C_ptr->CursorMovement(PointCoord((VM_ptr->getUpperLeft().get_x() * 2 + VM_ptr->getWidthAddition()) / 2, (VM_ptr->getUpperLeft().get_y() * 2 + VM_ptr->getHeightAddition()) / 2));
	C_ptr->setIntersectionFlag(AllObjects_ptr->IsPartOfExistingObject(C_ptr->getCursorConsoleLocation()));
	if (!C_ptr->getIntersectionFlag())
	{
		Draw_ptr->drawCursorPixel(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y(), color::cYELLOW);
	}
	return;
}
void WorldMap::Enter_Key_PlayingField()
{
	if (AllObjects_ptr->getLastElementFlag() && !AllObjects_ptr->IsPartOfExistingObject(AllObjects_ptr->getPreliminaryElement()))
	{
		ConstructionDescriptor* cd_ptr = AllObjects_ptr->getPreliminaryElement()->getDescriptor();
		Construction* realobject_ptr = SideMenu_ptr->getManager(cd_ptr)->CreateConstruction(C_ptr->getCursorConsoleLocation());
		int position = AllObjects_ptr->getAllObjects().size();
		AllObjects_ptr->addObject(realobject_ptr, position);
		if (Building* b_ptr = dynamic_cast<Building*>(realobject_ptr))
		{
			Buildings_ptr->addBuilding(b_ptr);
			Draw_ptr->drawConstruction(b_ptr->getUpperLeft().get_x(), b_ptr->getUpperLeft().get_y(), b_ptr->getUpperLeft().get_x() + b_ptr->getWidthAddition(),
				b_ptr->getUpperLeft().get_y() + b_ptr->getHeightAddition(), b_ptr->getDescriptor()->getBuildingSymbol(), color::cYELLOW, color::cDARK_CYAN);
		}
		if (Road* r_ptr = dynamic_cast<Road*>(realobject_ptr))
		{
			Roads_ptr->addRoad(r_ptr);
			Roads_ptr->RedrawRoads(r_ptr);
		}
		C_ptr->setCursorConsoleLocation();
		AllObjects_ptr->getPreliminaryElement()->setUpperLeft(C_ptr->getCursorConsoleLocation());
		if (!AllObjects_ptr->IsPartOfExistingObject(AllObjects_ptr->getPreliminaryElement()))
		{
			Draw_ptr->drawConstruction(AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_x(), AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_y(), 
				AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_x() + AllObjects_ptr->getPreliminaryElement()->getWidthAddition(), 
				AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_y() + AllObjects_ptr->getPreliminaryElement()->getHeightAddition(),
				cd_ptr->getBuildingSymbol(), cd_ptr->getForegroundColor(), cd_ptr->getBackgroundColor());
			C_ptr->CursorMovement(AllObjects_ptr->getPreliminaryElement()->getUpperLeft());
		}
	}
	return;
}
void WorldMap::Enter_Key_SideMenu()
{
	PointCoord MenuUL = SideMenu_ptr->getUpperLeft();
	PointCoord MenuBR(SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition(), SideMenu_ptr->getUpperLeft().get_y() + SideMenu_ptr->getHeightAddition());
	PreliminaryBuildingAdd(SideMenu_ptr->CreatePreliminaryObject(C_ptr->getCursorConsoleLocation()));
	Draw_ptr->drawRectangle(MenuUL.get_x() + 2, C_ptr->getCursorConsoleLocation().get_y(), MenuBR.get_x() - 2, C_ptr->getCursorConsoleLocation().get_y() + ConstructionOptions::getAllOptions()->getMenuElementBordersHeight() - 1, color::cRED);
	C_ptr->CursorMovement(PointCoord((VM_ptr->getUpperLeft().get_x() * 2 + VM_ptr->getWidthAddition()) / 2, (VM_ptr->getUpperLeft().get_y() * 2 + VM_ptr->getHeightAddition()) / 2));
	AllObjects_ptr->getPreliminaryElement()->setUpperLeft(C_ptr->getCursorConsoleLocation());
	bool objectintersection = AllObjects_ptr->IsPartOfExistingObject(AllObjects_ptr->getPreliminaryElement());
	if (!objectintersection)
	{
		IngameObject* io_ptr = AllObjects_ptr->getPreliminaryElement();
		Draw_ptr->drawConstruction(io_ptr->getUpperLeft().get_x(), io_ptr->getUpperLeft().get_y(), io_ptr->getUpperLeft().get_x() + io_ptr->getWidthAddition(), io_ptr->getUpperLeft().get_y() + io_ptr->getHeightAddition(),
			io_ptr->getDescriptor()->getBuildingSymbol(), io_ptr->getDescriptor()->getForegroundColor(), io_ptr->getDescriptor()->getBackgroundColor());
		C_ptr->CursorMovement(io_ptr->getUpperLeft());
	}
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
		int up_y = AllObjects_ptr->getPreliminaryElement()->getDescriptor()->getUpperLeft().get_y();
		int right_x = SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition() - 2;
		int bot_y = up_y + ConstructionOptions::getAllOptions()->getMenuElementBordersHeight() - 1;
		AllObjects_ptr->setLastElementFlag(0);
		Draw_ptr->drawRectangle(left_x, up_y, right_x, bot_y, color::cYELLOW);
		Draw_ptr->eraseConstruction(AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_x(), AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_y(),
			AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_x() + AllObjects_ptr->getPreliminaryElement()->getWidthAddition(),
			AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_y() + AllObjects_ptr->getPreliminaryElement()->getHeightAddition());
		AllObjects_ptr->ErasePreliminaryElement();
		C_ptr->CursorMovement(PointCoord((VM_ptr->getUpperLeft().get_x() * 2 + VM_ptr->getWidthAddition()) / 2, (VM_ptr->getUpperLeft().get_y() * 2 + VM_ptr->getHeightAddition()) / 2));
		if (!AllObjects_ptr->IsPartOfExistingObject(C_ptr->getCursorConsoleLocation()))
		{
			Draw_ptr->drawCursorPixel(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y(), ConstructionOptions::getAllOptions()->getCursorBackgroundColor());
		}
		else
		{
			C_ptr->setIntersectionFlag(true);
		}
	}
}
void WorldMap::Arrows_PlayingField(PointCoord cursordestination)
{
	if (!C_ptr->getIntersectionFlag())
	{
		Draw_ptr->erasePixel(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y());
	}
	if (AllObjects_ptr->getLastElementFlag())
	{
		Draw_ptr->eraseConstruction(AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_x(), AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_y(),
			AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_x() + AllObjects_ptr->getPreliminaryElement()->getWidthAddition(),
			AllObjects_ptr->getPreliminaryElement()->getUpperLeft().get_y() + AllObjects_ptr->getPreliminaryElement()->getHeightAddition());
	}
	C_ptr->CursorMovement(cursordestination);
	if (AllObjects_ptr->getLastElementFlag())
	{
		if (!AllObjects_ptr->IsPartOfExistingObject(AllObjects_ptr->getPreliminaryElement()) && C_ptr->getCursorConsoleLocation().get_x() != VM_ptr->getUpperLeft().get_x()
			&& C_ptr->getCursorConsoleLocation().get_x() != VM_ptr->getUpperLeft().get_x() + VM_ptr->getWidthAddition() && C_ptr->getCursorConsoleLocation().get_y() != VM_ptr->getUpperLeft().get_y()
			&& C_ptr->getCursorConsoleLocation().get_y() != VM_ptr->getUpperLeft().get_y() + VM_ptr->getHeightAddition());
		{
			AllObjects_ptr->getPreliminaryElement()->setUpperLeft(C_ptr->getCursorConsoleLocation());
			IngameObject* io_ptr = AllObjects_ptr->getPreliminaryElement();
			Draw_ptr->drawConstruction(io_ptr->getUpperLeft().get_x(), io_ptr->getUpperLeft().get_y(), io_ptr->getUpperLeft().get_x() + io_ptr->getWidthAddition(), io_ptr->getUpperLeft().get_y() + io_ptr->getHeightAddition(),
				io_ptr->getDescriptor()->getBuildingSymbol(), io_ptr->getDescriptor()->getForegroundColor(), io_ptr->getDescriptor()->getBackgroundColor());
			C_ptr->CursorMovement(io_ptr->getUpperLeft());
		}
	}
	else if (!AllObjects_ptr->IsPartOfExistingObject(PointCoord(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y())) && C_ptr->getCursorConsoleLocation().get_x() != VM_ptr->getUpperLeft().get_x()
		&& C_ptr->getCursorConsoleLocation().get_x() != VM_ptr->getUpperLeft().get_x() + VM_ptr->getWidthAddition() && C_ptr->getCursorConsoleLocation().get_y() != VM_ptr->getUpperLeft().get_y()
		&& C_ptr->getCursorConsoleLocation().get_y() != VM_ptr->getUpperLeft().get_y() + VM_ptr->getHeightAddition())
	{
		C_ptr->setIntersectionFlag(false);
		Draw_ptr->drawCursorPixel(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y(), color::cYELLOW);
	}
	else
	{
		C_ptr->setIntersectionFlag(true);
	}
	return;
}
void WorldMap::UpArrow_SideMenu()
{
	C_ptr->CursorMovement(SideMenu_ptr->MenuNavigation(C_ptr->getCursorConsoleLocation(), IconsPosition::UPPER));
}
void WorldMap::DownArrow_SideMenu()
{
	C_ptr->CursorMovement(SideMenu_ptr->MenuNavigation(C_ptr->getCursorConsoleLocation(), IconsPosition::LOWER));
}
void WorldMap::UserActions(int key)
{
	SideMenuStatus MenuPosition = SideMenu_ptr->getCurrentSide();
	if ((C_ptr->getCursorConsoleLocation().get_x() < (VM_ptr->getUpperLeft().get_x() + VM_ptr->getWidthAddition()) && MenuPosition == SideMenuStatus::RIGHT) ||
		(C_ptr->getCursorConsoleLocation().get_x() > VM_ptr->getUpperLeft().get_x() && MenuPosition == SideMenuStatus::LEFT))	//this condition checks if the cursor is in the playing field or in the menu
	{
		switch (key)
		{
		case 104: { H_Key(); return; }	//'h' key hide or display SideMenu
		case 115: { S_Key(); return; }	//'s' key change placement of menu from right to left and vice versa
		case 75: { Arrows_PlayingField(PointCoord(C_ptr->getCursorConsoleLocation().get_x() - 1, C_ptr->getCursorConsoleLocation().get_y())); return; }	//left arrow 
		case 72: { Arrows_PlayingField(PointCoord(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y() - 1)); return; }	//up arrow 
		case 77: { Arrows_PlayingField(PointCoord(C_ptr->getCursorConsoleLocation().get_x() + 1, C_ptr->getCursorConsoleLocation().get_y())); return; }	//right arrow 
		case 80: { Arrows_PlayingField(PointCoord(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y() + 1)); return; }	//down arrow 
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
		case 104: { H_Key(); return; }	//'h' key hide or display SideMenu
		case 115: { S_Key(); return; }	//'s' key change placement of menu from right to left and vice versa
		case 72: { UpArrow_SideMenu(); return; }	//up arrow
		case 80: { DownArrow_SideMenu(); return; }	//down arrow
		case 9: { Tab_Key_SideMenu(); return; }	//tab key moves cursor to the center of playing field
		case 13: { Enter_Key_SideMenu(); return; }	//enter key chooses building to create
		default:
			return;
		}
	}
}