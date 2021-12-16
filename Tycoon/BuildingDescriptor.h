#pragma once
#include "ConstructionDescriptor.h"
class BuildingDescriptor : public ConstructionDescriptor
{
private:
	char buildingsymbol;
public:
	BuildingDescriptor(PointCoord _upperLeft, unsigned int _constructioncost, string _description, char _iconsymbol, color _foreground, color _background, char _buildingsymbol,
		unsigned int _dailyexpences = 0, unsigned int _constructionheightadd = 0, unsigned int _constructionwidthadd = 0) :
		ConstructionDescriptor(_upperLeft, _constructioncost, _description, _iconsymbol, _foreground, _background, _dailyexpences, _constructionheightadd, _constructionwidthadd)
	{
		buildingsymbol = _buildingsymbol;
	}
	~BuildingDescriptor() {}
	char GetBuildingSymbol() override;
	void setbuildingsymbol(const char _symb);
};