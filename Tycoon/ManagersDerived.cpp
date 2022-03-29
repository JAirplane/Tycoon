#include "ManagersDerived.h"
///////////////Building Manager Class: Construction Manager derived///////////////
Construction* BuildingManager::CreateConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr)
{
	Building* building_ptr = new Building(upperLeft, GetDescriptor(), paint_ptr);
	allObjects_ptr->AddObject(building_ptr);
	building_ptr->CopyEntrance(allObjects_ptr->GetPreliminaryElement());
	return building_ptr;
}
Construction* BuildingManager::CreatePreliminaryConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr)
{
	Building* building_ptr = new Building(upperLeft, GetDescriptor(), paint_ptr);
	allObjects_ptr->AddPreliminaryElement(building_ptr);
	return building_ptr;
}
///////////////Road Manager Class: Construction Manager derived///////////////
Construction* RoadManager::CreateConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr)
{
	Road* road_ptr = new Road(upperLeft, GetDescriptor(), paint_ptr);
	road_ptr->GraphStatusAttach(allObjects_ptr->GetGraph());
	allObjects_ptr->AddObject(road_ptr);
	road_ptr->GraphStatusNotify(true);
	return road_ptr;
}
Construction* RoadManager::CreatePreliminaryConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr)
{
	Road* road_ptr = new Road(upperLeft, GetDescriptor(), paint_ptr);
	allObjects_ptr->AddPreliminaryElement(road_ptr);
	return road_ptr;
}