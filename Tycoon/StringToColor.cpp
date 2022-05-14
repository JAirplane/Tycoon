#include "StringToColor.h"
StringToColor* StringToColor::CreateStringToColorConverter()
{
	return new StringToColor();
}
StringToColor* StringToColor::GetStringToColorConverter()
{
	return stringToColorConverter;
}
color StringToColor::Convert(string textColor)
{
	if (textColor == "black")
	{
		return cBLACK;
	}
	else if (textColor == "dark blue")
	{
		return cDARK_BLUE;
	}
	else if (textColor == "dark green")
	{
		return cDARK_GREEN;
	}
	else if (textColor == "dark cyan")
	{
		return cDARK_CYAN;
	}
	else if (textColor == "dark red")
	{
		return cDARK_RED;
	}
	else if (textColor == "dark magenta")
	{
		return cDARK_MAGENTA;
	}
	else if (textColor == "brown")
	{
		return cBROWN;
	}
	else if (textColor == "light gray")
	{
		return cLIGHT_GRAY;
	}
	else if (textColor == "dark gray")
	{
		return cDARK_GRAY;
	}
	else if (textColor == "blue")
	{
		return cBLUE;
	}
	else if (textColor == "green")
	{
		return cGREEN;
	}
	else if (textColor == "cyan")
	{
		return cCYAN;
	}
	else if (textColor == "red")
	{
		return cRED;
	}
	else if (textColor == "magenta")
	{
		return cMAGENTA;
	}
	else if (textColor == "yellow")
	{
		return cYELLOW;
	}
	else if (textColor == "white")
	{
		return cWHITE;
	}
	else
	{
		throw MyException("StringToColor::Convert(string textColor) got bad string argument");
	}
}
StringToColor* StringToColor::stringToColorConverter = StringToColor::CreateStringToColorConverter();