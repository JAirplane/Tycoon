#pragma once
#include "Coord_and_constants.h"
#include <vector>
class DijkstraAlgorithm
{
private:
	static int GetClosestUnvisitedVertexIndex(vector<int> distances, vector<bool> visitedVertices);
public:
	static DijkstraAlgorithm* dijkstra;
	DijkstraAlgorithm() {}
	~DijkstraAlgorithm() 
	{
		delete dijkstra;
	}
	static vector<int> GetDistances(vector<vector<int> > weightMatrix, int startNodeIndex);
};