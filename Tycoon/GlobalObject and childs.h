#pragma once
#include "Coord and constants.h"
#include "drawheader.h"
/////////////Parent Class of All Objects/////////////
class GlobalObject
{
private:
	PointCoord UpperLeft;
	unsigned int Height;
	unsigned int Width;
	bool RoadConnection;
public:
	GlobalObject(PointCoord ul) : UpperLeft(ul)
	{}
	~GlobalObject()
	{}
	PointCoord getUpperLeft() const;
	void setUpperLeft(PointCoord _pc);
	unsigned int getHeight() const;
	void setHeight(const int _h);
	unsigned int getWidth() const;
	void setWidth(const int _w);

	//virtual void DefineGraphStatus(int mask);
	//virtual string getDescription() const;
	//virtual char SetRoadSymbol(int mask) const;
	//virtual GlobalObject* CreateObject(PointCoord _pc) = 0;
};
/////////////Child Classes/////////////
/////////////Parent Class of Every Construction Type/////////////
class Construction : public GlobalObject
{
private:
	unsigned int ConstructionCost;
public:
	Construction(PointCoord _ul) : GlobalObject(_ul)
	{}
	~Construction()
	{}
	int getConstructionCost() const;
	void setConstructionCost(const int cost);
};
/////////////Menu Icon/////////////
template <typename T>
class Icon : public Construction
{
private:
	unsigned int DailyExpences;
	string description;
	char IconSymbol;
	T* construction_ptr;
public:
	Icon(PointCoord _ul, T* constr_ptr, string _desc, unsigned int _cost, unsigned int _de, char symb) : Construction(_ul);
	~Icon();
	string getDescription() const;
	void setDescription(string _desc);
	unsigned int getDailyExpences();
	void setDailyExpences(unsigned int exp);
	char getIconSymbol();
	void setIconSymbol(const char symbol);
	T* getIconsPointerType();
	Icon* CreateIcon(PointCoord _ul, T* constr_ptr, string _desc, unsigned int _cost, unsigned int _de, char symbol);
};
///////////////Icon Class: Construction derived///////////////
template <typename T>
Icon<T>::Icon(PointCoord _ul, T* constr_ptr, string _desc, unsigned int _cost, unsigned int _de, char symb) : Construction(_ul)
{
	setHeight(IconHeight);
	setWidth(IconWidth);
	setConstructionCost(_cost);
	description = _desc;
	DailyExpences = _de;
	IconSymbol = symb;
	construction_ptr = constr_ptr;
}
template <typename T>
Icon<T>::~Icon() {}
template <typename T>
string Icon<T>::getDescription() const
{
	return description;
}
template <typename T>
void Icon<T>::setDescription(string _desc)
{
	description = _desc;
}
template <typename T>
unsigned int Icon<T>::getDailyExpences()
{
	return DailyExpences;
}
template <typename T>
void Icon<T>::setDailyExpences(unsigned int exp)
{
	DailyExpences = exp;
}
template <typename T>
char Icon<T>::getIconSymbol()
{
	return IconSymbol;
}
template <typename T>
void Icon<T>::setIconSymbol(const char symbol)
{
	IconSymbol = symbol;
}
template <typename T>
Icon<T>* Icon<T>::CreateIcon(PointCoord _ul, T* constr_ptr, string _desc, unsigned int _cost, unsigned int _de, char symbol)
{
	Icon<T>* i_ptr = new Icon(_ul, constr_ptr, _desc, _cost, _de, symbol);
	return i_ptr;
}
template <typename T>
T* getIconsPointerType()
{
	return construction_ptr;
}
/////////////Parent Class of Buildings/////////////
class Building : public Construction
{
private:
	char DrawSymbol;
	unsigned int DailyExpences;
public:
	Building(PointCoord _ul) : Construction(_ul)
	{}
	unsigned int getDailyExpences() const;
	void setDailyExpences(const int _de);
	char getSymbol() const;
	void setSymbol(const char _s);
};
/////////////One Pixel of Road/////////////
class Road : public Construction
{
private:
	bool GraphStatus;
	bool RoadIsInChain;
public:
	Road(PointCoord _ul) : Construction(_ul)
	{
		setHeight(RoadHeight);
		setWidth(RoadWidth);
		GraphStatus = false;
		RoadIsInChain = false;
	}
	~Road()
	{}
	//GlobalObject* CreateObject(PointCoord _pc) override;
	char SetRoadSymbol(int mask) const;
	bool getGraphStatus() const;
	void setGraphStatus(bool status);
	void DefineGraphStatus(int mask);
	bool getRoadIsInChainStatus();
	void setRoadIsInChainStatus(bool chainflag);
};
/////////////Ice Cream Shop/////////////
class IceCreamShop : public Building
{
private:
	unsigned int LastDayVisitors;
	int LastDayProfit;
public:
	IceCreamShop(PointCoord _ul) : Building(_ul)
	{
		setHeight(IceCreamShopHeight);
		setWidth(IceCreamShopWidth);
		setConstructionCost(IceCreamShopCost);
		setDailyExpences(IceCreamShopExpences);
		LastDayVisitors = 0;
		LastDayProfit = 0;
	}
	GlobalObject* CreateObject(PointCoord _pc);
};
/////////////People are looking for some fun!/////////////
class Visitor : public GlobalObject
{
private:
	int FoodCapacity;
	int NeedToPee;
public:
	Visitor(PointCoord _ul, int fc, int ntp) : GlobalObject(_ul)
	{
		setHeight(VisitorHeight);
		setWidth(VisitorWidth);
		FoodCapacity = fc;
		NeedToPee = ntp;
	}
	~Visitor()
	{}
	void VisitorMove(int _x, int _y);
	//GlobalObject* CreateObject(PointCoord _pc) override;
};
/////////////End of Constructions Classes/////////////