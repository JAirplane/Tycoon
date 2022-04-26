#pragma once
#include "IngameObjectDerived.h"
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
	bool GoOutside(const list<Road*>& allRoads, list<Visitor*> allVisitors);
	pair<Building*, int> FindNearestDestination(const vector<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances) const; // returns destination building and 
		// destination road index
	Building* GetDestination() const;
	int SetDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<int> distances, int lowestEntertainmentPrice); // returns destination road index
	pair<vector<int>, int> ChooseDestination(const list<Building*>& allBuildings, const list<Road*>& allRoads, vector<vector<int> > weightMatrix, int lowestEntertainmentPrice);
	// returns distances and destination road index
	void ClearDestination();
	const vector<int> GetPath() const;
	void SetPath(vector<int> newPath);
	void ClearPath();
	int GetNextPathIndex(const list<Road*>& allRoads, Road* currentRoad);
};