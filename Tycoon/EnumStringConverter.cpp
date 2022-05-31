#include "EnumStringConverter.h"
EnumStringConverter* EnumStringConverter::CreateStringToColorConverter()
{
	return new EnumStringConverter();
}
EnumStringConverter* EnumStringConverter::GetStringToColorConverter()
{
	return stringToColorConverter;
}
color EnumStringConverter::Convert(string textColor)
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
		throw MyException("EnumStringConverter::Convert(string textColor) got bad string argument");
	}
}
string EnumStringConverter::Convert_DirectionToString(Direction anyDir)
{
	if (anyDir == Direction::None)
	{
		return "none";
	}
	else if (anyDir == Direction::Left)
	{
		return "left";
	}
	else if (anyDir == Direction::Up)
	{
		return "up";
	}
	else if (anyDir == Direction::Right)
	{
		return "right";
	}
	else if (anyDir == Direction::Down)
	{
		return "down";
	}
	else
	{
		throw MyException("EnumStringConverter::Convert_DirectionToString(Direction anyDir) got bad direction");
	}
}
Direction EnumStringConverter::Convert_StringToDirection(string anyStr)
{
	if (anyStr == "none" || anyStr == "None")
	{
		return Direction::None;
	}
	else if (anyStr == "left" || anyStr == "Left")
	{
		return Direction::Left;
	}
	else if (anyStr == "up" || anyStr == "Up")
	{
		return Direction::Up;
	}
	else if (anyStr == "right" || anyStr == "Right")
	{
		return Direction::Right;
	}
	else if (anyStr == "down" || anyStr == "Down")
	{
		return Direction::Down;
	}
	else
	{
		throw MyException("EnumStringConverter::Convert_StringToDirection(string anyStr) got bad string");
	}
}
EnumStringConverter* EnumStringConverter::stringToColorConverter = EnumStringConverter::CreateStringToColorConverter();