#pragma once
#include <list>
#include <vector>
#include <typeinfo>
#include "ManagersDerived.h"
/////////////Parent Class for containers in the Game/////////////
class BasicContainer
{
private:
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
public:
	BasicContainer(Cursor* c_ptr, Visualisation* d_ptr) : cursor_ptr(c_ptr), draw_ptr(d_ptr)
	{}
	~BasicContainer()
	{}
	Cursor* GetCursor() const;
	Visualisation* GetDrawer() const;
}
/////////////Container of All Objects in the Game/////////////
class AllObjects : public BasicContainer
{
private:
	list<IngameObject*> everyObject;
	bool lastElementIsPreliminary;
public:
	AllObjects(Cursor* c_ptr, Visualisation* paint_ptr) : BasicContainer(c_ptr, paint_ptr)
	{
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
	bool ObjectImposition(PointCoord point, PlayingField* field_ptr) const;
	bool ObjectImposition(IngameObject* object_ptr, Camera* camera_ptr, PlayingField* field_ptr) const;
	void EraseObjects(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY);
	void ShiftAllObjects(Direction shiftDirection);
	void ShiftAllObjects(Direction shiftDirection, int shiftValue);
};
/////////////Container of All Types of buildings Class/////////////
class AllBuildings : public BasicContainer
{
private:
	list<Building*> buildings;
public:
	AllBuildings(Cursor* c_ptr, Visualisation* paint_ptr) : BasicContainer(c_ptr, paint_ptr)
	{}
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
class AllRoads : public BasicContainer
{
private:
	list<Road*> roads;
public:
	AllRoads(Cursor* c_ptr, Visualisation* paint_ptr) : BasicContainer(c_ptr, paint_ptr)
	{}
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
class AllVisitors : public BasicContainer
{
private:
	list<Visitor*> visitors;
	AllObjects* allObjects_ptr;
public:
	AllVisitors(Cursor* c_ptr, AllObjects* container_ptr, Visualisation* paint_ptr) : BasicContainer(c_ptr, paint_ptr)
	{
		allObjects_ptr = container_ptr;
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