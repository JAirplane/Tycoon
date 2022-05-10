#pragma once
#include "Menu.h"
class Button : public MyRectangle
{
private:
	string title;
public:
	Button(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* externalBorder, color letterColor, color shadingColor, string buttonTitle,
		Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, externalBorder, letterColor, shadingColor, vis_ptr, cur_ptr)
	{
		int length = (int)buttonTitle.length();
		if (length > widthAdd - 1)
		{
			string truncatedTitle = buttonTitle.substr(0, (size_t)(widthAdd - 1));
			title = truncatedTitle;
		}
		else
		{
			title = buttonTitle;
		}
	}
	virtual ~Button()
	{}
	string GetButtonTitle() const;
	void Display() const;
};
