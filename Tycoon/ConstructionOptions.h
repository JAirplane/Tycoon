#pragma once
#include "FindByPoint.h"
#include <string>
/////////////Construction Options Class : Singleton pattern/////////////
class ConstructionOptions
{
protected:
	ConstructionOptions() {}
	~ConstructionOptions()
	{
		delete constructionParameters;
	}
	static ConstructionOptions* constructionParameters;
public:
	ConstructionOptions(ConstructionOptions& other) = delete;
	void operator=(const ConstructionOptions&) = delete;
	static ConstructionOptions* CreateConstructionOptions();
	static ConstructionOptions* GetAllOptions();
	///////////////Height Addition Constants///////////////
	virtual const int GetVisitorHeightAdd() const;
	///////////////Width Addition Constants///////////////
	virtual const int GetVisitorWidthAdd() const;
	///////////////Description Initialisation Constants///////////////
	virtual const string GetArrowsDescription() const;
	virtual const string GetTabDescription() const;
	virtual const string GetEnterDescription() const;
	virtual const string GetEscDescription() const;
	virtual const string GetHKeyDescription() const;
	virtual const string GetSKeyDescription() const;
	virtual const string GetRKeyDescription() const;
	///////////////Initialisation Coord Constants///////////////
	virtual const PointCoord GetCameraInitialUpperLeft() const;
	virtual const PointCoord GetPlayingFieldUpperLeft() const;
	virtual const PointCoord GetInfoPanelUpperLeft() const;
	virtual const PointCoord GetInitialSplashScreenUpperLeft() const;
	virtual const PointCoord GetMainMenuUpperLeft() const;
	///////////////Color Constants///////////////
	virtual color GetCursorBackgroundColor() const;
	//
	virtual color GetMenuElementActiveColor() const;
	virtual color GetMenuElementUnderConstructionColor() const;
	//
	virtual color GetButtonBorderActiveColor() const;
	virtual color GetButtonDisabledColor() const;
	//
	virtual color GetVisitorForegroundColor() const;
	virtual color GetVisitorBackgroundColor() const;
	//Empty Border Rectangle Symbol
	virtual const wstring GetEmptyRectangleBorderSymbol() const;
	//
	virtual const string GetControlsButtonTitle() const;
	virtual const string GetInfoScreenButtonTitle() const;
	virtual const string GetDeconstructButtonTitle() const;
	virtual const string GetNewGameButtonTitle() const;
	virtual const string GetContinueButtonTitle() const;
	virtual const string GetExitButtonTitle() const;
	//
	virtual const wstring GetVisitorSymbol() const;
	///////////////Indent Constants///////////////
	virtual const int GetInfoPanelAboveIndent() const;
	virtual const int GetInfoPanelBottomIndent() const;
	virtual const int GetInfoPanelLeftIndent() const;
	virtual const int GetInfoPanelRightIndent() const;
};