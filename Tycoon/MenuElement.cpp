#include "MenuElement.h"
/////////////Menu Element Class/////////////
MyRectangle* MenuElement::GetIcon() const
{
	return icon_ptr;
}
ConstructionManager* MenuElement::GetManager() const
{
	return manager_ptr;
}