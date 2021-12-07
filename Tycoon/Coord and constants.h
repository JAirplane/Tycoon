#pragma once
//#include "unicode/uchar.h"
#include "unicode/uchriter.h"
#include "msoftcon.h"
using namespace std;
//int ucharrrrrrrrrrrr = 'a';
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
/////////////Construction Options Class : Singleton pattern/////////////
class ConstructionOptions
{
protected:
	ConstructionOptions() {}
	~ConstructionOptions()
	{
		delete ConstructionParameters;
	}
	static ConstructionOptions* ConstructionParameters;
public:
	ConstructionOptions(ConstructionOptions& other) = delete;
	void operator=(const ConstructionOptions&) = delete;
	static ConstructionOptions* getAllOptions();
	///////////////Height Addition Constants///////////////
	virtual const int getIceCreamShopHeightAdd() const;
	virtual const int getMenuElementBordersHeight() const; //height of 1 element of menu
	virtual const int getRoadHeightAdd() const;
	virtual const int getVisitorHeightAdd() const;
	virtual const int getVisibleMapHeight() const;
	virtual const int getMenuHeightAdd() const;
	///////////////Width Addition Constants///////////////
	virtual const int getIceCreamShopWIdthAdd() const;
	virtual const int getRoadWidthAdd() const;
	virtual const int getVisitorWidthAdd() const;
	virtual const int getVisibleMapWidth() const;
	virtual const int getMenuWidthAdd() const;
	///////////////Cost Initialisation Constants///////////////
	virtual const int getIceCreamShopCost() const;
	virtual const int getRoadCost() const;
	///////////////Daily Expences Initialisation Constants///////////////
	virtual const int getIceCreamShopExpences() const;
	///////////////Description Initialisation Constants///////////////
	virtual const string getIceCreamShopDescription() const;
	virtual const string getRoadDescription() const;
	///////////////Building Symbol Constants///////////////
	virtual const char getIceCreamShopSymbol() const;
	///////////////Initialisation Coord Constants///////////////
	virtual const PointCoord getVisibleMapInitialCoordUL() const;

};