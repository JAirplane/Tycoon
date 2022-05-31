#include "SaveAndExit_InfoPanel.h"
void SaveAndExitScreen::CreateButtons()
{
	RectangleConstantsXML* leaveButtonRectangleConstants = DTOCollector::GetCollector()->GetFigureConstants("infoPanelSaveAndExitExitButton");
	int leaveLeftX = this->GetHalfXAxis() - 10 - leaveButtonRectangleConstants->widthAddition;
	leave_ptr = RectangleCreator::GetRectangleFactory()->CreateButton(PointCoord(leaveLeftX, this->GetUpperLeft().Get_y() + 1), leaveButtonRectangleConstants,
		this->GetDrawPointer(), this->GetCursor());
	leave_ptr->SetHeightAddition(this->GetHeightAddition() - 2);
	cancel_ptr = RectangleCreator::GetRectangleFactory()->CreateButton(PointCoord(this->GetHalfXAxis() + 10, this->GetUpperLeft().Get_y() + 1),
		DTOCollector::GetCollector()->GetFigureConstants("infoPanelSaveAndExitCancelButton"), this->GetDrawPointer(), this->GetCursor());
	cancel_ptr->SetHeightAddition(this->GetHeightAddition() - 2);
}
Button* SaveAndExitScreen::GetExitButton() const
{
	return leave_ptr;
}
Button* SaveAndExitScreen::GetCancelButton() const
{
	return cancel_ptr;
}