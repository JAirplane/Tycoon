#include "InfoPanel.h"
void InfoPanel::DrawInfoPanelBorders()
{
	draw_ptr->DrawRectangle(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		infoPanelBorderSymbols_ptr->GetVerticalSymbol(), infoPanelBorderSymbols_ptr->GetHorizontalSymbol(), infoPanelBorderSymbols_ptr->GetUpperLeftSymbol(),
		infoPanelBorderSymbols_ptr->GetUpperRightSymbol(), infoPanelBorderSymbols_ptr->GetBottomLeftSymbol(), infoPanelBorderSymbols_ptr->GetBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelColor());
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void InfoPanel::EraseInfoPanelBorders()
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
	int leftX = GetUpperLeft().Get_x() + 1;
	int topY = GetUpperLeft().Get_y() + 1;
	for (topY; topY < GetUpperLeft().Get_y() + GetHeightAddition(); topY++)
	{
		for (leftX; leftX < GetUpperLeft().Get_x() + GetWidthAddition(); leftX++)
		{
			draw_ptr->ErasePixel(leftX, topY);
		}
		leftX = GetUpperLeft().Get_x() + 1;
	}
	cursor_ptr->CursorMovement(cursor_ptr->GetCursorConsoleLocation());
}
void InfoPanel::AddMessage(const string error)
{
	messages.push_front(make_pair(error, false));
}
void InfoPanel::DeleteMessage()
{
	messages.pop_back();
}
void InfoPanel::DisplayMessage()
{
	messages.back().second = true;
	set_cursor_pos(GetUpperLeft().Get_x() + 1, GetUpperLeft().Get_y() + 1);
	cout << messages.back().first;
}