#pragma once

class RoadGraphNode
{
private:
	Construction* RoadVertex;
	unsigned int EdgeDistance;
public:
	RoadGraphNode(Construction* vertex, unsigned int distance = 0) : RoadVertex(vertex), EdgeDistance(distance)
	{}
	~RoadGraphNode()
	{}
	RoadGraphNode* CreateNode(Construction* vertex, unsigned int distance = 0)
	{
		RoadGraphNode* newnode_ptr = new RoadGraphNode(vertex, distance);
		return newnode_ptr;
	}
	Construction* getVertex() const
	{
		return RoadVertex;
	}
	unsigned int getDistance() const
	{
		return EdgeDistance;
	}
};
class RoadGraph
{
private:
	list<list<RoadGraphNode*> > Graph;
public:
	RoadGraph()
	{}
	~RoadGraph()
	{
		list<list<RoadGraphNode*> >::iterator externaliter;
		for (externaliter = Graph.begin(); externaliter != Graph.end(); externaliter++)
		{
			list<RoadGraphNode*> internal = *externaliter;
			list<RoadGraphNode*>::iterator internaliter;
			for (internaliter = internal.begin(); internaliter != internal.end(); internaliter++)
			{
				delete (*internaliter);
			}
		}
	}
	void addRootNode(RoadGraphNode* _rootroad)
	{
		list<RoadGraphNode*> internal;
		internal.push_back(RootRoad);
		Graph.push_back(internal);
	}
	void addNode(RoadGraphNode* _road, Construction* _rootvertex)
	{
		list<list<RoadGraphNode*> >::iterator externaliter;
		for (externaliter = Graph.begin(); externaliter != Graph.end(); externaliter++)
		{
			list<RoadGraphNode*> internal = *externaliter;
			list<RoadGraphNode*>::iterator internaliter = internal.begin();
			if ((*internaliter)->getVertex() == _rootvertex)
			{
				(*externaliter).push_back(_road);
				return;
			}
		}
	}
}