#include "Menu.h"
/////////////Side Menu Class/////////////
MenuStatus Menu::getCurrentSide()
{
	return CurrentSide;
}
bool Menu::getHideMenuStatus() const
{
	return Hidden;
}
void Menu::setHideMenuStatus(bool hideflag)
{
	Hidden = hideflag;
}
Direction Menu::ChangeMenuSide()
{
	vector<ConstructionManager*>::iterator iter;
	Direction SD;
	PointCoord UL, MenuUL;
	if (CurrentSide == MenuStatus::LEFT)
	{
		CurrentSide = MenuStatus::RIGHT;
		UL = ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft();
		unsigned int widthadd = camera_ptr->GetWidthAddition();
		MenuUL = PointCoord(UL.Get_x() + widthadd + 1, UL.Get_y());
		SD = Direction::Left;
	}
	else
	{
		CurrentSide = MenuStatus::LEFT;
		MenuUL = ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft();
		unsigned int menuwidthadd = GetWidthAddition();
		UL = PointCoord(MenuUL.Get_x() + menuwidthadd + 1, MenuUL.Get_y());
		SD = Direction::Right;
	}
	camera_ptr->SetUpperLeft(UL);
	SetUpperLeft(MenuUL);
	int _x = (GetUpperLeft().Get_x() * 2 + GetWidthAddition()) / 2;
	int _y = GetUpperLeft().Get_y() + 1;
	for (iter = Managers.begin(); iter != Managers.end(); iter++)
	{
		(*iter)->SetUpperLeft(PointCoord(_x, _y));
		_y += ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight();
	}
	return SD;
}
void Menu::ShowIcons()
{
	int left_x = GetUpperLeft().Get_x();
	int top_y = GetUpperLeft().Get_y();
	int right_x = GetUpperLeft().Get_x() + GetWidthAddition();
	int bot_y = GetUpperLeft().Get_x() + GetHeightAddition();
	vector<ConstructionManager*>::iterator iter;
	for (iter = Managers.begin(); iter != Managers.end(); iter++)
	{
		draw_ptr->drawRectangle(left_x + 2, top_y + 1, right_x - 2, top_y + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight(), color::cYELLOW);
		draw_ptr->drawIcon(left_x + 3, top_y + 2, (*iter)->GetDescriptor()->getConstructionCost(), (*iter)->GetDescriptor()->getDailyExpences(),
			(*iter)->GetDescriptor()->getIconSymbol(), (*iter)->GetDescriptor()->getDescription(), color::cGREEN);
		top_y += ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight();
	}
}
void Menu::ShowMenuBorders()
{
	int left_x = GetUpperLeft().Get_x();
	int top_y = GetUpperLeft().Get_y();
	int right_x = GetUpperLeft().Get_x() + ConstructionOptions::GetAllOptions()->GetMenuWidthAdd();
	int bot_y = GetUpperLeft().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuHeightAdd();
	draw_ptr->drawRectangle(left_x, top_y, right_x, bot_y, color::cBLUE);
}
PointCoord Menu::getNearestIconCoords(PointCoord currenticon, IconsPosition ip) //this method returns next upper/lower Icon's coords before/after "currenticon" coord
{
	vector<ConstructionManager*>::iterator iter;
	if (ip == IconsPosition::UPPER)
	{
		PointCoord nearest(currenticon.Get_x(), currenticon.Get_y() - 1000);
		for (iter = Managers.begin(); iter != Managers.end(); iter++)
		{
			if ((*iter)->GetUpperLeft().Get_y() < currenticon.Get_y() && (*iter)->GetUpperLeft().Get_y() > nearest.Get_y())
			{
				nearest = (*iter)->GetUpperLeft();
			}
		}
		return nearest;
	}
	else
	{
		PointCoord nearest(currenticon.Get_x(), currenticon.Get_y() + 1000);
		for (iter = Managers.begin(); iter != Managers.end(); iter++)
		{
			if ((*iter)->GetUpperLeft().Get_y() > currenticon.Get_y() && (*iter)->GetUpperLeft().Get_y() < nearest.Get_y())
			{
				nearest = (*iter)->GetUpperLeft();
			}
		}
		return nearest;
	}
}
void Menu::IconsShift(IconsPosition ip)
{
	vector<ConstructionManager*>::iterator iter;
	if (ip == IconsPosition::UPPER)
	{
		for (iter = Managers.begin(); iter != Managers.end(); iter++)
		{
			PointCoord UL((*iter)->GetUpperLeft().Get_x(), (*iter)->GetUpperLeft().Get_y() - ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight());
			(*iter)->SetUpperLeft(UL);
		}
	}
	else
	{
		for (iter = Managers.begin(); iter != Managers.end(); iter++)
		{
			PointCoord UL((*iter)->GetUpperLeft().Get_x(), (*iter)->GetUpperLeft().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight());
			(*iter)->SetUpperLeft(UL);
		}
	}
}
PointCoord Menu::MenuNavigation(PointCoord currenticon, IconsPosition ip)
{
	PointCoord nearest = getNearestIconCoords(currenticon, ip);
	PointCoord MenuUL = GetUpperLeft();
	unsigned int menu_height = GetHeightAddition();
	unsigned int menu_width = GetWidthAddition();
	if (nearest.Get_y() == currenticon.Get_y() + 1000 || nearest.Get_y() == currenticon.Get_y() - 1000)
	{
		return currenticon;
	}
	else
	{
		if (nearest.Get_y() < camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition())
		{
			draw_ptr->drawRectangle(MenuUL.Get_x() + 2, currenticon.Get_y(), MenuUL.Get_x() + menu_width - 2, currenticon.Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1, color::cYELLOW);
			draw_ptr->drawRectangle(MenuUL.Get_x() + 2, nearest.Get_y(), MenuUL.Get_x() + menu_width - 2, nearest.Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1, color::cGREEN);
			return nearest;
		}
		else
		{
			IconsShift(ip);
			return currenticon;
		}
	}
}
IngameObject* Menu::CreatePreliminaryObject(PointCoord iconpos)
{
	vector<ConstructionManager*>::iterator iter;
	for (iter = Managers.begin(); iter != Managers.end(); iter++)
	{
		if (iconpos == (*iter)->GetUpperLeft())
		{
			int x_coord = (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) / 2;
			int y_coord = (camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition()) / 2;
			Construction* preliminary_ptr = (*iter)->CreateConstruction(PointCoord(x_coord, y_coord));
			return preliminary_ptr;
		}
	}
}
void Menu::EraseMenu()
{
	for (int j = GetUpperLeft().Get_y(); j <= GetUpperLeft().Get_y() + GetHeightAddition(); j++)
	{
		for (int i = GetUpperLeft().Get_x(); i <= GetUpperLeft().Get_x() + GetWidthAddition(); i++)
		{
			draw_ptr->erasePixel(i, j);
		}
	}
}
void Menu::addManager(ConstructionManager* manager_ptr)
{
	Managers.push_back(manager_ptr);
}
ConstructionManager* Menu::getManager(ConstructionDescriptor* cd_ptr)
{
	vector<ConstructionManager*>::iterator iter;
	for (iter = Managers.begin(); iter != Managers.end(); iter++)
	{
		if ((*iter)->GetUpperLeft() == cd_ptr->GetUpperLeft())
		{
			return (*iter);
		}
	}
}