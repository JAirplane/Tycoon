#pragma once
#include "unicode/uchar.h"
#include "unicode/unistr.h"
#include "msoftcon.h"
using namespace std;
///////////////Enum ShiftDirection///////////////
enum class Direction { None, Up, Right, Down, Left };
///////////////Enum RoadMask///////////////
enum class RoadMask {
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
		x_coord = pc.Get_x();
		y_coord = pc.Get_y();
	}
	int Get_x() const;
	int Get_y() const;
	void set_coord(int _x, int _y);
	void set_coord(PointCoord pc);
	bool operator == (PointCoord);
};