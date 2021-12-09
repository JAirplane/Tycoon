#pragma once
#include "Cursor.h"
/////////////Parent Class of All Objects/////////////
class GlobalObject
{
private:
	PointCoord UpperLeft;
	unsigned int HeightAddition;
	unsigned int WidthAddition;
public:
	GlobalObject(PointCoord ul, unsigned int _heightadd = 0, unsigned int _widthadd = 0) : UpperLeft(ul), HeightAddition(_heightadd), WidthAddition(_widthadd)
	{}
	~GlobalObject()
	{}
	PointCoord getUpperLeft() const;
	void setUpperLeft(PointCoord _pc);
	unsigned int getHeightAddition() const;
	void setHeightAddition(const int _ha);
	unsigned int getWidthAddition() const;
	void setWidthAddition(const int _wa);
};
class ConstructionManager;
/////////////Parent Class of Every Object in Game/////////////
class IngameObject : public GlobalObject
{
public:
	IngameObject(PointCoord ul, unsigned int _heightadd = 0, unsigned int _widthadd = 0) : GlobalObject(ul, _heightadd, _widthadd)
	{}
	virtual ConstructionManager* getManager() const;
};
