#include "SaveLoad.h"
void SaveLoad::SaveGame(const GameStats* stats, const list<Construction*>& allBuildings, const list<Construction*>& allRoads, const list<Visitor*>& allVisitors)
{
	pugi::xml_document savedGameCondition;
	pugi::xml_node gameCondition = savedGameCondition.append_child("gameCondition");
	pugi::xml_node gameStats = gameCondition.append_child("gameStats");
	pugi::xml_node moneyAmount = gameStats.append_child("moneyAmount");
	moneyAmount.text().set(to_string(stats->amountOfMoney).c_str());
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
	bool saveResult = savedGameCondition.save_file("Game_Save.xml");
	if (!saveResult)
	{
		throw MyException("SaveLoad::SaveGame(const GameStats* stats, vector<Construction*> allBuildings, vector<Construction*> allRoads, vector<Visitor*> allVisitors) saving failed");
	}
}
void SaveLoad::FillGlobalObjectNodePart(GlobalObject* gameObject, pugi::xml_node& objectNode)
{
	pugi::xml_node xCoord = objectNode.append_child("xCoord");
	xCoord.text().set(to_string(gameObject->GetUpperLeft().Get_x()).c_str());
	pugi::xml_node yCoord = objectNode.append_child("yCoord");
	yCoord.text().set(to_string(gameObject->GetUpperLeft().Get_y()).c_str());
}
void SaveLoad::FillConstructionNodePart(Construction* gameObject, pugi::xml_node& objectNode)
{
	pugi::xml_node overallVisitors = objectNode.append_child("overallVisitors");
	overallVisitors.text().set(to_string(gameObject->allTimeVisited).c_str());
	pugi::xml_node descriptorId = objectNode.append_child("descriptorId");
	descriptorId.text().set(to_string(gameObject->GetDescriptor()->uniqueId).c_str());
}
void SaveLoad::FillBuildingNodePart(Construction* gameObject, pugi::xml_node& objectNode)
{
	pugi::xml_node entranceHeightAdd = objectNode.append_child("entranceHeightAdd");
	entranceHeightAdd.text().set(to_string(gameObject->GetEntranceHeightAdd()).c_str());
	pugi::xml_node entranceWidthAdd = objectNode.append_child("entranceWidthAdd");
	entranceWidthAdd.text().set(to_string(gameObject->GetEntranceWidthAdd()).c_str());
	pugi::xml_node exitDirection = objectNode.append_child("exitDirection");
	exitDirection.text().set(EnumStringConverter::GetStringToColorConverter()->Convert_DirectionToString(gameObject->GetExitDirection()).c_str());
	pugi::xml_node overallProfit = objectNode.append_child("overallProfit");
	overallProfit.text().set(to_string(gameObject->overallRevenue).c_str());
	pugi::xml_node visitorsInside = objectNode.append_child("visitorsInside");
	visitorsInside.text().set(to_string(gameObject->visitorsCounter).c_str());
}
void SaveLoad::FillVisitorNodePart(Visitor* person, pugi::xml_node& objectNode)
{
	pugi::xml_node insideBuilding = objectNode.append_child("insideBuilding");
	insideBuilding.text().set(to_string(person->buildingVisiting).c_str());
	pugi::xml_node foodCapacity = objectNode.append_child("foodCapacity");
	foodCapacity.text().set(to_string(person->starvation).c_str());
	pugi::xml_node toiletNeed = objectNode.append_child("toiletNeed");
	toiletNeed.text().set(to_string(person->toiletNeed).c_str());
	pugi::xml_node moneyAmount = objectNode.append_child("moneyAmount");
	moneyAmount.text().set(to_string(person->visitorCash).c_str());
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
	if (roadForSave->VisibleOutsidePlayingfield())
	{
		road.append_attribute("name") = "visibleRoad";
	}
	else if (!roadForSave->IsBreakable())
	{
		road.append_attribute("name") = "unbreakableRoad";
	}
	else
	{
		road.append_attribute("name") = "road";
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
//
void SaveLoad::LoadGame(AllObjects* allObjects_ptr, Menu* menu_ptr)
{
	pugi::xml_document loadedGameCondition = XMLDownloader::GetDownloader()->CreateDocument("Game_Save.xml");
	pugi::xml_node gameCondition = loadedGameCondition.child("gameCondition");
	pugi::xml_node gameStats = gameCondition.child("gameStats");
	this->LoadGameStatsData(menu_ptr->GetGameStats(), gameStats);
	pugi::xml_node ingameObjects = gameCondition.child("ingameObjects");
	pugi::xml_node buildings = ingameObjects.child("buildings");
	for (pugi::xml_node building = buildings.first_child(); building; building = building.next_sibling())
	{
		this->LoadBuildingData(menu_ptr, allObjects_ptr, building);
	}
	pugi::xml_node roads = ingameObjects.child("roads");
	for (pugi::xml_node road = roads.first_child(); road; road = road.next_sibling())
	{
		this->LoadRoadData(menu_ptr, allObjects_ptr, road);
	}
	pugi::xml_node visitors = ingameObjects.child("visitors");
	for (pugi::xml_node visitor = visitors.first_child(); visitor; visitor = visitor.next_sibling())
	{
		this->LoadVisitorData(menu_ptr, allObjects_ptr, visitor);
	}
}
void SaveLoad::LoadGameStatsData(GameStats* stats, pugi::xml_node gameStats)
{
	stats->amountOfMoney = stoi(gameStats.child_value("moneyAmount"));
}
PointCoord SaveLoad::DownloadUpperLeft(pugi::xml_node objectNode)
{
	return PointCoord(stoi(objectNode.child_value("xCoord")), stoi(objectNode.child_value("yCoord")));
}
int SaveLoad::DownloadDescriptorId(pugi::xml_node objectNode)
{
	return stoi(objectNode.child_value("descriptorId"));
}
void SaveLoad::LoadBuildingData(Menu* menu_ptr, AllObjects* allObjects_ptr, pugi::xml_node objectNode)
{
	ConstructionManager* desiredBuildingManager = nullptr;
	MenuElement* desiredElement = menu_ptr->GetMenuElementByDescriptorId(this->DownloadDescriptorId(objectNode));
	if (desiredElement == nullptr)
	{
		if (menu_ptr->GetExitManager()->GetDescriptor()->uniqueId == this->DownloadDescriptorId(objectNode))
		{
			desiredBuildingManager = menu_ptr->GetExitManager();
		}
	}
	else
	{
		desiredBuildingManager = desiredElement->GetManager();
	}
	if (desiredBuildingManager == nullptr)
	{
		throw MyException("SaveLoad::LoadBuildingData(Menu* menu_ptr, AllObjects* allObjects_ptr, pugi::xml_node objectNode) bad ID");
	}
	Construction* loadedBuilding = desiredBuildingManager->CreateConstruction(this->DownloadUpperLeft(objectNode), menu_ptr->GetDrawPointer(), allObjects_ptr);
	loadedBuilding->allTimeVisited = stoi(objectNode.child_value("overallVisitors"));
	loadedBuilding->SetEntranceHeightAdd(stoi(objectNode.child_value("entranceHeightAdd")));
	loadedBuilding->SetEntranceWidthAdd(stoi(objectNode.child_value("entranceWidthAdd")));
	loadedBuilding->SetExitDirection(EnumStringConverter::GetStringToColorConverter()->Convert_StringToDirection(objectNode.child_value("exitDirection")));
	loadedBuilding->overallRevenue = stoi(objectNode.child_value("overallProfit"));
	loadedBuilding->visitorsCounter = stoi(objectNode.child_value("visitorsInside"));
}
void SaveLoad::LoadRoadData(Menu* menu_ptr, AllObjects* allObjects_ptr, pugi::xml_node objectNode)
{
	Construction* loadedRoad = nullptr;
	pugi::xml_attribute name = objectNode.first_attribute();
	if (name.value() == string("road"))
	{
		MenuElement* desiredElement = menu_ptr->GetMenuElementByDescriptorId(this->DownloadDescriptorId(objectNode));
		if (desiredElement == nullptr)
		{
			throw MyException("SaveLoad::LoadRoadData(Menu* menu_ptr, AllObjects* allObjects_ptr, pugi::xml_node objectNode) bad ID");
		}
		loadedRoad = desiredElement->GetManager()->CreateConstruction(this->DownloadUpperLeft(objectNode), menu_ptr->GetDrawPointer(), allObjects_ptr);
	}
	else if (name.as_string() == string("unbreakableRoad"))
	{
		loadedRoad = menu_ptr->GetUnbreakableRoadManager()->CreateConstruction(this->DownloadUpperLeft(objectNode), menu_ptr->GetDrawPointer(), allObjects_ptr);
	}
	else if (name.as_string() == string("visibleRoad"))
	{
		loadedRoad = menu_ptr->GetVisibleOutsideCameraRoadManager()->CreateConstruction(this->DownloadUpperLeft(objectNode), menu_ptr->GetDrawPointer(), allObjects_ptr);
	}
	else
	{
		throw MyException("SaveLoad::LoadRoadData(Menu* menu_ptr, AllObjects* allObjects_ptr, pugi::xml_node objectNode) bad atrribute name");
	}
	loadedRoad->allTimeVisited = stoi(objectNode.child_value("overallVisitors"));
}
void SaveLoad::LoadVisitorData(Menu* menu_ptr, AllObjects* allObjects_ptr, pugi::xml_node objectNode)
{
	//park level doesn't matter here, so it is 0
	Visitor* loadedVisitor = menu_ptr->GetVisitorManager()->CreateVisitor(this->DownloadUpperLeft(objectNode), menu_ptr->GetDrawPointer(), allObjects_ptr, 0);
	loadedVisitor->buildingVisiting = stoi(objectNode.child_value("insideBuilding"));
	loadedVisitor->starvation = stoi(objectNode.child_value("foodCapacity"));
	loadedVisitor->toiletNeed = stoi(objectNode.child_value("toiletNeed"));
	loadedVisitor->visitorCash = stoi(objectNode.child_value("moneyAmount"));
}