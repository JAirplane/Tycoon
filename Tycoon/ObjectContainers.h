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
		list<Building*>::iterator buildingIter;
		for (buildingIter = buildings.begin(); buildingIter != buildings.end(); buildingIter++)
		{
			delete (*buildingIter);
		}
		list<Road*>::iterator roadIter;
		for (roadIter = roads.begin(); roadIter != roads.end(); roadIter++)
		{
			delete (*roadIter);
		}
		list<Visitor*>::iterator visitorIter;
		for (visitorIter = visitors.begin(); visitorIter != visitors.end(); visitorIter++)
		{
			delete (*visitorIter);
		}
	}
	int GetBuildingsQuantity() const;
	int GetRoadsQuantity() const;
	int GetVisitorsQuantity() const;
	void AddObject(Building* obj_ptr);
	void AddObject(Road* obj_ptr);
	void AddObject(Visitor* obj_ptr, int position = 0, bool isPreliminary = false);
	PreliminaryStatus GetPreliminaryStatus() const;
	Construction* GetPreliminaryElement(); //it takes last element of everyObject list
	void ErasePreliminaryElement();
	bool ObjectImposition(PointCoord point, PlayingField* field_ptr) const;
	bool ObjectImposition(IngameObject* object_ptr, Camera* camera_ptr, PlayingField* field_ptr) const;
	void EraseObjects(Camera* camera_ptr);
	void ShiftBuildings(Direction shiftDirection, int shiftValue = 1);
	void ShiftRoads(Direction shiftDirection, int shiftValue = 1);
	void ShiftVisitors(Direction shiftDirection, int shiftValue = 1);
	void DisplayBuildings(Camera* camera_ptr, PlayingField* field_ptr) const;
	void VisitorAppear();
	bool LocationCheck(PointCoord);
	void DisplayVisitors();
	int RoadEnvironment(PointCoord point);
	void DisplayRoads(Camera* camera_ptr, PlayingField* field_ptr);
	void RedrawNeibourRoads(PointCoord roadUpperLeft,Camera* camera_ptr, PlayingField* field_ptr); //when new road tile added or removed redraw all neighbor roads
	void IsGraphRoadsOnly();
	void SetRoadAndBuildingConnectionStatuses(); //sets true status to every building object that is connected to road and sets true "IsGraph" status to every connected road as well
	void RotatePreliminaryBuilding();
};