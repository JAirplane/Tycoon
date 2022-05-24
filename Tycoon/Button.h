#pragma once
#include "Rectangle.h"
#include <functional>
class Button : public MyRectangle
{
private:
	string title;
public:
	Button(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, initial, vis_ptr, cur_ptr)
	{
		string buttonTitle = initial->buttonTitle;
		int length = (int)buttonTitle.length();
		if (length > initial->widthAddition - 1)
		{
			string truncatedTitle = buttonTitle.substr(0, (size_t)(initial->widthAddition - 1));
			title = truncatedTitle;
		}
		else
		{
			title = buttonTitle;
		}
	}
	Button(Button& anotherButton) : MyRectangle(anotherButton)
	{
		string buttonTitle = anotherButton.GetButtonTitle();
		int length = (int)buttonTitle.length();
		if (length > anotherButton.GetWidthAddition() - 1)
		{
			string truncatedTitle = buttonTitle.substr(0, (size_t)(anotherButton.GetWidthAddition() - 1));
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
	virtual bool GetEnabled() const;
	virtual void SetEnabled(bool newCondition);
	virtual void Display(function<bool()> enableButton = nullptr);
};
class ActivatedByConditionButton : public Button
{
private:
	bool enabled;
public:
	ActivatedByConditionButton(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : Button(upperLeft, initial, vis_ptr, cur_ptr)
	{
		this->enabled = false;
	}
	ActivatedByConditionButton(Button& someButton) : Button(someButton)
	{
		this->enabled = false;
	}
	virtual ~ActivatedByConditionButton() {}
	bool GetEnabled() const;
	void SetEnabled(bool newCondition);
	void Display(function<bool()> enableButton) override;
};