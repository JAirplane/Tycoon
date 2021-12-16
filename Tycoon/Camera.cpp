#include "Camera.h"
///////////////Camera Class///////////////
Direction Camera::CursorBordersCheck(Cursor* cursor_ptr)
{
	Direction SD;
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_x() == GetUpperLeft().Get_x())
	{
		SD = Direction::Right;
		return SD;
	}
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_y() == GetUpperLeft().Get_y())
	{
		SD = Direction::Down;
		return SD;
	}
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_x() == (GetUpperLeft().Get_x() + ConstructionOptions::GetAllOptions()->GetCameraWidthAdd()))
	{
		SD = Direction::Left;
		return SD;
	}
	if ((cursor_ptr->GetCursorConsoleLocation()).Get_y() == (GetUpperLeft().Get_y() + ConstructionOptions::GetAllOptions()->GetCameraHeightAdd()))
	{
		SD = Direction::Up;
		return SD;
	}
	SD = Direction::None;
	return SD;
}