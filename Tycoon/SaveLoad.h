#pragma once
#include "Display.h"
class SaveLoad
{
public:
	SaveLoad() {}
	virtual ~SaveLoad() {}

	//
	void SaveGame(const GameStats* stats, vector<Construction*> allBuildings, vector<Construction*> allRoads, vector<Visitor*> allVisitors);
	void FillGlobalObjectNodePart(GlobalObject* gameObject, pugi::xml_node& objectNode);
	void FillConstructionNodePart(Construction* gameObject, pugi::xml_node& objectNode);
	void FillBuildingNodePart(Construction* gameObject, pugi::xml_node& objectNode);
	void FillVisitorNodePart(Visitor* person, pugi::xml_node& objectNode);
	void AddBuildingNode(Construction* buildingForSave, pugi::xml_node& buildings);
	void AddRoadNode(Construction* roadForSave, pugi::xml_node& roads);
	void AddVisitorNode(Visitor* visitorForSave, pugi::xml_node& visitors);
};