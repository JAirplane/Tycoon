#pragma once
#include "MenuScreen_InfoPanel.h"
class ConstructionInfoScreen : public MyRectangle
{
private:
	Button* deconstruct_ptr;
	MyRectangle* constructionIcon_ptr;
	Construction* chosen_ptr;
public:
	ConstructionInfoScreen(PointCoord upperLeft, RectangleConstantsXML* initial, Visualisation* vis_ptr, Cursor* cur_ptr) : MyRectangle(upperLeft, initial, vis_ptr, cur_ptr)
	{
		deconstruct_ptr = nullptr;
		constructionIcon_ptr = nullptr;
		chosen_ptr = nullptr;
	}
	ConstructionInfoScreen(MyRectangle& someRectangle) : MyRectangle(someRectangle)
	{
		deconstruct_ptr = nullptr;
		constructionIcon_ptr = nullptr;
		chosen_ptr = nullptr;
	}
	virtual ~ConstructionInfoScreen()
	{
		delete deconstruct_ptr;
		delete constructionIcon_ptr;
	}
	virtual void CreateDeconstructButton();
	virtual void CreateConstructionIcon();
	//
	Button* GetDeconstructButton();
	Construction* GetChosenConstruction() const;
	void SetChosenConstruction(Construction* choice_ptr);
	//
	void ClearChosenConstruction(); //do not free memory
	void DeselectConstruction(const Camera* cam_ptr, const AllObjects* allObjects_ptr);
	void ClearChosenConstructionStatistic();
	void ShowChosenConstructionStatistic();
	void DisplayConstructionInfo();
};