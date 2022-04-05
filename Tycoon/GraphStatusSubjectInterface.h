#pragma once
#include "Camera.h"
class GraphStatusObserverInterface;
class Road;
class GraphStatusSubjectInterface
{
public:
	virtual ~GraphStatusSubjectInterface() {};
	virtual void GraphStatusAttach(GraphStatusObserverInterface* observer) = 0;
	virtual void GraphStatusDetach(GraphStatusObserverInterface* observer) = 0;
	virtual void GraphStatusNotify(vector<pair<pair<int, int>, Direction> > edges) = 0;
	virtual void GraphStatusNotify(int index) = 0;
};