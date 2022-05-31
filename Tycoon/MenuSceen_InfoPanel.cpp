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
	RectangleConstantsXML* infoPanelMenuScreenControlsButtonConstants = DTOCollector::GetCollector()->GetFigureConstants("infoPanelMenuScreenControlsButton");
	RectangleConstantsXML* infoPanelMenuScreenSaveAndExitButtonConstants = DTOCollector::GetCollector()->GetFigureConstants("infoPanelMenuScreenSaveAndExitButton");
	int controlsButtonWidthAdd = infoPanelMenuScreenControlsButtonConstants->widthAddition;
	int leftXControlsButton = this->GetHalfXAxis() - controlsButtonWidthAdd / 2;
	int rightXControlsButton = leftXControlsButton + controlsButtonWidthAdd;
	int leftXMessagesAndInfoButton = leftXControlsButton - 2 - infoPanelMenuScreenMessagesAndInfoButtonConstants->widthAddition;
	int leftXSaveAndExitButton = rightXControlsButton + 2;
	int topYButtons = GetUpperLeft().Get_y() + 1;
	PointCoord messagesAndInfoButtonUpperLeft = PointCoord(leftXMessagesAndInfoButton, topYButtons);
	PointCoord controlsButtonUpperLeft = PointCoord(leftXControlsButton, topYButtons);
	PointCoord saveAndExitButtonUpperLeft = PointCoord(leftXSaveAndExitButton, topYButtons);
	messagesAndInfoButton_ptr = this->CreateButton(messagesAndInfoButtonUpperLeft, "infoPanelMenuScreenMessagesAndInfoButton");
	controlsButton_ptr = this->CreateButton(controlsButtonUpperLeft, "infoPanelMenuScreenControlsButton");
	saveAndExitButton_ptr = this->CreateButton(saveAndExitButtonUpperLeft, "infoPanelMenuScreenSaveAndExitButton");
}
Button* MenuScreen::GetMessagesButton() const
{
	return messagesAndInfoButton_ptr;
}
Button* MenuScreen::GetControlsButton() const
{
	return controlsButton_ptr;
}
Button* MenuScreen::GetSaveAndExitButton() const
{
	return saveAndExitButton_ptr;
}
void MenuScreen::DrawMenuScreenButton(Button* button_ptr)
{
	button_ptr->Display();
}