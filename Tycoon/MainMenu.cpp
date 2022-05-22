#include "MainMenu.h"
Button* MainMenu::CreateButton(PointCoord upperLeft, int heightAdd, int widthAdd, wstring verticalSymbol, wstring horizontalSymbol,
	wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol, color borderForegroundColor,
	color borderBackgroundColor, color letterColor, color shadingColor, string buttonTitle, color activeColor, color pressedButtonColor, bool createActivated) const
{
	Button* newButton = nullptr;
	MyRectangle newButtonRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(upperLeft, heightAdd, widthAdd, verticalSymbol, horizontalSymbol, upperLeftSymbol,
		upperRightSymbol, bottomLeftSymbol, bottomRightSymbol, borderForegroundColor, borderBackgroundColor, letterColor, shadingColor, GetDrawPointer(), GetCursor());
	if (createActivated)
	{
		newButton = new ActivatedByConditionButton(newButtonRectangle, buttonTitle, activeColor, pressedButtonColor);
	}
	else
	{
		newButton = new Button(newButtonRectangle, buttonTitle, activeColor, pressedButtonColor);
	}
	return newButton;
}
Button* MainMenu::CreateButton(PointCoord upperLeft, string buttonTitleXML, string buttonTitle, bool createActivated) const
{
	Button* newButton = nullptr;
	Button someButton = RectangleCreator::GetRectangleFactory()->CreateButton(upperLeft,
		XMLDownloader::GetDownloader()->DownloadButtonConstants(buttonTitleXML), this->GetDrawPointer(), this->GetCursor());
	if (createActivated)
	{
		newButton = new ActivatedByConditionButton(someButton);
	}
	else
	{
		newButton = new Button(someButton);
	}
	return newButton;
}
void MainMenu::CreateButtons()
{
	RectangleConstantsXML continueButtonConstants = XMLDownloader::GetDownloader()->DownloadRectangleConstants("continueButton");
	PointCoord continueButtonUpperLeft = PointCoord(this->GetHalfXAxis() - continueButtonConstants.widthAddition / 2, this->GetUpperLeft().Get_y() + this->GetHeightAddition() / 3);
	continueGame = this->CreateButton(continueButtonUpperLeft, "continueButton", ConstructionOptions::GetAllOptions()->GetContinueButtonTitle(), true);
	PointCoord newGameButtonUpperLeft = PointCoord(continueGame->GetUpperLeft().Get_x(), continueGame->GetUpperLeft().Get_y() + continueGame->GetHeightAddition() + 2);
	newGame = this->CreateButton(newGameButtonUpperLeft, "newGameButton", ConstructionOptions::GetAllOptions()->GetNewGameButtonTitle(), false);
	PointCoord exitButtonUpperLeft = PointCoord(newGame->GetUpperLeft().Get_x(), newGame->GetUpperLeft().Get_y() + newGame->GetHeightAddition() + 2);
	exit = this->CreateButton(exitButtonUpperLeft, "exitButton",
		ConstructionOptions::GetAllOptions()->GetExitButtonTitle(), false);
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