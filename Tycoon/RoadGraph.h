#pragma once
#include <vector>
#include <limits>
#include "ObjectContainers.h"
class Node
{
private:
	const Road* roadVertex;
public:
	Node(const Road* vertex) : roadVertex(vertex)
	{}
	~Node()
	{}
	const Road* GetVertex() const;
};
class SideNode : public Node
{
private:
	int distanceToRoot;
	vector<const Road*> pathFromRoot;
public:
	SideNode(const Road* vertex) : Node(vertex)
	{
		distanceToRoot = 0; //range between two different nodes
	}
	~SideNode()
	{}
	int GetDistanceToRoot() const;
	void AddPath(vector<const Road*> path, int distance);
	void ClearPath(); // do not free the memory, just left the vector empty
	void ResetPathCapacity();
};
class RootNode : public Node
{
private:
	SideNode* leftVertex;
	SideNode* topVertex;
	SideNode* rightVertex;
	SideNode* bottomVertex;
public:
	RootNode(const Road* vertex) : Node(vertex)
	{
		leftVertex = nullptr;
		topVertex = nullptr;
		rightVertex = nullptr;
		bottomVertex = nullptr;
	}
	~RootNode()
	{
		delete leftVertex;
		delete topVertex;
		delete rightVertex;
		delete bottomVertex;
	}
	SideNode* CreateSideNode(Direction side, const Road* vertex_ptr);
	bool AddSideNode(const Road* pathElement, vector<const Road*>& path, int& distance, Direction pathDirection);
	void DeleteSideNode(Direction side);
	void DeleteSideNode(const Road* vertex_ptr);
	PointCoord GetFirstPathElementCoord(Direction pathDirection) const;
};
class RoadGraph
{
private:
	list<RootNode*> graph;
public:
	RoadGraph()
	{}
	~RoadGraph()
	{
		for (auto& element : graph)
		{
			delete element;
		}
	}
	void CreateRootNode(const Road* vertex_ptr);
	void DeleteRootNode(const Road* vertex_ptr);
	void AddRootNode(const Road* vertex_ptr);
	RootNode* FindRootNode(const Road* vertex_ptr);
	const Road* FindNextPathPoint(PointCoord leftPoint, PointCoord upperPoint, PointCoord rightPoint, PointCoord downPoint, PointCoord previousPathElement, const list<Road*>& roads);
	void FillPathToSideNode(RootNode* node_ptr, Direction pathDirection, const list<Road*>& roads);
	void FillAllPathes(RootNode* node_ptr, const list<Road*>& roads);
	vector<Road*> GetNodesToDestination(PointCoord currentLocation, Road* destination) const;
};