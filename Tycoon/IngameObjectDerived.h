#pragma once
#include "IngameObject.h"
/////////////Parent Class of Every Construction Type/////////////
class Construction : public IngameObject
{
private:
	ConstructionDescriptor* describe_ptr;
public:
	Construction(PointCoord upperLeft, ConstructionDescriptor* description_ptr, Visualisation* paint_ptr) : IngameObject(upperLeft, paint_ptr)
	{
		describe_ptr = description_ptr;
		SetHeightAddition(describe_ptr->GetConstructionHeightAdd());
		SetWidthAddition(describe_ptr->GetConstructionWidthAdd());
	}
	~Construction()
	{}
	ConstructionDescriptor* GetDescriptor() const override; //no setter here
	virtual int GetEntranceHeightAdd() const;
	virtual int GetEntranceWidthAdd() const;
	virtual Direction GetExitDirection() const;
	virtual wstring GetEntranceSymbol(Direction out) const;
	void DrawObject(int mask = 0) const override;
};
/////////////Parent Class of buildings/////////////
class Building : public Construction
{
private:
	int entranceHeightAdd;
	int entranceWidthAdd;
	Direction exitDirection;
	bool connectedToRoad;
	int lastDayVisitors;
	int lastDayProfit;
public:
	Building(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : Construction(upperLeft, manager_ptr, paint_ptr)
	{
		SetHeightAddition(manager_ptr->GetConstructionHeightAdd());
		SetWidthAddition(manager_ptr->GetConstructionWidthAdd());
		this->entranceHeightAdd = manager_ptr->GetConstructionHeightAdd();
		this->entranceWidthAdd = manager_ptr->GetConstructionWidthAdd() / 2;
		connectedToRoad = false;
		lastDayVisitors = 0;
		lastDayProfit = 0;
		exitDirection = Direction::Down;
	}
	~Building() {}
	int GetEntranceHeightAdd() const;
	void SetEntranceHeightAdd(int heightAdd);
	int GetEntranceWidthAdd() const;
	void SetEntranceWidthAdd(int widthAdd);
	Direction GetExitDirection() const;
	void SetExitDirection(Direction exit);
	wstring GetEntranceSymbol(Direction exit) const;
	void CopyEntrance(Construction* preliminary_ptr);
	bool GetRoadConnectionStatus() const;
	void SetRoadConnectionStatus(bool connected);
	int GetVisitorsCount() const;
	void SetVisitorsCount(int visitorsCount);
	int GetProfit() const;
	void SetProfit(int profit);
	color GetBackgroundColor() const;
	void DrawObject(int mask = 0) const override;
	void DrawPartly(int leftX, int rightX, int topY, int bottomY) const;
};
/////////////One Pixel of Road/////////////
class Road : public Construction
{
private:
	bool graphStatus;
	bool roadIsInChain;
public:
	Road(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : Construction(upperLeft, manager_ptr, paint_ptr)
	{
		SetHeightAddition(GetDescriptor()->GetConstructionHeightAdd());
		SetWidthAddition(GetDescriptor()->GetConstructionWidthAdd());
		graphStatus = false;
		roadIsInChain = false;
	}
	~Road() {}
	bool GetGraphStatus() const;
	void SetGraphStatus(bool status);
	void DefineGraphStatus(int mask);
	bool GetRoadIsInChainStatus();
	void SetRoadIsInChainStatus(bool chainFlag);
	void DrawObject(int mask = 0) const override;
};
/////////////People are looking for some fun!/////////////
class Visitor : public IngameObject
{
private:
	int foodCapacity;
	int needToPee;
public:
	Visitor(PointCoord upperLeft, int foodCapacity, int needToPee, Visualisation* paint_ptr) : IngameObject(upperLeft, paint_ptr)
	{
		this->foodCapacity = foodCapacity;
		this->needToPee = needToPee;
	}
	~Visitor()
	{}
	void VisitorMove(int _x, int _y);
	void DrawObject(int mask = 0) const override;
	//GlobalObject* CreateObject(PointCoord _point) override;
};
/////////////End of Constructions Classes/////////////