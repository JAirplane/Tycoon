#pragma once
#include <memory>
#include "Building.h"
/////////////One Pixel of Road/////////////
class Road : public Construction
{
private:
	list<GraphStatusObserverInterface*> graphStatusObservers;
public:
	Road(PointCoord upperLeft, const ConstructionDescriptor* roadData, const Visualisation* paint_ptr) : Construction(upperLeft, roadData, paint_ptr)
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
	//
	int GetVisitorsInside() const override;
	void SetVisitorsInside(int visitorsValue) override;
	__declspec(property(get = GetVisitorsInside, put = SetVisitorsInside)) int visitorsCounter;
	//
	Direction GetExitDirection() const override;
	void SetExitDirection(Direction exit) override;
	int RotateConstruction() override;
	int GetProfit() const;
	bool RoadIsAnEntrance(const list<Building*>& allBuildings);
	PointCoord GetEntrancePoint() const override;
	PointCoord GetRedrawNeighboursPoint() const override;
	//
	int GetMaskWithConstruction(const Construction* someConstruction_ptr) const;
	virtual int GetMaskWithRealRoads(const list<Construction*>& allRoads) const;
	int GetMaskWithRealBuildings(const list<Construction*>& allBuildings) const;
	int GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) override;
	//
	bool Connected(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) override;
	vector<Construction*> GetNeighbourRoads(const list<Construction*>& allRoads) const override;
	vector<Construction*> GetNeighbourBuildings(const list<Construction*>& allBuildings) const override;
	void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const override;
	void DrawObject(const wstring drawingSymbol) const override;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
};
class UnbreakableRoad : public Road
{
public:
	UnbreakableRoad(PointCoord upperLeft, const ConstructionDescriptor* roadData, const Visualisation* paint_ptr) : Road(upperLeft, roadData, paint_ptr)
	{}
	~UnbreakableRoad() {}
	bool IsBreakable() const override;
	void SetRoadConnectionStatus(bool connected) override;
	int GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr);
};
class VisibleOutsidePlayingfieldRoad : public UnbreakableRoad
{
public:
	VisibleOutsidePlayingfieldRoad(PointCoord upperLeft, const ConstructionDescriptor* roadData, const Visualisation* paint_ptr) : UnbreakableRoad(upperLeft, roadData, paint_ptr)
	{}
	~VisibleOutsidePlayingfieldRoad() {}
	bool VisibleOutsidePlayingfield() const override;
	int GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) override;
};
/////////////End of Constructions Classes/////////////