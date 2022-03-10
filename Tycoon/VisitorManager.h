#pragma once
#include "IngameObjectManager.h"
class VisitorManager : public IngameObjectManager
{
private:
	VisitorDescriptor* description_ptr;
public:
	VisitorManager(VisitorDescriptor* describe_ptr)
	{
		description_ptr = describe_ptr;
	}
	~VisitorManager()
	{
		delete description_ptr;
	}
	Visitor* CreateVisitor(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr);
};

