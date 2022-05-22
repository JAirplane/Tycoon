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
color Button::GetActiveColor() const
{
	return activeColor;
}
color Button::GetPressedButtonColor() const
{
	return pressedButtonColor;
}
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
		if (!enableButton)
		{
			this->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonDisabledColor());
			this->GetBorder()->SetBorderBackgroundColor(ConstructionOptions::GetAllOptions()->GetButtonDisabledColor());
			this->SetTextColor(ConstructionOptions::GetAllOptions()->GetButtonDisabledColor());
		}
	}
	else
	{
		if (enableButton)
		{
			this->GetBorder()->SetBorderForegroundColor(this->GetBorder()->GetBorderForegroundColor());
			this->GetBorder()->SetBorderBackgroundColor(this->GetBorder()->GetBorderBackgroundColor());
			this->SetTextColor(ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor());
		}
	}
	this->Button::Display();
}