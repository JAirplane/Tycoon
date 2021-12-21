#pragma once
#include "Camera.h"
#include <vector>
class Menu : public GlobalObject
{
private:
	Visualisation* draw_ptr;
	Camera* camera_ptr;
	Cursor* cursor_ptr;
	vector<ConstructionManager*> managers;
	MenuStatus currentSide;
	bool hidden;
public:
	Menu(Visualisation* drawptr, Camera* vmptr, Cursor* _cursor_ptr, PointCoord upperLeft) : GlobalObject(upperLeft), draw_ptr(drawptr), camera_ptr(vmptr), cursor_ptr(_cursor_ptr)
	{
		SetHeightAddition(ConstructionOptions::GetAllOptions()->GetMenuHeightAdd());
		SetWidthAddition(ConstructionOptions::GetAllOptions()->GetMenuWidthAdd());
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
	}
	bool GetHideMenuStatus() const;
	void SetHideMenuStatus(bool hideFlag);
	MenuStatus GetCurrentSide();
	Direction ChangeMenuSide();
	void ShowMenuItems();
	void ShowMenuBorders();
	PointCoord GetNearestIconCoords(PointCoord currentIcon, IconsPosition ip);
	void IconsShift(IconsPosition ip);
	Construction* CreatePreliminaryObject(PointCoord iconPosition);
	PointCoord MenuNavigation(PointCoord currentIcon, IconsPosition ip);
	void EraseMenu();
	void AddManager(ConstructionManager* manager_ptr);
	ConstructionManager* GetManager(ConstructionDescriptor* cd_ptr);
};