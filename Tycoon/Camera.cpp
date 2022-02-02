#include "Camera.h"
///////////////Camera Class///////////////
Direction Camera::CursorIsOnCameraBorder()
{
	if (GetCursor()->GetCursorConsoleLocation().Get_x() == GetUpperLeft().Get_x())
	{
		return Direction::Right;
	}
	if (GetCursor()->GetCursorConsoleLocation().Get_y() == GetUpperLeft().Get_y())
	{
		return Direction::Down;
	}
	if (GetCursor()->GetCursorConsoleLocation().Get_x() == (GetUpperLeft().Get_x() + GetWidthAddition()))
	{
		return Direction::Left;
	}
	if (GetCursor()->GetCursorConsoleLocation().Get_y() == (GetUpperLeft().Get_y() + GetHeightAddition()))
	{
		return Direction::Up;
	}
	return Direction::None;
}
bool Camera::IsShift(PlayingField* field_ptr, Direction shiftDirection)
{
	int playingFieldLeftX = field_ptr->GetUpperLeft().Get_x();
	int playingFieldTopY = field_ptr->GetUpperLeft().Get_y();
	int playingFieldRightX = field_ptr->GetUpperLeft().Get_x() + field_ptr->GetWidthAddition();
	int playingFieldBottomY = field_ptr->GetUpperLeft().Get_y() + field_ptr->GetHeightAddition();
	int cameraLeftX = GetUpperLeft().Get_x();
	int cameraRightX = GetUpperLeft().Get_x() + GetWidthAddition();
	int cameraTopY = GetUpperLeft().Get_y();
	int cameraBottomY = GetUpperLeft().Get_y() + GetHeightAddition();
	switch (shiftDirection)
	{
	case Direction::Up:
	{
		if (cameraBottomY - playingFieldBottomY < 4)
		{return true;}
		else
		{return false;}
	}
	case Direction::Right:
	{
		if (playingFieldLeftX - cameraLeftX < 4)
		{return true;}
		else
		{return false;}
	}
	case Direction::Down:
	{
		if (playingFieldTopY - cameraTopY < 4)
		{return true;}
		else
		{return false;}
	}
	case Direction::Left:
	{
		if (cameraRightX - playingFieldRightX < 4)
		{return true;}
		else
		{return false;}
	}
	default: {return false; }
	}
}