#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct PointCoord
{
private:
	int x_coord;
	int y_coord;
public:
	PointCoord(int x, int y) : x_coord(x), y_coord(y)
	{}
	int get_x();
	int get_y();
	void set_coord(int, int);
};
class WorldMap
{
private:
	map< Construction*, int > WMConstructions;
	map< Construction*, int >::iterator iter;
public:
	void addConst(Construction* cstrptr);
};
/////////////Parent Class of all constructions/////////////
class Construction
{
private:
	PointCoord UpperRight;
	PointCoord BottomLeft;
	int ConstCondition;
public:
	Construction(PointCoord ur, PointCoord bl) : UpperRight(ur), BottomLeft(bl), ConstCondition(100)
	{}
	PointCoord getUpperRight();
	PointCoord getBottomLeft();
};
/////////////Child Classes of Construction/////////////
class SomeBuiding : public Construction
{
private:
	static const int ConstCost;
	static const int DailyExpences;
	int LastDayVisitors;
	int LastDayProfit;
public:
	SomeBuiding(PointCoord _ur, PointCoord _b1) : Construction(_ur, _b1)
	{}
	static const int getSomeBuidingCost();
};
class Road : public Construction
{
private:
	static const int ConstCost;
	static const int DailyExpences;
public:
	Road(PointCoord _ur, PointCoord _b1) : Construction(_ur, _b1)
	{}
	static const int getRoadCost();
};
/////////////End of Constructions Classes/////////////
/////////////Visitor Classes/////////////
class Visitor
{
private:
	PointCoord Location;
	int FoodCapacity;
	int NeedToPee;
public:
	Visitor(PointCoord loc, int fc, int ntp) : Location(loc), FoodCapacity(fc), NeedToPee(ntp)
	{}
	PointCoord getLoc();
	void NeedsUp();
	void ChooseDir();
};
class AllCurrentVisitors
{
private:
	vector<Visitor*> AllVisitors;
	vector<Visitor*>::iterator iter;
public:
	void addVisitor(Visitor* vptr);
	bool LocationCheck(PointCoord);
};
class VisitorsLife
{
private:
	AllCurrentVisitors* ACVptr;
	drawVisitor* dVptr;
public:
	VisitorsLife(AllCurrentVisitors* acv) : ACVptr(acv)
	{}
	void VisitorAppear();
	bool VisitorLocCheck(PointCoord);
};
