#include "StartScreen.h"
void InitialScreen::CreatePressAnyKey()
{
	RectangleConstantsXML pressAnyKeyConstants = XMLDownloader::GetDownloader()->DownloadRectangleConstants("pressAnyKey");
	PointCoord pressAnyKeyUpperLeft = PointCoord(GetHalfXAxis() - (pressAnyKeyConstants.widthAddition + 1) / 2, GetUpperLeft().Get_y() + 20);
	MyRectangle* pressAnyKeyRectangle = RectangleCreator::GetRectangleFactory()->CreateRectangle(pressAnyKeyUpperLeft,
		pressAnyKeyConstants, this->GetDrawPointer(), this->GetCursor());
	pressAnyKey = new MyRectangle(pressAnyKeyRectangle);
	delete pressAnyKeyRectangle;
}
const MyRectangle* InitialScreen::GetPressAnyKey() const
{
	return pressAnyKey;
}
void InitialScreen::ShowGameTitle(color textColor) const
{
	GetCursor()->CursorMovement(PointCoord(GetUpperLeft().Get_x() + 9, GetUpperLeft().Get_y() + 10));
	Alphabet::DrawLetter(Alphabet::Get_F_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_A_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_I_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_R_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_Y_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	//
	Alphabet::DrawLetter(Alphabet::Get_T_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 3, GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_A_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_L_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_E_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	//
	Alphabet::DrawLetter(Alphabet::Get_P_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 3, GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_A_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_R_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_K_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	set_color(cBLACK);
}
void InitialScreen::ShowAuthor(color textColor) const
{
	GetCursor()->CursorMovement(PointCoord(GetUpperLeft().Get_x() + GetWidthAddition() - author.size() - 9, GetUpperLeft().Get_y() + 18));
	set_color(textColor);
	cout << author;
	set_color(cBLACK);
}
void InitialScreen::DrawHaveFunIscription(color textColor) const
{
	int xCoord = this->GetUpperLeft().Get_x() + 28;
	int yCoord = pressAnyKey->GetUpperLeft().Get_y() + 10;
	GetCursor()->CursorMovement(PointCoord(xCoord, yCoord));
	Alphabet::DrawLetter(Alphabet::Get_H_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_A_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_V_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_E_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_F_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 3, GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_U_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_N_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x(), GetCursor()->GetCursorConsoleLocation().Get_y(), cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	Alphabet::DrawLetter(Alphabet::Get_ExclamationMark_Matrix(), GetCursor()->GetCursorConsoleLocation().Get_x() + 1, GetCursor()->GetCursorConsoleLocation().Get_y(),
		cBLACK, textColor);
	GetCursor()->SetCursorConsoleLocation();
	set_color(cBLACK);
}
void InitialScreen::DrawPressAnyKeyLetter(char letter, PointCoord position, color letterColor) const
{
	set_color(letterColor);
	GetCursor()->CursorMovement(position);
	cout << letter;
	set_color(cBLACK);
}
void InitialScreen::PressAnyKeyAnimation() const
{
	srand(static_cast<unsigned int>(time(0)));
	color inscriptionColor = static_cast<color>(rand() % 14 + 1);
	int newColor = -1;
	while (true)
	{
		int letterPositionXCoord = pressAnyKey->GetUpperLeft().Get_x() + 1;
		int letterPositionYCoord = pressAnyKey->GetUpperLeft().Get_y() + 1;
		do
		{
			newColor = rand() % 14 + 1;
		} while (static_cast<color>(newColor) == inscriptionColor);
		inscriptionColor = static_cast<color>(newColor);
		for (auto letter : pressAnyKeyInscrition)
		{
			this->DrawPressAnyKeyLetter(letter, PointCoord(letterPositionXCoord, letterPositionYCoord), inscriptionColor);
			if (_kbhit()) { return; }
			++letterPositionXCoord;
			wait(100);
		}
	}
}