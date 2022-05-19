#include "MenuScreen_InfoPanel.h"
Button* MenuScreen::CreateButton(PointCoord upperLeft, string buttonTitle)
{
	MyRectangle* buttonRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(upperLeft,
		XMLDownloader::GetDownloader()->DownloadRectangleConstants("infoPanelMenuScreenButton"), this->GetDrawPointer(), this->GetCursor());
	buttonRectangle->SetHeightAddition(this->GetHeightAddition() - 2);
	Button* created = new Button(buttonRectangle, buttonTitle);
	delete buttonRectangle;
	return created;
}
void MenuScreen::CreateButtons()
{
	int buttonWidthAdd = ConstructionOptions::GetAllOptions()->GetInfoPanelButtonWidthAdd();
	int buttonHeightAdd = GetHeightAddition() - 2;
	int leftXMenuScreen = GetUpperLeft().Get_x();
	int rightXMenuScreen = leftXMenuScreen + GetWidthAddition();
	int topYButtons = GetUpperLeft().Get_y() + 1;
	int leftXInfoScreenButton = rightXMenuScreen / 2 - rightXMenuScreen / 10 - buttonWidthAdd;
	int leftXControlsButton = rightXMenuScreen / 2 + rightXMenuScreen / 10;
	PointCoord leftButtonUpperLeft = PointCoord(leftXInfoScreenButton, topYButtons);
	PointCoord rightButtonUpperLeft = PointCoord(leftXControlsButton, topYButtons);
	messagesAndInfoButton_ptr = this->CreateButton(leftButtonUpperLeft, ConstructionOptions::GetAllOptions()->GetInfoScreenButtonTitle());
	controlsButton_ptr = this->CreateButton(rightButtonUpperLeft, ConstructionOptions::GetAllOptions()->GetControlsButtonTitle());
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
	button_ptr->Display();
}