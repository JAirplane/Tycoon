#include "Map.h"
///////////////WorldMap Class///////////////
void WorldMap::DisplaySideMenuBorders()
{
	int left_x = VM_ptr->getUpperLeftCorner().get_x();
	int top_y = VM_ptr->getUpperLeftCorner().get_y();
	int right_x = VM_ptr->getBottomRightCorner().get_x();
	int bot_y = VM_ptr->getBottomRightCorner().get_y();
	SideMenu_ptr->ShowMenuBorders();
	C_ptr->CursorMovement(PointCoord((left_x + right_x) / 2, (top_y + bot_y) / 2));
}
void WorldMap::DisplayIcons()
{
	int left_x = VM_ptr->getUpperLeftCorner().get_x();
	int top_y = VM_ptr->getUpperLeftCorner().get_y();
	int right_x = VM_ptr->getBottomRightCorner().get_x();
	int bot_y = VM_ptr->getBottomRightCorner().get_y();
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
	C_ptr->CursorMovement(PointCoord((VM_ptr->getUpperLeftCorner().get_x() + VM_ptr->getBottomRightCorner().get_x()) / 2,
		(VM_ptr->getUpperLeftCorner().get_y() + VM_ptr->getBottomRightCorner().get_y()) / 2));
}
void WorldMap::eraseScreen()
{
	system("cls");
}
void WorldMap::DisplayPlayingField()
{
	int left_x = VM_ptr->getUpperLeftCorner().get_x();
	int top_y = VM_ptr->getUpperLeftCorner().get_y();
	int right_x = VM_ptr->getBottomRightCorner().get_x();
	int bot_y = VM_ptr->getBottomRightCorner().get_y();
	Draw_ptr->drawPlayingField(left_x, top_y, right_x, bot_y);
}
void WorldMap::GameProcess()
{
	char ch = 'a';
	ShiftDirection SD;
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
		if (SD != ShiftDirection::Middle)
		{
			eraseAllObjects();
			Shift(SD);
			DisplayAllObjects();
		}
		wait(100);
	}
}
void WorldMap::Shift(ShiftDirection SD)
{
	C_ptr->CursorShift(SD);
	list< GlobalObject* >::iterator iter;
	for (iter = (AllObjects_ptr->getAllObjects()).begin(); iter != (AllObjects_ptr->getAllObjects()).end(); iter++)
	{
		PointCoord ul = (*iter)->getUpperLeft();
		PointCoord br = (*iter)->getBottomRight();
		switch (SD)
		{
		case ShiftDirection::Right:
		{
			ul.set_coord(ul.get_x() + 1, ul.get_y());
			br.set_coord(br.get_x() + 1, br.get_y());
			break;
		}
		case ShiftDirection::Down:
		{
			ul.set_coord(ul.get_x(), ul.get_y() + 1);
			br.set_coord(br.get_x(), br.get_y() + 1);
			break;
		}
		case ShiftDirection::Left:
		{
			ul.set_coord(ul.get_x() - 1, ul.get_y());
			br.set_coord(br.get_x() - 1, br.get_y());
			break;
		}
		case ShiftDirection::Up:
		{
			ul.set_coord(ul.get_x(), ul.get_y() - 1);
			br.set_coord(br.get_x(), br.get_y() - 1);
			break;
		}
		}
		(*iter)->setBottomRight(br);
		(*iter)->setUpperLeft(ul);
	}
}
void WorldMap::Shift(ShiftDirection SD, int shiftvalue)
{
	C_ptr->CursorShift(SD, shiftvalue);
	list< GlobalObject* >::iterator iter;
	for (iter = (AllObjects_ptr->getAllObjects()).begin(); iter != (AllObjects_ptr->getAllObjects()).end(); iter++)
	{
		PointCoord ul = (*iter)->getUpperLeft();
		PointCoord br = (*iter)->getBottomRight();
		switch (SD)
		{
		case ShiftDirection::Right:
		{
			ul.set_coord(ul.get_x() + shiftvalue, ul.get_y());
			br.set_coord(br.get_x() + shiftvalue, br.get_y());
			break;
		}
		case ShiftDirection::Left:
		{
			ul.set_coord(ul.get_x() - shiftvalue, ul.get_y());
			br.set_coord(br.get_x() - shiftvalue, br.get_y());
			break;
		}
		}
		(*iter)->setBottomRight(br);
		(*iter)->setUpperLeft(ul);
	}
}
void WorldMap::DisplayAllObjects()
{
	list< GlobalObject* >::iterator iter;
	for (iter = (Buildings_ptr->getAllBuildings()).begin(); iter != (Buildings_ptr->getAllBuildings()).end(); iter++)
	{
		PointCoord ULBuilding = (*iter)->getUpperLeft();
		PointCoord BRBuilding = (*iter)->getBottomRight();
		Draw_ptr->drawBuilding(ULBuilding.get_x(), ULBuilding.get_y(), BRBuilding.get_x(), BRBuilding.get_y(), (*iter)->getSymbol());
	}
	list< GlobalObject* >::iterator iter1;
	for (iter1 = (Roads_ptr->getAllRoads()).begin(); iter1 != (Roads_ptr->getAllRoads()).end(); iter1++)
	{
		PointCoord ULRoad = (*iter)->getUpperLeft();
		int mask1 = Roads_ptr->RoadEnvironment(ULRoad);
		char RoadSymbol = Roads_ptr->SetRoadSymbol(mask1);
		Draw_ptr->drawRoad(ULRoad.get_x(), ULRoad.get_y(), RoadSymbol);
	}
	list< Visitor* >::iterator iter2;
	for (iter2 = (Visitors_ptr->getAllVisitors()).begin(); iter2 != (Visitors_ptr->getAllVisitors()).end(); iter2++)
	{
		PointCoord ULVisitor = (*iter)->getUpperLeft();
		Draw_ptr->drawVisitor(ULVisitor.get_x(), ULVisitor.get_y());
	}
}
void WorldMap::eraseAllObjects()
{
	list< GlobalObject* >::iterator iter;
	for (iter = (Buildings_ptr->getAllBuildings()).begin(); iter != (Buildings_ptr->getAllBuildings()).end(); iter++)
	{
		PointCoord ULBuilding = (*iter)->getUpperLeft();
		PointCoord BRBuilding = (*iter)->getBottomRight();
		Draw_ptr->eraseBuilding(ULBuilding.get_x(), ULBuilding.get_y(), BRBuilding.get_x(), BRBuilding.get_y());
	}
	list< GlobalObject* >::iterator iter1;
	for (iter1 = (Roads_ptr->getAllRoads()).begin(); iter1 != (Roads_ptr->getAllRoads()).end(); iter1++)
	{
		PointCoord ULRoad = (*iter)->getUpperLeft();
		Draw_ptr->erasePixel(ULRoad.get_x(), ULRoad.get_y());
	}
	list< Visitor* >::iterator iter2;
	for (iter2 = (Visitors_ptr->getAllVisitors()).begin(); iter2 != (Visitors_ptr->getAllVisitors()).end(); iter2++)
	{
		PointCoord ULVisitor = (*iter)->getUpperLeft();
		Draw_ptr->erasePixel(ULVisitor.get_x(), ULVisitor.get_y());
	}
}
void WorldMap::PreliminaryBuildingCreation(GlobalObject* go_ptr)
{
	GlobalObject* preliminary_ptr = go_ptr->CreateObject();
	AllObjects_ptr->addObject(preliminary_ptr);
	AllObjects_ptr->setLastElementFlag(1);
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
	Shift(SideMenu_ptr->ChangeMenuStatus(), SideMenu_ptr->getMenuBottomRight().get_x() - SideMenu_ptr->getMenuUpperLeft().get_x());
	eraseScreen();
	DisplayPlayingField();
	DisplaySideMenu();
	DisplayAllObjects();
}
void WorldMap::Tab_Key_Playingfield()
{
	PointCoord MenuUL = SideMenu_ptr->getMenuUpperLeft();
	PointCoord MenuBR = SideMenu_ptr->getMenuBottomRight();
	AllObjects_ptr->setLastElementFlag(0);
	GlobalObject* preliminary_ptr = AllObjects_ptr->getPreliminaryElement();
	Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, preliminary_ptr->getUpperLeft().get_y() - 3, MenuBR.get_x() - 2, preliminary_ptr->getUpperLeft().get_y() + 2, color::cYELLOW);
	AllObjects_ptr->ErasePreliminaryElement();
	PointCoord UpperVisibleIcon = SideMenu_ptr->getNearestIconCoords(PointCoord(0, 0), IconsPosition::LOWER);
	C_ptr->CursorMovement(UpperVisibleIcon);
	Draw_ptr->drawIconBorders(SideMenu_ptr->getMenuUpperLeft().get_x() + 2, UpperVisibleIcon.get_y() - 3, SideMenu_ptr->getMenuBottomRight().get_x() - 2, UpperVisibleIcon.get_y() + 2, color::cGREEN);
	return;
}
void WorldMap::Enter_Key_PlayingField()
{
	if (AllObjects_ptr->getLastElementFlag())
	{
		GlobalObject* UnderConstruction_ptr = nullptr;
		memcpy(UnderConstruction_ptr, AllObjects_ptr->getPreliminaryElement(), sizeof(AllObjects_ptr->getPreliminaryElement()));
		BuildingType BT = AllObjects_ptr->DefinePointerType(UnderConstruction_ptr);
		AllObjects_ptr->ErasePreliminaryElement();
		switch (BT)
		{
		case BuildingType::Road:
		{
			GlobalObject* r_ptr = new Road(C_ptr->getCursorConsoleLocation());
			AllObjects_ptr->addObject(r_ptr);
			Roads_ptr->addRoad(r_ptr);
			AllObjects_ptr->addObject(UnderConstruction_ptr);
			int roadmask = Roads_ptr->RoadEnvironment(r_ptr->getUpperLeft());
			char roadsymbol = Roads_ptr->SetRoadSymbol(roadmask);
			Draw_ptr->drawRoad(r_ptr->getUpperLeft().get_x(), r_ptr->getUpperLeft().get_y(), roadsymbol);
			return;
		}
		case BuildingType::IceCreamShop:
		{
			GlobalObject* r_ptr = new IceCreamShop(C_ptr->getCursorConsoleLocation());
			AllObjects_ptr->addObject(r_ptr);
			Buildings_ptr->addBuilding(r_ptr);
			AllObjects_ptr->addObject(UnderConstruction_ptr);
			Draw_ptr->drawBuilding(r_ptr->getUpperLeft().get_x(), r_ptr->getUpperLeft().get_y(),
				r_ptr->getBottomRight().get_x(), r_ptr->getBottomRight().get_y(), r_ptr->getSymbol());
			return;
		}
		}
	}
	else
	{
		return;
	}
}
void WorldMap::Enter_Key_SideMenu()
{
	PointCoord MenuUL = SideMenu_ptr->getMenuUpperLeft();
	PointCoord MenuBR = SideMenu_ptr->getMenuBottomRight();
	PreliminaryBuildingCreation(SideMenu_ptr->ChooseBuilding(C_ptr->getCursorConsoleLocation()));
	Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, C_ptr->getCursorConsoleLocation().get_y() - 3, MenuBR.get_x() - 2, C_ptr->getCursorConsoleLocation().get_y() + 2, color::cRED);
	C_ptr->CursorMovement(PointCoord(VM_ptr->getBottomRightCorner().get_x() / 2, VM_ptr->getBottomRightCorner().get_y() / 2));
	return;
}
void WorldMap::Esc_Key_PlayingField()
{
	PointCoord MenuUL = SideMenu_ptr->getMenuUpperLeft();
	PointCoord MenuBR = SideMenu_ptr->getMenuBottomRight();
	AllObjects_ptr->setLastElementFlag(0);
	GlobalObject* preliminary_ptr = AllObjects_ptr->getPreliminaryElement();
	Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, preliminary_ptr->getUpperLeft().get_y() - 3, MenuBR.get_x() - 2, preliminary_ptr->getUpperLeft().get_y() + 2, color::cYELLOW);
	AllObjects_ptr->ErasePreliminaryElement();
}
void WorldMap::UserActions(int key)
{
	SideMenuStatus MenuPosition = SideMenu_ptr->getCurrentStatus();
	switch (key)
	{
	case 104: { H_Key(); return; }	//'h' key hide or display SideMenu
	case 115: { S_Key(); return; }	//'s' key change placement of menu from right to left and vice versa
	}
	if ((C_ptr->getCursorConsoleLocation().get_x() < VM_ptr->getBottomRightCorner().get_x() && MenuPosition == SideMenuStatus::RIGHT) ||	//this condition checks if the cursor is in the playing field or in the menu
		(C_ptr->getCursorConsoleLocation().get_x() > VM_ptr->getUpperLeftCorner().get_x() && MenuPosition == SideMenuStatus::LEFT))
	{
		switch (key)
		{
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
		case 72: {C_ptr->CursorMovement(SideMenu_ptr->MenuNavigation(C_ptr->getCursorConsoleLocation(), IconsPosition::UPPER)); return;	}				//up arrow
		case 80: { C_ptr->CursorMovement(SideMenu_ptr->MenuNavigation(C_ptr->getCursorConsoleLocation(), IconsPosition::LOWER)); return; }				//down arrow
		case 9: { C_ptr->CursorMovement(PointCoord(VM_ptr->getBottomRightCorner().get_x() / 2, VM_ptr->getBottomRightCorner().get_y() / 2)); return; }	//tab key moves cursor to the center of playing field
		case 13: { Enter_Key_SideMenu(); return; }																										//enter key chooses building to create
		default:
			return;
		}
	}
}