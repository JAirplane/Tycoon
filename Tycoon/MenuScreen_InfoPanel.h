#pragma once
#include "Button.h"
class MenuScreen : public MyRectangle
{
private:
	Button* messagesAndInfoButton_ptr;
	Button* controlsButton_ptr;
public:
	MenuScreen(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor, Visualisation* vis_ptr,
		Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
	{
		messagesAndInfoButton_ptr = nullptr;
		controlsButton_ptr = nullptr;
	}
	MenuScreen(MyRectangle* someRectange) : MyRectangle(someRectange)
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
