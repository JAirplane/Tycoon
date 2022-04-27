#pragma once
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include "msoftcon.h"
using namespace std;
class Visualisation
{
public:
	Visualisation()
	{
		init_graphics();
	}
	void DrawRectangle(int leftX, int topY, int rightX, int bottomY, wstring vertical, wstring horizontal, wstring upperLeft,
		wstring upperRight, wstring bottomLeft, wstring bottomRight, color foreground, color background = cBLACK) const;
	void DrawPartOfRectangle(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int leftX, int topY, int rightX, int bottomY,
		wstring vertical, wstring horizontal, wstring upperLeft, wstring upperRight, wstring bottomLeft, wstring bottomRight, color foreground, color background = cBLACK) const;
	void ErasePartOfRectangle(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int leftX, int topY, int rightX, int bottomY) const;
	void DrawCursorPixel(int x, int y, color background = cBLACK) const;
	void ErasePixel(int x, int y) const;
	void DrawMenuElementContent(int leftX, int topY, int constructionCost, int dailySpend, const wstring iconSymbol,
		string description, color foregroundIcon, color backgroundIcon) const;
	void DrawVisitor(int xCoord, int yCoord, color foreground, color background, const wstring visitorSymbol) const;
	void DrawConstruction(int leftX, int topY, int rightX, int bottomY, const wstring constructionSymbol, color foreground, const wstring entranceSymbol = L"",
		int entranceHeightAdd = -1, int entranceWidthAdd = -1, color background = cBLACK) const;
	void DrawConstruction(int leftX, int topY, int rightX, int bottomY, const wstring constructionSymbol, color foreground, color background = cBLACK) const;
	void EraseConstruction(int leftX, int topY, int rightX, int bottomY) const;
	void WriteMessage(int initialX, int initialY, string message, color letterColor, color background = cBLACK) const;
};