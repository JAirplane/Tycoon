#include "Menu.h"
/////////////Side Menu Class/////////////
//for roads
ConstructionManager* Menu::CreateManager(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
	color backgroundNotConnected, color backgroundChosen)
{
	ConstructionDescriptor* roadDesc_ptr = new RoadDescriptor(menuElementLocation, constructionCost, description, iconSymbol,
		foreground, backgroundConnected, backgroundNotConnected, backgroundChosen);
	return new RoadManager(GetCursor(), roadDesc_ptr);
}
// for buildings
ConstructionManager* Menu::CreateManager(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
	color backgroundNotConnected, color backgroundChosen, wstring buildingSymbol, int dailyExpences, int constructionHeightAdd, int constructionWidthAdd)
{
	ConstructionDescriptor* buildingDesc_ptr = new BuildingDescriptor(menuElementLocation, constructionCost, description, iconSymbol,
		foreground, backgroundConnected, backgroundNotConnected, backgroundChosen, buildingSymbol, dailyExpences, constructionHeightAdd, constructionWidthAdd);
	return new BuildingManager(GetCursor(), buildingDesc_ptr);
}
// create road element
void Menu::CreateMenuElement(int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
	color backgroundNotConnected, color backgroundChosen)
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
	ConstructionManager* manager_ptr = CreateManager(elementLocation, constructionCost, description, iconSymbol, foreground, backgroundConnected, backgroundNotConnected,
		backgroundChosen);
	MenuElement* element_ptr = new MenuElement(GetDrawPointer(), GetCursor(), elementLocation, elementHeightAdd, elementWidthAdd, elementBorder_ptr, menuElementLetterColor,
		menuElementShadingColor, menuIcon_ptr, manager_ptr);
	menuItems.push_back(element_ptr);
}
// create building element
void Menu::CreateMenuElement(int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
	color backgroundNotConnected, color backgroundChosen, wstring buildingSymbol, int dailyExpences, int constructionHeightAdd, int constructionWidthAdd)
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
	ConstructionManager* manager_ptr = CreateManager(elementLocation, constructionCost, description, iconSymbol, foreground, backgroundConnected, backgroundNotConnected,
		backgroundChosen, buildingSymbol, dailyExpences, constructionHeightAdd, constructionWidthAdd);
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
	if(menuItems.empty())
	{
		throw MyException("Menu::ChangeMenuSide(Camera* camera_ptr) menu elements container is empty.");
	}
	vector<MenuElement*>::iterator menuElementIter;
	for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
	{
		(*menuElementIter)->SetUpperLeft(PointCoord(_x, _y));
		(*menuElementIter)->GetIcon()->SetUpperLeft(PointCoord(_x + 1, _y + 1));
		(*menuElementIter)->GetManager()->GetDescriptor()->SetMenuElementLocation(PointCoord(_x, _y));
		_y += ConstructionOptions::GetAllOptions()->GetMenuElementHeightAdd() + 1;
	}
	return shiftDirection;
}
void Menu::ShowMenuItems()
{
	int leftX = GetUpperLeft().Get_x();
	int topY = GetUpperLeft().Get_y();
	int rightX = GetUpperLeft().Get_x() + GetWidthAddition();
	int bottomY = GetUpperLeft().Get_x() + GetHeightAddition();
	if(menuItems.empty())
	{
		throw MyException("Menu::ShowMenuItems() menu elements container is empty.");
	}
	vector<MenuElement*>::iterator menuElementIter;
	for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end() && (topY + (*menuElementIter)->GetHeightAddition()) < bottomY; menuElementIter++)
	{
		(*menuElementIter)->DrawBorder();
		(*menuElementIter)->GetIcon()->DrawBorder();
		(*menuElementIter)->GetDrawPointer()->DrawMenuElementContent((*menuElementIter)->GetIcon()->GetUpperLeft().Get_x() + 1,
			(*menuElementIter)->GetIcon()->GetUpperLeft().Get_y() + 1, (*menuElementIter)->GetManager()->GetDescriptor()->GetConstructionCost(),
			(*menuElementIter)->GetManager()->GetDescriptor()->GetDailyExpences(), (*menuElementIter)->GetManager()->GetDescriptor()->GetIconSymbol(),
			(*menuElementIter)->GetManager()->GetDescriptor()->GetDescription(), (*menuElementIter)->GetManager()->GetDescriptor()->GetForegroundColor(),
			(*menuElementIter)->GetManager()->GetDescriptor()->GetConnectedBackgroundColor());
		topY += (*menuElementIter)->GetHeightAddition() + 1;
	}
}
MenuElement* Menu::GetMenuElement(int yCoord) const
{
	if(menuItems.empty())
	{
		throw MyException("Menu::GetMenuElement(int yCoord) menu elements container is empty.");
	}
	vector<MenuElement*>::const_iterator menuElementIter;
	for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
	{
		if ((*menuElementIter)->GetUpperLeft().Get_y() == yCoord)
		{
			return (*menuElementIter);
		}
	}
	throw MyException("Menu::GetMenuElement(int yCoord) no menu element at this location.");
}
MenuElement* Menu::GetUpperVisibleMenuElement() const
{
	if(menuItems.empty())
	{
		throw MyException("Menu::GetUpperVisibleMenuElement() menu elements container is empty.");
	}
	vector<MenuElement*>::const_iterator menuElementIter;
	for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
	{
		if ((*menuElementIter)->GetUpperLeft().Get_y() > GetUpperLeft().Get_y())
		{
			return (*menuElementIter);
		}
	}
	return nullptr;
}
//this method returns next upper/lower menu element before/after "currentIcon" coord
MenuElement* Menu::GetNextMenuElement(MenuElement* currentElement, IconsPosition upperOrLower) const
{
	if(menuItems.empty())
	{
		throw MyException("Menu::GetNextMenuElement(MenuElement* currentElement, IconsPosition upperOrLower) menu elements container is empty.");
	}
	if(currentElement == nullptr)
	{
		throw MyException("Menu::GetNextMenuElement(MenuElement* currentElement, IconsPosition upperOrLower) currentElement is nullptr.");
	}
	MenuElement* nearest = nullptr;
	if (upperOrLower == IconsPosition::UPPER)
	{
		if (menuItems.front()->GetUpperLeft().Get_y() < currentElement->GetUpperLeft().Get_y())
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
			if ((*menuElementIter)->GetUpperLeft().Get_y() < currentElement->GetUpperLeft().Get_y() && (*menuElementIter)->GetUpperLeft().Get_y() > nearest->GetUpperLeft().Get_y())
			{
				nearest = *menuElementIter;
			}
		}
		return nearest;
	}
	else
	{
		if (menuItems.back()->GetUpperLeft().Get_y() > currentElement->GetUpperLeft().Get_y())
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
			if ((*menuElementRIter)->GetUpperLeft().Get_y() > currentElement->GetUpperLeft().Get_y() && (*menuElementRIter)->GetUpperLeft().Get_y() < nearest->GetUpperLeft().Get_y())
			{
				nearest = *menuElementRIter;
			}
		}
		return nearest;
	}
}
void Menu::MenuElementsShift(IconsPosition upperOrLower)
{
	if(menuItems.empty())
	{
		throw MyException("Menu::MenuElementsShift(IconsPosition upperOrLower) menu elements container is empty.");
	}
	vector<MenuElement*>::iterator menuElementIter;
	switch (upperOrLower)
	{
	case IconsPosition::UPPER:
	{
		for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
		{
			(*menuElementIter)->SetUpperLeft(PointCoord((*menuElementIter)->GetUpperLeft().Get_x(),
				(*menuElementIter)->GetUpperLeft().Get_y() + (*menuElementIter)->GetHeightAddition() + 1));
			(*menuElementIter)->GetIcon()->SetUpperLeft(PointCoord((*menuElementIter)->GetUpperLeft().Get_x() + 1,
				(*menuElementIter)->GetUpperLeft().Get_y() + (*menuElementIter)->GetHeightAddition() + 2));
			(*menuElementIter)->GetManager()->GetDescriptor()->SetMenuElementLocation(PointCoord((*menuElementIter)->GetUpperLeft().Get_x(),
				(*menuElementIter)->GetUpperLeft().Get_y() + (*menuElementIter)->GetHeightAddition() + 1));
		}
	}
	case IconsPosition::LOWER:
	{
		for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
		{
			(*menuElementIter)->SetUpperLeft(PointCoord((*menuElementIter)->GetUpperLeft().Get_x(),
				(*menuElementIter)->GetUpperLeft().Get_y() - (*menuElementIter)->GetHeightAddition() - 1));
			(*menuElementIter)->GetIcon()->SetUpperLeft(PointCoord((*menuElementIter)->GetUpperLeft().Get_x() + 1,
				(*menuElementIter)->GetUpperLeft().Get_y() - (*menuElementIter)->GetHeightAddition()));
			(*menuElementIter)->GetManager()->GetDescriptor()->SetMenuElementLocation(PointCoord((*menuElementIter)->GetUpperLeft().Get_x(),
				(*menuElementIter)->GetUpperLeft().Get_y() - (*menuElementIter)->GetHeightAddition() - 1));
		}
	}
	default: {throw MyException("Menu::MenuElementsShift(IconsPosition upperOrLower) bas IconsPosition argument."); }
	}
}
MenuElement* Menu::MenuNavigation(MenuElement* currentElement, IconsPosition upperOrLower)
{
	MenuElement* nearest = GetNextMenuElement(currentElement, upperOrLower);
	PointCoord menuUpperLeft = GetUpperLeft();
	int menuHeight = GetHeightAddition();
	int menuWidth = GetWidthAddition();
	if (nearest == nullptr)
	{
		return nearest;
	}
	else
	{
		currentElement->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor());
		nearest->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementActiveColor());
		if (nearest->GetUpperLeft().Get_y() + nearest->GetHeightAddition() < GetUpperLeft().Get_y() + GetHeightAddition() ||
			nearest->GetUpperLeft().Get_y() > GetUpperLeft().Get_y())
		{
			currentElement->DrawBorder();
			nearest->DrawBorder();
		}
		else
		{
			MenuElementsShift(upperOrLower);
			ClearContent();
			ShowMenuItems();
		}
		return nearest;
	}
}
void Menu::MenuElementRedrawBorder(int elementTopY, color newColor)
{
	MenuElement* element_ptr = GetMenuElement(elementTopY);
	element_ptr->GetBorder()->SetBorderForegroundColor(newColor);
	if (!hidden)
	{
		element_ptr->DrawBorder();
	}
}
Construction* Menu::CreatePreliminaryObject(AllObjects* allObjects_ptr, Camera* camera_ptr) const
{
	if(menuItems.empty())
	{
		throw MyException("Menu::MenuElementsShift(IconsPosition upperOrLower) menu elements container is empty.");
	}
	vector<MenuElement*>::const_iterator menuElementIter;
	for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
	{
		if (GetCursor()->GetCursorConsoleLocation().Get_y() == (*menuElementIter)->GetUpperLeft().Get_y())
		{
			int xCoord = (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) / 2;
			int yCoord = (camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition()) / 2;
			Construction* preliminary_ptr = (*menuElementIter)->GetManager()->CreatePreliminaryConstruction(PointCoord(xCoord, yCoord), GetDrawPointer(), allObjects_ptr);
			return preliminary_ptr;
		}
	}
	return nullptr;
}