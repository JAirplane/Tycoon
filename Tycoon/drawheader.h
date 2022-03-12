#pragma once
#include <iostream>
#include <windows.h>
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
		wstring upperRight, wstring bottomLeft, wstring bottomRight, color foreground, color background = cBLACK);
	void DrawPartOfRectangle(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int leftX, int topY, int rightX, int bottomY,
		wstring vertical, wstring horizontal, wstring upperLeft, wstring upperRight, wstring bottomLeft, wstring bottomRight, color foreground, color background = cBLACK);
	void ErasePartOfRectangle(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int leftX, int topY, int rightX, int bottomY);
	void DrawCursorPixel(int x, int y, color background = cBLACK);
	void ErasePixel(int x, int y);
	void DrawMenuElementContent(int leftX, int topY, int constructionCost, int dailySpend, const wstring iconSymbol,
		string description, color foregroundIcon, color backgroundIcon);
	void DrawVisitor(int xCoord, int yCoord, color foreground, color background, const wstring visitorSymbol);
	void DrawConstruction(int leftX, int topY, int rightX, int bottomY, const wstring constructionSymbol, color foreground, const wstring entranceSymbol = L"",
		int entranceHeightAdd = -1, int entranceWidthAdd = -1, color background = cBLACK);
	void DrawConstruction(int leftX, int topY, int rightX, int bottomY, const wstring constructionSymbol, color foreground, color background = cBLACK);
	void EraseConstruction(int leftX, int topY, int rightX, int bottomY);
	void WriteMessage(int initialX, int initialY, string message, color letterColor, color background = cBLACK);
};