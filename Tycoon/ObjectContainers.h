#pragma once
#include <list>
#include <typeinfo>
#include "CursorClass.h"
enum class BuildingType
{
	Road,
	IceCreamShop,
};
/////////////Container of All Objects in the Game/////////////
class AllObjects
{
private:
	list<GlobalObject*> EveryObject;
	Cursor* C_ptr;
	bool LastElementIsPreliminary;
public:
	AllObjects(Cursor* _C_ptr)
	{
		C_ptr = _C_ptr;
		LastElementIsPreliminary = 0;
	}
	~AllObjects()
	{
		list<GlobalObject*>::iterator iter;
		for (iter = EveryObject.begin(); iter != EveryObject.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addObject(GlobalObject* obj_ptr);
	void addBeforePreliminary(GlobalObject* obj_ptr);
	list<GlobalObject*>& getAllObjects();
	void setLastElementFlag(bool changer);
	bool getLastElementFlag();
	GlobalObject* getPreliminaryElement();
	void ErasePreliminaryElement();
	BuildingType DefinePointerType(GlobalObject* go_ptr);
	bool IsPartOfExistingObject(PointCoord _pc);
};
/////////////Container of All Types of Buildings Class/////////////
class AllBuildings
{
private:
	list<Building*> Buildings;
	Cursor* C_ptr;
	AllObjects* AllObjects_ptr;
	Visualisation* Draw_ptr;
public:
	AllBuildings(Cursor* _C_ptr, AllObjects* _AllObjects_ptr, Visualisation* _Draw_ptr)
	{
		C_ptr = _C_ptr;
		AllObjects_ptr = _AllObjects_ptr;
		Draw_ptr = _Draw_ptr;
	}
	~AllBuildings()
	{
		list<Building*>::iterator iter;
		for (iter = Buildings.begin(); iter != Buildings.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addBuilding(Building* go_ptr);
	void DisplayBuildings();
	void EraseBuildings();
	void addBeforePreliminary(Building* obj_ptr);
	list<Building*>& getAllBuildings();
};
/////////////Road Container Class/////////////
class AllRoads
{
private:
	list<Road*> Roads;
	Cursor* C_ptr;
	AllObjects* AllObjects_ptr;
	Visualisation* Draw_ptr;
public:
	AllRoads(Cursor* _C_ptr, AllObjects* _AllObjects_ptr, Visualisation* _Draw_ptr)
	{
		C_ptr = _C_ptr;
		AllObjects_ptr = _AllObjects_ptr;
		Draw_ptr = _Draw_ptr;
	}
	~AllRoads()
	{
		list<Road*>::iterator iter;
		for (iter = Roads.begin(); iter != Roads.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addRoad(Road* r_ptr);
	void addBeforePreliminary(Road* obj_ptr);
	list<Road*>& getAllRoads();
	int RoadEnvironment(PointCoord pc1);
	char SetRoadSymbol(int mask) const;
	void DisplayRoads();
	void EraseRoads();
	void IsGraph_RoadsOnly();
	void setChainStatus();
};
/////////////Visitor Container Class/////////////
class AllVisitors
{
private:
	list<Visitor*> Visitors;
	Cursor* C_ptr;
	AllObjects* AllObjects_ptr;
	Visualisation* Draw_ptr;
public:
	AllVisitors(Cursor* _C_ptr, AllObjects* _AllObjects_ptr, Visualisation* _Draw_ptr)
	{
		C_ptr = _C_ptr;
		AllObjects_ptr = _AllObjects_ptr;
		Draw_ptr = _Draw_ptr;
	}
	~AllVisitors()
	{
		list<Visitor*>::iterator iter;
		for (iter = Visitors.begin(); iter != Visitors.end(); iter++)
		{
			delete (*iter);
		}
	}
	void VisitorAppear();
	bool LocationCheck(PointCoord);
	void DisplayVisitors();
	void EraseVisitors();
	list<Visitor*>& getAllVisitors();
};