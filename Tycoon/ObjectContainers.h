#pragma once
#include <typeinfo>
#include <functional>
#include "RoadGraph.h"
/////////////Containers of All Objects in the Game/////////////
class AllObjects : public GraphStatusObserverInterface
{
private:
	Cursor* cursor_ptr;
	Visualisation* draw_ptr;
	list<Building*> buildings;
	list<Road*> roads;
	list<Visitor*> visitors;
	Construction* preliminaryConstruction_ptr;
	vector<Road*> outOfPlayingFieldEntrance;
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
		for (auto parkEntrance : outOfPlayingFieldEntrance)
		{
			delete parkEntrance;
		}
		delete graph_ptr;
	}
	void CreateParkEntrance(const PlayingField* playingField_ptr, ConstructionDescriptor* descriptor_ptr, Visualisation* draw_ptr);
	//

	void GraphStatusUpdate(Road* graphStatusChanged_ptr) override;
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
	//
	Road* FindRoad(PointCoord location) const;
	Building* FindBuilding(PointCoord location) const;
	Construction* FindConstruction(PointCoord location) const; //checks if location is on road or building
	Construction* FindOutOfPlayingFieldConstruction(PointCoord location) const;
	void DeleteConstruction(Construction* forDeleting, function<bool(Construction*)> IsEqual);
	void DeleteVisitor(Visitor* forDeleting, function<bool(Visitor*)> IsEqual);
	//
	const Road* FindNextPathPoint(PointCoord point, PointCoord previousPathElement);
	vector<PointCoord> FindPathToTheNearestNode(PointCoord location, Direction dir);
	Edge* UpdateEdge(Node* updated_ptr, Direction side);
	vector<int> UpdateEdges(Node* updated_ptr, int realRoadMask); //it returns indices of the neibour nodes
	//
	void MoveInOneStep(Visitor* person, const Camera* camera_ptr);
	void MoveOutOneStep(Visitor* person, Construction* visitorLocationRoad, const Camera* camera_ptr, const PlayingField* field_ptr);
	void AllVisitorsStep(const Camera* camera_ptr, const PlayingField* field_ptr);
};