#include "Coord and constants.h"
///////////////PointCoord Struct///////////////
//UChar32 ucharrrrrrrrrrrr = 'a';
int PointCoord::get_x() const
{
	return x_coord;
}
int PointCoord::get_y() const
{
	return y_coord;
}
void PointCoord::set_coord(int x, int y)
{
	x_coord = x;
	y_coord = y;
}
void PointCoord::set_coord(PointCoord pc)
{
	x_coord = pc.get_x();
	y_coord = pc.get_y();
}
bool PointCoord::operator == (PointCoord pc)
{
	return (x_coord == pc.x_coord && y_coord == pc.y_coord);
}
/////////////Construction Options Class : Singleton patern/////////////
///////////////Ice Cream Shop Initialisation Constants///////////////
const int ConstructionOptions::getIceCreamShopHeightAdd() const
{
	return 1;
}
const int ConstructionOptions::getIceCreamShopWidthAdd() const
{
	return 1;
}
const int ConstructionOptions::getIceCreamShopCost() const
{
	return 250;
}
const int ConstructionOptions::getIceCreamShopExpences() const
{
	return 20;
}
const string ConstructionOptions::getIceCreamShopDescription() const
{
	return "Ice cream! Everybody loves it!";
}
const char ConstructionOptions::getIceCreamShopSymbol() const
{
	return '!';
}
///////////////Icon Initialisation Constants, it has no size///////////////
const int ConstructionOptions::getMenuElementBordersHeight() const
{
	return 6;
}
///////////////Road Initialisation Constants///////////////
const int ConstructionOptions::getRoadHeightAdd() const
{
	return 0;
}
const int ConstructionOptions::getRoadWidthAdd() const
{
	return 0;
}
const int ConstructionOptions::getRoadCost() const
{
	return 20;
}
const string ConstructionOptions::getRoadDescription() const
{
	return "Visitors can walk roads only";
}
///////////////Visitor Initialisation Constants///////////////
const int ConstructionOptions::getVisitorHeightAdd() const
{
	return 0;
}
const int ConstructionOptions::getVisitorWidthAdd() const
{
	return 0;
}
///////////////VisibleMap UpperLeft Coord, height and width///////////////
const PointCoord ConstructionOptions::getVisibleMapInitialCoordUL() const
{
	return PointCoord(1, 1);
}
const int ConstructionOptions::getVisibleMapHeight() const
{
	return 34;
}
const int ConstructionOptions::getVisibleMapWidth() const
{
	return 69;
}
///////////////SideMenu Width Constant///////////////
const int ConstructionOptions::getMenuHeightAdd() const
{
	return 34;
}
const int ConstructionOptions::getMenuWidthAdd() const
{
	return 45;
}
///////////////Construction Options Initialisation and using///////////////
ConstructionOptions* ConstructionOptions::ConstructionParameters = new ConstructionOptions();
ConstructionOptions* ConstructionOptions::getAllOptions()
{
	return ConstructionParameters;
}
const char ConstructionOptions::getIceCreamShopIconSymbol() const
{
	return '!';
}
const char ConstructionOptions::getRoadIconSymbol() const
{
	return '+';
}