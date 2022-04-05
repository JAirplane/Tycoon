#pragma once
#include "GraphStatusSubjectInterface.h"
class Road;
//notifies observers about construction graph status changing
class GraphStatusObserverInterface
{
public:
	virtual ~GraphStatusObserverInterface() {};
	virtual void GraphStatusUpdate(vector<pair<pair<int, int>, Direction> > neighbourLinks) = 0;
	virtual void GraphStatusUpdate(int index) = 0;
};