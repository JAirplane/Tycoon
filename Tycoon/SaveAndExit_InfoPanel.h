#pragma once
#include "SplitScreen.h"
class SaveAndExitScreen : public RectangleWithButtons
{
private:
	Button* saveAndExit_ptr;
	Button* unsavedExit_ptr;
	Button* cancel_ptr;
public:
	SaveAndExitScreen(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : RectangleWithButtons(upperLeft, initial, vis_ptr, cur_ptr)
	{
		saveAndExit_ptr = nullptr;
		unsavedExit_ptr = nullptr;
		cancel_ptr = nullptr;
	}
	SaveAndExitScreen(MyRectangle& someRectange) : RectangleWithButtons(someRectange)
	{
		saveAndExit_ptr = nullptr;
		unsavedExit_ptr = nullptr;
		cancel_ptr = nullptr;
	}
	virtual ~SaveAndExitScreen()
	{
		delete saveAndExit_ptr;
		delete unsavedExit_ptr;
		delete cancel_ptr;
	}
	Button* CreateButton(PointCoord upperLeft, string buttonTitle) const override;
	void CreateButtons() override;
	Button* GetExitButton() const;
	Button* GetUnsavedExitButton() const;
	Button* GetCancelButton() const;
};