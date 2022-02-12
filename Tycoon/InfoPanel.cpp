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
	messagesAndInfoScreen_ptr = new MessagesAndInfoScreen(messagesAndInfoScreenUpperLeft, messagesAndInfoScreenHeightAdd, messagesAndInfoScreenWidthAdd,
		messagesAndInfoBorderVisual_ptr, messagesAndInfoLetterColor, messagesAndInfoShadingColor, GetDrawPointer(), GetCursor());
	messagesAndInfoScreen_ptr->CreateConstructionInfoScreen();
	messagesAndInfoScreen_ptr->CreateMessagesScreen();
}
//
const MenuScreen* InfoPanel::GetMenuScreen()
{
	return mainScreen_ptr;
}
const ControlsScreen* InfoPanel::GetControlsScreen()
{
	return gameControlInfo_ptr;
}
MessagesAndInfoScreen* InfoPanel::GetMessagesScreen()
{
	return messagesAndInfoScreen_ptr;
}
InfoPanelContentType InfoPanel::GetCurrentContent() const
{
	return currentScreen;
}
//
void InfoPanel::ShowSplashScreen(color foreground, color background)
{
	currentScreen = InfoPanelContentType::SplashScreen;
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
}
void InfoPanel::ShowMenuScreen()
{
	currentScreen = InfoPanelContentType::MenuScreen;
	mainScreen_ptr->DrawBorder();
	mainScreen_ptr->GetMessagesButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderActiveColor());
	mainScreen_ptr->GetControlsButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
	mainScreen_ptr->DrawMenuScreenButton(mainScreen_ptr->GetMessagesButton());
	mainScreen_ptr->DrawMenuScreenButton(mainScreen_ptr->GetControlsButton());
	GetCursor()->CursorMovement(PointCoord(mainScreen_ptr->GetMessagesButton()->GetHalfXAxis(),
		mainScreen_ptr->GetMessagesButton()->GetUpperLeft().Get_y()));
}
void InfoPanel::ShowControls()
{
	currentScreen = InfoPanelContentType::Controls;
	gameControlInfo_ptr->DrawBorder();
	gameControlInfo_ptr->DisplayControls();
}
void InfoPanel::ShowMessagesScreen()
{
	currentScreen = InfoPanelContentType::SystemMessagesAndConstructionInfo;
	messagesAndInfoScreen_ptr->DrawBorder();
	if (!messagesAndInfoScreen_ptr->MessagesIsEmpty())
	{
		messagesAndInfoScreen_ptr->DeleteOldMessages();
		messagesAndInfoScreen_ptr->DisplayMessages();
	}
	else
	{
		messagesAndInfoScreen_ptr->DisplayMessage(GetHalfXAxis() + 2, messagesAndInfoScreen_ptr->GetUpperLeft().Get_y() + 1, "No messages");
	}
	messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->DisplayConstructionInfo();
}
void InfoPanel::SwitchContent(InfoPanelContentType choosenContent)
{
	ClearContent();
	switch (choosenContent)
	{
	case InfoPanelContentType::SplashScreen:
	{
		ShowSplashScreen(ConstructionOptions::GetAllOptions()->GetSplashScreenForegroundColor(), ConstructionOptions::GetAllOptions()->GetSplashScreenBackgroundColor());
		return;
	}
	case InfoPanelContentType::MenuScreen:
	{
		ShowMenuScreen();
		return;
	}
	case InfoPanelContentType::Controls:
	{
		ShowControls();
		return;
	}
	case InfoPanelContentType::SystemMessagesAndConstructionInfo:
	{
		ShowMessagesScreen();
		return;
	}
	default: {return; } //TODO throw exception
	}
}
void InfoPanel::EndInteraction()
{
	if (currentScreen == InfoPanelContentType::MenuScreen)
	{
		mainScreen_ptr->GetMessagesButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
		mainScreen_ptr->GetControlsButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor());
		SwitchContent(InfoPanelContentType::SplashScreen);
	}
}