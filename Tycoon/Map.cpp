#pragma once
#include <cstdlib>
#include "logicheader.h"
using namespace std;
///////////////WorldMap Class///////////////
void WorldMap::drawMapBorders()
{
	Draw_ptr->drawWorld();
}
void WorldMap::GameProcess()
{
	char ch = 'a';
	ShiftDirection SD;
	drawMapBorders();
	set_cursor_pos(5, 5);
	C_ptr->setCursorConsoleLocation();
	Buildings_ptr->CreateBuilding(ch);
	while (true)
	{
		SD = VM_ptr->CursorBordersCheck(C_ptr);
		if (SD != ShiftDirection::Middle)
		{
			eraseAll();
			Shift(SD);
			drawAll();
		}
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
		wait(300);
	}
}
void WorldMap::Shift(ShiftDirection SD)
{
	C_ptr->CursorShift(SD);
	list< GlobalObject* >::iterator iter;
	for (iter = (AllObjects_ptr -> getAllObjects()).begin(); iter != (AllObjects_ptr -> getAllObjects()).end(); iter++)
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
void WorldMap::drawAll()
{
	list< GlobalObject* >::iterator iter;
	for (iter = (Buildings_ptr->getAllBuildings()).begin(); iter != (Buildings_ptr->getAllBuildings()).end(); iter++)
	{
		PointCoord ULBuilding = (*iter)->getUpperLeft();
		PointCoord BRBuilding = (*iter)->getBottomRight();
		Draw_ptr->drawBuilding(ULBuilding.get_x(), ULBuilding.get_y(), BRBuilding.get_x(), BRBuilding.get_y(), (*iter)->getSymbol());
	}
	list< Road* >::iterator iter1;
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
void WorldMap::eraseAll()
{
	list< GlobalObject* >::iterator iter;
	for (iter = (Buildings_ptr->getAllBuildings()).begin(); iter != (Buildings_ptr->getAllBuildings()).end(); iter++)
	{
		PointCoord ULBuilding = (*iter)->getUpperLeft();
		PointCoord BRBuilding = (*iter)->getBottomRight();
		Draw_ptr->eraseBuilding(ULBuilding.get_x(), ULBuilding.get_y(), BRBuilding.get_x(), BRBuilding.get_y());
	}
	list< Road* >::iterator iter1;
	for (iter1 = (Roads_ptr->getAllRoads()).begin(); iter1 != (Roads_ptr->getAllRoads()).end(); iter1++)
	{
		PointCoord ULRoad = (*iter)->getUpperLeft();
		Draw_ptr->eraseRoad(ULRoad.get_x(), ULRoad.get_y());
	}
	list< Visitor* >::iterator iter2;
	for (iter2 = (Visitors_ptr->getAllVisitors()).begin(); iter2 != (Visitors_ptr->getAllVisitors()).end(); iter2++)
	{
		PointCoord ULVisitor = (*iter)->getUpperLeft();
		Draw_ptr->eraseVisitor(ULVisitor.get_x(), ULVisitor.get_y());
	}
}
void WorldMap::UserActions(int key)
{
	switch (key)
	{
		case 75:
		{
			set_cursor_pos(C_ptr->getCursorConsoleLocation().get_x() - 1, C_ptr->getCursorConsoleLocation().get_y());
			C_ptr->setCursorConsoleLocation();
			return;
		}
		case 72:
		{
			set_cursor_pos(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y() - 1);
			C_ptr->setCursorConsoleLocation();
			return;
		}
		case 77:
		{
			set_cursor_pos(C_ptr->getCursorConsoleLocation().get_x() + 1, C_ptr->getCursorConsoleLocation().get_y());
			C_ptr->setCursorConsoleLocation();
			return;
		}
		case 80:
		{
			set_cursor_pos(C_ptr->getCursorConsoleLocation().get_x(), C_ptr->getCursorConsoleLocation().get_y() + 1);
			C_ptr->setCursorConsoleLocation();
			return;
		}
		default:
			return;
	}
}
///////////////VisibleMap Class///////////////
void VisibleMap::SetCorners(int left_x, int right_x, int up_y, int bot_y)
{
	UpperLeftCorner.set_coord(left_x, up_y);
	BottomRightCorner.set_coord(right_x, bot_y);
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