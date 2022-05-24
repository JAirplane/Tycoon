#pragma once
#include "InfoPanel.h"
class MainMenu : public MyRectangle
{
public:
	MainMenu(MyRectangle& anotherRectangle) : MyRectangle(anotherRectangle)
	{
		continueGame = nullptr;
		newGame = nullptr;
		exit = nullptr;
	}
	virtual ~MainMenu()
	{
		delete continueGame;
		delete newGame;
		delete exit;
	}
	Button* CreateButton(PointCoord upperLeft, RectangleConstantsXML* initial, bool createActivated) const;
	Button* CreateButton(PointCoord upperLeft, string buttonTitleXML, bool createActivated) const;
	void CreateButtons();
	Button* GetNewGameButton() const;
	Button* GetContinueButton() const;
	Button* GetExitButton() const;
	void DrawTitle(color titleColor) const;
	void Display(color titleColor);
	Button* GetCurrentActiveButton(const Cursor* cursor_ptr) const;
	void ActiveButtonUp(Cursor* cursor_ptr);
	void ActiveButtonDown(Cursor* cursor_ptr);
	void ChangeActiveButton();
private:
	Button* newGame;
	Button* continueGame;
	Button* exit;
};