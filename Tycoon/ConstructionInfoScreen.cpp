#include "ConstructionInfoScreen.h"
void ConstructionInfoScreen::CreateDeconstructButton()
{
	RectangleSymbols* constrictionInfoButtonBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonBottomRightSymbol());
	color borderForegroundColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonBorderForegroundColor();
	color borderBackgroundColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonBorderBackgroundColor();
	BorderAppearance* constructionInfoButtonBorder_ptr = new BorderAppearance(constrictionInfoButtonBorderSymbols_ptr, borderForegroundColor, borderBackgroundColor);
	color buttonLetterColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonLetterColor();
	color buttonShadingColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonShadingColor();
	int buttonWidthAdd = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonWidthAdd();
	int buttonHeightAdd = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonHeightAdd();
	int rightXScreen = GetUpperLeft().Get_x() + GetWidthAddition();
	int topYButton = GetUpperLeft().Get_y() + 2;
	int leftXButton = rightXScreen - buttonWidthAdd - 1;
	deconstruct_ptr = new Button(PointCoord(leftXButton, topYButton), buttonHeightAdd, buttonWidthAdd, constructionInfoButtonBorder_ptr, buttonLetterColor, buttonShadingColor,
		ConstructionOptions::GetAllOptions()->GetDeconstructButtonTitle(), GetDrawPointer(), GetCursor());
}
void ConstructionInfoScreen::CreateConstructionIcon()
{
	RectangleSymbols* iconSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconBottomRightSymbol());
	color iconBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconBorderForegroundColor();
	color iconBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconBorderBackgroundColor();
	BorderAppearance* iconBorder = new BorderAppearance(iconSymbols_ptr, iconBorderForegroundColor, iconBorderBackgroundColor);
	color iconLetterColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconLetterColor();
	color iconShadingColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconShadingColor();
	//
	PointCoord iconLocation = PointCoord(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 1);
	int iconHeightAdd = ConstructionOptions::GetAllOptions()->GetMenuIconHeightAdd();	//always equal to menu icon
	int iconWidthAdd = ConstructionOptions::GetAllOptions()->GetMenuIconWidthAdd();	//always equal to menu icon
	constructionIcon_ptr = new MyRectangle(iconLocation, iconHeightAdd, iconWidthAdd, iconBorder, iconLetterColor, iconShadingColor, GetDrawPointer(), GetCursor());
}
//
Button* ConstructionInfoScreen::GetDeconstructButton()
{
	return deconstruct_ptr;
}
Construction* ConstructionInfoScreen::GetChosenConstruction() const
{
	return chosen_ptr;
}
void ConstructionInfoScreen::SetChosenConstruction(Construction* choice_ptr)
{
	if(choice_ptr == nullptr)
	{
		throw MyException("ConstructionInfoScreen::SetChosenConstruction(Construction* choice_ptr) argument is nullptr.");
	}
	chosen_ptr = choice_ptr;
}
//
void ConstructionInfoScreen::ClearChosenConstruction()
{
	chosen_ptr = nullptr;
}
void ConstructionInfoScreen::DeselectConstruction(const Camera* cam_ptr, const AllObjects* allObjects_ptr)
{
	if (cam_ptr == nullptr)
	{
		throw MyException("ConstructionInfoScreen::DeselectConstruction(Camera* cam_ptr, int environmentMask) received nullptr camera");
	}
	if (allObjects_ptr == nullptr)
	{
		throw MyException("ConstructionInfoScreen::DeselectConstruction(Camera* cam_ptr, int environmentMask) received nullptr allObjects");
	}
	if (chosen_ptr != nullptr)
	{
		chosen_ptr->SetChosenStatus(false);
		if (cam_ptr->IsObjectInsideTheRectangle(chosen_ptr))
		{
			chosen_ptr->Redraw_VisitorCheck(cam_ptr, allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(),
				allObjects_ptr->GetAllVisitors(), allObjects_ptr->GetPreliminaryElement());
		}
		this->ClearChosenConstruction();
	}
}
void ConstructionInfoScreen::ClearChosenConstructionStatistic()
{
	int xCoord = constructionIcon_ptr->GetUpperLeft().Get_x() + constructionIcon_ptr->GetWidthAddition() + 2;
	int yCoord = constructionIcon_ptr->GetUpperLeft().Get_y() + 1;
	for (yCoord; yCoord < constructionIcon_ptr->GetUpperLeft().Get_y() + 3; yCoord++)
	{
		for (xCoord; xCoord < deconstruct_ptr->GetUpperLeft().Get_x(); xCoord++)
		{
			set_cursor_pos(xCoord, yCoord);
			cout << " ";
		}
	}
}
void ConstructionInfoScreen::ShowChosenConstructionStatistic()
{
	int messageXCoord = constructionIcon_ptr->GetUpperLeft().Get_x() + constructionIcon_ptr->GetWidthAddition() + 2;
	int messageYCoord = constructionIcon_ptr->GetUpperLeft().Get_y();
	set_cursor_pos(messageXCoord, messageYCoord);
	set_color(GetTextColor(), GetShadingColor());
	cout << "Visitors all the time: " << chosen_ptr->allTimeVisited;
	++messageYCoord;
	if (chosen_ptr->overallRevenue != -1)
	{
		set_cursor_pos(messageXCoord, messageYCoord);
		cout << "Overall profit: " << chosen_ptr->overallRevenue;
		++messageYCoord;
	}
	set_cursor_pos(messageXCoord, messageYCoord);
	if (chosen_ptr->GetDescriptor()->GetMaxVisitors() == 0)
	{
		cout << "Maximum visitors: unlimited";
	}
	else
	{
		cout << "Maximum simultaneous visitors: " << chosen_ptr->GetDescriptor()->GetMaxVisitors();
	}
	++messageYCoord;
	set_cursor_pos(messageXCoord, messageYCoord);
	if (chosen_ptr->GetDescriptor()->GetEntertainmentValue() == 1)
	{
		cout << "It's an amusement construction";
	}
	else
	{
		cout << "Not an amusement construction";
	}
	++messageYCoord;
	set_cursor_pos(messageXCoord, messageYCoord);
	cout << "Visit time: " << chosen_ptr->GetDescriptor()->GetVisitTime();
}
void ConstructionInfoScreen::DisplayConstructionInfo()
{
	if (chosen_ptr != nullptr)
	{
		constructionIcon_ptr->DrawBorder();
		GetDrawPointer()->DrawConstruction(constructionIcon_ptr->GetUpperLeft().Get_x() + 1, constructionIcon_ptr->GetUpperLeft().Get_y() + 1,
			constructionIcon_ptr->GetUpperLeft().Get_x() + constructionIcon_ptr->GetWidthAddition() - 1,
			constructionIcon_ptr->GetUpperLeft().Get_y() + constructionIcon_ptr->GetHeightAddition() - 1, chosen_ptr->GetDescriptor()->GetIconSymbol(),
			chosen_ptr->GetDescriptor()->GetForegroundColor(), chosen_ptr->GetDescriptor()->GetConnectedBackgroundColor());
		deconstruct_ptr->Display();
		this->ShowChosenConstructionStatistic();
	}
	else
	{
		set_cursor_pos(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 1);
		set_color(GetTextColor(), GetShadingColor());
		cout << "Choose construction to get data";
	}
}