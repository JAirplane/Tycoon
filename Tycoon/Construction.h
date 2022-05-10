#pragma once
#include <functional>
#include "IngameObject.h"
/////////////Parent Class of Every Construction Type/////////////
class Visitor;
class Construction : public IngameObject, public GraphStatusSubjectInterface
{
private:
	const ConstructionDescriptor* describe_ptr;
	bool connectedToRoad;
	bool isChosen;
	int overallVisitors;
public:
	Construction(PointCoord upperLeft, const ConstructionDescriptor* description_ptr, const Visualisation* paint_ptr) : IngameObject(upperLeft, paint_ptr)
	{
		describe_ptr = description_ptr;
		SetHeightAddition(describe_ptr->GetHeightAdd());
		SetWidthAddition(describe_ptr->GetWidthAdd());
		connectedToRoad = false;
		isChosen = false;
		overallVisitors = 0;
	}
	virtual ~Construction()
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
	int GetOverallVisitors() const;
	void SetOverallVisitors(int overallVisitors);
	__declspec(property(get = GetOverallVisitors, put = SetOverallVisitors)) int allTimeVisited;
	//
	virtual int GetProfit() const = 0;
	virtual void SetProfit(int profit) = 0;
	__declspec(property(get = GetProfit, put = SetProfit)) int overallRevenue;
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
	//
	color GetBackgroundColor() const;
	virtual int RotateConstruction() = 0;
	virtual void CopyRotationProperties(Construction* another_ptr);
	virtual int GetEnvironmentMask(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) const = 0;
	virtual bool Connected(const list<Construction*>& allRoads, const list<Construction*>& allBuildings, const Construction* preliminary_ptr) = 0;
	virtual void CorrectConstructionCoordsForDraw(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int& leftX, int& topY, int& rightX, int& bottomY) const;
	virtual void DrawObject(int mask = 0, int leftX = 0, int topY = 0, int rightX = 0, int bottomY = 0) const = 0;
	virtual void DrawObject(const wstring drawingSymbol) const;
	void EraseObject(int cameraLeftX = 0, int cameraTopY = 0, int cameraRightX = 0, int cameraBottomY = 0) const = 0;
	//
	virtual vector<Construction*> GetNeighbourRoads(const list<Construction*>& allRoads) const = 0;
	virtual vector<Construction*> GetNeighbourBuildings(const list<Construction*>& allBuildings) const = 0;
	//
	virtual bool IsBreakable() const;
	virtual void Redraw_VisitorCheck(const Camera* cam_ptr, const list<Construction*>& allRoads, const list<Construction*>& allBuildings,
		const list<Visitor*>& allVisitors, const Construction* preliminary_ptr) const = 0;
	static vector<Construction*> ChooseFromBuildings(_Mem_fn<int (ConstructionDescriptor::*)() const> buildingProperty, const list<Construction*>& allBuildings);
};