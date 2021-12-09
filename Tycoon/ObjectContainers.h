#pragma once
#include <list>
#include <vector>
#include <typeinfo>
#include "ManagersDerived.h"
#include "drawheader.h"
/////////////Container of All Objects in the Game/////////////
class AllObjects
{
private:
	list<IngameObject*> EveryObject;
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
		list<IngameObject*>::iterator iter;
		for (iter = EveryObject.begin(); iter != EveryObject.end(); iter++)
		{
			delete (*iter);
		}
	}
	list<IngameObject*>& getAllObjects();
	void addObject(IngameObject* obj_ptr);
	void addObject(IngameObject* obj_ptr, int _position);
	void setLastElementFlag(bool changer);
	bool getLastElementFlag();
	IngameObject* getPreliminaryElement(); //it takes last element of EveryObject list
	void ErasePreliminaryElement();
	bool IsPartOfExistingObject(PointCoord _pc);
};
/////////////Container of All Types of Buildings Class/////////////
class AllBuildings
{
private:
	list<Construction*> Buildings;
	Cursor* C_ptr;
	Visualisation* Draw_ptr;
public:
	AllBuildings(Cursor* _C_ptr, Visualisation* _Draw_ptr)
	{
		C_ptr = _C_ptr;
		Draw_ptr = _Draw_ptr;
	}
	~AllBuildings()
	{
		list<Construction*>::iterator iter;
		for (iter = Buildings.begin(); iter != Buildings.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addBuilding(Construction* go_ptr);
	void DisplayBuildings();
	void EraseBuildings();
	const list<Construction*> getAllBuildings();
	vector<PointCoord> getPotentialRoadCoords(); //returns points that are near the entrances
	void setRoadConnectionStatus(vector<PointCoord> connectedroads);
};
/////////////Road Container Class/////////////
class AllRoads
{
private:
	list<Construction*> Roads;
	Cursor* C_ptr;
	Visualisation* Draw_ptr;
public:
	AllRoads(Cursor* _C_ptr, Visualisation* _Draw_ptr)
	{
		C_ptr = _C_ptr;
		Draw_ptr = _Draw_ptr;
	}
	~AllRoads()
	{
		list<Construction*>::iterator iter;
		for (iter = Roads.begin(); iter != Roads.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addRoad(Construction* r_ptr);
	list<Construction*>& getAllRoads();
	int RoadEnvironment(PointCoord pc1);
	char SetRoadSymbol(int mask) const;
	void DisplayRoads();
	void EraseRoads();
	void IsGraph_RoadsOnly();
	vector<PointCoord> RoadConnectedToEntranceCheck(vector<PointCoord> possibleroads);
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