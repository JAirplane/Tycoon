#pragma once
#include "Rectangle.h"
#include <functional>
class Button : public MyRectangle
{
private:
	string title;
	color activeColor;
	color pressedButtonColor;
public:
	Button(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* externalBorder, color letterColor, color shadingColor, string buttonTitle, color activeColor,
		color pressedButtonColor, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, externalBorder, letterColor, shadingColor, vis_ptr, cur_ptr)
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
		this->activeColor = activeColor;
		this->pressedButtonColor = pressedButtonColor;
	}
	Button(MyRectangle& someRectangle, string buttonTitle, color activeColor, color pressedButtonColor) : MyRectangle(someRectangle)
	{
		int length = (int)buttonTitle.length();
		if (length > someRectangle.GetWidthAddition() - 1)
		{
			string truncatedTitle = buttonTitle.substr(0, (size_t)(someRectangle.GetWidthAddition() - 1));
			title = truncatedTitle;
		}
		else
		{
			title = buttonTitle;
		}
		this->activeColor = activeColor;
		this->pressedButtonColor = pressedButtonColor;
	}
	Button(Button& anotherButton) : MyRectangle(anotherButton.GetUpperLeft(), anotherButton.GetHeightAddition(), anotherButton.GetWidthAddition(), anotherButton.GetBorder(),
		anotherButton.GetTextColor(), anotherButton.GetShadingColor(), anotherButton.GetDrawPointer(), anotherButton.GetCursor())
	{
		title = anotherButton.GetButtonTitle();
		activeColor = anotherButton.GetActiveColor();
		pressedButtonColor = anotherButton.GetPressedButtonColor();
	}
	virtual ~Button()
	{}
	string GetButtonTitle() const;
	color GetActiveColor() const;
	color GetPressedButtonColor() const;
	virtual bool GetEnabled() const;
	virtual void SetEnabled(bool newCondition);
	virtual void Display(function<bool()> enableButton = nullptr);
};
class ActivatedByConditionButton : public Button
{
private:
	bool enabled;
public:
	ActivatedByConditionButton(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* externalBorder, color letterColor, color shadingColor,
		string buttonTitle, color activeColor, color pressedButtonColor, Visualisation* vis_ptr, Cursor* cur_ptr) :
		Button(upperLeft, heightAdd, widthAdd, externalBorder, letterColor, shadingColor, buttonTitle, activeColor, pressedButtonColor, vis_ptr, cur_ptr)
	{
		this->enabled = false;
	}
	ActivatedByConditionButton(MyRectangle& someRectangle, string buttonTitle, color activeColor, color pressedButtonColor) :
		Button(someRectangle, buttonTitle, activeColor, pressedButtonColor)
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