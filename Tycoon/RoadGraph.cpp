#include "RoadGraph.h"

//Class Node
PointCoord Node::GetNodeLocation() const
{
	return nodeLocation;
}
void Node::SetNodeLocation(PointCoord anotherLocation)
{
	nodeLocation = anotherLocation;
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
	case Direction::Left: {leftNeighbour = neighbour; }
	case Direction::Up: {aboveNeighbour = neighbour; }
	case Direction::Right: {rightNeighbour = neighbour; }
	case Direction::Down: {bottomNeighbour = neighbour; }
	default: {throw MyException("Node::GetNeighbourNode(Direction side) bad direction"); }
	}
}
//Class RoadGraph
Node* RoadGraph::FindNode(PointCoord location)
{
	for (auto someNode : allNodes)
	{
		if (someNode->nodePoint == location)
		{
			return someNode;
		}
	}
	return nullptr;
}
void RoadGraph::SetNeighbourhood(Node* someNode_ptr, Direction side)
{
	if (someNode_ptr == nullptr)
	{
		throw MyException("RoadGraph::SetNeighbourhood(Node* someNode_ptr, Direction side) got nullptr node");
	}
	Node* neighbour = FindNode(someNode_ptr->nodePoint.GetSideCoord(side));
	if (neighbour == nullptr)
	{
		return;
	}
	someNode_ptr->SetNeighbourNode(neighbour, side);
	switch (side)
	{
	case Direction::Left: {neighbour->SetNeighbourNode(someNode_ptr, Direction::Right); return; }
	case Direction::Up: {neighbour->SetNeighbourNode(someNode_ptr, Direction::Down); return; }
	case Direction::Right: {neighbour->SetNeighbourNode(someNode_ptr, Direction::Left); return; }
	case Direction::Down: {neighbour->SetNeighbourNode(someNode_ptr, Direction::Up); return; }
	default: {throw MyException("RoadGraph::SetNeighbourhood(Node* someNode_ptr, Direction side) bad direction"); }
	}
}
Node* RoadGraph::AddNode(PointCoord location)
{
	if (FindNode(location) == nullptr)
	{
		Node* newNode_ptr = new Node(location);
		allNodes.push_back(newNode_ptr);
		SetNeighbourhood(newNode_ptr, Direction::Left);
		SetNeighbourhood(newNode_ptr, Direction::Up);
		SetNeighbourhood(newNode_ptr, Direction::Right);
		SetNeighbourhood(newNode_ptr, Direction::Down);
		return newNode_ptr;
	}
	throw MyException("RoadGraph::AddNode(PointCoord location) addition of existed node");

}
void RoadGraph::DeleteNode(PointCoord location)
{
	Node* forDeleting = FindNode(location);
	if (forDeleting == nullptr)
	{
		throw MyException("RoadGraph::DeleteNode(PointCoord location) no node found");
	}
	if (forDeleting->GetNeighbourNode(Direction::Left) != nullptr)
	{
		forDeleting->GetNeighbourNode(Direction::Left)->SetNeighbourNode(nullptr, Direction::Left);
	}
	if (forDeleting->GetNeighbourNode(Direction::Up) != nullptr)
	{
		forDeleting->GetNeighbourNode(Direction::Up)->SetNeighbourNode(nullptr, Direction::Up);
	}
	if (forDeleting->GetNeighbourNode(Direction::Right) != nullptr)
	{
		forDeleting->GetNeighbourNode(Direction::Right)->SetNeighbourNode(nullptr, Direction::Right);
	}
	if (forDeleting->GetNeighbourNode(Direction::Down) != nullptr)
	{
		forDeleting->GetNeighbourNode(Direction::Down)->SetNeighbourNode(nullptr, Direction::Down);
	}
	delete forDeleting;
}
//
void RoadGraph::GraphStatusUpdate(PointCoord nodeLocation, bool addOrDelete)
{
	if (addOrDelete)
	{
		AddNode(nodeLocation);
	}
	else
	{
		DeleteNode(nodeLocation);
	}
}
void RoadGraph::EraseAllNodes()
{
	for (auto everyNode : allNodes)
	{
		delete everyNode;
	}
}
void RoadGraph::BuildGraph(vector<PointCoord> allRoadsLocations)
{
	for (PointCoord everyRoadLocation : allRoadsLocations)
	{
		AddNode(everyRoadLocation);
	}
}
int RoadGraph::GetNodePosition(Node* someNode) const
{
	if (someNode == nullptr)
	{
		return -1;
	}
	int index = 0;
	for (auto everyNode : allNodes)
	{
		if (everyNode == someNode)
		{
			return index;
		}
		++index;
	}
	throw MyException("RoadGraph::GetNodePosition(Node* someNode) const someNode is out of graph");
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
	int neighbourNodeIndex = 0;
	auto node = allNodes.begin();
	for (auto& column : matrix)
	{
		neighbourNodeIndex = GetNodePosition((*node)->GetNeighbourNode(Direction::Left));
		if (neighbourNodeIndex != -1)
		{
			column.at(neighbourNodeIndex) = 1;
		}
		neighbourNodeIndex = GetNodePosition((*node)->GetNeighbourNode(Direction::Up));
		if (neighbourNodeIndex != -1)
		{
			column.at(neighbourNodeIndex) = 1;
		}
		neighbourNodeIndex = GetNodePosition((*node)->GetNeighbourNode(Direction::Right));
		if (neighbourNodeIndex != -1)
		{
			column.at(neighbourNodeIndex) = 1;
		}
		neighbourNodeIndex = GetNodePosition((*node)->GetNeighbourNode(Direction::Down));
		if (neighbourNodeIndex != -1)
		{
			column.at(neighbourNodeIndex) = 1;
		}
		advance(node, 1);
	}
}