#pragma once
#include <memory>
#include <functional>
#include "IngameObject.h"
/////////////Parent Class of Every Construction Type/////////////
//class GraphStatusSubjectInterface;
//class GraphStatusObserverInterface;
class Visitor;
class Construction : public IngameObject, public GraphStatusSubjectInterface
{
private:
	const ConstructionDescriptor* describe_ptr;
	bool connectedToRoad;
	bool isChosen;
	int visitorsCount;
public:
	Construction(PointCoord upperLeft, const ConstructionDescriptor* description_ptr, const Visualisation* paint_ptr) : IngameObject(upperLeft, paint_ptr)
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
	void GraphStatusAttach(GraphStatusObserverInterface* observer) override;
	void GraphStatusDetach(GraphStatusObserverInterface* observer) override;
	void GraphStatusNotify(vector<pair<pair<int, int>, Direction> > edges) override;
	void GraphStatusNotify(int constructionIndex) override;
	//
	const ConstructionDescriptor* GetDescriptor() const; //no setter here
	//
	virtual int GetEntranceHeightAdd() const = 0;
	virtual int GetEntranceWidthAdd() const = 0;
	//
	virtual int GetVisitorsInside() const = 0;
	virtual void SetVisitorsInside(int visitorsValue) = 0;
	__declspec(property(get = GetVisitorsInside, put = SetVisitorsInside)) int visitorsCounter;
	//
	virtual PointCoord GetEntrancePoint() const = 0;
	virtual PointCoord GetRedrawNeighboursPoint() const = 0;
	virtual Direction GetExitDirection() const = 0;
	virtual void SetExitDirection(Direction exit) = 0;
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
	virtual int GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) = 0;
	virtual bool Connected(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) = 0;
	virtual void CorrectConstructionCoordsForDraw(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int& leftX, int& topY, int& rightX, int& bottomY) const;
	virtual void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const = 0;
	virtual void DrawObject(const wstring drawingSymbol) const;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const = 0;
	//
	virtual vector<Construction*> GetNeighbourRoads(const list<Construction*>& allRoads) const = 0;
	virtual vector<Construction*> GetNeighbourBuildings(const list<Construction*>& allBuildings) const = 0;
	virtual Construction* GetPreliminaryNeighbour(Construction* preliminary_ptr) const = 0;
	virtual void RedrawNeighbours(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const list<Visitor*>& allVisitors,
		Construction* preliminary_ptr, const Camera* camera_ptr) = 0;
	static void RedrawNeighbours(PointCoord centralPoint, const list<Construction*>& allRoads, const list<Construction*>& allBuildings,
		const list<Visitor*>& allVisitors, Construction* preliminary_ptr, const Camera* camera_ptr);
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
	Building(PointCoord upperLeft, const ConstructionDescriptor* buildingData, const Visualisation* paint_ptr) : Construction(upperLeft, buildingData, paint_ptr)
	{
		SetHeightAddition(buildingData->GetHeightAdd());
		SetWidthAddition(buildingData->GetWidthAdd());
		this->entranceHeightAdd = buildingData->GetHeightAdd();
		this->entranceWidthAdd = buildingData->GetWidthAdd() / 2;
		overallProfit = 0;
		visitorsInside = 0;
		exitDirection = Direction::Down;
	}
	~Building() {}
	int GetVisitorsInside() const override;
	void SetVisitorsInside(int visitorsValue) override;
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
	int GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) override;
	bool Connected(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) override;
	int GetProfit() const;
	void SetProfit(int profit);
	vector<Construction*> GetNeighbourRoads(const list<Construction*>& allRoads) const override;
	vector<Construction*> GetNeighbourBuildings(const list<Construction*>& allBuildings) const override;
	Construction* GetPreliminaryNeighbour(Construction* preliminary_ptr) const override;
	void RedrawNeighbours(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const list<Visitor*>& allVisitors,
		Construction* preliminary_ptr, const Camera* camera_ptr) override;
	void CorrectConstructionCoordsForDraw(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int& leftX, int& topY, int& rightX, int& bottomY) const override;
	void DrawObject(int mask = 0, int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const override;
	static vector<Construction*> ChooseFromBuildings(_Mem_fn<int (ConstructionDescriptor::*)() const> buildingProperty, const list<Construction*>& allBuildings);
};
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
	Construction* GetPreliminaryNeighbour(Construction* preliminary_ptr) const override;
	void RedrawNeighbours(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const list<Visitor*>& allVisitors,
		Construction* preliminary_ptr, const Camera* camera_ptr) override;
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