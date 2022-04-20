#include "RoadGraph.h"
//Class Node
int Node::GetIndex() const
{
	return objectIndex;
}
void Node::SetIndex(int index)
{
	objectIndex = index;
}
Node* Node::GetNeighbourNode(Direction side)
{
	switch (side)
	{
	case Direction::Left: {return leftNeighbour; }
	case Direction::Up: {return aboveNeighbour; }
	case Direction::Right: {return rightNeighbour; }
	case Direction::Down: {return bottomNeighbour; }
	default: {throw MyException("Node::GetNeighbourNode(Direction side) bad direction"); }
	}
}
void Node::SetNeighbourNode(Node* neighbour, Direction side)
{
	switch (side)
	{
	case Direction::Left: {leftNeighbour = neighbour; return; }
	case Direction::Up: {aboveNeighbour = neighbour; return; }
	case Direction::Right: {rightNeighbour = neighbour; return; }
	case Direction::Down: {bottomNeighbour = neighbour; return; }
	default: {throw MyException("Node::GetNeighbourNode(Direction side) bad direction"); }
	}
}
//Class RoadGraph
Node* RoadGraph::FindNode(int index) const
{
	for (auto someNode : allNodes)
	{
		if (someNode->indexOfObject == index)
		{
			return someNode;
		}
	}
	return nullptr;
}
void RoadGraph::SetNeighbourhood(pair<pair<int, int>, Direction> roadEdge)
{
	Node* mainNode = FindNode(roadEdge.first.first);
	Node* neighbourNode = FindNode(roadEdge.first.second);
	if (mainNode == nullptr || neighbourNode == nullptr)
	{
		throw MyException("RoadGraph::SetNeighbourhood(pair<pair<int, int>, Direction> roadEdge) node wasn't found");
	}
	mainNode->SetNeighbourNode(neighbourNode, roadEdge.second);
	switch (roadEdge.second)
	{
	case Direction::Left: {neighbourNode->SetNeighbourNode(mainNode, Direction::Right); return; }
	case Direction::Up: {neighbourNode->SetNeighbourNode(mainNode, Direction::Down); return; }
	case Direction::Right: {neighbourNode->SetNeighbourNode(mainNode, Direction::Left); return; }
	case Direction::Down: {neighbourNode->SetNeighbourNode(mainNode, Direction::Up); return; }
	default: {throw MyException("RoadGraph::SetNeighbourhood(pair<pair<int, int>, Direction> roadEdge) bad direction"); }
	}
}
void RoadGraph::SetNeighbourhoodEverySide(vector<pair<pair<int, int>, Direction> > neighbourLinks)
{
	if (neighbourLinks.empty())
	{
		return;
	}
	else
	{
		if (neighbourLinks.at(0).first.second != -1)
		{
			for (auto& link : neighbourLinks)
			{
				SetNeighbourhood(link);
			}
		}
	}
}
Node* RoadGraph::CreateNode(int index)
{
	if (FindNode(index) == nullptr)
	{
		Node* newNode_ptr = new Node(index);
		return newNode_ptr;
	}
	throw MyException("RoadGraph::CreateNode(int index) addition of existed node");
}
Node* RoadGraph::AddNode(vector<pair<pair<int, int>, Direction> > neighbourLinks)
{
	if (neighbourLinks.empty())
	{
		throw MyException("RoadGraph::AddNode(vector<pair<pair<int, int>, Direction> > neighbourLinks) vector is empty");
	}
	Node* newNode_ptr = CreateNode(neighbourLinks.at(0).first.first);
	allNodes.push_back(newNode_ptr);
	SetNeighbourhoodEverySide(neighbourLinks);
	return newNode_ptr;
}
void RoadGraph::DeleteNode(int index)
{
	Node* forDeleting = FindNode(index);
	if (forDeleting == nullptr)
	{
		throw MyException("RoadGraph::DeleteNode(PointCoord location) no node found");
	}
	if (forDeleting->GetNeighbourNode(Direction::Left) != nullptr)
	{
		forDeleting->GetNeighbourNode(Direction::Left)->SetNeighbourNode(nullptr, Direction::Right);
	}
	if (forDeleting->GetNeighbourNode(Direction::Up) != nullptr)
	{
		forDeleting->GetNeighbourNode(Direction::Up)->SetNeighbourNode(nullptr, Direction::Down);
	}
	if (forDeleting->GetNeighbourNode(Direction::Right) != nullptr)
	{
		forDeleting->GetNeighbourNode(Direction::Right)->SetNeighbourNode(nullptr, Direction::Left);
	}
	if (forDeleting->GetNeighbourNode(Direction::Down) != nullptr)
	{
		forDeleting->GetNeighbourNode(Direction::Down)->SetNeighbourNode(nullptr, Direction::Up);
	}
	allNodes.remove(forDeleting);
}
//
void RoadGraph::GraphStatusUpdate(vector<pair<pair<int, int>, Direction> > neighbourLinks)
{
	if (neighbourLinks.empty())
	{
		throw MyException("RoadGraph::GraphStatusUpdate(vector<pair<pair<int, int>, Direction side> > neighbourLinks) empty vector");
	}
	AddNode(neighbourLinks);
}
void RoadGraph::GraphStatusUpdate(int index)
{
	DeleteNode(index);
	UpdateIndices(index);
}
void RoadGraph::EraseAllNodes()
{
	for (auto everyNode : allNodes)
	{
		delete everyNode;
	}
}
void RoadGraph::BuildGraph(vector<pair<pair<int, int>, Direction> > neighbourLinks)
{
	if (!allNodes.empty())
	{
		throw MyException("RoadGraph::BuildGraph(vector<pair<pair<int, int>, Direction> > neighbourLinks) graph should be empty to build it");
	}
	if (neighbourLinks.empty())
	{
		throw MyException("RoadGraph::BuildGraph(vector<pair<pair<int, int>, Direction> > neighbourLinks) got empty argument vector");
	}
	for (auto link : neighbourLinks)
	{
		CreateNode(link.first.first);
	}
	SetNeighbourhoodEverySide(neighbourLinks);
}
void RoadGraph::UpdateIndices(int index)
{
	for (auto everyNode : allNodes)
	{
		if (everyNode->indexOfObject > index)
		{
			--everyNode->indexOfObject;
		}
	}
}
void RoadGraph::SetWeight(Node* someNode, Direction neighbourSide, vector<int>& column)
{
	Node* neighbourNode = someNode->GetNeighbourNode(neighbourSide);
	if (neighbourNode == nullptr)
	{
		return;
	}
	column.at(neighbourNode->indexOfObject) = 1;
}
vector<vector<int> > RoadGraph::GetWeightMatrix()
{
	vector<vector<int> > matrix;
	int graphSize = allNodes.size();
	matrix.resize(graphSize);
	for (auto& column : matrix)
	{
		column.resize(graphSize, 0);
	}
	int nodeIndex = 0;
	Node* node = nullptr;
	for (auto& column : matrix)
	{
		node = FindNode(nodeIndex);
		SetWeight(node, Direction::Left, column);
		SetWeight(node, Direction::Up, column);
		SetWeight(node, Direction::Right, column);
		SetWeight(node, Direction::Down, column);
		++nodeIndex;
	}
	return matrix;
}
void RoadGraph::FindNextPathIndex(vector<int>& pathIndices, vector<int> distances, Node*& current, int& currentDistance, int side)
{
	Node* neighbour = current->GetNeighbourNode((Direction)side);
	if (neighbour != nullptr && distances.at(neighbour->indexOfObject) == currentDistance - 1)
	{
		--currentDistance;
		pathIndices.push_back(neighbour->indexOfObject);
		current = neighbour;
		return;
 	}
	else
	{
		if (side > 1)
		{
			--side;
			FindNextPathIndex(pathIndices, distances, current, currentDistance, side);
			return;
		}
		else
		{
			throw MyException("RoadGraph::FindNextPathIndex(vector<int>& pathIndices, vector<int> distances, Node*& current, int& currentDistance, int side) next path node was not found");
		}
	}
}
vector<int> RoadGraph::GetPathIndices(vector<int> distances, int destinationIndex)
{
	if (distances.empty())
	{
		throw MyException("RoadGraph::GetPathIndices(vector<int> distances, int destinationIndex) distances is empty");
	}
	Node* last = FindNode(destinationIndex);
	if (last == nullptr)
	{
		throw MyException("RoadGraph::GetPathIndices(vector<int> distances, int destinationIndex) bad destination index");
	}
	vector<int> pathIndices;
	pathIndices.push_back(destinationIndex);
	int distance = distances.at(destinationIndex);
	while (distance != 0)
	{
		FindNextPathIndex(pathIndices, distances, last, distance);
	}
	return pathIndices;
}