#inclide "RoadDescriptor.h"
wstring RoadDescriptor::GetConstructionSymbol(Road * r_ptr)
{
	wstring roadSymbol = roads_ptr->DrawRoad(r_ptr);
	roads_ptr->RedrawNeibourRoads(r_ptr);
	return roadSymbol;
}