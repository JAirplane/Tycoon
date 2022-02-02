#pragma once
#include "MenuElement.h"
#include <vector>
class Menu : public MyRectangle
{
private:
	vector<MenuElement*> menuItems;
	MenuStatus currentSide;
	bool hidden;
	ConstructionManager* CreateManager(PointCoord managerLocation, unsigned int constructionCost, string description, wstring iconSymbol, color foreground, color background);
	ConstructionManager* CreateManager(PointCoord menuElementLocation, int constructionCost, string description, wstring iconSymbol, color foreground, color background,
		wstring buildingSymbol, int dailyExpences = 0, int constructionheightAdd = 0, int constructionwidthAdd = 0);
public:
	Menu(Visualisation* draw_ptr, Cursor* cursor_ptr, PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* menuBorbder_ptr,
		color letterColor, color shadingColor) : MyRectangle(upperLeft, heightAdd, widthAdd, menuBorbder_ptr, letterColor, shadingColor, draw_ptr, cursor_ptr)
	{
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
	void CreateMenuElement(unsigned int constructionCost, string description, wstring iconSymbol, color foreground, color background);
	// create building element
	void CreateMenuElement(int constructionCost, string description, wstring iconSymbol, color foreground, color background,
		wstring buildingSymbol, int dailyExpences = 0, int constructionheightAdd = 0, int constructionwidthAdd = 0);
	BorderAppearance* CreateElementBorder();
	MyRectangle* CreateIcon(PointCoord elementLocation);
	//
	MenuStatus GetCurrentSide() const;
	bool GetHideMenuStatus() const;
	void SetHideMenuStatus(bool hideFlag);
	Direction ChangeMenuSide(Camera* camera_ptr);
	void ShowMenuItems(PointCoord underConstruction = PointCoord(0, 0));
	MenuElement* GetUpperVisibleMenuElement() const;
	MenuElement* GetNextMenuElement(PointCoord currentElement, IconsPosition upperOrLower) const;
	void IconsShift(IconsPosition ip);
	Construction* CreatePreliminaryObject(PointCoord iconPosition, AllObjects* allObjects_ptr) const;
	PointCoord MenuNavigation(PointCoord currentIcon, IconsPosition ip);
	void EraseMenu();
	void AddManager(ConstructionManager* manager_ptr);
	ConstructionManager* GetManager(ConstructionDescriptor* cd_ptr) const;
};