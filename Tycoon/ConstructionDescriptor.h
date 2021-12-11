#pragma once
#include "GlobalObject.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
class ConstructionDescriptor : public GlobalObject
{
private:
	unsigned int ConstructionHeightAddition;
	unsigned int ConstructionWidthAddition;
	unsigned int ConstructionCost;
	unsigned int DailyExpences;
	string Description;
	char IconSymbol;
public:
	ConstructionDescriptor(PointCoord _upperleft, unsigned int _constructioncost, string _description, char _iconsymbol,
		unsigned int _dailyexpences = 0, unsigned int _constructionheightadd = 0, unsigned int _constructionwidthadd = 0) : GlobalObject(_upperleft)
	{
		ConstructionHeightAddition = _constructionheightadd;
		ConstructionWidthAddition = _constructionwidthadd;
		ConstructionCost = _constructioncost;
		DailyExpences = _dailyexpences;
		Description = _description;
		IconSymbol = _iconsymbol;
	}
	~ConstructionDescriptor() {}
	unsigned int getConstructionHeightAdd() const;
	void setConstructionHeightAdd(unsigned int _heightadd);
	unsigned int getConstructionWidthAdd() const;
	void setConstructionWidthAdd(unsigned int _widthadd);
	unsigned int getConstructionCost() const;
	void setConstructionCost(const int cost);
	string getDescription() const;
	void setDescription(string _desc);
	char getIconSymbol();
	void setIconSymbol(const char _symb);
	unsigned int getDailyExpences() const;
	void setDailyExpences(unsigned int exp);
	virtual char getBuildingSymbol();
	virtual void setBuildingSymbol(const char _symb);
};
