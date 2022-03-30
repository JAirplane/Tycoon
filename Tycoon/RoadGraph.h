#pragma once
#include <limits>
#include <algorithm>
#include <iterator>
#include "ObserverInterface.h"
class Node
{
private:
	PointCoord nodeLocation;
	Node* leftNeighbour;
	Node* aboveNeighbour;
	Node* rightNeighbour;
	Node* bottomNeighbour;
public:
	Node(PointCoord location) : nodeLocation(location)
	{
		leftNeighbour = nullptr;
		aboveNeighbour = nullptr;
		rightNeighbour = nullptr;
		bottomNeighbour = nullptr;
	}
	~Node() {}
	PointCoord GetNodeLocation() const;
	void SetNodeLocation(PointCoord anotherLocation);
	Node* GetNeighbourNode(Direction side);
	void SetNeighbourNode(Node* neibour, Direction side);
	__declspec(property(get = GetNodeLocation, put = SetNodeLocation)) PointCoord nodePoint;
};
class RoadGraph : public GraphStatusObserverInterface
{
private:
	list<Node*> allNodes;
public:
	RoadGraph()
	{}
	~RoadGraph()
	{
		for (auto everyNode : allNodes)
		{
			delete everyNode;
		}
	}
	void GraphStatusUpdate(PointCoord nodeLocation, bool addOrDelete) override;
	//
	Node* FindNode(PointCoord location);
	void SetNeighbourhood(Node* someNode_ptr, Direction side);
	Node* AddNode(PointCoord location);
	void DeleteNode(PointCoord location);
	void EraseAllNodes();
	void BuildGraph(vector<PointCoord> allRoadsLocations);
	int GetNodePosition(Node* someNode) const;
	void SetWeight(Node* someNode, Direction neighbourSide, vector<int>& column);
	vector<vector<int> > GetWeightMatrix();
};