#pragma once
#include "IngameObject.h"
#include <list>
/////////////Parent Class of Every Construction Type/////////////
class Road;
class Building;
class Construction : public IngameObject
{
private:
	ConstructionDescriptor* describe_ptr;
	bool connectedToRoad;
public:
	Construction(PointCoord upperLeft, ConstructionDescriptor* description_ptr, Visualisation* paint_ptr) : IngameObject(upperLeft, paint_ptr)
	{
		describe_ptr = description_ptr;
		SetHeightAddition(describe_ptr->GetConstructionHeightAdd());
		SetWidthAddition(describe_ptr->GetConstructionWidthAdd());
		connectedToRoad = false;
	}
	~Construction()
	{}
	ConstructionDescriptor* GetDescriptor() const override; //no setter here
	virtual int GetEntranceHeightAdd() const = 0;
	virtual int GetEntranceWidthAdd() const = 0;
	virtual PointCoord GetEntrancePoint() const = 0;
	virtual PointCoord GetRedrawNeiboursPoint() const = 0;
	virtual Direction GetExitDirection() const = 0;
	virtual void RotateConstruction() = 0;
	virtual wstring GetEntranceSymbol(Direction out) const;
	bool GetRoadConnectionStatus() const;
	void SetRoadConnectionStatus(bool connected);
	virtual int GetNeibourRoadMask(const list<Road*>& allRoads, const Construction* preliminary_ptr) const = 0;
	virtual int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) = 0;
	virtual void IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) = 0;
	virtual void ConnectedToRoad(const list<Road*>& allRoads, const Construction* preliminary_ptr) = 0;
	void DrawObject(int mask = 0) const override;
	virtual void RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) = 0;
	static void RedrawNeibours(PointCoord centralPoint, const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr);
};
/////////////Parent Class of buildings/////////////
class Building : public Construction
{
private:
	int entranceHeightAdd;
	int entranceWidthAdd;
	Direction exitDirection;
	int lastDayVisitors;
	int lastDayProfit;
public:
	Building(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : Construction(upperLeft, manager_ptr, paint_ptr)
	{
		SetHeightAddition(manager_ptr->GetConstructionHeightAdd());
		SetWidthAddition(manager_ptr->GetConstructionWidthAdd());
		this->entranceHeightAdd = manager_ptr->GetConstructionHeightAdd();
		this->entranceWidthAdd = manager_ptr->GetConstructionWidthAdd() / 2;
		lastDayVisitors = 0;
		lastDayProfit = 0;
		exitDirection = Direction::Down;
	}
	~Building() {}
	int GetEntranceHeightAdd() const override;
	void SetEntranceHeightAdd(int heightAdd);
	int GetEntranceWidthAdd() const override;
	void SetEntranceWidthAdd(int widthAdd);
	Direction GetExitDirection() const override;
	void SetExitDirection(Direction exit);
	PointCoord GetEntrancePoint() const override;
	void RotateConstruction() override;
	int GetNeibourRoadMask(const list<Road*>& allRoads, const Construction* preliminary_ptr) const override;
	PointCoord GetRedrawNeiboursPoint() const override;
	PointCoord GetPotentialConnectedRoadPoint() const;
	wstring GetEntranceSymbol(Direction exit) const override;
	void CopyEntrance(Construction* preliminary_ptr);
	int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void ConnectedToRoad(const list<Road*>& allRoads, const Construction* preliminary_ptr) override;
	int GetVisitorsCount() const;
	void SetVisitorsCount(int visitorsCount);
	int GetProfit() const;
	void SetProfit(int profit);
	color GetBackgroundColor() const;
	void RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void DrawObject(int mask = 0) const override;
	void DrawPartly(int leftX, int rightX, int topY, int bottomY) const;
};
/////////////One Pixel of Road/////////////
class Road : public Construction
{
private:
	bool graphStatus;
public:
	Road(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : Construction(upperLeft, manager_ptr, paint_ptr)
	{
		SetHeightAddition(GetDescriptor()->GetConstructionHeightAdd());
		SetWidthAddition(GetDescriptor()->GetConstructionWidthAdd());
		graphStatus = false;
	}
	~Road() {}
	int GetEntranceHeightAdd() const override;
	int GetEntranceWidthAdd() const override;
	Direction GetExitDirection() const override;
	void RotateConstruction() override;
	bool GetGraphStatus() const;
	void SetGraphStatus(bool status);
	bool RoadIsAnEntrance(const list<Building*>& allBuildings);
	PointCoord GetEntrancePoint() const override;
	PointCoord GetRedrawNeiboursPoint() const override;
	int GetNeibourRoadMask(const list<Road*>& allRoads, const Construction* preliminary_ptr) const override;
	int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void ConnectedToRoad(const list<Road*>& allRoads, const Construction* preliminary_ptr) override;
	void DefineGraphStatus(int mask); // use NeibourRoadMask here!
	void RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
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