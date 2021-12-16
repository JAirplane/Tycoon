#pragma once
#include "Camera.h"
#include <vector>
class Menu : public GlobalObject
{
private:
	Visualisation* draw_ptr;
	Camera* camera_ptr;
	Cursor* cursor_ptr;
	vector<ConstructionManager*> Managers;
	MenuStatus CurrentSide;
	bool Hidden;
public:
	Menu(Visualisation* drawptr, Camera* vmptr, Cursor* _cursor_ptr, PointCoord _ul) : GlobalObject(_ul), draw_ptr(drawptr), camera_ptr(vmptr), cursor_ptr(_cursor_ptr)
	{
		SetHeightAddition(ConstructionOptions::GetAllOptions()->GetMenuHeightAdd());
		SetWidthAddition(ConstructionOptions::GetAllOptions()->GetMenuWidthAdd());
		Hidden = 0;
		CurrentSide = MenuStatus::RIGHT;
	}
	~Menu()
	{
		vector<ConstructionManager*>::iterator iter;
		for (iter = Managers.begin(); iter != Managers.end(); iter++)
		{
			delete (*iter);
		}
	}
	bool getHideMenuStatus() const;
	void setHideMenuStatus(bool hideflag);
	MenuStatus getCurrentSide();
	Direction ChangeMenuSide();
	void ShowIcons();
	void ShowMenuBorders();
	PointCoord getNearestIconCoords(PointCoord currenticon, IconsPosition ip);
	void IconsShift(IconsPosition ip);
	IngameObject* CreatePreliminaryObject(PointCoord iconpos);
	PointCoord MenuNavigation(PointCoord currenticon, IconsPosition ip);
	void EraseMenu();
	void addManager(ConstructionManager* manager_ptr);
	ConstructionManager* getManager(ConstructionDescriptor* cd_ptr);
};