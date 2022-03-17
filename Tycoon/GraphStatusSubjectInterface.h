#pragma once
#include "Camera.h"
#include <list>
class GraphStatusObserverInterface;
class Road;
class GraphStatusSubjectInterface
{
public:
	virtual ~GraphStatusSubjectInterface() {};
	virtual void GraphStatusAttach(GraphStatusObserverInterface* observer) = 0;
	virtual void GraphStatusDetach(GraphStatusObserverInterface* observer) = 0;
	virtual void GraphStatusNotify(const list<Road*>& roads) = 0;
};
