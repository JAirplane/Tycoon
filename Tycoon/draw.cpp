#pragma once
#include <iostream>
#include <windows.h>
#include "msoftcon.h"
#include "drawheader.h"
using namespace std;
///////////////////drawMap Class///////////////////
void Visualisation::DrawRectangle(int leftX, int topY, int rightX, int bottomY, color foreground, color background)
{
	set_color(foreground, background);
	for (int y = topY + 1; y < bottomY; y++)
	{
		set_cursor_pos(leftX, y);
		cout << (char)186 << "\n";
	}
	for (int y = topY + 1; y < bottomY; y++)
	{
		set_cursor_pos(rightX, y);
		cout << (char)186;
	}
	for (int x = leftX + 1; x < rightX; x++)
	{
		set_cursor_pos(x, topY);
		cout << (char)205;
	}
	for (int x = leftX + 1; x < rightX; x++)
	{
		set_cursor_pos(x, bottomY);
		cout << (char)205;
	}
	set_cursor_pos(rightX, topY);
	cout << (char)187;
	set_cursor_pos(rightX, bottomY);
	cout << (char)188;
	set_cursor_pos(leftX, bottomY);
	cout << (char)200;
	set_cursor_pos(leftX, topY);
	cout << (char)201;
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
	char visitorsymbol = 'a';
	set_cursor_pos(x, y);
	cout << visitorsymbol;
	set_color(cYELLOW);
}
void Visualisation::DrawConstruction(int leftX, int topY, int rightX, int bottomY, const char ch, color foreground, color background)
{
	set_color(foreground, background);
	for (int j = topY; j <= bottomY; j++)
	{
		for (int i = leftX; i <= rightX; i++)
		{
			set_cursor_pos(i, j);
			cout << ch;
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
void Visualisation::DrawIcon(int leftX, int topY, int constructionCost, int dailySpend, const char iconSymbol, string description, color foreground, color background) //icon border
{
	DrawRectangle(leftX, topY, leftX + 3, topY + 3, cGREEN);
	DrawConstruction(leftX + 1, topY + 1, leftX + 2, topY + 2, iconSymbol, foreground, background);
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