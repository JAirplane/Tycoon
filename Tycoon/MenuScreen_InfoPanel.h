#pragma once
#include "Menu.h"
class MenuScreen : public RectangleWithButtons
{
private:
	Button* messagesAndInfoButton_ptr;
	Button* controlsButton_ptr;
	Button* saveAndExitButton_ptr;
public:
	MenuScreen(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : RectangleWithButtons(upperLeft, initial, vis_ptr, cur_ptr)
	{
		messagesAndInfoButton_ptr = nullptr;
		controlsButton_ptr = nullptr;
		saveAndExitButton_ptr = nullptr;
	}
	MenuScreen(MyRectangle& someRectange) : RectangleWithButtons(someRectange)
	{
		messagesAndInfoButton_ptr = nullptr;
		controlsButton_ptr = nullptr;
		saveAndExitButton_ptr = nullptr;
	}
	virtual ~MenuScreen()
	{
		delete messagesAndInfoButton_ptr;
		delete controlsButton_ptr;
		delete saveAndExitButton_ptr;
	}
	Button* CreateButton(PointCoord upperLeft, string buttonTitle) const override;
	void CreateButtons() override;
	Button* GetMessagesButton() const;
	Button* GetControlsButton() const;
	Button* GetSaveAndExitButton() const;
	void DrawMenuScreenButton(Button* button_ptr);
};
