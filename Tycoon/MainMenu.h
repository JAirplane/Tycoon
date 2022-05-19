#pragma once
#include "InfoPanel.h"
class MainMenu : public MyRectangle
{
public:
	MainMenu(MyRectangle* anotherRectangle) : MyRectangle(anotherRectangle)
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
	Button* CreateButton(PointCoord upperLeft, int heightAdd, int widthAdd, wstring verticalSymbol, wstring horizontalSymbol,
		wstring upperLeftSymbol, wstring upperRightSymbol, wstring bottomLeftSymbol, wstring bottomRightSymbol, color borderForegroundColor,
		color borderBackgroundColor, color letterColor, color shadingColor, string buttonTitle, bool createActivated) const;
	Button* CreateButton(PointCoord upperLeft, string buttonTitleXML, string buttonTitle, bool createActivated) const;
	void CreateButtons();
	void DrawTitle(color titleColor) const;
	void Display(color titleColor);
private:
	Button* newGame;
	Button* continueGame;
	Button* exit;
};