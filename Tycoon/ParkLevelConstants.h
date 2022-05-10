#pragma once
#include <vector>
#include "pugixml.hpp"
#include "MyException.h"
class Level
{
public:
	Level(int lvlNumber, int maxBuildings, int maxVisitors, int visitorMoneyFormulaValue)
	{
		this->lvlNumber = lvlNumber;
		this->maxBuildings = maxBuildings;
		this->maxVisitors = maxVisitors;
		this->visitorMoneyFormulaValue = visitorMoneyFormulaValue;
	}
	virtual ~Level() {}
	int GetLvlNumber() const;
	int GetMaxBuildings() const;
	int GetMaxVisitors() const;
	int GetVisitorMoneyFormulaValue() const;
	__declspec(property(get = GetLvlNumber)) int level;
	__declspec(property(get = GetMaxBuildings)) int maximumBuildings;
	__declspec(property(get = GetMaxVisitors)) int maximumVisitors;
	__declspec(property(get = GetVisitorMoneyFormulaValue)) int moneyFormulaValue;
private:
	int lvlNumber;
	int maxBuildings;
	int maxVisitors;
	int visitorMoneyFormulaValue;
};
class ParkLevelConstants
{
public:
	ParkLevelConstants()
	{
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_file("ParkLevelConstants.xml");
		if (!result)
		{
			string msg = "XML [ParkLevelConstants.xml] parsed with errors. ";
			msg.append("Error description: ");
			msg.append(result.description());
			throw MyException(msg);
		}
		pugi::xml_node levels = doc.child("parkLevels");
		for (pugi::xml_node level = levels.child("level"); level; level = level.next_sibling("level"))
		{
			int lvlNumber = level.attribute("lvlNumber").as_int();
			int maxBuildings = atoi(level.child_value("maxBuildingsQuantity"));
			int maxVisitors = atoi(level.child_value("maxVisitorsQuantity"));
			int visitorMoneyFormulaValue = atoi(level.child_value("visitorMoneyFormulaConstant"));
			Level* levelConstant = new Level(lvlNumber, maxBuildings, maxVisitors, visitorMoneyFormulaValue);
			lvls.push_back(levelConstant);
		}
	}
	virtual ~ParkLevelConstants()
	{
		for (auto lvl : lvls)
		{
			delete lvl;
		}
	}
	ParkLevelConstants(ParkLevelConstants& other) = delete;
	void operator=(const ParkLevelConstants&) = delete;
	static ParkLevelConstants* UploadParkConstants();
	static const ParkLevelConstants* GetConstantsPointer();
	const vector<Level*> GetAllConstants() const;
protected:
	static ParkLevelConstants* parkConstants;
private:
	vector<Level*> lvls;
};
