#include "VisitorManager.h";
Visitor* VisitorManager::CreateVisitor(PointCoord upperLeft, Visualisation* paint_ptr, AllObjects* allObjects_ptr)
{
	Visitor* vis_ptr = new Visitor(upperLeft, paint_ptr, description_ptr);
	allObjects_ptr->AddObject(vis_ptr);
	return vis_ptr;
}