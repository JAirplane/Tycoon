#include "MessagesAndInfoScreen_InfoPanel.h"
void GameMessagesScreen::AddMessage(const string msg)
{
	messages.push_front(msg);
}
void GameMessagesScreen::DeleteMessage()
{
	messages.pop_back();
}
void GameMessagesScreen::DisplayMessage(int initialX, int initialY, string message, color letterColor, color background)
{
	GetDrawPointer()->WriteMessage(initialX, initialY, message, letterColor, background);
}
void GameMessagesScreen::DeleteOldMessages()
{
	while (messages.size() > (GetHeightAddition() + 1 - ConstructionOptions::GetAllOptions()->GetInfoPanelAboveIndent() - ConstructionOptions::GetAllOptions()->GetInfoPanelBottomIndent()))
	{
		DeleteMessage();
	}
}
void GameMessagesScreen::DisplayMessages()
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