#pragma once
#include "RectangleBorder.h"
class IngameObjectDescriptor
{
private:
	int heightAddition;
	int widthAddition;
	color foreground;
	color background; //for constructions it's a "Not Connected" or default background color
public:
	IngameObjectDescriptor(color foreground, color background = cBLACK, int heightAddition = 0, int widthAddition = 0)
	{
		this->heightAddition = heightAddition;
		this->widthAddition = widthAddition;
		this->foreground = foreground;
		this->background = background;
	}
	IngameObjectDescriptor(ConstructionConstantsXMLDownload* setOfConstants)
	{
		this->heightAddition = setOfConstants->heightAddition;
		this->widthAddition = setOfConstants->widthAddition;
		this->foreground = setOfConstants->constructionForegroundColor;
		this->background = setOfConstants->constructionBackgroundDisconnectedColor;
	}
	virtual ~IngameObjectDescriptor() {}
	int GetHeightAdd() const;
	int GetWidthAdd() const;
	color GetForegroundColor() const;
	color GetBackgroundColor() const;
};
