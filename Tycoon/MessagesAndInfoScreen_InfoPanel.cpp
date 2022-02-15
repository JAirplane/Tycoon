#include "MessagesAndInfoScreen_InfoPanel.h"
void MessagesAndInfoScreen::CreateMessagesScreen()
{
	RectangleSymbols* messagesScreenSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol(),
		ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol(), ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol(),
		ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol(), ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol(),
		ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol());
	BorderAppearance* messagesScreenBorder_ptr = new BorderAppearance(messagesScreenSymbols_ptr, cBLACK, cBLACK);
	color messagesScreenLetterColor = ConstructionOptions::GetAllOptions()->GetMessagesPartScreenLetterColor();
	color messagesScreenShadingColor = ConstructionOptions::GetAllOptions()->GetMessagesPartScreenShadingColor();
	messagesScreen_ptr = new MyRectangle(PointCoord(GetHalfXAxis() + 1, GetUpperLeft().Get_y()), GetHeightAddition(), GetHalfYAxis() - 1, messagesScreenBorder_ptr,
		messagesScreenLetterColor, messagesScreenShadingColor, GetDrawPointer(), GetCursor());
}
void MessagesAndInfoScreen::CreateConstructionInfoScreen()
{
	RectangleSymbols* constructionInfoScreenSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol(),
		ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol(), ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol(),
		ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol(), ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol(),
		ConstructionOptions::GetAllOptions()->GetEmptyRectangleBorderSymbol());
	BorderAppearance* constructionInfoScreenBorder_ptr = new BorderAppearance(constructionInfoScreenSymbols_ptr, cBLACK, cBLACK);
	color constructionInfoScreenLetterColor = ConstructionOptions::GetAllOptions()->GetInfoPartScreenLetterColor();
	color constructionInfoScreenShadingColor = ConstructionOptions::GetAllOptions()->GetInfoPartScreenShadingColor();
	constructionInfo_ptr = new ConstructionInfoScreen(GetUpperLeft(), GetHeightAddition(), GetHalfYAxis() - 1, constructionInfoScreenBorder_ptr,
		constructionInfoScreenLetterColor, constructionInfoScreenShadingColor, GetDrawPointer(), GetCursor());
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
		return 1;
	}
	else
	{
		return 0;
	}
}
void MessagesAndInfoScreen::AddMessage(const string msg)
{
	messages.push_front(msg);
}
void MessagesAndInfoScreen::DeleteMessage()
{
	messages.pop_back();
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