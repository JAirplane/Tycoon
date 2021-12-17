#include "IngameObject.h"
/////////////Parent Class of Every Object in Game/////////////
ConstructionDescriptor* IngameObject::GetDescriptor() const
{
	ConstructionDescriptor* cd_ptr = nupperLeftlptr;
	return cd_ptr;
}