#pragma once
#include <list>
#include <vector>
#include <typeinfo>
#include "Camera.h"
/////////////Containers of All Objects in the Game/////////////
class AllObjects
{
private:
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
	list<Building*> buildings;
	list<Road*> roads;
	list<Visitor*> visitors;
	PreliminaryStatus containsPreliminary;
public:
	AllObjects(Cursor* c_ptr, Visualisation* paint_ptr)
	{
		cursor_ptr = c_ptr;
		draw_ptr = paint_ptr;
		containsPreliminary = PreliminaryStatus::NONE;
	}
	~AllObjects()
	{
		list<Building*>::iterator iter;
		for (iter = buildings.begin(); iter != buildings.end(); iter++)
		{
			delete (*iter);
		}
		list<Road*>::iterator iter;
		for (iter = roads.begin(); iter != roads.end(); iter++)
		{
			delete (*iter);
		}
		list<Visitor*>::iterator iter;
		for (iter = visitors.begin(); iter != visitors.end(); iter++)
		{
			delete (*iter);
		}
	}
	int GetBuildingsQuantity() const;
	int GetRoadsQuantity() const;
	int GetVisitorsQuantity() const;
	void AddObject(Building* obj_ptr, int position = GetElementsQuantity() + 1, bool isPreliminary = false);
	void AddObject(Road* obj_ptr, int position = GetElementsQuantity() + 1, bool isPreliminary = false);
	void AddObject(Visitor* obj_ptr, int position = GetElementsQuantity() + 1, bool isPreliminary = false);
	PreliminaryStatus GetPreliminaryStatus() const;
	Construction* GetPreliminaryElement(); //it takes last element of everyObject list
	void ErasePreliminaryElement();
	bool ObjectImposition(PointCoord point, PlayingField* field_ptr) const;
	bool ObjectImposition(IngameObject* object_ptr, Camera* camera_ptr, PlayingField* field_ptr) const;
	void EraseObjects(Camera* camera_ptr);
	void ShiftAllObjects(Direction shiftDirection);
	void ShiftAllObjects(Direction shiftDirection, int shiftValue);
	void DisplayBuildings(Camera* camera_ptr) const;
	vector<PointCoord> GetPotentialRoadCoords(); //returns points that are near the entrances
	void SetRoadConnectionStatus(vector<PointCoord> connectedRoads);
	void VisitorAppear();
	bool LocationCheck(PointCoord);
	void DisplayVisitors();
	int RoadEnvironment(PointCoord point);
	void DisplayRoads(int cameraLeftX, int cameraRightX, int cameraTopY, int cameraBottomY);
	void RedrawNeibourRoads(PointCoord roadUpperLeft); //when new road tile added or removed redraw all neighbor roads
	void IsGraphRoadsOnly();
	vector<PointCoord> RoadConnectedToEntranceCheck(vector<PointCoord> possibleRoads);
};