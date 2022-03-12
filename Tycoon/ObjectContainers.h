#pragma once
#include <vector>
#include <typeinfo>
#include <functional>
#include "IngameObjectDerived.h"
/////////////Containers of All Objects in the Game/////////////
class AllObjects
{
private:
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
	list<Building*> buildings;
	list<Road*> roads;
	list<Visitor*> visitors;
	Construction* preliminaryConstruction_ptr;
	vector<Road*> outOfPlayingFieldEntrance;
public:
	AllObjects(Cursor* c_ptr, Visualisation* paint_ptr)
	{
		cursor_ptr = c_ptr;
		draw_ptr = paint_ptr;
		preliminaryConstruction_ptr = nullptr;
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
		delete preliminaryConstruction_ptr;
		for (auto parkEntrance : outOfPlayingFieldEntrance)
		{
			delete parkEntrance;
		}
	}
	void CreateParkEntrance(const PlayingField* playingField_ptr, ConstructionDescriptor* descriptor_ptr, Visualisation* draw_ptr);
	//
	const list<Building*>& GetAllBuildings() const;
	const list<Road*>& GetAllRoads() const;
	size_t GetBuildingsQuantity() const;
	size_t GetRoadsQuantity() const;
	size_t GetVisitorsQuantity() const;
	void AddObject(Building* obj_ptr);
	void AddObject(Road* obj_ptr);
	void AddObject(Visitor* obj_ptr);
	void AddPreliminaryElement(Construction* preliminary_ptr);
	Construction* GetPreliminaryElement() const;
	void ErasePreliminaryElement(Camera* camera_ptr, PlayingField* field_ptr);
	//
	bool RectangleImposition(PointCoord point, const MyRectangle* rect_ptr) const;
	bool RectangleImposition(IngameObject* object_ptr, const MyRectangle* rect_ptr) const;
	bool BuildingsImposition(PointCoord point) const;
	bool BuildingsImposition(IngameObject* object_ptr) const;
	bool RoadsImposition(PointCoord point) const;
	bool RoadsImposition(IngameObject* object_ptr) const;
	bool EntranceRoadsImposition(PointCoord point) const;
	bool VisitorsImposition(PointCoord point) const;
	bool VisitorsImposition(IngameObject* object_ptr) const;
	bool ObjectImposition(PointCoord point, PlayingField* field_ptr) const;
	bool ObjectImposition(IngameObject* object_ptr, const Camera* camera_ptr, const PlayingField* field_ptr) const;
	//
	void EraseObjects(Camera* camera_ptr);
	void ShiftBuildings(Direction shiftDirection, int shiftValue = 1);
	void ShiftRoads(Direction shiftDirection, int shiftValue = 1);
	void ShiftEntranceRoads(Direction shiftDirection, int shiftValue = 1);
	void ShiftVisitors(Direction shiftDirection, int shiftValue = 1);
	void DisplayBuildings(Camera* camera_ptr, PlayingField* field_ptr) const;
	void DisplayVisitors();
	void DisplayRoads(Camera* camera_ptr, PlayingField* field_ptr);
	void DisplayParkEntrance(const Camera* camera_ptr);
	Construction* FindConstruction(PointCoord location) const; //checks if location is on road or building
	void DeleteConstruction(Construction* forDeleting, function<bool(Construction*)> IsEqual);
};