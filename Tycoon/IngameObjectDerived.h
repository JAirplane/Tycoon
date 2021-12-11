#pragma once
#include "IngameObject.h"
/////////////Parent Class of Every Construction Type/////////////
class Construction : public IngameObject
{
private:
	ConstructionDescriptor* Describe_ptr;
public:
	Construction(PointCoord _ul, ConstructionDescriptor* _describe_ptr) : IngameObject(_ul)
	{
		Describe_ptr = _describe_ptr;
		setHeightAddition(Describe_ptr->getConstructionHeightAdd());
		setWidthAddition(Describe_ptr->getConstructionWidthAdd());
	}
	~Construction()
	{}
	ConstructionDescriptor* getDescriptor() const override; //no setter here
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
	Building(PointCoord _ul, ConstructionDescriptor* _manager_ptr) : Construction(_ul, _manager_ptr)
	{
		setHeightAddition(getDescriptor()->getConstructionHeightAdd());
		setWidthAddition(getDescriptor()->getConstructionWidthAdd());
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
	Road(PointCoord _ul, ConstructionDescriptor* _manager_ptr) : Construction(_ul, _manager_ptr)
	{
		setHeightAddition(getDescriptor()->getConstructionHeightAdd());
		setWidthAddition(getDescriptor()->getConstructionWidthAdd());
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
