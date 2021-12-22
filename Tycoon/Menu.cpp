#include "Menu.h"
/////////////Side Menu Class/////////////
MenuStatus Menu::GetCurrentSide()
{
	return currentSide;
}
bool Menu::GetHideMenuStatus() const
{
	return hidden;
}
void Menu::SetHideMenuStatus(bool hideFlag)
{
	hidden = hideFlag;
}
Direction Menu::ChangeMenuSide()
{
	vector<ConstructionManager*>::iterator iter;
	Direction shiftDirection;
	PointCoord upperLeft, menuUpperLeft;
	if (currentSide == MenuStatus::LEFT)
	{
		currentSide = MenuStatus::RIGHT;
		upperLeft = ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft();
		unsigned int widthAdd = camera_ptr->GetWidthAddition();
		menuUpperLeft = PointCoord(upperLeft.Get_x() + widthAdd + 1, upperLeft.Get_y());
		shiftDirection = Direction::Left;
	}
	else
	{
		currentSide = MenuStatus::LEFT;
		menuUpperLeft = ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft();
		unsigned int menuWidthAdd = GetWidthAddition();
		upperLeft = PointCoord(menuUpperLeft.Get_x() + menuWidthAdd + 1, menuUpperLeft.Get_y());
		shiftDirection = Direction::Right;
	}
	camera_ptr->SetUpperLeft(upperLeft);
	SetUpperLeft(menuUpperLeft);
	int _x = (GetUpperLeft().Get_x() * 2 + GetWidthAddition()) / 2;
	int _y = GetUpperLeft().Get_y() + 1;
	for (iter = managers.begin(); iter != managers.end(); iter++)
	{
		(*iter)->SetUpperLeft(PointCoord(_x, _y));
		_y += ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight();
	}
	return shiftDirection;
}
void Menu::ShowMenuItems()
{
	int leftX = GetUpperLeft().Get_x();
	int topY = GetUpperLeft().Get_y();
	int rightX = GetUpperLeft().Get_x() + GetWidthAddition();
	int bottomY = GetUpperLeft().Get_x() + GetHeightAddition();
	vector<ConstructionManager*>::iterator iter;
	for (iter = managers.begin(); iter != managers.end() && (topY + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight()) < bottomY; iter++)
	{
		draw_ptr->DrawRectangle(leftX + 2, topY + 1, rightX - 2, topY + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight(),
			itemBorderSymbols_ptr->GetVerticalSymbol(), itemBorderSymbols_ptr->GetHorizontalSymbol(), itemBorderSymbols_ptr->GetUpperLeftSymbol(),
			itemBorderSymbols_ptr->GetUpperRightSymbol(), itemBorderSymbols_ptr->GetBottomLeftSymbol(), itemBorderSymbols_ptr->GetBottomRightSymbol(),
			itemBorderSymbols_ptr->GetForegroundColor());
		draw_ptr->DrawIcon(leftX + 3, topY + 2, iconBorderSymbols_ptr->GetVerticalSymbol(), iconBorderSymbols_ptr->GetHorizontalSymbol(),
			iconBorderSymbols_ptr->GetUpperLeftSymbol(), iconBorderSymbols_ptr->GetUpperRightSymbol(), iconBorderSymbols_ptr->GetBottomLeftSymbol(),
			iconBorderSymbols_ptr->GetBottomRightSymbol(), (*iter)->GetDescriptor()->GetConstructionCost(), (*iter)->GetDescriptor()->GetDailyExpences(), (*iter)->GetDescriptor()->GetIconSymbol(),
			(*iter)->GetDescriptor()->GetDescription(), (*iter)->GetDescriptor()->GetForegroundColor(), (*iter)->GetDescriptor()->GetBackgroundColor(), iconBorderSymbols_ptr->GetForegroundColor());
		topY += ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight();
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void Menu::ShowMenuBorders()
{
	int leftX = GetUpperLeft().Get_x();
	int topY = GetUpperLeft().Get_y();
	int rightX = GetUpperLeft().Get_x() + ConstructionOptions::GetAllOptions()->GetMenuWidthAdd();
	int bottomY = GetUpperLeft().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuHeightAdd();
	draw_ptr->DrawRectangle(leftX, topY, rightX, bottomY, menuBorderSymbols_ptr->GetVerticalSymbol(), menuBorderSymbols_ptr->GetHorizontalSymbol(),
		menuBorderSymbols_ptr->GetUpperLeftSymbol(), menuBorderSymbols_ptr->GetUpperRightSymbol(), menuBorderSymbols_ptr->GetBottomLeftSymbol(),
		menuBorderSymbols_ptr->GetBottomRightSymbol(), menuBorderSymbols_ptr->GetMenuColor());
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
PointCoord Menu::GetNearestIconCoords(PointCoord currentIcon, IconsPosition ip) //this method returns next upper/lower Icon's coords before/after "currentIcon" coord
{
	vector<ConstructionManager*>::iterator iter;
	if (ip == IconsPosition::UPPER)
	{
		PointCoord nearest(currentIcon.Get_x(), currentIcon.Get_y() - 1000);
		for (iter = managers.begin(); iter != managers.end(); iter++)
		{
			if ((*iter)->GetUpperLeft().Get_y() < currentIcon.Get_y() && (*iter)->GetUpperLeft().Get_y() > nearest.Get_y())
			{
				nearest = (*iter)->GetUpperLeft();
			}
		}
		return nearest;
	}
	else
	{
		PointCoord nearest(currentIcon.Get_x(), currentIcon.Get_y() + 1000);
		for (iter = managers.begin(); iter != managers.end(); iter++)
		{
			if ((*iter)->GetUpperLeft().Get_y() > currentIcon.Get_y() && (*iter)->GetUpperLeft().Get_y() < nearest.Get_y())
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
		for (iter = managers.begin(); iter != managers.end(); iter++)
		{
			PointCoord upperLeft((*iter)->GetUpperLeft().Get_x(), (*iter)->GetUpperLeft().Get_y() - ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight());
			(*iter)->SetUpperLeft(upperLeft);
		}
	}
	else
	{
		for (iter = managers.begin(); iter != managers.end(); iter++)
		{
			PointCoord upperLeft((*iter)->GetUpperLeft().Get_x(), (*iter)->GetUpperLeft().Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight());
			(*iter)->SetUpperLeft(upperLeft);
		}
	}
}
PointCoord Menu::MenuNavigation(PointCoord currentIcon, IconsPosition ip)
{
	PointCoord nearest = GetNearestIconCoords(currentIcon, ip);
	PointCoord menuUpperLeft = GetUpperLeft();
	unsigned int menuHeight = GetHeightAddition();
	unsigned int menuWidth = GetWidthAddition();
	if (nearest.Get_y() == currentIcon.Get_y() + 1000 || nearest.Get_y() == currentIcon.Get_y() - 1000)
	{
		return currentIcon;
	}
	else
	{
		if (nearest.Get_y() < camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition())
		{
			draw_ptr->DrawRectangle(menuUpperLeft.Get_x() + 2, currentIcon.Get_y(), menuUpperLeft.Get_x() + menuWidth - 2, currentIcon.Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1,
				ConstructionOptions::GetAllOptions()->GetMenuItemVerticalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemHorizontalSymbol(),
				ConstructionOptions::GetAllOptions()->GetMenuItemUpperLeftSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemUpperRightSymbol(),
				ConstructionOptions::GetAllOptions()->GetMenuItemBottomLeftSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemBottomRightSymbol(),
				ConstructionOptions::GetAllOptions()->GetMenuItemInactiveColor());
			draw_ptr->DrawRectangle(menuUpperLeft.Get_x() + 2, nearest.Get_y(), menuUpperLeft.Get_x() + menuWidth - 2, nearest.Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1,
				ConstructionOptions::GetAllOptions()->GetMenuItemVerticalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemHorizontalSymbol(),
				ConstructionOptions::GetAllOptions()->GetMenuItemUpperLeftSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemUpperRightSymbol(),
				ConstructionOptions::GetAllOptions()->GetMenuItemBottomLeftSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemBottomRightSymbol(),
				ConstructionOptions::GetAllOptions()->GetMenuItemActiveColor());
			return nearest;
		}
		else
		{
			IconsShift(ip);
			return currentIcon;
		}
	}
}
Construction* Menu::CreatePreliminaryObject(PointCoord iconPosition)
{
	vector<ConstructionManager*>::iterator iter;
	for (iter = managers.begin(); iter != managers.end(); iter++)
	{
		if (iconPosition == (*iter)->GetUpperLeft())
		{
			int xCoord = (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) / 2;
			int yCoord = (camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition()) / 2;
			Construction* preliminary_ptr = (*iter)->CreateConstruction(PointCoord(xCoord, yCoord));
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
			draw_ptr->ErasePixel(i, j);
		}
	}
}
void Menu::AddManager(ConstructionManager* manager_ptr)
{
	managers.push_back(manager_ptr);
}
ConstructionManager* Menu::GetManager(ConstructionDescriptor* cd_ptr) const
{
	vector<ConstructionManager*>::iterator iter;
	for (iter = managers.begin(); iter != managers.end(); iter++)
	{
		if ((*iter)->GetUpperLeft() == cd_ptr->GetUpperLeft())
		{
			return (*iter);
		}
	}
}
RectangleSymbols* Menu::GetMenuSymbols() const
{
	return menuBorderSymbols_ptr;
}
RectangleSymbols* Menu::GetItemSymbols() const
{
	return itemBorderSymbols_ptr;
}
RectangleSymbols* Menu::GetIconSymbols() const
{
	return iconBorderSymbols_ptr;
}