#pragma once
#include "MenuScreen_InfoPanel.h"
class ConstructionInfoScreen : public MyRectangle
{
private:
	Button* deconstruct_ptr;
	MyRectangle* constructionIcon_ptr;
	Construction* choosen_ptr;
public:
	ConstructionInfoScreen(PointCoord upperLeft, int heightAdd, int widthAdd, BorderAppearance* borderApp_ptr, color letterColor, color backgroundColor, Visualisation* vis_ptr,
		Cursor* cur_ptr) : MyRectangle(upperLeft, heightAdd, widthAdd, borderApp_ptr, letterColor, backgroundColor, vis_ptr, cur_ptr)
	{
		deconstruct_ptr = nullptr;
		constructionIcon_ptr = nullptr;
		choosen_ptr = nullptr;
	}
	~ConstructionInfoScreen()
	{
		delete deconstruct_ptr;
		delete constructionIcon_ptr;
	}
	virtual void CreateDeconstructButton();
	virtual void CreateConstructionIcon();
	//
	void DisplayConstructionInfo();
};