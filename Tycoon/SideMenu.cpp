#include "SideMenu.h"
/////////////Side Menu Class/////////////
SideMenuStatus SideMenu::getCurrentSide()
{
	return CurrentSide;
}
bool SideMenu::getHideMenuStatus() const
{
	return Hidden;
}
void SideMenu::setHideMenuStatus(bool hideflag)
{
	Hidden = hideflag;
}
ShiftDirection SideMenu::ChangeMenuSide()
{
	vector<ConstructionManager*>::iterator iter;
	ShiftDirection SD;
	PointCoord UL, MenuUL;
	if (CurrentSide == SideMenuStatus::LEFT)
	{
		CurrentSide = SideMenuStatus::RIGHT;
		UL = ConstructionOptions::getAllOptions()->getVisibleMapInitialCoordUL();
		unsigned int widthadd = VM_ptr->getWidthAddition();
		MenuUL = PointCoord(UL.get_x() + widthadd, UL.get_y());
		SD = ShiftDirection::Right;
	}
	else
	{
		CurrentSide = SideMenuStatus::LEFT;
		MenuUL = ConstructionOptions::getAllOptions()->getVisibleMapInitialCoordUL();
		unsigned int menuwidthadd = getWidthAddition();
		UL = PointCoord(MenuUL.get_x() + menuwidthadd, MenuUL.get_y());
		SD = ShiftDirection::Left;
	}
	VM_ptr->setUpperLeft(UL);
	setUpperLeft(MenuUL);
	int _x = (getUpperLeft().get_x() * 2 + getWidthAddition()) / 2;
	int _y = getUpperLeft().get_y() + 4;
	for (iter = Managers.begin(); iter != Managers.end(); iter++)
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
	int right_x = getUpperLeft().get_x() + getWidthAddition();
	int bot_y = getUpperLeft().get_x() + getHeightAddition();
	vector<ConstructionManager*>::iterator iter;
	for (iter = Managers.begin(); iter != Managers.end(); iter++)
	{
		Draw_ptr->drawIconBorders(left_x + 2, top_y + 1, right_x - 2, top_y + 6, color::cYELLOW);
		Draw_ptr->drawIcon(left_x + 3, top_y + 2, (*iter)->getConstructionCost(), (*iter)->getDailyExpences(),
			(*iter)->getBuildingSymbol(), (*iter)->getDescription(), color::cGREEN);
		top_y += ConstructionOptions::getAllOptions()->getMenuElementBordersHeight();
	}
}
void SideMenu::ShowMenuBorders()
{
	int left_x = getUpperLeft().get_x();
	int top_y = getUpperLeft().get_y();
	int right_x = getUpperLeft().get_x() + ConstructionOptions::getAllOptions()->getMenuWidthAdd();
	int bot_y = getUpperLeft().get_y() + ConstructionOptions::getAllOptions()->getMenuHeightAdd();
	Draw_ptr->drawMenuBorders(left_x, top_y, right_x, bot_y, color::cBLUE);
}
PointCoord SideMenu::getNearestIconCoords(PointCoord currenticon, IconsPosition ip) //this method returns next upper/lower Icon's coords before/after "currenticon" coord
{
	vector<ConstructionManager*>::iterator iter;
	if (ip == IconsPosition::UPPER)
	{
		PointCoord nearest(currenticon.get_x(), currenticon.get_y() - 1000);
		for (iter = Managers.begin(); iter != Managers.end(); iter++)
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
		for (iter = Managers.begin(); iter != Managers.end(); iter++)
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
	vector<ConstructionManager*>::iterator iter;
	if (ip == IconsPosition::UPPER)
	{
		for (iter = Managers.begin(); iter != Managers.end(); iter++)
		{
			PointCoord UL((*iter)->getUpperLeft().get_x(), (*iter)->getUpperLeft().get_y() - ConstructionOptions::getAllOptions()->getMenuElementBordersHeight());
			(*iter)->setUpperLeft(UL);
		}
	}
	else
	{
		for (iter = Managers.begin(); iter != Managers.end(); iter++)
		{
			PointCoord UL((*iter)->getUpperLeft().get_x(), (*iter)->getUpperLeft().get_y() + ConstructionOptions::getAllOptions()->getMenuElementBordersHeight());
			(*iter)->setUpperLeft(UL);
		}
	}
}
PointCoord SideMenu::MenuNavigation(PointCoord currenticon, IconsPosition ip)
{
	PointCoord nearest = getNearestIconCoords(currenticon, ip);
	PointCoord MenuUL = getUpperLeft();
	unsigned int menu_height = getHeightAddition();
	unsigned int menu_width = getWidthAddition();
	if (nearest.get_y() == currenticon.get_y() + 1000 || nearest.get_y() == currenticon.get_y() - 1000)
	{
		return currenticon;
	}
	else
	{
		if (nearest.get_y() < VM_ptr->getUpperLeft().get_y() + VM_ptr->getHeightAddition())
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
	vector<ConstructionManager*>::iterator iter;
	for (iter = Managers.begin(); iter != Managers.end(); iter++)
	{
		if (iconpos == (*iter)->getUpperLeft())
		{
			int x_coord = (VM_ptr->getUpperLeft().get_x() + VM_ptr->getUpperLeft().get_x() + VM_ptr->getWidthAddition()) / 2;
			int y_coord = (VM_ptr->getUpperLeft().get_y() + VM_ptr->getUpperLeft().get_y() + VM_ptr->getHeightAddition()) / 2;
			Construction* preliminary_ptr = (*iter)->CreateConstruction(PointCoord(x_coord, y_coord));
			return preliminary_ptr;
		}
	}
}
void SideMenu::EraseMenu()
{
	for (int j = getUpperLeft().get_y(); j <= getUpperLeft().get_y() + getHeightAddition(); j++)
	{
		for (int i = getUpperLeft().get_x(); i <= getUpperLeft().get_x() + getWidthAddition(); i++)
		{
			Draw_ptr->erasePixel(i, j);
		}
	}
}