#pragma once
#include "InfoPanel.h"
class Display
{
public:
	Display(Visualisation* draw_ptr)
	{
		this->draw_ptr = draw_ptr;
	}
	virtual ~Display() {}
	void DisplayInitialScreen(const InitialScreen* startScreen);
	void DrawCursor(const Cursor* cursor_ptr, const AllObjects* container_ptr, const PlayingField* field_ptr) const;
	// display / erase main game elements
	void DisplayMenu(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
		const AllObjects* container_ptr, const PlayingField* field_ptr) const;
	void HideMenu(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
		const AllObjects* container_ptr, const PlayingField* field_ptr) const;
	void DisplayCamera(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
		const AllObjects* container_ptr, const PlayingField* field_ptr) const;
	void DisplayPlayingField(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
		const AllObjects* container_ptr, const PlayingField* field_ptr) const;
	void ErasePlayingField(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
		const AllObjects* container_ptr, const PlayingField* field_ptr) const;
	void DisplayInfoPanel(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, InfoPanel* infoPanel_ptr,
		const AllObjects* container_ptr, const PlayingField* field_ptr) const;
	void HideInfoPanel(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
		const AllObjects* container_ptr, const PlayingField* field_ptr) const;
	void EraseScreen() const;
	void DisplayAllObjects(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
		const AllObjects* container_ptr, const PlayingField* field_ptr) const;
	//
	void HideInterface(Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
		const AllObjects* container_ptr, const PlayingField* field_ptr) const;
	void ShowInterface(Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, InfoPanel* infoPanel_ptr,
		const AllObjects* container_ptr, const PlayingField* field_ptr) const;
private:
	Visualisation* draw_ptr;
};