#pragma once
#include "ControlsScreen_InfoPanel.h"
class MessagesAndInfoScreen : public SplitScreen
{
private:
	MyRectangle* messagesScreen_ptr;
	ConstructionInfoScreen* constructionInfo_ptr;
	list<string> messages;
public:
	MessagesAndInfoScreen(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : SplitScreen(upperLeft, initial, vis_ptr, cur_ptr)
	{
		messagesScreen_ptr = nullptr;
		constructionInfo_ptr = nullptr;
	}
	MessagesAndInfoScreen(MyRectangle& someRectangle) : SplitScreen(someRectangle)
	{
		messagesScreen_ptr = nullptr;
		constructionInfo_ptr = nullptr;
	}
	virtual ~MessagesAndInfoScreen()
	{
		delete messagesScreen_ptr;
		delete constructionInfo_ptr;
	}
	void CreateMessagesScreen();
	void CreateConstructionInfoScreen();
	//
	ConstructionInfoScreen* GetConstructionInfoScreen() const;
	MyRectangle* GetMessagesScreen() const;
	//
	bool MessagesIsEmpty();
	void AddMessage(const string msg);
	void DeleteMessage();
	void DisplayMessage(int initialX, int initialY, string message);
	void DeleteOldMessages();
	void DisplayMessages();
};