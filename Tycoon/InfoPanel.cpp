#include "InfoPanel.h"
///////////////InfoScreen Button///////////////
string InfoScreenButton::GetButtonTitle() const
{
	return title;
}
///////////////InfoPanel///////////////
void InfoPanel::DrawSplashScreen(color foreground, color background)
{
	PointCoord previousLoc = GetCursor()->GetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_I_Matrix(), GetUpperLeft().Get_x() + 3, GetUpperLeft().Get_y() + 2);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_N_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 1, GetCursor()->GetCursorConsoleLocation().Get_y());
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_F_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 1, GetCursor()->GetCursorConsoleLocation().Get_y());
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_O_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 1, GetCursor()->GetCursorConsoleLocation().Get_y());
	GetCursor()->SetCursorConsoleLocation();
	GetCursor()->CursorMovement(PointCoord(GetCursor()->GetCursorConsoleLocation().Get_x() + 2, GetCursor()->GetCursorConsoleLocation().Get_y()));
	Alphabet::DrawLetter(Alphabet::Get_P_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 1, GetCursor()->GetCursorConsoleLocation().Get_y());
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_A_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 1, GetCursor()->GetCursorConsoleLocation().Get_y());
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_N_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 1, GetCursor()->GetCursorConsoleLocation().Get_y());
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_E_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 1, GetCursor()->GetCursorConsoleLocation().Get_y());
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_L_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 1, GetCursor()->GetCursorConsoleLocation().Get_y());
	GetCursor()->CursorMovement(previousLoc);
}
void InfoPanel::AddMessage(const string msg)
{
	messages.push_front(msg);
}
void InfoPanel::DeleteMessage()
{
	messages.pop_back();
}
void InfoPanel::DisplayMessage(int initialX, int initialY, string message, color letterColor, color background)
{
	GetDrawPointer()->WriteMessage(initialX, initialY, message, letterColor, background);
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
void InfoPanel::DrawMenuScreenButton(InfoScreenButton* button_ptr)
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
void InfoPanel::DrawMenuScreen()
{
	menuScreen->DrawBorder();
	messagesAndInfoButton_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderActiveColor());
	controlsButton_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
	DrawMenuScreenButton(messagesAndInfoButton_ptr);
	DrawMenuScreenButton(controlsButton_ptr);
	GetCursor()->CursorMovement(PointCoord((messagesAndInfoButton_ptr->GetWidthAddition() + 1) / 2, messagesAndInfoButton_ptr->GetUpperLeft().Get_y()));
}
void InfoPanel::ShowControls()
{
	int midX = (controlsScreen->GetWidthAddition() + 1) / 2;
	int leftX = controlsScreen->GetUpperLeft().Get_x();
	int topY = controlsScreen->GetUpperLeft().Get_y();
	int rightX = controlsScreen->GetUpperLeft().Get_x() + controlsScreen->GetWidthAddition();
	int bottomY = controlsScreen->GetUpperLeft().Get_y() + controlsScreen->GetHeightAddition();
	controlsScreen->DrawBorder();
	for (int y = topY + 1; y < bottomY; y++)
	{
		set_cursor_pos(leftX + midX, y);
		wcout << L"\u205E";
	}
	set_color(controlsScreen->GetTextColor(), controlsScreen->GetShadingColor());
	vector<string>::iterator controlsIter;
	for (controlsIter = controlsDescription.begin(); controlsIter != controlsDescription.end(); controlsIter++)
	{
		for (int y = topY + 1; y < bottomY; y++)
		{
			set_cursor_pos(leftX + 1, y);
			cout << *(controlsIter);
		}
		for (int y = topY + 1; y < bottomY; y++)
		{
			set_cursor_pos(leftX + midX + 1, y);
			cout << *(controlsIter);
		}
	}
}
void InfoPanel::SwitchContent(InfoPanelContentType choosenContent)
{
	ClearContent();
	switch (choosenContent)
	{
	case InfoPanelContentType::SplashScreen:
	{ DrawInfoPanelSplashScreen(ConstructionOptions::GetAllOptions()->GetSplashScreenForegroundColor(), ConstructionOptions::GetAllOptions()->GetSplashScreenBackgroundColor()); return; }
	case InfoPanelContentType::InfoScreen:
	{ DrawInfoScreen(ConstructionOptions::GetAllOptions()->GetInfoPanelButtonWidth(), ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetButtonContentBackgroundColor(), ConstructionOptions::GetAllOptions()->GetInfoScreenBorderForegroundColor(),
		ConstructionOptions::GetAllOptions()->GetButtonBorderActiveColor(), ConstructionOptions::GetAllOptions()->GetInfoScreenBorderBackgroundColor()); return; }
	case InfoPanelContentType::Controls:
	{ DrawInfoPanelSplashScreen(ConstructionOptions::GetAllOptions()->GetSplashScreenForegroundColor(), ConstructionOptions::GetAllOptions()->GetSplashScreenBackgroundColor()); return; }
	}
}