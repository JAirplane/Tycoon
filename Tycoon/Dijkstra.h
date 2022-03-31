#pragma once
#include "IngameObjectDerived.h"
class DijkstraAlgorithm
{
private:
	static int GetClosestUnvisitedVertexIndex(vector<int> distances, vector<bool> visitedVertices);
public:
	DijkstraAlgorithm() {}
	~DijkstraAlgorithm() {}
	static vector<int> GetDistances(vector<vector<int> > weightMatrix, int startNodeIndex);
};