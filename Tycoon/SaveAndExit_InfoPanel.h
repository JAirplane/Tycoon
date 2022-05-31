#pragma once
#include "SplitScreen.h"
class SaveAndExitScreen : public MyRectangle
{
private:
	Button* leave_ptr;
	Button* cancel_ptr;
public:
	SaveAndExitScreen(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, initial, vis_ptr, cur_ptr)
	{
		leave_ptr = nullptr;
		cancel_ptr = nullptr;
	}
	SaveAndExitScreen(MyRectangle& someRectange) : MyRectangle(someRectange)
	{
		leave_ptr = nullptr;
		cancel_ptr = nullptr;
	}
	virtual ~SaveAndExitScreen()
	{
		delete leave_ptr;
		delete cancel_ptr;
	}
	void CreateButtons();
	Button* GetExitButton() const;
	Button* GetCancelButton() const;
};