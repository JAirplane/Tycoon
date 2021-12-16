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
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
	bool LastElementIsPreliminary;
public:
	AllObjects(Cursor* _cursor_ptr, Visualisation* _draw_ptr)
	{
		cursor_ptr = _cursor_ptr;
		draw_ptr = _draw_ptr;
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
	bool IsPartOfExistingObject(IngameObject* object_ptr, int camera_left_x, int camera_right_x, int camera_top_y, int camera_bottom_y);
	void EraseObjects(int camera_left_x, int camera_right_x, int camera_top_y, int camera_bottom_y);
};
/////////////Container of All Types of buildings Class/////////////
class Allbuildings
{
private:
	list<Building*> buildings;
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
public:
	Allbuildings(Cursor* _cursor_ptr, Visualisation* _draw_ptr)
	{
		cursor_ptr = _cursor_ptr;
		draw_ptr = _draw_ptr;
	}
	~Allbuildings()
	{
		list<Building*>::iterator iter;
		for (iter = buildings.begin(); iter != buildings.end(); iter++)
		{
			delete (*iter);
		}
	}
	void AddBuilding(Building* go_ptr);
	void DisplayBuildings(int camera_left_x, int camera_right_x, int camera_top_y, int camera_bottom_y);
	const list<Building*> getAllbuildings();
	vector<PointCoord> getPotentialRoadCoords(); //returns points that are near the entrances
	void setRoadConnectionStatus(vector<PointCoord> connectedroads);
};
/////////////Road Container Class/////////////
class AllRoads
{
private:
	list<Road*> Roads;
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
public:
	AllRoads(Cursor* _cursor_ptr, Visualisation* _draw_ptr)
	{
		cursor_ptr = _cursor_ptr;
		draw_ptr = _draw_ptr;
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
	void DisplayRoads(int camera_left_x, int camera_right_x, int camera_top_y, int camera_bottom_y);
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
	Cursor* cursor_ptr;
	AllObjects* AllObjects_ptr;
	Visualisation* draw_ptr;
public:
	AllVisitors(Cursor* _cursor_ptr, AllObjects* _AllObjects_ptr, Visualisation* _draw_ptr)
	{
		cursor_ptr = _cursor_ptr;
		AllObjects_ptr = _AllObjects_ptr;
		draw_ptr = _draw_ptr;
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
	list<Visitor*>& getAllVisitors();
};