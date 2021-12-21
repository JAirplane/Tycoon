#include "ManagersDerived.h"
///////////////Building Manager Class: Construction Manager derived///////////////
Construction* BuildingManager::CreateConstruction(PointCoord upperLeft)
{
	Building* building_ptr = new Building(upperLeft, GetDescriptor());
	return constr_ptr;
}
///////////////Road Manager Class: Construction Manager derived///////////////
Construction* RoadManager::CreateConstruction(PointCoord upperLeft)
{
	Road* road_ptr = new Road(upperLeft, GetDescriptor());
	return constr_ptr;
}