#include "Button.h"
///////////////Button///////////////
string Button::GetButtonTitle() const
{
	return title;
}
void Button::Display(function<bool()> enableButton)
{
	DrawBorder();
	if(title.empty())
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
void ActivatedByConditionButton::Display(function<bool()> enableButton)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("SavedTycoon.xml");
	if (enabled)
	{
		if (!result)
		{
			this->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonDisabledColor());
			this->GetBorder()->SetBorderBackgroundColor(ConstructionOptions::GetAllOptions()->GetButtonDisabledColor());
			this->SetTextColor(ConstructionOptions::GetAllOptions()->GetButtonDisabledColor());
		}
	}
	else
	{
		if (result)
		{
			this->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
			this->GetBorder()->SetBorderBackgroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderBackgroundColor());
			this->SetTextColor(ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor());
		}
	}
	this->Button::Display();
}