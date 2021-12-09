#pragma once
#include "IngameObjectDerived.h"
/////////////Building Manager has additional fields that are necessary for buildings/////////////
class BuildingManager : public ConstructionManager
{
private:
	unsigned int DailyExpences;
	char BuildingSymbol;
public:
	BuildingManager(PointCoord _upperleft, Cursor* _c_ptr, unsigned int _constructioncost, string _description, char _iconsymbol, unsigned int _dailyexpences,
		char _buildingsymbol, unsigned int _constructionheightadd = 0, unsigned int _constructionwidthadd = 0) :
		ConstructionManager(_upperleft, _c_ptr, _constructioncost, _description, _iconsymbol, _constructionheightadd, _constructionwidthadd)
	{
		DailyExpences = _dailyexpences;
		BuildingSymbol = _buildingsymbol;
	}
	ConstructionManager* CreateManager(Cursor* _c_ptr, unsigned int _constructioncost, string _description, char _iconsymbol, unsigned int _dailyexpences,
		char _buildingsymbol, unsigned int _constructionheightadd = 0, unsigned int _constructionwidthadd = 0);
	char getBuildingSymbol() override;
	void setBuildingSymbol(const char _symb);
	unsigned int getDailyExpences() const;
	void setDailyExpences(unsigned int exp);
	Construction* CreateConstruction(PointCoord upperleft) override;
};
///////////////Road Manager Class: Construction Manager derived///////////////
class RoadManager : public ConstructionManager
{
public:
	RoadManager(PointCoord _upperleft, Cursor* _c_ptr, unsigned int _constructioncost, string _description, char _iconsymbol,
		unsigned int _constructionheightadd = 0, unsigned int _constructionwidthadd = 0) :
		ConstructionManager(_upperleft, _c_ptr, _constructioncost, _description, _iconsymbol, _constructionheightadd, _constructionwidthadd)
	{}
	Construction* CreateConstruction(PointCoord upperleft) override;
	ConstructionManager* CreateManager(Cursor* _c_ptr, unsigned int _constructioncost, string _description, char _iconsymbol,
		unsigned int _constructionheightadd = 0, unsigned int _constructionwidthadd = 0);
};
