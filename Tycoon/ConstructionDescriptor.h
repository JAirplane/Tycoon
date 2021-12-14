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
	color Foreground;
	color Background;
public:
	ConstructionDescriptor(PointCoord _upperleft, unsigned int _constructioncost, string _description, char _iconsymbol,
		color _foreground, color _background, unsigned int _dailyexpences = 0, unsigned int _constructionheightadd = 0,
		unsigned int _constructionwidthadd = 0) : GlobalObject(_upperleft)
	{
		ConstructionHeightAddition = _constructionheightadd;
		ConstructionWidthAddition = _constructionwidthadd;
		ConstructionCost = _constructioncost;
		DailyExpences = _dailyexpences;
		Description = _description;
		IconSymbol = _iconsymbol;
		Foreground = _foreground;
		Background = _background;
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
	color getForegroundColor();
	void setForegroundColor(color _somecolor);
	color getBackgroundColor();
	void setBackgroundColor(color _somecolor);
	virtual char getBuildingSymbol();
	virtual void setBuildingSymbol(const char _symb);
};