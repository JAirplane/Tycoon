#pragma once
#include <list>
#include <vector>
#include <typeinfo>
#include "ManagersDerived.h"
/////////////Container of All Objects in the Game/////////////
class AllObjects
{
private:
	list<IngameObject*> everyObject;
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
	bool lastElementIsPreliminary;
public:
	AllObjects(Cursor* c_ptr, Visualisation* paint_ptr)
	{
		cursor_ptr = c_ptr;
		draw_ptr = paint_ptr;
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
	int GetElementsQuantity() const;
	void AddObject(IngameObject* obj_ptr);
	void AddObject(IngameObject* obj_ptr, int position);
	void SetLastElementFlag(bool changer);
	bool GetLastElementFlag();
	IngameObject* GetPreliminaryElement(); //it takes last element of everyObject list
	void AddPreliminaryElement(Construction* c_ptr);
	void ErasePreliminaryElement();
	bool IsPartOfExistingObject(PointCoord point) const;
	bool IsPartOfExistingObject(IngameObject* object_ptr, int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY);
	void EraseObjects(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY);
	void ShiftAllObjects(Direction shiftDirection);
	void ShiftAllObjects(Direction shiftDirection, int shiftValue);
};
/////////////Container of All Types of buildings Class/////////////
class AllBuildings
{
private:
	list<Building*> buildings;
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
public:
	AllBuildings(Cursor* c_ptr, Visualisation* paint_ptr)
	{
		cursor_ptr = c_ptr;
		draw_ptr = paint_ptr;
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
	void DisplayBuildings(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY) const;
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
	AllRoads(Cursor* c_ptr, Visualisation* paint_ptr)
	{
		cursor_ptr = c_ptr;
		draw_ptr = paint_ptr;
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
	int RoadEnvironment(PointCoord point);
	void DisplayRoads(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY);
	void RedrawNeibourRoads(PointCoord roadUpperLeft); //when new road tile added or removed redraw all neighbor roads
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
	AllVisitors(Cursor* c_ptr, AllObjects* container_ptr, Visualisation* paint_ptr)
	{
		cursor_ptr = c_ptr;
		allObjects_ptr = container_ptr;
		draw_ptr = paint_ptr;
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
};