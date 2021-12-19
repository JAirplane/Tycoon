#pragma once
#include "IngameObject.h"
/////////////Parent Class of Every Construction Type/////////////
class Construction : public IngameObject
{
private:
	ConstructionDescriptor* describe_ptr;
public:
	Construction(PointCoord upperLeft, ConstructionDescriptor* describe_ptr) : IngameObject(upperLeft)
	{
		this->describe_ptr = describe_ptr;
		SetHeightAddition(describe_ptr->GetConstructionHeightAdd());
		SetWidthAddition(describe_ptr->GetConstructionWidthAdd());
	}
	~Construction()
	{}
	ConstructionDescriptor* GetDescriptor() const override; //no setter here
};
/////////////Parent Class of buildings/////////////
class Building : public Construction
{
private:
	PointCoord entrance;
	Direction exitDirection;
	bool connectedToRoad;
	unsigned int lastDayvisitors;
	int lastDayProfit;
public:
	Building(PointCoord upperLeft, ConstructionDescriptor* manager_ptr) : Construction(upperLeft, manager_ptr)
	{
		SetHeightAddition(GetDescriptor()->GetConstructionHeightAdd());
		SetWidthAddition(GetDescriptor()->GetConstructionWidthAdd());
		connectedToRoad = 0;
		lastDayvisitors = 0;
		lastDayProfit = 0;
		entrance = PointCoord((GetUpperLeft().Get_x() * 2 + GetWidthAddition()) / 2, GetUpperLeft().Get_y() + GetHeightAddition());
		exitDirection = Direction::Down;
	}
	~Building() {}
	PointCoord GetEntrance() const;
	void SetEntrance(PointCoord entrance);
	Direction GetExitDirection() const;
	void SetExitDirection(Direction exitDirection);
	bool GetRoadConnectionStatus() const;
	void SetRoadConnectionStatus(bool connected);
	unsigned int GetvisitorsCount() const;
	void SetvisitorsCount(unsigned int visitorsCount);
	int GetProfit() const;
	void SetProfit(int profit);
};
/////////////One Pixel of Road/////////////
class Road : public Construction
{
private:
	bool graphStatus;
	bool roadIsInChain;
public:
	Road(PointCoord upperLeft, ConstructionDescriptor* manager_ptr) : Construction(upperLeft, manager_ptr)
	{
		SetHeightAddition(GetDescriptor()->GetConstructionHeightAdd());
		SetWidthAddition(GetDescriptor()->GetConstructionWidthAdd());
		graphStatus = false;
		roadIsInChain = false;
	}
	~Road()
	{}
	char SetRoadSymbol(int mask) const;
	bool GetGraphStatus() const;
	void SetGraphStatus(bool status);
	void DefineGraphStatus(int mask);
	bool GetroadIsInChainStatus();
	void SetRoadIsInChainStatus(bool chainFlag);
};
/////////////People are looking for some fun!/////////////
class Visitor : public IngameObject
{
private:
	int foodCapacity;
	int needToPee;
public:
	Visitor(PointCoord upperLeft, int foodCapacity, int needToPee) : IngameObject(upperLeft)
	{
		this->foodCapacity = foodCapacity;
		this->needToPee = needToPee;
	}
	~Visitor()
	{}
	void VisitorMove(int _x, int _y);
	//GlobalObject* CreateObject(PointCoord _point) override;
};
/////////////End of Constructions Classes/////////////