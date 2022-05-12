#pragma once
#include "Alphabet.h"
#include "RectangleCreator.h"
class InitialScreen : public MyRectangle
{
private:
	MyRectangle* pressAnyKey;
	string author;
	string pressAnyKeyInscrition;
public:
	InitialScreen(MyRectangle* anotherRectangle) : MyRectangle(anotherRectangle)
	{
		pressAnyKey = nullptr;
		author = "By Eugene Shevchenko";
		pressAnyKeyInscrition = "Press Any Key";
	}
	virtual ~InitialScreen() {}
	void CreatePressAnyKey();
	const MyRectangle* GetPressAnyKey() const;
	void ShowGameTitle(color textColor) const;
	void ShowAuthor(color textColor) const;
	void DrawHaveFunIscription(color textColor) const;
	void DrawPressAnyKeyLetter(char letter, PointCoord position, color letterColor) const;
	void PressAnyKeyAnimation() const;
};