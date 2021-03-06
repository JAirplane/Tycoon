#pragma once
#include "Display.h"
class SaveLoad
{
public:
	SaveLoad() {}
	virtual ~SaveLoad() {}

	//
	void SaveGame(const GameStats* stats, const PlayingField* field, const list<Construction*>& allBuildings, const list<Construction*>& allRoads, const list<Visitor*>& allVisitors);
	void FillGlobalObjectNodePart(const GlobalObject* gameObject, pugi::xml_node& objectNode);
	void FillConstructionNodePart(const Construction* gameObject, pugi::xml_node& objectNode);
	void FillBuildingNodePart(const Construction* gameObject, pugi::xml_node& objectNode);
	void FillVisitorNodePart(const Visitor* person, pugi::xml_node& objectNode);
	void AddBuildingNode(Construction* buildingForSave, pugi::xml_node& buildings);
	void AddRoadNode(Construction* roadForSave, pugi::xml_node& roads);
	void AddVisitorNode(Visitor* visitorForSave, pugi::xml_node& visitors);
	//
	void LoadGame(AllObjects* allObjects_ptr, Menu* menu_ptr, PlayingField* field_ptr);
	void LoadGameStatsData(GameStats* stats, pugi::xml_node objectNode);
	PointCoord DownloadUpperLeft(pugi::xml_node objectNode);
	int DownloadDescriptorId(pugi::xml_node objectNode);
	void LoadBuildingData(Menu* menu_ptr, AllObjects* allObjects_ptr, pugi::xml_node objectNode);
	void LoadRoadData(Menu* menu_ptr, AllObjects* allObjects_ptr, pugi::xml_node objectNode);
	void LoadVisitorData(Menu* menu_ptr, AllObjects* allObjects_ptr, pugi::xml_node objectNode);
};