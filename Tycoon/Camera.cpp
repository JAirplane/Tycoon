#include "Camera.h"
///////////////Camera Class///////////////
Direction Camera::CursorBordersCheck(Cursor* cursor_ptr, PlayingField* field_ptr)
{
	Direction shiftDirection;
	int playingFieldLeftX = field_ptr->GetUpperLeft().Get_x();
	int playingFieldTopY = field_ptr->GetUpperLeft().Get_y();
	int playingFieldRightX = field_ptr->GetUpperLeft().Get_x() + field_ptr->GetWidthAddition();
	int playingFieldBottomY = field_ptr->GetUpperLeft().Get_x() + field_ptr->GetHeightAddition();
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_x() == GetUpperLeft().Get_x() && (playingFieldLeftX - GetUpperLeft().Get_x()) < 4)
	{
		shiftDirection = Direction::Right;
		return shiftDirection;
	}
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_y() == GetUpperLeft().Get_y() && (playingFieldTopY - GetUpperLeft().Get_y()) < 4)
	{
		shiftDirection = Direction::Down;
		return shiftDirection;
	}
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_x() == (GetUpperLeft().Get_x() + GetWidthAddition()) && (GetUpperLeft().Get_x() + GetWidthAddition() - playingFieldRightX) < 4)
	{
		shiftDirection = Direction::Left;
		return shiftDirection;
	}
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_y() == (GetUpperLeft().Get_y() + GetHeightAddition()) && (GetUpperLeft().Get_y() + GetHeightAddition() - playingFieldBottomY) < 4)
	{
		shiftDirection = Direction::Up;
		return shiftDirection;
	}
	shiftDirection = Direction::None;
	return shiftDirection;
}
RectangleSymbols* Camera::GetBorderSymbols() const
{
	return borderSymbols_ptr;
}