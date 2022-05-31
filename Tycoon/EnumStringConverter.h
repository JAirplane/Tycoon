#pragma once
#include <string>
#include "Coord_and_constants.h"
class EnumStringConverter
{
protected:
	static EnumStringConverter* stringToColorConverter;
public:
	EnumStringConverter() {}
	virtual ~EnumStringConverter()
	{
		delete stringToColorConverter;
	}
	static EnumStringConverter* CreateStringToColorConverter();
	static EnumStringConverter* GetStringToColorConverter();
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
	virtual string Convert_DirectionToString(Direction anyDir);
	virtual Direction Convert_StringToDirection(string anyStr);
	/* list of suitable strings:
		none
		up
		right
		down
		left
	*/
};