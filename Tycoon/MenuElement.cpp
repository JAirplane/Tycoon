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
void MenuElement::Draw() const
{
	this->DrawBorder();
	this->GetIcon()->DrawBorder();
	this->GetDrawPointer()->DrawMenuElementContent(icon_ptr->GetUpperLeft().Get_x() + 1, icon_ptr->GetUpperLeft().Get_y() + 1, manager_ptr->GetDescriptor()->GetConstructionCost(),
		manager_ptr->GetDescriptor()->GetDailyExpences(), manager_ptr->GetDescriptor()->GetIconSymbol(), manager_ptr->GetDescriptor()->GetDescription(),
		manager_ptr->GetDescriptor()->GetForegroundColor(), manager_ptr->GetDescriptor()->GetConnectedBackgroundColor());
}
void MenuElement::Shift(IconsPosition upperOrLower)
{
	PointCoord currentLocation = this->GetUpperLeft();
	switch (upperOrLower)
	{
		case IconsPosition::UPPER:
		{this->SetUpperLeft(PointCoord(currentLocation.Get_x(), currentLocation.Get_y() + this->GetHeightAddition() + 1)); break;}
		case IconsPosition::LOWER:
		{this->SetUpperLeft(PointCoord(currentLocation.Get_x(), currentLocation.Get_y() - this->GetHeightAddition() - 1)); break;}
		default: {throw MyException("MenuElement::Shift(IconsPosition upperOrLower) bad IconsPosition argument."); }
	}
	icon_ptr->SetUpperLeft(PointCoord(currentLocation.Get_x() + 1, this->GetUpperLeft().Get_y() + 1));
	manager_ptr->GetDescriptor()->SetMenuElementLocation(this->GetUpperLeft());
}