#include "SideMenu.h"
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