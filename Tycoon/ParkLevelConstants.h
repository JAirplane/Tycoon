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
	~Level() {}
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
		if (result)
		{
			string msg = "XML [ParkLevelConstants.xml] parsed without errors, attr value: [";
			msg.append(doc.child("node").attribute("attr").value());
			msg.append("]");
			throw MyException(msg);
		}
		else
		{
			string msg = "XML [ParkLevelConstants.xml] parsed with errors. ";
			msg.append("Error description: ");
			msg.append(result.description());
			cout << msg;
			throw MyException(msg);
		}
	}
	~ParkLevelConstants()
	{

	}
	/*static void CreateParkConstants()
	{
		ParkLevelConstants::parkConstants = new ParkLevelConstants();
	}*/
protected:
	static ParkLevelConstants* parkConstants;
private:
	vector<Level*> lvls;
};

