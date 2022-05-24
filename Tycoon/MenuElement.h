#pragma once
#include "ManagersDerived.h"
class MenuElement : public MyRectangle
{
private:
	MyRectangle* icon_ptr;
	ConstructionManager* manager_ptr;
public:
	MenuElement(Visualisation* draw_ptr, Cursor* cursor_ptr, PointCoord upperLeft, RectangleConstantsXML* initial, MyRectangle* icn_ptr, ConstructionManager* manage_ptr) :
		MyRectangle(upperLeft, initial, draw_ptr, cursor_ptr)
	{
		icon_ptr = icn_ptr;
		manager_ptr = manage_ptr;
	}
	MenuElement()
	{
		icon_ptr = nullptr;
		manager_ptr = nullptr;
	}
	MenuElement(MyRectangle& menuElementRectangle, MyRectangle* icn_ptr, ConstructionManager* manage_ptr) :
		MyRectangle(menuElementRectangle)
	{
		icon_ptr = icn_ptr;
		manager_ptr = manage_ptr;
	}
	virtual ~MenuElement()
	{
		delete icon_ptr;
		delete manager_ptr;
	}
	MyRectangle* GetIcon() const;
	ConstructionManager* GetManager() const;
	void Draw() const;
	void Shift(IconsPosition upperOrLower);
};
