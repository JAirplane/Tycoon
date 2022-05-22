#include "ConstructionOptions.h"
/////////////Construction Options Class : Singleton patern/////////////
///////////////Height Addition Constants///////////////
const int ConstructionOptions::GetVisitorHeightAdd() const
{
	return 0;
}
///////////////Width Addition Constants///////////////
const int ConstructionOptions::GetVisitorWidthAdd() const
{
	return 0;
}
///////////////Description Initialisation Constants///////////////
const string ConstructionOptions::GetArrowsDescription() const
{
	return "Arrows to navigate on the playingfield / in menu";
}
const string ConstructionOptions::GetTabDescription() const
{
	return "Tab to switch between main screen and menu";
}
const string ConstructionOptions::GetEnterDescription() const
{
	return "Enter to press buttons / to build constructions";
}
const string ConstructionOptions::GetEscDescription() const
{
	return "Esc to deselect construction";
}
const string ConstructionOptions::GetHKeyDescription() const
{
	return "'H' key to hide / show menu elements";
}
const string ConstructionOptions::GetSKeyDescription() const
{
	return "'S' key to switch menu side";
}
const string ConstructionOptions::GetRKeyDescription() const
{
	return "'R' key rotates buildings";
}
///////////////Initialisation Coord Constants///////////////
const PointCoord ConstructionOptions::GetCameraInitialUpperLeft() const
{
	return PointCoord(1, 1);
}
const PointCoord ConstructionOptions::GetPlayingFieldUpperLeft() const
{
	return PointCoord(-30, -30);
}
const PointCoord ConstructionOptions::GetInfoPanelUpperLeft() const
{
	return PointCoord(1, 37);
}
const PointCoord ConstructionOptions::GetInitialSplashScreenUpperLeft() const
{
	return PointCoord(1, 1);
}
const PointCoord ConstructionOptions::GetMainMenuUpperLeft() const
{
	return PointCoord(1, 1);
}
///////////////Color Construction Constants///////////////
color ConstructionOptions::GetCursorBackgroundColor() const
{
	return color::cYELLOW;
}
//
color ConstructionOptions::GetMenuElementActiveColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetMenuElementUnderConstructionColor() const
{
	return color::cRED;
}
//
color ConstructionOptions::GetButtonBorderActiveColor() const
{
	return color::cGREEN;
}
color ConstructionOptions::GetButtonDisabledColor() const
{
	return cDARK_GRAY;
}
//
color ConstructionOptions::GetVisitorForegroundColor() const
{
	return cYELLOW;
}
color ConstructionOptions::GetVisitorBackgroundColor() const
{
	return cBLACK;
}
//
color ConstructionOptions::GetSplashScreenForegroundColor() const
{
	return cBLACK;
}
color ConstructionOptions::GetSplashScreenBackgroundColor() const
{
	return cCYAN;
}
//
const string ConstructionOptions::GetControlsButtonTitle() const
{
	return "CONTROLS";
}
const string ConstructionOptions::GetInfoScreenButtonTitle() const
{
	return "MESSAGES AND INFO";
}
const string ConstructionOptions::GetDeconstructButtonTitle() const
{
	return "Deconstruct";
}
const string ConstructionOptions::GetNewGameButtonTitle() const
{
	return "New Game";
}
const string ConstructionOptions::GetContinueButtonTitle() const
{
	return "Continue";
}
const string ConstructionOptions::GetExitButtonTitle() const
{
	return "Exit";
}
//
const wstring ConstructionOptions::GetVisitorSymbol() const
{
	return L"\u263A";
}
///////////////Empty Border Rectangle Symbol///////////////
const wstring ConstructionOptions::GetEmptyRectangleBorderSymbol() const
{
	return wstring(L" ");
}
///////////////Indent Constants///////////////
const int ConstructionOptions::GetInfoPanelAboveIndent() const
{
	return 2;
}
const int ConstructionOptions::GetInfoPanelBottomIndent() const
{
	return 2;
}
const int ConstructionOptions::GetInfoPanelLeftIndent() const
{
	return 2;
}
const int ConstructionOptions::GetInfoPanelRightIndent() const
{
	return 2;
}
///////////////ConstructionOptions Initialisation and using///////////////
ConstructionOptions* ConstructionOptions::GetAllOptions()
{
	return constructionParameters;
}
ConstructionOptions* ConstructionOptions::CreateConstructionOptions()
{
	return new ConstructionOptions();
}
ConstructionOptions* ConstructionOptions::constructionParameters = ConstructionOptions::CreateConstructionOptions();