#pragma once
#include "ConstructionConstantsXML.h"
class RectangleConstantsXML
{
private:
	int heightAdd;
	int widthAdd;
	color borderForeground;
	color borderBackground;
	color contentForeground;
	color contentBackground;
	wstring verticalBorderSymbol;
	wstring horizontalBorderSymbol;
	wstring upperLeftBorderSymbol;
	wstring upperRightBorderSymbol;
	wstring bottomLeftBorderSymbol;
	wstring bottomRightBorderSymbol;
public:
	RectangleConstantsXML(int heightAdd, int widthAdd, color borderForeground, color borderBackground, color contentForeground, color contentBackground, 
		wstring verticalBorderSymbol, wstring horizontalBorderSymbol, wstring upperLeftBorderSymbol, wstring upperRightBorderSymbol, 
		wstring bottomLeftBorderSymbol, wstring bottomRightBorderSymbol) 
	{
		this->heightAdd = heightAdd;
		this->widthAdd = widthAdd;
		this->borderForeground = borderForeground;
		this->borderBackground = borderBackground;
		this->contentForeground = contentForeground;
		this->contentBackground = contentBackground;
		this->verticalBorderSymbol = verticalBorderSymbol;
		this->horizontalBorderSymbol = horizontalBorderSymbol;
		this->upperLeftBorderSymbol = upperLeftBorderSymbol;
		this->upperRightBorderSymbol = upperRightBorderSymbol;
		this->bottomLeftBorderSymbol = bottomLeftBorderSymbol;
		this->bottomRightBorderSymbol = bottomRightBorderSymbol;
	}
	virtual ~RectangleConstantsXML() {}
	int GetHeightAdd() const;
	__declspec(property(get = GetHeightAdd)) int heightAddition;
	int GetWidthAdd() const;
	__declspec(property(get = GetWidthAdd)) int widthAddition;
	color GetBorderForegroundColor() const;
	__declspec(property(get = GetBorderForegroundColor)) color foregroundBorderColor;
	color GetBorderBackgroundColor() const;
	__declspec(property(get = GetBorderBackgroundColor)) color backgroundBorderColor;
	color GetContentForegroundColor() const;
	__declspec(property(get = GetContentForegroundColor)) color foregroundContentColor;
	color GetContentBackgroundColor() const;
	__declspec(property(get = GetContentBackgroundColor)) color backgroundContentColor;
	wstring GetVerticalBorderSymbol() const;
	__declspec(property(get = GetVerticalBorderSymbol)) wstring borderSymbolVertical;
	wstring GetHorizontalBorderSymbol() const;
	__declspec(property(get = GetHorizontalBorderSymbol)) wstring borderSymbolHorizontal;
	wstring GetUpperLeftBorderSymbol() const;
	__declspec(property(get = GetUpperLeftBorderSymbol)) wstring borderSymbolUpperLeft;
	wstring GetUpperRightBorderSymbol() const;
	__declspec(property(get = GetUpperRightBorderSymbol)) wstring borderSymbolUpperRight;
	wstring GetBottomLeftBorderSymbol() const;
	__declspec(property(get = GetBottomLeftBorderSymbol)) wstring borderSymbolBottomLeft;
	wstring GetBottomRightBorderSymbol() const;
	__declspec(property(get = GetBottomRightBorderSymbol)) wstring borderSymbolBottomRight;
};