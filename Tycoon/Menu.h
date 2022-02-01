#pragma once
#include "ManagersDerived.h"
#include <vector>
class MenuElement : public MyRectangle
{
private:
	MyRectangle* icon_ptr;
	ConstructionManager* manager_ptr;
public:
	MenuElement(Visualisation* draw_ptr, Cursor* cursor_ptr, PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* menuBorbder_ptr,
		color letterColor, color shadingColor, MyRectangle* icn_ptr, ConstructionManager* manage_ptr) :
		MyRectangle(upperLeft, heightAdd, widthAdd, menuBorbder_ptr, letterColor, shadingColor, draw_ptr, cursor_ptr)
	{
		icon_ptr = icn_ptr;
		manager_ptr = manage_ptr;
	}
	~MenuElement()
	{
		delete icon_ptr;
		delete manager_ptr;
	}
	const MyRectangle* GetIcon() const;
	const ConstructionManager* GetManager() const;
};
class Menu : public MyRectangle
{
private:
	Camera* camera_ptr;
	vector<MenuElement*> menuItems;
	vector<ConstructionManager*> managers;
	MenuStatus currentSide;
	bool hidden;
public:
	Menu(Visualisation* draw_ptr, Camera* cam_ptr, Cursor* cursor_ptr, PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* menuBorbder_ptr,
		color letterColor, color shadingColor) : MyRectangle(upperLeft, heightAdd, widthAdd, menuBorbder_ptr, letterColor, shadingColor, draw_ptr, cursor_ptr)
	{
		camera_ptr = cam_ptr;
		hidden = 0;
		currentSide = MenuStatus::RIGHT;
		RectangleSymbols* elementSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuItemVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuItemHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuItemUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuItemBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuItemBottomRightSymbol());
		color menuElementBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetMenuElementInactiveColor();
		color menuElementBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetMenuElementBackgroundColor();
		BorderAppearance* menuElementBorder = new BorderAppearance(elementSymbols_ptr, menuElementBorderForegroundColor, menuElementBorderBackgroundColor);
		color menuElementLetterColor = ConstructionOptions::GetAllOptions()->GetMenuElementLetterColor();
		color menuElementShadingColor = ConstructionOptions::GetAllOptions()->GetMenuElementShadingColor();
		//
		PointCoord firstElementLocation = PointCoord(upperLeft.Get_x() + 2, upperLeft.Get_y() + 1);
		int elementHeightAdd = ConstructionOptions::GetAllOptions()->GetMenuElementHeightAdd();
		int elementWidthAdd = widthAdd - 4;
		//
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
		PointCoord firstIconLocation = PointCoord(firstElementLocation.Get_x() + 1, firstElementLocation.Get_y() + 1);
		int iconHeightAdd = ConstructionOptions::GetAllOptions()->GetMenuIconHeightAdd();
		int iconWidthAdd = ConstructionOptions::GetAllOptions()->GetMenuIconWidthAdd();
		MyRectangle* menuIcon_ptr = new MyRectangle(firstIconLocation, iconHeightAdd, iconWidthAdd, menuIconBorder, menuIconLetterColor, menuIconShadingColor, draw_ptr, cursor_ptr);
		//
		ConstructionDescriptor* iceCreamDesc = new BuildingDescriptor(firstElementLocation, ConstructionOptions::GetAllOptions()->GetIceCreamShopCost(),
			ConstructionOptions::GetAllOptions()->GetIceCreamShopDescription(), ConstructionOptions::GetAllOptions()->GetIceCreamShopIconSymbol(),
			ConstructionOptions::GetAllOptions()->GetIceCreamShopForegroundColor(), ConstructionOptions::GetAllOptions()->GetIceCreamShopBackgroundColor(),
			ConstructionOptions::GetAllOptions()->GetIceCreamShopSymbol(), ConstructionOptions::GetAllOptions()->GetIceCreamShopExpences(),
			ConstructionOptions::GetAllOptions()->GetIceCreamShopHeightAdd(), ConstructionOptions::GetAllOptions()->GetIceCreamShopWidthAdd());
		ConstructionManager* iceCreamManager_ptr = new BuildingManager(cursor_ptr, iceCreamDesc);
		//
		MenuElement* IceCreamShop_ptr = new MenuElement(draw_ptr, cursor_ptr, firstElementLocation, elementHeightAdd, elementWidthAdd, menuElementBorder, menuElementLetterColor,
			menuElementShadingColor, menuIcon_ptr, iceCreamManager_ptr);
		menuItems.push_back(IceCreamShop_ptr);

	}
	~Menu()
	{
		vector<ConstructionManager*>::iterator managersIter;
		for (managersIter = managers.begin(); managersIter != managers.end(); managersIter++)
		{
			delete (*managersIter);
		}
		vector<MenuElement*>::iterator elementsIter;
		for (elementsIter = menuItems.begin(); elementsIter != menuItems.end(); elementsIter++)
		{
			delete (*elementsIter);
		}
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