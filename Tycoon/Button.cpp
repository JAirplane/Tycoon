#include "Button.h"
///////////////Button///////////////
string Button::GetButtonTitle() const
{
	return title;
}
bool Button::GetEnabled() const
{
	return true;
}
void Button::SetEnabled(bool newCondition)
{}
void Button::Display(function<bool()> enableButton)
{
	DrawBorder();
	if (title.empty())
	{
		throw MyException("Button::Display() button has an empty title string.");
	}
	int length = (int)title.length();
	set_color(GetTextColor(), GetShadingColor());
	int addToLeftX = (GetWidthAddition() - 1 - length) / 2;
	set_cursor_pos(GetUpperLeft().Get_x() + 1 + addToLeftX, GetHalfYAxis());
	cout << title;
}
///////////////Activated By Condition Button///////////////
bool ActivatedByConditionButton::GetEnabled() const
{
	return enabled;
}
void ActivatedByConditionButton::SetEnabled(bool newCondition)
{
	enabled = newCondition;
}
void ActivatedByConditionButton::Display(function<bool()> enableButton)
{
	if (enabled)
	{
		if (!enableButton())
		{
			this->GetBorder()->SetBorderBackgroundColor(ConstructionOptions::GetAllOptions()->GetButtonDisabledColor());
			this->SetTextColor(ConstructionOptions::GetAllOptions()->GetButtonDisabledColor());
			enabled = false;
		}
	}
	else
	{
		if (enableButton())
		{
			this->GetBorder()->SetBorderBackgroundColor(this->GetInitialCondition()->backgroundBorderColor);
			this->SetTextColor(this->GetInitialCondition()->foregroundContentColor);
			enabled = true;
		}
	}
	this->Button::Display();
}