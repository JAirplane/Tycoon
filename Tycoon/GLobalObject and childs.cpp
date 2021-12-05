#include "GlobalObject and childs.h"
///////////////Parent Class of All Objects///////////////
PointCoord GlobalObject::getUpperLeft() const
{
	return UpperLeft;
}
void GlobalObject::setUpperLeft(PointCoord pc)
{
	UpperLeft.set_coord(pc.get_x(), pc.get_y());
}
unsigned int GlobalObject::getHeightAddition() const
{
	return HeightAddition;
}
void GlobalObject::setHeightAddition(const int _hadd)
{
	HeightAddition = _hadd;
}
unsigned int GlobalObject::getWidthAddition() const
{
	return WidthAddition;
}
void GlobalObject::setWidthAddition(const int _wadd)
{
	WidthAddition = _wadd;
}
///////////////ConstructionManager Class: GlobalObject derived///////////////
unsigned int ConstructionManager::getConstructionCost() const
{
	return ConstructionCost;
}
void ConstructionManager::setConstructionCost(const int _constructioncost)
{
	ConstructionCost = _constructioncost;
}

string ConstructionManager::getDescription() const
{
	return Description;
}
void ConstructionManager::setDescription(string _desc)
{
	Description = _desc;
}
char ConstructionManager::getIconSymbol()
{
	return IconSymbol;
}
void ConstructionManager::setIconSymbol(const char symbol)
{
	IconSymbol = symbol;
}
Building* ConstructionManager::CreateBuilding()
{
	PointCoord upperleft = C_ptr->getCursorConsoleLocation();
	Building* constr_ptr = new Building(upperleft, this, ConstructionHeightAddition, ConstructionWidthAddition);
	return constr_ptr;
}
///////////////Building Manager Class: ConstructionManager derived///////////////
unsigned int BuildingManager::getDailyExpences() const
{
	return DailyExpences;
}
void BuildingManager::setDailyExpences(unsigned int _dailyexpences)
{
	DailyExpences = _dailyexpences;
}
char BuildingManager::getBuildingSymbol()
{
	return BuildingSymbol;
}
void BuildingManager::setBuildingSymbol(const char _buildingsymbol)
{
	BuildingSymbol = _buildingsymbol;
}
///////////////Construction Class: GlobalObject derived///////////////
ConstructionManager* Construction::getManager() const //no setter here
{
	return Manager_ptr;
}
///////////////Building Class: Construction derived///////////////
PointCoord Building::getEntrance() const
{
	return Entrance;
}
void Building::setEntrance(PointCoord _entrance)
{
	Entrance = _entrance;
}
unsigned int Building::getVisitorsCount() const
{
	return LastDayVisitors;
}
void Building::setVisitorsCount(unsigned int _visitorscount)
{
	LastDayVisitors = _visitorscount;
}
int Building::getProfit() const
{
	return LastDayProfit;
}
void Building::setProfit(int _profit)
{
	LastDayProfit = _profit;
}
///////////////Road Class: Construction derived///////////////
//GlobalObject* Road::CreateObject(PointCoord _pc)
//{
//	GlobalObject* Obj_ptr = new Road(_pc);
//	return Obj_ptr;
//}
char Road::SetRoadSymbol(int mask) const
{
	char RoadSymbol = 'a';
	switch (mask)
	{
	case none: return RoadSymbol = '+';
	case leftside: return RoadSymbol = '+';
	case topside: return RoadSymbol = '+';
	case rightside: return RoadSymbol = '+';
	case bottomside: return RoadSymbol = '+';
	case vertical: return RoadSymbol = '+';
	case horizontal: return RoadSymbol = '+';
	case lefttop_angle: return RoadSymbol = '+';
	case righttop_angle: return RoadSymbol = '+';
	case leftbottom_angle: return RoadSymbol = '+';
	case rightbottom_angle: return RoadSymbol = '+';
	case right_T: return RoadSymbol = '+';
	case left_T: return RoadSymbol = '+';
	case top_T: return RoadSymbol = '+';
	case bottom_T: return RoadSymbol = '+';
	case cross: return RoadSymbol = '+';
	default: return RoadSymbol = '-';
	}
}
bool Road::getGraphStatus() const
{
	return GraphStatus;
}
void Road::setGraphStatus(bool status)
{
	GraphStatus = status;
}
void Road::DefineGraphStatus(int mask)
{
	setGraphStatus(0);
	switch (mask)
	{
	case leftside: { setGraphStatus(1); return; }
	case topside: { setGraphStatus(1); return; }
	case rightside: { setGraphStatus(1); return; }
	case bottomside: { setGraphStatus(1); return; }
	case right_T: { setGraphStatus(1); return; }
	case left_T: { setGraphStatus(1); return; }
	case top_T: { setGraphStatus(1); return; }
	case bottom_T: { setGraphStatus(1); return; }
	case cross: { setGraphStatus(1); return; }
	default: return;
	}
}
bool Road::getRoadIsInChainStatus()
{
	return RoadIsInChain;
}
void Road::setRoadIsInChainStatus(bool chainflag)
{
	RoadIsInChain = chainflag;
}
///////////////Visitor Class///////////////
void Visitor::VisitorMove(int x, int y)
{
	setUpperLeft(PointCoord(x, y));
}
//GlobalObject* Visitor::CreateObject(PointCoord _pc)
//{
//	GlobalObject* fake_ptr = nullptr;
//	return fake_ptr;
//}