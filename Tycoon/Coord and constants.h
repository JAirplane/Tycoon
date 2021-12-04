#pragma once
//#include "unicode/uchar.h"
#include "unicode/uchriter.h"
#include "msoftcon.h"
using namespace std;
//int ucharrrrrrrrrrrr = 'a';
///////////////Ice Cream Shop Initialisation Constants///////////////
const int IceCreamShopHeightAdd = 1;
const int IceCreamShopWidthAdd = 1;
const int IceCreamShopCost = 250;
const int IceCreamShopExpences = 20;
const string IceCreamShopIconDescription = "Ice cream! Everybody loves it!";
const char IceSymbol = '!';
///////////////Icon Initialisation Constants, it has no size///////////////
const int MenuElementBordersHeight = 6;
///////////////Road Initialisation Constants///////////////
const int RoadHeightAdd = 0;
const int RoadWidthAdd = 0;
const int RoadCost = 250;
const int RoadExpences = 20;
const string RoadDescription = "Visitors can walk roads only";
const char RoadSymbol = (char)187;
///////////////Visitor Initialisation Constants///////////////
const int VisitorHeightAdd = 0;
const int VisitorWidthAdd = 0;
///////////////VisibleMap UpperLeft Coord, height and width///////////////
const PointCoord UL_Angle = PointCoord(1, 1);
const int VisibleMapHeightAdd = 69;
const int VisibleMapWidthAdd = 34;
///////////////SideMenu Width Constant///////////////
const int MenuWidthAdd = 45;
//no need to initialize Menu_Y_axis, it's the same value as Y_axis
///////////////Enum ShiftDirection///////////////
enum class ShiftDirection { Up, Right, Down, Left, Middle };
///////////////Enum RoadMask///////////////
enum class RoadMask {
	NONE = 0,
	LEFT = 1,
	TOP = 2,
	RIGHT = 4,
	BOTTOM = 8,
};
/////////////Current Position of Side Menu/////////////
enum class SideMenuStatus
{
	LEFT,
	RIGHT,
};
/////////////Icons Position higher or lower than current active icon or coord/////////////
enum class IconsPosition
{
	UPPER,
	LOWER,
};
///////////////All Possible Types of Mask///////////////
const int none = int(RoadMask::NONE);
const int leftside = int(RoadMask::LEFT);
const int topside = int(RoadMask::TOP);
const int rightside = int(RoadMask::RIGHT);
const int bottomside = int(RoadMask::BOTTOM);
const int vertical = int(RoadMask::BOTTOM) | int(RoadMask::TOP);
const int horizontal = int(RoadMask::LEFT) | int(RoadMask::RIGHT);
const int lefttop_angle = int(RoadMask::LEFT) | int(RoadMask::TOP);
const int righttop_angle = int(RoadMask::RIGHT) | int(RoadMask::TOP);
const int leftbottom_angle = int(RoadMask::LEFT) | int(RoadMask::BOTTOM);
const int rightbottom_angle = int(RoadMask::RIGHT) | int(RoadMask::BOTTOM);
const int right_T = int(RoadMask::RIGHT) | int(RoadMask::BOTTOM) | int(RoadMask::TOP);
const int left_T = int(RoadMask::LEFT) | int(RoadMask::BOTTOM) | int(RoadMask::TOP);
const int top_T = int(RoadMask::RIGHT) | int(RoadMask::LEFT) | int(RoadMask::TOP);
const int bottom_T = int(RoadMask::RIGHT) | int(RoadMask::LEFT) | int(RoadMask::BOTTOM);
const int cross = int(RoadMask::RIGHT) | int(RoadMask::LEFT) | int(RoadMask::BOTTOM) | int(RoadMask::TOP);
/////////////Point Coord Class/////////////
struct PointCoord
{
private:
	int x_coord;
	int y_coord;
public:
	PointCoord()
	{
		x_coord = 1;
		y_coord = 1;
	}
	~PointCoord()
	{}
	PointCoord(int x, int y) : x_coord(x), y_coord(y)
	{}
	PointCoord(COORD crd)
	{
		x_coord = static_cast<int>(crd.X) + 1;
		y_coord = static_cast<int>(crd.Y) + 1;
	}
	PointCoord(const PointCoord& pc)
	{
		x_coord = pc.get_x();
		y_coord = pc.get_y();
	}
	int get_x() const;
	int get_y() const;
	void set_coord(int _x, int _y);
	void set_coord(PointCoord pc);
	bool operator == (PointCoord);
};