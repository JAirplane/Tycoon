#include "ConstructionManager.h"
///////////////ConstructionManager Class: GlobalObject derived///////////////
ConstructionDescriptor* ConstructionManager::GetDescriptor()
{
	return describe_ptr;
}
void ConstructionManager::SetUpperLeft(PointCoord point)
{
	GlobalObject::SetUpperLeft(point);
	describe_ptr->SetManagerLocation(point);
}