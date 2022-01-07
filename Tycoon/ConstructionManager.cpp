#include "ConstructionManager.h"
///////////////ConstructionManager Class: GlobalObject derived///////////////
Construction* ConstructionManager::CreateConstruction(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr)
{
	Construction* empty_ptr = nullptr;
	return empty_ptr;
}
ConstructionDescriptor* ConstructionManager::GetDescriptor()
{
	return describe_ptr;
}
void ConstructionManager::SetUpperLeft(PointCoord point)
{
	GlobalObject::SetUpperLeft(point);
	describe_ptr->SetManagerLocation(point);
}