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
	RectangleConstantsXML()
	{
		heightAdd = 0;
		widthAdd = 0;
		borderForeground = color::cBLACK;
		borderBackground = color::cBLACK;
		contentForeground = color::cBLACK;
		contentBackground = color::cBLACK;
		verticalBorderSymbol = L"";
		horizontalBorderSymbol = L"";
		upperLeftBorderSymbol = L"";
		upperRightBorderSymbol = L"";
		bottomLeftBorderSymbol = L"";
		bottomRightBorderSymbol = L"";
	}
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
	//
	virtual string GetTitle() const;
	__declspec(property(get = GetTitle)) string buttonTitle;
	virtual color GetActiveButtonColor() const;
	__declspec(property(get = GetActiveButtonColor)) color activeButtonColor;
	virtual color GetPressedButtonColor() const;
	__declspec(property(get = GetPressedButtonColor)) color pressedColor;
};
class ButtonConstantsXML : public RectangleConstantsXML
{
private:
	string title;
	color active;
	color pressed;
public:
	ButtonConstantsXML()
	{
		title = "";
		active = color::cBLACK;
		pressed = color::cBLACK;
	}
	ButtonConstantsXML(int heightAdd, int widthAdd, color borderForeground, color borderBackground, color contentForeground, color contentBackground,
		wstring verticalBorderSymbol, wstring horizontalBorderSymbol, wstring upperLeftBorderSymbol, wstring upperRightBorderSymbol,
		wstring bottomLeftBorderSymbol, wstring bottomRightBorderSymbol, string title, color activeColor, color pressedButtonColor) :
		RectangleConstantsXML(heightAdd, widthAdd, borderForeground, borderBackground, contentForeground, contentBackground, verticalBorderSymbol,
			horizontalBorderSymbol, upperLeftBorderSymbol, upperRightBorderSymbol, bottomLeftBorderSymbol, bottomRightBorderSymbol)
	{
		this->title = title;
		active = activeColor;
		pressed = pressedButtonColor;
	}
	virtual ~ButtonConstantsXML() {}
	string GetTitle() const override;
	__declspec(property(get = GetTitle)) string buttonTitle;
	color GetActiveButtonColor() const override;
	__declspec(property(get = GetActiveButtonColor)) color activeButtonColor;
	color GetPressedButtonColor() const override;
	__declspec(property(get = GetPressedButtonColor)) color pressedColor;
};