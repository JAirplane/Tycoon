#include "BuildingDescriptor.h"
char BuildingDescriptor::GetBuildingSymbol()
{
	return buildingsymbol;
}
void BuildingDescriptor::setbuildingsymbol(const char _symb)
{
	buildingsymbol = _symb;
}