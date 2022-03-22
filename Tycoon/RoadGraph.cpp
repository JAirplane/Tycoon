#include "RoadGraph.h"
//Class Node
int Node::GetNodeIndex() const
{
	return index;
}
void Node::SetNodeIndex(int newIndex)
{
	index = newIndex;
}
PointCoord Node::GetNodeLocation() const
{
	return nodeLocation;
}
void Node::SetNodeLocation(PointCoord anotherLocation)
{
	nodeLocation = anotherLocation;
}
//Class Edge
int Edge::GetStartingIndex() const
{
	return startingNodeIndex;
}
void Edge::SetStartingIndex(int newIndex)
{
	startingNodeIndex = newIndex;
}
int Edge::GetEndingIndex() const
{
	return endingNodeIndex;
}
void Edge::SetEndingIndex(int newIndex)
{
	endingNodeIndex = newIndex;
}
//Class RoadGraph
Node* RoadGraph::AddNode(PointCoord location)
{
	if (FindNode(location) == nullptr)
	{
		Node* newNode_ptr = new Node(location);
		newNode_ptr->nodeIndex = allNodes.size() + 1;
		allNodes.push_back(newNode_ptr);
		return newNode_ptr;
	}
	return nullptr;
}
void RoadGraph::DeleteNode(PointCoord location)
{
	auto IsEqual = [&](Node* element) -> bool
	{
		return location == element->nodePoint;
	};
	allNodes.remove_if(IsEqual);
}
void RoadGraph::DeleteNode(int index)
{
	auto IsEqual = [index](Node* element) -> bool
	{
		return index == element->nodeIndex;
	};
	allNodes.remove_if(IsEqual);
}
Edge* RoadGraph::AddEdge(PointCoord startPoint, PointCoord endPoint)
{
	if (FindNode(startPoint) == nullptr)
	{
		throw MyException("RoadGraph::AddEdge(PointCoord startPoint, PointCoord endPoint) startPoint is nullptr");
	}
	if (FindNode(startPoint) == nullptr)
	{
		throw MyException("RoadGraph::AddEdge(PointCoord startPoint, PointCoord endPoint) endPoint is nullptr");
	}
	Node* startNode = FindNode(startPoint);
	Node* endNode = FindNode(endPoint);
	if (FindEdge(startNode->nodeIndex, endNode->nodeIndex) == nullptr)
	{
		Edge* newEdge = new Edge(FindNode(startPoint)->nodeIndex, FindNode(endPoint)->nodeIndex);
		allEdges.push_back(newEdge);
		return newEdge;
	}
	return nullptr;
}
void RoadGraph::DeleteEdge(int startIndex, int endIndex)
{
	auto IsEqual = [=](Edge* element) -> bool
	{
		return (startIndex == element->startingIndex && endIndex == element->endingIndex);
	};
	allEdges.remove_if(IsEqual);
}
void RoadGraph::DeleteEdges(int index) //we need only begining or ending to delete edge as node no longer exist
{
	auto IsEqual = [index](Edge* element) -> bool
	{
		return (index == element->startingIndex || index == element->endingIndex);
	};
	allEdges.remove_if(IsEqual);
}
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
Node* RoadGraph::FindNode(int index)
{
	for (auto someNode : allNodes)
	{
		if (someNode->nodeIndex == index)
		{
			return someNode;
		}
	}
	return nullptr;
}
Edge* RoadGraph::FindEdge(int startIndex, int endIndex)
{
	for (auto someEdge : allEdges)
	{
		if (someEdge->startingIndex == startIndex && someEdge->endingIndex == endIndex)
		{
			return someEdge;
		}
	}
	return nullptr;
}
void RoadGraph::UpdateAllIndices()
{
	int newIndex = 1;
	for (auto everyNode : allNodes)
	{
		int oldIndex = everyNode->nodeIndex;
		everyNode->nodeIndex = newIndex;
		for (auto everyEdge : allEdges)
		{
			if (everyEdge->startingIndex == oldIndex)
			{
				everyEdge->startingIndex = newIndex;
			}
			else if (everyEdge->endingIndex == oldIndex)
			{
				everyEdge->endingIndex = newIndex;
			}
			else { break; }
		}
		++newIndex;
	}
}


//void RoadGraph::GraphStatusUpdate(Road* graphStatusChanged_ptr, const list<Road*>& roads)
//{
//	if (graphStatusChanged_ptr->GetGraphStatus())
//	{
//		RootNode* newRoot_ptr = AddRootNode(graphStatusChanged_ptr);
//		FillAllPathes(newRoot_ptr, roads);
//		for (auto rootNode : graph)
//		{
//			if (rootNode->GetVertex() == newRoot_ptr->GetSideNode(Direction::Left)->GetVertex() && rootNode != newRoot_ptr)
//			{
//				FillPathToSideNode(rootNode, Direction::Right, roads);
//			}
//			if (rootNode->GetVertex() == newRoot_ptr->GetSideNode(Direction::Up)->GetVertex() && rootNode != newRoot_ptr)
//			{
//				FillPathToSideNode(rootNode, Direction::Down, roads);
//			}
//			if (rootNode->GetVertex() == newRoot_ptr->GetSideNode(Direction::Right)->GetVertex() && rootNode != newRoot_ptr)
//			{
//				FillPathToSideNode(rootNode, Direction::Left, roads);
//			}
//			if (rootNode->GetVertex() == newRoot_ptr->GetSideNode(Direction::Down)->GetVertex() && rootNode != newRoot_ptr)
//			{
//				FillPathToSideNode(rootNode, Direction::Up, roads);
//			}
//		}
//	}
//	else
//	{
//		int sideNodeDeletedCounter = 0;
//		for (auto rootNode : graph)
//		{
//			Direction deletedSideNode = rootNode->DeleteSideNode(graphStatusChanged_ptr->GetVertex());
//			if (DeleteSideNode() != Direction::None)
//			{
//				++sideNodeDeletedCounter;
//				FillPathToSideNode(rootNode, deletedSideNode, roads);
//			}
//			if (sideNodeDeletedCounter == 4)
//			{
//				break;
//			}
//		}
//		DeleteRootNode(graphStatusChanged_ptr);
//	}
//}
// void RoadGraph::FillAllPathes(RootNode* node_ptr, const list<Road*>& roads)
// {
	// if (node_ptr == nullptr)
	// {
		// throw MyException("RoadGraph::FillPathToSideNodes(const RootNode* node_ptr, const list<Road*>& roads) got RootNode nullptr.");
	// }
	// if (roads.empty())
	// {
		// throw MyException("RoadGraph::FillPathToSideNodes(const RootNode* node_ptr, const list<Road*>& roads) got empty road list.");
	// }
	// int mask = node_ptr->GetVertex()->GetMaskPartRealRoads(roads);
	// if (mask & leftside)
	// {
		// FillPathToSideNode(node_ptr, Direction::Left, roads);
	// }
	// if (mask & topside)
	// {
		// FillPathToSideNode(node_ptr, Direction::Up, roads);
	// }
	// if (mask & rightside)
	// {
		// FillPathToSideNode(node_ptr, Direction::Right, roads);
	// }
	// if (mask & bottomside)
	// {
		// FillPathToSideNode(node_ptr, Direction::Down, roads);
	// }
// }