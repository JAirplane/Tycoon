#pragma once
#include "Menu.h"
class MenuScreen : public MyRectangle
{
private:
	Button* messagesAndInfoButton_ptr;
	Button* controlsButton_ptr;
public:
	MenuScreen(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, initial, vis_ptr, cur_ptr)
	{
		messagesAndInfoButton_ptr = nullptr;
		controlsButton_ptr = nullptr;
	}
	MenuScreen(MyRectangle& someRectange) : MyRectangle(someRectange)
	{
		messagesAndInfoButton_ptr = nullptr;
		controlsButton_ptr = nullptr;
	}
	virtual ~MenuScreen()
	{
		delete messagesAndInfoButton_ptr;
		delete controlsButton_ptr;
	}
	virtual Button* CreateButton(PointCoord upperLeft, string buttonTitle);
	virtual void CreateButtons();
	Button* GetMessagesButton() const;
	Button* GetControlsButton() const;
	void DrawMenuScreenButton(Button* button_ptr);
};
