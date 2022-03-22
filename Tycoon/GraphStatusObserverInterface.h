#pragma once
#include "GraphStatusSubjectInterface.h"
class Road;
//notifies observers about construction graph status changing
class GraphStatusObserverInterface
{
public:
	virtual ~GraphStatusObserverInterface() {};
	virtual void GraphStatusUpdate(Road* graphStatusChanged_ptr) = 0;
};