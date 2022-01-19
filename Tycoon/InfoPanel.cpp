#include "InfoPanel.h"
void InfoPanel::DrawInfoPanelExternalBorders()
{
	draw_ptr->DrawRectangle(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		infoPanelBorderSymbols_ptr->GetVerticalSymbol(), infoPanelBorderSymbols_ptr->GetHorizontalSymbol(), infoPanelBorderSymbols_ptr->GetUpperLeftSymbol(),
		infoPanelBorderSymbols_ptr->GetUpperRightSymbol(), infoPanelBorderSymbols_ptr->GetBottomLeftSymbol(), infoPanelBorderSymbols_ptr->GetBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelColor());
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void InfoPanel::EraseInfoPanelExternalBorders()
{
	int leftX = GetUpperLeft().Get_x();
	int topY = GetUpperLeft().Get_y();
	for (topY; topY <= GetUpperLeft().Get_y() + GetHeightAddition(); topY++)
	{
		draw_ptr->ErasePixel(leftX, topY);
		draw_ptr->ErasePixel(leftX + GetWidthAddition(), topY);
	}
	topY = GetUpperLeft().Get_y();
	for (leftX; leftX <= GetUpperLeft().Get_x() + GetWidthAddition(); leftX++)
	{
		draw_ptr->ErasePixel(leftX, topY);
		draw_ptr->ErasePixel(leftX, topY + GetHeightAddition());
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void InfoPanel::DrawInfoPanelSplashScreen(color foreground, color background)
{
	PointCoord previousLoc = cursor_ptr->GetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_I_Matrix(), GetUpperLeft().Get_x() + 3, GetUpperLeft().Get_y() + 2);
	cursor_ptr->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_N_Matrix(), cursor_ptr->GetCursorConsoleLocation().Get_x() + 1, cursor_ptr->GetCursorConsoleLocation().Get_y());
	cursor_ptr->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_F_Matrix(), cursor_ptr->GetCursorConsoleLocation().Get_x() + 1, cursor_ptr->GetCursorConsoleLocation().Get_y());
	cursor_ptr->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_O_Matrix(), cursor_ptr->GetCursorConsoleLocation().Get_x() + 1, cursor_ptr->GetCursorConsoleLocation().Get_y());
	cursor_ptr->SetCursorConsoleLocation();
	cursor_ptr->CursorMovement(PointCoord(cursor_ptr->GetCursorConsoleLocation().Get_x() + 2, cursor_ptr->GetCursorConsoleLocation().Get_y()));
	Alphabet::DrawLetter(Alphabet::Get_P_Matrix(), cursor_ptr->GetCursorConsoleLocation().Get_x() + 1, cursor_ptr->GetCursorConsoleLocation().Get_y());
	cursor_ptr->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_A_Matrix(), cursor_ptr->GetCursorConsoleLocation().Get_x() + 1, cursor_ptr->GetCursorConsoleLocation().Get_y());
	cursor_ptr->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_N_Matrix(), cursor_ptr->GetCursorConsoleLocation().Get_x() + 1, cursor_ptr->GetCursorConsoleLocation().Get_y());
	cursor_ptr->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_E_Matrix(), cursor_ptr->GetCursorConsoleLocation().Get_x() + 1, cursor_ptr->GetCursorConsoleLocation().Get_y());
	cursor_ptr->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_L_Matrix(), cursor_ptr->GetCursorConsoleLocation().Get_x() + 1, cursor_ptr->GetCursorConsoleLocation().Get_y());
	cursor_ptr->CursorMovement(previousLoc);
}
void InfoPanel::ClearInfoPanelContent()
{
	int leftX = GetUpperLeft().Get_x() + ConstructionOptions::GetAllOptions()->GetInfoPanelLeftIndent();
	int topY = GetUpperLeft().Get_y() + ConstructionOptions::GetAllOptions()->GetInfoPanelAboveIndent();
	for (topY; topY < GetUpperLeft().Get_y() + GetHeightAddition(); topY++)
	{
		for (leftX; leftX < GetUpperLeft().Get_x() + GetWidthAddition(); leftX++)
		{
			draw_ptr->ErasePixel(leftX, topY);
		}
		leftX = GetUpperLeft().Get_x() + ConstructionOptions::GetAllOptions()->GetInfoPanelLeftIndent();
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void InfoPanel::AddMessage(const string error)
{
	messages.push_front(error);
}
void InfoPanel::DeleteMessage()
{
	messages.pop_back();
}
void InfoPanel::DisplayMessage(int initialX, int initialY, string message, color letterColor, color background)
{
	draw_ptr->WriteMessage(initialX, initialY, message, letterColor, background);
}
void InfoPanel::DeleteOldMessages()
{
	while (messages.size() > (GetHeightAddition() + 1 - ConstructionOptions::GetAllOptions()->GetInfoPanelAboveIndent() - ConstructionOptions::GetAllOptions()->GetInfoPanelBottomIndent()))
	{
		DeleteMessage();
	}
}
void InfoPanel::DisplayMessages()
{
	list<string>::iterator messageIter;
	int initialX = GetUpperLeft().Get_x() + ConstructionOptions::GetAllOptions()->GetInfoPanelLeftIndent();
	int initialY = GetUpperLeft().Get_y() + ConstructionOptions::GetAllOptions()->GetInfoPanelAboveIndent();
	for (messageIter = messages.begin(); messageIter != messages.end(); messageIter++)
	{
		DisplayMessage(initialX, initialY, (*messageIter), cRED);
		++initialY;
	}
}
void InfoPanel::DrawInfoScreenBorders(int leftX, int topY, int rightX, int bottomY, color foreground, color background)
{
	draw_ptr->DrawRectangle(leftX, topY, rightX, bottomY, infoScreenBorderSymbols_ptr->GetVerticalSymbol(), infoScreenBorderSymbols_ptr->GetHorizontalSymbol(),
		infoScreenBorderSymbols_ptr->GetUpperLeftSymbol(), infoScreenBorderSymbols_ptr->GetUpperRightSymbol(), infoScreenBorderSymbols_ptr->GetBottomLeftSymbol(),
		infoScreenBorderSymbols_ptr->GetBottomRightSymbol(), foreground, background);
}
void InfoPanel::DrawInfoScreenButton(int leftX, int topY, int rightX, int bottomY, color foreground, color background)
{
	draw_ptr->DrawRectangle(leftX, topY, rightX, bottomY, infoScreenButtonBorderSymbols_ptr->GetVerticalSymbol(),
		infoScreenButtonBorderSymbols_ptr->GetHorizontalSymbol(), infoScreenButtonBorderSymbols_ptr->GetUpperLeftSymbol(), 
		infoScreenButtonBorderSymbols_ptr->GetUpperRightSymbol(), infoScreenButtonBorderSymbols_ptr->GetBottomLeftSymbol(),
		infoScreenButtonBorderSymbols_ptr->GetBottomRightSymbol(), foreground, background);
}
void InfoPanel::DrawInfoScreen(int leftX, int topY, int rightX, int bottomY, color foreground, color background)
{
	DrawInfoScreenBorders(leftX, topY, rightX, bottomY, foreground, background);

}