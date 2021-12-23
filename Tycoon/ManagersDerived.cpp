#include "ManagersDerived.h"
///////////////Building Manager Class: Construction Manager derived///////////////
Construction* BuildingManager::CreateConstruction(PointCoord upperLeft, Visualisation* paint_ptr)
{
	Building* building_ptr = new Building(upperLeft, GetDescriptor(), paint_ptr);
	return building_ptr;
}
///////////////Road Manager Class: Construction Manager derived///////////////
Construction* RoadManager::CreateConstruction(PointCoord upperLeft, Visualisation* paint_ptr)
{
	Road* road_ptr = new Road(upperLeft, GetDescriptor(), paint_ptr);
	return road_ptr;
}