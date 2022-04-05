#pragma once
#include "GameStats.h"
class Menu : public MyRectangle
{
private:
	GameStats* gameStats_ptr;
	vector<MenuElement*> menuItems;
	VisitorManager* visitorsCreator_ptr;
	MenuStatus currentSide;
	bool hidden;
	ConstructionManager* CreateManager(PointCoord managerLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChosen);
	ConstructionManager* CreateManager(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChosen, wstring buildingSymbol, bool restoreToiletNeed, int satisfactionOfHunger, int visitPrice,
		int dailyExpences = 0, int constructionheightAdd = 0, int constructionwidthAdd = 0);
public:
	Menu(Visualisation* draw_ptr, Cursor* cursor_ptr, PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* menuBorbder_ptr,
		color letterColor, color shadingColor) : MyRectangle(upperLeft, heightAdd, widthAdd, menuBorbder_ptr, letterColor, shadingColor, draw_ptr, cursor_ptr)
	{
		gameStats_ptr = nullptr;
		visitorsCreator_ptr = nullptr;
		hidden = 0;
		currentSide = MenuStatus::RIGHT;
	}
	~Menu()
	{
		vector<MenuElement*>::iterator elementsIter;
		for (elementsIter = menuItems.begin(); elementsIter != menuItems.end(); elementsIter++)
		{
			delete (*elementsIter);
		}
	}
	// create road element
	void CreateMenuElement(int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChosen);
	// create building element
	void CreateMenuElement(int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChosen, wstring buildingSymbol, bool restoreToiletNeed, int satisfactionOfHunger, int visitPrice,
		int dailyExpences = 0, int constructionheightAdd = 0, int constructionwidthAdd = 0);
	// create game stats
	virtual void CreateGameStats();
	virtual void CreateVisitorManager();
	BorderAppearance* CreateElementBorder();
	MyRectangle* CreateIcon(PointCoord elementLocation);
	//
	vector<MenuElement*> GetMenuItems() const;
	GameStats* GetGameStats() const;
	VisitorManager* GetVisitorManager() const;
	MenuStatus GetCurrentSide() const;
	bool GetHideMenuStatus() const;
	void SetHideMenuStatus(bool hideFlag);
	Direction ChangeMenuSide(Camera* camera_ptr);
	void ShowStats();
	void ShowMenuItems();
	MenuElement* GetMenuElement(int yCoord) const;
	MenuElement* GetUpperVisibleMenuElement() const;
	MenuElement* GetNextMenuElement(MenuElement* currentElement, IconsPosition upperOrLower) const;
	void MenuElementsShift(IconsPosition upperOrLower);
	Construction* CreatePreliminaryObject(AllObjects* allObjects_ptr, Camera* camera_ptr) const;
	Visitor* CreateVisitor(const PlayingField* field_ptr, AllObjects* container_ptr) const;
	void MenuElementRedrawBorder(int elementTopY, color newColor);
	MenuElement* MenuNavigation(MenuElement* currentElement, IconsPosition upperOrLower);
	void ParkLevelCheck(const AllObjects* container_ptr);
};