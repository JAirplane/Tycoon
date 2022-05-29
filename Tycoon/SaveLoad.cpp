#include "SaveLoad.h"
void SaveLoad::SaveGame(const GameStats* stats, vector<Construction*> allBuildings, vector<Construction*> allRoads, vector<Visitor*> allVisitors)
{
	pugi::xml_document savedGameCondition;
	pugi::xml_node gameCondition = savedGameCondition.append_child("gameCondition");
	pugi::xml_node gameStats = gameCondition.append_child("gameStats");
	pugi::xml_node moneyAmount = gameStats.append_child("moneyAmount");
	moneyAmount.set_value(to_string(stats->amountOfMoney).c_str());
	pugi::xml_node ingameObjects = gameCondition.append_child("ingameObjects");
	pugi::xml_node buildings = ingameObjects.append_child("buildings");
}
void SaveLoad::FillGlobalObjectNodePart(GlobalObject* gameObject, pugi::xml_node& objectNode)
{
	pugi::xml_node xCoord = objectNode.append_child("xCoord");
	xCoord.set_value(to_string(gameObject->GetUpperLeft().Get_x()).c_str());
	pugi::xml_node yCoord = objectNode.append_child("yCoord");
	yCoord.set_value(to_string(gameObject->GetUpperLeft().Get_y()).c_str());
}
void SaveLoad::FillConstructionNodePart(Construction* gameObject, pugi::xml_node& objectNode)
{
	pugi::xml_node overallVisitors = objectNode.append_child("overallVisitors");
	overallVisitors.set_value(to_string(gameObject->allTimeVisited).c_str());
	pugi::xml_node descriptorId = objectNode.append_child("descriptorId");
	descriptorId.set_value(to_string(gameObject->GetDescriptor()->uniqueId).c_str());
}
void SaveLoad::FillBuildingNodePart(Construction* gameObject, pugi::xml_node& objectNode)
{
	pugi::xml_node entranceHeightAdd = objectNode.append_child("entranceHeightAdd");
	entranceHeightAdd.set_value(to_string(gameObject->GetEntranceHeightAdd()).c_str());
	pugi::xml_node entranceWidthAdd = objectNode.append_child("entranceWidthAdd");
	entranceWidthAdd.set_value(to_string(gameObject->GetEntranceWidthAdd()).c_str());

}
void SaveLoad::AddBuildingNode(Construction* buildingForSave, pugi::xml_node& buildings)
{
	pugi::xml_node building = buildings.append_child("building");
	this->FillGlobalObjectNodePart(buildingForSave, building);
}