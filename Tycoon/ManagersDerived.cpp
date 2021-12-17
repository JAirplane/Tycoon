#include "managershiftDirectionerived.h"
///////////////Building Manager Class: Construction Manager derived///////////////
Construction* BuildingManager::CreateConstruction(PointCoord upperLeft)
{
	Construction* constr_ptr = new Building(upperLeft, GetDescriptor());
	return constr_ptr;
}
///////////////Road Manager Class: Construction Manager derived///////////////
Construction* RoadManager::CreateConstruction(PointCoord upperLeft)
{
	Construction* constr_ptr = new Road(upperLeft, GetDescriptor());
	return constr_ptr;
}