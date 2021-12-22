#pragma once
#include <iostream>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include "msoftcon.h"
#include "drawheader.h"
using namespace std;
///////////////////drawMap Class///////////////////
void Visualisation::DrawRectangle(int leftX, int topY, int rightX, int bottomY, wstring vertical, wstring horizontal, wstring upperLeft,
	wstring upperRight, wstring bottomLeft, wstring bottomRight, color foreground, color background)
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	set_color(foreground, background);
	for (int y = topY + 1; y < bottomY; y++)
	{
		set_cursor_pos(leftX, y);
		wcout << vertical;
	}
	for (int y = topY + 1; y < bottomY; y++)
	{
		set_cursor_pos(rightX, y);
		wcout << vertical;
	}
	for (int x = leftX + 1; x < rightX; x++)
	{
		set_cursor_pos(x, topY);
		wcout << horizontal;
	}
	for (int x = leftX + 1; x < rightX; x++)
	{
		set_cursor_pos(x, bottomY);
		wcout << horizontal;
	}
	set_cursor_pos(rightX, topY);
	wcout << upperRight;
	set_cursor_pos(rightX, bottomY);
	wcout << bottomRight;
	set_cursor_pos(leftX, bottomY);
	wcout << bottomLeft;
	set_cursor_pos(leftX, topY);
	wcout << upperLeft;
	_setmode(_fileno(stdout), _O_TEXT);
	set_color(cYELLOW);
}
void Visualisation::ErasePixel(int x, int y)
{
	set_color(cBLACK);
	set_cursor_pos(x, y);
	cout << ' ';
}
void Visualisation::DrawCursorPixel(int x, int y, color background)
{
	set_cursor_pos(x, y);
	set_color(cBLACK, background);
	cout << ' ';
	set_cursor_pos(x, y);
}
void Visualisation::DrawVisitor(int x, int y)
{
	char visitorSymbol = 'a';
	set_cursor_pos(x, y);
	cout << visitorSymbol;
	set_color(cYELLOW);
}
void Visualisation::DrawConstruction(int leftX, int topY, int rightX, int bottomY, const wstring constructionSymbol, color foreground, const wstring entranceSymbol = L"",
	int entranceHeightAdd = -1, int entranceWidthAdd = -1, color background)
{
	set_color(foreground, background);
	_setmode(_fileno(stdout), _O_U16TEXT);
	for (int j = topY; j <= bottomY; j++)
	{
		for (int i = leftX; i <= rightX; i++)
		{
			set_cursor_pos(i, j);
			wcout << constructionSymbol;
		}
	}
	if (entranceHeightAdd != -1 && entranceWidthAdd != -1)
	{
		set_cursor_pos(leftX + entranceWidthAdd, topY + entranceHeightAdd);
		wcout << entranceSymbol;
	}
	set_color(cYELLOW);
	_setmode(_fileno(stdout), _O_TEXT);
}
void Visualisation::DrawConstruction(int leftX, int topY, int rightX, int bottomY, const wstring constructionSymbol, color foreground, color background)
{
	set_color(foreground, background);
	for (int j = topY; j <= bottomY; j++)
	{
		for (int i = leftX; i <= rightX; i++)
		{
			set_cursor_pos(i, j);
			cout << constructionSymbol;
		}
	}
	set_color(cYELLOW);
}
void Visualisation::EraseConstruction(int leftX, int topY, int rightX, int bottomY)
{
	for (int j = topY; j <= bottomY; j++)
	{
		for (int i = leftX; i <= rightX; i++)
		{
			ErasePixel(i, j);
		}
	}
}
void Visualisation::DrawIcon(int leftX, int topY, wstring vertical, wstring horizontal, wstring upperLeft, wstring upperRight, wstring bottomLeft,
	wstring bottomRight, int constructionCost, int dailySpend, const wstring iconSymbol, string description, color foregroundIcon, color backgroundIcon,
	color foregroundBorder, color backgroundBorder) //icon border
{
	DrawRectangle(leftX, topY, leftX + 3, topY + 3, vertical, horizontal, upperLeft, upperRight, bottomLeft, bottomRight, foregroundBorder, backgroundBorder);
	DrawConstruction(leftX + 1, topY + 1, leftX + 2, topY + 2, iconSymbol, foregroundIcon, backgroundIcon);
	set_cursor_pos(leftX + 4, topY);
	set_color(cLIGHT_GRAY);
	cout << description;
	set_cursor_pos(leftX + 4, topY + 1);
	cout << "Construction Cost: " << constructionCost;
	set_cursor_pos(leftX + 4, topY + 2);
	if (dailySpend != 0)
	{
		cout << "Service will cost you " << dailySpend << " per day.";
	}
	set_color(cYELLOW);
}