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
	list<GlobalObject*>::const_iterator iter;
	for (iter = (AllObjects_ptr->getAllObjects()).begin(); iter != (AllObjects_ptr->getAllObjects()).end(); iter++)
	{
		PointCoord ul = (*iter)->getUpperLeft();
		switch (SD)
		{
		case ShiftDirection::Right:
		{
			ul.set_coord(ul.get_x() + 1, ul.get_y());
			break;
		}
		case ShiftDirection::Down:
		{
			ul.set_coord(ul.get_x(), ul.get_y() + 1);
			break;
		}
		case ShiftDirection::Left:
		{
			ul.set_coord(ul.get_x() - 1, ul.get_y());
			break;
		}
		case ShiftDirection::Up:
		{
			ul.set_coord(ul.get_x(), ul.get_y() - 1);
			break;
		}
		}
		(*iter)->setUpperLeft(ul);
	}
}
void WorldMap::Shift(ShiftDirection SD, int shiftvalue)
{
	C_ptr->CursorShift(SD, shiftvalue);
	list< GlobalObject* >::const_iterator iter;
	for (iter = (AllObjects_ptr->getAllObjects()).begin(); iter != (AllObjects_ptr->getAllObjects()).end(); iter++)
	{
		PointCoord ul = (*iter)->getUpperLeft();
		switch (SD)
		{
		case ShiftDirection::Right:
		{
			ul.set_coord(ul.get_x() + shiftvalue, ul.get_y());
			break;
		}
		case ShiftDirection::Left:
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
//PointCoord WorldMap::RoadConnection()	//returns PointCoord of Road Pixel, choosen as Graph
//{
//	list< GlobalObject* >::iterator iterBuildings;
//	list< GlobalObject* >::iterator iterRoads;
//	for (iterBuildings = Buildings_ptr->getAllBuildings().begin(); iterBuildings != Buildings_ptr->getAllBuildings().end(); iterBuildings++)
//	{
//		vector<PointCoord> PointsAround;
//		PointCoord UL = (*iterBuildings)->getUpperLeft();
//		PointCoord BR = (*iterBuildings)->getBottomRight();
//		for (int x = UL.get_x(); x <= BR.get_x(); x++)
//		{
//			PointsAround.push_back(PointCoord(x, UL.get_y() - 1));
//		}
//		for (int x = UL.get_x(); x <= BR.get_x(); x++)
//		{
//			PointsAround.push_back(PointCoord(x, BR.get_y() + 1));
//		}
//		for (int y = UL.get_y(); y <= BR.get_y(); y++)
//		{
//			PointsAround.push_back(PointCoord(UL.get_x() - 1, y));
//		}
//		for (int y = UL.get_y(); y <= BR.get_y(); y++)
//		{
//			PointsAround.push_back(PointCoord(BR.get_x() + 1, y));
//		}
//		vector<PointCoord>::iterator iterCoord;
//		vector<PointCoord> RoadsAround;
//		for (iterRoads = Roads_ptr->getAllRoads().begin(); iterRoads != Roads_ptr->getAllRoads().end(); iterRoads++)
//		{
//			for (iterCoord = PointsAround.begin(); iterCoord != PointsAround.end(); iterCoord++)
//			{
//				if ((*iterCoord) == (*iterRoads)->getUpperLeft())
//				{
//					RoadsAround.push_back((*iterCoord));
//				}
//			}
//		}
//
//	}
//}
void WorldMap::PreliminaryBuildingCreation(GlobalObject* preliminary_ptr)
{
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
	Shift(SideMenu_ptr->ChangeMenuSide(), SideMenu_ptr->getUpperLeft().get_x() + SideMenu_ptr->getWidthAddition() - SideMenu_ptr->getUpperLeft().get_x());
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
		GlobalObject* preliminary_ptr = AllObjects_ptr->getPreliminaryElement();
		Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, preliminary_ptr->getUpperLeft().get_y() - 3, MenuBR.get_x() - 2, preliminary_ptr->getUpperLeft().get_y() + 2, color::cYELLOW);
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
		BuildingType BT = AllObjects_ptr->DefinePointerType(AllObjects_ptr->getPreliminaryElement());
		switch (BT)
		{
		case BuildingType::Road:
		{
			GlobalObject* r_ptr = new Road(C_ptr->getCursorConsoleLocation());
			AllObjects_ptr->addBeforePreliminary(r_ptr);
			Roads_ptr->addRoad(r_ptr);
			int roadmask = Roads_ptr->RoadEnvironment(r_ptr->getUpperLeft());
			char roadsymbol = r_ptr->SetRoadSymbol(roadmask);
			Draw_ptr->drawRoad(r_ptr->getUpperLeft().get_x(), r_ptr->getUpperLeft().get_y(), roadsymbol);
			return;
		}
		case BuildingType::IceCreamShop:
		{
			GlobalObject* r_ptr = new IceCreamShop(C_ptr->getCursorConsoleLocation());
			AllObjects_ptr->addBeforePreliminary(r_ptr);
			Buildings_ptr->addBuilding(r_ptr);
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
	C_ptr->CursorMovement(PointCoord((VM_ptr->getBottomRightCorner().get_x() + VM_ptr->getUpperLeftCorner().get_x()) / 2, (VM_ptr->getBottomRightCorner().get_y() + VM_ptr->getUpperLeftCorner().get_y()) / 2));
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
	C_ptr->CursorMovement(PointCoord((VM_ptr->getBottomRightCorner().get_x() + VM_ptr->getUpperLeftCorner().get_x()) / 2, (VM_ptr->getBottomRightCorner().get_y() + VM_ptr->getUpperLeftCorner().get_y()) / 2));
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
		case 9:
		{
			PointCoord MenuUL = SideMenu_ptr->getMenuUpperLeft();
			PointCoord MenuBR = SideMenu_ptr->getMenuBottomRight();
			Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, C_ptr->getCursorConsoleLocation().get_y() - 3, MenuBR.get_x() - 2, C_ptr->getCursorConsoleLocation().get_y() + 2, color::cYELLOW);
			C_ptr->CursorMovement(PointCoord((VM_ptr->getBottomRightCorner().get_x() + VM_ptr->getUpperLeftCorner().get_x()) / 2, (VM_ptr->getBottomRightCorner().get_y() + VM_ptr->getUpperLeftCorner().get_y()) / 2));
			return;
		}	//tab key moves cursor to the center of playing field
		case 13: { Enter_Key_SideMenu(); return; }																										//enter key chooses building to create
		default:
			return;
		}
	}
}