#pragma once
#include <vector>
#include <limits>
#include <algorithm>
#include "IngameObjectDerived.h"
class Node
{
private:
	int index;
	PointCoord nodeLocation;
public:
	Node(PointCoord location) : nodeLocation(location)
	{
		index = -1; //means no index assignment
	}
	~Node() {}
	int GetNodeIndex() const;
	void SetNodeIndex(int newIndex);
	PointCoord GetNodeLocation() const;
	void SetNodeLocation(PointCoord anotherLocation);
	__declspec(property(get = GetNodeIndex, put = SetNodeIndex)) int nodeIndex;
	__declspec(property(get = GetNodeLocation, put = SetNodeLocation)) PointCoord nodePoint;
};
class Edge
{
private:
	int startingNodeIndex;
	int endingNodeIndex;
public:
	Edge(int start, int end) : startingNodeIndex(start), endingNodeIndex(end)
	{}
	~Edge() {}
	int GetStartingIndex() const;
	void SetStartingIndex(int newIndex);
	int GetEndingIndex() const;
	void SetEndingIndex(int newIndex);
	__declspec(property(get = GetStartingIndex, put = SetStartingIndex)) int startingIndex;
	__declspec(property(get = GetEndingIndex, put = SetEndingIndex)) int endingIndex;
};
class RoadGraph
{
private:
	list<Node*> allNodes;
	list<Edge*> allEdges;
public:
	RoadGraph()
	{}
	~RoadGraph()
	{
		for (auto everyNode : allNodes)
		{
			delete everyNode;
		}
		for (auto everyEdge : allEdges)
		{
			delete everyEdge;
		}
	}
	Node* AddNode(PointCoord location);
	void DeleteNode(PointCoord location);
	void DeleteNode(int index);
	Edge* AddEdge(PointCoord startPoint, PointCoord endPoint);
	Edge* AddEdge(int startIndex, int endIndex);
	void DeleteEdge(int startIndex, int endIndex);
	void DeleteEdges(int index);
	Node* FindNode(PointCoord location);
	Node* FindNode(int index);
	Edge* FindEdge(int startIndex, int endIndex);
	vector<int> FindNeibourNodeIndices(int nodeIndex);
	void UpdateAllIndices();


	//
	//RootNode* CreateRootNode(const Road* vertex_ptr);
	//void DeleteRootNode(const Road* vertex_ptr);
	//RootNode* AddRootNode(const Road* vertex_ptr);
	//RootNode* FindRootNode(const Road* vertex_ptr);
	//const Road* FindNextPathPoint(PointCoord leftPoint, PointCoord upperPoint, PointCoord rightPoint, PointCoord downPoint, PointCoord previousPathElement, const list<Road*>& roads);
	//void FillPathToSideNode(RootNode* node_ptr, Direction pathDirection, const list<Road*>& roads);
	//void FillAllPathes(RootNode* node_ptr, const list<Road*>& roads);
	//vector<Road*> GetNodesToDestination(PointCoord currentLocation, Road* destination) const;
};