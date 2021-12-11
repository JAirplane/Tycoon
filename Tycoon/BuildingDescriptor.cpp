#include "BuildingDescriptor.h"
char BuildingDescriptor::getBuildingSymbol()
{
	return BuildingSymbol;
}
void BuildingDescriptor::setBuildingSymbol(const char _symb)
{
	BuildingSymbol = _symb;
}