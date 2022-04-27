#include "ConstructionManager.h"
///////////////ConstructionManager Class: GlobalObject derived///////////////
ConstructionDescriptor* ConstructionManager::GetDescriptor() const
{
	return describe_ptr;
}