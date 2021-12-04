#pragma once
#include "CursorClass.h"
#include "drawheader.h"
/////////////Parent Class of All Objects/////////////
class GlobalObject
{
private:
	PointCoord UpperLeft;
	unsigned int HeightAddition;
	unsigned int WidthAddition;
public:
	GlobalObject(PointCoord ul, unsigned int _heightadd = 0, unsigned int _widthadd = 0) : UpperLeft(ul), HeightAddition(_heightadd), WidthAddition(_widthadd)
	{}
	~GlobalObject()
	{}
	PointCoord getUpperLeft() const;
	void setUpperLeft(PointCoord _pc);
	unsigned int getHeightAddition() const;
	void setHeightAddition(const int _ha);
	unsigned int getWidthAddition() const;
	void setWidthAddition(const int _wa);

	//virtual void DefineGraphStatus(int mask);
	//virtual string getDescription() const;
	//virtual char SetRoadSymbol(int mask) const;
	//virtual GlobalObject* CreateObject(PointCoord _pc) = 0;
};
/////////////Child Classes/////////////
/////////////Parent Class of Every Construction Type/////////////
class ConstructionManager;
class Construction : public GlobalObject
{
private:
	ConstructionManager* Manager_ptr;
public:
	Construction(PointCoord _ul, ConstructionManager* _manager_ptr, unsigned int _heightadd = 0, unsigned int _widthadd = 0) : GlobalObject(_ul, _heightadd, _widthadd)
	{
		Manager_ptr = _manager_ptr;
	}
	~Construction()
	{}
	ConstructionManager* getManager() const; //no setter here
};
/////////////ConstructionManager has all information about Construction/////////////
class ConstructionManager : public GlobalObject
{
private:
	Cursor* C_ptr;
	unsigned int ConstructionHeightAddition;
	unsigned int ConstructionWidthAddition;
	unsigned int ConstructionCost;
	unsigned int DailyExpences;
	char ConstructionSymbol;
	string Description;
	char IconSymbol;
public:
	ConstructionManager(PointCoord _upperleft, Cursor* _c_ptr, unsigned int _constructioncost, unsigned int _dailyexpences, 
						string _description, char _iconsymbol, unsigned int _constructionheightadd = 0 , unsigned int _constructionwidthadd = 0, char _constructionsymbol = '*') : GlobalObject(_upperleft)
	{
		C_ptr = _c_ptr;
		ConstructionHeightAddition = _constructionheightadd;
		ConstructionWidthAddition = _constructionwidthadd;
		ConstructionCost = _constructioncost;
		DailyExpences = _dailyexpences;
		ConstructionSymbol = _constructionsymbol;
		Description = _description;
		IconSymbol = _iconsymbol;
	}
	~ConstructionManager() {}
	unsigned int getConstructionCost() const;
	void setConstructionCost(const int cost);
	unsigned int getDailyExpences() const;
	void setDailyExpences(unsigned int exp);
	string getDescription() const;
	void setDescription(string _desc);
	char getConstructionSymbol();
	void setConstructionSymbol(const char _symb);
	char getIconSymbol();
	void setIconSymbol(const char _symb);
	Construction* CreateConstruction();
};
/////////////Parent Class of Buildings/////////////
class Building : public Construction
{
private:
	PointCoord Entrance;
	unsigned int LastDayVisitors;
	int LastDayProfit;
public:
	Building(PointCoord _ul, PointCoord _entrance, ConstructionManager* _manager_ptr, unsigned int _heightadd = 0, unsigned int _widthadd = 0) : Construction(_ul, _manager_ptr, _heightadd, _widthadd)
	{
		Entrance = _entrance;
		LastDayVisitors = 0;
		LastDayProfit = 0;
	}
	~Building() {}
	PointCoord getEntrance() const;
	void setEntrance(PointCoord _entrance);
	unsigned int getVisitorsCount() const;
	void setVisitorsCount(unsigned int _visitorscount);
	int getProfit() const;
	void setProfit(int _profit);

};
/////////////One Pixel of Road/////////////
class Road : public Construction
{
private:
	bool GraphStatus;
	bool RoadIsInChain;
public:
	Road(PointCoord _ul, ConstructionManager* _manager_ptr) : Construction(_ul, _manager_ptr)
	{
		GraphStatus = false;
		RoadIsInChain = false;
	}
	~Road()
	{}
	//GlobalObject* CreateObject(PointCoord _pc) override;
	char SetRoadSymbol(int mask) const;
	bool getGraphStatus() const;
	void setGraphStatus(bool status);
	void DefineGraphStatus(int mask);
	bool getRoadIsInChainStatus();
	void setRoadIsInChainStatus(bool chainflag);
};
/////////////Ice Cream Shop/////////////
class IceCreamShop : public Building
{
private:
	
public:
	IceCreamShop(PointCoord _ul) : Building(_ul)
	{
		setHeight(IceCreamShopHeight);
		setWidth(IceCreamShopWidth);
		setConstructionCost(IceCreamShopCost);
		setDailyExpences(IceCreamShopExpences);
		LastDayVisitors = 0;
		LastDayProfit = 0;
	}
	GlobalObject* CreateObject(PointCoord _pc);
};
/////////////People are looking for some fun!/////////////
class Visitor : public GlobalObject
{
private:
	int FoodCapacity;
	int NeedToPee;
public:
	Visitor(PointCoord _ul, int fc, int ntp) : GlobalObject(_ul)
	{
		setHeight(VisitorHeight);
		setWidth(VisitorWidth);
		FoodCapacity = fc;
		NeedToPee = ntp;
	}
	~Visitor()
	{}
	void VisitorMove(int _x, int _y);
	//GlobalObject* CreateObject(PointCoord _pc) override;
};
/////////////End of Constructions Classes/////////////