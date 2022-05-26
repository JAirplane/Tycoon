#include "Display.h"
void Display::DisplayInitialScreen(const InitialScreen* startScreen)
{
	startScreen->DrawBorder();
	startScreen->ShowGameTitle(startScreen->GetTextColor());
	startScreen->ShowAuthor(cGREEN);
	startScreen->DrawHaveFunIscription(cYELLOW);
	startScreen->GetPressAnyKey()->DrawBorder();
	startScreen->PressAnyKeyAnimation();
}
void Display::DisplayMainMenu(MainMenu* mainMenu_ptr, Cursor* cursor_ptr)
{
	mainMenu_ptr->DrawBorder();
	mainMenu_ptr->Display(mainMenu_ptr->GetTextColor());
	if (mainMenu_ptr->GetContinueButton()->GetEnabled())
	{
		mainMenu_ptr->GetContinueButton()->RedrawBorder(mainMenu_ptr->GetContinueButton()->GetBorder()->GetBorderForegroundColor(),
			mainMenu_ptr->GetContinueButton()->GetInitialCondition()->activeButtonColor);
		cursor_ptr->CursorMovement(PointCoord(mainMenu_ptr->GetContinueButton()->GetHalfXAxis(), mainMenu_ptr->GetContinueButton()->GetUpperLeft().Get_y()));
	}
	else
	{
		mainMenu_ptr->GetNewGameButton()->RedrawBorder(mainMenu_ptr->GetNewGameButton()->GetBorder()->GetBorderForegroundColor(),
			mainMenu_ptr->GetNewGameButton()->GetInitialCondition()->activeButtonColor);
		cursor_ptr->CursorMovement(PointCoord(mainMenu_ptr->GetNewGameButton()->GetHalfXAxis(), mainMenu_ptr->GetNewGameButton()->GetUpperLeft().Get_y()));
	}
}
void Display::DrawCursor(const Cursor* cursor_ptr, const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	if (!container_ptr->ObjectImposition(cursor_ptr->GetCursorConsoleLocation(), field_ptr) && container_ptr->GetPreliminaryElement() == nullptr)
	{
		draw_ptr->DrawCursorPixel(cursor_ptr->GetCursorConsoleLocation().Get_x(), cursor_ptr->GetCursorConsoleLocation().Get_y(),
			ConstructionOptions::GetAllOptions()->GetCursorBackgroundColor());
	}
}
void Display::DisplayMenu(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
	const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	menu_ptr->DrawBorder();
	menu_ptr->ShowMenuItems();
	menu_ptr->ShowStats();
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	DrawCursor(cursor_ptr, container_ptr, field_ptr);
}
void Display::HideMenu(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
	const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	menu_ptr->ClearContent();
	menu_ptr->EraseBorder();
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	DrawCursor(cursor_ptr, container_ptr, field_ptr);
}
void Display::DisplayCamera(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
	const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	camera_ptr->DrawBorder();
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	DrawCursor(cursor_ptr, container_ptr, field_ptr);
}
void Display::DisplayPlayingField(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
	const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	int leftX = field_ptr->GetUpperLeft().Get_x();
	int topY = field_ptr->GetUpperLeft().Get_y();
	int rightX = leftX + field_ptr->GetWidthAddition();
	int bottomY = topY + field_ptr->GetHeightAddition();
	draw_ptr->DrawPartOfRectangle(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY,
		field_ptr->GetBorder()->GetBorderSymbols()->GetVerticalSymbol(), field_ptr->GetBorder()->GetBorderSymbols()->GetHorizontalSymbol(),
		field_ptr->GetBorder()->GetBorderSymbols()->GetUpperLeftSymbol(), field_ptr->GetBorder()->GetBorderSymbols()->GetUpperRightSymbol(),
		field_ptr->GetBorder()->GetBorderSymbols()->GetBottomLeftSymbol(), field_ptr->GetBorder()->GetBorderSymbols()->GetBottomRightSymbol(),
		field_ptr->GetBorder()->GetBorderForegroundColor());
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	DrawCursor(cursor_ptr, container_ptr, field_ptr);
}
void Display::ErasePlayingField(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
	const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	int cameraLeftX = camera_ptr->GetUpperLeft().Get_x();
	int cameraTopY = camera_ptr->GetUpperLeft().Get_y();
	int cameraRightX = cameraLeftX + camera_ptr->GetWidthAddition();
	int cameraBottomY = cameraTopY + camera_ptr->GetHeightAddition();
	int leftX = field_ptr->GetUpperLeft().Get_x();
	int topY = field_ptr->GetUpperLeft().Get_y();
	int rightX = leftX + field_ptr->GetWidthAddition();
	int bottomY = topY + field_ptr->GetHeightAddition();
	draw_ptr->ErasePartOfRectangle(cameraLeftX, cameraTopY, cameraRightX, cameraBottomY, leftX, topY, rightX, bottomY);
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	DrawCursor(cursor_ptr, container_ptr, field_ptr);
}
void Display::DisplayInfoPanel(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, InfoPanel* infoPanel_ptr,
	const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	infoPanel_ptr->DrawBorder();
	infoPanel_ptr->ShowSplashScreen(infoPanel_ptr->GetTextColor(), infoPanel_ptr->GetShadingColor());
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	DrawCursor(cursor_ptr, container_ptr, field_ptr);
}
void Display::HideInfoPanel(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
	const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	infoPanel_ptr->ClearContent();
	infoPanel_ptr->EraseBorder();
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	DrawCursor(cursor_ptr, container_ptr, field_ptr);
}
void Display::EraseScreen() const
{
	set_color(color::cBLACK);
	system("cls");
}
void Display::DisplayAllObjects(const Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
	const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	container_ptr->DisplayBuildings(camera_ptr, field_ptr);
	container_ptr->DisplayRoads(camera_ptr, field_ptr);
	container_ptr->DisplayVisitors(camera_ptr);
	cursor_ptr->ReturnToCamera(camera_ptr, menu_ptr, infoPanel_ptr);
	DrawCursor(cursor_ptr, container_ptr, field_ptr);
}
//
void Display::HideInterface(Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, const InfoPanel* infoPanel_ptr,
	const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	HideMenu(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, container_ptr, field_ptr);
	HideInfoPanel(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, container_ptr, field_ptr);
	menu_ptr->SetHideMenuStatus(1);
}
void Display::ShowInterface(Menu* menu_ptr, Cursor* cursor_ptr, const Camera* camera_ptr, InfoPanel* infoPanel_ptr,
	const AllObjects* container_ptr, const PlayingField* field_ptr) const
{
	DisplayMenu(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, container_ptr, field_ptr);
	DisplayInfoPanel(menu_ptr, cursor_ptr, camera_ptr, infoPanel_ptr, container_ptr, field_ptr);
	menu_ptr->SetHideMenuStatus(0);
}