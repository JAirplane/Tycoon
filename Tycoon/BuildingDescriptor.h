#pragma once
#include "ConstructionDescriptor.h"
class BuildingDescriptor : public ConstructionDescriptor
{
private:
	char BuildingSymbol;
public:
	BuildingDescriptor(PointCoord _upperleft, unsigned int _constructioncost, string _description, char _iconsymbol, char _buildingsymbol,
		unsigned int _dailyexpences = 0, unsigned int _constructionheightadd = 0, unsigned int _constructionwidthadd = 0) :
		ConstructionDescriptor(_upperleft, _constructioncost, _description, _iconsymbol, _dailyexpences, _constructionheightadd, _constructionwidthadd)
	{
		BuildingSymbol = _buildingsymbol;
	}
	~BuildingDescriptor() {}
	char getBuildingSymbol() override;
	void setBuildingSymbol(const char _symb);
};