#include "MainMenu.h"
Button* MainMenu::CreateButton(PointCoord upperLeft, int heightAdd, int widthAdd, wstring verticalSymbol, wstring horizontalSymbol,
	wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol, color borderForegroundColor,
	color borderBackgroundColor, color letterColor, color shadingColor, string buttonTitle) const
{
	MyRectangle* newButtonRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(upperLeft, heightAdd, widthAdd, verticalSymbol, horizontalSymbol, upperLeftSymbol,
		upperRightSymbol, bottomLeftSymbol, bottomRightSymbol, borderForegroundColor, borderBackgroundColor, letterColor, shadingColor, GetDrawPointer(), GetCursor());
	Button* newButton = new Button(newButtonRectangle, buttonTitle);
	delete newButtonRectangle;
	return newButton;
}
Button* MainMenu::CreateButton(PointCoord upperLeft, int heightAdd, int widthAdd, wstring verticalSymbol, wstring horizontalSymbol,
	wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol, color borderForegroundColor,
	color borderBackgroundColor, color letterColor, color shadingColor, string buttonTitle, bool enabled) const
{
	MyRectangle* newButtonRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(upperLeft, heightAdd, widthAdd, verticalSymbol, horizontalSymbol, upperLeftSymbol,
		upperRightSymbol, bottomLeftSymbol, bottomRightSymbol, borderForegroundColor, borderBackgroundColor, letterColor, shadingColor, GetDrawPointer(), GetCursor());
	Button* newButton = new ActivatedByConditionButton(newButtonRectangle, buttonTitle, enabled);
	delete newButtonRectangle;
	return newButton;
}
void MainMenu::CreateButtons()
{
	int continueButtonWidthAdd = ConstructionOptions::GetAllOptions()->GetContinueButtonWidthAdd();
	int continueButtonHeightAdd = ConstructionOptions::GetAllOptions()->GetContinueButtonHeightAdd();
	PointCoord continueButtonUpperLeft = PointCoord(this->GetHalfXAxis() - continueButtonWidthAdd / 2, this->GetUpperLeft().Get_y() + this->GetHeightAddition() / 3);
	continueGame = this->CreateButton(continueButtonUpperLeft, continueButtonHeightAdd, continueButtonWidthAdd,
		ConstructionOptions::GetAllOptions()->GetContinueButtonVerticalSymbol(), ConstructionOptions::GetAllOptions()->GetContinueButtonHorizontalSymbol(),
		ConstructionOptions::GetAllOptions()->GetContinueButtonUpperLeftSymbol(), ConstructionOptions::GetAllOptions()->GetContinueButtonUpperRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetContinueButtonBottomLeftSymbol(), ConstructionOptions::GetAllOptions()->GetContinueButtonBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor(), ConstructionOptions::GetAllOptions()->GetButtonBorderBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor(), ConstructionOptions::GetAllOptions()->GetButtonContentBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetContinueButtonTitle(), true);
	int newGameButtonWidthAdd = ConstructionOptions::GetAllOptions()->GetNewGameButtonWidthAdd();
	int newGameButtonHeightAdd = ConstructionOptions::GetAllOptions()->GetNewGameButtonHeightAdd();
	PointCoord newGameButtonUpperLeft = PointCoord(continueGame->GetUpperLeft().Get_x(), continueGame->GetUpperLeft().Get_y() + continueGame->GetHeightAddition() + 2);
	newGame = this->CreateButton(newGameButtonUpperLeft, newGameButtonHeightAdd, newGameButtonWidthAdd,
		ConstructionOptions::GetAllOptions()->GetNewGameButtonVerticalSymbol(), ConstructionOptions::GetAllOptions()->GetNewGameButtonHorizontalSymbol(),
		ConstructionOptions::GetAllOptions()->GetNewGameButtonUpperLeftSymbol(), ConstructionOptions::GetAllOptions()->GetNewGameButtonUpperRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetNewGameButtonBottomLeftSymbol(), ConstructionOptions::GetAllOptions()->GetNewGameButtonBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor(), ConstructionOptions::GetAllOptions()->GetButtonBorderBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor(), ConstructionOptions::GetAllOptions()->GetButtonContentBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetNewGameButtonTitle());
	int exitButtonWidthAdd = ConstructionOptions::GetAllOptions()->GetExitButtonWidthAdd();
	int exitButtonHeightAdd = ConstructionOptions::GetAllOptions()->GetExitButtonHeightAdd();
	PointCoord exitButtonUpperLeft = PointCoord(newGame->GetUpperLeft().Get_x(), newGame->GetUpperLeft().Get_y() + newGame->GetHeightAddition() + 2);
	exit = this->CreateButton(exitButtonUpperLeft, exitButtonHeightAdd, exitButtonWidthAdd,
		ConstructionOptions::GetAllOptions()->GetExitButtonVerticalSymbol(), ConstructionOptions::GetAllOptions()->GetExitButtonHorizontalSymbol(),
		ConstructionOptions::GetAllOptions()->GetExitButtonUpperLeftSymbol(), ConstructionOptions::GetAllOptions()->GetExitButtonUpperRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetExitButtonBottomLeftSymbol(), ConstructionOptions::GetAllOptions()->GetExitButtonBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetButtonBorderInactiveColor(), ConstructionOptions::GetAllOptions()->GetButtonBorderBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetButtonContentForegroundColor(), ConstructionOptions::GetAllOptions()->GetButtonContentBackgroundColor(),
		ConstructionOptions::GetAllOptions()->GetExitButtonTitle());
}
void MainMenu::DrawTitle(color titleColor) const
{
	GetCursor()->CursorMovement(PointCoord(GetUpperLeft().Get_x() + 27, GetUpperLeft().Get_y() + 5));
	Alphabet::DrawLetter(Alphabet::Get_M_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, titleColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_A_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, titleColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_I_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, titleColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_N_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, titleColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_M_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 3, GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, titleColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_E_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, titleColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_N_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, titleColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_U_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, titleColor);
	GetCursor()->SetCursorConsoleLocation();
}
void MainMenu::Display(color titleColor)
{
	this->DrawTitle(titleColor);
	function<bool()> enableButton = []()
	{
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_file("SavedTycoon.xml");
		if (result)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	continueGame->Display(enableButton);
	newGame->Display();
	exit->Display();
}