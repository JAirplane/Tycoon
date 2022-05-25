#include "InfoPanel.h"
///////////////InfoPanel///////////////
// create Screens
void InfoPanel::CreateMenuScreen()
{
	PointCoord menuScreenUpperLeft = PointCoord(this->GetUpperLeft().Get_x() + 2, this->GetUpperLeft().Get_y() + 2);
	MyRectangle* menuScreenRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(menuScreenUpperLeft,
		DTOCollector::GetCollector()->GetInfoPanelMenuScreenConstants(), this->GetDrawPointer(), this->GetCursor());
	menuScreenRectangle->SetHeightAddition(this->GetHeightAddition() - 4);
	menuScreenRectangle->SetWidthAddition(this->GetWidthAddition() - 4);
	mainScreen_ptr = new MenuScreen(*menuScreenRectangle);
	delete menuScreenRectangle;
	mainScreen_ptr->CreateButtons();
}
void InfoPanel::CreateControlsScreen()
{
	PointCoord controlsScreenUpperLeft = PointCoord(this->GetUpperLeft().Get_x() + 2, this->GetUpperLeft().Get_y() + 2);
	MyRectangle* controlsScreenRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(controlsScreenUpperLeft,
		DTOCollector::GetCollector()->GetInfoPanelControlsScreenConstants(), this->GetDrawPointer(), this->GetCursor());
	controlsScreenRectangle->SetHeightAddition(this->GetHeightAddition() - 4);
	controlsScreenRectangle->SetWidthAddition(this->GetWidthAddition() - 4);
	gameControlInfo_ptr = new ControlsScreen(*controlsScreenRectangle);
	delete controlsScreenRectangle;
	gameControlInfo_ptr->FillControlsDescriptions();
}
void InfoPanel::CreateGameMessagesScreen()
{
	PointCoord messagesAndInfoScreenUpperLeft = PointCoord(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 2);
	MyRectangle* messagesAndInfoScreenRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(messagesAndInfoScreenUpperLeft,
		DTOCollector::GetCollector()->GetInfoPanelMessagesAndInfoScreenConstants(), this->GetDrawPointer(), this->GetCursor());
	messagesAndInfoScreenRectangle->SetHeightAddition(this->GetHeightAddition() - 4);
	messagesAndInfoScreenRectangle->SetWidthAddition(this->GetWidthAddition() - 4);
	messagesAndInfoScreen_ptr = new MessagesAndInfoScreen(*messagesAndInfoScreenRectangle);
	delete messagesAndInfoScreenRectangle;
	messagesAndInfoScreen_ptr->CreateConstructionInfoScreen();
	messagesAndInfoScreen_ptr->CreateMessagesScreen();
}
// when receive notification from GameManagement that user choose some construction on the playing field
void InfoPanel::ChosenConstructionUpdate(Construction* choice_ptr)
{
	SetChosenConstruction(choice_ptr); //already throws exception, if receives nullptr
	if (currentScreen != InfoPanelContentType::SystemMessagesAndConstructionInfo)
	{
		SwitchContent(InfoPanelContentType::SystemMessagesAndConstructionInfo);
	}
	else
	{
		messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->ClearContent();
		messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->DisplayConstructionInfo();
	}
	EraseInfoPanelMessage();
	DisplayInfoPanelMessage("Press 'i' to get to the InfoPanel");
}
// when receive user message from GameManagement
void InfoPanel::UserMessageUpdate(const string message)
{
	if (message.empty())
	{
		throw MyException("InfoPanel::UserMessageUpdate(const string message) received empty string.");
	}
	messagesAndInfoScreen_ptr->AddMessage(message);
	messagesAndInfoScreen_ptr->DeleteOldMessages();
	if (currentScreen != InfoPanelContentType::SystemMessagesAndConstructionInfo)
	{
		SwitchContent(InfoPanelContentType::SystemMessagesAndConstructionInfo);
	}
	else
	{
		messagesAndInfoScreen_ptr->GetMessagesScreen()->ClearContent();
		messagesAndInfoScreen_ptr->DisplayMessages();
	}
	GetCursor()->CursorMovement(GetCursor()->GetCursorConsoleLocation());
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
void InfoPanel::DisplayInfoPanelMessage(string msg)
{
	set_cursor_pos(GetUpperLeft().Get_x() + GetWidthAddition() - 1 - static_cast<int>(msg.length()), GetUpperLeft().Get_y() + 1);
	set_color(GetTextColor(), GetShadingColor());
	cout << msg;
	set_color(cWHITE, cBLACK);
}
void InfoPanel::EraseInfoPanelMessage()
{
	int xCoord = GetUpperLeft().Get_x() + 1;
	int yCoord = GetUpperLeft().Get_y() + 1;
	set_cursor_pos(GetUpperLeft().Get_x() + 1, GetUpperLeft().Get_y() + 1);
	set_color(cBLACK, cBLACK);
	while (xCoord < GetUpperLeft().Get_x() + GetWidthAddition())
	{
		cout << " ";
		++xCoord;
	}
	set_color(cWHITE, cBLACK);
}
void InfoPanel::ShowSplashScreen(color foreground, color background)
{
	PointCoord previousLocation = GetCursor()->GetCursorConsoleLocation();
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
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_Asterisk_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 2, GetCursor()->GetCursorConsoleLocation().Get_y());
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_Asterisk_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 2, GetCursor()->GetCursorConsoleLocation().Get_y() + 1);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_Asterisk_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 2, GetCursor()->GetCursorConsoleLocation().Get_y() + 1);
	DisplayInfoPanelMessage("Press 'i' to get to the InfoPanel");
	GetCursor()->CursorMovement(previousLocation);
}
void InfoPanel::ShowMenuScreen()
{
	currentScreen = InfoPanelContentType::MenuScreen;
	mainScreen_ptr->DrawBorder();
	mainScreen_ptr->GetMessagesButton()->GetBorder()->SetBorderForegroundColor(mainScreen_ptr->GetMessagesButton()->GetInitialCondition()->activeButtonColor);
	mainScreen_ptr->GetControlsButton()->GetBorder()->SetBorderForegroundColor(mainScreen_ptr->GetControlsButton()->GetInitialCondition()->foregroundBorderColor);
	mainScreen_ptr->DrawMenuScreenButton(mainScreen_ptr->GetMessagesButton());
	mainScreen_ptr->DrawMenuScreenButton(mainScreen_ptr->GetControlsButton());
	DisplayInfoPanelMessage("Press 'i' to return to the camera");
	GetCursor()->CursorMovement(PointCoord(mainScreen_ptr->GetMessagesButton()->GetHalfXAxis(),
		mainScreen_ptr->GetMessagesButton()->GetUpperLeft().Get_y()));
}
void InfoPanel::ShowControls()
{
	currentScreen = InfoPanelContentType::Controls;
	DisplayInfoPanelMessage("Press 'esc' to return to the previous screen");
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
void InfoPanel::UpdateConstructionInfo() const
{
	if (currentScreen == InfoPanelContentType::SystemMessagesAndConstructionInfo && messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetChosenConstruction() != nullptr &&
		messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetChosenConstruction()->allTimeVisited !=
		messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetChosenConstruction()->allTimeVisitedOld)
	{
		messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetChosenConstruction()->allTimeVisitedOld =
			messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetChosenConstruction()->allTimeVisited;
		messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->ClearChosenConstructionStatistic();
		messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->ShowChosenConstructionStatistic();
	}
}
void InfoPanel::SwitchContent(InfoPanelContentType choosenContent)
{
	ClearContent();
	switch (choosenContent)
	{
	case InfoPanelContentType::SplashScreen:
	{
		ShowSplashScreen(this->GetTextColor(), this->GetShadingColor());
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
	default: {throw MyException("InfoPanel::SwitchContent(InfoPanelContentType choosenContent) got unknown content type."); } //exception
	}
}
void InfoPanel::GetToInfoPanelDisplayRule()
{
	switch (currentScreen)
	{
	case InfoPanelContentType::SplashScreen:
	{
		SwitchContent(InfoPanelContentType::MenuScreen);
		return;
	}
	case InfoPanelContentType::MenuScreen:
	{
		mainScreen_ptr->GetMessagesButton()->GetBorder()->SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderActiveColor());
		mainScreen_ptr->GetMessagesButton()->DrawBorder();
		GetCursor()->CursorMovement(PointCoord(mainScreen_ptr->GetMessagesButton()->GetHalfXAxis(), mainScreen_ptr->GetMessagesButton()->GetUpperLeft().Get_y()));
		return;
	}
	case InfoPanelContentType::Controls:
	{
		SwitchContent(InfoPanelContentType::MenuScreen);
		return;
	}
	case InfoPanelContentType::SystemMessagesAndConstructionInfo:
	{
		if (messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetChosenConstruction() != nullptr)
		{
			messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetDeconstructButton()->GetBorder()->
				SetBorderForegroundColor(ConstructionOptions::GetAllOptions()->GetButtonBorderActiveColor());
			messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetDeconstructButton()->DrawBorder();
			EraseInfoPanelMessage();
			DisplayInfoPanelMessage("Press 'enter' to deconstruct chosen one");
			GetCursor()->CursorMovement(PointCoord(messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetDeconstructButton()->GetHalfXAxis(),
				messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetDeconstructButton()->GetUpperLeft().Get_y()));
		}
		else
		{
			EraseInfoPanelMessage();
			DisplayInfoPanelMessage("Press 'esc' to get to the previous screen");
			GetCursor()->CursorMovement(PointCoord(messagesAndInfoScreen_ptr->GetHalfXAxis(), messagesAndInfoScreen_ptr->GetUpperLeft().Get_y()));
		}
		return;
	}
	default:
	{
		ShowSplashScreen(this->GetTextColor(), this->GetShadingColor());
		throw MyException("InfoPanel::GetToInfoPanelDisplayRule() currentScreen is undefined.");
	}
	}
}
void InfoPanel::EndInteractionDisplayRule()
{
	switch (currentScreen)
	{
	case InfoPanelContentType::SplashScreen: {return; }
	case InfoPanelContentType::MenuScreen:
	{
		mainScreen_ptr->GetMessagesButton()->GetBorder()->SetBorderForegroundColor(mainScreen_ptr->GetMessagesButton()->GetBorder()->GetBorderForegroundColor());
		mainScreen_ptr->GetControlsButton()->GetBorder()->SetBorderForegroundColor(mainScreen_ptr->GetControlsButton()->GetBorder()->GetBorderForegroundColor());
		SwitchContent(InfoPanelContentType::SplashScreen);
		return;
	}
	case InfoPanelContentType::Controls: {return; }
	case InfoPanelContentType::SystemMessagesAndConstructionInfo:
	{
		EraseInfoPanelMessage();
		DisplayInfoPanelMessage("Press 'i' to get to the InfoPanel");
		if (messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetChosenConstruction() != nullptr)
		{
			messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetDeconstructButton()->GetBorder()->
				SetBorderForegroundColor(messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetDeconstructButton()->GetBorder()->GetBorderForegroundColor());
			messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->GetDeconstructButton()->DrawBorder();
		}
		else
		{
			messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->DisplayConstructionInfo();
		}
		return;
	}
	default:
	{
		ShowSplashScreen(ConstructionOptions::GetAllOptions()->GetSplashScreenForegroundColor(), ConstructionOptions::GetAllOptions()->GetSplashScreenBackgroundColor());
		throw MyException("InfoPanel::EndInteractionDisplayRule() currentScreen is undefined."); //exception
	}
	}
}
void InfoPanel::SetChosenConstruction(Construction* choice_ptr)
{
	messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->SetChosenConstruction(choice_ptr);
}
void InfoPanel::ClearChoosenConstruction()
{
	messagesAndInfoScreen_ptr->GetConstructionInfoScreen()->ClearChosenConstruction();
}