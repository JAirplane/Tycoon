#pragma once
using namespace std;
#include "Coord and constants.h"
/////////////Parent Class of all constructions/////////////
class GlobalObject
{
private:
	PointCoord UpperLeft;
	PointCoord BottomRight;
	int StartCondition;
public:
	GlobalObject(PointCoord ul) : UpperLeft(ul), StartCondition(100)
	{}
	~GlobalObject()
	{}
	PointCoord getUpperLeft() const;
	PointCoord getBottomRight();
	void setUpperLeft(PointCoord);
	void setBottomRight(PointCoord);
	virtual const char getSymbol();
};
/////////////Child Classes of Construction/////////////
/////////////Ice Cream Shop/////////////
class IceCreamShop : public GlobalObject
{
private:
	static const int ConstructionCost;
	static const int DailyExpences;
	int LastDayVisitors;
	int LastDayProfit;
	static const char drawConstructionSymbol;
public:
	IceCreamShop(PointCoord _ul) : GlobalObject(_ul)
	{
		PointCoord pc;
		pc = getUpperLeft();
		setBottomRight(PointCoord(pc.get_x() - 1, pc.get_y() - 1));
		LastDayVisitors = 0;
		LastDayProfit = 0;
	}
	static const int getIceCreamShopCreateCost();
	virtual const char getSymbol();
};
/////////////One Pixel of Road/////////////
class Road : public GlobalObject
{
private:
	int RoadEnvironmentMask;
	static const int RoadCost;
	static const char drawRoadSymbol;
public:
	Road(PointCoord _ul) : GlobalObject(_ul)
	{
		RoadEnvironmentMask = 0;
	}
	~Road()
	{}
	static const int getRoadCost();
	const char getRoadSymbol() const;
	PointCoord getRoadLocation() const;
	void setRoadLocation(PointCoord);
	int& get_set_RoadEnvironmentMask();
};
/////////////People are looking for some fun!/////////////
class Visitor : public GlobalObject
{
private:
	int FoodCapacity;
	int NeedToPee;
public:
	Visitor(PointCoord _ul, int fc, int ntp) : GlobalObject(_ul)
	{
		FoodCapacity = fc;
		NeedToPee = ntp;
	}
	~Visitor()
	{}
	PointCoord getLocation();
	void VisitorMove(int, int);
	void NeedsUp();
	void ChooseDir();
};
/////////////End of Constructions Classes/////////////
