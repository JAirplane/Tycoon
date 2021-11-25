#pragma once
#include <conio.h>
#include <typeinfo>
#include "Map.h"
using namespace std;
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
	int left_x = SideMenu_ptr->getMenuUpperLeft().get_x();
	int top_y = SideMenu_ptr->getMenuUpperLeft().get_y();
	int right_x = SideMenu_ptr->getMenuBottomRight().get_x();
	int bot_y = SideMenu_ptr->getMenuBottomRight().get_y();
	for (int j = top_y; j <= bot_y; j++)
	{
		for (int i = left_x; i <= right_x; i++)
		{
			Draw_ptr->erasePixel(i, j);
		}
	}
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
void WorldMap::UserActions(int key)
{
	SideMenuStatus MenuPosition = SideMenu_ptr->getCurrentStatus();
	switch (key)
	{
	case 104:	//'h' key hide or display SideMenu
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
	case 115:	//'s' key change placement of menu from right to left and vice versa
	{
		Shift(SideMenu_ptr->ChangeMenuStatus(), SideMenu_ptr->getMenuBottomRight().get_x() - SideMenu_ptr->getMenuUpperLeft().get_x());
		eraseScreen();
		DisplayPlayingField();
		DisplaySideMenu();
		DisplayAllObjects();
	}
	}
	if ((C_ptr->getCursorConsoleLocation().get_x() < VM_ptr->getBottomRightCorner().get_x() && MenuPosition == SideMenuStatus::RIGHT) ||
		(C_ptr->getCursorConsoleLocation().get_x() > VM_ptr->getUpperLeftCorner().get_x() && MenuPosition == SideMenuStatus::LEFT))							//this condition checks if the cursor is in the playing field or in the menu
	{
		switch (key)
		{
		case 75: { C_ptr->CursorMovement(PointCoord(C_ptr->getCursorConsoleLocation().get_x() - 1, C_ptr->getCursorConsoleLocation().get_y())); return; }	//left arrow 
		case 72: { C_ptr->CursorMovement(PointCoord(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y() - 1)); return; }	//up arrow 
		case 77: { C_ptr->CursorMovement(PointCoord(C_ptr->getCursorConsoleLocation().get_x() + 1, C_ptr->getCursorConsoleLocation().get_y())); return; }	//right arrow 
		case 80: { C_ptr->CursorMovement(PointCoord(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y() + 1)); return; }	//down arrow 
		case 9:																																				//tab key moves cursor from the playing field to the menu
		{
			PointCoord UpperVisibleIcon = SideMenu_ptr->getNearestIconCoords(PointCoord(0, 0), IconsPosition::LOWER);
			C_ptr->CursorMovement(UpperVisibleIcon);
			Draw_ptr->drawIconBorders(SideMenu_ptr->getMenuUpperLeft().get_x() + 2, UpperVisibleIcon.get_y() - 3, SideMenu_ptr->getMenuBottomRight().get_x() - 2, UpperVisibleIcon.get_y() + 2, color::cGREEN);
			return;
		}
		case 13:
		{
			if (AllObjects_ptr->getLastElementFlag())
			{
				GlobalObject* UnderConstruction_ptr = AllObjects_ptr->getPreliminaryElement();
				AllObjects_ptr->setLastElementFlag(0);
				BuildingType BT = AllObjects_ptr->DefinePointerType(UnderConstruction_ptr);
				AllObjects_ptr->ErasePreliminaryElement();
				switch (BT)
				{
					case BuildingType::Road:
					{
						GlobalObject* r_ptr = new Road(C_ptr->getCursorConsoleLocation());
						AllObjects_ptr->addObject(r_ptr);
						Roads_ptr->addRoad(r_ptr);
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
		default:
			return;
		}
	}
	else
	{
		switch (key)
		{
		case 72: {C_ptr->CursorMovement(SideMenu_ptr->MenuNavigation(C_ptr->getCursorConsoleLocation(), IconsPosition::UPPER)); return;	}	//up arrow
		case 80: { C_ptr->CursorMovement(SideMenu_ptr->MenuNavigation(C_ptr->getCursorConsoleLocation(), IconsPosition::LOWER)); return; }	//down arrow
		case 9: { C_ptr->CursorMovement(PointCoord(VM_ptr->getBottomRightCorner().get_x() / 2, VM_ptr->getBottomRightCorner().get_y() / 2)); return; }	//tab key moves cursor to the center of playing field
		case 13:
		{
			PreliminaryBuildingCreation(SideMenu_ptr->ChooseBuilding(C_ptr->getCursorConsoleLocation()));
			C_ptr->CursorMovement(PointCoord(VM_ptr->getBottomRightCorner().get_x() / 2, VM_ptr->getBottomRightCorner().get_y() / 2));
			return;
		}
		default:
			return;
		}
	}
}
///////////////VisibleMap Class///////////////
PointCoord VisibleMap::getUpperLeftCorner() const
{
	return UpperLeftCorner;
}
PointCoord VisibleMap::getBottomRightCorner() const
{
	return BottomRightCorner;
}
void VisibleMap::SetCorners(PointCoord UL, PointCoord BR)
{
	UpperLeftCorner.set_coord(UL);
	BottomRightCorner.set_coord(BR);
}
ShiftDirection VisibleMap::CursorBordersCheck(Cursor* C_ptr)
{
	ShiftDirection SD;
	if ((C_ptr->getCursorConsoleLocation()).get_x() == UpperLeftCorner.get_x())
	{
		SD = ShiftDirection::Right;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_y() == UpperLeftCorner.get_y())
	{
		SD = ShiftDirection::Down;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_x() == BottomRightCorner.get_x())
	{
		SD = ShiftDirection::Left;
		return SD;
	}
	if ((C_ptr->getCursorConsoleLocation()).get_y() == BottomRightCorner.get_y())
	{
		SD = ShiftDirection::Up;
		return SD;
	}
	SD = ShiftDirection::Middle;
	return SD;
}
/////////////Side Menu Class/////////////
void SideMenu::setMenuCoords(PointCoord UL, PointCoord BR)
{
	MenuUpperLeft = UL;
	MenuBottomRight = BR;
}
PointCoord SideMenu::getMenuUpperLeft() const
{
	return MenuUpperLeft;
}
PointCoord SideMenu::getMenuBottomRight() const
{
	return MenuBottomRight;
}
SideMenuStatus SideMenu::getCurrentStatus()
{
	return CurrentStatus;
}
bool SideMenu::getHideMenuStatus() const
{
	return Hidden;
}
void SideMenu::setHideMenuStatus(bool hideflag)
{
	Hidden = hideflag;
}
ShiftDirection SideMenu::ChangeMenuStatus()
{
	vector<GlobalObject*>::iterator iter;
	ShiftDirection SD;
	PointCoord UL, BR, MenuUL, MenuBR;
	if (CurrentStatus == SideMenuStatus::LEFT)
	{
		CurrentStatus = SideMenuStatus::RIGHT;
		UL = PointCoord(1, 1);
		BR = PointCoord(UL.get_x() + X_axis, UL.get_y() + Y_axis);
		MenuUL = PointCoord(VM_ptr->getBottomRightCorner().get_x() + 1, VM_ptr->getUpperLeftCorner().get_y());
		MenuBR = PointCoord(MenuUL.get_x() + Menu_X_axis, MenuUL.get_y() + Y_axis);
		SD = ShiftDirection::Right;
	}
	else
	{
		CurrentStatus = SideMenuStatus::LEFT;
		MenuUL = PointCoord(1, 1);
		MenuBR = PointCoord(MenuUL.get_x() + Menu_X_axis, MenuUL.get_y() + Y_axis);
		UL = PointCoord(MenuBR.get_x() + 1, MenuUL.get_y());
		BR = PointCoord(UL.get_x() + X_axis, UL.get_y() + Y_axis);
		SD = ShiftDirection::Left;
	}
	setMenuCoords(MenuUL, MenuBR);
	VM_ptr->SetCorners(UL, BR);
	int _x = (getMenuBottomRight().get_x() + getMenuUpperLeft().get_x()) / 2;
	int _y = getMenuUpperLeft().get_y() + 4;
	for (iter = Icons.begin(); iter != Icons.end(); iter++)
	{
		(*iter)->setUpperLeft(PointCoord(_x, _y));
		_y += 6;
	}
	return SD;
}
void SideMenu::ShowIcons()
{
	int left_x = MenuUpperLeft.get_x();
	int top_y = MenuUpperLeft.get_y();
	int right_x = MenuBottomRight.get_x();
	int bot_y = MenuBottomRight.get_y();
	vector<GlobalObject*>::iterator iter;
	for (iter = Icons.begin(); iter != Icons.end(); iter++)
	{
		Draw_ptr->drawIconBorders(left_x + 2, top_y + 1, right_x - 2, top_y + 6, color::cYELLOW);
		Draw_ptr->drawIcon(left_x + 3, top_y + 2, (*iter)->getConstructionCost(), (*iter)->getDailyExpences(),
			(*iter)->getSymbol(), (*iter)->getDescription(), color::cGREEN);
		top_y += 6;
	}
}
void SideMenu::ShowMenuBorders()
{
	int left_x = MenuUpperLeft.get_x();
	int top_y = MenuUpperLeft.get_y();
	int right_x = MenuBottomRight.get_x();
	int bot_y = MenuBottomRight.get_y();
	Draw_ptr->drawMenuBorders(left_x, top_y, right_x, bot_y, color::cBLUE);
}
PointCoord SideMenu::getNearestIconCoords(PointCoord currenticon, IconsPosition ip) //this method returns next upper/lower Icon's coords after "currenticon" coord
{
	vector<GlobalObject*>::iterator iter;
	if (ip == IconsPosition::UPPER)
	{
		PointCoord nearest(currenticon.get_x(), currenticon.get_y() - 1000);
		for (iter = Icons.begin(); iter != Icons.end(); iter++)
		{
			if ((*iter)->getUpperLeft().get_y() < currenticon.get_y() && (*iter)->getUpperLeft().get_y() > nearest.get_y())
			{
				nearest = (*iter)->getUpperLeft();
			}
		}
		return nearest;
	}
	else
	{
		PointCoord nearest(currenticon.get_x(), currenticon.get_y() + 1000);
		for (iter = Icons.begin(); iter != Icons.end(); iter++)
		{
			if ((*iter)->getUpperLeft().get_y() > currenticon.get_y() && (*iter)->getUpperLeft().get_y() < nearest.get_y())
			{
				nearest = (*iter)->getUpperLeft();
			}
		}
		return nearest;
	}
}
void SideMenu::IconsShift(IconsPosition ip)
{
	vector<GlobalObject*>::iterator iter;
	if (ip == IconsPosition::UPPER)
	{
		for (iter = Icons.begin(); iter != Icons.end(); iter++)
		{
			PointCoord UL((*iter)->getUpperLeft().get_x(), (*iter)->getUpperLeft().get_y() - 6);
			(*iter)->setUpperLeft(UL);
		}
	}
	else
	{
		for (iter = Icons.begin(); iter != Icons.end(); iter++)
		{
			PointCoord UL((*iter)->getUpperLeft().get_x(), (*iter)->getUpperLeft().get_y() + 6);
			(*iter)->setUpperLeft(UL);
		}
	}
}
PointCoord SideMenu::MenuNavigation(PointCoord currenticon, IconsPosition ip)
{
	PointCoord nearest = getNearestIconCoords(currenticon, ip);
	PointCoord MenuUL = getMenuUpperLeft();
	PointCoord MenuBR = getMenuBottomRight();
	if (nearest.get_y() == currenticon.get_y() + 1000 || nearest.get_y() == currenticon.get_y() - 1000)
	{
		return currenticon;
	}
	else
	{
		if (nearest.get_y() < VM_ptr->getBottomRightCorner().get_y())
		{
			Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, currenticon.get_y() - 3, MenuBR.get_x() - 2, currenticon.get_y() + 2, color::cYELLOW);
			Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, nearest.get_y() - 3, MenuBR.get_x() - 2, nearest.get_y() + 2, color::cGREEN);
			return nearest;
		}
		else
		{
			IconsShift(ip);
			return currenticon;
		}
	}
}
GlobalObject* SideMenu::ChooseBuilding(PointCoord iconpos)
{
	vector<GlobalObject*>::iterator iter;
	for (iter = Icons.begin(); iter != Icons.end(); iter++)
	{
		if (iconpos == (*iter)->getUpperLeft())
		{
			return (*iter);
		}
	}
}