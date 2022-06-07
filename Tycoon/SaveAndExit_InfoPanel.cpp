#include "SaveAndExit_InfoPanel.h"
Button* SaveAndExitScreen::CreateButton(PointCoord upperLeft, string buttonTitle) const
{
	Button* created = RectangleCreator::GetRectangleFactory()->CreateButton(upperLeft,
		DTOCollector::GetCollector()->GetFigureConstants(buttonTitle), this->GetDrawPointer(), this->GetCursor());
	created->SetHeightAddition(this->GetHeightAddition() - 2);
	return created;
}
void SaveAndExitScreen::CreateButtons()
{
	RectangleConstantsXML* saveAndExitButtonRectangleConstants = DTOCollector::GetCollector()->GetFigureConstants("infoPanelSaveAndExitExitButton");
	RectangleConstantsXML* unsavedExitButtonRectangleConstants = DTOCollector::GetCollector()->GetFigureConstants("infoPanelSaveAndExitUnsavedExitButton");
	RectangleConstantsXML* cancelButtonRectangleConstants = DTOCollector::GetCollector()->GetFigureConstants("infoPanelSaveAndExitCancelButton");
	int unsavedExitButtonWidthAdd = unsavedExitButtonRectangleConstants->widthAddition;
	int leftXUnsavedExitButton = this->GetHalfXAxis() - unsavedExitButtonWidthAdd / 2;
	int rightXUnsavedExitButton = leftXUnsavedExitButton + unsavedExitButtonWidthAdd;
	int leftXSaveAndExitButton = leftXUnsavedExitButton - 2 - saveAndExitButtonRectangleConstants->widthAddition;
	int leftXCancelButton = rightXUnsavedExitButton + 2;
	int topYButtons = this->GetUpperLeft().Get_y() + 1;
	PointCoord saveAndExitButtonUpperLeft = PointCoord(leftXSaveAndExitButton, topYButtons);
	PointCoord unsavedExitButtonUpperLeft = PointCoord(leftXUnsavedExitButton, topYButtons);
	PointCoord cancelButtonUpperLeft = PointCoord(leftXCancelButton, topYButtons);
	saveAndExit_ptr = this->CreateButton(saveAndExitButtonUpperLeft, "infoPanelSaveAndExitExitButton");
	unsavedExit_ptr = this->CreateButton(unsavedExitButtonUpperLeft, "infoPanelSaveAndExitUnsavedExitButton");
	cancel_ptr = this->CreateButton(cancelButtonUpperLeft, "infoPanelSaveAndExitCancelButton");
}
Button* SaveAndExitScreen::GetExitButton() const
{
	return saveAndExit_ptr;
}
Button* SaveAndExitScreen::GetUnsavedExitButton() const
{
	return unsavedExit_ptr;
}
Button* SaveAndExitScreen::GetCancelButton() const
{
	return cancel_ptr;
}