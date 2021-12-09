#include "IngameObjectDerived.h"
///////////////ConstructionManager Class: GlobalObject derived///////////////
unsigned int ConstructionManager::getConstructionHeightAdd() const
{
	return ConstructionHeightAddition;
}
void ConstructionManager::setConstructionHeightAdd(unsigned int _heightadd)
{
	ConstructionHeightAddition = _heightadd;
}
unsigned int ConstructionManager::getConstructionWidthAdd() const
{
	return ConstructionWidthAddition;
}
void ConstructionManager::setConstructionWidthAdd(unsigned int _widthadd)
{
	ConstructionWidthAddition = _widthadd;
}
unsigned int ConstructionManager::getConstructionCost() const
{
	return ConstructionCost;
}
void ConstructionManager::setConstructionCost(const int _constructioncost)
{
	ConstructionCost = _constructioncost;
}
string ConstructionManager::getDescription() const
{
	return Description;
}
void ConstructionManager::setDescription(string _desc)
{
	Description = _desc;
}
char ConstructionManager::getIconSymbol()
{
	return IconSymbol;
}
void ConstructionManager::setIconSymbol(const char symbol)
{
	IconSymbol = symbol;
}
Construction* ConstructionManager::CreateConstruction(PointCoord upperleft)
{
	Construction* constr_ptr = new Construction(upperleft, this);
	return constr_ptr;
}
ConstructionManager* ConstructionManager::CreateManager(Cursor* _c_ptr, unsigned int _constructioncost, string _description, char _iconsymbol,
	unsigned int _constructionheightadd, unsigned int _constructionwidthadd)
{
	PointCoord _upperleft(0, 0);
	ConstructionManager* cm_ptr = new ConstructionManager(_upperleft, _c_ptr, _constructioncost, _description, _iconsymbol, _constructionheightadd, _constructionwidthadd);
	return cm_ptr;
}
char ConstructionManager::getBuildingSymbol()
{
	return '0';
}
void ConstructionManager::setBuildingSymbol(const char _symb)
{}
unsigned int ConstructionManager::getDailyExpences() const
{
	return 0;
}
void ConstructionManager::setDailyExpences(unsigned int exp)
{}