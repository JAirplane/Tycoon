#pragma once
#include "Menu.h"
#include "Alphabet.h"
class InfoScreenButton : public MyRectangle
{
private:
	string title;
public:
	InfoScreenButton(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* externalBorder, color letterColor, color shadingColor, string buttonTitle,
		Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, externalBorder, letterColor, shadingColor, vis_ptr, cur_ptr)
	{
		title = buttonTitle;
	}
	~InfoScreenButton()
		{}
	string GetButtonTitle() const;
};
class InfoPanel : public MyRectangle
{
private:
	MyRectangle* menuScreen;
	InfoScreenButton* messagesAndInfoButton_ptr;
	InfoScreenButton* controlsButton_ptr;
	MyRectangle* controlsScreen;
	vector<string> controlsDescription;
	MyRectangle* messagesAndInfoScreen;
	list<string> messages;
	InfoPanelContentType currentScreen;
	
public:
	InfoPanel(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* externalBorder, color letterColor,
		color shadingColor, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, externalBorder, letterColor, shadingColor, vis_ptr, cur_ptr)
	{
		//Menu Screen initialisation
		RectangleSymbols* menuScreenBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuScreenVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenBottomRightSymbol());
		color menuScreenBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetMenuScreenBorderForegroundColor();
		color menuScreenBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetMenuScreenBorderBackgroundColor();
		BorderAppearance* menuScreenBorder = new BorderAppearance(menuScreenBorderSymbols_ptr, menuScreenBorderForegroundColor, menuScreenBorderBackgroundColor);
		color menuLetterColor = ConstructionOptions::GetAllOptions()->GetMenuScreenTextColor();
		color menuShadingColor = ConstructionOptions::GetAllOptions()->GetMenuScreenShadingColor();
		PointCoord menuScreenUpperLeft = PointCoord(upperLeft.Get_x() + 2, upperLeft.Get_y() + 2);
		int menuScreenHeightAdd = heightAdd - 4;
		int menuScreenWidthAdd = widthAdd - 4;
		menuScreen = new MyRectangle(menuScreenUpperLeft, menuScreenHeightAdd, menuScreenWidthAdd, menuScreenBorder, menuLetterColor, menuShadingColor, vis_ptr, cur_ptr);
		//Buttons on Menu Screen initialisation
		RectangleSymbols* infoScreenButtonBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuScreenButtonVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenButtonHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenButtonUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenButtonUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenButtonBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenButtonBottomRightSymbol());
		color borderForegroundColor = ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor();
		color borderBackgroundColor = ConstructionOptions::GetAllOptions()->GetButtonBorderBackgroundColor();
		BorderAppearance* borderVisual_ptr = new BorderAppearance(infoScreenButtonBorderSymbols_ptr, borderForegroundColor, borderBackgroundColor);
		BorderAppearance* controlsButtonBorderVisual_ptr = new BorderAppearance(*borderVisual_ptr);
		color buttonLetterColor = ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor();
		color buttonShadingColor = ConstructionOptions::GetAllOptions()->GetButtonContentBackgroundColor();
		int buttonWidthAdd = ConstructionOptions::GetAllOptions()->GetInfoPanelButtonWidthAdd();
		int buttonHeightAdd = menuScreenHeightAdd - 2;
		int leftX = GetUpperLeft().Get_x();
		int topYButtons = GetUpperLeft().Get_y() + 3;
		int rightX = leftX + widthAdd;
		int leftXInfoScreenButton = rightX / 2 - rightX / 10 - buttonWidthAdd;
		int leftXControlsButton = rightX / 2 + rightX / 10;
		PointCoord leftButtonUpperLeft = PointCoord(leftXInfoScreenButton, topYButtons);
		PointCoord rightButtonUpperLeft = PointCoord(leftXControlsButton, topYButtons);
		messagesAndInfoButton_ptr = new InfoScreenButton(leftButtonUpperLeft, buttonHeightAdd, buttonWidthAdd, borderVisual_ptr, buttonLetterColor, buttonShadingColor, 
			ConstructionOptions::GetAllOptions()->GetInfoScreenButtonTitle(), vis_ptr, cur_ptr);
		controlsButton_ptr = new InfoScreenButton(rightButtonUpperLeft, buttonHeightAdd, buttonWidthAdd, controlsButtonBorderVisual_ptr, buttonLetterColor, buttonShadingColor,
			ConstructionOptions::GetAllOptions()->GetControlsButtonTitle(), vis_ptr, cur_ptr);
		//Controls Screen initialisation
		RectangleSymbols* controlsBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetControlsVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetControlsHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetControlsUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetControlsUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetControlsBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetControlsBottomRightSymbol());
		color controlsScreenBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetControlsScreenBorderForegroundColor();
		color controlsScreenBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetControlsScreenBorderBackgroundColor();
		BorderAppearance* controlsBorderVisual_ptr = new BorderAppearance(controlsBorderSymbols_ptr, controlsScreenBorderForegroundColor, controlsScreenBorderBackgroundColor);
		color controlsLetterColor = ConstructionOptions::GetAllOptions()->GetControlsScreenLetterColor();
		color controlsShadingColor = ConstructionOptions::GetAllOptions()->GetControlsScreenShadingColor();
		PointCoord controlsScreenUpperLeft = PointCoord(upperLeft.Get_x() + 2, upperLeft.Get_y() + 2);
		int controlsScreenHeightAdd = heightAdd - 4;
		int controlsScreenWidthAdd = widthAdd - 4;
		controlsScreen = new MyRectangle(controlsScreenUpperLeft, controlsScreenHeightAdd, controlsScreenWidthAdd, 
			controlsBorderVisual_ptr, controlsLetterColor, controlsShadingColor, vis_ptr, cur_ptr);
		controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetArrowsDescription());
		controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetTabDescription());
		controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetEnterDescription());
		controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetEscDescription());
		controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetHKeyDescription());
		controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetSKeyDescription());
		controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetRKeyDescription());
		//Messages and info Screen initialisation
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
		PointCoord messagesAndInfoScreenUpperLeft = PointCoord(upperLeft.Get_x() + 2, upperLeft.Get_y() + 2);
		int messagesAndInfoScreenHeightAdd = heightAdd - 4;
		int messagesAndInfoScreenWidthAdd = widthAdd - 4;
		messagesAndInfoScreen = new MyRectangle(messagesAndInfoScreenUpperLeft, messagesAndInfoScreenHeightAdd, messagesAndInfoScreenWidthAdd,
			messagesAndInfoBorderVisual_ptr, messagesAndInfoLetterColor, messagesAndInfoShadingColor, vis_ptr, cur_ptr);
		currentScreen = InfoPanelContentType::None;
	}
	~InfoPanel()
	{
		delete menuScreen;
		delete messagesAndInfoButton_ptr;
		delete controlsButton_ptr;
		delete controlsScreen;
		delete messagesAndInfoScreen;
	}
	void DrawSplashScreen(color foreground, color background);
	void AddMessage(const string);
	void DeleteMessage();
	void DisplayMessage(int initialX, int initialY, string message, color letterColor, color background = cBLACK);
	void DeleteOldMessages();
	void DisplayMessages();
	void DrawMenuScreenButton(InfoScreenButton* button_ptr);
	void DrawMenuScreen();
	void ShowControls();
	void SwitchContent(InfoPanelContentType choosenContent);
	void Arrows(Direction arrowDir);
	void EndInteraction();
};