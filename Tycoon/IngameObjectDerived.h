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
	bool isChosen;
	int visitorsCount;
public:
	Construction(PointCoord upperLeft, ConstructionDescriptor* description_ptr, Visualisation* paint_ptr) : IngameObject(upperLeft, paint_ptr)
	{
		describe_ptr = description_ptr;
		SetHeightAddition(describe_ptr->GetConstructionHeightAdd());
		SetWidthAddition(describe_ptr->GetConstructionWidthAdd());
		connectedToRoad = false;
		isChosen = false;
		visitorsCount = 0;
	}
	~Construction()
	{}
	ConstructionDescriptor* GetDescriptor() const; //no setter here
	//
	virtual int GetEntranceHeightAdd() const = 0;
	virtual int GetEntranceWidthAdd() const = 0;
	//
	virtual PointCoord GetEntrancePoint() const = 0;
	virtual PointCoord GetRedrawNeiboursPoint() const = 0;
	virtual Direction GetExitDirection() const = 0;
	virtual wstring GetEntranceSymbol(Direction out) const;
	bool GetRoadConnectionStatus() const;
	void SetRoadConnectionStatus(bool connected);
	bool GetChosenStatus() const;
	void SetChosenStatus(bool chosen);
	virtual int GetProfit() const = 0;
	virtual int GetVisitorsCount() const;
	//
	color GetBackgroundColor() const;
	virtual int RotateConstruction() = 0;
	virtual int GetNeibourRoadMask(const list<Road*>& allRoads, const Construction* preliminary_ptr) const = 0;
	virtual int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) = 0;
	virtual void IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) = 0;
	virtual void ConnectedToRoad(const list<Road*>& allRoads, const Construction* preliminary_ptr) = 0;
	void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const override;
	virtual void RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr, const Camera* camera_ptr) = 0;
	static void RedrawNeibours(PointCoord centralPoint, const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr);
	void SetVisitorsCount(int visitorsCount);
};
/////////////Parent Class of buildings/////////////
class Building : public Construction
{
private:
	int entranceHeightAdd;
	int entranceWidthAdd;
	Direction exitDirection;
	int overallProfit;
public:
	Building(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : Construction(upperLeft, manager_ptr, paint_ptr)
	{
		SetHeightAddition(manager_ptr->GetConstructionHeightAdd());
		SetWidthAddition(manager_ptr->GetConstructionWidthAdd());
		this->entranceHeightAdd = manager_ptr->GetConstructionHeightAdd();
		this->entranceWidthAdd = manager_ptr->GetConstructionWidthAdd() / 2;
		overallProfit = 0;
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
	int RotateConstruction() override; // returns -1 if rotation failed
	int GetNeibourRoadMask(const list<Road*>& allRoads, const Construction* preliminary_ptr) const override;
	PointCoord GetRedrawNeiboursPoint() const override;
	PointCoord GetPotentialConnectedRoadPoint() const;
	wstring GetEntranceSymbol(Direction exit) const override;
	void CopyEntrance(Construction* preliminary_ptr);
	int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void ConnectedToRoad(const list<Road*>& allRoads, const Construction* preliminary_ptr) override;
	int GetProfit() const;
	void SetProfit(int profit);
	void RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr, const Camera* camera_ptr) override;
	void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const override;
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
	int RotateConstruction() override;
	bool GetGraphStatus() const;
	void SetGraphStatus(bool status);
	int GetProfit() const;
	bool RoadIsAnEntrance(const list<Building*>& allBuildings);
	PointCoord GetEntrancePoint() const override;
	PointCoord GetRedrawNeiboursPoint() const override;
	int GetNeibourRoadMask(const list<Road*>& allRoads, const Construction* preliminary_ptr) const override;
	int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void ConnectedToRoad(const list<Road*>& allRoads, const Construction* preliminary_ptr) override;
	void DefineGraphStatus(int mask); // use NeibourRoadMask here!
	void RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr, const Camera* camera_ptr) override;
	void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const override;
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
	void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const override;
	//GlobalObject* CreateObject(PointCoord _point) override;
};
/////////////End of Constructions Classes/////////////