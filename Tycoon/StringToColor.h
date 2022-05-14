#pragma once
#include "MyException.h"
class StringToColor
{
protected:
	static StringToColor* stringToColorConverter;
public:
	StringToColor() {}
	virtual ~StringToColor()
	{
		delete stringToColorConverter;
	}
	static StringToColor* CreateStringToColorConverter();
	static StringToColor* GetStringToColorConverter();
	virtual color Convert(string textColor);
	/* list of text versions of color to convert to color type:
	   black
	   dark blue
	   dark green
	   dark cyan
	   dark red
	   dark magenta
	   brown
	   light gray
	   dark gray
	   blue
	   green
	   cyan
	   red
	   magenta
	   yellow
	   white
	*/
};