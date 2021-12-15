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
	bool IsEmpty();
	void setLastElementFlag(bool changer);
	bool getLastElementFlag();
	IngameObject* getPreliminaryElement(); //it takes last element of EveryObject list
	void ErasePreliminaryElement();
	bool IsPartOfExistingObject(PointCoord _pc);
	bool IsPartOfExistingObject(IngameObject* object_ptr, int camera_left_x, int camera_right_x, int camera_top_y, int camera_bottom_y);
};
/////////////Container of All Types of Buildings Class/////////////
class AllBuildings
{
private:
	list<Building*> Buildings;
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
		list<Building*>::iterator iter;
		for (iter = Buildings.begin(); iter != Buildings.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addBuilding(Building* go_ptr);
	void DisplayBuildings();
	void EraseBuildings();
	const list<Building*> getAllBuildings();
	vector<PointCoord> getPotentialRoadCoords(); //returns points that are near the entrances
	void setRoadConnectionStatus(vector<PointCoord> connectedroads);
};
/////////////Road Container Class/////////////
class AllRoads
{
private:
	list<Road*> Roads;
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
		list<Road*>::iterator iter;
		for (iter = Roads.begin(); iter != Roads.end(); iter++)
		{
			delete (*iter);
		}
	}
	void addRoad(Road* r_ptr);
	list<Road*>& getAllRoads();
	int RoadEnvironment(PointCoord pc1);
	void DisplayRoads();
	void EraseRoads();
	void RedrawRoads(Road* r_ptr); //when new road tile added or removed redraw all neighbor roads
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