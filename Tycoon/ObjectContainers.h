#pragma once
using namespace std;
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
	list< GlobalObject* > EveryObject;
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
		list< GlobalObject* >::iterator iter;
		for (iter = EveryObject.begin(); iter != EveryObject.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addObject(GlobalObject* obj_ptr);
	list< GlobalObject* >& getAllObjects();
	void setLastElementFlag(bool changer);
	bool getLastElementFlag();
	GlobalObject* getPreliminaryElement();
	void ErasePreliminaryElement();
	BuildingType DefinePointerType(GlobalObject* go_ptr);
};
/////////////Container of All Types of Buildings Class/////////////
class AllBuildings
{
private:
	list< GlobalObject* > Buildings;
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
		list< GlobalObject* >::iterator iter;
		for (iter = Buildings.begin(); iter != Buildings.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addBuilding(GlobalObject* go_ptr);
	list< GlobalObject* >& getAllBuildings();
};
/////////////Road Container Class/////////////
class AllRoads
{
private:
	list<GlobalObject*> Roads;
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
		list<GlobalObject*>::iterator iter;
		for (iter = Roads.begin(); iter != Roads.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addRoad(GlobalObject* r_ptr);
	list<GlobalObject*>& getAllRoads();
	int RoadEnvironment(PointCoord pc1);
	char SetRoadSymbol(int mask) const;
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
	list<Visitor*>& getAllVisitors();
};