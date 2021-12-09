#include "ManagersDerived.h"
///////////////Building Manager Class: Construction Manager derived///////////////
unsigned int BuildingManager::getDailyExpences() const
{
	return DailyExpences;
}
void BuildingManager::setDailyExpences(unsigned int _dailyexpences)
{
	DailyExpences = _dailyexpences;
}
char BuildingManager::getBuildingSymbol()
{
	return BuildingSymbol;
}
void BuildingManager::setBuildingSymbol(const char _buildingsymbol)
{
	BuildingSymbol = _buildingsymbol;
}
Construction* BuildingManager::CreateConstruction(PointCoord upperleft)
{
	Construction* constr_ptr = new Building(upperleft, this);
	return constr_ptr;
}
ConstructionManager* BuildingManager::CreateManager(Cursor* _c_ptr, unsigned int _constructioncost, string _description, char _iconsymbol, unsigned int _dailyexpences,
	char _buildingsymbol, unsigned int _constructionheightadd, unsigned int _constructionwidthadd)
{
	PointCoord _upperleft(0, 0);
	ConstructionManager* cm_ptr = new BuildingManager(_upperleft, _c_ptr, _constructioncost, _description, _iconsymbol, _dailyexpences, _buildingsymbol, _constructionheightadd, _constructionwidthadd);
	return cm_ptr;
}
///////////////Road Manager Class: Construction Manager derived///////////////
Construction* RoadManager::CreateConstruction(PointCoord upperleft)
{
	Construction* constr_ptr = new Road(upperleft, this);
	return constr_ptr;
}
ConstructionManager* RoadManager::CreateManager(Cursor* _c_ptr, unsigned int _constructioncost, string _description, char _iconsymbol,
	unsigned int _constructionheightadd, unsigned int _constructionwidthadd)
{
	PointCoord _upperleft(0, 0);
	ConstructionManager* cm_ptr = new RoadManager(_upperleft, _c_ptr, _constructioncost, _description, _iconsymbol, _constructionheightadd, _constructionwidthadd);
	return cm_ptr;
}
