#include "Menu.h"
/////////////Side Menu Class/////////////
bool Menu::IdIsUnique(int newId) const
{
	for (auto everyElement : menuItems)
	{
		if (newId == everyElement->GetManager()->GetDescriptor()->uniqueId)
		{
			return false;
		}
	}
	return true;
}
ConstructionManager* Menu::CreateManager(int descriptorId, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
	color backgroundNotConnected, color backgroundChosen, wstring buildingSymbol, int restoreToiletNeed, int satisfactionOfHunger, int visitPrice,
	int enetrtainmentValue, int isExit, int maxVisitors, int visitTime, int dailyExpences, int constructionHeightAdd, int constructionWidthAdd)
{
	if (IdIsUnique(descriptorId))
	{
		if (restoreToiletNeed == 0 && satisfactionOfHunger == 0 && enetrtainmentValue == 0 && isExit == 0 && visitTime == 0)
		{
			ConstructionDescriptor* roadDesc_ptr = new RoadDescriptor(descriptorId, constructionCost, description, iconSymbol,
				foreground, backgroundConnected, backgroundNotConnected, backgroundChosen);
			return new RoadManager(roadDesc_ptr);
		}
		else
		{
			ConstructionDescriptor* buildingDesc_ptr = new BuildingDescriptor(descriptorId, constructionCost, description, iconSymbol, foreground, backgroundConnected,
				backgroundNotConnected, backgroundChosen, buildingSymbol, restoreToiletNeed, satisfactionOfHunger, visitPrice, enetrtainmentValue, isExit, maxVisitors, visitTime,
				dailyExpences, constructionHeightAdd, constructionWidthAdd);
			return new BuildingManager(buildingDesc_ptr);
		}
	}
	else
	{
		throw MyException("Menu::CreateManager(int descriptorId, int constructionCost, args... descriptorId isn't unique");
	}

}
ConstructionManager* Menu::CreateManager(ConstructionConstantsXML setOfConstants)
{
	if (IdIsUnique(setOfConstants.uniqueId))
	{
		if (setOfConstants.constructionHasToilet == 0 && setOfConstants.constructionSatisfiesHunger == 0 && setOfConstants.constructionIsEntertainment == 0 &&
			setOfConstants.constructionIsExit == 0 && setOfConstants.constructionVisitTime == 0)
		{
			ConstructionDescriptor* roadDesc_ptr = new RoadDescriptor(setOfConstants);
			return new RoadManager(roadDesc_ptr);
		}
		else
		{
			ConstructionDescriptor* buildingDesc_ptr = new BuildingDescriptor(setOfConstants);
			return new BuildingManager(buildingDesc_ptr);
		}
	}
	else
	{
		throw MyException("Menu::CreateManager(ConstructionConstantsXML setOfConstants) descriptorId isn't unique");
	}
}
//
void Menu::CreateMenuElement(int uniqueId, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
	color backgroundNotConnected, color backgroundChosen, wstring buildingSymbol, int restoreToiletNeed, int satisfactionOfHunger, int visitPrice, int entertainmentValue,
	int isExit, int maxVisitors, int visitTime, int dailyExpences, int constructionHeightAdd, int constructionWidthAdd)
{
	PointCoord elementLocation(0, 0);
	if (menuItems.empty())
	{
		if (gameStats_ptr == nullptr)
		{
			throw MyException("Menu::CreateMenuElement(args...) tried to create menu element with gameStats == nullptr");
		}
		elementLocation = PointCoord(GetUpperLeft().Get_x() + 2, gameStats_ptr->GetUpperLeft().Get_y() + gameStats_ptr->GetHeightAddition() + 1);
	}
	else
	{
		elementLocation = PointCoord(GetUpperLeft().Get_x() + 2, menuItems.back()->GetUpperLeft().Get_y() + menuItems.back()->GetHeightAddition() + 1);
	}
	MyRectangle* menuElementRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(elementLocation,
		DTOCollector::GetCollector()->GetFigureConstants("sideMenuElement"), GetDrawPointer(), GetCursor());
	menuElementRectangle->SetWidthAddition(this->GetWidthAddition() - 4);
	MyRectangle* menuIcon_ptr = CreateIcon(elementLocation);
	ConstructionManager* manager_ptr = CreateManager(uniqueId, constructionCost, description, iconSymbol, foreground, backgroundConnected, backgroundNotConnected,
		backgroundChosen, buildingSymbol, restoreToiletNeed, satisfactionOfHunger, visitPrice, entertainmentValue, isExit, maxVisitors, visitTime,
		dailyExpences, constructionHeightAdd, constructionWidthAdd);
	MenuElement* element_ptr = new MenuElement(*menuElementRectangle, menuIcon_ptr, manager_ptr);
	delete menuElementRectangle;
	menuItems.push_back(element_ptr);
}
void Menu::CreateMenuElement(string constructionType)
{
	PointCoord elementLocation(0, 0);
	if (menuItems.empty())
	{
		if (gameStats_ptr == nullptr)
		{
			throw MyException("Menu::CreateMenuElement(args...) tried to create menu element with gameStats == nullptr");
		}
		elementLocation = PointCoord(GetUpperLeft().Get_x() + 2, gameStats_ptr->GetUpperLeft().Get_y() + gameStats_ptr->GetHeightAddition() + 1);
	}
	else
	{
		elementLocation = PointCoord(GetUpperLeft().Get_x() + 2, menuItems.back()->GetUpperLeft().Get_y() + menuItems.back()->GetHeightAddition() + 1);
	}
	MyRectangle* menuElementRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(elementLocation,
		DTOCollector::GetCollector()->GetFigureConstants("sideMenuElement"), GetDrawPointer(), GetCursor());
	menuElementRectangle->SetWidthAddition(this->GetWidthAddition() - 4);
	MyRectangle* menuIcon_ptr = CreateIcon(elementLocation);
	ConstructionManager* manager_ptr = CreateManager(XMLDownloader::GetDownloader()->DownloadConstructionConstants(constructionType));
	MenuElement* element_ptr = new MenuElement(*menuElementRectangle, menuIcon_ptr, manager_ptr);
	delete menuElementRectangle;
	menuItems.push_back(element_ptr);
}
MyRectangle* Menu::CreateIcon(PointCoord elementLocation)
{
	PointCoord iconLocation = PointCoord(elementLocation.Get_x() + 1, elementLocation.Get_y() + 1);
	MyRectangle* newIcon = RectangleCreator::GetRectangleFactory()->CreateRectangle(iconLocation,
		DTOCollector::GetCollector()->GetFigureConstants("menuElementIcon"), this->GetDrawPointer(), this->GetCursor());
	return newIcon;
}
//
void Menu::CreateExit(const PlayingField* playingField_ptr, const Visualisation* draw_ptr, AllObjects* container)
{
	exitManager = this->CreateManager(XMLDownloader::GetDownloader()->DownloadConstructionConstants("exit"));
	Construction* exit1 = exitManager->CreateConstruction(PointCoord(playingField_ptr->GetHalfXAxis(),
		playingField_ptr->GetUpperLeft().Get_y() + playingField_ptr->GetHeightAddition() + 4), draw_ptr, container);
	exit1->SetExitDirection(Direction::Up);
	Construction* exit2 = exitManager->CreateConstruction(PointCoord(playingField_ptr->GetHalfXAxis() + 1,
		playingField_ptr->GetUpperLeft().Get_y() + playingField_ptr->GetHeightAddition() + 4), draw_ptr, container);
	exit2->SetExitDirection(Direction::Up);
	exit1->SetRoadConnectionStatus(true);
	exit2->SetRoadConnectionStatus(true);
}
void Menu::CreateParkEntrance(const PlayingField* playingField_ptr, const Visualisation* draw_ptr, ConstructionDescriptor* descriptor_ptr, AllObjects* container)
{
	if (playingField_ptr == nullptr)
	{
		throw MyException("CreateParkEntrance(const PlayingField* playingField_ptr, ConstructionDescriptor* descriptor_ptr, Visualisation* draw_ptr, AllObjects* container) playingfield is nullptr");
	}
	if (draw_ptr == nullptr)
	{
		throw MyException("CreateParkEntrance(const PlayingField* playingField_ptr, ConstructionDescriptor* descriptor_ptr, Visualisation* draw_ptr, AllObjects* container) draw_ptr is nullptr");
	}
	this->CreateExit(playingField_ptr, draw_ptr, container);
	visibleOutsideCameraRoadManager = new VisibleOutsideRoadManager(descriptor_ptr);
	for (int yAdd = 3; yAdd >= 0; yAdd--)
	{
		for (int xAdd = 0; xAdd <= 1; xAdd++)
		{
			Construction* visibleOutsideCameraRoad = visibleOutsideCameraRoadManager->CreateConstruction(PointCoord(playingField_ptr->GetHalfXAxis() + xAdd,
				playingField_ptr->GetUpperLeft().Get_y() + playingField_ptr->GetHeightAddition() + yAdd), draw_ptr, container);
			visibleOutsideCameraRoad->SetRoadConnectionStatus(true);
		}
	}
	unbreakableRoadManager = new UnbreakableRoadManager(descriptor_ptr);
	for (int xAdd = 0; xAdd <= 1; xAdd++)
	{
		Construction* undestructableRoad = unbreakableRoadManager->CreateConstruction(PointCoord(playingField_ptr->GetHalfXAxis() + xAdd,
			playingField_ptr->GetUpperLeft().Get_y() + playingField_ptr->GetHeightAddition() - 1), draw_ptr, container);
		undestructableRoad->SetRoadConnectionStatus(true);
	}
}
//
void Menu::CreateGameStats()
{
	PointCoord gameStatsLocation = PointCoord(this->GetUpperLeft().Get_x() + 1, this->GetUpperLeft().Get_y() + 1);
	MyRectangle* gameStatsRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(gameStatsLocation,
		DTOCollector::GetCollector()->GetFigureConstants("sideMenuGameStats"), this->GetDrawPointer(), this->GetCursor());
	gameStatsRectangle->SetWidthAddition(this->GetWidthAddition() - 2);
	gameStats_ptr = new GameStats(*gameStatsRectangle);
	delete gameStatsRectangle;
}
void Menu::CreateVisitorManager()
{
	VisitorDescriptor* describe_ptr = new VisitorDescriptor(ConstructionOptions::GetAllOptions()->GetVisitorSymbol(), ConstructionOptions::GetAllOptions()->GetVisitorForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetVisitorBackgroundColor(), ConstructionOptions::GetAllOptions()->GetVisitorHeightAdd(),
		ConstructionOptions::GetAllOptions()->GetVisitorWidthAdd());
	visitorsCreator_ptr = new VisitorManager(describe_ptr);
}
//
GameStats* Menu::GetGameStats() const
{
	return gameStats_ptr;
}
vector<MenuElement*> Menu::GetMenuItems() const
{
	return menuItems;
}
VisitorManager* Menu::GetVisitorManager() const
{
	return visitorsCreator_ptr;
}
ConstructionManager* Menu::GetExitManager() const
{
	return exitManager;
}
ConstructionManager* Menu::GetVisibleOutsideCameraRoadManager() const
{
	return visibleOutsideCameraRoadManager;
}
ConstructionManager* Menu::GetUnbreakableRoadManager() const
{
	return unbreakableRoadManager;
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
		menuUpperLeft = PointCoord(cameraUpperLeft.Get_x() + camera_ptr->GetWidthAddition() + 1, cameraUpperLeft.Get_y());
		shiftDirection = Direction::Left;
	}
	else
	{
		currentSide = MenuStatus::LEFT;
		menuUpperLeft = ConstructionOptions::GetAllOptions()->GetCameraInitialUpperLeft();
		cameraUpperLeft = PointCoord(menuUpperLeft.Get_x() + this->GetWidthAddition() + 1, menuUpperLeft.Get_y());
		shiftDirection = Direction::Right;
	}
	camera_ptr->SetUpperLeft(cameraUpperLeft);
	this->SetUpperLeft(menuUpperLeft);
	gameStats_ptr->SetUpperLeft(PointCoord(this->GetUpperLeft().Get_x() + 1, this->GetUpperLeft().Get_y() + 1));
	int _x = this->GetUpperLeft().Get_x() + 2;
	int _y = gameStats_ptr->GetUpperLeft().Get_y() + gameStats_ptr->GetHeightAddition() + 1;
	if (menuItems.empty())
	{
		throw MyException("Menu::ChangeMenuSide(Camera* camera_ptr) menu elements container is empty.");
	}
	vector<MenuElement*>::iterator menuElementIter;
	for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
	{
		(*menuElementIter)->SetUpperLeft(PointCoord(_x, _y));
		(*menuElementIter)->GetIcon()->SetUpperLeft(PointCoord(_x + 1, _y + 1));
		_y += (*menuElementIter)->GetHeightAddition() + 1;
	}
	return shiftDirection;
}
void Menu::ShowStats() const
{
	gameStats_ptr->DrawBorder();
	gameStats_ptr->DrawContent();
}
void Menu::UpdateStatsDisplay()
{
	if (gameStats_ptr->previousNumberOfVisitors != gameStats_ptr->NumberOfVisitors || gameStats_ptr->previousAmountOfMoney != gameStats_ptr->amountOfMoney)
	{
		gameStats_ptr->ClearContent();
		gameStats_ptr->DrawContent();
		gameStats_ptr->SetPreviousAmountOfMoney();
		gameStats_ptr->SetPreviousVisitorsNumber();
	}
}
void Menu::ShowMenuItems() const
{
	int bottomY = GetUpperLeft().Get_y() + GetHeightAddition();
	if (menuItems.empty())
	{
		throw MyException("Menu::ShowMenuItems() menu elements container is empty.");
	}
	vector<MenuElement*>::const_iterator menuElementIter;
	for (menuElementIter = menuItems.begin(); menuElementIter != menuItems.end(); menuElementIter++)
	{
		if ((*menuElementIter)->GetUpperLeft().Get_y() + (*menuElementIter)->GetHeightAddition() < bottomY &&
			(*menuElementIter)->GetUpperLeft().Get_y() > gameStats_ptr->GetUpperLeft().Get_y() + gameStats_ptr->GetHeightAddition())
		{
			(*menuElementIter)->Draw();
		}
	}
}
MenuElement* Menu::GetMenuElement(int yCoord) const
{
	if (menuItems.empty())
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
MenuElement* Menu::GetMenuElementByDescriptorId(int uniqueID) const
{
	if (menuItems.empty())
	{
		throw MyException("Menu::GetMenuElementByDescriptorId(int uniqueID) const menu elements container is empty.");
	}
	for (auto menuElement : menuItems)
	{
		if (menuElement->GetManager()->GetDescriptor()->uniqueId == uniqueID)
		{
			return menuElement;
		}
	}
	throw MyException("Menu::GetMenuElementByDescriptorId(int uniqueID) const bad ID.");
}
MenuElement* Menu::GetUpperVisibleMenuElement() const
{
	if (menuItems.empty())
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
	if (menuItems.empty())
	{
		throw MyException("Menu::GetNextMenuElement(MenuElement* currentElement, IconsPosition upperOrLower) menu elements container is empty.");
	}
	if (currentElement == nullptr)
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
			if ((*menuElementRIter)->GetUpperLeft().Get_y() > currentElement->GetUpperLeft().Get_y() &&
				(*menuElementRIter)->GetUpperLeft().Get_y() < nearest->GetUpperLeft().Get_y())
			{
				nearest = *menuElementRIter;
			}
		}
		return nearest;
	}
}
void Menu::MenuElementsShift(IconsPosition upperOrLower)
{
	if (menuItems.empty())
	{
		throw MyException("Menu::MenuElementsShift(IconsPosition upperOrLower) menu elements container is empty.");
	}
	for (auto menuElement : menuItems)
	{
		menuElement->Shift(upperOrLower);
	}
}
MenuElement* Menu::MenuNavigation(MenuElement* currentElement, IconsPosition upperOrLower)
{
	MenuElement* nearest = GetNextMenuElement(currentElement, upperOrLower);
	if (nearest == nullptr)
	{
		return nearest;
	}
	else
	{
		currentElement->GetBorder()->SetBorderForegroundColor(currentElement->GetInitialCondition()->foregroundBorderColor);
		nearest->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementActiveColor());
		if (nearest->GetUpperLeft().Get_y() + nearest->GetHeightAddition() >= GetUpperLeft().Get_y() + GetHeightAddition() ||
			nearest->GetUpperLeft().Get_y() <= gameStats_ptr->GetUpperLeft().Get_y() + gameStats_ptr->GetHeightAddition())
		{
			MenuElementsShift(upperOrLower);
			ClearContent();
			ShowStats();
			ShowMenuItems();
		}
		else
		{
			currentElement->DrawBorder();
			nearest->DrawBorder();
		}
		return nearest;
	}
}
void Menu::MenuElementRedrawBorder(MenuElement* element_ptr, string newCondition)
{
	if (hidden)
	{
		if (newCondition == "active")
		{
			element_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementActiveColor());
		}
		else if (newCondition == "inactive")
		{
			element_ptr->GetBorder()->SetBorderForegroundColor(element_ptr->GetInitialCondition()->foregroundBorderColor);
		}
		else if (newCondition == "chosen")
		{
			element_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetMenuElementUnderConstructionColor());
		}
		else
		{
			throw MyException("Menu::MenuElementRedrawBorder(int elementTopY, string newCondition) bad condition");
		}
	}
	else
	{
		if (newCondition == "active")
		{
			element_ptr->RedrawBorder(ConstructionOptions::GetAllOptions()->GetMenuElementActiveColor(), element_ptr->GetInitialCondition()->backgroundBorderColor);
		}
		else if (newCondition == "inactive")
		{
			element_ptr->RedrawBorder(element_ptr->GetInitialCondition()->foregroundBorderColor, element_ptr->GetInitialCondition()->backgroundBorderColor);
		}
		else if (newCondition == "chosen")
		{
			element_ptr->RedrawBorder(ConstructionOptions::GetAllOptions()->GetMenuElementUnderConstructionColor(), element_ptr->GetInitialCondition()->backgroundBorderColor);
		}
		else
		{
			throw MyException("Menu::MenuElementRedrawBorder(int elementTopY, string newCondition) bad condition");
		}
	}
}
Construction* Menu::CreatePreliminaryObject(AllObjects* allObjects_ptr, Camera* camera_ptr) const
{
	if (menuItems.empty())
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
Visitor* Menu::CreateVisitor(const PlayingField* field_ptr, const Camera* camera_ptr, AllObjects* container_ptr) const
{
	if (field_ptr == nullptr)
	{
		throw MyException("Menu::CreateVisitor(const PlayingField* field_ptr, AllObjects* container_ptr) const playingfield is nullptr");
	}
	if (camera_ptr == nullptr)
	{
		throw MyException("Menu::CreateVisitor(const PlayingField* field_ptr, AllObjects* container_ptr) const camera is nullptr");
	}
	if (container_ptr == nullptr)
	{
		throw MyException("Menu::CreateVisitor(const PlayingField* field_ptr, AllObjects* container_ptr) const container_ptr is nullptr");
	}
	int randomX = rand() % 2; //2 possible cells to appear
	int constY = field_ptr->GetUpperLeft().Get_y() + field_ptr->GetHeightAddition() + 3; // 3 pixels lower than playingfield's bottom yCoord
	PointCoord startVisitorPoint(field_ptr->GetHalfXAxis() + randomX, constY);
	Visitor* newVisitor = visitorsCreator_ptr->CreateVisitor(startVisitorPoint, GetDrawPointer(), container_ptr, gameStats_ptr->parkLevel);
	++gameStats_ptr->NumberOfVisitors;
	if (camera_ptr->IsObjectInsideTheRectangle(newVisitor))
	{
		newVisitor->DrawObject();
	}
	return newVisitor;
}
void Menu::ParkLevelCheck(const AllObjects* container_ptr)
{
	int buildingsQuantity = static_cast<int>(container_ptr->GetAllBuildings().size());
	if (buildingsQuantity <= ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(0)->maximumBuildings)
	{
		gameStats_ptr->parkLevel = 0;
	}
	else if (buildingsQuantity <= ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(1)->maximumBuildings)
	{
		gameStats_ptr->parkLevel = 1;
	}
	else if (buildingsQuantity <= ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(2)->maximumBuildings)
	{
		gameStats_ptr->parkLevel = 2;
	}
	else if (buildingsQuantity <= ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(3)->maximumBuildings)
	{
		gameStats_ptr->parkLevel = 3;
	}
	else if (buildingsQuantity <= ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(4)->maximumBuildings)
	{
		gameStats_ptr->parkLevel = 4;
	}
	else
	{
		gameStats_ptr->parkLevel = 5;
	}
}
void Menu::VisitorAddition(const PlayingField* field_ptr, const Camera* camera_ptr, AllObjects* container_ptr) const
{
	switch (gameStats_ptr->parkLevel)
	{
	case 0:
	{
		if (gameStats_ptr->NumberOfVisitors < ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(0)->maximumVisitors)
		{
			CreateVisitor(field_ptr, camera_ptr, container_ptr);
		}
		return;
	}
	case 1:
	{
		if (gameStats_ptr->NumberOfVisitors < ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(1)->maximumVisitors)
		{
			CreateVisitor(field_ptr, camera_ptr, container_ptr);
		}
		return;
	}
	case 2:
	{
		if (gameStats_ptr->NumberOfVisitors < ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(2)->maximumVisitors)
		{
			CreateVisitor(field_ptr, camera_ptr, container_ptr);
		}
		return;
	}
	case 3:
	{
		if (gameStats_ptr->NumberOfVisitors < ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(3)->maximumVisitors)
		{
			CreateVisitor(field_ptr, camera_ptr, container_ptr);
		}
		return;
	}
	case 4:
	{
		if (gameStats_ptr->NumberOfVisitors < ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(4)->maximumVisitors)
		{
			CreateVisitor(field_ptr, camera_ptr, container_ptr);
		}
		return;
	}
	case 5:
	{
		if (gameStats_ptr->NumberOfVisitors < ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(5)->maximumVisitors)
		{
			CreateVisitor(field_ptr, camera_ptr, container_ptr);
		}
		return;
	}
	default: {throw MyException("GameManagement::VisitorCreationCycle(chrono::milliseconds& lastLaunch, chrono::milliseconds& visitorCreationDelay) bad park level"); }
	}
}
int Menu::GetLowestEntertainmentVisitPrice() const
{
	int lowestPrice = numeric_limits<int>::max();
	for (auto menuElement : menuItems)
	{
		if (menuElement->GetManager()->GetDescriptor()->GetEntertainmentValue() != 0)
		{
			int visitPrice = menuElement->GetManager()->GetDescriptor()->GetVisitPrice();
			if (visitPrice < lowestPrice)
			{
				lowestPrice = visitPrice;
			}
		}
	}
	return lowestPrice;
}