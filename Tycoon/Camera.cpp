#include "Camera.h"
///////////////Camera Class///////////////
Direction Camera::CursorBordersCheck(Cursor* cursor_ptr)
{
	Direction shiftDirection;
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_x() == GetUpperLeft().Get_x())
	{
		shiftDirection = Direction::Right;
		return shiftDirection;
	}
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_y() == GetUpperLeft().Get_y())
	{
		shiftDirection = Direction::Down;
		return shiftDirection;
	}
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_x() == (GetUpperLeft().Get_x() + ConstructionOptions::GetAllOptions()->GetCamerawidthAdd()))
	{
		shiftDirection = Direction::Left;
		return shiftDirection;
	}
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_y() == (GetUpperLeft().Get_y() + ConstructionOptions::GetAllOptions()->GetCameraheightAdd()))
	{
		shiftDirection = Direction::Up;
		return shiftDirection;
	}
	shiftDirection = Direction::None;
	return shiftDirection;
}