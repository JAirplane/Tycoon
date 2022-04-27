#include "ManagersDerived.h"
///////////////Building Manager Class: Construction Manager derived///////////////
Construction* BuildingManager::CreateConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const
{
	Building* building_ptr = new Building(upperLeft, GetDescriptor(), paint_ptr);
	allObjects_ptr->AddObject(building_ptr);
	if (allObjects_ptr->GetPreliminaryElement() != nullptr)
	{
		building_ptr->CopyEntrance(allObjects_ptr->GetPreliminaryElement());
	}
	return building_ptr;
}
Construction* BuildingManager::CreatePreliminaryConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const
{
	Building* building_ptr = new Building(upperLeft, GetDescriptor(), paint_ptr);
	allObjects_ptr->AddPreliminaryElement(building_ptr);
	return building_ptr;
}
///////////////Road Manager Class: Construction Manager derived///////////////
Construction* RoadManager::CreateConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const
{
	Road* road_ptr = new Road(upperLeft, GetDescriptor(), paint_ptr);
	road_ptr->GraphStatusAttach(allObjects_ptr->GetGraph());
	allObjects_ptr->AddObject(road_ptr);
	auto roadEdges = allObjects_ptr->GetRoadEdges(road_ptr);
	road_ptr->GraphStatusNotify(roadEdges);
	return road_ptr;
}
Construction* RoadManager::CreatePreliminaryConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const
{
	Road* road_ptr = new Road(upperLeft, GetDescriptor(), paint_ptr);
	allObjects_ptr->AddPreliminaryElement(road_ptr);
	return road_ptr;
}
//
Construction* VisibleOutsideRoadManager::CreateConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const
{
	VisibleOutsidePlayingfieldRoad* road_ptr = new VisibleOutsidePlayingfieldRoad(upperLeft, GetDescriptor(), paint_ptr);
	allObjects_ptr->AddObject(road_ptr);
	road_ptr->GraphStatusAttach(allObjects_ptr->GetGraph());
	auto roadEdges = allObjects_ptr->GetRoadEdges(road_ptr);
	road_ptr->GraphStatusNotify(roadEdges);
	return road_ptr;
}
Construction* VisibleOutsideRoadManager::CreatePreliminaryConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const
{
	return nullptr;
}
Construction* UnbreakableRoadManager::CreateConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const
{
	UnbreakableRoad* road_ptr = new UnbreakableRoad(upperLeft, GetDescriptor(), paint_ptr);
	allObjects_ptr->AddObject(road_ptr);
	road_ptr->GraphStatusAttach(allObjects_ptr->GetGraph());
	auto roadEdges = allObjects_ptr->GetRoadEdges(road_ptr);
	road_ptr->GraphStatusNotify(roadEdges);
	return road_ptr;
}
Construction* UnbreakableRoadManager::CreatePreliminaryConstruction(PointCoord upperLeft, const Visualisation* paint_ptr, AllObjects* allObjects_ptr) const
{
	return nullptr;
}