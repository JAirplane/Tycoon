#pragma once
#include "MenuElement.h"
class Menu : public MyRectangle
{
private:
	GameStats* gameStats_ptr;
	vector<MenuElement*> menuItems;
	VisitorManager* visitorsCreator_ptr;
	MenuStatus currentSide;
	bool hidden;
	//
	ConstructionManager* exitManager;
	ConstructionManager* visibleOutsideCameraRoadManager;
	ConstructionManager* unbreakableRoadManager;
	//
	ConstructionManager* CreateManager(PointCoord managerLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChosen);
	ConstructionManager* CreateManager(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChosen, wstring buildingSymbol, int restoreToiletNeed, int satisfactionOfHunger, int visitPrice,
		int enetrtainmentValue, int isExit, int maxVisitors, int visitTime, int dailyExpences = 0, int constructionHeightAdd = 0, int constructionWidthAdd = 0);
public:
	Menu(Visualisation* draw_ptr, Cursor* cursor_ptr, PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* menuBorbder_ptr,
		color letterColor, color shadingColor) : MyRectangle(upperLeft, heightAdd, widthAdd, menuBorbder_ptr, letterColor, shadingColor, draw_ptr, cursor_ptr)
	{
		gameStats_ptr = nullptr;
		visitorsCreator_ptr = nullptr;
		hidden = 0;
		currentSide = MenuStatus::RIGHT;
		exitManager = nullptr;
		visibleOutsideCameraRoadManager = nullptr;
		unbreakableRoadManager = nullptr;
	}
	Menu(MyRectangle* someRectangle) : MyRectangle(someRectangle)
	{
		gameStats_ptr = nullptr;
		visitorsCreator_ptr = nullptr;
		hidden = 0;
		currentSide = MenuStatus::RIGHT;
		exitManager = nullptr;
		visibleOutsideCameraRoadManager = nullptr;
		unbreakableRoadManager = nullptr;
	}
	virtual ~Menu()
	{
		vector<MenuElement*>::iterator elementsIter;
		for (elementsIter = menuItems.begin(); elementsIter != menuItems.end(); elementsIter++)
		{
			delete (*elementsIter);
		}
		delete visitorsCreator_ptr;
		delete gameStats_ptr;
		delete exitManager;
		delete visibleOutsideCameraRoadManager;
		delete unbreakableRoadManager;
	}
	// create road element
	void CreateMenuElement(int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChosen);
	// create building element
	void CreateMenuElement(int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChosen, wstring buildingSymbol, int restoreToiletNeed, int satisfactionOfHunger, int visitPrice,
		int entertainmentValue, int isExit, int maxVisitors, int visitTime, int dailyExpences = 0, int constructionHeightAdd = 0, int constructionWidthAdd = 0);
	// create game stats
	virtual void CreateGameStats();
	virtual void CreateVisitorManager();
	BorderAppearance* CreateElementBorder();
	MyRectangle* CreateIcon(PointCoord elementLocation);
	//
	void CreateExit(const PlayingField* playingField_ptr, const Visualisation* draw_ptr, AllObjects* container);
	void CreateParkEntrance(const PlayingField* playingField_ptr, const Visualisation* draw_ptr, ConstructionDescriptor* descriptor_ptr, AllObjects* container);
	//
	vector<MenuElement*> GetMenuItems() const;
	GameStats* GetGameStats() const;
	VisitorManager* GetVisitorManager() const;
	ConstructionManager* GetExitManager() const;
	ConstructionManager* GetVisibleOutsideCameraRoadManager() const;
	ConstructionManager* GetUnbreakableRoadManager() const;
	MenuStatus GetCurrentSide() const;
	bool GetHideMenuStatus() const;
	void SetHideMenuStatus(bool hideFlag);
	Direction ChangeMenuSide(Camera* camera_ptr);
	void ShowStats() const;
	void UpdateStatsDisplay();
	void ShowMenuItems() const;
	MenuElement* GetMenuElement(int yCoord) const;
	MenuElement* GetUpperVisibleMenuElement() const;
	MenuElement* GetNextMenuElement(MenuElement* currentElement, IconsPosition upperOrLower) const;
	void MenuElementsShift(IconsPosition upperOrLower);
	Construction* CreatePreliminaryObject(AllObjects* allObjects_ptr, Camera* camera_ptr) const;
	Visitor* CreateVisitor(const PlayingField* field_ptr, const Camera* camera_ptr, AllObjects* container_ptr) const;
	void VisitorAddition(const PlayingField* field_ptr, const Camera* camera_ptr, AllObjects* container_ptr) const;
	void MenuElementRedrawBorder(int elementTopY, color newColor);
	MenuElement* MenuNavigation(MenuElement* currentElement, IconsPosition upperOrLower);
	void ParkLevelCheck(const AllObjects* container_ptr);
	int GetLowestEntertainmentVisitPrice() const;
};