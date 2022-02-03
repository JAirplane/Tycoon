#include "MenuScreen_InfoPanel.h"
void MenuScreen::CreateButtons()
{
	RectangleSymbols* infoScreenButtonBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuScreenButtonVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuScreenButtonHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenButtonUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuScreenButtonUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenButtonBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuScreenButtonBottomRightSymbol());
	color borderForegroundColor = ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor();
	color borderBackgroundColor = ConstructionOptions::GetAllOptions()->GetButtonBorderBackgroundColor();
	BorderAppearance* borderVisual_ptr = new BorderAppearance(infoScreenButtonBorderSymbols_ptr, borderForegroundColor, borderBackgroundColor);
	BorderAppearance* controlsButtonBorderVisual_ptr = new BorderAppearance(*borderVisual_ptr);
	color buttonLetterColor = ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor();
	color buttonShadingColor = ConstructionOptions::GetAllOptions()->GetButtonContentBackgroundColor();
	int buttonWidthAdd = ConstructionOptions::GetAllOptions()->GetInfoPanelButtonWidthAdd();
	int buttonHeightAdd = GetHeightAddition() - 2;
	int leftXMenuScreen = GetUpperLeft().Get_x();
	int rightXMenuScreen = leftXMenuScreen + GetWidthAddition();
	int topYButtons = GetUpperLeft().Get_y() + 1;
	int leftXInfoScreenButton = rightXMenuScreen / 2 - rightXMenuScreen / 10 - buttonWidthAdd;
	int leftXControlsButton = rightXMenuScreen / 2 + rightXMenuScreen / 10;
	PointCoord leftButtonUpperLeft = PointCoord(leftXInfoScreenButton, topYButtons);
	PointCoord rightButtonUpperLeft = PointCoord(leftXControlsButton, topYButtons);
	messagesAndInfoButton_ptr = new Button(leftButtonUpperLeft, buttonHeightAdd, buttonWidthAdd, borderVisual_ptr, buttonLetterColor, buttonShadingColor,
		ConstructionOptions::GetAllOptions()->GetInfoScreenButtonTitle(), GetDrawPointer(), GetCursor());
	controlsButton_ptr = new Button(rightButtonUpperLeft, buttonHeightAdd, buttonWidthAdd, controlsButtonBorderVisual_ptr, buttonLetterColor, buttonShadingColor,
		ConstructionOptions::GetAllOptions()->GetControlsButtonTitle(), GetDrawPointer(), GetCursor());
}
Button* MenuScreen::GetMessagesButton() const
{
	return messagesAndInfoButton_ptr;
}
Button* MenuScreen::GetControlsButton() const
{
	return controlsButton_ptr;
}
void MenuScreen::DrawMenuScreenButton(Button* button_ptr)
{
	button_ptr->DrawBorder();
	button_ptr->ClearContent();
	int length = (int)button_ptr->GetButtonTitle().length();
	set_color(button_ptr->GetTextColor(), button_ptr->GetShadingColor());
	if (length > button_ptr->GetWidthAddition() - 1)
	{
		string truncatedTitle = button_ptr->GetButtonTitle().substr(0, (size_t)(button_ptr->GetWidthAddition() - 1));
		set_cursor_pos(button_ptr->GetUpperLeft().Get_x() + 1, button_ptr->GetUpperLeft().Get_y() + 2);
		cout << truncatedTitle;
	}
	else
	{
		int addToLeftX = (button_ptr->GetWidthAddition() - 1 - length) / 2;
		set_cursor_pos(button_ptr->GetUpperLeft().Get_x() + 1 + addToLeftX, button_ptr->GetUpperLeft().Get_y() + 2);
		cout << button_ptr->GetButtonTitle();
	}
}