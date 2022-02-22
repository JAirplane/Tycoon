#pragma once
#include <vector>

class Node
{
private:
	const Construction* roadVertex;
public:
	Node(const Construction* vertex) : roadVertex(vertex_ptr)
	{}
	~Node()
	{}
	const Construction* getVertex() const;
};
class SideNode : public Node
{
private:
	int distanceToRoot;
	vector<const Construction*> pathFromRoot;
public:
	SideNode(const Construction* vertex) : Node(vertex)
	{
		distanceToRoot = 1; //minimum range between two different nodes
	}
	~SideNode()
	{}
	int GetDistanceToRoot() const;
	void AddToPath(const Construction* notANodeRoad_ptr);
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
	RootNode(const Construction* vertex) : Node(vertex)
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
	SideNode* CreateSideNode(Direction side, const Construction* vertex_ptr);
	void DeleteSideNode(Direction side);
	void DeleteSideNode(const Construction* vertex_ptr);
	void PathAdd(Direction side, const Construction* notANodeRoad_ptr);
	PointCoord GetFirstPathElementCoord(Direction pathDirection);
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
	void CreateRootNode(const Construction* vertex_ptr);
	void DeleteRootNode(const Construction* vertex_ptr);
	void AddRootNode(const Construction* vertex_ptr);
	RootNode* FindRootNode(const Construction* vertex_ptr);
	void FillGraphWithRootNodes(const list<Road*>& roads);
	void FillPathToSideNode(const RootNode* node_ptr, Direction pathDirection, const list<Road*>& roads);
	void FillPathToSideNodes(const RootNode* node_ptr, const list<Road*>& roads);
};