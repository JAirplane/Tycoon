#include "VisitorManager.h"
Visitor* VisitorManager::CreateVisitor(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr, int parkLevel)
{
	Visitor* vis_ptr = new Visitor(upperLeft, paint_ptr, description_ptr, parkLevel);
	allObjects_ptr->AddObject(vis_ptr);
	return vis_ptr;
}