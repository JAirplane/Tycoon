#pragma once
#include <memory>
#include <functional>
#include "IngameObject.h"
/////////////Parent Class of Every Construction Type/////////////
class Road;
class Building;
class GraphStatusSubjectInterface;
class GraphStatusObserverInterface;
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
	virtual PointCoord GetRedrawNeighboursPoint() const = 0;
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
	virtual void CopyRotationProperties(Construction* another_ptr);
	virtual int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) = 0;
	virtual bool Connected(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) = 0;
	virtual void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const = 0;
	virtual void DrawObject(const wstring drawingSymbol) const;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const = 0;
	//
	virtual vector<Construction*> GetNeighbourRoads(const list<Road*>& allRoads) const = 0;
	virtual vector<Construction*> GetNeighbourBuildings(const list<Building*>& allBuildings) const = 0;
	virtual Construction* GetPreliminaryNeighbour(Construction* preliminary_ptr) const = 0;
	virtual void RedrawNeighbours(const list<Road*>& allRoads, const list<Building*>& allBuildings, Construction* preliminary_ptr, const Camera* camera_ptr) = 0;
	static void RedrawNeighbours(PointCoord centralPoint, const list<Road*>& allRoads, const list<Building*>& allBuildings,
		Construction* preliminary_ptr, const Camera* camera_ptr);
	void SetVisitorsCount(int visitorsCount);
	virtual bool IsBreakable() const;
};
/////////////Parent Class of buildings/////////////
class Building : public Construction
{
private:
	int entranceHeightAdd;
	int entranceWidthAdd;
	Direction exitDirection;
	int overallProfit;
	int visitorsInside;
public:
	Building(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : Construction(upperLeft, manager_ptr, paint_ptr)
	{
		SetHeightAddition(manager_ptr->GetHeightAdd());
		SetWidthAddition(manager_ptr->GetWidthAdd());
		this->entranceHeightAdd = manager_ptr->GetHeightAdd();
		this->entranceWidthAdd = manager_ptr->GetWidthAdd() / 2;
		overallProfit = 0;
		visitorsInside = 0;
		exitDirection = Direction::Down;
	}
	~Building() {}
	int GetVisitorsInside() const;
	void SetVisitorsInside(int visitorsValue);
	__declspec(property(get = GetVisitorsInside, put = SetVisitorsInside)) int visitorsCounter;
	int GetEntranceHeightAdd() const override;
	void SetEntranceHeightAdd(int heightAdd);
	int GetEntranceWidthAdd() const override;
	void SetEntranceWidthAdd(int widthAdd);
	Direction GetExitDirection() const override;
	void SetExitDirection(Direction exit);
	PointCoord GetEntrancePoint() const override;
	int RotateConstruction() override; // returns -1 if rotation failed
	PointCoord GetRedrawNeighboursPoint() const override;
	PointCoord GetPotentialConnectedRoadPoint() const;
	wstring GetEntranceSymbol() const override;
	void CopyEntrance(Construction* preliminary_ptr);
	void CopyRotationProperties(Construction* another_ptr) override;
	int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	bool Connected(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	int GetProfit() const;
	void SetProfit(int profit);
	vector<Construction*> GetNeighbourRoads(const list<Road*>& allRoads) const override;
	vector<Construction*> GetNeighbourBuildings(const list<Building*>& allBuildings) const override;
	Construction* GetPreliminaryNeighbour(Construction* preliminary_ptr) const override;
	void RedrawNeighbours(const list<Road*>& allRoads, const list<Building*>& allBuildings, Construction* preliminary_ptr, const Camera* camera_ptr) override;
	void CorrectBuildingCoordsForDraw(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int& leftX, int& topY, int& rightX, int& bottomY) const;
	void DrawObject(int mask = 0, int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
	static vector<Building*> ChooseFromBuildings(_Mem_fn<int (ConstructionDescriptor::*)() const> buildingProperty, const list<Building*>& allBuildings);
};
/////////////One Pixel of Road/////////////
class Road : public Construction, public GraphStatusSubjectInterface
{
private:
	list<GraphStatusObserverInterface*> graphStatusObservers;
public:
	Road(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : Construction(upperLeft, manager_ptr, paint_ptr)
	{
		SetHeightAddition(GetDescriptor()->GetHeightAdd());
		SetWidthAddition(GetDescriptor()->GetWidthAdd());
	}
	~Road() {}
	//
	void GraphStatusAttach(GraphStatusObserverInterface* observer) override;
	void GraphStatusDetach(GraphStatusObserverInterface* observer) override;
	void GraphStatusNotify(vector<pair<pair<int, int>, Direction> > edges) override;
	void GraphStatusNotify(int roadIndex) override;
	//
	int GetEntranceHeightAdd() const override;
	int GetEntranceWidthAdd() const override;
	Direction GetExitDirection() const override;
	int RotateConstruction() override;
	int GetProfit() const;
	bool RoadIsAnEntrance(const list<Building*>& allBuildings);
	PointCoord GetEntrancePoint() const override;
	PointCoord GetRedrawNeighboursPoint() const override;
	//
	int GetMaskWithConstruction(const Construction* someConstruction_ptr) const;
	virtual int GetMaskWithRealRoads(const list<Road*>& allRoads) const;
	int GetMaskWithRealBuildings(const list<Building*>& allBuildings) const;
	int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	//
	bool Connected(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
	vector<Construction*> GetNeighbourRoads(const list<Road*>& allRoads) const override;
	vector<Construction*> GetNeighbourBuildings(const list<Building*>& allBuildings) const override;
	Construction* GetPreliminaryNeighbour(Construction* preliminary_ptr) const override;
	void RedrawNeighbours(const list<Road*>& allRoads, const list<Building*>& allBuildings, Construction* preliminary_ptr, const Camera* camera_ptr) override;
	void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const override;
	void DrawObject(const wstring drawingSymbol) const override;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
};
class UnbreakableRoad : public Road
{
public:
	UnbreakableRoad(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : Road(upperLeft, manager_ptr, paint_ptr)
	{}
	~UnbreakableRoad() {}
	bool IsBreakable() const override;
	void SetRoadConnectionStatus(bool connected) override;
	int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr);
};
class VisibleOutsidePlayingfieldRoad : public UnbreakableRoad
{
public:
	VisibleOutsidePlayingfieldRoad(PointCoord upperLeft, ConstructionDescriptor* manager_ptr, Visualisation* paint_ptr) : UnbreakableRoad(upperLeft, manager_ptr, paint_ptr)
	{}
	~VisibleOutsidePlayingfieldRoad() {}
	bool VisibleOutsidePlayingfield() const override;
	int GetEnvironmentMask(const list<Road*>& allRoads, const list<Building*>& allBuildings, const Construction* preliminary_ptr) override;
};
/////////////People are looking for some fun!/////////////
class Visitor : public IngameObject
{
private:
	VisitorDescriptor* description_ptr;
	Building* destination_ptr;
	Building* previousVisitedBuilding;
	int insideBuilding;
	vector<int> pathIndices;
	int foodCapacity;
	int needToPee;
	int moneyAmount;
public:
	Visitor(PointCoord upperLeft, Visualisation* paint_ptr, VisitorDescriptor* describe_ptr, int currentParkLevel) : IngameObject(upperLeft, paint_ptr)
	{
		description_ptr = describe_ptr;
		destination_ptr = nullptr;
		previousVisitedBuilding = nullptr;
		insideBuilding = 0;
		foodCapacity = 100;
		needToPee = 100;
		moneyAmount = 0;
		switch (currentParkLevel)
		{
		case 0: {moneyAmount = rand() % ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(0)->moneyFormulaValue +
			ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(0)->moneyFormulaValue; break; }
		case 1: {moneyAmount = rand() % ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(1)->moneyFormulaValue +
			ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(1)->moneyFormulaValue; break; }
		case 2: {moneyAmount = rand() % ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(2)->moneyFormulaValue +
			ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(2)->moneyFormulaValue; break; }
		case 3: {moneyAmount = rand() % ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(3)->moneyFormulaValue +
			ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(3)->moneyFormulaValue; break; }
		case 4: {moneyAmount = rand() % ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(4)->moneyFormulaValue +
			ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(4)->moneyFormulaValue; break; }
		case 5: {moneyAmount = rand() % ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(5)->moneyFormulaValue +
			ParkLevelConstants::GetConstantsPointer()->GetAllConstants().at(5)->moneyFormulaValue; break; }
		default: {throw MyException("Visitor(PointCoord upperLeft, Visualisation* paint_ptr, VisitorDescriptor* describe_ptr, int currentParkLevel) bad park level"); }
		}
	}
	~Visitor()
	{}
	VisitorDescriptor* GetDescriptor() const;
	int GetFoorCapacity() const;
	void SetFoodCapacity(int foodCapacity);
	int GetNeedToPee() const;
	void SetNeedToPee(int newNeed);
	int GetMoneyAmount() const;
	void SetMoneyAmount(int money);
	int GetInsideBuildingValue() const;
	void SetInsideBuildingValue(int periodsInsideBuilding);
	__declspec(property(get = GetFoorCapacity, put = SetFoodCapacity)) int starvation;
	__declspec(property(get = GetNeedToPee, put = SetNeedToPee)) int toiletNeed;
	__declspec(property(get = GetMoneyAmount, put = SetMoneyAmount)) int visitorCash;
	__declspec(property(get = GetInsideBuildingValue, put = SetInsideBuildingValue)) int buildingVisiting;
	void VisitorMove(PointCoord destination);
	void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const override;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
	void MakeAStep(int destinationRoadIndex, const list<Road*>& allRoads, const Camera* camera_ptr);
	bool GoInside();
	void GoOutside(const list<Road*>& allRoads, list<Visitor*> allVisitors);
	pair<Building*, int> FindNearestDestination(const vector<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances) const; // returns destination building and 
	// destination road index
	Building* GetDestination() const;
	int SetDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances); // returns destination road index
	pair<vector<int>, int> ChooseDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<vector<int> > weightMatrix); // returns distances and destination road index
	void ClearDestination();
	const vector<int> GetPath() const;
	void SetPath(vector<int> newPath);
	void ClearPath();
	int GetNextPathIndex(const list<Road*>& allRoads, Road* currentRoad);
};
/////////////End of Constructions Classes/////////////