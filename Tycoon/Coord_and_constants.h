#pragma once
#include "msoftcon.h"
#include "ParkLevelConstants.h"
using namespace std;
///////////////Enum ShiftDirection///////////////
enum class Direction { None, Up, Right, Down, Left };
///////////////Enum roadMask///////////////
enum class roadMask {
	NONE = 0,
	LEFT = 1,
	TOP = 2,
	RIGHT = 4,
	BOTTOM = 8,
};
/////////////Current Position of Side Menu/////////////
enum class MenuStatus
{
	LEFT,
	RIGHT,
};
/////////////Icons Position higher or lower than current active icon or coord/////////////
enum class IconsPosition
{
	NONE,
	UPPER,
	LOWER,
};
/////////////InfoPanel Types of Content/////////////
enum class InfoPanelContentType
{
	None,
	SplashScreen,
	MenuScreen,
	Controls,
	SystemMessagesAndConstructionInfo,
};
/////////////Interface zones/////////////
enum class CursorLocation
{
	Unknown,
	Camera,
	Menu,
	InfoPanel,
};
///////////////All Possible Types of Mask///////////////
const int none = int(roadMask::NONE);
const int leftside = int(roadMask::LEFT);
const int topside = int(roadMask::TOP);
const int rightside = int(roadMask::RIGHT);
const int bottomside = int(roadMask::BOTTOM);
const int vertical = int(roadMask::BOTTOM) | int(roadMask::TOP);
const int horizontal = int(roadMask::LEFT) | int(roadMask::RIGHT);
const int lefttop_angle = int(roadMask::LEFT) | int(roadMask::TOP);
const int righttop_angle = int(roadMask::RIGHT) | int(roadMask::TOP);
const int leftbottom_angle = int(roadMask::LEFT) | int(roadMask::BOTTOM);
const int rightbottom_angle = int(roadMask::RIGHT) | int(roadMask::BOTTOM);
const int right_T = int(roadMask::RIGHT) | int(roadMask::BOTTOM) | int(roadMask::TOP);
const int left_T = int(roadMask::LEFT) | int(roadMask::BOTTOM) | int(roadMask::TOP);
const int top_T = int(roadMask::RIGHT) | int(roadMask::LEFT) | int(roadMask::TOP);
const int bottom_T = int(roadMask::RIGHT) | int(roadMask::LEFT) | int(roadMask::BOTTOM);
const int cross = int(roadMask::RIGHT) | int(roadMask::LEFT) | int(roadMask::BOTTOM) | int(roadMask::TOP);
/////////////Point Coord Class/////////////
struct PointCoord
{
private:
	int xCoord;
	int yCoord;
public:
	PointCoord()
	{
		xCoord = 1;
		yCoord = 1;
	}
	~PointCoord()
	{}
	PointCoord(int x, int y) : xCoord(x), yCoord(y)
	{}
	PointCoord(COORD crd)
	{
		xCoord = static_cast<int>(crd.X) + 1;
		yCoord = static_cast<int>(crd.Y) + 1;
	}
	PointCoord(const PointCoord& point)
	{
		xCoord = point.Get_x();
		yCoord = point.Get_y();
	}
	int Get_x() const;
	int Get_y() const;
	void SetCoord(int x, int y);
	void SetCoord(PointCoord point);
	PointCoord GetSideCoord(Direction dir) const;
	bool operator == (PointCoord point);
	bool operator != (PointCoord point);
};
class NumberOfDigits
{
protected:
	static NumberOfDigits* countDigits_ptr;
public:
	int GetNumberOfDigits(int number);
	static NumberOfDigits* GetDigitsCounter();
};