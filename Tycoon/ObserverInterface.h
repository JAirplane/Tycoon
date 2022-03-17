#pragma once
#include "IngameObjectDerived.h"
//notifies observers about some events with a string message
class MessageObserverInterface
{
public:
	virtual ~MessageObserverInterface() {};
	virtual void UserMessageUpdate(const string message) = 0;
};
class MessageSubjectInterface
{
public:
	virtual ~MessageSubjectInterface() {};
	virtual void UserMessageAttach(MessageObserverInterface* observer) = 0;
	virtual void UserMessageDetach(MessageObserverInterface* observer) = 0;
	virtual void UserMessageNotify(const string message) = 0;
};
//notifies observers about construction, choosen by user
class ConstructionInfoObserverInterface
{
public:
	virtual ~ConstructionInfoObserverInterface() {};
	virtual void ChosenConstructionUpdate(Construction* choosen_ptr) = 0;
};
class ConstructionInfoSubjectInterface
{
public:
	virtual ~ConstructionInfoSubjectInterface() {};
	virtual void ChosenConstructionAttach(ConstructionInfoObserverInterface* observer) = 0;
	virtual void ChosenConstructionDetach(ConstructionInfoObserverInterface* observer) = 0;
	virtual void ChosenConstructionNotify(Construction* choosenConstruction_ptr) = 0;
};

