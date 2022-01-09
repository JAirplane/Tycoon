#pragma once
#include "ManagersDerived.h"
#include <vector>
class Menu : public GlobalObject
{
private:
	Visualisation* draw_ptr;
	Camera* camera_ptr;
	Cursor* cursor_ptr;
	RectangleSymbols* menuBorderSymbols_ptr;
	RectangleSymbols* itemBorderSymbols_ptr;
	RectangleSymbols* iconBorderSymbols_ptr;
	vector<ConstructionManager*> managers;
	MenuStatus currentSide;
	bool hidden;
public:
	Menu(Visualisation* drawptr, Camera* vmptr, Cursor* cursorptr, PointCoord upperLeft, RectangleSymbols* menuSymbols_ptr, RectangleSymbols* itemSymbols_ptr,
		RectangleSymbols* iconSymbols_ptr, int heightAdd, int widthAdd) : GlobalObject(upperLeft, heightAdd, widthAdd), draw_ptr(drawptr), camera_ptr(vmptr), cursor_ptr(cursorptr)
	{
		menuBorderSymbols_ptr = menuSymbols_ptr;
		itemBorderSymbols_ptr = itemSymbols_ptr;
		iconBorderSymbols_ptr = iconSymbols_ptr;
		hidden = 0;
		currentSide = MenuStatus::RIGHT;
	}
	~Menu()
	{
		vector<ConstructionManager*>::iterator iter;
		for (iter = managers.begin(); iter != managers.end(); iter++)
		{
			delete (*iter);
		}
		delete menuBorderSymbols_ptr;
		delete itemBorderSymbols_ptr;
		delete iconBorderSymbols_ptr;
	}
	bool GetHideMenuStatus() const;
	void SetHideMenuStatus(bool hideFlag);
	MenuStatus GetCurrentSide();
	Direction ChangeMenuSide();
	void ShowMenuItems(PointCoord underConstruction = PointCoord(0, 0));
	void ShowMenuBorders();
	PointCoord GetNearestIconCoords(PointCoord currentIcon, IconsPosition ip);
	void IconsShift(IconsPosition ip);
	Construction* CreatePreliminaryObject(PointCoord iconPosition, AllObjects* allObjects_ptr) const;
	PointCoord MenuNavigation(PointCoord currentIcon, IconsPosition ip);
	void EraseMenu();
	void AddManager(ConstructionManager* manager_ptr);
	ConstructionManager* GetManager(ConstructionDescriptor* cd_ptr) const;
	RectangleSymbols* GetMenuSymbols() const;
	RectangleSymbols* GetItemSymbols() const;
	RectangleSymbols* GetIconSymbols() const;
};