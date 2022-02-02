#include "Menu.h"
/////////////Side Menu Class/////////////
//for roads
ConstructionManager* Menu::CreateManager(PointCoord menuElementLocation, unsigned int constructionCost, string description, wstring iconSymbol, color foreground, color background)
{
	ConstructionDescriptor* roadDesc_ptr = new RoadDescriptor(menuElementLocation, constructionCost, description, iconSymbol, foreground, background);
	ConstructionManager* roadManager_ptr = new BuildingManager(GetCursor(), roadDesc_ptr);
}
// for buildings
ConstructionManager* Menu::CreateManager(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color background,
	wstring buildingSymbol, int dailyExpences, int constructionHeightAdd, int constructionWidthAdd) 
{
	ConstructionDescriptor* buildingDesc_ptr = new BuildingDescriptor(menuElementLocation, constructionCost, description, iconSymbol,
		foreground, background, buildingSymbol, dailyExpences, constructionHeightAdd, constructionWidthAdd);
	ConstructionManager* buildingManager_ptr = new BuildingManager(GetCursor(), buildingDesc_ptr);
}
// create road element
void Menu::CreateMenuElement(unsigned int constructionCost, string description, wstring iconSymbol, color foreground, color background)
{
	BorderAppearance* elementBorder_ptr = CreateElementBorder();
	color menuElementLetterColor = ConstructionOptions::GetAllOptions()->GetMenuElementLetterColor();
	color menuElementShadingColor = ConstructionOptions::GetAllOptions()->GetMenuElementShadingColor();
	PointCoord elementLocation(0, 0);
	if (menuItems.empty())
	{
		elementLocation = PointCoord(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 1);
	}
	else
	{
		elementLocation = PointCoord(GetUpperLeft().Get_x() + 2, menuItems.back()->GetUpperLeft().Get_y() + menuItems.back()->GetHeightAddition() + 1);
	}
	int elementHeightAdd = ConstructionOptions::GetAllOptions()->GetMenuElementHeightAdd();
	int elementWidthAdd = GetWidthAddition() - 4;
	MyRectangle* menuIcon_ptr = CreateIcon(elementLocation);
	ConstructionManager* manager_ptr = CreateManager(elementLocation, constructionCost, description, iconSymbol, foreground, background);
	MenuElement* element_ptr = new MenuElement(GetDrawPointer(), GetCursor(), elementLocation, elementHeightAdd, elementWidthAdd, elementBorder_ptr, menuElementLetterColor,
		menuElementShadingColor, menuIcon_ptr, manager_ptr);
	menuItems.push_back(element_ptr);
}
// create building element
void Menu::CreateMenuElement(int constructionCost, string description, wstring iconSymbol, color foreground, color background,
	wstring buildingSymbol, int dailyExpences, int constructionHeightAdd, int constructionWidthAdd)
{
	BorderAppearance* elementBorder_ptr = CreateElementBorder();
	color menuElementLetterColor = ConstructionOptions::GetAllOptions()->GetMenuElementLetterColor();
	color menuElementShadingColor = ConstructionOptions::GetAllOptions()->GetMenuElementShadingColor();
	PointCoord elementLocation(0, 0);
	if (menuItems.empty())
	{
		elementLocation = PointCoord(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 1);
	}
	else
	{
		elementLocation = PointCoord(GetUpperLeft().Get_x() + 2, menuItems.back()->GetUpperLeft().Get_y() + menuItems.back()->GetHeightAddition() + 1);
	}
	int elementHeightAdd = ConstructionOptions::GetAllOptions()->GetMenuElementHeightAdd();
	int elementWidthAdd = GetWidthAddition() - 4;
	MyRectangle* menuIcon_ptr = CreateIcon(elementLocation);
	ConstructionManager* manager_ptr = CreateManager(elementLocation, constructionCost, description, iconSymbol, foreground, background, buildingSymbol,
		dailyExpences, constructionHeightAdd, constructionWidthAdd);
	MenuElement* element_ptr = new MenuElement(GetDrawPointer(), GetCursor(), elementLocation, elementHeightAdd, elementWidthAdd, elementBorder_ptr, menuElementLetterColor,
		menuElementShadingColor, menuIcon_ptr, manager_ptr);
	menuItems.push_back(element_ptr);
}
BorderAppearance* Menu::CreateElementBorder()
{
	RectangleSymbols* elementSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuItemVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuItemHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuItemUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuItemBottomRightSymbol());
	color menuElementBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor();
	color menuElementBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetMenuElementBackgroundColor();
	BorderAppearance* menuElementBorder_ptr = new BorderAppearance(elementSymbols_ptr, menuElementBorderForegroundColor, menuElementBorderBackgroundColor);
	return menuElementBorder_ptr;
}
MyRectangle* Menu::CreateIcon(PointCoord elementLocation)
{
	RectangleSymbols* iconSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuIconVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuIconHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuIconUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuIconUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuIconBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuIconBottomRightSymbol());
	color menuIconBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetMenuIconForegroundColor();
	color menuIconBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetMenuIconBackgroundColor();
	BorderAppearance* menuIconBorder = new BorderAppearance(iconSymbols_ptr, menuIconBorderForegroundColor, menuIconBorderBackgroundColor);
	color menuIconLetterColor = ConstructionOptions::GetAllOptions()->GetMenuIconLetterColor();
	color menuIconShadingColor = ConstructionOptions::GetAllOptions()->GetMenuIconShadingColor();
	//
	PointCoord firstIconLocation = PointCoord(elementLocation.Get_x() + 1, elementLocation.Get_y() + 1);
	int iconHeightAdd = ConstructionOptions::GetAllOptions()->GetMenuIconHeightAdd();
	int iconWidthAdd = ConstructionOptions::GetAllOptions()->GetMenuIconWidthAdd();
	MyRectangle* menuIcon_ptr = new MyRectangle(firstIconLocation, iconHeightAdd, iconWidthAdd, menuIconBorder,
		menuIconLetterColor, menuIconShadingColor, GetDrawPointer(), GetCursor());
	return menuIcon_ptr;
}
MenuStatus Menu::GetCurrentSide() const
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
Direction Menu::ChangeMenuSide(Camera* camera_ptr)
{
	vector<MenuElement*>::iterator menuElementIter;
	Direction shiftDirection;
	PointCoord cameraUpperLeft, menuUpperLeft;
	if (currentSide == MenuStatus::LEFT)
	{
		currentSide = MenuStatus::RIGHT;
		cameraUpperLeft = ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft();
		int cameraWidthAdd = camera_ptr->GetWidthAddition();
		menuUpperLeft = PointCoord(cameraUpperLeft.Get_x() + cameraWidthAdd + 1, cameraUpperLeft.Get_y());
		shiftDirection = Direction::Left;
	}
	else
	{
		currentSide = MenuStatus::LEFT;
		menuUpperLeft = ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft();
		int menuWidthAdd = GetWidthAddition();
		cameraUpperLeft = PointCoord(menuUpperLeft.Get_x() + menuWidthAdd + 1, menuUpperLeft.Get_y());
		shiftDirection = Direction::Right;
	}
	camera_ptr->SetUpperLeft(cameraUpperLeft);
	SetUpperLeft(menuUpperLeft);
	int _x = GetUpperLeft().Get_x() + 2;
	int _y = GetUpperLeft().Get_y() + 1;
	for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
	{
		(*menuElementIter)->SetUpperLeft(PointCoord(_x, _y));
		(*menuElementIter)->GetIcon()->SetUpperLeft(PointCoord(_x + 1, _y + 1));
		(*menuElementIter)->GetManager()->GetDescriptor()->SetMenuElementLocation(PointCoord(_x, _y));
		_y += ConstructionOptions::GetAllOptions()->GetMenuElementHeightAdd() + 1;
	}
	return shiftDirection;
}
void Menu::ShowMenuItems(PointCoord underConstruction)
{
	int leftX = GetUpperLeft().Get_x();
	int topY = GetUpperLeft().Get_y();
	int rightX = GetUpperLeft().Get_x() + GetWidthAddition();
	int bottomY = GetUpperLeft().Get_x() + GetHeightAddition();
	vector<MenuElement*>::iterator menuElementIter;
	for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end() && (topY + (*menuElementIter)->GetHeightAddition()) < bottomY; menuElementIter++)
	{
		(*menuElementIter)->DrawBorder();
		(*menuElementIter)->GetIcon()->DrawBorder();
		(*menuElementIter)->GetDrawPointer()->DrawMenuElementContent((*menuElementIter)->GetIcon()->GetUpperLeft().Get_x() + 1,
			(*menuElementIter)->GetIcon()->GetUpperLeft().Get_y() + 1, (*menuElementIter)->GetManager()->GetDescriptor()->GetConstructionCost(),
			(*menuElementIter)->GetManager()->GetDescriptor()->GetDailyExpences(), (*menuElementIter)->GetManager()->GetDescriptor()->GetIconSymbol(),
			(*menuElementIter)->GetManager()->GetDescriptor()->GetDescription(), (*menuElementIter)->GetManager()->GetDescriptor()->GetForegroundColor(),
			(*menuElementIter)->GetManager()->GetDescriptor()->GetBackgroundColor());
		topY += (*menuElementIter)->GetHeightAddition() + 1;
	}
	GetCursor()->CursorMovement(GetCursor()->GetCursorConsoleLocation());
}
MenuElement* Menu::GetUpperVisibleMenuElement() const
{
	vector<MenuElement*>::const_iterator menuElementIter;
	for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
	{
		if ((*menuElementIter)->GetUpperLeft().Get_y() > GetUpperLeft().Get_y())
		{
			return (*menuElementIter);
		}
	}
}
//this method returns next upper/lower menu element before/after "currentIcon" coord
MenuElement* Menu::GetNextMenuElement(PointCoord currentElement, IconsPosition upperOrLower) const
{
	MenuElement* nearest = nullptr;
	if (upperOrLower == IconsPosition::UPPER)
	{
		if (menuItems.front()->GetUpperLeft().Get_y() < currentElement.Get_y())
		{
			nearest = menuItems.front();
		}
		else
		{
			return nearest;
		}
		vector<MenuElement*>::const_iterator menuElementIter;
		for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
		{
			if ((*menuElementIter)->GetUpperLeft().Get_y() < currentElement.Get_y() && (*menuElementIter)->GetUpperLeft().Get_y() > nearest->GetUpperLeft().Get_y())
			{
				nearest = *menuElementIter;
			}
		}
		return nearest;
	}
	else
	{
		if (menuItems.back()->GetUpperLeft().Get_y() > currentElement.Get_y())
		{
			nearest = menuItems.back();
		}
		else
		{
			return nearest;
		}
		vector<MenuElement*>::const_reverse_iterator menuElementRIter;
		for (menuElementRIter = menuItems.rbegin(); menuElementRIter != menuItems.rend(); menuElementRIter++)
		{
			if ((*menuElementRIter)->GetUpperLeft().Get_y() > currentElement.Get_y() && (*menuElementRIter)->GetUpperLeft().Get_y() < nearest->GetUpperLeft().Get_y())
			{
				nearest = *menuElementRIter;
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
				itemBorderSymbols_ptr->GetVerticalSymbol(), itemBorderSymbols_ptr->GetHorizontalSymbol(), itemBorderSymbols_ptr->GetUpperLeftSymbol(), itemBorderSymbols_ptr->GetUpperRightSymbol(),
				itemBorderSymbols_ptr->GetBottomLeftSymbol(), itemBorderSymbols_ptr->GetBottomRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemInactiveColor());
			draw_ptr->DrawRectangle(menuUpperLeft.Get_x() + 2, nearest.Get_y(), menuUpperLeft.Get_x() + menuWidth - 2, nearest.Get_y() + ConstructionOptions::GetAllOptions()->GetMenuElementBordersHeight() - 1,
				itemBorderSymbols_ptr->GetVerticalSymbol(), itemBorderSymbols_ptr->GetHorizontalSymbol(), itemBorderSymbols_ptr->GetUpperLeftSymbol(), itemBorderSymbols_ptr->GetUpperRightSymbol(),
				itemBorderSymbols_ptr->GetBottomLeftSymbol(), itemBorderSymbols_ptr->GetBottomRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemActiveColor());
			return nearest;
		}
		else
		{
			IconsShift(ip);
			return currentIcon;
		}
	}
}
Construction* Menu::CreatePreliminaryObject(PointCoord iconPosition, AllObjects* allObjects_ptr) const
{
	vector<ConstructionManager*>::const_iterator iter;
	for (iter = managers.begin(); iter != managers.end(); iter++)
	{
		if (iconPosition == (*iter)->GetUpperLeft())
		{
			int xCoord = (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) / 2;
			int yCoord = (camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition()) / 2;
			Construction* preliminary_ptr = (*iter)->CreatePreliminaryConstruction(PointCoord(xCoord, yCoord), draw_ptr, allObjects_ptr);
			return preliminary_ptr;
		}
	}
	return nullptr;
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
	vector<ConstructionManager*>::const_iterator iter;
	for (iter = managers.begin(); iter != managers.end(); iter++)
	{
		if ((*iter)->GetUpperLeft() == cd_ptr->GetManagerLocation())
		{
			return (*iter);
		}
	}
	return nullptr;
}