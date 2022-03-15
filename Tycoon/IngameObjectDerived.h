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
		SetHeightAddition(describe_ptr->GetHeightAdd());
		SetWidthAddition(describe_ptr->GetWidthAdd());
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
	virtual PointCoord GetPotentialConnectedRoadPoint() const;
	virtual wstring GetEntranceSymbol() const;
	bool GetRoadConnectionStatus() const;
	virtual void SetRoadConnectionStatus(bool connected);
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
	virtual void Connected(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) = 0;
	virtual void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const = 0;
	virtual void DrawObject(const wstring drawingSymbol) const;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const = 0;
	virtual void RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr, const Camera* camera_ptr) = 0;
	static void RedrawNeibours(PointCoord centralPoint, const list<Road*>& allRoads, const list<Building*>& allBuildings,
		const Construction* preliminary_ptr, const Camera* camera_ptr);
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
		SetHeightAddition(manager_ptr->GetHeightAdd());
		SetWidthAddition(manager_ptr->GetWidthAdd());
		this->entranceHeightAdd = manager_ptr->GetHeightAdd();
		this->entranceWidthAdd = manager_ptr->GetWidthAdd() / 2;
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
	wstring GetEntranceSymbol() const override;
	void CopyEntrance(Construction* preliminary_ptr);
	int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void Connected(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	int GetProfit() const;
	void SetProfit(int profit);
	void RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr, const Camera* camera_ptr) override;
	void CorrectBuildingCoordsForDraw(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int& leftX, int& topY, int& rightX, int& bottomY) const;
	void DrawObject(int mask = 0, int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
};
/////////////One Pixel of Road/////////////
class Road : public Construction
{
private:
	bool graphStatus;
public:
	Road(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : Construction(upperLeft, manager_ptr, paint_ptr)
	{
		SetHeightAddition(GetDescriptor()->GetHeightAdd());
		SetWidthAddition(GetDescriptor()->GetWidthAdd());
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
	int GetMaskPartPreliminaryRoad(const Construction* preliminary_ptr) const;
	virtual int GetMaskPartRealRoads(const list<Road*>& allRoads) const;
	int GetNeibourRoadMask(const list<Road*>& allRoads, const Construction* preliminary_ptr) const override;
	int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void IsGraph(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void Connected(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	void DefineGraphStatus(int mask); // use NeibourRoadMask here!
	void RedrawNeibours(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr, const Camera* camera_ptr) override;
	void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const override;
	void DrawObject(const wstring drawingSymbol) const override;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
	virtual bool IsBreakable() const;
};
class UnbreakableRoad : public Road
{
public:
	UnbreakableRoad(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : Road(upperLeft, manager_ptr, paint_ptr)
	{}
	~UnbreakableRoad() {}
	bool IsBreakable() const override;
	void SetRoadConnectionStatus(bool connected) override;
	int GetMaskPartRealRoads(const list<Road*>& allRoads) const override;
};
/////////////People are looking for some fun!/////////////
class Visitor : public IngameObject
{
private:
	VisitorDescriptor* description_ptr;
	int foodCapacity;
	int needToPee;
	MovementStatus CurrentPurpose;
public:
	Visitor(PointCoord upperLeft, Visualisation* paint_ptr, VisitorDescriptor* describe_ptr) : IngameObject(upperLeft, paint_ptr)
	{
		description_ptr = describe_ptr;
		foodCapacity = 100;
		needToPee = 100;
		CurrentPurpose = MovementStatus::MovingIn;
	}
	~Visitor()
	{}
	VisitorDescriptor* GetDescriptor() const;
	int GetFoorCapacity() const;
	void SetFoodCapacity(int foodCapacity);
	int GetNeedToPee() const;
	void SetNeedToPee(int newNeed);
	MovementStatus GetMovementPurpose() const;
	void SetMovementPurpose(MovementStatus newPurpose);
	__declspec(property(get = GetFoorCapacity, put = SetFoodCapacity)) int starvation;
	__declspec(property(get = GetNeedToPee, put = SetNeedToPee)) int toiletNeed;
	void VisitorMove(PointCoord destination);
	void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const override;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
	void MakeAStep(Construction* destinationRoadTile);
};
/////////////End of Constructions Classes/////////////