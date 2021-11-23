#pragma once
using namespace std;
#include "Coord and constants.h"
#include "drawheader.h"
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
	PointCoord getBottomRight() const;
	void setUpperLeft(PointCoord);
	void setBottomRight(PointCoord);
	virtual char getSymbol() const;
	virtual int getConstructionCost() const;
	virtual int getDailyExpences() const;
	virtual string getDescription() const;
};
/////////////Child Classes of Construction/////////////
/////////////Ice Cream Shop/////////////
class IceCreamShop : public GlobalObject
{
private:
	static int ConstructionCost;
	static int DailyExpences;
	int LastDayVisitors;
	int LastDayProfit;
	static char drawConstructionSymbol;
public:
	IceCreamShop(PointCoord _ul) : GlobalObject(_ul)
	{
		PointCoord pc;
		pc = getUpperLeft();
		setBottomRight(PointCoord(pc.get_x() + 1, pc.get_y() + 1));
		LastDayVisitors = 0;
		LastDayProfit = 0;
	}
	virtual int getConstructionCost() const;
	virtual int getDailyExpences() const;
	virtual char getSymbol() const;
};
/////////////Menu Icon of Ice Cream Shop/////////////
class IceCreamShopIcon : public IceCreamShop
{
private:
	Visualisation* Draw_ptr;
	string description;
public:
	IceCreamShopIcon(PointCoord _ul) : IceCreamShop(_ul)
	{
		description = "Ice Cream Shop! Everybody loves it!";
	}
	string getDescription() const override;
};
/////////////One Pixel of Road/////////////
class Road : public GlobalObject
{
private:
	static int ConstructionCost;
	static int DailyExpences;
public:
	Road(PointCoord _ul) : GlobalObject(_ul)
	{}
	~Road()
	{}
	virtual int getConstructionCost() const;
	virtual int getDailyExpences() const;
	virtual char getSymbol() const;
	PointCoord getRoadLocation() const;
	void setRoadLocation(PointCoord);
};
/////////////Menu Road Icon/////////////
class RoadIcon : public Road
{
private:
	Visualisation* Draw_ptr;
	string description;
public:
	RoadIcon(PointCoord _ul) : Road(_ul)
	{
		description = "Your visitors can walk roads only";
	}
	string getDescription() const override;
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
