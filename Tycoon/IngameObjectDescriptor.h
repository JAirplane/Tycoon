#pragma once
#include "Cursor.h"
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
	~IngameObjectDescriptor() {}
	int GetHeightAdd() const;
	int GetWidthAdd() const;
	color GetForegroundColor() const;
	color GetBackgroundColor() const;
};
