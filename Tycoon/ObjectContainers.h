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
	list<IngameObject*> everyObject;
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
	bool lastElementIsPreliminary;
public:
	AllObjects(Cursor* cursor_ptr, Visualisation* draw_ptr)
	{
		this->cursor_ptr = cursor_ptr;
		this->draw_ptr = draw_ptr;
		lastElementIsPreliminary = 0;
	}
	~AllObjects()
	{
		list<IngameObject*>::iterator iter;
		for (iter = everyObject.begin(); iter != everyObject.end(); iter++)
		{
			delete (*iter);
		}
	}
	list<IngameObject*>& GetAllObjects();
	void AddObject(IngameObject* obj_ptr);
	void AddObject(IngameObject* obj_ptr, int position);
	void SetLastElementFlag(bool changer);
	bool GetLastElementFlag();
	IngameObject* GetPreliminaryElement(); //it takes last element of everyObject list
	void ErasePreliminaryElement();
	bool IsPartOfExistingObject(PointCoord point);
	bool IsPartOfExistingObject(IngameObject* object_ptr, int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY);
	void EraseObjects(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY);
};
/////////////Container of All Types of buildings Class/////////////
class AllBuildings
{
private:
	list<Building*> buildings;
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
public:
	AllBuildings(Cursor* cursor_ptr, Visualisation* draw_ptr)
	{
		this->cursor_ptr = cursor_ptr;
		this->draw_ptr = draw_ptr;
	}
	~AllBuildings()
	{
		list<Building*>::iterator iter;
		for (iter = buildings.begin(); iter != buildings.end(); iter++)
		{
			delete (*iter);
		}
	}
	void AddBuilding(Building* go_ptr);
	void DisplayBuildings(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY);
	const list<Building*> GetAllBuildings();
	vector<PointCoord> GetPotentialRoadCoords(); //returns points that are near the entrances
	void SetRoadConnectionStatus(vector<PointCoord> connectedRoads);
};
/////////////Road Container Class/////////////
class AllRoads
{
private:
	list<Road*> roads;
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
public:
	AllRoads(Cursor* cursor_ptr, Visualisation* draw_ptr)
	{
		this->cursor_ptr = cursor_ptr;
		this->draw_ptr = draw_ptr;
	}
	~AllRoads()
	{
		list<Road*>::iterator iter;
		for (iter = roads.begin(); iter != roads.end(); iter++)
		{
			delete (*iter);
		}
	}
	void AddRoad(Road* r_ptr);
	list<Road*>& GetAllRoads();
	int RoadEnvironment(PointCoord point);
	void DisplayRoads(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY);
	void RedrawrRoads(Road* r_ptr); //when new road tile added or removed redraw all neighbor roads
	void IsGraphRoadsOnly();
	vector<PointCoord> RoadConnectedToEntranceCheck(vector<PointCoord> possibleRoads);
	void SetChainStatus();
};
/////////////Visitor Container Class/////////////
class AllVisitors
{
private:
	list<Visitor*> visitors;
	Cursor* cursor_ptr;
	AllObjects* allObjects_ptr;
	Visualisation* draw_ptr;
public:
	AllVisitors(Cursor* cursor_ptr, AllObjects* allObjects_ptr, Visualisation* draw_ptr)
	{
		this->cursor_ptr = cursor_ptr;
		this->allObjects_ptr = allObjects_ptr;
		this->draw_ptr = draw_ptr;
	}
	~AllVisitors()
	{
		list<Visitor*>::iterator iter;
		for (iter = visitors.begin(); iter != visitors.end(); iter++)
		{
			delete (*iter);
		}
	}
	void VisitorAppear();
	bool LocationCheck(PointCoord);
	void DisplayVisitors();
	list<Visitor*>& GetAllVisitors();
};