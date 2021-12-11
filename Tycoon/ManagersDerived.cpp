#include "ManagersDerived.h"
///////////////Building Manager Class: Construction Manager derived///////////////
Construction* BuildingManager::CreateConstruction(PointCoord upperleft)
{
	Construction* constr_ptr = new Building(upperleft, getDescriptor());
	return constr_ptr;
}
///////////////Road Manager Class: Construction Manager derived///////////////
Construction* RoadManager::CreateConstruction(PointCoord upperleft)
{
	Construction* constr_ptr = new Road(upperleft, getDescriptor());
	return constr_ptr;
}
