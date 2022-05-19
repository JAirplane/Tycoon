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
	Button(MyRectangle* someRectangle, string buttonTitle) : MyRectangle(someRectangle)
	{
		int length = (int)buttonTitle.length();
		if (length > someRectangle->GetWidthAddition() - 1)
		{
			string truncatedTitle = buttonTitle.substr(0, (size_t)(someRectangle->GetWidthAddition() - 1));
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
	virtual void Display(function<bool()> enableButton = nullptr);
};
class ActivatedByConditionButton : public Button
{
private:
	bool enabled;
public:
	ActivatedByConditionButton(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* externalBorder, color letterColor, color shadingColor, string buttonTitle,
		Visualisation* vis_ptr, Cursor* cur_ptr) : Button(upperLeft, heightAdd, widthAdd, externalBorder, letterColor, shadingColor, buttonTitle, vis_ptr, cur_ptr)
	{
		this->enabled = false;
	}
	ActivatedByConditionButton(MyRectangle* someRectangle, string buttonTitle) : Button(someRectangle, buttonTitle)
	{
		this->enabled = false;
	}
	virtual ~ActivatedByConditionButton() {}
	void Display(function<bool()> enableButton) override;
};