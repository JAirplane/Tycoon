#pragma once
#include "VisitorDescriptor.h"
/////////////ConstructionDescriptor Class contains all necessary data about Constructions/////////////
class ConstructionDescriptor : public IngameObjectDescriptor
{
private:
	int id;
	int constructionCost;
	int dailyExpences;
	string description;
	wstring iconSymbol;
	color backgroundConnected;
	color backgroundChosen;
public:
	ConstructionDescriptor(int uniqueId, int constructionCost, string description, wstring iconSymbol, color foreground, color backgroundConnected,
		color backgroundNotConnected, color backgroundChosen, int dailyExpences = 0, int constructionHeightAddition = 0, int constructionWidthAddition = 0) :
		IngameObjectDescriptor(foreground, backgroundNotConnected, constructionHeightAddition, constructionWidthAddition)
	{
		this->id = uniqueId;
		this->constructionCost = constructionCost;
		this->dailyExpences = dailyExpences;
		this->description = description;
		this->iconSymbol = iconSymbol;
		this->backgroundConnected = backgroundConnected;
		this->backgroundChosen = backgroundChosen;
	}
	ConstructionDescriptor(ConstructionConstantsXML setOfConstants) : IngameObjectDescriptor(setOfConstants)
	{
		this->id = setOfConstants.uniqueId;
		this->constructionCost = setOfConstants.cost;
		this->dailyExpences = setOfConstants.expences;
		this->description = setOfConstants.textDescription;
		this->iconSymbol = setOfConstants.constructionIconSymbol;
		this->backgroundConnected = setOfConstants.constructionBackgroundConnectedColor;
		this->backgroundChosen = setOfConstants.constructionBackgroundChosenColor;
	}
	virtual ~ConstructionDescriptor() {}
	int GetDescriptorId() const;
	__declspec(property(get = GetDescriptorId)) int uniqueId;
	int GetConstructionCost() const;
	string GetDescription() const;
	wstring GetIconSymbol() const;
	int GetDailyExpences() const;
	color GetConnectedBackgroundColor() const;
	color GetChosenBackgroundColor() const;
	virtual wstring GetConstructionSymbol(int mask = 0) const = 0;
	virtual int GetRestorationOfToiletNeed() const;
	virtual int GetSatisfactionOfHunger() const;
	virtual int GetVisitPrice() const;
	virtual int GetEntertainmentValue() const;
	virtual int GetIsExit() const;
	virtual int GetMaxVisitors() const;
	virtual int GetVisitTime() const;
};