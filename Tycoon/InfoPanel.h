#pragma once
#include "Menu.h"
#include "Alphabet.h"
class InfoScreenButton : public MyRectangle
{
private:
	string title;
public:
	InfoScreenButton(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* externalBorder, color letterColor,
		color shadingColor, string buttonTitle) : MyRectangle(upperLeft, heightAdd, widthAdd, externalBorder, letterColor, shadingColor)
	{
		title = buttonTitle;
		RectangleSymbols* infoScreenButtonBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuScreenButtonVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenButtonHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenButtonUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenButtonUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenButtonBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenButtonBottomRightSymbol());
		color borderForegroundColor = ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor();
		color borderBackgroundColor = ConstructionOptions::GetAllOptions()->GetButtonBorderBackgroundColor();
		BorderAppearance* borderVisual_ptr = new BorderAppearance(infoScreenButtonBorderSymbols_ptr, borderForegroundColor, borderBackgroundColor);
		color titleColor = ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor();
		color shadingColor = ConstructionOptions::GetAllOptions()->GetButtonContentBackgroundColor();
	}
	~InfoScreenButton()
		{}
	string GetButtonTitle() const;
};
class InfoPanel : public MyRectangle
{
private:
	Visualisation* draw_ptr;
	Cursor* cursor_ptr;
	MyRectangle* menuScreen;
	InfoScreenButton* leftButton_ptr;
	InfoScreenButton* rightButton_ptr;
	RectangleSymbols* controlsBorderSymbols_ptr;
	list<string> messages;
	vector<string> controls;
public:
	InfoPanel(Visualisation* drawptr, Cursor* cursorptr, PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* externalBorder, color letterColor,
		color shadingColor, InfoScreenButton* lButton_ptr, InfoScreenButton* rButton_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, externalBorder, letterColor, shadingColor)
	{
		draw_ptr = drawptr;
		cursor_ptr = cursorptr;
		/*RectangleSymbols* borderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetInfoPanelVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoPanelHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoPanelUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetInfoPanelBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetInfoPanelBottomRightSymbol());
		color borderForegroundColor = ConstructionOptions::GetAllOptions()->GetInfoPanelBorderForegroundColor();
		color borderBackgroundColor = ConstructionOptions::GetAllOptions()->GetInfoPanelBorderBackgroundColor();
		BorderAppearance* externalBorder = new BorderAppearance(borderSymbols_ptr, borderForegroundColor, borderBackgroundColor);
		color letterColor = ConstructionOptions::GetAllOptions()->GetInfoPanelTextColor();
		color shadingColor = ConstructionOptions::GetAllOptions()->GetInfoPanelShadingColor();*/
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
		menuScreen = new MyRectangle(menuScreenUpperLeft, heightAdd - 4, widthAdd - 4, menuScreenBorder, menuLetterColor, menuShadingColor);
		RectangleSymbols* infoScreenButtonBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetMenuScreenButtonVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenButtonHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenButtonUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenButtonUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetMenuScreenButtonBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetMenuScreenButtonBottomRightSymbol());
		color borderForegroundColor = ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor();
		color borderBackgroundColor = ConstructionOptions::GetAllOptions()->GetButtonBorderBackgroundColor();
		BorderAppearance* borderVisual_ptr = new BorderAppearance(infoScreenButtonBorderSymbols_ptr, borderForegroundColor, borderBackgroundColor);
		color buttonLetterColor = ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor();
		color buttonShadingColor = ConstructionOptions::GetAllOptions()->GetButtonContentBackgroundColor();
		
		int buttonWidth = ConstructionOptions::GetAllOptions()->GetInfoPanelButtonWidth();
		int leftX = GetUpperLeft().Get_x();
		int topY = GetUpperLeft().Get_y();
		int rightX = GetUpperLeft().Get_x() + GetWidthAddition();
		int bottomY = GetUpperLeft().Get_y() + GetHeightAddition();
		int leftXFirstButton = rightX / 2 - rightX / 10 - buttonWidth;
		int leftXSecondButton = rightX / 2 + rightX / 10;
		PointCoord leftButtonUpperLeft = PointCoord(rightX / 2 - rightX / 10 - ConstructionOptions::GetAllOptions()->Get);
		DrawInfoScreenButton(leftXFirstButton, topY + 3, leftXFirstButton + buttonWidth, topY + 7, ConstructionOptions::GetAllOptions()->GetControlsButtonTitle(),
			letterColor, insideBackground, buttonActive, backgroundBorder);
		DrawInfoScreenButton(leftXSecondButton, topY + 3, leftXSecondButton + buttonWidth, topY + 7, ConstructionOptions::GetAllOptions()->GetInfoScreenButtonTitle(),
			letterColor, insideBackground, foregroundBorder, backgroundBorder);

		controlsBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetControlsVerticalSymbol(),
			ConstructionOptions::GetAllOptions()->GetControlsHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetControlsUpperLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetControlsUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetControlsBottomLeftSymbol(),
			ConstructionOptions::GetAllOptions()->GetControlsBottomRightSymbol());
		//

		leftButton_ptr = lButton_ptr;
		rightButton_ptr = rButton_ptr;
		controls.push_back("Use arrows to navigate on the playingfield / navigate in menu");
		controls.push_back("Tab to switch between main screen and menu");
		controls.push_back("Enter to select construction in the menu / to build it on the playingfield");
		controls.push_back("Esc to deselect construction");
		controls.push_back("'H' key to hide / show menu elements");
		controls.push_back("'S' key to switch menu side");
		controls.push_back("'R' key rotates buildings");
	}
	~InfoPanel()
	{
		delete externalBorderSymbols_ptr;
		delete infoScreenBorderSymbols_ptr;
		delete controlsBorderSymbols_ptr;
	}
	void DrawInfoPanelExternalBorders();
	void EraseInfoPanelExternalBorders();
	void ClearInfoPanelContent();
	void DrawInfoPanelSplashScreen(color foreground, color background);
	void AddMessage(const string);
	void DeleteMessage();
	void DisplayMessage(int initialX, int initialY, string message, color letterColor, color background = cBLACK);
	void DeleteOldMessages();
	void DisplayMessages();
	void DrawInfoScreenBorders(int leftX, int topY, int rightX, int bottomY, color foreground, color background = cBLACK);
	void DrawInfoScreenButton(int leftX, int topY, int rightX, int bottomY, string buttonTitle, color letterColor,
		color insideBackground, color foregroundBorder, color backgroundBorder = cBLACK);
	void DrawInfoScreen(int buttonWidth, color letterColor, color insideBackground, color foregroundBorder, color buttonActive, color backgroundBorder = cBLACK);
	void DrawControlsBorder(int leftX, int topY, int rightX, int bottomY, color foreground, color background = cBLACK);
	void ShowControls(color foreground, color background = cBLACK);
	void SwitchContent(InfoPanelContentType choosenContent);
};