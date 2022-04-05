#include "Dijkstra.h"
int DijkstraAlgorithm::GetClosestUnvisitedVertexIndex(vector<int> distances, vector<bool> visitedVertices)
{
	int dimension = distances.size();
	if (dimension == visitedVertices.size())
	{
		throw MyException("DijkstraAlgorithm::GetClosestUnvisitedVertexIndex(vector<int> distances, vector<bool> visitedVertices) dimension of vector args is different");
	}
	int minimumDistance = numeric_limits<int>::max();
	int vertexIndex = -1;
	for (int i = 0; i < dimension; i++)
	{
		if (visitedVertices.at(i) == false && distances.at(i) <= minimumDistance)
		{
			vertexIndex = i;
			minimumDistance = distances.at(i);
		}
	}
	return vertexIndex;
}
vector<int> DijkstraAlgorithm::GetDistances(vector<vector<int> > weightMatrix, int startVertexIndex)
{
	if (weightMatrix.empty())
	{
		throw MyException("DijkstraAlgorithm::GetDistances(vector<vector<int> > weightMatrix, int startVertexIndex) got empty weightMatrix");
	}
	int matrixDimension = weightMatrix.size();
	if (matrixDimension != weightMatrix.at(0).size())
	{
		throw MyException("DijkstraAlgorithm::GetDistances(vector<vector<int> > weightMatrix, int startVertexIndex) weightMatrix column isn't equal to row");
	}
	int maxPossibleDistance = numeric_limits<int>::max();
	vector<int> distances(matrixDimension, maxPossibleDistance);
	distances.at(startVertexIndex) = 0;
	vector<bool> visitedVertices(matrixDimension, false);
	for (int i = 0; i < matrixDimension; i++)
	{
		int nearestVertexIndex = GetClosestUnvisitedVertexIndex(distances, visitedVertices);
		if (nearestVertexIndex == -1)
		{
			throw MyException("DijkstraAlgorithm::GetDistances(vector<vector<int> > weightMatrix, int startVertexIndex) returns index = -1");
		}
		visitedVertices.at(nearestVertexIndex) = true;
		for (int j = 0; j < matrixDimension; j++)
		{
			if (!visitedVertices.at(j) && weightMatrix.at(nearestVertexIndex)[j] != 0 && distances.at(nearestVertexIndex) != maxPossibleDistance &&
				distances.at(nearestVertexIndex) + weightMatrix.at(nearestVertexIndex)[j] < distances.at(j))
			{
				distances.at(j) = distances.at(nearestVertexIndex) + weightMatrix.at(nearestVertexIndex)[j];
			}
		}
	}
	return distances;
}
DijkstraAlgorithm* DijkstraAlgorithm::dijkstra = new DijkstraAlgorithm();