#pragma once
#include <typeinfo>
#include <functional>
#include "GameStats.h"
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
	RoadGraph* graph_ptr;
public:
	AllObjects(Cursor* c_ptr, Visualisation* paint_ptr)
	{
		cursor_ptr = c_ptr;
		draw_ptr = paint_ptr;
		preliminaryConstruction_ptr = nullptr;
		graph_ptr = new RoadGraph();
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
		delete graph_ptr;
	}
	void CreateExit(const PlayingField* playingField_ptr, Visualisation* draw_ptr);
	void CreateParkEntrance(const PlayingField* playingField_ptr, ConstructionDescriptor* descriptor_ptr, Visualisation* draw_ptr);
	//
	const list<Building*>& GetAllBuildings() const;
	const list<Road*>& GetAllRoads() const;
	const list<Visitor*>& GetAllVisitors() const;
	RoadGraph* GetGraph() const;
	void AddObject(Building* obj_ptr);
	void AddObject(Road* obj_ptr);
	void AddObject(Visitor* obj_ptr);
	void AddPreliminaryElement(Construction* preliminary_ptr);
	Construction* GetPreliminaryElement() const;
	void ErasePreliminaryElement(Camera* camera_ptr, PlayingField* field_ptr);
	//
	bool BuildingsImposition(PointCoord point) const;
	bool BuildingsImposition(IngameObject* object_ptr) const;
	bool RoadsImposition(PointCoord point) const;
	bool RoadsImposition(IngameObject* object_ptr) const;
	bool VisitorsImposition(PointCoord point) const;
	bool VisitorsImposition(IngameObject* object_ptr) const;
	bool ObjectImposition(PointCoord point, PlayingField* field_ptr) const;
	bool ObjectImposition(IngameObject* object_ptr, const Camera* camera_ptr, const PlayingField* field_ptr) const;
	//
	void EraseObjects(Camera* camera_ptr);
	void ShiftBuildings(Direction shiftDirection, int shiftValue = 1);
	void ShiftRoads(Direction shiftDirection, int shiftValue = 1);
	void ShiftVisitors(Direction shiftDirection, int shiftValue = 1);
	void DisplayBuildings(const Camera* camera_ptr, const PlayingField* field_ptr) const;
	void DisplayVisitors(const Camera* camera_ptr);
	void DisplayRoads(const Camera* camera_ptr, const PlayingField* field_ptr);
	//
	Construction* FindConstruction(PointCoord location) const; //checks if location is on road or building
	void DeleteConstruction(Construction* forDeleting, function<bool(Construction*)> IsEqual);
	void DeleteVisitor(Visitor* forDeleting, function<bool(Visitor*)> IsEqual);
	//
	void AddEdge(int mainRoadIndex, PointCoord location, Direction side, vector<pair<pair<int, int>, Direction> >& roadEdges) const;
	vector<pair<pair<int, int>, Direction> > GetRoadEdges(Road* someRoad) const;
	//
	void ClearVisitorPathes(int roadIndex);
	void ClearVisitorPathes(Construction* destination);
	vector<Visitor*> AllVisitorsStep(const Camera* camera_ptr, const PlayingField* field_ptr, GameStats* statistics, int lowestEntertainmentPrice);
	void DeleteVisitors(vector<Visitor*>& forDeleting);
};