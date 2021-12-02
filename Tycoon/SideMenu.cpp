#include "SideMenu.h"
/////////////Side Menu Class/////////////
SideMenuStatus SideMenu::getSideStatus()
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
	vector<Icon<T>*>::iterator iter;
	ShiftDirection SD;
	PointCoord UL, MenuUL;
	if (CurrentStatus == SideMenuStatus::LEFT)
	{
		CurrentStatus = SideMenuStatus::RIGHT;
		UL = UL_Angle;
		unsigned int width = VM_ptr->getWidth();
		MenuUL = PointCoord(UL.get_x() + width, UL.get_y());
		SD = ShiftDirection::Right;
	}
	else
	{
		CurrentStatus = SideMenuStatus::LEFT;
		MenuUL = UL_Angle;
		unsigned int menuwidth = getWidth();
		UL = PointCoord(MenuUL.get_x() + menuwidth, MenuUL.get_y());
		SD = ShiftDirection::Left;
	}
	VM_ptr->setUpperLeft(UL);
	setUpperLeft(MenuUL);
	int _x = (getUpperLeft().get_x() * 2 + getWidth() - 1) / 2;
	int _y = getUpperLeft().get_y() + 4;
	for (iter = Icons.begin(); iter != Icons.end(); iter++)
	{
		(*iter)->setUpperLeft(PointCoord(_x, _y));
		_y += 6;
	}
	return SD;
}
void SideMenu::ShowIcons()
{
	int left_x = getUpperLeft().get_x();
	int top_y = getUpperLeft().get_y();
	int right_x = getUpperLeft().get_x() + getWidth() - 1;
	int bot_y = getUpperLeft().get_x() + getHeight() - 1;
	vector<Icon<T>*>::iterator iter;
	for (iter = Icons.begin(); iter != Icons.end(); iter++)
	{
		Draw_ptr->drawIconBorders(left_x + 2, top_y + 1, right_x - 2, top_y + 6, color::cYELLOW);
		Draw_ptr->drawIcon(left_x + 3, top_y + 2, (*iter)->getConstructionCost(), (*iter)->getDailyExpences(),
			(*iter)->getIconSymbol(), (*iter)->getDescription(), color::cGREEN);
		top_y += 6;
	}
}
void SideMenu::ShowMenuBorders()
{
	int left_x = getUpperLeft().get_x();
	int top_y = getUpperLeft().get_y();
	int right_x = getUpperLeft().get_x() + MenuWidth - 1;
	int bot_y = getUpperLeft().get_y() + VisibleMapHeight - 1;
	Draw_ptr->drawMenuBorders(left_x, top_y, right_x, bot_y, color::cBLUE);
}
PointCoord SideMenu::getNearestIconCoords(PointCoord currenticon, IconsPosition ip) //this method returns next upper/lower Icon's coords after "currenticon" coord
{
	vector<Icon<T>*>::iterator iter;
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
	vector<Icon<T>*>::iterator iter;
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
	PointCoord MenuUL = getUpperLeft();
	unsigned int menu_height = getHeight();
	unsigned int menu_width = getWidth();
	if (nearest.get_y() == currenticon.get_y() + 1000 || nearest.get_y() == currenticon.get_y() - 1000)
	{
		return currenticon;
	}
	else
	{
		if (nearest.get_y() < VM_ptr->getUpperLeft().get_y() + VM_ptr->getHeight() - 1)
		{
			Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, currenticon.get_y() - 3, MenuUL.get_x() + menu_width - 3, currenticon.get_y() + 2, color::cYELLOW);
			Draw_ptr->drawIconBorders(MenuUL.get_x() + 2, nearest.get_y() - 3, MenuUL.get_x() + menu_width - 3, nearest.get_y() + 2, color::cGREEN);
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
	vector<Icon<T>*>::iterator iter;
	for (iter = Icons.begin(); iter != Icons.end(); iter++)
	{
		if (iconpos == (*iter)->getUpperLeft())
		{
			return (*iter);
		}
	}
}
void SideMenu::EraseMenu()
{
	for (int j = MenuUpperLeft.get_y(); j <= MenuBottomRight.get_y(); j++)
	{
		for (int i = MenuUpperLeft.get_x(); i <= MenuBottomRight.get_x(); i++)
		{
			Draw_ptr->erasePixel(i, j);
		}
	}
}