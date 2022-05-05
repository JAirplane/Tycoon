#include "Cursor.h"
///////////////Cursor Class///////////////
PointCoord Cursor::GetCursorConsoleLocation() const
{
	return cursorConsoleLocation;
}
void Cursor::SetCursorConsoleLocation()
{
	cursorConsoleLocation = GetConsoleCursorPosition();
}
void Cursor::CursorMovement(PointCoord cursorDestination)
{
	set_cursor_pos(cursorDestination.Get_x(), cursorDestination.Get_y());
	SetCursorConsoleLocation();
}
void Cursor::CursorShift(Direction shiftDirection, int shiftValue)
{
	switch (shiftDirection)
	{
	case Direction::Right:
	{ CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() + shiftValue, GetCursorConsoleLocation().Get_y())); return; }
	case Direction::Down:
	{ CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x(), GetCursorConsoleLocation().Get_y() + shiftValue)); return; }
	case Direction::Left:
	{ CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x() - shiftValue, GetCursorConsoleLocation().Get_y())); return; }
	case Direction::Up:
	{ CursorMovement(PointCoord(GetCursorConsoleLocation().Get_x(), GetCursorConsoleLocation().Get_y() - shiftValue)); return; }
	default: {return; }
	}
}
CursorLocation Cursor::GetCursorArea(const GlobalObject* camera_ptr, const GlobalObject* menu_ptr, const GlobalObject* infoPanel_ptr) const
{
	if (this->GetCursorConsoleLocation().Get_x() < (camera_ptr->GetUpperLeft().Get_x() + camera_ptr->GetWidthAddition()) &&
		this->GetCursorConsoleLocation().Get_x() > camera_ptr->GetUpperLeft().Get_x() &&
		this->GetCursorConsoleLocation().Get_y() < (camera_ptr->GetUpperLeft().Get_y() + camera_ptr->GetHeightAddition()) &&
		this->GetCursorConsoleLocation().Get_y() > camera_ptr->GetUpperLeft().Get_y())	//this condition checks if the cursor is within the camera borders
	{
		return CursorLocation::Camera;
	}
	else if (this->GetCursorConsoleLocation().Get_x() < (menu_ptr->GetUpperLeft().Get_x() + menu_ptr->GetWidthAddition()) &&
		this->GetCursorConsoleLocation().Get_x() > menu_ptr->GetUpperLeft().Get_x() &&
		this->GetCursorConsoleLocation().Get_y() < (menu_ptr->GetUpperLeft().Get_y() + menu_ptr->GetHeightAddition()) &&
		this->GetCursorConsoleLocation().Get_y() > menu_ptr->GetUpperLeft().Get_y())		//when the cursor is in the Menu
	{
		return CursorLocation::Menu;
	}
	else if (this->GetCursorConsoleLocation().Get_x() < (infoPanel_ptr->GetUpperLeft().Get_x() + infoPanel_ptr->GetWidthAddition()) &&
		this->GetCursorConsoleLocation().Get_x() > infoPanel_ptr->GetUpperLeft().Get_x() &&
		this->GetCursorConsoleLocation().Get_y() < (infoPanel_ptr->GetUpperLeft().Get_y() + infoPanel_ptr->GetHeightAddition()) &&
		this->GetCursorConsoleLocation().Get_y() > infoPanel_ptr->GetUpperLeft().Get_y())	//when the cursor is in the InfoPanel
	{
		return CursorLocation::InfoPanel;
	}
	else
	{
		return CursorLocation::Unknown; //probably somewhere on border
	}
}
void Cursor::ReturnToCamera(const GlobalObject* camera_ptr, const GlobalObject* menu_ptr, const GlobalObject* infoPanel_ptr)
{
	if (this->GetCursorArea(camera_ptr, menu_ptr, infoPanel_ptr) == CursorLocation::Camera)
	{
		this->CursorMovement(this->GetCursorConsoleLocation());
	}
	else
	{
		this->CursorMovement(PointCoord(camera_ptr->GetHalfXAxis(), camera_ptr->GetHalfYAxis()));
	}
}