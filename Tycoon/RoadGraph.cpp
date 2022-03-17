#include "RoadGraph.h"
//Class Node : Parent
const Road* Node::GetVertex() const
{
	return roadVertex;
}
//Class SideNode : Node Derived
int SideNode::GetDistanceToRoot() const
{
	return distanceToRoot;
}
void SideNode::AddPath(vector<const Road*> path, int distance)
{
	pathFromRoot = path;
	distanceToRoot = distance;
}
void SideNode::ClearPath()
{
	while (!pathFromRoot.empty())
	{
		pathFromRoot.pop_back();
	}
	distanceToRoot = 0;
}
void SideNode::ResetPathCapacity()
{
	vector<const Road*> empty;
	empty.swap(pathFromRoot);
}
//Class RootNode : Node Derived
SideNode* RootNode::GetSideNode(Direction sideNodeDirection)
{
	switch (sideNodeDirection)
	{
	case Direction::Left: {return leftVertex; }
	case Direction::Up: {return topVertex; }
	case Direction::Right: {return rightVertex; }
	case Direction::Down: {return bottomVertex; }
	default: {throw MyException("RootNode::GetSideNode(Direction sideNodeDirection) bad direction"); }
	}
}
SideNode* RootNode::CreateSideNode(Direction side, const Road* vertex_ptr)
{
	if (vertex_ptr == nullptr)
	{
		throw MyException("RootNode::CreateSideNode(Direction side, Construction* vertex_ptr) got nullptr Construction*.");
	}
	switch (side)
	{
	case Direction::Left: {leftVertex = new SideNode(vertex_ptr); return leftVertex; }
	case Direction::Up: {topVertex = new SideNode(vertex_ptr); return topVertex; }
	case Direction::Right: {rightVertex = new SideNode(vertex_ptr); return rightVertex; }
	case Direction::Down: {bottomVertex = new SideNode(vertex_ptr); return bottomVertex; }
	default: {throw MyException("RootNode::CreateSideNode(Direction side, Construction* vertex_ptr) bad Direction."); }
	}
}
void RootNode::DeleteSideNode(Direction side)
{
	switch (side)
	{
	case Direction::Left: {delete leftVertex; leftVertex = nullptr; return; }
	case Direction::Up: {delete topVertex; topVertex = nullptr; return; }
	case Direction::Right: {delete rightVertex; rightVertex = nullptr; return; }
	case Direction::Down: {delete bottomVertex; bottomVertex = nullptr; return; }
	default: {throw MyException("RootNode::DeleteSideNode(Direction side) bad Direction."); }
	}
}
Direction RootNode::DeleteSideNode(const Road* vertex_ptr)
{
	if (vertex_ptr == nullptr)
	{
		throw MyException("RootNode::DeleteSideNode(Construction* vertex_ptr) got nullptr Construction*.");
	}
	if (vertex_ptr->GetUpperLeft() == leftVertex->GetVertex()->GetUpperLeft())
	{
		delete leftVertex;
		leftVertex = nullptr;
		return Direction::Left;
	}
	else if (vertex_ptr->GetUpperLeft() == topVertex->GetVertex()->GetUpperLeft())
	{
		delete topVertex;
		topVertex = nullptr;
		return Direction::Up;
	}
	else if (vertex_ptr->GetUpperLeft() == rightVertex->GetVertex()->GetUpperLeft())
	{
		delete rightVertex;
		rightVertex = nullptr;
		return Direction::Right;
	}
	else if (vertex_ptr->GetUpperLeft() == bottomVertex->GetVertex()->GetUpperLeft())
	{
		delete bottomVertex;
		bottomVertex = nullptr;
		return Direction::Down;
	}
	else
	{
		return Direction::None;
	}
}
PointCoord RootNode::GetFirstPathElementCoord(Direction pathDirection) const
{
	switch (pathDirection)
	{
	case Direction::Left: {return PointCoord(GetVertex()->GetUpperLeft().Get_x() - 1, GetVertex()->GetUpperLeft().Get_y()); }
	case Direction::Up: {return PointCoord(GetVertex()->GetUpperLeft().Get_x(), GetVertex()->GetUpperLeft().Get_y() - 1); }
	case Direction::Right: {return PointCoord(GetVertex()->GetUpperLeft().Get_x() + 1, GetVertex()->GetUpperLeft().Get_y()); }
	case Direction::Down: {return PointCoord(GetVertex()->GetUpperLeft().Get_x(), GetVertex()->GetUpperLeft().Get_y() + 1); }
	default: {throw MyException("RootNode::GetFirstPathElementCoord(Direction pathDirection) const bad direction"); }
	}
}
bool RootNode::AddSideNode(const Road* pathElement, vector<const Road*>& path, int& distance, Direction pathDirection) //returns true if we received and create SideNode
{
	if (pathElement == nullptr)
	{
		throw MyException("RootNode::AddSideNode(const Construction* pathElement, vector<const Construction*>& path, int distance, Direction pathDirection) got nullptr pathElement.");
	}
	++distance;
	if (pathElement->GetGraphStatus())
	{
		SideNode* sNode_ptr = CreateSideNode(pathDirection, pathElement);
		sNode_ptr->AddPath(path, distance);
		return true;
	}
	else
	{
		path.push_back(pathElement);
		return false;
	}
}
//Class RoadGraph
void RoadGraph::GraphStatusUpdate(Road* graphStatusChanged_ptr, const list<Road*>& roads)
{
	if (graphStatusChanged_ptr->GetGraphStatus())
	{
		RootNode* newRoot_ptr = AddRootNode(graphStatusChanged_ptr);
		FillAllPathes(newRoot_ptr, roads);
		for (auto rootNode : graph)
		{
			if (rootNode->GetVertex() == newRoot_ptr->GetSideNode(Direction::Left)->GetVertex() && rootNode != newRoot_ptr)
			{
				FillPathToSideNode(rootNode, Direction::Right, roads);
			}
			if (rootNode->GetVertex() == newRoot_ptr->GetSideNode(Direction::Up)->GetVertex() && rootNode != newRoot_ptr)
			{
				FillPathToSideNode(rootNode, Direction::Down, roads);
			}
			if (rootNode->GetVertex() == newRoot_ptr->GetSideNode(Direction::Right)->GetVertex() && rootNode != newRoot_ptr)
			{
				FillPathToSideNode(rootNode, Direction::Left, roads);
			}
			if (rootNode->GetVertex() == newRoot_ptr->GetSideNode(Direction::Down)->GetVertex() && rootNode != newRoot_ptr)
			{
				FillPathToSideNode(rootNode, Direction::Up, roads);
			}
		}
	}
	else
	{
		int sideNodeDeletedCounter = 0;
		for (auto rootNode : graph)
		{
			Direction deletedSideNode = rootNode->DeleteSideNode(graphStatusChanged_ptr);
			if (deletedSideNode != Direction::None)
			{
				++sideNodeDeletedCounter;
				FillPathToSideNode(rootNode, deletedSideNode, roads);
			}
			if (sideNodeDeletedCounter == 4)
			{
				break;
			}
		}
		DeleteRootNode(graphStatusChanged_ptr);
	}
}
RootNode* RoadGraph::CreateRootNode(const Road* vertex_ptr)
{
	RootNode* root_ptr = new RootNode(vertex_ptr);
	graph.push_back(root_ptr);
	return root_ptr;
}
void RoadGraph::DeleteRootNode(const Road* vertex_ptr)
{
	if (vertex_ptr == nullptr)
	{
		throw MyException("RoadGraph::DeleteRootNode(Construction* vertex_ptr) got nullptr Construction*.");
	}
	auto IsEqual = [vertex_ptr](RootNode* graphElement) -> bool
	{
		return vertex_ptr->GetUpperLeft() == graphElement->GetVertex()->GetUpperLeft();
	};
	graph.remove_if(IsEqual);
}
RootNode* RoadGraph::AddRootNode(const Road* vertex_ptr)
{
	if (vertex_ptr == nullptr)
	{
		throw MyException("RoadGraph::AddRootNode(Construction* vertex_ptr) got nullptr Construction*.");
	}
	if (vertex_ptr->GetGraphStatus() != true)
	{
		throw MyException("RoadGraph::AddRootNode(Construction* vertex_ptr) road is not graph.");
	}
	for (auto element : graph)
	{
		if (element->GetVertex()->GetUpperLeft() == vertex_ptr->GetUpperLeft())
		{
			throw MyException("RoadGraph::AddRootNode(Construction* vertex_ptr) addition of existing element.");
		}
	}
	RootNode* root_ptr = CreateRootNode(vertex_ptr);
	return root_ptr;
}
const Road* RoadGraph::FindNextPathPoint(PointCoord leftPoint, PointCoord upperPoint, PointCoord rightPoint, PointCoord downPoint, PointCoord previousPathElement, const list<Road*>& roads)
{
	if (roads.empty())
	{
		throw MyException("RoadGraph::FindNextPathPoint(PointCoord leftPoint, PointCoord upperPoint, PointCoord rightPoint, PointCoord downPoint, PointCoord previousPathElement, const list<Road*>& roads) got empty road list.");
	}
	for (auto roadElement : roads)
	{
		if ((roadElement->GetUpperLeft() == leftPoint || roadElement->GetUpperLeft() == upperPoint || roadElement->GetUpperLeft() == rightPoint ||
			roadElement->GetUpperLeft() == downPoint) && roadElement->GetUpperLeft() != previousPathElement)
		{
			return roadElement;
		}
	}
	return nullptr;
}
void RoadGraph::FillPathToSideNode(RootNode* node_ptr, Direction pathDirection, const list<Road*>& roads)
{
	if (roads.empty())
	{
		throw MyException("RoadGraph::FillPathToSideNode(const RootNode* node_ptr, Direction pathDirection, const list<Road*>& roads) got empty road list.");
	}
	if (node_ptr == nullptr)
	{
		throw MyException("RoadGraph::FillPathToSideNode(const RootNode* node_ptr, Direction pathDirection, const list<Road*>& roads) got nullptr RootNode.");
	}
	if (pathDirection == Direction::None)
	{
		return;
	}
	PointCoord leftPoint = node_ptr->GetFirstPathElementCoord(pathDirection); //any direction for first element and then left possible path element
	PointCoord upperPoint = PointCoord(numeric_limits<int>::max(), numeric_limits<int>::max());
	PointCoord rightPoint = PointCoord(numeric_limits<int>::max(), numeric_limits<int>::max());
	PointCoord downPoint = PointCoord(numeric_limits<int>::max(), numeric_limits<int>::max());
	PointCoord previousPathElement = node_ptr->GetVertex()->GetUpperLeft();
	vector<const Road*> path;
	int distance = 0; //minimum distance is equal to 1, every non-graph road tile adds 1 to it
	const Road* pathElement = FindNextPathPoint(leftPoint, upperPoint, rightPoint, downPoint, previousPathElement, roads);
	if (pathElement != nullptr)
	{
		if (node_ptr->AddSideNode(pathElement, path, distance, pathDirection))
		{
			return; //means end 
		}
		previousPathElement = node_ptr->GetVertex()->GetUpperLeft();
		leftPoint = PointCoord(pathElement->GetUpperLeft().Get_x() - 1, pathElement->GetUpperLeft().Get_y());
		upperPoint = PointCoord(pathElement->GetUpperLeft().Get_x(), pathElement->GetUpperLeft().Get_y() - 1);
		rightPoint = PointCoord(pathElement->GetUpperLeft().Get_x() + 1, pathElement->GetUpperLeft().Get_y());
		downPoint = PointCoord(pathElement->GetUpperLeft().Get_x(), pathElement->GetUpperLeft().Get_y() + 1);
	}
	else
	{
		return; //means there is no path in this direction from rootNode
	}
	for (auto roadElement : roads)
	{
		pathElement = FindNextPathPoint(leftPoint, upperPoint, rightPoint, downPoint, previousPathElement, roads);
		if (pathElement != nullptr)
		{
			if (node_ptr->AddSideNode(pathElement, path, distance, pathDirection))
			{
				return;
			}
			previousPathElement = (path.rbegin()[1])->GetUpperLeft(); //being here means that we add at least two elements to our path vector
			leftPoint = PointCoord(roadElement->GetUpperLeft().Get_x() - 1, roadElement->GetUpperLeft().Get_y());
			upperPoint = PointCoord(roadElement->GetUpperLeft().Get_x(), roadElement->GetUpperLeft().Get_y() - 1);
			rightPoint = PointCoord(roadElement->GetUpperLeft().Get_x() + 1, roadElement->GetUpperLeft().Get_y());
			downPoint = PointCoord(roadElement->GetUpperLeft().Get_x(), roadElement->GetUpperLeft().Get_y() + 1);
			roadElement = *(roads.begin());
		}
	}
}
void RoadGraph::FillAllPathes(RootNode* node_ptr, const list<Road*>& roads)
{
	if (node_ptr == nullptr)
	{
		throw MyException("RoadGraph::FillPathToSideNodes(const RootNode* node_ptr, const list<Road*>& roads) got RootNode nullptr.");
	}
	if (roads.empty())
	{
		throw MyException("RoadGraph::FillPathToSideNodes(const RootNode* node_ptr, const list<Road*>& roads) got empty road list.");
	}
	int mask = node_ptr->GetVertex()->GetMaskPartRealRoads(roads);
	if (mask & leftside)
	{
		FillPathToSideNode(node_ptr, Direction::Left, roads);
	}
	if (mask & topside)
	{
		FillPathToSideNode(node_ptr, Direction::Up, roads);
	}
	if (mask & rightside)
	{
		FillPathToSideNode(node_ptr, Direction::Right, roads);
	}
	if (mask & bottomside)
	{
		FillPathToSideNode(node_ptr, Direction::Down, roads);
	}
}
//vector<Road*> RoadGraph::GetNodesOfThePath(PointCoord currentLocation, Road* destination) const //this works only if current location is a graph node
//{
//	vector<Road*> pathNodes;
//	for (auto node : graph)
//	{
//
//	}
//}