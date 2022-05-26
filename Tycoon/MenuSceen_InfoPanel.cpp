#include "MenuScreen_InfoPanel.h"
Button* MenuScreen::CreateButton(PointCoord upperLeft, string buttonTitle)
{
	Button* created = RectangleCreator::GetRectangleFactory()->CreateButton(upperLeft,
		DTOCollector::GetCollector()->GetFigureConstants(buttonTitle), this->GetDrawPointer(), this->GetCursor());
	created->SetHeightAddition(this->GetHeightAddition() - 2);
	return created;
}
void MenuScreen::CreateButtons()
{
	RectangleConstantsXML* infoPanelMenuScreenMessagesAndInfoButtonConstants = DTOCollector::GetCollector()->GetFigureConstants("infoPanelMenuScreenMessagesAndInfoButton");
	int buttonWidthAdd = infoPanelMenuScreenMessagesAndInfoButtonConstants->widthAddition;
	int buttonHeightAdd = GetHeightAddition() - 2;
	int leftXMenuScreen = GetUpperLeft().Get_x();
	int rightXMenuScreen = leftXMenuScreen + GetWidthAddition();
	int topYButtons = GetUpperLeft().Get_y() + 1;
	int leftXInfoScreenButton = rightXMenuScreen / 2 - rightXMenuScreen / 10 - buttonWidthAdd;
	int leftXControlsButton = rightXMenuScreen / 2 + rightXMenuScreen / 10;
	PointCoord leftButtonUpperLeft = PointCoord(leftXInfoScreenButton, topYButtons);
	PointCoord rightButtonUpperLeft = PointCoord(leftXControlsButton, topYButtons);
	messagesAndInfoButton_ptr = this->CreateButton(leftButtonUpperLeft, "infoPanelMenuScreenMessagesAndInfoButton");
	controlsButton_ptr = this->CreateButton(rightButtonUpperLeft, "infoPanelMenuScreenControlsButton");
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