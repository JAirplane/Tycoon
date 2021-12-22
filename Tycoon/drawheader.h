#pragma once
#include <iostream>
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
	void DrawCursorPixel(int x, int y, color background = cBLACK);
	void ErasePixel(int x, int y);
	void DrawIcon(int leftX, int topY, wstring vertical, wstring horizontal, wstring upperLeft, wstring upperRight, wstring bottomLeft,
		wstring bottomRight, int constructionCost, int dailySpend, const wstring iconSymbol, string description, color foreground, const wstring entranceSymbol = L"",
		int entranceHeightAdd = -1, int entranceWidthAdd = -1, color background = cBLACK);
	void DrawVisitor(int _x, int _y);
	void DrawConstruction(int leftX, int topY, int rightX, int bottomY, const wstring constructionSymbol, color foreground, const wstring entranceSymbol = L"",
		int entranceHeightAdd = -1, int entranceWidthAdd = -1, color background = cBLACK);
	void DrawConstruction(int leftX, int topY, int rightX, int bottomY, const char constructionSymbol, color foreground, color background = cBLACK);
	void EraseConstruction(int leftX, int topY, int rightX, int bottomY);
};