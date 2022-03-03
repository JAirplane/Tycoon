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
	int leftXButton = rightXScreen - buttonWidthAdd - 2;
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
void ConstructionInfoScreen::DeselectConstruction(const Camera* cam_ptr, const PlayingField* field_ptr, const AllObjects* allObjects_ptr)
{
	if (cam_ptr == nullptr)
	{
		throw MyException("ConstructionInfoScreen::DeselectConstruction(Camera* cam_ptr, int environmentMask) received nullptr camera");
	}
	if (field_ptr == nullptr)
	{
		throw MyException("ConstructionInfoScreen::DeselectConstruction(Camera* cam_ptr, int environmentMask) received nullptr playingfield");
	}
	if (allObjects_ptr == nullptr)
	{
		throw MyException("ConstructionInfoScreen::DeselectConstruction(Camera* cam_ptr, int environmentMask) received nullptr allObjects");
	}
	if (chosen_ptr != nullptr)
	{
		chosen_ptr->SetChosenStatus(false);
		if (!allObjects_ptr->ObjectImposition(chosen_ptr, cam_ptr, field_ptr))
		{
			chosen_ptr->EraseObject(cam_ptr->GetUpperLeft().Get_x(), cam_ptr->GetUpperLeft().Get_y(), cam_ptr->GetUpperLeft().Get_x() + cam_ptr->GetWidthAddition(),
				cam_ptr->GetUpperLeft().Get_y() + cam_ptr->GetHeightAddition());
			int mask = chosen_ptr->GetEnvironmentMask(allObjects_ptr->GetAllRoads(), allObjects_ptr->GetAllBuildings(), allObjects_ptr->GetPreliminaryElement());
			chosen_ptr->DrawObject(mask, cam_ptr->GetUpperLeft().Get_x(), cam_ptr->GetUpperLeft().Get_y(), cam_ptr->GetUpperLeft().Get_x() + cam_ptr->GetWidthAddition(),
				cam_ptr->GetUpperLeft().Get_y() + cam_ptr->GetHeightAddition());
		}
		ClearChosenConstruction();
	}
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
		set_cursor_pos(constructionIcon_ptr->GetUpperLeft().Get_x() + constructionIcon_ptr->GetWidthAddition() + 2, constructionIcon_ptr->GetUpperLeft().Get_y() + 1);
		set_color(GetTextColor(), GetShadingColor());
		cout << "Visitors: " << chosen_ptr->GetVisitorsCount();
		int profit = chosen_ptr->GetProfit();
		if (profit != -1)
		{
			set_cursor_pos(constructionIcon_ptr->GetUpperLeft().Get_x() + constructionIcon_ptr->GetWidthAddition() + 2, constructionIcon_ptr->GetUpperLeft().Get_y() + 2);
			cout << "Overall profit: " << chosen_ptr->GetProfit();
		}
	}
	else
	{
		set_cursor_pos(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 1);
		set_color(GetTextColor(), GetShadingColor());
		cout << "Choose construction to get data";
	}
}