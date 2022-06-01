#pragma once
#include "Visitor.h"
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
	Building(PointCoord upperLeft, ConstructionDescriptor* buildingData, const Visualisation* paint_ptr) : Construction(upperLeft, buildingData, paint_ptr)
	{
		SetHeightAddition(buildingData->GetHeightAdd());
		SetWidthAddition(buildingData->GetWidthAdd());
		this->entranceHeightAdd = buildingData->GetHeightAdd();
		this->entranceWidthAdd = buildingData->GetWidthAdd() / 2;
		overallProfit = 0;
		visitorsInside = 0;
		exitDirection = Direction::Down;
	}
	virtual ~Building() {}
	int GetVisitorsInside() const override;
	void SetVisitorsInside(int visitorsValue) override;
	__declspec(property(get = GetVisitorsInside, put = SetVisitorsInside)) int visitorsCounter;
	int GetProfit() const override;
	void SetProfit(int profit) override;
	__declspec(property(get = GetProfit, put = SetProfit)) int overallRevenue;
	int GetEntranceHeightAdd() const override;
	void SetEntranceHeightAdd(int heightAdd) override;
	int GetEntranceWidthAdd() const override;
	void SetEntranceWidthAdd(int widthAdd) override;
	Direction GetExitDirection() const override;
	void SetExitDirection(Direction exit);
	PointCoord GetEntrancePoint() const override;
	int RotateConstruction() override; // returns -1 if rotation failed
	PointCoord GetRedrawNeighboursPoint() const override;
	PointCoord GetPotentialConnectedRoadPoint() const;
	wstring GetEntranceSymbol() const override;
	void CopyEntrance(Construction* preliminary_ptr);
	void CopyRotationProperties(Construction* another_ptr) override;
	int GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) const override;
	bool Connected(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) override;
	vector<Construction*> GetNeighbourRoads(const list<Construction*>& allRoads) const override;
	vector<Construction*> GetNeighbourBuildings(const list<Construction*>& allBuildings) const override;
	void CorrectConstructionCoordsForDraw(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int& leftX, int& topY, int& rightX, int& bottomY) const override;
	void DrawObject(int mask = 0, int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
	
	void Redraw_VisitorCheck(const Camera* cam_ptr, const list<Construction*>& allRoads, const list<Construction*>& allBuildings,
		const list<Visitor*>& allVisitors, const Construction* preliminary_ptr) const override;
};