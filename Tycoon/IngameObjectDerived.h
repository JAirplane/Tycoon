#pragma once
#include "GlobalObject+IngameObject.h"
class Construction;
/////////////Construction Manager has all the information about Construction/////////////
class ConstructionManager : public GlobalObject
{
private:
	Cursor* C_ptr;
	unsigned int ConstructionHeightAddition;
	unsigned int ConstructionWidthAddition;
	unsigned int ConstructionCost;
	string Description;
	char IconSymbol;
public:
	ConstructionManager(PointCoord _upperleft, Cursor* _c_ptr, unsigned int _constructioncost, string _description, char _iconsymbol,
		unsigned int _constructionheightadd = 0, unsigned int _constructionwidthadd = 0) : GlobalObject(_upperleft)
	{
		C_ptr = _c_ptr;
		ConstructionHeightAddition = _constructionheightadd;
		ConstructionWidthAddition = _constructionwidthadd;
		ConstructionCost = _constructioncost;
		Description = _description;
		IconSymbol = _iconsymbol;
	}
	~ConstructionManager() {}
	virtual ConstructionManager* CreateManager(Cursor* _c_ptr, unsigned int _constructioncost, string _description, char _iconsymbol,
		unsigned int _constructionheightadd = 0, unsigned int _constructionwidthadd = 0);
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
	virtual Construction* CreateConstruction(PointCoord upperleft);
	virtual char getBuildingSymbol();
	virtual void setBuildingSymbol(const char _symb);
	virtual unsigned int getDailyExpences() const;
	virtual void setDailyExpences(unsigned int exp);
};
/////////////Parent Class of Every Construction Type/////////////
class Construction : public IngameObject
{
private:
	ConstructionManager* Manager_ptr;
public:
	Construction(PointCoord _ul, ConstructionManager* _manager_ptr) : IngameObject(_ul)
	{
		Manager_ptr = _manager_ptr;
		setHeightAddition(Manager_ptr->getConstructionHeightAdd());
		setWidthAddition(Manager_ptr->getConstructionWidthAdd());
	}
	~Construction()
	{}
	ConstructionManager* getManager() const override; //no setter here
	virtual char SetRoadSymbol(int mask) const;
	virtual void DefineGraphStatus(int mask);
	virtual PointCoord getEntrance() const;
	virtual Direction getExitDirection() const;
	virtual void setGraphStatus(bool status);
	virtual void setRoadConnectionStatus(bool connected);
};
/////////////Parent Class of Buildings/////////////
class Building : public Construction
{
private:
	PointCoord Entrance;
	Direction ExitDir;
	bool ConnectedToRoad;
	unsigned int LastDayVisitors;
	int LastDayProfit;
public:
	Building(PointCoord _ul, ConstructionManager* _manager_ptr) : Construction(_ul, _manager_ptr)
	{
		setHeightAddition(getManager()->getConstructionHeightAdd());
		setWidthAddition(getManager()->getConstructionWidthAdd());
		ConnectedToRoad = 0;
		LastDayVisitors = 0;
		LastDayProfit = 0;
		Entrance = PointCoord((getUpperLeft().get_x() * 2 + getWidthAddition()) / 2, getUpperLeft().get_y() + getHeightAddition());
		ExitDir = Direction::Down;
	}
	~Building() {}
	PointCoord getEntrance() const;
	void setEntrance(PointCoord _entrance);
	Direction getExitDirection() const;
	void setExitDirection(Direction _dir);
	bool getRoadConnectionStatus() const;
	void setRoadConnectionStatus(bool connected);
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
		setHeightAddition(getManager()->getConstructionHeightAdd());
		setWidthAddition(getManager()->getConstructionWidthAdd());
		GraphStatus = false;
		RoadIsInChain = false;
	}
	~Road()
	{}
	char SetRoadSymbol(int mask) const override;
	bool getGraphStatus() const;
	void setGraphStatus(bool status);
	void DefineGraphStatus(int mask);
	bool getRoadIsInChainStatus();
	void setRoadIsInChainStatus(bool chainflag);
};
/////////////People are looking for some fun!/////////////
class Visitor : public IngameObject
{
private:
	int FoodCapacity;
	int NeedToPee;
public:
	Visitor(PointCoord _ul, int fc, int ntp) : IngameObject(_ul)
	{
		FoodCapacity = fc;
		NeedToPee = ntp;
	}
	~Visitor()
	{}
	void VisitorMove(int _x, int _y);
	//GlobalObject* CreateObject(PointCoord _pc) override;
};
/////////////End of Constructions Classes/////////////
