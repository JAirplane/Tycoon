#include "MenuScreen_InfoPanel.h"
void MenuScreen::CreateButtons()
{
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
	int buttonHeightAdd = GetHeightAddition() - 2;
	int leftXMenuScreen = GetUpperLeft().Get_x();
	int rightXMenuScreen = leftXMenuScreen + GetWidthAddition();
	int topYButtons = GetUpperLeft().Get_y() + 1;
	int leftXInfoScreenButton = rightXMenuScreen / 2 - rightXMenuScreen / 10 - buttonWidthAdd;
	int leftXControlsButton = rightXMenuScreen / 2 + rightXMenuScreen / 10;
	PointCoord leftButtonUpperLeft = PointCoord(leftXInfoScreenButton, topYButtons);
	PointCoord rightButtonUpperLeft = PointCoord(leftXControlsButton, topYButtons);
	messagesAndInfoButton_ptr = new Button(leftButtonUpperLeft, buttonHeightAdd, buttonWidthAdd, borderVisual_ptr, buttonLetterColor, buttonShadingColor,
		ConstructionOptions::GetAllOptions()->GetInfoScreenButtonTitle(), GetDrawPointer(), GetCursor());
	controlsButton_ptr = new Button(rightButtonUpperLeft, buttonHeightAdd, buttonWidthAdd, controlsButtonBorderVisual_ptr, buttonLetterColor, buttonShadingColor,
		ConstructionOptions::GetAllOptions()->GetControlsButtonTitle(), GetDrawPointer(), GetCursor());
}