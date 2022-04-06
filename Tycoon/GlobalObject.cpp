#include "GlobalObject.h"
///////////////Parent Class of All Objects///////////////
PointCoord GlobalObject::GetUpperLeft() const
{
	return upperLeft;
}
void GlobalObject::SetUpperLeft(PointCoord point)
{
	upperLeft.SetCoord(point.Get_x(), point.Get_y());
}
int GlobalObject::GetHeightAddition() const
{
	return heightAddition;
}
void GlobalObject::SetHeightAddition(const int heightAdd)
{
	heightAddition = heightAdd;
}
int GlobalObject::GetWidthAddition() const
{
	return widthAddition;
}
void GlobalObject::SetWidthAddition(const int widthAdd)
{
	widthAddition = widthAdd;
}
int GlobalObject::GetHalfXAxis() const
{
	return GetUpperLeft().Get_x() + GetWidthAddition() / 2;
}
int GlobalObject::GetHalfYAxis() const
{
	return GetUpperLeft().Get_y() + GetHeightAddition() / 2;
}
bool GlobalObject::VisibleOutsidePlayingfield() const
{
	return false;
}