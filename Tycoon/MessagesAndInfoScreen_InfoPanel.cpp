#include "MessagesAndInfoScreen_InfoPanel.h"
void MessagesAndInfoScreen::CreateMessagesScreen()
{
	messagesScreen_ptr = RectangleCreator::GetRectangleFactory()->CreateRectangle(PointCoord(this->GetHalfXAxis() + 1, this->GetUpperLeft().Get_y()),
		DTOCollector::GetCollector()->GetFigureConstants("infoPanelMessagesAndInfoScreen"), this->GetDrawPointer(), this->GetCursor());
	messagesScreen_ptr->SetHeightAddition(this->GetHeightAddition());
	messagesScreen_ptr->SetWidthAddition(this->GetWidthAddition() / 2);
}
void MessagesAndInfoScreen::CreateConstructionInfoScreen()
{
	MyRectangle* constructionInfoScreenRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(this->GetUpperLeft(),
		DTOCollector::GetCollector()->GetFigureConstants("infoPanelConstructionInfoScreen"), this->GetDrawPointer(), this->GetCursor());
	constructionInfoScreenRectangle->SetHeightAddition(this->GetHeightAddition());
	constructionInfoScreenRectangle->SetWidthAddition(this->GetWidthAddition() / 2 - 1);
	constructionInfo_ptr = new ConstructionInfoScreen(*constructionInfoScreenRectangle);
	delete constructionInfoScreenRectangle;
	constructionInfo_ptr->CreateDeconstructButton();
	constructionInfo_ptr->CreateConstructionIcon();
}
//
ConstructionInfoScreen* MessagesAndInfoScreen::GetConstructionInfoScreen() const
{
	return constructionInfo_ptr;
}
MyRectangle* MessagesAndInfoScreen::GetMessagesScreen() const
{
	return messagesScreen_ptr;
}
//
bool MessagesAndInfoScreen::MessagesIsEmpty()
{
	if (messages.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void MessagesAndInfoScreen::AddMessage(const string msg)
{
	messages.push_front(msg);
}
void MessagesAndInfoScreen::DeleteMessage()
{
	if (!messages.empty())
	{
		messages.pop_back();
	}
}
void MessagesAndInfoScreen::DisplayMessage(int initialX, int initialY, string message)
{
	GetDrawPointer()->WriteMessage(initialX, initialY, message, messagesScreen_ptr->GetTextColor(), messagesScreen_ptr->GetShadingColor());
}
void MessagesAndInfoScreen::DeleteOldMessages()
{
	while (messages.size() > (static_cast<unsigned long long>(messagesScreen_ptr->GetHeightAddition()) - 1))
	{
		DeleteMessage();
	}
}
void MessagesAndInfoScreen::DisplayMessages()
{
	if (!messages.empty())
	{
		messagesScreen_ptr->ClearContent();
		list<string>::iterator messageIter;
		int initialX = messagesScreen_ptr->GetUpperLeft().Get_x() + 1;
		int initialY = messagesScreen_ptr->GetUpperLeft().Get_y() + 1;
		int count = 0;
		for (messageIter = messages.begin(); messageIter != messages.end() && count < GetHeightAddition() - 1; messageIter++, ++count)
		{
			DisplayMessage(initialX, initialY, (*messageIter));
			++initialY;
		}
	}
}