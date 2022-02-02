#include "InfoPanel.h"
///////////////InfoPanel///////////////
// create Screens
void InfoPanel::CreateMenuScreen()
{
	RectangleSymbols* menuScreenBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuScreenVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuScreenHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuScreenUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMenuScreenBottomRightSymbol());
	color menuScreenBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetMenuScreenBorderForegroundColor();
	color menuScreenBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetMenuScreenBorderBackgroundColor();
	BorderAppearance* menuScreenBorder = new BorderAppearance(menuScreenBorderSymbols_ptr, menuScreenBorderForegroundColor, menuScreenBorderBackgroundColor);
	color menuLetterColor = ConstructionOptions::GetAllOptions()->GetMenuScreenTextColor();
	color menuShadingColor = ConstructionOptions::GetAllOptions()->GetMenuScreenShadingColor();
	PointCoord menuScreenUpperLeft = PointCoord(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 2);
	int menuScreenHeightAdd = GetHeightAddition() - 4;
	int menuScreenWidthAdd = GetWidthAddition() - 4;
	mainScreen_ptr = new MenuScreen(menuScreenUpperLeft, menuScreenHeightAdd, menuScreenWidthAdd, menuScreenBorder,
		menuLetterColor, menuShadingColor, GetDrawPointer(), GetCursor());
	mainScreen_ptr->CreateButtons();
}
void InfoPanel::CreateControlsScreen()
{
	RectangleSymbols* controlsBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetControlsVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetControlsHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetControlsUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetControlsUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetControlsBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetControlsBottomRightSymbol());
	color controlsScreenBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetControlsScreenBorderForegroundColor();
	color controlsScreenBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetControlsScreenBorderBackgroundColor();
	BorderAppearance* controlsBorderVisual_ptr = new BorderAppearance(controlsBorderSymbols_ptr, controlsScreenBorderForegroundColor, controlsScreenBorderBackgroundColor);
	color controlsLetterColor = ConstructionOptions::GetAllOptions()->GetControlsScreenLetterColor();
	color controlsShadingColor = ConstructionOptions::GetAllOptions()->GetControlsScreenShadingColor();
	PointCoord controlsScreenUpperLeft = PointCoord(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 2);
	int controlsScreenHeightAdd = GetHeightAddition() - 4;
	int controlsScreenWidthAdd = GetWidthAddition() - 4;
	gameControlInfo_ptr = new ControlsScreen(controlsScreenUpperLeft, controlsScreenHeightAdd, controlsScreenWidthAdd,
		controlsBorderVisual_ptr, controlsLetterColor, controlsShadingColor, GetDrawPointer(), GetCursor());
	gameControlInfo_ptr->FillControlsDescriptions();
}
void InfoPanel::CreateGameMessagesScreen()
{
	RectangleSymbols* messagesAndInfoBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMessagesAndInfoVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetMessagesAndInfoHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMessagesAndInfoUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMessagesAndInfoUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMessagesAndInfoBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetMessagesAndInfoBottomRightSymbol());
	color messagesAndInfoScreenBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetMessagesAndInfoScreenBorderForegroundColor();
	color messagesAndInfoScreenBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetMessagesAndInfoScreenBorderBackgroundColor();
	BorderAppearance* messagesAndInfoBorderVisual_ptr = new BorderAppearance(messagesAndInfoBorderSymbols_ptr,
		messagesAndInfoScreenBorderForegroundColor, messagesAndInfoScreenBorderBackgroundColor);
	color messagesAndInfoLetterColor = ConstructionOptions::GetAllOptions()->GetMessagesAndInfoScreenLetterColor();
	color messagesAndInfoShadingColor = ConstructionOptions::GetAllOptions()->GetMessagesAndInfoScreenShadingColor();
	PointCoord messagesAndInfoScreenUpperLeft = PointCoord(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 2);
	int messagesAndInfoScreenHeightAdd = GetHeightAddition() - 4;
	int messagesAndInfoScreenWidthAdd = GetWidthAddition() - 4;
	messagesAndInfoScreen_ptr = new GameMessagesScreen(messagesAndInfoScreenUpperLeft, messagesAndInfoScreenHeightAdd, messagesAndInfoScreenWidthAdd,
		messagesAndInfoBorderVisual_ptr, messagesAndInfoLetterColor, messagesAndInfoShadingColor, GetDrawPointer(), GetCursor());
}
//
void InfoPanel::DrawSplashScreen(color foreground, color background)
{
	currentScreen = InfoPanelContentType::SplashScreen;
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
void InfoPanel::DrawMenuScreenButton(Button* button_ptr)
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
	currentScreen = InfoPanelContentType::MenuScreen;
	GetCursor()->CursorMovement(PointCoord(messagesAndInfoButton_ptr->GetUpperLeft().Get_x() + messagesAndInfoButton_ptr->GetWidthAddition() / 2,
		messagesAndInfoButton_ptr->GetUpperLeft().Get_y()));
}
void InfoPanel::ShowControls()
{
	currentScreen = InfoPanelContentType::Controls;
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
		{ 
			DrawSplashScreen(ConstructionOptions::GetAllOptions()->GetSplashScreenForegroundColor(), ConstructionOptions::GetAllOptions()->GetSplashScreenBackgroundColor());
			currentScreen = InfoPanelContentType::SplashScreen;
			return;
		}
		case InfoPanelContentType::MenuScreen:
		{ 
			DrawMenuScreen();
			currentScreen = InfoPanelContentType::MenuScreen;
			return;
		}
		case InfoPanelContentType::Controls:
		{ 
			ShowControls();
			currentScreen = InfoPanelContentType::Controls;
			return;
		}
	}
}
void InfoPanel::Arrows(Direction arrowDir)
{
	if (currentScreen == InfoPanelContentType::MenuScreen)
	{
		if (GetCursor()->GetCursorConsoleLocation() == PointCoord(controlsButton_ptr->GetUpperLeft().Get_x() + controlsButton_ptr->GetWidthAddition() / 2,
			controlsButton_ptr->GetUpperLeft().Get_y()) && arrowDir == Direction::Left)
		{
			controlsButton_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
			controlsButton_ptr->DrawBorder();
			messagesAndInfoButton_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderActiveColor());
			messagesAndInfoButton_ptr->DrawBorder();
			GetCursor()->CursorMovement(PointCoord(messagesAndInfoButton_ptr->GetUpperLeft().Get_x() + messagesAndInfoButton_ptr->GetWidthAddition() / 2,
				messagesAndInfoButton_ptr->GetUpperLeft().Get_y()));
		}
		if (GetCursor()->GetCursorConsoleLocation() == PointCoord(messagesAndInfoButton_ptr->GetUpperLeft().Get_x() + messagesAndInfoButton_ptr->GetWidthAddition() / 2,
			messagesAndInfoButton_ptr->GetUpperLeft().Get_y()) && arrowDir == Direction::Right)
		{
			messagesAndInfoButton_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
			messagesAndInfoButton_ptr->DrawBorder();
			controlsButton_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderActiveColor());
			controlsButton_ptr->DrawBorder();
			GetCursor()->CursorMovement(PointCoord(controlsButton_ptr->GetUpperLeft().Get_x() + controlsButton_ptr->GetWidthAddition() / 2,
				controlsButton_ptr->GetUpperLeft().Get_y()));
		}
	}
}
void InfoPanel::EndInteraction()
{
	if (currentScreen == InfoPanelContentType::MenuScreen)
	{
		messagesAndInfoButton_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
		controlsButton_ptr->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
		SwitchContent(InfoPanelContentType::SplashScreen);
	}

}