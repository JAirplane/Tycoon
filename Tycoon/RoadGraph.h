#pragma once
#include <limits>
#include <algorithm>
#include <iterator>
#include "ObserverInterface.h"
class Node
{
private:
	int objectIndex;
	Node* leftNeighbour;
	Node* aboveNeighbour;
	Node* rightNeighbour;
	Node* bottomNeighbour;
public:
	Node(int index) : objectIndex(index)
	{
		leftNeighbour = nullptr;
		aboveNeighbour = nullptr;
		rightNeighbour = nullptr;
		bottomNeighbour = nullptr;
	}
	~Node() {}
	int GetIndex() const;
	void SetIndex(int index);
	Node* GetNeighbourNode(Direction side);
	void SetNeighbourNode(Node* neibour, Direction side);
	__declspec(property(get = GetIndex, put = SetIndex)) int indexOfObject;
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
	void GraphStatusUpdate(vector<pair<pair<int, int>, Direction> > neighbourLinks) override;
	void GraphStatusUpdate(int index) override;
	//
	Node* FindNode(int index) const;
	void SetNeighbourhood(pair<pair<int, int>, Direction> roadEdge);
	void SetNeighbourhoodEverySide(vector<pair<pair<int, int>, Direction> > neighbourLinks);
	Node* CreateNode(int index);
	Node* AddNode(vector<pair<pair<int, int>, Direction> > neighbourLinks);
	void DeleteNode(int index);
	void EraseAllNodes();
	void BuildGraph(vector<pair<pair<int, int>, Direction> > neighbourLinks);
	void UpdateIndices(int index); //all indicies after "index" are decremented
	void SetWeight(Node* someNode, Direction neighbourSide, vector<int>& column);
	vector<vector<int> > GetWeightMatrix();
	void FindNextPathIndex(vector<int>& pathIndices, vector<int> distances, Node*& current, int& currentDistance, int side = 4);
	vector<int> GetPathIndices(vector<int> distances, int destinationIndex);
};