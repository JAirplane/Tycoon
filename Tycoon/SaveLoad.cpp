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
	for (auto everyBuilding : allBuildings)
	{
		this->AddBuildingNode(everyBuilding, buildings);
	}
	pugi::xml_node roads = ingameObjects.append_child("roads");
	for (auto everyRoad : allRoads)
	{
		this->AddRoadNode(everyRoad, roads);
	}
	pugi::xml_node visitors = ingameObjects.append_child("visitors");
	for (auto everyVisitor : allVisitors)
	{
		this->AddVisitorNode(everyVisitor, visitors);
	}
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
	pugi::xml_node exitDirection = objectNode.append_child("exitDirection");
	exitDirection.set_value(EnumStringConverter::GetStringToColorConverter()->Convert_DirectionToString(gameObject->GetExitDirection()).c_str());
	pugi::xml_node overallProfit = objectNode.append_child("overallProfit");
	overallProfit.set_value(to_string(gameObject->overallRevenue).c_str());
	pugi::xml_node visitorsInside = objectNode.append_child("visitorsInside");
	visitorsInside.set_value(to_string(gameObject->visitorsCounter).c_str());
}
void SaveLoad::FillVisitorNodePart(Visitor* person, pugi::xml_node& objectNode)
{
	pugi::xml_node insideBuilding = objectNode.append_child("insideBuilding");
	insideBuilding.set_value(to_string(person->buildingVisiting).c_str());
	pugi::xml_node foodCapacity = objectNode.append_child("foodCapacity");
	foodCapacity.set_value(to_string(person->starvation).c_str());
	pugi::xml_node toiletNeed = objectNode.append_child("toiletNeed");
	toiletNeed.set_value(to_string(person->toiletNeed).c_str());
	pugi::xml_node moneyAmount = objectNode.append_child("moneyAmount");
	moneyAmount.set_value(to_string(person->visitorCash).c_str());
}
void SaveLoad::AddBuildingNode(Construction* buildingForSave, pugi::xml_node& buildings)
{
	pugi::xml_node building = buildings.append_child("building");
	this->FillGlobalObjectNodePart(buildingForSave, building);
	this->FillConstructionNodePart(buildingForSave, building);
	this->FillBuildingNodePart(buildingForSave, building);
}
void SaveLoad::AddRoadNode(Construction* roadForSave, pugi::xml_node& roads)
{
	pugi::xml_node road = roads.append_child("road");
	pugi::xml_attribute roadAttr;
	if (roadForSave->VisibleOutsidePlayingfield())
	{
		roadAttr = road.attribute("VisibleRoad");
	}
	else if (!roadForSave->IsBreakable())
	{
		roadAttr = road.attribute("UnbreakableRoad");
	}
	else
	{
		roadAttr = road.attribute("Road");
	}
	this->FillGlobalObjectNodePart(roadForSave, road);
	this->FillConstructionNodePart(roadForSave, road);
}
void SaveLoad::AddVisitorNode(Visitor* visitorForSave, pugi::xml_node& visitors)
{
	pugi::xml_node visitor = visitors.append_child("visitor");
	this->FillGlobalObjectNodePart(visitorForSave, visitor);
	this->FillVisitorNodePart(visitorForSave, visitor);
}