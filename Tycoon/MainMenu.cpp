#include "MainMenu.h"
Button* MainMenu::CreateButton(PointCoord upperLeft, RectangleConstantsXML* initial, bool createActivated) const
{
	Button* newButton = nullptr;
	Button* intermediary = RectangleCreator::GetRectangleFactory()->CreateButton(upperLeft, initial, GetDrawPointer(), GetCursor());
	if (createActivated)
	{
		newButton = new ActivatedByConditionButton(*intermediary);
	}
	else
	{
		newButton = new Button(*intermediary);
	}
	delete intermediary;
	return newButton;
}
Button* MainMenu::CreateButton(PointCoord upperLeft, string buttonTitleXML, bool createActivated) const
{
	Button* newButton = nullptr;
	Button* intermediary = RectangleCreator::GetRectangleFactory()->CreateButton(upperLeft,
		DTOCollector::GetCollector()->GetFigureConstants(buttonTitleXML), this->GetDrawPointer(), this->GetCursor());
	if (createActivated)
	{
		newButton = new ActivatedByConditionButton(*intermediary);
	}
	else
	{
		newButton = new Button(*intermediary);
	}
	delete intermediary;
	return newButton;
}
void MainMenu::CreateButtons()
{
	RectangleConstantsXML* continueButtonConstants = DTOCollector::GetCollector()->GetFigureConstants("continueButton");
	PointCoord continueButtonUpperLeft = PointCoord(this->GetHalfXAxis() - continueButtonConstants->widthAddition / 2, this->GetUpperLeft().Get_y() + this->GetHeightAddition() / 3);
	continueGame = this->CreateButton(continueButtonUpperLeft, "continueButton", true);
	PointCoord newGameButtonUpperLeft = PointCoord(continueGame->GetUpperLeft().Get_x(), continueGame->GetUpperLeft().Get_y() + continueGame->GetHeightAddition() + 2);
	newGame = this->CreateButton(newGameButtonUpperLeft, "newGameButton", false);
	PointCoord exitButtonUpperLeft = PointCoord(newGame->GetUpperLeft().Get_x(), newGame->GetUpperLeft().Get_y() + newGame->GetHeightAddition() + 2);
	exit = this->CreateButton(exitButtonUpperLeft, "exitButton", false);
}
Button* MainMenu::GetNewGameButton() const
{
	return newGame;
}
Button* MainMenu::GetContinueButton() const
{
	return continueGame;
}
Button* MainMenu::GetExitButton() const
{
	return exit;
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
		return result;
	};
	continueGame->Display(enableButton);
	newGame->Display();
	exit->Display();
}
Button* MainMenu::GetCurrentActiveButton(const Cursor* cursor_ptr) const
{
	if (cursor_ptr->GetCursorConsoleLocation().Get_y() == continueGame->GetUpperLeft().Get_y())
	{
		return continueGame;
	}
	else if (cursor_ptr->GetCursorConsoleLocation().Get_y() == newGame->GetUpperLeft().Get_y())
	{
		return newGame;
	}
	else if (cursor_ptr->GetCursorConsoleLocation().Get_y() == exit->GetUpperLeft().Get_y())
	{
		return exit;
	}
	else
	{
		throw MyException("MainMenu::GetCurrentActiveButton(const Cursor* cursor_ptr) const bad cursor position");
	}
}
void MainMenu::ActiveButtonUp(Cursor* cursor_ptr)
{
	Button* currentActive = GetCurrentActiveButton(cursor_ptr);
	if (currentActive == continueGame)
	{
		return;
	}
	else if (currentActive == newGame)
	{
		if (continueGame->GetEnabled())
		{
			currentActive->RedrawBorder(currentActive->GetInitialCondition()->foregroundBorderColor, currentActive->GetInitialCondition()->backgroundBorderColor);
			continueGame->RedrawBorder(continueGame->GetInitialCondition()->foregroundBorderColor, continueGame->GetInitialCondition()->activeButtonColor);
			cursor_ptr->CursorMovement(PointCoord(continueGame->GetHalfXAxis(), continueGame->GetUpperLeft().Get_y()));
		}
		else
		{
			return;
		}
	}
	else if (currentActive == exit)
	{
		currentActive->RedrawBorder(currentActive->GetInitialCondition()->foregroundBorderColor, currentActive->GetInitialCondition()->backgroundBorderColor);
		newGame->RedrawBorder(newGame->GetInitialCondition()->foregroundBorderColor, newGame->GetInitialCondition()->activeButtonColor);
		cursor_ptr->CursorMovement(PointCoord(newGame->GetHalfXAxis(), newGame->GetUpperLeft().Get_y()));
	}
	else
	{
		throw MyException("MainMenu::ActiveButtonUp(Cursor* cursor_ptr) bad current active button");
	}
}
void MainMenu::ActiveButtonDown(Cursor* cursor_ptr)
{
	Button* currentActive = GetCurrentActiveButton(cursor_ptr);
	if (currentActive == continueGame)
	{
		currentActive->RedrawBorder(currentActive->GetInitialCondition()->foregroundBorderColor, currentActive->GetInitialCondition()->backgroundBorderColor);
		newGame->RedrawBorder(newGame->GetInitialCondition()->foregroundBorderColor, newGame->GetInitialCondition()->activeButtonColor);
		cursor_ptr->CursorMovement(PointCoord(newGame->GetHalfXAxis(), newGame->GetUpperLeft().Get_y()));
	}
	else if (currentActive == newGame)
	{
		currentActive->RedrawBorder(currentActive->GetInitialCondition()->foregroundBorderColor, currentActive->GetInitialCondition()->backgroundBorderColor);
		exit->RedrawBorder(exit->GetInitialCondition()->foregroundBorderColor, exit->GetInitialCondition()->activeButtonColor);
		cursor_ptr->CursorMovement(PointCoord(exit->GetHalfXAxis(), exit->GetUpperLeft().Get_y()));
	}
	else if (currentActive == exit)
	{
		return;
	}
	else
	{
		throw MyException("MainMenu::ActiveButtonDown(Cursor* cursor_ptr) bad current active button");
	}
}
int MainMenu::PressButton(Cursor* cursor_ptr)
{
	Button* currentActive = GetCurrentActiveButton(cursor_ptr);
	if (currentActive == continueGame)
	{
		return 3;
	}
	else if (currentActive == newGame)
	{
		return 2;
	}
	else if (currentActive == exit)
	{
		return 1;
	}
	else
	{
		throw MyException("MainMenu::ActiveButtonDown(Cursor* cursor_ptr) bad current active button");
	}
}