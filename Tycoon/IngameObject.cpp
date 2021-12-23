#include "IngameObject.h"
/////////////Parent Class of Every Object in Game/////////////
ConstructionDescriptor* IngameObject::GetDescriptor() const
{
	ConstructionDescriptor* cd_ptr = nullptr;
	return cd_ptr;
}
Visualisation* IngameObject::GetPainter() const
{
	return draw_ptr;
}